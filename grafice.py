import os
import wave
import matplotlib.pyplot as plt
import numpy as np



if os.getcwd() != 'C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat':
    os.chdir('C:\\Users\\tudor_ytmdyrk\\Desktop\\p3 cmpilat')

def read_audio(nume):
    s = wave.open(nume, 'r')
    a = s.readframes(-1)
    sa = np.frombuffer(a, 'Int16')
    sa = sa.astype(np.int16)
    return sa




tehno = read_audio('lana.wav')


fisier = open("intrare.dat", "w+")
for i in tehno:
    fisier.write(str(i) +" ")
fisier.close()




#%%


# =============================================================================
# celula cu functii
# =============================================================================



#reverberating delay, ambele functii st la fel dar implementate diferit


def reverberating_delay_PADDING(x, dry, wet, g, M):
    M = round(M * 44.1)
    #ar trebui introduse macrourile din starcore aici, dar vom face urmatoarea mizerie
    s1 = (1-g) 
    x = np.concatenate((x, np.array([0 for i in range(M+1)])), axis=None)
    buffer = np.zeros(len(x) ) #buffer de lungimea de intrare
    y = np.zeros(len(x))
    #functia sane de transfer e ceva gen
    #y[n] = x[n] * dry + (x[n] * wet + x[n-M]*g)
    
    for i in range(M):
        buffer[i] = x[i] * wet * s1   #calculam noua vaeabla din bufer
        y[i] = x[i] * dry 
    
    
    for i in range(M, len(x)):
        buffer[i] = x[i] * wet * s1 + buffer[i-M] * g  #calculam noua vaeabla din bufer
        y[i] = x[i] * dry + buffer[i-M]
    
 
    
    print(len(x), len(y), len(buffer))
    
    for i in range(M, len(x)):
        buffer[i] = x[i] * wet * s1 + buffer[i-M] * g  #calculam noua vaeabla din bufer
        y[i] = x[i] * dry + buffer[i-M]
    

    #observatie ca variabilele care au inrat in buffer au fost inmultite cu wet
    y = np.array(y)
    return y.astype(np.int16) 




def reverberating_delay_NOPADDING(x, dry, wet, g, M):
    M = round(M * 44.1)
    #ar trebui introduse macrourile din starcore aici, dar vom face urmatoarea mizerie
    
    s1 = (1-g) 
    buffer = np.zeros(len(x)) #buffer de lungimea de intrare
    y = np.zeros(len(x))

    
    for i in range(M):
        buffer[i] = x[i] * wet * s1   #calculam noua vaeabla din bufer
        y[i] = x[i] * dry 
    
    
    for i in range(M, len(x)):
        buffer[i] = x[i] * wet * s1 + buffer[i-M] * g  #calculam noua vaeabla din bufer
        y[i] = x[i] * dry + buffer[i-M]
    
    

    #observatie ca variabilele care au inrat in buffer au fost inmultite cu wet
    y = np.array(y)
    return y.astype(np.int16) 



def all_pass_NOPADDING(x, g, M):
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
       buffer[i] = x[i] + buffer[i-M] * g 
       y[i] = (x[i] + buffer[i-M] * g) * -g + buffer[i-M]


    y = np.array(y)
    return y.astype(np.int16)




def all_pass_PADDING(x, g, M):

    M = round(M * 44.1)
    x = np.concatenate((x, np.array([0 for i in range(M+1)])), axis=None)
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
       buffer[i] = x[i] + buffer[i-M] * g 
       y[i] = (x[i] + buffer[i-M] * g) * -g + buffer[i-M]


    y = np.array(y)
    return y.astype(np.int16)

