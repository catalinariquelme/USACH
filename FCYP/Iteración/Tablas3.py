#imprimir tablas de multiplicar hasta el 10

n = int(input("Ingrese hasta que tabla desea imprimir: "))
i = 1

if n <= 0:
    while n <= 0:
        n = int(input("Ingrese un número válido: "))

else:
    while n >= i:

        j = 1
        print("TABLA DEL", i)
        print()
        while 10 >= j:
            
            print("{} X {} = {}".format(i,j, j*i))
            j += 1
        i+= 1
        print()