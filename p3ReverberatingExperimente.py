import os
import wave 
#import matplotlib.pyplot as plt
import numpy as np
import simpleaudio as sa


if os.getcwd() != 'C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat':
    os.chdir('C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat')


def read_audio(nume):
    s = wave.open(nume, 'r')
    a = s.readframes(-1)
    sa = np.frombuffer(a, 'Int16')
    sa = sa.astype(np.int16)
    return sa




tehno = read_audio('lana.wav')

#%%
obj = sa.play_buffer(tehno, 2, 2, 44100)


#%%

obj.stop()


#%%


#FOR TESTING PURPOSES O SA SCRIEM FISIERUL INTR UN ETXT SI O SA COMPARAM CU REALITAEA



fisier = open("intrare.dat", "w+")
for i in tehno:
    fisier.write(str(i) +" ")
fisier.close()




#%%


# =============================================================================
# celula cu functii
# =============================================================================



#reverberating delay, ambele functii st la fel dar implementate diferit


def reverberating_delay2(x, dry, wet, g, M):
    M = round(M * 44.1)
    buffer = np.zeros(len(x)) #buffer de lungimea de intrare
    y = np.zeros(len(x))
    #functia sane de transfer e ceva gen
    #y[n] = x[n] * dry + (x[n] * wet + x[n-M]*g)
    
    y [:M]= x[:M] * dry #toate alea care ies curate
    buffer[:M] = x[:M] * wet * (1-g) #ft import wetul
    
    for i in range(M, len(x)):
        buffer[i] = x[i] * wet * (1-g) + buffer[i-M] * g  #calculam noua vaeabla din bufer
        y[i] = x[i] * dry + buffer[i-M]
        
    #observatie ca variabilele care au inrat in buffer au fost inmultite cu wet
    y = np.array(y)
    return y.astype(np.int16)

#ambele fac acelasi lucru, doar rev 2 e mai inceata ca timp de executie si 
#ca volum, nush am un bug undeva, dar rev 2 e implementata in c
#ah, reverberating delay nu e scalata

#for all intents and purposes, ce se intoarce de la 2 == 0.7 * ce se intoarce de la 1

def reverberating_delay(init, dry, wet, g, M):
    M = round(M * 44.1)
    a1 = dry / (abs(dry) + abs(wet*(1-g)))
    a2 = wet*(1-g)/(abs(dry)+abs(wet*(1-g)))
    init_scalat_iesire = init * a1 #sunt alea care ies pe canalul dry
    init_scalat_comb = init * a2 #scalare la intrarea in comb filter
    buffer = np.zeros(len(init)) #buffer de lungimea de intrare
    y_iesire_comb = []
    for i in range(len(init)-M):
        buffer[M+i] = init_scalat_comb[i] #in bufer la M+i punem esantioanele de la i la M, i=primu
        init_scalat_comb[i+M] = init_scalat_comb[i+M] + g * init_scalat_comb[i]
        #pentru linia de mai sus, practic dupa intarzierea de M esantioane, trebuie
        #sa adaugam la esantioanele de la de intrarea in buffer, esantioanele iesite
        #si scalate cu g
        
        #in final, forurl are grija sa puna in buffer() tot ce trebuie
        
    y = buffer + init_scalat_iesire
    y = np.array(y)
    return y.astype(np.int16)


# =============================================================================
# FILTRUL TRECE TOT  care e ca un comb doar ca se ia dupa adunare sampleur
# =============================================================================



def all_pass(x, g, M):
    M = round(M * 44.1)
    buffer = np.zeros(len(x))
    y = np.zeros(len(x))
    # raspunsul acestui filtru este ceva de  genul
    # y[n] = (x[n] + x[n] * z^(-M) * g)*(-g) + x[n] * z^(-M)
    # y[n] = (x[n] + x[n-M] * g)*(-g) + x[n-M] 
    # iar pentru primele M esantioane, z^(-M) nu exista, 
    # deci initial  putem doar copia direct salat
   
    y[:M] = x[:M] * -g 
    buffer[:M] = x[:M] 
    for i in range(M,len(x)):
       buffer[i] = x[i] + buffer[i-M] * g #facut optimizari scos ultimu esantion si bagat nou 
       y[i] = (x[i] + buffer[i-M] * g) * -g + buffer[i-M]

 
    y = np.array(y)
    return y.astype(np.int16)


def schroeder(x, dry):
    #in milisecunde
    #35, 40, 45, 50, gain 0.5 tot
    #la trece tot
    #in ms 5. 2, gain 0.7
    x = x / 2 # sa nu depasim
    copieX = x / 4
    temp = [0 for i in range(len(x))]
    temp = np.array(temp)
    #in loc sa modificam esantioanele
    #dam un numar de ms aprox egal cu nr 
    #esantioane
    temp = temp + reverberating_delay(copieX, 0, 1, 0.5, 35)
    temp = temp + reverberating_delay(copieX, 0, 1, 0.5, 40)
    temp = temp + reverberating_delay(copieX, 0, 1, 0.5, 45)
    temp = temp + reverberating_delay(copieX, 0, 1, 0.5, 50)
    temp = all_pass(temp, 0.7, 5)
    temp = all_pass(temp, 0.7, 2)
    y = temp + dry * x
    
    y = np.array(y)
    return y.astype(np.int16) #PE 32 DE BITI




