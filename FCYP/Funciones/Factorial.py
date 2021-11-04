
n=5#int(input("Ingrese el número que queira encontrar el factorial: "))

factorial=1

if n < 0:
   print("No hay factorial definido para negativos")

elif(n == 0):
    print("El factorial de 0 es 1")

else:
  while(n > 0):

    factorial = factorial*n
    n = n-1
        
  print("El factorial del número es:",factorial)