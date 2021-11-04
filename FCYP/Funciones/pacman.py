#El input va a entrar separados por espacios
pacman = "P o o o o o o G"
puntaje = 0
vidaPacman = True
vidaFantasma = True

listaPacman = pacman.split(" ")
vidaPacman = listaPacman.count("P")

#Se ejecuta mientras esten vivos Pacman y el Fantasma
while vidaPacman == True and vidaFantasma == True:
    #Se identifica en que posicion se encuentra la letra P
    posicionPacman = listaPacman.index("P")
    #Si es un o Pacman agrega 100 puntos
    if listaPacman[posicionPacman + 1] == "o":
        puntaje += 100
    #En el caso que sea O Pacman esta habilitado para comerse al fantasma por 6 puntos
    elif listaPacman[posicionPacman + 1] == "O":
        ataque = True
    #En el caso que se encuentre con el fantasma podra comer o ser comido por el fantasma
    elif listaPacman[posicionPacman + 1] == "G":
        #Si antes se habia topado con un O podra comerse al fantasma
        if ataque == True:
            puntaje += 500
            posicionFantasma = listaPacman.index("G")
            listaPacman[posicionFantasma] = "_"
            print(listaPacman)
            break
        #El fantasma se come a Pacman
        else: 
            vidaPacman =False
            print(listaPacman)
            break
        
    listaPacman[posicionPacman+1]= "_"
    listaPacman.insert(posicionPacman,listaPacman.pop(posicionPacman+1))

    #Fantasma
    ataque = True
    posicionFantasma = listaPacman.index("G")
    if listaPacman[posicionFantasma - 1] == "o"or listaPacman[posicionFantasma - 1] == "O":
        pass

    elif listaPacman[posicionFantasma - 1] == "P":
        #Se come al fantasma
        if ataque == True:
            puntaje += 500
            posicionFantasma = listaPacman.index("G")
            listaPacman[posicionFantasma] = "_"
            print("caca")
            print(listaPacman)
            vidaFantasma = False
        #El fantasma se come a Pacman
        else: 
            print("te comieron")
            vidaPacman = False
    listaPacman[posicionFantasma-1]= "_"
    listaPacman.insert(posicionFantasma,listaPacman.pop(posicionFantasma-1))
    print(listaPacman)
print(puntaje)