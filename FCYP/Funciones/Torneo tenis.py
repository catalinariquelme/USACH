#Escriba un programa para simular un campeonato de tenis.

#Primero, debe pedir al usuario que ingrese los nombres de ocho tenistas. A continuación, 
# debe pedir los resultados de los partidos juntando los jugadores de dos en dos. 
# El ganador de cada partido avanza a la ronda siguiente.

#El programa debe continuar preguntando ganadores de partidos hasta que quede 
# un único jugador, que es el campeón del torneo.

Jugador1 = "Nadal"#input("Jugador 1: ")
Jugador2 = "Melzer"#input("Jugador 2: ")
Jugador3 = "Murray"#input("Jugador 3: ")
Jugador4 = "Soderling"#input("Jugador 4: ")
Jugador5 = "Djokovic"#input("Jugador 5: ")
Jugador6 = "Berdych"#input("Jugador 6: ")
Jugador7 = "Federer"#input("Jugador 7: ")
Jugador8 = "Ferrer"#input("Jugador 8: ")

jugadores = [Jugador1,Jugador2,Jugador3,Jugador4,Jugador5,Jugador6,Jugador7,Jugador8]

import random 

def ganadores_uwu(jugadores,cuantosSon):
    jugadoresTotales = cuantosSon
    i = 0
    finalistas = []

    while i < jugadoresTotales:
        ganador = random.choice(["a","b"])
        print("a.",jugadores[i],"b.",jugadores[i+1],":",ganador)

        if ganador == "a":
            finalistas.append(jugadores[i])
        elif ganador == "b":
            finalistas.append(jugadores[i+1])
        i +=2
    return finalistas

print()

print("Ronda 1")
jugadores = ganadores_uwu(jugadores,8)
print(jugadores)

print()

print("Ronda 2")
jugadores = ganadores_uwu(jugadores,4)
print(jugadores)

print()

print("Ronda 3")
jugadores = ganadores_uwu(jugadores,2)
print(jugadores)

print("Campeón: ",jugadores[0])