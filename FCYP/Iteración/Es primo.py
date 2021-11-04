
#Indicar si un numero es primo o no

#ENTRADA
n = int(input("Ingrese un número: "))
EsPrimo = True
i = 2

#PROCESAMIENTO
while i < n:
    
    if n % i == 0:
        EsPrimo = False
    i +=1

#SALIDA
if EsPrimo == False:
    print("No es primo")
else:
    print("Es primo")


