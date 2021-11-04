#S = Stroud (primera posiciónn siempre)
#C = Camino libre
#G = Camino con guardia
#L = LLave
#S = Salida

#La salida cuenta como una área por recorrer (1 hora la primera vez que la recorre)
#Tomando en cuenta que el usuario coloca una llave

mapa = "S C G S L C"#input("Ingrese la ruta separada por espacios")
tiempoLimite = int(input("Ingrese cuanto tiempo (en horas) cuenta para escapar: "))
mapa.isupper()
mapa = mapa.split(" ")

#Se elimina el primer elemento ya que correponde al personaje
mapa.pop(0)

#Existen dos cosas, uno en donde la llave se encuentre antes de la salida
#o por el contrario la salida se encuentre antes que la llave
#en este caso se debe recorrer nuevamente la lista pero en la mitad de tiempo

posicionSalida = mapa.index("S")
posicionLlave = mapa.index("L")

#Funcion que determina cuanto tiempo tarda sefun el mapa y si es primera vez que ve el área
def tiempo_que_se_tarda(mapa,numero_de_vueltas):
    tiempo = 0 #Cuanto timepo va a tardar (total) en minutos
    i = 0 #Contador posicion letras mapa

    while i < len(mapa):
        #En el caso que mientras de su 1 vuelta y encuentre la salida, quedando aun areas, no las toma en cuenta
        #para el tiempo final
        if i >= posicionSalida and numero_de_vueltas == 1:
            break
        
        #En el caso que este la segunda vuelta y encuentra la salida se rompe el ciclo
        if i == posicionSalida and numero_de_vueltas == 2:
            break

        if mapa[i] == "C" or mapa[i] == "S":
            tiempo += 60/numero_de_vueltas
        elif mapa[i] == "G":
            tiempo += 120/numero_de_vueltas
        i +=1

    return tiempo

#En el caso que la llave se encuentre antes que la salida
if posicionLlave < posicionSalida:
    tiempo = tiempo_que_se_tarda(mapa,1)

#En el caso que la llave se encuentre despues de la salida y tenga que dar una segunda vuelta
else:
    tiempo = tiempo_que_se_tarda(mapa,1) + tiempo_que_se_tarda(mapa,2)

#Trabajando con los tiempos
def minutos_a_horas(minutos):
    horas = minutos // 60
    minutosDeHoras = minutos % 60
    return int(horas),int(minutosDeHoras)

tiempoLimite *= 60
tiempoSobrante = tiempoLimite - tiempo

if tiempoLimite < tiempo:
    print("No cuenta con el suficiente tiempo para escapar")

elif tiempoLimite >= tiempo:
    tiempo = minutos_a_horas(tiempo)
    tiempoSobrante = minutos_a_horas(tiempoSobrante)

    print("Logra escapar")
    print("En un tiempo de:",tiempo[0],"horas y",tiempo[1],"minutos")
    print("Restandole: ",tiempoSobrante[0],"horas y",tiempo[1],"minutos")
