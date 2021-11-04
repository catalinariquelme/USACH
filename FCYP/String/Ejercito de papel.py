#o enemigos
#x nuestros
#* fuego
#Si hay un x todos los enemigos mueren, no pueden pasar fuego (*)

batalla = "oooo*oo*xoxx**xo" #input("Ingrese campo de batalla: ")
#Se crea una lista que adentro tiene strings (divididos por *)
batalla = batalla.split("*")
enemigosTotales = 0
j = 0
#Se recorre la lista
while j<len(batalla):
    soldado = False
    enemigosVivos = 0
    i = 0
    #Se recorre el string
    while i<len(batalla[j]):
        #Si la posicion es un enemigo y ademas no se a encontrado ningun soldado, se cuenta
        if batalla [j][i]== "o" and soldado == False:
            enemigosVivos +=1
        #En cambio si se ecnontro un soldado se reinicia el conteo que se tenia y se
        #indica que se encontro un soldado para que no siga contando enemigos
        elif batalla[j][i] == "x":
            enemigosVivos = 0
            soldado = True
        i+=1
    #Los enemigos encontrados entre * se suman a los enemigos totales 
    enemigosTotales += enemigosVivos
    j +=1
print("Enemigos que quedan vivos:",enemigosTotales)