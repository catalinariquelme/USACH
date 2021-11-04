
textoOriginal = "En fluidodinámica la velocidad límite o velocidad final es la velocidad máxima que alcanza un cuerpo de un fluido infinito bajo la acción de una fuerza constante"

print(textoOriginal)

texto = textoOriginal.split(" ")

def censurar_pabras(palabraPorCensurar,texto):
    i = 0
    posicionesPalabras = []

    #Se edentifica en que indices se encuentran las palabras, se guardan en una lista
    while i < len(texto):
        if texto[i] == palabraPorCensurar:
            posicionesPalabras.append(i)
        i += 1

    i = 0

    #Con la lista de los indices se identifica en que parte se encuentran las palabras
    #Una vez identificada la palabra se analiza solo ese indice
    while i < len(posicionesPalabras):
        palabra = texto[posicionesPalabras[i]]
        j = 0
        listaPalabra = []

        #Se convierte cada letra de la palabra en un objeto de una lista con el finde modificarse
        while j < len(palabra):
            listaPalabra.append(palabra[j])
            j +=1
        j = 1
        #Se modifica cada una de las letras por un *, excepto la primera
        while j < len(listaPalabra):
            listaPalabra[j]="*"
            j+=1
        censura = "".join(listaPalabra)
        texto[posicionesPalabras[i]] = censura
        i +=1

    string = " ".join(texto)
    return string

#La varialble texto termina despejada

palabraPorCensurar= input("Palabra a censurar: ")
caca = censurar_pabras(palabraPorCensurar,texto)
print(caca)

palabraPorCensurar= input("Otra: ")
caca2 = censurar_pabras(palabraPorCensurar,texto)
print(caca2)