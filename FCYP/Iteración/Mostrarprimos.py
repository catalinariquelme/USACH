
#Mostrar primos hasta ese número

#ENTRADA
n = 10#int(input("Ingrese un número"))
EsPrimo = True
j = 2

#PROCESAMIENTO
while j <= n:
    i = 2
    
    while i < n:    
        if n % i == 0:
            EsPrimo = False
            print("no es primo")      
        i +=1

    n -=1