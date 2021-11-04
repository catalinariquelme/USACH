#Ejercicios laboratorio clase 11/09/2020
#Nombre: Catalina Riquelme
#Sección: G3
#Profesora: Nicole Henriquez
#Fecha: 11/05/2020

#Construya un programa que reciba como entrada un texto a través de 
#archivo y una palabra e indique si la palabra está en el texto o no

##BLOQUE DE DEFINICIONES

#Función que lee un archivo 
#Entrada: string(nombre del archivo a leer)
#Salida: lista(con string con contenido del texto)
def leer(nombre):
    archivo = open(nombre,"r")
    listaTexto = archivo.readlines()
    archivo.close()
    return listaTexto

#Función que cuenta cuantas veces se encue
#Entrada: string
#Salida: lista con string
def numeroPalabraOracion(numeroPalabras,listaFrase,palabra):
    i = 0
    print(listaFrase)
    while i < len(listaFrase):
        listaFrase[i]=listaFrase[i].lower()
        if palabra == listaFrase[i]:
            numeroPalabras +=1
        i+=1
    return numeroPalabras

##BLOQUE PRINCIPAL
#Entrada
palabraOriginal = input("Ingrese una palabra: ")

#Procesamiento
palabra = palabraOriginal.lower()
texto = leer("texto.txt")
numeroPalabras = 0
i=0
while i < len(texto):
    parrafo = texto[i]
    listaParrafo = parrafo.split(" ")
    numeroPalabras = numeroPalabraOracion(numeroPalabras,listaParrafo,palabra)
    i+=1

#Salida
if numeroPalabras == 0:
    print("La palabra "+palabraOriginal+" no se encuentra en el texto.")
else:
    print("La palabra "+palabraOriginal+" se encuentra",numeroPalabras,"veces.")
