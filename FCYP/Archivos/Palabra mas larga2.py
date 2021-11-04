print()
print("EJERCICIO 2")
print()
#Construya un programa que encuentre la palabra más larga en un texto, 
#considere que el texto le será entregado desde un archivo llamado ‘texto.txt’

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

#Se llama la función con el fin de leer el archivo texto.txt y almacenar la
#información
texto = leer("texto.txt")
#Se recorre la lista texto con el fin de convertir todo en un solo string
#Dejando todo en la posición 0
while len(texto) > 1:
    #Se suma el string siguiente al primero, luego se borra
    texto[0]= texto[0]+ " "+texto[1]
    texto.pop(1)

#El string se separa en palabras y se almacena
listaTexto = texto[0].split(" ")
j=0
#Se recorre la lista listaTexto con la finalidad de ir dejando la palabra más 
#larga al final
while j < len(listaTexto)-1:
    i = 0
    while i < len(listaTexto)-1:
        #En el caso que la palabra sea mayor que la siguiente se mueve
        if len(listaTexto[i]) > len(listaTexto[i+1]):
            listaTexto.insert(i,listaTexto.pop(i+1))
        i += 1
    j +=1

print("Palabra más larga:",listaTexto[len(listaTexto)-1])