#filtru fir

def refInit(x):


    y = [0 for i in range(len(x))]
    ponderi = [0.841, 0.504, 0.490,
           0.379, 0.380, 0.346,
           0.289, 0.272, 0.192,
           0.193, 0.217, 0.181,
           0.180, 0.181, 0.176,
           0.142, 0.167, 0.134]


    # intarzieri = [191, 760, 45, 191,
    #           10, 124, 707, 120,
    #           385, 67, 36, 76,
    #           420, 5, 80, 67,
    #           54, 195]


  

    intarzieri = [190, 759, 44, 190,
              9, 123, 706, 119,
              384, 66, 35, 75,
              419, 4, 79, 66,
              53, 194]
    
    for j in range(len(ponderi)):
        if j != 0:
            print(  sum(intarzieri[:j])  )
            y[sum(intarzieri[:j]):] = y[sum(intarzieri[:j]):] + x[:( len(x) - sum(intarzieri[:j]))]*ponderi[j]
        
    y = np.array(y)
    y = y 
    return y.astype(np.int16)


#comburi ptr moorer

def comburi(x, gainComburi):
   # x = x / 8
    milisecunde = [40, 44, 48, 52, 56, 60]
 #   gainuri = [10**(-3 * round(i * 44.1 ) / 44.1) for i in milisecunde] #form 3.43
   # print(gainuri)
    y = 0
    for i in range(len(milisecunde)):
        y = y + reverberating_delay(x, 0, 1, gainComburi, milisecunde[i]) * 0.7#07 de la functie gresita
        
    y = np.array(y)
    return y.astype(np.int16)





def moorer(x, reglSemnal, reglReflexii, reglReverb, gainComburi):
    #x = x / 8 #for good measure
    reflInit = refInit(x)
    reflInit = reflInit / 8 #for good measure
    iesireComburi = comburi(reflInit, gainComburi)
    reverbFinal = all_pass(iesireComburi, 0.8, 7)
    y = reglSemnal * x + reglReflexii * reflInit + reglReverb * reverbFinal
    y = np.array(y)
    return y.astype(np.int16)
    
#https://christianfloisand.wordpress.com/2012/10/18/algorithmic-reverbs-the-moorer-design/


#%%

#semnalControl = moorer(tehno, 0.4, 0.5, 0.5, 0.6)
semnalControl = moorer(tehno, 0.5, 0.5, 0.5, 0.8)
#semnalControl2 = reverberating_delay2(tehno,0.5, 0.5, 0.5, 200)
#semnalControl1 = reverberating_delay(tehno,0.5, 0.5, 0.5, 200)

#%%
obj = sa.play_buffer(semnalControl, 2, 2, 44100 )

#%%
obj.stop()

#%%

##comparatii
#

iesireCW = open("C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat\\iesireMoorer.dat", "r+")
a = [i for i in iesireCW]  
a = [int(i) for i in a[0].split()]

a = np.array(a)
a = a.astype(np.int16)

#%%

obj = sa.play_buffer(a, 2, 2, 44100)
#%%

obj.stop()

#%%
import matplotlib.pyplot as plt
plt.figure(figsize = (15, 5))
plt.plot(semnalControl1, label = "1")
plt.plot(semnalControl2, label = "2", alpha = 0.4, color='red')
#plt.plot(q*7-a, label = "diferenta", alpha = 0.4, color='green', marker="*")

plt.grid()
plt.legend()
plt.show()

#%%

plt.figure(figsize = (15, 5))
plt.plot(a, label = "CodeWarrior")
plt.plot(semnalControl, label = "Python", alpha = 0.4, color='red')
#plt.plot(q*7-a, label = "diferenta", alpha = 0.4, color='green', marker="*")

plt.grid()
plt.legend()
plt.show()




#%%


#exista o diferenta mare la fiecare
#buffer. Adica, la itemul 1543 e o
#diferenta enorma, atunci e si momentu
#cand intra primu buffer in actiune, 
#crek e un bug in c, dar anyways,
#good enough

import matplotlib.pyplot as plt


plt.figure(figsize=(15, 5))
plt.plot(semnalControl[:4500], label="semnalControl")
plt.plot(a[:4500], label="a", alpha = 0.6)
#plt.figure(figsize=(15, 5))
#plt.plot(q-a, label="diferenta")

plt.legend()
plt.grid()
plt.show()


#%%


dif = q - a

#%%
obj = sa.play_buffer(q, 2, 2, 44100)
#%%

obj.stop()





