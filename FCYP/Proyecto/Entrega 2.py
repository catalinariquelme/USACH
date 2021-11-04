#SECCIÓN DE LABORATORIO: 0-G-3
#PROFESOR DE LABORATORIO: NICOLE HENRÍQUEZ
#PROFESOR DE TEORIA: ALEJANDRO CISTERNA
#INTEGRANTES
#1.
#NOMBRE: Emilio Acuña Espinoza
#RUT:20.534.508-6
#CARRERA: Ingeniería Civil Obras Civiles
#2.
#NOMBRE: Ricardo Avaca Montecinos
#RUT:20.655.745-1
#CARRERA: Ingeniería Civil Informática
#3.
#NOMBRE: Catalina Riquelme Zamora
#RUT: 20.642.812-0    
#CARRERA: Ingeniería de Ejecución en Computación e Informática

#Fecha: 03/09/2020
#VERSION:3.9
#Objetivo: Sistema de combate automático entre un personaje elegido por el usuario y un personaje, enemigo aleatorio implementando el modelo autamtico ATB, ahora con mas elementos RPG


#BLOQUE DE FUNCIONES#

#Importación de constantes
#no hay

#Definición de constantes
#no hay

#Importación de funciones
from random import randint
from time import sleep
from random import choice

#Funcion para calcular el aumento de atributos de los personajes y enemigos dependiendo del nivelw
#Entrada:Datos de los personajes y enemigos
#Salida:Los datos que tienen que cambiar debedido al aumento de nivel
def aumentoAtributo(atributoEnNivel1,experienciaMaxima):
    aumentoAlAtributo = (atributoEnNivel1*experienciaMaxima)/1000000
    aumentoAlAtributo = round(aumentoAlAtributo)
    return aumentoAlAtributo

#Funcion para aumentar las estadisticas cuando el personaje sube de nivel   
#Entrada:Datos Originales del personaje, datos del personaje, Datos de Persona
#Salida:Estadisticas aumentadas que se reemplazan en la lista del personaje 
def aumentoPorNivel (personaje,datosPersonajeOriginal,datosPersonajeAumentados):
    #Aumento de la vida
    personaje[0] = datosPersonajeAumentados[0] + aumentoAtributo(datosPersonajeOriginal[0],personaje[12])
    personaje[2] = datosPersonajeAumentados[2] + aumentoAtributo(datosPersonajeOriginal[2],personaje[12])
    personaje[3] = datosPersonajeAumentados[3] + aumentoAtributo(datosPersonajeOriginal[3],personaje[12])
    personaje[8] = datosPersonajeAumentados[8] + aumentoAtributo(datosPersonajeOriginal[8],personaje[12])
    personaje[9] = datosPersonajeAumentados[9] + aumentoAtributo(datosPersonajeOriginal[9],personaje[12])
    personaje[10] = datosPersonajeAumentados[10] + aumentoAtributo(datosPersonajeOriginal[10],personaje[12])
    personaje[11] = datosPersonajeAumentados[11] + aumentoAtributo(datosPersonajeOriginal[11],personaje[12])
    return True
#Funcion para calcular la experiencia tras una batalla ganada por el personaje
#Entrada: Numeros de combate
#Salida: experiencia (float)

def calculoExperiencia(experienciasOp,nivelesOp,nivelPersonaje,factorCrit,op):
    experiencia = (experienciasOp*(nivelesOp/nivelPersonaje)*factorCrit*(1+op))/7
    #Se aproxima la experiencia
    experiencia = round(experiencia)
    return experiencia

#Funcion para determinar la experiencia por niveles
#Entrada:Un string que determina el tipo de crecimiento
#Salida:Una Formula que determina la experiencia necesaria para alcanzar un determinado nivel
def experienciaPorNivel(tipoCrecimiento,nivel):
    #Se asignan los tipos de crecimiento dependiendo de las formulas
    if tipoCrecimiento == "rapido":
        experienciaEnNivel = (4*nivel**3)/5
        
    elif tipoCrecimiento == "medio":
        experienciaEnNivel = nivel**3
        
    elif tipoCrecimiento == "lento":
        experienciaEnNivel = (5*nivel**3)/4
    
    elif tipoCrecimiento == "ultraLento":
        experienciaEnNivel = (7*nivel**3)/4
    
    #Retorna el valor calculado
    return experienciaEnNivel

#Función para seleccionar de los enemigos
#Entrada: entero que determine al enemigo
#Salida: lista con los datos del enemigo
def seleccionEnemigo(enemigoElegir):#Funcion para la seleccion de Enemigos
    #Lista con la información de los enemigos 
    #enemigo = [Puntos de vida,velocidad,ataque,defensa,umbral de hechizo,PHA,PHD,PHC,daño mínimo,daño máximo,experiencia máxima,
    #nivel,nombre,tipo de crecimiento]
    kobold = [4,2,2,12,20,0,0,4,1,6,0,0,800000,1,"Kobold", "rapido"]#1
    goblin = [6,4,1,12,0,0,0,0,1,4,0,0,1000000,1,"Goblin","medio"]#2
    guerreroOrco = [12,2,5,14,0,0,0,0,1,8,0,0,1250000,1,"Guerrero Orco","lento"]#3
    ##################Colocar una condicion de balance para que funcione con los demas enfrentamientos 
    #En el caso que el enemigo sea 1 se le asigna la lista kobold
    if enemigoElegir == 1:
        enemigo = kobold[:]
        
    #En el caso que el enemigo sea 2 se le asigna la lista goblin
    elif enemigoElegir == 2:
        enemigo = goblin[:]
        
    #En el caso que el enemigo sea 3 se le asigna la lista guerrero orco
    elif enemigoElegir == 3:
        enemigo = guerreroOrco[:]
        
    return enemigo

