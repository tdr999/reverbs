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




tehno = read_audio('tehno2.wav')

#%%
obj = sa.play_buffer(tehno, 2, 2, 44100)


#%%

obj.stop()


#%%

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
#ca volum, nush am un bug undeva

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
#%%

ir_teh = reverberating_delay2(tehno, 0.6, 0.4, 0.8, 80)

#%%
obj = sa.play_buffer(ir_teh, 2, 2, 44100 )

#%%
obj.stop()

#%%


#FOR TESTING PURPOSES O SA SCRIEM FISIERUL INTR UN ETXT SI O SA COMPARAM CU REALITAEA



fisier = open("intrare.dat", "w+")
for i in tehno:
    fisier.write(str(i) +" ")
fisier.close()

#%%

#obj = sa.play_buffer(code_warior, 2, 2, 44100)



#program de control in C


iesireCW = open("C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat\\iesireReverberating.dat", "r+")
a = [i for i in iesireCW]  
a = [int(i) for i in a[0].split()]

a = np.array(a)
a = a.astype(np.int16)


#%%
obj = sa.play_buffer(a, 2, 2, 44100)
#%%

#masuratoare erori esantion cu esantion

q = [abs(ir_teh[i] - a[i]) / (abs(ir_teh[i]) + 0.0001) * 100.0 for i in range(len(a))]


print(q[4000:4010])

#testTes = open("C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat\\zeu.dat","w")
#for i in q:
#    testTes.write(str(i)+ " ")

#%%

obj.stop()

iesireCW.close()

#%%

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


#%%

all_audio = all_pass(tehno, 0.6, 80)

#%%


obj = sa.play_buffer(all_audio, 2, 2, 44100)

#%%


obj.stop()

#%%

iesireCW = open("C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat\\iesireAllPass.dat", "r+")
a = [i for i in iesireCW]  
a = [int(i) for i in a[0].split()]

a = np.array(a)
a = a.astype(np.int16)

#%%
obj = sa.play_buffer(a, 2, 2, 44100)
#%%

obj.stop()