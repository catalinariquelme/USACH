#Basquetball efectividad

#En el caso que solo exista UN puntaje máximo
def eficiencia_jugadores(jugadores):

    nJugadores = len(jugadores)
    i = 0
    puntajes = []

    #Recorriendo a los diversos jugadores
    while i < nJugadores:
        j = 0
        nPartidos = len(jugadores[i])
        puntos = 0

        #Recorriendo los partidos de cada uno de los jugadores
        #Sacando el promedio de puntos de todos los partidos
        #Agregandolos a una lista en donde se almacenan los puntos de todos los jugadores
        while j < nPartidos:
            puntos += jugadores[i][j]
            j +=1
        
        puntos /= nPartidos
        puntajes.append(puntos)
        i +=1

    #Con función nativa se identifica el número más alto
    puntajeAlto = max(puntajes)

    #Se consulta el en que indice se encuentra el puntajeAlto dentro de la lista puntajes
    indice = puntajes.index(puntajeAlto)

    #Se crea una lista jugadorEficiente que contiene el indice(número de jugador) y su respectivo puntaje de eficiencia
    jugadorEficiente = []
    jugadorEficiente.append(indice)
    jugadorEficiente.append(puntajeAlto)

    return jugadorEficiente

jugadores = [[20,20,35,40],[53,42],[25,14,19]] #A modo de práctica
print(eficiencia_jugadores(jugadores))