#Funcion para ejecutar el Turno del Enemigo
#Entrada: lista con los datos del enemigo,lista con los datos del personaje,booleano turno enemigo, lista con los datos iniciales del enemigo
#Salida: Booleano determinando si termino o no el turno del enemigo
def accionEnemigo (datosEnemigo, datosPersonaje, turnoEnemigo,datosEnemigoOriginal):#########################
    #En el caso que la vida sea negativa o igual a cero termina el turno del enemigo
    if datosEnemigo[0] <= 0:
        turnoEnemigo = False
        
    #Por el contrario el enemigo realiza acciones
    else:
        print("Atacará", datosEnemigo[14])
        print("Turno enemigo")
        #Se le pide al usuario que presione enter para tener un mejor control del terminal, [reemplazar por sleeps("Inserte cantidad de tiempo que quiere robar")]
        #Y evitar que demasiado texto se imprima en poco tiempo
        señalInicio= input("Presione cualquier tecla para continuar: ")
        print()
        print("Cuando se complete la barra el enemigo podrá atacar")
        print()
        #Se realiza un ciclo que vaya imprimiendo la actualización cada cierto tiempo de la barra Gauge
        barraOriginal = "| ░ ░ ░ ░ ░ ░ ░ ░ ░|"
        barraLista = barraOriginal.split(" ")
        #Se imprime la barra vácia que con el tiempo se irá llenando
        print("|░░░░░░░░░░|")
        i = 0 
        #Se recorre la barra con el fin de llenarla en un determinado tiempo
        while i < len(barraLista):
            #Se utiliza la función sleep para regular el tiempo con el que se imprime la barra
            sleep(1/datosEnemigo[1]) 
            if i == 0:
                barraLista[i] = "|█"
                barra = "".join(barraLista)
                print(barra)
                i +=1
            elif i == len(barraLista)-1:
                barraLista[i] = "█|"
                barra = "".join(barraLista)
                print(barra)
                i +=1
            else:
                barraLista[i] = "█"
                barra = "".join(barraLista)
                print(barra)
                i +=1
                
        #Se va a elegir por el enemigo entre ataque y hechizo
        ataqueHechizo = randint(1,2)
        #Ataque
        # Si toca 1 se realiza el ataque
        if ataqueHechizo == 1:
            print()
            print("Enemigo ha escogido Ataque")
            #Se escoge un número al azar entre 1 y 20
            numeroAleatorio = randint(1,20)
            #En base al número aleatorio se suma con el ataque del enemigo para determinar
            #el número de ataque
            numeroAtaque = datosEnemigo[2] + numeroAleatorio
            #Si el número de ataque es mayor a la defensa del personaje puede atacar
            if numeroAtaque >= datosPersonaje[3]:
                #Fallo
                #Si el número al azar es 1 ocurre un excepción el cual beneficia al personaje
                #dañando al propio enemigo
                if  numeroAleatorio == 1: 
                    print("La vida del enemigo es de ",datosEnemigo[0],"de vida")
                    #Se determina el número de fallo entre 1 y 3
                    numeroFallo = randint(1,3)
                    #Se le resta el número de fallo al enemigo
                    datosEnemigo[0] = datosEnemigo[0]-numeroFallo       
                    print("El enemigo falló el ataque y se hizo daño a el mismo")
                    print("Le quedan",datosEnemigo[0],"de vida al enemigo")
                    
                #Crítico
                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                elif numeroAleatorio == 20:
                    print()
                    print("El enemigo logró realizarte daño")
                    print()
                    print("CRÍTICO")
                    print("Te quedan",datosPersonaje[0],"de vida")
                    #El daño del enemigo aumenta 2* por un valor dado por un número al azar entre el daño
                    #mínimo y máximo del enemigo
                    daño= 2*(randint(datosEnemigo[8],datosEnemigo[9]))
                    #Se le resta el daño calculado al personaje
                    datosPersonaje[0] = datosPersonaje[0] - daño
                    print("El enemigo te hizo",daño,"de daño")
                    print("Te queda ",datosPersonaje[0],"de vida")
                    print()
                #Para cualquiero otro caso el procedimiento es normal
                else:
                    print()
                    print("El enemigo realizar un ataque con éxito")
                    print()
                    #Se determina el daño que realiza entre el daño mínimo y máximo del enemigo
                    daño = randint(datosEnemigo[8],datosEnemigo[9])
                    print("Tú vida actual es:",datosPersonaje[0])
                    print("El enemigo te realizado",daño,"de daño")
                    #Se le resta la vida al personaje
                    datosPersonaje[0] = datosPersonaje[0] - daño
                    print("Tú vida ahora es:", datosPersonaje[0])
                    print()
            else:#El enemigo no pudo superar el dato de defensa del personaje
                print()
                print("El enemigo falló el ataque")
                print()
            turnoEnemigo= False
            
        #Hechizo
        elif ataqueHechizo ==2:
            print()
            print("Enemigo ha escogido Hechizo")
            print()
            
            umbral = randint(1,20)
            
            if umbral > datosEnemigo[4]:
                
                valor = randint(0,100)
                #Hechizo de Ataque
                if valor < datosEnemigo[5]:
                    print("El enemigo va a realizar Hechizo de ataque")
                    #Crítico
                    if valor == 20: 
                        print("CRÍTICO")
                        print()
                        daño = int(randint(datosEnemigo[10],datosEnemigo[11])*1.5)
                        print("Tú vida actual es:",datosPersonaje[0])
                        print("El enemigo logro realizarte",daño,"de daño")
                        datosPersonaje[0] = datosPersonaje[0] - daño
                        print("Tú nueva vida es de:",datosPersonaje[0])
                        print()
                        
                    #Fallo
                    elif valor ==1:
                        print("La vida del enemigo es de:",datosEnemigo[0])
                        print("El enemigo fallo al realizar Hechizo de Ataque")
                        datosEnemigo[0] = int(datosEnemigo[0]/2)
                        print("Realizandose el Hechizo de Ataque contra el mismo")
                        print("La vida del enemigo se redujo a la mitad")
                        print("La vida actual del enemigo es:",datosEnemigo[0])
                        print()
                        
                    #Para cualquier otro caso el procedimiento es el mismo
                    else:
                        daño = randint(datosEnemigo[10],datosEnemigo[11])
                        print("Tu vida es:",datosPersonaje[0])
                        print("El enemigo realizó",daño,"de daño")
                        datosPersonaje[0] = datosPersonaje[0] - daño
                        print("Tú nueva vida es:", datosPersonaje[0])
                        print()
                        
                #Hechizo de Defensa
                elif valor < datosEnemigo[6]:
                    print("Enemigo va a realizar Hechizo de Defensa")
                    #Crítico
                    if valor == 20:
                        print("CRÍTICO")
                        print()
                        print("La defensa del enemigo es:",datosEnemigo[3])
                        datosEnemigo[3]= datosEnemigo[3] + 2
                        print("La defensa del enemigo ha aumentado en 2")
                        print("La nueva defensa del enemigo es",datosEnemigo[3])
                        print()
                        
                    #Fallo
                    elif valor == 1:
                        print("FALLO")
                        print()
                        print("Tú defensa es: ",datosPersonaje[3])
                        datosPersonaje[3] = datosPersonaje[3] +1
                        print("El enemigo ha fallado el Hechizo")
                        print("A aumentado tú defensa")
                        print("Tú nueva defensa es: ",datosPersonaje[3])
                        print()
                        
                    #En cualquier otro caso el procedimiento es el normal
                    else:
                        print("La defesa del enemigo es:",datosEnemigo[3])
                        datosEnemigo[3] += 1
                        print("Ha aumentado la defensa del enemigo")
                        print("Ahora su defensa es :",datosEnemigo[3])
                        print()
                        
                #Hechizo de Curación
                elif valor < enemigo[7]:
                    print("El enemigo va a realizar Hechizo de Curación")
                    #Crítico
                    if valor == 20:
                        print("CRÍTICO")
                        print()
                        print("La vida del enemigo es: ",datosEnemigo[0])
                        if datosEnemigo[0] == datosEnemigoOriginal[0]: #Re-definir Curacion crítica!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                            print("Enemigo no se pudo curar ya que tiene vida al máximo")
                            print()
                            
                        else:
                            datosEnemigo[0] +=4
                            print("El enemigo se a curado 4 de vida")
                            if datosEnemigo[0] > datosEnemigoOriginal[0]:
                                datosEnemigo[0] = datosEnemigoOriginal #Esto tambien es parte!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                print("La nueva vida del enemigo es: ",datosEnemigo[0])
                                
                            else:
                                print("La nueva vida del enemigo es: ",datosEnemigo[0])
                                
                            print()
                    #Fallo
                    elif valor == 1:
                        print("El enemigo ha fallado el Hechizo de curación y te curo a ti")
                        print("Tú vida actual es:",datosPersonaje[0])
                        datosPersonaje[0]+=4
                        if datosPersonaje[0] == datosPersonajeOriginal:
                            print("No te has podido curar porque tienes la vida al máximo")#No te puedes sobre curar
                            
                        else:
                            print("Y te a curado 4 de vida")
                            if datosPersonaje[0] >datosPersonajeOriginal[0]:
                                datosPersonaje[0]= datosPersonajeOriginal
                                print("Tu nuevo nivel de vida es: ",datosPersonaje[0])
                                
                            else:
                                print("Tu nuevo nivel de vida es: ",datosPersonaje[0])
                                
                        print()
                        
                    else:
                        if datosEnemigo[0] == datosEnemigoOriginal[0]:#Enemego no se puede curar porque tiene la vida full
                            print("El enemigo no se pudo curar ya que tiene la vida al máximo")
                            print()
                            
                        else:#Curacion
                            cura = randint(1,8)
                            print("Se va curar ", cura ,"de vida")
                            datosEnemigo[0]= datosEnemigo[0] + cura
                            if datosEnemigo[0] > datosEnemigoOriginal[0]:
                                datosEnemigo[0] = datosEnemigoOriginal[0]
                                print("La nueva vida del enemigo es:",datosEnemigo[0])
                            else:
                                print("La nueva vida del enemigo es:",datosEnemigo[0])
                            print()
                            
                #Ataque Simple
                else:
                    print("El enemigo realizó Ataque Simple")
                    print()
                    daño = randint(datosEnemigo[8],datosEnemigo[9])
                    print("Tú vida actual es:",datosPersonaje[0])
                    datosPersonaje[0] = datosPersonaje[0] - daño
                    print("El enemigo te ha quitado",daño,"de vida")
                    print("Ahora te quedan",datosPersonaje[0], "puntos de vida")
                    print()
                #Termina el turno de enemigo
                turnoEnemigo = False
            else:
                print("El enemigo fallo al realizar el Hechizo")
                print() 
                
    return turnoEnemigo
    
#Función que realiza la batalla sin imprimir datos al usuario, lado enemigo    
#Entrada: lista con los datos del enemigo,lista con los datos del personaje,booleano turno enemigo, lista con los datos iniciales del enemigo
#Salida: Booleano determinando si termino o no el turno del enemigo
def accionEnemigoSkip (datosEnemigo, datosPersonaje, turnoEnemigo,datosEnemigoOriginal):
    #En el caso que la vida del enemigo sea menor o igual a 0 acaba el turno del enemigo
    if datosEnemigo[0] <= 0:
        turnoEnemigo = False
    else:
        #Se elige por el enemigo entre ataque y hechizo
        ataqueHechizo = randint(1,2)
        #Ataque
        # Si toca 1 se realiza el ataque
        if ataqueHechizo == 1:
            #Se escoge un número al azar entre 1 y 20
            numeroAleatorio = randint(1,20)
            #En base al número aleatorio se suma con el ataque del enemigo para determinar
            #el número de ataque
            numeroAtaque = datosEnemigo[2] + numeroAleatorio
            #Si el número de ataque es mayor a la defensa del personaje puede atacar
            if numeroAtaque >= datosPersonaje[3]:
                #Fallo
                #Si el número al azar es 1 ocurre un excepción el cual beneficia al personaje
                #dañando al propio enemigo
                if  numeroAleatorio == 1: 
                    #Se determina el número de fallo entre 1 y 3
                    numeroFallo = randint(1,3)
                    #Se le resta el número de fallo al enemigo
                    datosEnemigo[0] = datosEnemigo[0]-numeroFallo      
                    
                #Crítico
                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                elif numeroAleatorio == 20:
                    #El daño del enemigo aumenta 2* por un valor dado por un número al azar entre el daño
                    #mínimo y máximo del enemigo
                    daño= 2*(randint(datosEnemigo[8],datosEnemigo[9]))
                    #Se le resta el daño calculado al personaje
                    datosPersonaje[0] = datosPersonaje[0] - daño
                    
                #Para cualquiero otro caso el procedimiento es normal
                else:
                    #Se determina el daño que realiza entre el daño mínimo y máximo del enemigo
                    daño = randint(datosEnemigo[8],datosEnemigo[9])
                    #Se le resta la vida al personaje
                    datosPersonaje[0] = datosPersonaje[0] - daño
            
            #El turno del usuario termino
            turnoEnemigo= False
            
        #Hechizo
        elif ataqueHechizo ==2:
            #Se determina el umbral del enemigo eligiendo un número al azar entre 1 y 20
            umbral = randint(1,20)
            #Si el número es mayor al umbral puede realizar un Hechizo
            if umbral > datosEnemigo[4]:
                valor = randint(1,100)
                #Hechizo de Ataque
                if valor < datosEnemigo[5]:
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    if valor == 20: 
                        #Se determina el daño que realizará el personaje a través de un número al azar entre el
                        #daño de hechizo máximo y mímino del personaje, este tiene que ser entero
                        daño= int(randint(datosEnemigo[10],datosEnemigo[11])*1.5)
                        #Se le resta la el daño al personaje
                        datosPersonaje[0] = datosPersonaje[0] - daño
                        
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al personaje
                    elif valor ==1:
                        #Se le resta la mitad de la vida al enemigo, tiene que ser entero
                        datosEnemigo[0] = int(datosEnemigo[0]/2)
                        
                    #Para cualquier otro caso el procedimiento de Hechizo normal
                    else:
                        #Se determina el daño que realiza entre el daño de hechizo máximo y mínimo
                        daño = randint(datosEnemigo[10],datosEnemigo[11])
                        #Se le resta el daño provocado por el personaje al enemigo
                        datosPersonaje[0] = datosPersonaje[0] - daño
                        
                #Hechizo de Defensa
                elif valor < datosEnemigo[6]:
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    if valor == 20:
                        #Aumenta la defensa en 2
                        datosEnemigo[3]= datosEnemigo[3] + 2
                        #Se suma a la variable para decidir FactorCrit
                        
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al personaje
                    elif valor == 1:
                        #Aumenta en 1 el valor de la defensa del enemigo
                        datosPersonaje[3] = datosPersonaje[3] +1
                        
                    #En cualquier otro caso el procedimiento de Hechizo de Defensa normal
                    else:       
                        #Aumenta en la defensa del enemigo en 1
                        datosEnemigo[3] += 1
                        
                #Hechizo de Curación
                elif valor < datosEnemigo[7]:
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                    if valor == 20:
                        #Se restaura 4 puntos de vida del enemigo
                        datosEnemigo[0] +=4
                        #Si los puntos de curación superan los límites originales, quedará con el puntaje original
                        #ya que la vida no puede superar los datos originales
                        if datosEnemigo[0] > datosEnemigoOriginal[0]: #AQUI se tiene que re-definir como se cura!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                            datosEnemigo[0] = datosEnemigoOriginal
                                
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    elif valor == 1:
                        #Se le aumenta 4 a la vida del enemigo
                        datosPersonaje[0]+=4
                        #Si el puntaje de curado supera el límite de vida, quedará el puntaje original ya que no se pueden
                        #superar esos valores
                        if datosPersonaje[0] >datosPersonajeOriginal[0]:
                            datosPersonaje[0]= datosPersonajeOriginal
                        
                    #En cualquier otro caso se seguirá con un Hechizo de Curación normal
                    else:
                        #Se elige un número al azar entre 1 y 8 con el fin de curar al enemigo
                        cura = randint(1,8)
                        datosEnemigo[0]= datosEnemigo[0] + cura
                        #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                        if datosEnemigo[0] > datosEnemigoOriginal[0]:
                            datosEnemigo[0] = datosEnemigoOriginal[0]
                    
                #Ataque Simple
                #En el caso que no se puede realizar HA, HD y HC, el personaje ataca normalmente
                else:
                    #Se determina el daño que va a realizar el enemigo con un número al azar entre el daño
                    #máximo y mínimo
                    daño = randint(datosEnemigo[8],datosEnemigo[9])
                    #Se le resta el daño a la vida del personaje
                    datosPersonaje[0] = datosPersonaje[0] - daño
                    
                #Termina el turno de enemigo
                turnoEnemigo = False        
            
    return turnoEnemigo
    
