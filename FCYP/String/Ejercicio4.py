#Ejercicios laboratorio clase 09/06/2020
#Nombre: Catalina Riquelme
#Sección: G3
#Fecha: 10/06/2020

#Ejercicio 1
print("PROBLEMA 1")

#Construya un programa que identifique el número más alto dentro de una lista de elementos.
#  Considere que puede que no todos los elementos sean válidos.
#  Tome como ejemplo la lista [4,‘5’,‘veinte’,0,2.0,’z’,9,‘7’]

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


while i < len(lista):
    lista[i] = int(lista[i])
    i += 1    
j =0

print("Los números a analizar son:",lista)

while j < len(lista)-1:
    i = 0
    while i < len(lista)-1:
        if lista [i] > lista[i+1]:
            lista.insert(i,lista.pop(i+1))
        i += 1
    j +=1
ultimoNumero = len(lista)-1

#SALIDA
print("EL numero mayor es",lista[ultimoNumero])

#Ejercicio 2
print()
print("PROBLEMA 2")

#Construya un programa que reciba una lista de string cualquiera y 
# que retorne un string conformado de todos sus elementos. 


#DATOS DE ENTRADA
n2 = input("Ingrese datos separados por un espacio: ")
lista = n2.split(" ")
print(lista)

while len(lista) > 1:
    temp = lista[0]+lista[1]
    
    lista.pop(0)
    lista.pop(0)
    lista.insert(0,temp)

#DATOS DE SALIDA
print(lista)


#Problema 3
print()
print("PROBLEMA 3")

#Construya un programa que reciba por teclado un string cualquiera y 
# que entregue el string cambiando todas las ‘a’ por ‘i’. 
#Ejemplo:  entrada → hola, cómo estás?    salida → holi, cómo estis?

#Datos de entrada
texto = input("Ingrese un texto para cambiar las letras a por i: ")

#Procesamiento
textoNuevo= ""
i = 0
while i < len(texto):
    if texto[i] == "a":
        textoNuevo = textoNuevo + "i"
    else:
        textoNuevo = textoNuevo + texto[i]
    i +=1
#Datos de salida
print(textoNuevo)

#Ejercicio 4
print()
print("Ejercicio 4")

#En la oficina de la revista “Faces” diariamente llegan columnas de opinión para que sean publicadas.
# El trabajo de las y los redactores es revisar que estas columnas no excedan un número X de palabras 
# y así segura que no afecte el formato de las páginas a imprimir. Últimamente los textos han llegado fallados: 
# en lugar de espacios entre palabras está el símbolo % una vez y dos veces cuando es un punto (%%), 
# lo que ha dificultado el conteo a los redactores.
#Construya un programa que reciba los textos como string, el número de
# palabras límite como un entero e indique si el texto cumple con el límite de palabras.

#Datos de entrada
texto = input("Ingrese el texto: ")

#Pricesamiento
textoNuevo= ""
i = 0
while i < len(texto):
    if texto[i] == "%%":
        textoNuevo = textoNuevo + "."
    else:
        textoNuevo = textoNuevo + texto[i]
    i +=1

while i < len(texto):
    if texto[i] == "%":
        textoNuevo = textoNuevo + " "
    else:
        textoNuevo = textoNuevo + texto[i]
    i +=1

textoLista = textoNuevo
textoLista.split(" ")

#Salida
if len(textoNuevo) > 14:
    print("El texto contiene",len(textoLista)+1, "palabras, no cumple con el limite")

else:
    print(textoNuevo)