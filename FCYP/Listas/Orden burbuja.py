#Ordenamiento Burbuja
print()
print("ORDENAMIENTO BURBUJA")

#DATOS DE ENTRADA

lista = []
print("Para terminar escriba end")

n = input("Ingrese un número: ")

while n != "end":
    if n != "end":
        lista.append(n)
        n = input("Ingrese otro numero: ")
i = 0

#PROCESAMIENTO

#Transformando los string a flotantes o enteros (?)
while i < len(lista):
    lista[i] = int(lista[i])
    i += 1    
j =0
#Imprimiendo la original uwu
print("EL orden original es:",lista)

#Ir dejando el número más grande al final
while j < len(lista)-1:
    i = 0
    while i < len(lista)-1:
        if lista [i] > lista[i+1]:
            lista.insert(i,lista.pop(i+1))
        i += 1
    j +=1

#SALIDA
print("EL Orden final es:",lista)