#Función que realiza la batalla sin imprimir datos al usuario, lado usario
#Entrada: lista con los datos del personaje, lista con los datos iniciales del personaje 
#Salida: print ganaste/perdiste
def skipBatalla(personaje,datosPersonajeOriginal,criticosHechos,fallosHechos,experiencia):
    #Para determinar a quien le toca primero se comparan las velocidades
    #Para determinar cuando empieza y acaba el turno del personaje se crea una variable que vuelve False cuando termina el turno
    print()
    if batalla % 10 == 0:
        #Estadisticas del Jefe, no puede lanzar hechizos y sus ataques son fuertes.
        #jefe = [Puntos de vida,velocidad,ataque,defensa,umbral de hechizo,PHA,PHD,PHC,daño mínimo,daño máximo,experiencia máxima,
        #nivel,nombre,tipo de crecimiento]
        jefe = [80,2,9,15,20,0,0,0,8,13,0,0,1250000,1,"Jefe","lento"]#Es un Orco guerrero Gigante(?)
        #Se determina al jefe como enemigo, esto será durante solo una batalla, en la siguiente será definido
        #nuevamente el enemigo
        enemigo = jefe[:]
        #Se respaldan los datos del jefe
        datosEnemigoOriginal = enemigo
        #Se define como 1 la cantidad de enemigos
        cantidadEnemigos = 1
        #Se colocan los datos de una lista de enemigos
        listaEnemigos = [enemigo]
        #Se coloca esta información dentro de una lista
        listaDatosEnemigosOriginal = [enemigo]
        jefe[13] = personaje[13]
        #Se coloca el nivel del jefe en la variable suma niveles enemigos
        sumaNivelesEnemigos = jefe[13]
        sumaExperienciaEnemigos = experienciaPorNivel(jefe[15], jefe[13])
        print()
        print("¡¡¡SE ACERCA UN JEFE!!!")
        print()
    
    #En el caso que no sea una batalla multiplo de 10, continuará con una batalla normal escogiendo enemigos
    #y la cantidad de ellos de manera aleatoria
    else:
        #Se determina al azar cuantos enemigos se tiene que enfrentar al usuario
        cantidadEnemigos = randint(1,3)
        print()
        print("Te enfrentaras a:",cantidadEnemigos,"enemigo: ")
        #Se crea una lista en donde se guardaran los datos de los enemigos
        listaEnemigos = []
        #La expericia de los enemigos se define e inicia como 0
        sumaExperienciaEnemigos = 0
        #Se definen los criticos hechos por el personaje e inicia como 0
        criticosHechos = 0

        #En el caso que sea un enemigo a enfrentar se crea solo una variable de enemigo
        if cantidadEnemigos == 1:
            #Se llama a la función que selecciona el enemigo al azar
            enemigo1  = seleccionEnemigo(randint(1,3))
            #Se almacena en la lista destinada a guardar los enemigos
            listaEnemigos = [enemigo1]
            print(listaEnemigos[0][14])
            #Se define como enemigo al enemigo1 ya que no existen más contincantes
            enemigo = enemigo1[:]
            #Se respaldan los datos iniciales del enemigo
            datosEnemigoOriginal1 = enemigo1[:]
            #Se guardan los datos del enemigo 
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1]
            enemigo1[13] = personaje[13]
            #Se almacena el nivel del enemigo
            sumaNivelesEnemigos = personaje[13]
            #Se almacenan los datos ede la experiecia
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[15],enemigo1[13])
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 1
            while i <=  personaje[13]:
                nivelActual += experienciaPorNivel(enemigo1[15],i)
                if nivelActual < experienciaPorNivel(enemigo3[15],personaje[13]):
                    AumentoPorNivel(enemigo,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado)
                i+=1  
            
        #En el caso que sean dos enemigos a enfrentar
        elif cantidadEnemigos == 2:
            enemigo = randint(0,1)
            #Se elige un enemigo entre los tres enemigos disponibles
            enemigo1  = seleccionEnemigo(randint(1,3))
            #Se escoge el segundo enemigo
            enemigo2 = seleccionEnemigo(randint(1,3))
            #En el caso que ambos enemigos sean los mismos se escoge otro de los 2 restantes
            while enemigo1 == enemigo2: # Para previnir que se duplicen enemigos
                enemigo2 = seleccionEnemigo(randint(1,3))

            enemigo1[13] = randint(1,personaje[13])
            enemigo2[13] = randint(1,personaje[13])
            #En el caso que los enemigos escogidos sean iguales se hace un ciclo en donde se escogen enemigos distintos
            while not (enemigo1[13] + enemigo2[13] < personaje[13] + 3) and not(enemigo1[13] + enemigo2[13] > personaje[13] - 3):
                enemigo1[13] = randint(1,personaje[13])
                enemigo2[13] = randint(1,personaje[13])
                
            #Se calcula la experiencia del enemigo 1
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[15],enemigo1[13])
            #Se calcula la experiencia del enemigo 2 y se suma a la del enemigo 1, dando el total de experiencia
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[15],enemigo2[13])
            #Se suman los niveles de los enemigos y se almacena
            sumaNivelesEnemigos = enemigo1[13] + enemigo2[13]
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 1
            while i <=  personaje[13]:
                nivelActual += experienciaPorNivel(enemigo1[15],i)
                if nivelActual < experienciaPorNivel(enemigo1[15],enemigo1[13]):
                    AumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado)
                i+=1  

            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 2
            while i <=  personaje[13]:
                nivelActual += experienciaPorNivel(enemigo2[15],i)
                if nivelActual < experienciaPorNivel(enemigo2[15],enemigo2[13]):
                    AumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado)
                i+=1  

            #Se colocan ambos datos de los enemigos en una lista
            listaEnemigos = [enemigo1,enemigo2]
            print(listaEnemigos[0][14],"y",listaEnemigos[1][14])
            enemigo = listaEnemigos[enemigo][:]
            #Se guardan los datos iniciales de los enemigos
            datosEnemigoOriginal1 = enemigo1[:]
            datosEnemigoOriginal2 = enemigo2[:]
            #Se guardan en una lista los datos iniciales de los enemigos
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2]
            
        #En el caso que sean tres enemigos a enfrentar
        elif cantidadEnemigos == 3:
            #Se elige un número entre el 0 y el 2 para posteriormente utilizar este número 
            #como indice para determinar un enemigo con el se comparen las velocidades
            enemigo = randint(0,2)
            #Se elige un enemigo entre los tres enemigos disponibles
            enemigo1 = seleccionEnemigo(randint(1,3))
            #Se escongen dos enemigos al azar
            enemigo2 = seleccionEnemigo(randint(1,3))
            enemigo3 = seleccionEnemigo(randint(1,3))
            #En el caso que se repitan los enemigos a enfrentar se escogen otros hasta que sean distintos
            while enemigo1 == enemigo2 or enemigo1 == enemigo3 or enemigo2 == enemigo3 :
                enemigo2 = seleccionEnemigo(randint(1,3))
                enemigo3 = seleccionEnemigo(randint(1,3))

            #Se agregan los datos de los enemigos a una lista 
            enemigo1[13] = randint(1,personaje[13])
            enemigo2[13] = randint(1,personaje[13])
            enemigo3[13] = randint(1,personaje[13])
            #En el caso que los enemigos sean iguales se ejecuta un ciclo que determine que sean diferentes
            while not(enemigo1[13] + enemigo2[13] + enemigo3[13] < personaje[13]) + 3 and not(enemigo1[13] + enemigo2[13] + enemigo3[13] > personaje[13] - 3):
                enemigo1[13] = randint(1,personaje[13])
                enemigo2[13] = randint(1,personaje[13])
                enemigo3[13] = randint(1,personaje[13])

            #Se calcula la experiencia del enemigo 1 
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[15],enemigo1[13])
            #Se calcula la experiencia del enemigo 2 y se suma al enemigo 1
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[15],enemigo2[13])
            #Se calcula la experiencia del enemigo 3 y se suma a la del enemigo 1 y 2
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo3[15],enemigo3[13])
            #Se guardan las sumas de los enemigos
            sumaNivelesEnemigos = enemigo1[13] + enemigo2[13] + enemigo3[13]
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 1
            while i <=  personaje[13]:
                nivelActual += experienciaPorNivel(enemigo1[15],i)
                if nivelActual < experienciaPorNivel(enemigo1[15],enemigo1[13]):
                    AumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado)
                i+=1  

            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 2
            while i <=  personaje[13]:
                nivelActual += experienciaPorNivel(enemigo2[15],i)
                if nivelActual < experienciaPorNivel(enemigo2[15],enemigo2[13]):
                    AumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado)
                i+=1  
            
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 3
            while i <=  personaje[13]:
                nivelActual += experienciaPorNivel(enemigo3[15],i)
                if nivelActual < experienciaPorNivel(enemigo3[15],enemigo3[13]):
                    AumentoPorNivel(enemigo3,datosEnemigoOriginal3,datosEnemigoOriginal3Aumentado)
                i+=1  

            #Se crea una lista en donde se guardan las listas de los enemigos
            listaEnemigos = [enemigo1,enemigo2,enemigo3]
            print(listaEnemigos[0][14]+", "+listaEnemigos[1][14],"y",listaEnemigos[2][14])
            #Se elige al enemigo de las listas en donde se encuentran todos los enemigos
            enemigo = listaEnemigos[enemigo][:]
            #Se respaldan los datos de los enemigos
            datosEnemigoOriginal1 = enemigo1[:]
            datosEnemigoOriginal2 = enemigo2[:]
            datosEnemigoOriginal3 = enemigo3[:]
            #Se guardan todos los datos iniciales de los enemigos en una lista
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2,datosEnemigoOriginal3]
            
    #Se decide quien comienza basandose en las velocidades del enemigo y personaje
    if personaje [1] >= enemigo[1]:
        turno = True
        turnoEnemigo = False
    elif enemigo[1] > personaje[1]:
        turno= False
        turnoEnemigo= True
        
    #Mientras la vida de ambos contrincantes sea positiva tendrá a lugar la batalla  
    #Se decide si pelea contra el jefe dependiendo de la cantidad de batallas
    while cantidadEnemigos > 0 and personaje[0]>0:
        #Se elige de una manera pseudo-aleatoria el enemigo que atacará 
        enemigo = choice(listaEnemigos)
        #Se determina en que posición se encuentran los datos del enemigo de la ronda
        posicion = listaEnemigos.index(enemigo)
        #Se determina los datos originales del enemigo en base a la lista que contenia los datos
        #originales de los enemigos y la posición
        datosEnemigoOriginal = listaDatosEnemigosOriginal[posicion]
        #Mientras el turno del personaje sea True, se ejecutara el ciclo
        while turno == True:
            #Se elige por el usuario el Hechizo o Ataque
            accion = 1#randint(1,2)
            #Ataque
            # Si toca 1 se realiza el ataque         
            if accion == 1:
                #Se escoge un número al azar entre 1 y 20
                numeroAleatorio = 20#randint(1,20)
                #En base al número aleatorio se suma con el ataque del personaje para determinar
                #el número de ataque
                numeroAtaque = numeroAleatorio + personaje[2]
                #Si el número de ataque es mayor a la defensa del enemigo puede atacar
                if numeroAtaque >= enemigo[3] :
                    #Fallo
                    #Si el número al azar es 1 ocurre un excepción el cual beneficia al enemigo
                    #dañando al propio personaje
                    if numeroAleatorio == 1:
                        #Se determina el número de fallo entre 1 y 3
                        numeroFallo = randint(1,3)
                        #Se le resta el número de fallo al personaje
                        personaje[0] = personaje[0] - numeroFallo
                        
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                    elif numeroAleatorio == 20:
                        #El daño del personaje aumenta 2* por un valor dado por un número al azar entre el daño
                        #mínimo y máximo del personaje
                        daño = 2 * (randint(personaje[8],personaje[9]))
                        #Se le resta el daño calculado al personaje
                        enemigo[0] = enemigo[0] - daño
                        criticosHechos += 1 
                        
                    #Para cualquier otro caso el procedimiento es de un ataque noma 
                    else:
                        #Se determina el daño que realiza entre el daño mínimo y máximo del personaje
                        daño = randint(personaje[8],personaje[9])
                        #Se le resta la vida al enemigo
                        enemigo[0] = enemigo[0] - daño
                        
                    #El turno del usuario termino
                    turno = False
                    
                #En el caso de no ser mayor a la defensa el enemigo no puede atacar
                else:
                    #Al fallar el movimiento aumenta el contador de fallos
                    fallosHechos+=1
                    #El turno del usuario a terminado
                    turno = False
            #Hechizo
            #Si toca 2 se realizara un hechizo
            elif accion == 2:
                    #En el caso de que el usuario tenga el personaje Fighter no podrá realizar un hechizo ya que no tiene probabilidades
                    #en su tabla, diciendole que escoja ataque
                    if personaje == fighter:
                        turno = True
                    #En otro caso esta habilitado para realizar Hechizo    
                    else:
                        #Se determina el umbral del personaje eligiendo un número al azar entre 1 y 20
                        umbral = randint(1,20)
                        #Si el número es mayor al umbral puede realizar un Hechizo
                        if umbral > personaje[4]:
                            valor = randint(1,100)
                            #Hechizo de Ataque
                            if valor < personaje[5]:
                                #Crítico
                                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                                if valor == 20:
                                    #Se determina el daño que realizará el personaje a través de un número al azar entre el
                                    #daño de hechizo máximo y mímino del personaje, este tiene que ser entero
                                    daño = int(randint(personaje[10],personaje[11])*1.5)
                                    #Se le resta la el daño al enemigo
                                    enemigo[0] = enemigo[0]-daño
                                    criticosHechos += 1 
                                    
                                #Fallo
                                #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                                elif valor == 1:
                                    #Se le resta la mitad de la vida al personaje, tiene que ser entero
                                    personaje[0] = int(personaje[0]/2)
                                    
                                #Para cualquier otro caso el procedimiento de Hechizo normal
                                else:
                                    #Se determina el daño que realiza entre el daño de hechizo máximo y mínimo
                                    daño = randint(personaje[10],personaje[11])
                                    #Se le resta el daño provocado por el personaje al enemigo
                                    enemigo[0] = enemigo[0]-daño
                                            
                            #Hechizo de Defensa
                            elif valor < personaje[6]:
                                #Crítico
                                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                                if valor == 20:
                                    #Aumenta la defensa en 2 
                                    personaje[3] += 2
                                    criticosHechos += 1 
                                    
                                #Fallo
                                #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                                elif valor == 1:
                                    #Aumenta en 1 el valor de la defensa del enemigo
                                    enemigo[3] += 1
                                    
                                #Por el contario se sigue con normalidad
                                else:
                                    #Aumenta en la defensa del personaje en 1
                                    personaje[3] += 1
                                    
                            #Hechizo de Curación
                            elif valor < personaje[7]:
                                #Crítico
                                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                                if valor == 20:
                                    #Se restaura 4 puntos de vida del personaje
                                    personaje[0] += 4
                                    criticosHechos += 1 
                                    #Si los puntos de curación superan los límites originales, quedará con el puntaje original
                                    #ya que la vida no puede superar los datos originales
                                    if personaje[0] > datosPersonajeOriginal[0]: #!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Necesitamos Cambiar COmo se define la cura !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                        personaje[0] = datosPersonajeOriginal
                                        criticosHechos += 1 
                                        
                                #Fallo
                                #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                                elif valor == 1:
                                    #Se le aumenta 4 a la vida del enemigo
                                    enemigo [0]+= 4
                                    #Si el puntaje de curado supera el límite de vida, quedará el puntaje original ya que no se pueden
                                    #superar esos valores
                                    if enemigo[0] > datosEnemigoOriginal[0]:
                                        enemigo[0] = datosEnemigoOriginal
                                        
                                #En cualquier otro caso se seguirá con un Hechizo de Curación normal
                                else:
                                    #Se elige un número al azar entre 1 y 8 con el fin de curar al personaje
                                    cura = randint(1,8)
                                    personaje[0] = personaje[0] + cura
                                    #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                                    if personaje[0] > datosPersonajeOriginal[0]:
                                        personaje[0] = datosPersonajeOriginal
                                        
                            #Ataque simple
                            #En el caso que no se puede realizar HA, HD y HC, el personaje ataca normalmente
                            else:
                                #Se determina el daño que va a realizar el personaje con un número al azar entre el daño
                                #máximo y mínimo
                                daño = randint(personaje[8],personaje[9])
                                #Se le resta el daño a la vida del enemigo
                                enemigo[0] = enemigo[0] - daño
                        #En el caso que el número aleatorio no supere el umbral no podrá realizar Hechizo
                        else:
                            #En el caso de fallar el moviento aumenta el contador de fallos
                            fallosHechos+=1
                            #Acaba el turno del enemigo aunque no haya podido realizar el hechizo
                            turno = False
                        #Acaba el turno del usuario
                        turno = False
        
        #Se activa el turno del personaje
        turnoEnemigo = True
        #Comienza el turno del personaje
        while turnoEnemigo == True :
            #Se llama la función que contiene los procesos del enemigo, retornando el booleano par terminar
            #el turno del enemigo
            turnoEnemigo = accionEnemigoSkip(enemigo,personaje,turnoEnemigo, datosEnemigoOriginal)
        
        #Se activa el turno del personaje
        turno =  True
        #En el caso que muera uno de los enemigos muera disminuye la cantidad de enemigos
        #totales
        
        if enemigo[0] <= 0 :
            print("Murió "+listaEnemigos[posicion][14])
            cantidadEnemigos -=1
            listaEnemigos.pop(posicion)
            
    #En el caso que la vida sea menor o igual a 0 significa que murió el enemigo
    if enemigo[0] <= 0: 
        enemigo = datosEnemigoOriginal[:]
        #Cálculo factorCritic
        #Al terminar la batalla y terminar victoriozo el jugador recibe una bonificación por criticos y 
        #fallos hechos
        #En el caso que el caclulo sea mayor a 0 se asigna un valor de 1.5
        if (criticosHechos - fallosHechos) > 0:
            factorCritic = 1.5
            
        #En el caso que el caclulo sea menor a 0 se asigna un valor de 0.75
        elif (criticosHechos - fallosHechos) < 0:
            factorCritic = 0.75
            
        #En el caso que el caclulo sea igual a 0 se asigna un valor de 0
        elif (criticosHechos - fallosHechos) == 0:
            factorCritic = 0
        
        #Cálculo factorDaño
        #Bonificación por la salud restante de personaje, se divide la vida restante con la vida total
        factorDaño = int(personaje[0]/datosPersonajeOriginal[0])

        #Se calcula la experiencia ganada en el combate
        experiencia += calculoExperiencia(sumaExperienciaEnemigos,sumaNivelesEnemigos,personaje[13],factorCritic,factorDaño)
        print("\nTe queda "+str(personaje[0])+" de vida\n")
        print("No quedan más oponentes")
        print("GANASTE")
        print()
        return experiencia
    
    #En el caso que la vida del personaje sea menor o igual a 0 significa que murio el
    #personaje por lo que perdió
    elif personaje[0] <= 0:
        enemigo = datosEnemigoOriginal[:]
        print("\nNo te queda vida\n")
        print("Has muerto")
        print("PERDISTE")
        print()
        return 0
    
