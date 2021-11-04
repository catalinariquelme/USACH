print()
print("EJERCICIO 3")
print()
#Construya un programa que reciba como entrada un texto a través de 
#archivo y una palabra e indique si la palabra está en el texto o no

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

#Función que cuenta cuantas veces se encuentra una determinada palabra
#en una oración
#Entrada: enter(número de palabras ya contadas),lista(contiene str con palabas de la oración),
#string(palabra a buscar en la oración)
#Salida: entero(número de palabras encontradas en la oración)
def numeroPalabraOracion(numeroPalabras,listaFrase,palabra):
    i = 0
    #Se recorre las palabras de la oración a analizar
    while i < len(listaFrase):
        #Se pasa a minúscula en caso de que alguna de las letras se encuentre en mayúscula
        #para lograr comparar de manera correcta
        listaFrase[i]=listaFrase[i].lower()
        #En el caso que se encuentre una coinidencia se aumenta la variable que almacena el número
        #de palabras encontradas hasta el momento
        if palabra == listaFrase[i]:
            numeroPalabras +=1

        i+=1
        
    return numeroPalabras

##BLOQUE PRINCIPAL

#Datos de entrada
palabraOriginal = input("Ingrese una palabra: ")

#Procesamiento
#Se almacena la palabra a buscar en minúscula para lograr hacer una mejor comparación
#Se guarda la anterior para cuando se imprima salga con las mayúsculas correspondientes
palabra = palabraOriginal.lower()
#Se llama la función con el fin de leer el archivo texto.txt y almacenar la
#información
texto = leer("texto.txt")
numeroPalabras = 0
i=0
#Se recorre la lista texto
while i < len(texto):
    #Se determina que cada posicion de la lista es una oración
    oracion = texto[i]
    #Se separa el string de la oración en palabras para lograr compaarar
    listaOracion = oracion.split(" ")
    #Se llama la función para lograr analizar las palabras de i oración
    numeroPalabras = numeroPalabraOracion(numeroPalabras,listaOracion,palabra)
    i+=1
    
#Datos de salida
#Se imprimen los resultados
if numeroPalabras == 0:
    print("La palabra "+palabraOriginal+" no se encuentra en el texto.")
else:
    print("La palabra "+palabraOriginal+" se encuentra",numeroPalabras,"veces.")