def schroeder(x, dry):
    #in milisecunde
    #35, 40, 45, 50, gain 0.5 tot
    #la trece tot
    #in ms 5. 2, gain 0.7
    x = x / 2 # sa nu depasim
    copieX = x / 2
    temp = [0 for i in range(len(x))]
    temp = np.array(temp)
    #in loc sa modificam esantioanele
    #dam un numar de ms aprox egal cu nr 
    #esantioane
    temp = temp + reverberating_delay_NOPADDING(copieX, 0, 1, 0.5, 35)
    temp = temp + reverberating_delay_NOPADDING(copieX, 0, 1, 0.5, 40)
    temp = temp + reverberating_delay_NOPADDING(copieX, 0, 1, 0.5, 45)
    temp = temp + reverberating_delay_NOPADDING(copieX, 0, 1, 0.5, 50)
    temp = all_pass_NOPADDING(temp, 0.7, 5)
    temp = all_pass_NOPADDING(temp, 0.7, 2)
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


  

    intarzieri = [189, 759, 44, 190,
              9, 123, 706, 119,
              384, 66, 35, 75,
              419, 4, 79, 66,
              53, 194] #corectie de un esantion din cauza iteratorilor
                        #in python
                    
    
    intarzieri = np.cumsum(intarzieri)#cumulative sum, ne face arrayul de intarzieri
                                        #cumulate
    
    for j in range(len(ponderi)):
        # if j != 0:
        #     print(  sum(intarzieri[:j])  )
           # y[sum(intarzieri[:j]):] = y[sum(intarzieri[:j]):] + x[:( len(x) - sum(intarzieri[:j]))]*ponderi[j]
           y[intarzieri[j]:] = y[intarzieri[j]:] + x[:(len(x) - intarzieri[j])] * ponderi[j] #practic suprapunem
                                           #esantioanele intarziata
        
        
    y = np.array(y)
    y = y 
    return y.astype(np.int16)


#comburi ptr moorer

def comburi(x, gainComburi):
    milisecunde = [40, 44, 48, 52, 56, 60]
 #   gainuri = [10**(-3 * round(i * 44.1 ) / 44.1) for i in milisecunde] #form 3.43

    y = 0
    for i in range(len(milisecunde)):
        y = y + reverberating_delay_NOPADDING(x, 0, 1, gainComburi, milisecunde[i]) #07 de la functie gresita
        
    y = np.array(y)
    return y.astype(np.int16)





def moorer(x, reglSemnal, reglReflexii, reglReverb):
    #x = x / 8 #for good measure
    gainComburi = 0.8
    reflInit = refInit(x)
    copieReflInit = reflInit / 8 #for good measure
    iesireComburi = comburi(copieReflInit, gainComburi)
    reverbFinal = all_pass_NOPADDING(iesireComburi, 0.5, 7)
    y = reglSemnal * x + reglReflexii * reflInit + reglReverb * reverbFinal
    y = np.array(y)
    return y.astype(np.int16)
    

#%%

#RULATi reverberatingDelayExecutabil



semnalControl = reverberating_delay_PADDING(tehno,0.2, 0.7, 0.8, 90)


iesireCW = open("iesireReverberatingPADDING.dat", "r+")
a = [i for i in iesireCW]  
a = [int(i) for i in a[0].split()]

a = np.array(a)
a = a.astype(np.int16)


plt.figure(figsize=(15, 5))
plt.title("RevDelay pe lana")
plt.plot(semnalControl, label="semnalControl", color="blue")
plt.plot(a, label="semnalStarcore", alpha = 0.5, color="red")

plt.legend()
plt.grid()
plt.show()

iesireCW.close()

#%%

#RULATi AllpassExecutabil

semnalControl = all_pass_PADDING(tehno,0.7, 90)

iesireCW = open("iesireAllpassPADDING.dat", "r+")
a = [i for i in iesireCW]  
a = [int(i) for i in a[0].split()]

a = np.array(a)
a = a.astype(np.int16)


plt.figure(figsize=(15, 5))
plt.title("AllPass pe lana")
plt.plot(semnalControl, label="semnalControl", color="blue")
plt.plot(a, label="semnalStarcore", alpha = 0.5, color="red")

plt.legend()
plt.grid()
plt.show()
iesireCW.close()


#%% 

#RULATi SChroederExecutabil.

semnalControl = schroeder(tehno, 0.5)


iesireCW = open("iesireSchroeder.dat", "r+")
a = [i for i in iesireCW]  
a = [int(i) for i in a[0].split()]

a = np.array(a)
a = a.astype(np.int16)


plt.figure(figsize=(15, 5))
plt.title("Schroeder pe lana")
plt.plot(semnalControl, label="semnalControl", color="blue")
plt.plot(a, label="semnalStarcore", alpha = 0.5, color="red")


plt.legend()
plt.grid()
plt.show()

iesireCW.close()

#%%


semnalControl = moorer(tehno, 0.2, 0.7, 0.8)



iesireCW = open("iesireMoorer.dat", "r+")
a = [i for i in iesireCW]  
a = [int(i) for i in a[0].split()]

a = np.array(a)
a = a.astype(np.int16)



plt.figure(figsize=(15, 5))
plt.title("Moorer pe lana")
plt.plot(semnalControl, label="semnalControl", color="blue")
plt.plot(a, label="semnalStarcore", alpha = 0.5, color="red")

plt.legend()
plt.grid()
plt.show()


iesireCW.close()