##BLOQUE PRINCIPAL

#Se definen 4 listas, la primera con descripción de lo que contienen en cierta posición el resto de listas 
listaDescripcion = ["Ptos. de vida","Velocidad","Ataque","Defensa","Umbral de H.","Prob. H.A.","Prob. H.D.","Prob. H.C.","Daño mínimo","Daño máximo","Daño H. min","Daño H max","Exp. Inicial", "Nivel"]
#Listas con los tres personajes que existen
#personaje = [Puntos de vida,velocidad,ataque,defensa,umbral de hechizo,PHA,PHD,PHC,daño mínimo,daño máximo,experiencia máxima,
#nivel,nombre,tipo de crecimiento]
fighter = [12,3,5,14,20,0,0,0,2,8,0,0,1250000,1,"Fighter","lento"]#1
wizard = [6,2,2,12,10,20,40,0,1,4,4,12,1750000,1,"Wizard","ultraLento"]#2
cleric = [8,2,4,12,12,0,20,40,1,6,0,0,1250000,1,"Cleric","lento"]#3
print()
print("\t\t    1)FIGTHER\t    2)WIZARD\t    3)CLERIC") 
print()
i = 0
#Se realiza un ciclo con el fin de imprimir los datos en forma de tabla
while i < 12:
    print(listaDescripcion[i].ljust(15," "),"|\t",fighter[i],"\t","|\t",wizard[i],"\t","|\t",cleric[i], "\t|")
    i +=1

