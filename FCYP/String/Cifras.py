
#Un sistema de computador considera una cadena de dígitos decimales como válida si contiene un número impar
#de ceros (asumiendo que 0 es un número par). Así, dado un valor entero N, se debe entregar el número de
#cadenas válidas que existen con N dígitos decimales. Por ejemplo, si N=2, el algoritmo debería entregar 18 como
#salida, pues existen únicamente 18 cadenas válidas con 2 dígitos decimales (01, 02, 03, 04, 05, 06, 07, 08, 09, 10,
#20, 30, 40, 50, 60, 70, 80, 90)


#Se asume que el usuario ingresará n >= 1
n = 2#int(input("Ingrese cifras: "))
contador = 1
cantidadNumeros = 9 #Se consideran 01 02 03 04 05 06 07 08 09
while contador < 10**n:
    contador = str(contador)
    i =0
    while i < len(contador):
        if contador[i] == "0":
            cantidadNumeros +=1
        i+=1

    contador = int(contador)
    contador+=1

print("Cantidad de numeros con 0:", cantidadNumeros) #Return


# Extra (no entregar)
if cantidadNumeros % 2 == 0:
    print("No es valido (par)")

else:
    print("Es valido (par)\n")
