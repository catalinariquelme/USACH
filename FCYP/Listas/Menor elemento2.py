#imprimir menor de una serie de números

print()

lista = input("Ingrese números: ")
lista = lista.split(" ")

print(lista)
i = 0

print()

#PASANDO LOS STRING A BOOLEANOS (?)
while i < len(lista):
    lista[i] = int(lista[i])
    i += 1
print(lista)
print()

#Viendo cual es el menor de esta lista

numeroMenor = lista[0]
i = 1
while i < len(lista):

    if numeroMenor > lista [i]:
        numeroMenor = lista[i]
        
    i+=1

print(numeroMenor)