##Datos de entrada

#El número que ingrese el usuario corresponde a un personaje
personaje = input("Número de personaje: ")

##Procesamiento

#En el caso que el número sea distinto de 1,2 y 3 le pedira que ingrese núevamente el dato
while personaje != "1" and personaje !="2" and personaje !="3":
    print("Dato erróneo")
    personaje = input("Ingrese nuevamente el número del personaje: ")#Verificador

#Se convierte el dato a un entero para facilitar el trabajo
personaje = int(personaje)

print()
#Según el número que ingresa el usuario se le asignan los datoss del personaje a la variable "personaje"
#En el caos que personaje escogido por el usuario sea 1, se determina a lista Fighter como personaje
if personaje == 1:
    print("Personaje elegido: FIGHTER")
    print()
    personaje = fighter[:]

#En el caos que personaje escogido por el usuario sea 1, se determina a lista Wizard como personaje
elif personaje == 2:
    print("Personaje elegido: WIZARD")
    print()
    personaje = wizard[:]

#En el caos que personaje escogido por el usuario sea 1, se determina a lista Cleric como personaje
elif personaje == 3:
    print("Personaje elegido: CLERIC")
    print()
    personaje = cleric[:]

#Se guardan los datos del personaje 
datosPersonajeOriginal = personaje[:]
datosPersonajeAumentados = personaje[:]
#Se le consulta al usuario cuantas batallas desea enfrentar
numeroBatallas = input("Número de batallas a pelear: ")
#En el caso que el usuario ingrese de manera incorrecta se le pedirá nuevamente el valor
while not numeroBatallas.isnumeric():
    numeroBatallas = input("Ingresa la cantidad de batallas (Solo con digitos): ")

