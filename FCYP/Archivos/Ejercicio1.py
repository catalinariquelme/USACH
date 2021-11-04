#Ejercicios laboratorio clase 11/09/2020
#Nombre: Catalina Riquelme
#Sección: G3
#Profesora: Nicole Henriquez
#Fecha: 11/05/2020

print()
print("EJERCICIO 1")
print()
#Construya un programa en Python que cuente la cantidad de vocales y 
#consonantes en un texto en inglés entregado en un archivo de entrada llamado ‘texto.txt

##BLOQUE DE DEFINICIONES

#Función que lee un archivo 
#Entrada: string(nombre del archivo a leer)
#Salida: lista(con string con contenido del texto)
def leer(nombre):
    #Se abre el archivo en forma de lectura
    archivo = open(nombre,"r")
    #Se guarda el texto del archivo
    listaTexto = archivo.readlines()
    #Se cierra el archivo
    archivo.close()
    return listaTexto

#Función que cuenta la cantidad de vocales en un string
#Entrada:entero(número de vocales contadas hasta cierto momento,
#string(verso, en este caso de la canción)
#Salida: entero(número de vocales aumentada con el verso analizada)
def contadorVocales(cantidadVocales,verso):
    #Se guardan en un string las vocales tanto en minúsculas como en mayúsculas
    vocales = "aeiouAEIOU"
    j = 0
    #Se recorre cada letra del verso
    while j < len(verso):
        i=0
        #Se recorren las vocales comparandolas con cada letra de palabra
        while i < len(vocales):
            #En el caso que sea vocal se agrega a lo que ya se tiene acumulado
            #en la variable cadenaVocales
            if vocales[i]==verso[j]:
                cantidadVocales+=1

            i+=1

        j+=1
    return cantidadVocales

#Funcipon que cuenta la cantidad de consonantes en un string
#Entrada:entero(número de consonantes contadas hasta cierto momento,
#string(verso, en este caso de la canción)
#Salida:entero(número de consonantes aumentada con el verso analizada)
def contadorConsonantes(cantidadConsonantes,verso):
    #Se guardan en un string las consonantes tanto en minúsculas como en mayúsculas
    consonantes = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"
    j = 0
    #Se recorre cada letra del verso
    while j < len(verso):
        i = 0
        #Se recorren las consonantes comparandolas con cada letra de palabra
        while i < len(consonantes):
            #En el caso que sea consonante se agrega a lo que ya se tiene acumulado
            #en la variable cadenaConsonantes
            if consonantes[i]==verso[j]:
                cantidadConsonantes+=1

            i+=1

        j+=1

    return cantidadConsonantes

##BLOQUE PRINCIPAL

#Datos de entrada
#Se llama la función con el fin de leer el archivo texto.txt y almacenar la
#información
texto = leer("texto.txt")

#Procesamiento
#Se crean variables para almacenar la cantidad de consonantes y varoables
cantidadVocales = 0
cantidadConsonantes = 0
i = 0
#Se recorre la lista texto que contiene en cada posición un string con un un verso
while i < len(texto):
    #Se llaman las funciónes para contar las consonantes y vocales de una estrofa
    #Repitiendolo hasta que se analice en este caso la canción de froma completa
    cantidadConsonantes=contadorConsonantes(cantidadConsonantes,texto[i])
    cantidadVocales=contadorVocales(cantidadVocales,texto[i])
    i+=1

#Salida
print("Consonates:",cantidadConsonantes)
print("Vocales:",cantidadVocales)