numeroBatallas = int(numeroBatallas)
#Indica el número de batalla que se esta realizando
batalla = 1
experiencia = 0
siguienteNivel = 2
#
respuesta = ""
#Mientras el número elegido por usuario sea mayor al número de batallas realizadas
#Se ejecutara el ciclo
while batalla <= numeroBatallas:
    #Se crea la variable en donde se guardarán los los críticos del personaje
    criticosHechos = 0
    #Se crea una variable en donde se guardarán los fallos hechos del personaje
    fallosHechos = 0
    print()
    print("Batalla " + str(batalla))
    print()
    #Después de la primera batalla se imprime la información del personaje con 
    #los niveles y experiencia correspondiente
    if batalla > 1:
        print("\t\t     ",personaje[14]) 
        print()
        i = 0
        listaDescripcion[12] = "Experiencia"
        #Se realiza un ciclo con el fin de imprimir los datos en forma de tabla
        while i < 14:
            if i == 12:
                print(listaDescripcion[i].ljust(15," "),"|\t",experiencia)
            else:
                print(listaDescripcion[i].ljust(15," "),"|\t",personaje[i])
            i +=1
        print()
        
    #Se le consulta al usuario si desea saltarse la batalla y sólo visualizar el resultado
    skipBattle = input("Skip batalla (Si/No): ")
    print()
    #Se convierte a minúscula la respuesta para realizar posteriormen comprobación de la entrada
    skipBattle = skipBattle.lower() 
    #En el caso que usuario ingrese un dato erróneo sele pedirá nuevamente que ingrese el dato
    while skipBattle !="si" and skipBattle != "no":
        skipBattle = input("quieres skipearte la batalla? (Marque 'Si' o 'No' de acorde al caso): ")
        skipBattle = skipBattle.lower()
        print()
        print("Batalla " + str(batalla))
        print()
        
    #Si el usuario decide omitir la batalla se ejecutará la función omitiendo los prints de la batalla
    if skipBattle == "si":
        #Se llama a la función que contiene la información de la batalla más los prints
        experiencia += skipBatalla(personaje,datosPersonajeOriginal,criticosHechos,fallosHechos,experiencia)
        #Se aumenta el valor de batallas jugadas por el jugador
        batalla = batalla + 1
        #Se llama a la función sleep para que usuario alcance a leer la información
        sleep(3)
        
    #Por el contrario se ejecutra la batalla con normalidad
    elif skipBattle == "no" :
        print()
        #En el caso que la número de batalla que esta jugando el usuario sea multiplo de 10, se enfrentará a un jefe
        #Se ve si la variable batalla corresponde al enfrentamiento contra el jefe
        sumaExperienciaEnemigos = 0
        if batalla%10 == 0:
            #Estadisticas del Jefe, no puede lanzar hechizos y sus ataques son fuertes.
            #enemigo = [Puntos de vida,velocidad,ataque,defensa,umbral de hechizo,PHA,PHD,PHC,daño mínimo,daño máximo,experiencia máxima,
            #nivel,nombre,tipo de crecimiento]
            jefe = [80,2,9,15,20,0,0,0,8,13,0,0,1250000,1,"Jefe","lento"]
            #Se imprime en forma de tabla los datos del Jefe
            i = 0
            while i < 12:
                    print(listaDescripcion[i].ljust(15," "),"|\t",jefe[i],"\t|")
                    i +=1
                    
            #Se determina al jefe como enemigo, esto será durante solo una batalla, en la siguiente será definido
            #nuevamente el enemigo
            enemigo = jefe[:]
            #En la lista enemigos se colocan los datos del enemigo
            listaEnemigos = [enemigo]
            #Se respandan los datos iniciales del jefe
            datosEnemigoOriginal = enemigo[:]
            datosEnemigoOriginalAumentado = enemigo[:]
            #Se coloca esta información dentro de una lisra
            listaDatosEnemigosOriginal = [enemigo]
            #La cantidad de enemigos es 1 ya que al existir un jefe solo se enfrentará a él
            cantidadEnemigos = 1
            jefe[13] = personaje[13]
            sumaNivelesEnemigos = jefe[13]
            sumaExperienciaEnemigos = experienciaPorNivel(jefe[15], jefe[13])
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo
            while i <=  personaje[13]:
                nivelActual += experienciaPorNivel(enemigo[15],i)
                if nivelActual < experienciaPorNivel(jefe[15],personaje[13]):
                    AumentoPorNivel(enemigo,datosEnemigoOriginal,datosEnemigoOriginalAumentado)
                i+=1
            print()
            print("¡¡¡SE ACERCA UN JEFE!!!")
            
        #En el caso que no sea una batalla multiplo de 10 se enfrentará a un enemigo normal  
        else:
            #Se determina al azar cuantos enemigos se tiene que enfrentar al usuario
            cantidadEnemigos = randint(1,3)
            print()
            print()
            print("Te enfrentaras a",cantidadEnemigos,"enemigos: ")
            print()
            print()
            #Se crea una lista en donde se guardaran los datos de los enemigos
            listaEnemigos = []
            #En el caso que sea un enemigo a enfrentar se crea solo una variable de enemigo
            if cantidadEnemigos == 1:
                #Se llama a la función que selecciona el enemigo al azar
                enemigo1  = seleccionEnemigo(randint(1,3))
                #Se almacena en la lista destinada a guardar los enemigos
                listaEnemigos = [enemigo1]
                #Se respaldan los datos iniciales del enemigo
                datosEnemigoOriginal1 = enemigo1[:]
                datosEnemigoOriginal1Aumentado = enemigo[:] 
                #Se determina la variable enemigo como enemigo1 ya que no existen más enemigos
                enemigo = enemigo1[:]
                listaDatosEnemigosOriginal = [datosEnemigoOriginal1]
                print()
                print("Tu primer enemigo es: " + enemigo[14])
                print()
                enemigo1[13] = personaje[13]
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo
                while i <=  personaje[13]:
                    nivelActual += experienciaPorNivel(enemigo1[15],i)
                    if nivelActual < experienciaPorNivel(personaje[13]):
                        AumentoPorNivel(enemigo,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado)
                    i+=1
                    
                sumaNivelesEnemigos = enemigo[13]
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[15],enemigo1[13]) #perr
                #Se imprimen los datos del enemigo en forma de tabla hasta el valor 13
                contador = 0
                while contador < 12: 
                    print(listaDescripcion[i].ljust(15," "),"|\t",enemigo1[i],"\t|")
                    contador +=1
                    
            #En el caso que sean dos enemigos a enfrentar
            elif cantidadEnemigos == 2:
                #Se elige un número entre el 0 y el 1 para posteriormente utilizar este número 
                #como indice para determinar un enemigo con el se comparen las velocidades
                enemigo = randint(0,1)
                #Se elige un enemigo entre los tres enemigos disponibles
                enemigo1  = seleccionEnemigo(randint(1,3))
                
                print()
                print("Tu primer enemigo es " + enemigo1[14])
                print()                
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 1
                while i <=  personaje[13]:
                    nivelActual += experienciaPorNivel(enemigo1[15],i)
                    if nivelActual < experienciaPorNivel(enemigo1[15],personaje[13]):
                        AumentoPorNivel(enemigo,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado)
                    i+=1  
                
                #Se coloca un sleep para que usuario alcance a leer la información
                sleep(2)
                #Se escoge el segundo enemigo
                enemigo2 = seleccionEnemigo(randint(1,3))
                #En el caso que ambos enemigos sean los mismos se escoge otro de los 2 restantes
                while enemigo1 == enemigo2: # Para previnir que se duplicen enemigos
                    enemigo2 = seleccionEnemigo(randint(1,3))
                    
                enemigo1[13] = randint(1,personaje[13])
                enemigo2[13] = randint(1,personaje[13])
                while not(enemigo1[13] + enemigo2[13] < personaje[13] + 3) and not(enemigo1[13] + enemigo2[13] > personaje[13] - 3):
                    enemigo1[13] = randint(1,personaje[13])
                    enemigo2[13] = randint(1,personaje[13])
                print()
                print("Tu segundo enemigo es " + enemigo2[14])
                print()
                    
                #Se Calcula la experiencia del enemigo 1
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[15],enemigo1[13])
                #Se calcula la experiencia del enemigo 2 y se suma a la del enemigo 1, dando el total
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[15],enemigo2[13])
                #Se calcula la suma de los niveles de los enemigos
                sumaNivelesEnemigos = enemigo1[13] + enemigo2[13]
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 1
                while i <=  personaje[13]:
                    nivelActual += experienciaPorNivel(enemigo1[15],i)
                    if nivelActual < experienciaPorNivel(enemigo1[15],enemigo1[13]):
                        AumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado)
                    i += 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 1
                i = 1
                nivelActual = 1
                while i <=  personaje[13]:
                    nivelActual += experienciaPorNivel(enemigo2[15],i)
                    if nivelActual < experienciaPorNivel(enemigo2[15],enemigo2[13]):
                        AumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado)
                    i+= 1
                #Se coloca un sleep para que usuario alcance a leer la información
                sleep(2)
                #Se colocan ambos datos de los enemigos en una lista
                listaEnemigos = [enemigo1,enemigo2]
                enemigo = listaEnemigos[enemigo][:]
                #Se guardan los datos iniciales de los enemigos
                datosEnemigoOriginal1 = enemigo1[:]
                datosEnemigoOriginal2 = enemigo2[:]
                #Se crea una lista en donde se guardan las listas que contienen los datos iniciales de los enemigps
                listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2]
                
                #Se imprime la tabla de descripción del enemigo
                i = 0
                while i < 12:
                    print(listaDescripcion[i].ljust(15," "),"|\t",enemigo1[i],"\t|")
                    i +=1 
                #Una vez ya escogido ambos enemigos distintos se imprime los datos del enemigo restante
                i = 0
                while i < 12:
                    print(listaDescripcion[i].ljust(15," "),"|\t",enemigo2[i],"\t|")
                    i +=1
                
                
            #En el caso que sean tres enemigos a enfrentar
            elif cantidadEnemigos == 3:
                #Se elige un número entre el 0 y el 2 para posteriormente utilizar este número 
                #como indice para determinar un enemigo con el se comparen las velocidades
                enemigo = randint(0,2)
                #Se elige un enemigo entre los tres enemigos disponibles
                enemigo1 = seleccionEnemigo(randint(1,3))
                print()
                print("Tu primer enemigo es " + enemigo1[14])
                print()   
                #Se coloca un sleep para que usuario alcance a leer la información
                sleep(2)
                #Se escongen dos enemigos al azar
                enemigo2 = seleccionEnemigo(randint(1,3))
                enemigo3 = seleccionEnemigo(randint(1,3))
                #En el caso que se repitan los enemigos a enfrentar se escogen otros hasta que sean distintos
                while enemigo1 == enemigo2 or enemigo1 == enemigo3 or enemigo2 == enemigo3 :
                    enemigo2 = seleccionEnemigo(randint(1,3))
                    enemigo3 = seleccionEnemigo(randint(1,3))
                    
                print()
                print("Tu segundo enemigo es " + enemigo2[14])
                print()
                #Se coloca un sleep para que usuario alcance a leer la información
                sleep(2)
                print()
                print("Tu tercer enemigo es " + enemigo3[14])
                print()   

                enemigo1[13] = randint(1,personaje[13])
                enemigo2[13] = randint(1,personaje[13])
                enemigo3[13] = randint(1,personaje[13])
                while not(enemigo1[13] + enemigo2[13] + enemigo3[13] < personaje[13] + 3) and not(enemigo1[13] + enemigo2[13] + enemigo3[13] > personaje[13] - 3):
                    enemigo1[13] = randint(1,personaje[13])
                    enemigo2[13] = randint(1,personaje[13])
                    enemigo3[13] = randint(1,personaje[13])
                
                #Se calcula la experiencia del enemigo1 
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[15],enemigo1[13])
                #Se calcula la experiencia del enemigo2, sumandolo al del enemigo 1
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[15],enemigo2[13])
                #Se calcula la experiencia del enemigo 3, sumandola al del enemigo 1 y 2, dando el total
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo3[15],enemigo3[13])
                #Se suman los niveles de los enemigos
                sumaNivelesEnemigos = enemigo1[13] + enemigo2[13] + enemigo3[13]
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 1
                while i <=  personaje[13]:
                    nivelActual += experienciaPorNivel(enemigo1[15],i)
                    if nivelActual < experienciaPorNivel(enemigo1[15],enemigo1[13]):
                        AumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado)
                    i += 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 2
                i = 1
                nivelActual = 1
                while i <=  personaje[13]:
                    nivelActual += experienciaPorNivel(enemigo2[15],i)
                    if nivelActual < experienciaPorNivel(enemigo2[15],enemigo2[13]):
                        AumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado)
                    i+= 1
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 3
                while i <=  personaje[13]:
                    nivelActual += experienciaPorNivel(enemigo3[15],i)
                    if nivelActual < experienciaPorNivel(enemigo3[15],enemigo3[13]):
                        AumentoPorNivel(enemigo3,datosEnemigoOriginal3,datosEnemigoOriginal3Aumentado)
                    i+= 1
                #Se coloca un sleep para que usuario alcance a leer la información
                sleep(2)
                #Se agregan los datos de los enemigos a una lista 
                listaEnemigos = [enemigo1,enemigo2,enemigo3]
                enemigo = listaEnemigos[enemigo][:]
                #Se respaldan los datos de los enemigos
                datosEnemigoOriginal1 = enemigo1[:]
                datosEnemigoOriginal2 = enemigo2[:]
                datosEnemigoOriginal3 = enemigo3[:]
                datosEnemigoOriginal1Aumentado = enemigo1[:]
                datosEnemigoOriginal2Aumentado = enemigo2[:]
                datosEnemigoOriginal3Aumentado = enemigo3[:]
                #Se crea una lista en donde se guardan los datos iniciales de todos los enemigos
                listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2,datosEnemigoOriginal3]
                i = 0
                #Se imprimen los datos del primer enemigo a enfrentar
                while i < 12:
                    print(listaDescripcion[i].ljust(15," "),"|\t",enemigo1[i],"\t|")
                    i +=1
                #Se imprimen los datos del segundo enemigo
                i = 0
                while i < 12:
                    print(listaDescripcion[i].ljust(15," "),"|\t",enemigo2[i],"\t|")
                    i +=1
                #Se imprimen los datos del tercer enemigo                
                i = 0
                while i < 12:
                    print(listaDescripcion[i].ljust(15," "),"|\t",enemigo3[i],"\t|")
                    i +=1
                    
        #Respaldo datos originales
        datosPersonajeOriginal = personaje[:]
        #Para determinar a quien le toca primero se comparan las velocidades del personaje y enemigo1
        #Para determinar cuando empieza y acaba el turno del personaje se crea una variable que vuelve False cuando termina el turno  
        if personaje [1] >= enemigo[1]:
            turno = True
            turnoEnemigo = False
            
        elif enemigo[1] > personaje[1]:
            turno= False
            turnoEnemigo= True
            
        print()
        print("BATALLA "+str(batalla))
        print()
        #Mientras la vida de ambos contrincantes sea positiva tendrá a lugar la batalla  
        #Se decide si pelea contra el jefe dependiendo de la cantidad de batallas
        while cantidadEnemigos > 0 and personaje[0]>0:
            #Se elige de una manera pseudo-aleatoria el enemigo que atacará 
            enemigo = choice(listaEnemigos)
            #Se determina en que posición se encuentran los datos del enemigo de la ronda
            posicion = listaEnemigos.index(enemigo)
            #Se determina los datos originales del enemigo en base a la lista que contenia los datos
            #originales de los enemigos y la posición
            datosEnemigoOriginal = listaDatosEnemigosOriginal[posicion]
            #Mientras el turno del personaje sea True, se ejecutara el ciclo
            while turno == True:
                print("Atacarás a " + enemigo[14])
                señalEmpezar= input("Presione enter para continuar:")
                print()
                print("Cuando se complete la barra podrá atacar")
                print()
                #Se realiza un ciclo que vaya imprimiendo la actualización cada cierto tiempo de la barra Gauge
                barraOriginal = "| ░ ░ ░ ░ ░ ░ ░ ░ ░|"
                barraLista = barraOriginal.split(" ")
                #Se imprime la barra vácia que con el tiempo se irá llenando
                print("|░░░░░░░░░░|")
                i = 0
                #Se recorre la barra con el fin de llenarla en un determinado tiempo
                while i < len(barraLista):
                    #Se utiliza la función sleep para regular el tiempo con el que se imprime la barra
                    sleep(1/personaje[1])
                    turno = False
                    if i == 0:
                        barraLista[i] = "|█"
                        barra = "".join(barraLista)
                        print(barra)
                        i +=1
                        
                    elif i == len(barraLista)-1:
                        barraLista[i] = "█|"
                        barra = "".join(barraLista)
                        print(barra)
                        i +=1
                    else:
                        barraLista[i] = "█"
                        barra = "".join(barraLista)
                        print(barra)
                        i +=1
                        
                print()
                print("Ahora puede realizar una acción")
                #Se le solicita al usuario determinar que acción va a realizar
                accion = input("1)Ataque 2)Hechizo: ")
                #En caso de que el número sea distinto de 1 y 2, se tendrá que ingresar nuevamente
                while accion != "1" and accion !="2":
                    print("Dato erróneo")
                    accion = input("Ingrese nuevamente el número de la acción: ")
                    
                #Ataque
                #Si el usuario ingresa 1 se realiza el ataque         
                if accion == "1":
                    print()
                    print("Si el número de ataque es mayor a la defensa de su enemigo podrá atacar")
                    print("La defensa del enemigo es: ",enemigo[3])
                    #Se escoge un número al azar entre 1 y 20
                    numeroAleatorio = 20#randint(1,20)
                    #En base al número aleatorio se suma con el ataque del personaje para determinar
                    #el número de ataque
                    numeroAtaque = numeroAleatorio + personaje[2]
                    print("Número de ataque: ",numeroAtaque)
                    #Si el número de ataque es mayor a la defensa del enemigo puede atacar
                    if numeroAtaque >= enemigo[3] :
                        #Fallo
                        #Si el número al azar es 1 ocurre un excepción el cual beneficia al enemigo
                        if numeroAleatorio == 1:
                            print("Te quedan",personaje[0],"de vida")
                            #Se determina el número de fallo entre 1 y 3
                            numeroFallo = randint(1,3)
                            #Se le resta el número de fallo al personaje
                            personaje[0] = personaje[0] - numeroFallo
                            print("Eres tan torpe que te has herido a ti mismo quitandote",numeroFallo,"puntos de vida")
                            print("Ahora te quedan",personaje[0],"puntos de vida")
                            print()
                            
                        #Crítico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        elif numeroAleatorio == 20:
                            print()
                            print("Has realizado un ataque con exito")
                            print()
                            #El daño del personaje aumenta 2* por un valor dado por un número al azar entre el daño
                            #mínimo y máximo del personaje
                            daño = 2 * (randint(personaje[8],personaje[9]))
                            print("ATAQUE CRÍTICO")
                            print()
                            print("La vida del enemigo es:", enemigo[0])
                            print("Has realizado",daño,"de daño")
                            #Se le resta el daño calculado al personaje
                            enemigo[0] = enemigo[0] - daño
                            print("La nueva vida del enemigo es:", enemigo[0])
                            print()
                            criticosHechos += 1 
                            
                        #Para cualquier otro caso el procedimiento es el normal  
                        else:
                            print()
                            print("Has realizado un ataque con éxito")
                            print()
                            #Se determina el daño que realiza entre el daño mínimo y máximo del personaje
                            daño = randint(personaje[8],personaje[9])
                            print("La vida del enemigo es:",enemigo[0])
                            #Se le resta la vida al enemigo
                            enemigo[0] = enemigo[0] - daño
                            print("Has realizado "+ str(daño) +" daño")
                            print("La nueva vida del enemigo es:",enemigo[0])
                            print()
                        
                        #El turno del usuario termino
                        turno = False
                        
                    #En el caso de no ser mayor a la defensa el enemigo no puede atacar
                    else: 
                        print()
                        print("Fallaste al Atacar")
                        print()
                        #Al fallar aumenta el contador de fallos
                        fallosHechos+=1
                        #El turno del usuario a terminado
                        turno = False
                        
                #Hechizo
                #Si el usuario ingresa 2 se realizara un hechizo
                elif accion == "2":
                    print()
                    #En el caso de que el usuario tenga el personaje Fighter no podrá realizar un hechizo ya que no tiene probabilidades
                    #en su tabla, diciendole que escoja ataque
                    if personaje == fighter:
                        print("Usted no puede puede realizar hechizo")
                        print("Por favor elija Ataque")
                        print()
                        turno = True
                        
                    #En otro caso esta habilitado para realizar Hechizo    
                    else:
                        print("Si el número al azar es mayor a su umbral podrá realizar un hechizo")
                        print("Su umbral es:",personaje[4])
                        #Se determina el umbral del personaje eligiendo un número al azar entre 1 y 20
                        umbral = randint(1,20)
                        print("Numero al azar:",umbral)
                        #Si el número es mayor al umbral puede realizar un Hechizo
                        if umbral > personaje[4]:
                            print()
                            print("Puede realizar hechizo")
                            print()
                            valor = randint(1,100)
                            #Hechizo de Ataque
                            if valor < personaje[5]:
                                print("Hechizo de ataque")
                                #Crítico
                                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                                if valor == 20:
                                    print("CRÍTICO")
                                    #Se determina el daño que realizará el personaje a través de un número al azar entre el
                                    #daño de hechizo máximo y mímino del personaje, este tiene que ser entero
                                    daño = int(randint(personaje[10],personaje[11])*1.5)
                                    print("La vida del enemigo es:",enemigo[0])
                                    print("Has realizado",daño,"de daño")
                                    #Se le resta la el daño al enemigo
                                    enemigo[0] = enemigo[0]-daño 
                                    print("La nueva vida del enemigo es: ", enemigo[0])
                                    print()
                                    criticosHechos += 1 
                                    
                                #Fallo
                                #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                                elif valor == 1:
                                    print("FALLO")
                                    print("Te quedan",personaje[0],"de vida")
                                    #Se le resta la mitad de la vida al personaje, tiene que ser entero
                                    personaje[0] = int(personaje[0]/2)
                                    print("Su vida se a reducido a la mitad")
                                    print("Ahora te quedan",personaje[0],"puntos de vida")
                                    print()
                                    
                                #Por elcontrario actua con normalidad
                                else:
                                    #Se determina el daño que realiza entre el daño de hechizo máximo y mínimo
                                    daño = randint(personaje[10],personaje[11])
                                    print("La vida del enemigo es:",enemigo[0])
                                    print("Has realizado",daño,"de daño")
                                    #Se le resta el daño provocado por el personaje al enemigo
                                    enemigo[0] = enemigo[0]-daño
                                    print("La nueva vida del enemigo es: ", enemigo[0])
                                    print()
                                    
                            #Hechizo de Defensa
                            elif valor < personaje[6]:
                                print("HECHIZO DE DEFENSA")
                                #Crítico
                                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                                if valor ==20:
                                    print("CRÍTICO")
                                    print()
                                    print("La defensa actual es:",personaje[3])
                                    #Aumenta la defensa en 2 
                                    personaje[3] += 2
                                    print("A aumentado su defensa en 2")
                                    print("Ahora su defensa es:", personaje[3])
                                    print()
                                    criticosHechos += 1
                                    
                                #Fallo
                                #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                                elif valor ==1:
                                    print("FALLO")
                                    print()
                                    print("La defensa del enemigo es:",enemigo[3])
                                    #Aumenta en 1 el valor de la defensa del enemigo
                                    enemigo[3] += 1
                                    print("A aumentado su defensa del enemigo")
                                    print("Ahora la defensa del enemigo es:", enemigo[3])
                                    print()
                                    
                                #Por el contario se sigue con normalidad
                                else:
                                    print("La defensa actual es:",personaje[3])
                                    #Aumenta en la defensa del personaje en 1
                                    personaje[3] += 1
                                    print("A aumentado su defensa")
                                    print("Ahora su defensa es:", personaje[3])
                                    print()
                                    
                            #Hechizo de Curación
                            elif valor < personaje[7]:
                                print("Hechizo de curacion")
                                print()
                                #Crítico
                                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                                if valor == 20:
                                    print("CRÍTICO")
                                    #En el caso que el usuario tenga la vida llena no se curará
                                    if personaje[0] == datosPersonajeOriginal[0]:
                                        print("Usted no se puede curar ya que tiene la vida al máximo")
                                        print()
                                        criticosHechos += 1
                                        
                                    #Si no tiene la vida al máximo significa que puede curarse
                                    else:
                                        print("La vida actual es:",personaje[0])
                                        #Aumenta en 4 el nivel de vida del personaje
                                        personaje[0] += 4
                                        print("Usted se a curado 4 de vida")
                                        print()
                                        #Si los puntos de curación superan los límites originales, quedará con el puntaje original
                                        #ya que la vida no puede superar los datos originales
                                        if personaje[0] > datosPersonajeOriginal[0]:
                                            personaje[0] = datosPersonajeOriginal
                                            print("Su nueva vida es: ", personaje[0])
                                            print()
                                            criticosHechos += 1 
                                        #En el caso que no superen los datos orginales del personaje quedaran los datos con el aumento
                                        else:
                                            print("Su nueva vida es: ",personaje[0])
                                            criticosHechos += 1 
                                        print()
                                        
                                #Fallo
                                #Si el número al azar es 1 ocurre una excepción que beneficia al enemigo
                                elif valor == 1:
                                    print("FALLO")
                                    print()
                                    print("La vida actual del enemigo es;",enemigo[0])
                                    print("Has fallado y has curado al enemigo")
                                    #En el caso que el enemigo tenga la vida llena, no se curará 
                                    if enemigo[0] == datosEnemigoOriginal[0]:
                                        print("El enemigo no se pudo curar, porque tiene la vida llena")
                                        
                                    else:    
                                        #Se le aumenta 4 a la vida del enemigo
                                        enemigo [0]+= 4 
                                        print("El enemigo se a curado 4 de vida")
                                        #Si el puntaje de curado supera el límite de vida, quedará el puntaje original ya que no se pueden
                                        #superar esos valores
                                        if enemigo[0] > datosEnemigoOriginal[0]:
                                            enemigo[0] = datosEnemigoOriginal
                                            print("La nueva vida del enemigo es: ", enemigo[0])
                                            
                                        #Por el contrario se deja con la vida curada
                                        else:
                                            print("La nueva vida del enemigo es: ",personaje[0])
                                            
                                    print()
                                    
                                #En cualquier otro caso se seguirá con un Hechizo de Curación normal
                                else:
                                    print("La vida actual es:",personaje[0])
                                    #Si la vida se encuntra completa, no se curara
                                    if personaje[0] == datosPersonajeOriginal[0]:
                                        print("Usted no se puede curar ya que tiene la vida al máximo")
                                        print()
                                        
                                    else:
                                        #Se elige un número al azar entre 1 y 8 con el fin de curar al personaje
                                        cura = randint(1,8)
                                        print("Numero al azar: ",cura)
                                        print("Usted se va curar ",cura,"de vida")
                                        personaje[0] = personaje[0] + cura
                                        #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                                        if personaje[0] > datosPersonajeOriginal[0]:
                                            personaje[0] = datosPersonajeOriginal
                                            print("Su nueva vida es: ", personaje[0])
                                            
                                        #Por el contrario quedará con el valor aumentado
                                        else:
                                            print("Su nueva vida es: ",personaje[0])
                                            
                                        print()
                                
                            #Ataque simple
                            #En el caso que no se puede realizar HA, HD y HC, el personaje ataca normalmente
                            else:
                                print("Ataque simple")
                                print()
                                #Se determina el daño que va a realizar el personaje con un número al azar entre el daño
                                #máximo y mínimo
                                daño = randint(personaje[8],personaje[9])
                                print("La vida del enemigo es:",enemigo[0])
                                #Se le resta el daño a la vida del enemigo
                                enemigo[0] = enemigo[0] - daño
                                print("Has realizado "+ str(daño) +" puntos de daño")
                                print("Al enemigo le quedan "+str(enemigo[0])+ " puntos de vida")
                                print()
                        
                        #En el caso que el número aleatorio no supere el umbral no podrá realizar Hechizo
                        else:
                            print()
                            print("Fallaste al realizar el hechizo")
                            #Al fallar aumenta el contador de fallos
                            fallosHechos+=1
                            #Acaba el turno del enemigo aunque no haya podido realizar el hechizo
                            turno = False
                            
                        #Acaba el turno del usuario
                        turno = False
            
            #Se coloca un sleep para que usuario alcance a leer la información
            sleep(2)
            #Se activa el turno del enemigo
            turnoEnemigo = True
            #Se comprueba que el enemigo se encuentre vivo antes de que empiece su turno
            while turnoEnemigo == True :
                #Se llama la función acción enemigo que realiza los moviemientos del enemigo
                turnoEnemigo = accionEnemigo(enemigo,personaje,turnoEnemigo, datosEnemigoOriginal)
                
            #Se coloca un sleep para que usuario alcance a leer la información
            sleep(2)
            #Se activa el turno del personaje
            turno =  True
            #En el caso que muera uno de los enemigos muera disminuye la cantidad de enemigos
            #totales
            if enemigo[0] <= 0 :
                print("Murió "+listaEnemigos[posicion][14])
                print()
                #Se resta en uno la cantidad de enemigos 
                cantidadEnemigos -=1
                #Se elimina de la lista en donde se encuentran los enemigos al que murió
                listaEnemigos.pop(posicion)
            
            '''
            print(listaEnemigos)
            print(cantidadEnemigos)
            
            '''
            
        #Salida de datos para el usario
        print("Computo vidas")
        print("Enemigo:",enemigo[0])
        print("Personaje:",personaje[0])
        print()
        
        #En el caso que la vida del enemigo sea menor o igual a 0 significa que el enemigo murió
        if enemigo[0] <= 0:
            print("No quedan más oponentes")
            print("GANASTE")
            print()
            '''
            tengo la suma de la experiencia de enemigos, suma de niveles, nivel del personaje 
            '''
            
            #Cálculo factorCritic
            #Al terminar la batalla y terminar victoriozo el jugador recibe una bonificación por criticos y 
            #fallos hechos
            #En el caso que el caclulo sea mayor a 0 se asigna un valor de 1.5
            if (criticosHechos - fallosHechos) > 0:
                factorCritic = 1.5
                
            #En el caso que el caclulo sea menor a 0 se asigna un valor de 0.75
            elif (criticosHechos - fallosHechos) < 0:
                factorCritic = 0.75
                
            #En el caso que el caclulo sea igual a 0 se asigna un valor de 0
            elif (criticosHechos - fallosHechos) == 0:
                factorCritic = 0
                
            #Cálculo factorDaño
            #Bonificación por la salud restante de personaje, se divide la vida restante con la vida total
            factorDaño = int(personaje[0]/ datosPersonajeAumentados[0])
            
            #Se realiza un ciclo para sumar todos los niveles de los enemigos con los que se enfrento 
            #el personaje
            #Se suma  a la experencia ya calculada la acumulada en esta batalla
            experiencia += calculoExperiencia(sumaExperienciaEnemigos,sumaNivelesEnemigos,personaje[13],factorCritic,factorDaño) 
            #Se calcula la experiencia para alcanzar el siguiente nivel   
            experienciaParaNivel = experienciaPorNivel(personaje[15],siguienteNivel)
            #Se redondea los resultados para evitar excesivos decimales
            experienciaParaNivel = round(experienciaParaNivel)
            #Se realiza un ciclo para aumentar nivel
            while experienciaParaNivel < experiencia:
                personaje[13] += 1
                aumentoPorNivel(datosPersonajeAumentados,datosPersonajeOriginal,datosPersonajeAumentados)
                siguienteNivel += 1
                experienciaParaNivel = experienciaPorNivel(siguienteNivel,personaje[15],personaje[13])
                experienciaParaNivel = round(experienciaParaNivel)
                aumentoPorNivel(personaje,datosPersonajeOriginal,datosPersonajeAumentados)
                
            print("Necesitas "+ str(experienciaParaNivel) +" para subir de nivel")
            
        #Por el contrario si la vida del personaje es negativa significa que el personaje murió   
        elif personaje[0] <= 0:
            print("Has muerto")
            print()
            print("PERDISTE")
            print()

        #Al finalizar aumenta el número de batalla jugada 
        batalla +=1

    #Si el jugador muere se le da la opcion de esperar para que pueda seguir jugando
    if personaje[0] <=0 and batalla <= numeroBatallas:
        respuesta = input("¿Quieres esperar 10 segundos para regresar a jugar?: ")
        #El str ingresado por el usuario se convierte a mínuscula para realizar comprobación posteriormente
        respuesta = respuesta.lower()
        #En caso que el usuario ingrese el dato erróneo se le solicita otro hasta que sea válido
        while respuesta != "si"and respuesta != "no":
            respuesta = input("¿Quieres esperar 10 segundos para regresar a jugar? (Si o No de acorde al caso)") 
            respuesta = respuesta.lower()
    
    #Si el usario desea continuar tiene que esperar 10 segundos
    if respuesta == "si":
        print()
        print("Cuando se complete la barra podra atacar")
        #Se realiza un ciclo que vaya imprimiendo la actualización de la barra cada 1 segundo dando un total de 10 segundos
        barraOriginal = "| ░ ░ ░ ░ ░ ░ ░ ░ ░ ░|"
        barraLista = barraOriginal.split(" ")
        #Se imprime la barra vácia con el fin que posteriormente se vaya "llenando" 
        print("|░░░░░░░░░░░|")
        i = 0
        #Se recorre el str con el fin de ir actualizando la barra
        while i < len(barraLista): 
            #Se espera un segundo antes de imprimir la actualización,completando tras 10 segundo las barras
            sleep(1)
            #Se utiliza la barra para representar cuanto tiempo le falta al jugador para revivir
            if i == 0:
                barraLista[i] = "|▓"
                barra = "".join(barraLista)
                print(barra)
                i +=1
                
            elif i == len(barraLista)-1:
                barraLista[i] = "▓|"
                barra = "".join(barra)
                print(barra)
                i +=1
                
            else:
                barraLista[i] = "▓"
                barra = "".join(barraLista)
                print(barra)
                i +=1
                
        #Se restablece el valor de respuesta para que el usuario al momento de morir pueda elegir si quiere continuar su empresa
        respuesta = ""
        #Los datos del personaje regresan a los originales
        personaje[0] = datosPersonajeOriginal[0]
    
    #En el caso que el usuario no desee continuar termina el juego.
    elif respuesta == "no":
        batalla = numeroBatallas +1
        print("\t\tDatos del jugador!")
        print("\t\t\t↓")
        print()
        print()
        print("******",personaje,"********")
        print()
        print()
        