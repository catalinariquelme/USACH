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

#Fecha: 22/09/2020
#VERSION:4.6.2
#Objetivo: Sistema de combate automático entre un personaje elegido por el usuario y un personaje, 
#enemigo aleatorio implementando el modelo autamtico ATB, ahora con mas elementos RPG y sistema de guardado


#BLOQUE DE FUNCIONES#

#Importación de constantes
#no hay

#Definición de constantes
#no hay

#Importación de funciones
#Se importa para generar un número entero al azar entre ciertos párametros
from random import randint
from time import sleep
#Se importa para elegir un valor al azar en un conjunto de elementos en este caso un lista
from random import choice
from datetime import datetime

#Definición de Funciones

#Funcion para leer un archivo
#Entrada: nombre del archivo(string)
#Salida: lista con string con el contenido del archivo
def lectura (nombreArchivo):
    nombreArchivo = nombreArchivo + ".csv"
    nombreArchivo = open(nombreArchivo,"r")
    datosArchivo = nombreArchivo.readlines()
    nombreArchivo.close()
    return datosArchivo
    
#Funcion para escribir en un archivo
#Entrada: nombre del archivo(string), texto a escribir en el archivo(string)
#Salida: booleano True
def escribir(nombre,texto):
    nombre = nombre + ".csv"
    archivo = open(nombre,"w")
    archivo.write(texto)
    archivo.close()
    return True

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
def aumentoPorNivel (personaje,datosPersonajeOriginal,datosPersonajeAumentados,batalla):
    #Aumento de la vida
    if batalla%10 == 0:
        personaje[2] = datosPersonajeAumentados[2] + aumentoAtributo(datosPersonajeOriginal[2],personaje[17])
        personaje[4] = datosPersonajeAumentados[4] + aumentoAtributo(datosPersonajeOriginal[4],personaje[17])
        personaje[5] = datosPersonajeAumentados[5] + aumentoAtributo(datosPersonajeOriginal[5],personaje[17])
        personaje[10] = datosPersonajeAumentados[10] + aumentoAtributo(datosPersonajeOriginal[10],personaje[17])
        personaje[11] = datosPersonajeAumentados[11] + aumentoAtributo(datosPersonajeOriginal[11],personaje[17])
        personaje[12] = datosPersonajeAumentados[12] + aumentoAtributo(datosPersonajeOriginal[12],personaje[17])
        personaje[13] = datosPersonajeAumentados[13] + aumentoAtributo(datosPersonajeOriginal[13],personaje[17])
        
    else:
        personaje[2] = datosPersonajeAumentados[2] + aumentoAtributo(datosPersonajeOriginal[2],personaje[16])
        personaje[4] = datosPersonajeAumentados[4] + aumentoAtributo(datosPersonajeOriginal[4],personaje[16])
        personaje[5] = datosPersonajeAumentados[5] + aumentoAtributo(datosPersonajeOriginal[5],personaje[16])
        personaje[10] = datosPersonajeAumentados[10] + aumentoAtributo(datosPersonajeOriginal[10],personaje[16])
        personaje[11] = datosPersonajeAumentados[11] + aumentoAtributo(datosPersonajeOriginal[11],personaje[16])
        personaje[12] = datosPersonajeAumentados[12] + aumentoAtributo(datosPersonajeOriginal[12],personaje[16])
        personaje[13] = datosPersonajeAumentados[13] + aumentoAtributo(datosPersonajeOriginal[13],personaje[16])

    return True
#Funcion para calcular la experiencia tras una batalla ganada por el personaje
#Entrada: Numeros de combate
#Salida: experiencia (float)

def calculoExperiencia(experienciasOp,nivelesOp,nivelPersonaje,factorCrit,factorDaño):
    experiencia = (experienciasOp*(nivelesOp/nivelPersonaje)*factorCrit*(1+factorDaño))/7
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
#Entrada: entero que determina en que batalla se encuentra el usuario(batalla)
#Salida: lista con los datos del enemigo
def seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes):

    #En el caso que el usuario se encuentre en una batalla multiplo de 10
    if batalla%10 == 0:

        enemigo = randint(1,len(listaClasesJefes)-1)
        i = 1
        while i < len(listaClasesJefes):
            if enemigo == i:
                #Se asigna como enemigo una lista almacenada en una lista que contiene todo los jefes.
                enemigo = listaClasesJefes[enemigo][:]
                i = len(listaClasesJefes)
            i += 1
    
    #En el caso que no sea una batalla multiplo de 10 se elige un enemigo al azar entre 1 y 3
    else:
        enemigo = randint(1,len(listaClasesEnemigos)-1)
        i = 1
        while i < len(listaClasesEnemigos):
            if enemigo == i:
                #Se asigna como enemigo una lista almacenada en una lista que contiene todo los enemigos
                enemigo = listaClasesEnemigos[enemigo][:]
                i = len(listaClasesEnemigos)
            i += 1
            
    return enemigo
#Funcion para ejecutar el Turno del Enemigo
#Entrada: lista con los datos del enemigo,lista con los datos del personaje,booleano turno enemigo, lista con los datos iniciales del enemigo
#Salida: Booleano determinando si termino o no el turno del enemigo
def accionEnemigo (datosEnemigo, datospersonaje, turnoEnemigo,datosEnemigoOriginal):
    #En el caso que la vida sea negativa o igual a cero termina el turno del enemigo
    if datosEnemigo[2] <= 0:
        turnoEnemigo = False
        
    #Por el contrario el enemigo realiza acciones
    else:
        print("Atacará", datosEnemigo[0])
        print("Turno enemigo")
        #Se le pide al usuario que presione enter para tener un mejor control del terminal, [reemplazar por sleeps("Inserte cantidad de tiempo que quiere robar")]
        #Y evitar que demasiado texto se imprima en poco tiempo
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
            sleep(1/datosEnemigo[3]) 
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
            numeroAtaque = datosEnemigo[4] + numeroAleatorio
            #Si el número de ataque es mayor a la defensa del personaje puede atacar
            if numeroAtaque >= datospersonaje[5]:
                #Fallo
                #Si el número al azar es 1 ocurre un excepción el cual beneficia al personaje
                #dañando al propio enemigo
                if  numeroAleatorio == 1: 
                    print("La vida del enemigo es de ",datosEnemigo[2],"de vida")
                    #Se determina el número de fallo entre 1 y 3
                    numeroFallo = randint(1,3)
                    #Se le resta el número de fallo al enemigo
                    datosEnemigo[2] = datosEnemigo[2]-numeroFallo       
                    print("El enemigo falló el ataque y se hizo daño a el mismo")
                    print("Le quedan",datosEnemigo[2],"de vida al enemigo")
                    
                #Crítico
                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                elif numeroAleatorio == 20:
                    print()
                    print("El enemigo logró realizarte daño")
                    print()
                    print("CRÍTICO")
                    print("Te quedan",datospersonaje[2],"de vida")
                    #El daño del enemigo aumenta 2* por un valor dado por un número al azar entre el daño
                    #mínimo y máximo del enemigo
                    daño= 2*(randint(datosEnemigo[10],datosEnemigo[11]))
                    #Se le resta el daño calculado al personaje
                    datospersonaje[2] = datospersonaje[2] - daño
                    print("El enemigo te hizo",daño,"de daño")
                    print("Te queda ",datospersonaje[2],"de vida")
                    print()
                #Para cualquiero otro caso el procedimiento es normal
                else:
                    print("El enemigo realizó un ataque con éxito")
                    print()
                    #Se determina el daño que realiza entre el daño mínimo y máximo del enemigo
                    daño = randint(datosEnemigo[10],datosEnemigo[11])
                    print("Tú vida actual es:",datospersonaje[2])
                    print("El enemigo te realizado",daño,"de daño")
                    #Se le resta la vida al personaje
                    datospersonaje[2] = datospersonaje[2] - daño
                    print("Tú vida ahora es:", datospersonaje[2])
                    print()
            else:#El enemigo no pudo superar el dato de defensa del personaje
                print("El enemigo falló el ataque")
                print()
            turnoEnemigo= False
            
        #Hechizo
        elif ataqueHechizo ==2:
            print()
            print("Enemigo ha escogido Hechizo")
            print()
            #Se determina el umbral del enemigo eligiendo un número al azar entre 1 y 20
            umbral = randint(1,20)
            #Si el número es mayor al umbral puede realizar un Hechizo
            if umbral > datosEnemigo[6]:
                valor = randint(0,100)
                #Hechizo de Ataque
                if valor < datosEnemigo[7]:
                    print("El enemigo va a realizar Hechizo de ataque")
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                    if valor == 20: 
                        print("CRÍTICO")
                        print()
                        #Se determina el daño que realizará el enemigo a través de un número al azar entre el
                        #daño de hechizo máximo y mímino del enemigo, este tiene que ser entero
                        daño = int(randint(datosEnemigo[12],datosEnemigo[13])*1.5)
                        print("Tú vida actual es:",datospersonaje[2])
                        print("El enemigo logro realizarte",daño,"de daño")
                        #Se le resta la el daño al personaje
                        datospersonaje[2] = datospersonaje[2] - daño
                        print("Tú nueva vida es de:",datospersonaje[2])
                        print()
                        
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    elif valor ==1:
                        print("La vida del enemigo es de:",datosEnemigo[2])
                        print("El enemigo fallo al realizar Hechizo de Ataque")
                        #Se le resta la mitad de la vida al enemigo, tiene que ser entero
                        datosEnemigo[2] = int(datosEnemigo[2]/2)
                        print("Realizandose el Hechizo de Ataque contra el mismo")
                        print("La vida del enemigo se redujo a la mitad")
                        print("La vida actual del enemigo es:",datosEnemigo[2])
                        print()
                        
                    #Para cualquier otro caso el procedimiento es el mismo
                    else:
                        #Se determina el daño que realiza entre el daño de hechizo máximo y mínimo
                        daño = randint(datosEnemigo[12],datosEnemigo[13])
                        print("Tu vida es:",datospersonaje[2])
                        print("El enemigo realizó",daño,"de daño")
                        #Se le resta el daño provocado por el enemigo al personaje
                        datospersonaje[2] = datospersonaje[2] - daño
                        print("Tú nueva vida es:", datospersonaje[2])
                        print()
                        
                #Hechizo de Defensa
                elif valor < datosEnemigo[8]:
                    print("Enemigo va a realizar Hechizo de Defensa")
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    if valor == 20:
                        print("CRÍTICO")
                        print()
                        print("La defensa del enemigo es:",datosEnemigo[5])
                        #Aumenta la defensa en 2 
                        datosEnemigo[5]= datosEnemigo[5] + 2
                        print("La defensa del enemigo ha aumentado en 2")
                        print("La nueva defensa del enemigo es",datosEnemigo[5])
                        print()
                        
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al usuario
                    elif valor == 1:
                        print("FALLO")
                        print()
                        print("Tú defensa es: ",datospersonaje[5])
                        #Aumenta en 1 el valor de la defensa del personaje
                        datospersonaje[5] = datospersonaje[5] +1
                        print("El enemigo ha fallado el Hechizo")
                        print("A aumentado tú defensa")
                        print("Tú nueva defensa es: ",datospersonaje[5])
                        print()
                        
                    #En cualquier otro caso el procedimiento es el normal
                    else:
                        print("La defesa del enemigo es:",datosEnemigo[5])
                        #Aumenta en la defensa del personaje en 1
                        datosEnemigo[5] += 1
                        print("Ha aumentado la defensa del enemigo")
                        print("Ahora su defensa es :",datosEnemigo[5])
                        print()
                        
                #Hechizo de Curación
                elif valor < enemigo[9]:
                    print("El enemigo va a realizar Hechizo de Curación")
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                    if valor == 20:
                        print("CRÍTICO")
                        print()
                        print("La vida del enemigo es: ",datosEnemigo[2])
                        #En el caso que el usuario tenga la vida llena no se curará
                        if datosEnemigo[2] == datosEnemigoOriginal[2]: 
                            print("Enemigo no se pudo curar ya que tiene vida al máximo")
                            print()

                        #Si no tiene la vida al máximo significa que puede curarse
                        else:
                            #Aumenta en 4 el nivel de vida del personaje
                            datosEnemigo[2] +=4
                            print("El enemigo se a curado 4 de vida")
                            #Si los puntos de curación superan los límites originales, quedará con el puntaje original
                            #ya que la vida no puede superar los datos originales
                            if datosEnemigo[2] > datosEnemigoOriginal[2]:
                                datosEnemigo[2] = datosEnemigoOriginal[2]
                                print("La nueva vida del enemigo es: ",datosEnemigo[2])
                                
                            else:
                                print("La nueva vida del enemigo es: ",datosEnemigo[2])
                                
                            print()
                    #Fallo
                     #Si el número al azar es 1 ocurre una excepción que beneficia al personaje
                    elif valor == 1:
                        print("El enemigo ha fallado el Hechizo de curación y te curo a ti")
                        print("Tú vida actual es:",datospersonaje[2])
                        datospersonaje[2]+=4 
                        #En el caso que el enemigo no tenga la vida llena, se curará 
                        if datospersonaje[2] == datosPersonajeOriginal:
                            print("No te has podido curar porque tienes la vida al máximo")
                            
                        else:
                            print("Y te a curado 4 de vida")
                            if datospersonaje[2] >datosPersonajeOriginal[2]:
                                datospersonaje[2]= datosPersonajeOriginal[2]
                                print("Tu nuevo nivel de vida es: ",datospersonaje[2])
                                
                            else:
                                print("Tu nuevo nivel de vida es: ",datospersonaje[2])
                                
                        print()
                     #En cualquier otro caso se seguirá con un Hechizo de Curación normal  
                    else:
                        if datosEnemigo[2] == datosEnemigoOriginal[2]:
                            print("El enemigo no se pudo curar ya que tiene la vida al máximo")
                            print()
                        #Si la vida no se encuntra completa, se curará    
                        else:
                            #Se elige un número al azar entre 1 y 8 con el fin de curar al personaje
                            cura = randint(1,8)
                            print("Se va curar ", cura ,"de vida")
                            datosEnemigo[2]= datosEnemigo[2] + cura
                            #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                            if datosEnemigo[2] > datosEnemigoOriginal[2]:
                                datosEnemigo[2] = datosEnemigoOriginal[2]
                                print("La nueva vida del enemigo es:",datosEnemigo[2])
                            else:
                                print("La nueva vida del enemigo es:",datosEnemigo[2])
                            print()
                            
                #Ataque Simple
                else:
                    print("El enemigo realizó Ataque Simple")
                    print()
                    daño = randint(datosEnemigo[10],datosEnemigo[11])
                    print("Tú vida actual es:",datospersonaje[2])
                    datospersonaje[2] = datospersonaje[2] - daño
                    print("El enemigo te ha quitado",daño,"de vida")
                    print("Ahora te quedan",datospersonaje[2], "puntos de vida")
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

def accionEnemigoSkip (datosEnemigo, datospersonaje, turnoEnemigo,datosEnemigoOriginal):
    #En el caso que la vida del enemigo sea menor o igual a 0 acaba el turno del enemigo
    if datosEnemigo[2] <= 0:
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
            numeroAtaque = datosEnemigo[4] + numeroAleatorio
            #Si el número de ataque es mayor a la defensa del personaje puede atacar
            if numeroAtaque >= datospersonaje[5]:
                #Fallo
                #Si el número al azar es 1 ocurre un excepción el cual beneficia al personaje
                #dañando al propio enemigo
                if  numeroAleatorio == 1: 
                    #Se determina el número de fallo entre 1 y 3
                    numeroFallo = randint(1,3)
                    #Se le resta el número de fallo al enemigo
                    datosEnemigo[2] = datosEnemigo[2]-numeroFallo      
                    
                #Crítico
                #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                elif numeroAleatorio == 20:
                    #El daño del enemigo aumenta 2* por un valor dado por un número al azar entre el daño
                    #mínimo y máximo del enemigo
                    daño= 2*(randint(datosEnemigo[10],datosEnemigo[11]))
                    #Se le resta el daño calculado al personaje
                    datospersonaje[2] = datospersonaje[2] - daño
                    
                #Para cualquiero otro caso el procedimiento es normal
                else:
                    #Se determina el daño que realiza entre el daño mínimo y máximo del enemigo
                    daño = randint(datosEnemigo[10],datosEnemigo[11])
                    #Se le resta la vida al personaje
                    datospersonaje[2] = datospersonaje[2] - daño
            
            #El turno del usuario termino
            turnoEnemigo= False
            
        #Hechizo
        elif ataqueHechizo ==2:
            #Se determina el umbral del enemigo eligiendo un número al azar entre 1 y 20
            umbral = randint(1,20)
            #Si el número es mayor al umbral puede realizar un Hechizo
            if umbral > datosEnemigo[6]:
                valor = randint(1,100)
                #Hechizo de Ataque
                if valor < datosEnemigo[7]:
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    if valor == 20: 
                        #Se determina el daño que realizará el personaje a través de un número al azar entre el
                        #daño de hechizo máximo y mímino del personaje, este tiene que ser entero
                        daño= int(randint(datosEnemigo[12],datosEnemigo[13])*1.5)
                        #Se le resta la el daño al personaje
                        datospersonaje[2] = datospersonaje[2] - daño
                        
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al personaje
                    elif valor ==1:
                        #Se le resta la mitad de la vida al enemigo, tiene que ser entero
                        datosEnemigo[2] = int(datosEnemigo[2]/2)
                        
                    #Para cualquier otro caso el procedimiento de Hechizo normal
                    else:
                        #Se determina el daño que realiza entre el daño de hechizo máximo y mínimo
                        daño = randint(datosEnemigo[12],datosEnemigo[13])
                        #Se le resta el daño provocado por el personaje al enemigo
                        datospersonaje[2] = datospersonaje[2] - daño
                        
                #Hechizo de Defensa
                elif valor < datosEnemigo[8]:
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    if valor == 20:
                        #Aumenta la defensa en 2
                        datosEnemigo[5]= datosEnemigo[5] + 2
                        #Se suma a la variable para decidir FactorCrit
                        
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al personaje
                    elif valor == 1:
                        #Aumenta en 1 el valor de la defensa del enemigo
                        datospersonaje[5] = datospersonaje[5] +1
                        
                    #En cualquier otro caso el procedimiento de Hechizo de Defensa normal
                    else:       
                        #Aumenta en la defensa del enemigo en 1
                        datosEnemigo[5] += 1
                        
                #Hechizo de Curación
                elif valor < datosEnemigo[9]:
                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                    if valor == 20:
                        #Se restaura 4 puntos de vida del enemigo
                        datosEnemigo[2] +=4
                        #Si los puntos de curación superan los límites originales, quedará con el puntaje original
                        #ya que la vida no puede superar los datos originales
                        if datosEnemigo[2] > datosEnemigoOriginal[2]: 
                            datosEnemigo[2] = datosEnemigoOriginal[2]
                                
                    #Fallo
                    #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                    elif valor == 1:
                        #Se le aumenta 4 a la vida del enemigo
                        datospersonaje[2]+=4
                        #Si el puntaje de curado supera el límite de vida, quedará el puntaje original ya que no se pueden
                        #superar esos valores
                        if datospersonaje[2] >datosPersonajeOriginal[2]:
                            datospersonaje[2]= datosPersonajeOriginal[2]
                        
                    #En cualquier otro caso se seguirá con un Hechizo de Curación normal
                    else:
                        #Se elige un número al azar entre 1 y 8 con el fin de curar al enemigo
                        cura = randint(1,8)
                        datosEnemigo[2]= datosEnemigo[2] + cura
                        #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                        if datosEnemigo[2] > datosEnemigoOriginal[2]:
                            datosEnemigo[2] = datosEnemigoOriginal[2]
                    
                #Ataque Simple
                #En el caso que no se puede realizar HA, HD y HC, el personaje ataca normalmente
                else:
                    #Se determina el daño que va a realizar el enemigo con un número al azar entre el daño
                    #máximo y mínimo
                    daño = randint(datosEnemigo[10],datosEnemigo[11])
                    #Se le resta el daño a la vida del personaje
                    datospersonaje[2] = datospersonaje[2] - daño
                    
                #Termina el turno de enemigo
                turnoEnemigo = False        
            
    return turnoEnemigo
    
#Función que realiza la batalla sin imprimir datos al usuario, lado usario
#Entrada: lista con los datos del personaje, lista con los datos iniciales del personaje 
#Salida: print ganaste/perdiste
def skipBatalla(personaje,datosPersonajeOriginal,criticosHechos,fallosHechos,experiencia,siguienteNivel,batalla,partidaCargada,partida):
    #En el caso que la número de batalla que esta jugando el usuario sea multiplo de 10, se enfrentará a un jefe
    #Se ve si la variable batalla corresponde al enfrentamiento contra el jefe
    
    sumaExperienciaEnemigos = 0
    if batalla%10 == 0:
        cantidadEnemigos = randint(1,3)
        listaEnemigos = []
        
        #En el caso que sea un enemigo a enfrentar se crea solo una variable de enemigo
        if cantidadEnemigos == 1:
            #Se llama a la función que selecciona el enemigo al azar
            enemigo1  = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            
                
            print("¡¡¡SE ACERCA UN JEFE!!!")
            #Se almacena en la lista destinada a guardar los enemigos
            listaEnemigos = [enemigo1]
            #Se respaldan los datos iniciales del enemigo
            datosEnemigoOriginal1 = enemigo1[:]
            datosEnemigoOriginal1Aumentado = enemigo1[:] 
            #Se determina la variable enemigo como enemigo1 ya que no existen más enemigos
            enemigo = enemigo1[:]
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1]
            if personaje[15] == 1:
                enemigo1[15] = 1

            else:
                enemigo1[15] = personaje[15]-1  

            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo
            while i <=  enemigo1[15]:
                nivelActual = experienciaPorNivel(enemigo1[1],i)
                if nivelActual < experienciaPorNivel(personaje[1],enemigo1[15]):
                    aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)

                i+=1
            
            sumaNivelesEnemigos = enemigo[15]
            sumaExperienciaEnemigos += round(experienciaPorNivel(enemigo1[1],enemigo1[15]))
            sleep(1/2)
            print()
            print("Te enfrentaras a",cantidadEnemigos,"enemigo:",enemigo1[0])
    else:
        
        cantidadEnemigos = randint(1,3)
        #Se crea una lista en donde se guardaran los datos de los enemigos
        listaEnemigos = []
        #En el caso que sea un enemigo a enfrentar se crea solo una variable de enemigo
        if cantidadEnemigos == 1:
            #Se llama a la función que selecciona el enemigo al azar
            enemigo1  = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            #Se almacena en la lista destinada a guardar los enemigos
            listaEnemigos = [enemigo1]
            #Se respaldan los datos iniciales del enemigo
            datosEnemigoOriginal1 = enemigo1[:]
            datosEnemigoOriginal1Aumentado = enemigo1[:] 
            #Se determina la variable enemigo como enemigo1 ya que no existen más enemigos
            enemigo = enemigo1[:]
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1]
            if personaje[15] == 1:
                enemigo1[15] = 1

            else:
                enemigo1[15] = personaje[15]-1

            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo
            while i <=  enemigo1[15]:
                nivelActual = experienciaPorNivel(enemigo1[1],i)
                if nivelActual < experienciaPorNivel(personaje[1],enemigo1[15]):
                    aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                i+=1
                
            sumaNivelesEnemigos = enemigo[15]
            sumaExperienciaEnemigos += round(experienciaPorNivel(enemigo1[1],enemigo1[15])) 
            #Se imprimen los datos del enemigo en forma de tabla hasta el valor 13
            print()
            print("Tu primer enemigo es: " + enemigo[0])
 
        #En el caso que sean dos enemigos a enfrentar
        elif cantidadEnemigos == 2:
            #Se elige un número entre el 0 y el 1 para posteriormente utilizar este número 
            #como indice para determinar un enemigo con el se comparen las velocidades
            enemigo = randint(0,1)
            #Se elige un enemigo entre los tres enemigos disponibles
            enemigo1  = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            #Se escoge el segundo enemigo
            enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            #En el caso que ambos enemigos sean los mismos se escoge otro de los 2 restantes
            while enemigo1 == enemigo2: # Para previnir que se dupliquen enemigos
                enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            enemigo1[15] = randint(1,personaje[15])
            enemigo2[15] = randint(1,personaje[15])
            #Si el nivel del personaje es 1, el nivel de los enemigos es 1
            if personaje[15] == 1:
                enemigo1[15] = 1
                enemigo2[15] = 1

            #Si el nivel del personaje es 2, el nivel de los enemigos es 1
            elif personaje[15] == 2:
                enemigo1[15] = 1
                enemigo2[15] = 1
            
            else:    
                while not(enemigo1[15] + enemigo2[15] < personaje[15]):
                    enemigo1[15] = randint(1,personaje[15]-1)
                    enemigo2[15] = randint(1,personaje[15]-1)
                        
            #Se guardan los datos iniciales de los enemigos
            datosEnemigoOriginal1 = enemigo1[:]
            datosEnemigoOriginal2 = enemigo2[:]
            datosEnemigoOriginal1Aumentado = enemigo1[:]
            datosEnemigoOriginal2Aumentado = enemigo2[:]
            #Se Calcula la experiencia del enemigo 1
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[1],enemigo1[15])
            #Se calcula la experiencia del enemigo 2 y se suma a la del enemigo 1, dando el total
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[1],enemigo2[15])
            #Se calcula la suma de los niveles de los enemigos
            sumaNivelesEnemigos = enemigo1[15] + enemigo2[15]
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 1
            while i <=  enemigo1[15]:
                nivelActual = experienciaPorNivel(enemigo1[1],i)
                if nivelActual < experienciaPorNivel(enemigo1[1],enemigo1[15]):
                    aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                i += 1
            
            #Se realiza un ciclo para aumentar el nivel del enemigo 2
            i = 1
            nivelActual = 1
            while i <=  enemigo2[15]:
                nivelActual = experienciaPorNivel(enemigo2[1],i)
                if nivelActual < experienciaPorNivel(enemigo2[1],enemigo2[15]):
                    aumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal2Aumentado,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                
                i+= 1

            #Se colocan ambos datos de los enemigos en una lista
            listaEnemigos = [enemigo1,enemigo2]
            enemigo = listaEnemigos[enemigo][:]
            #Se crea una lista en donde se guardan las listas que contienen los datos iniciales de los enemigps
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2]
            #Se coloca un sleep para que usuario alcance a leer la información
            #Se imprime la tabla de descripción del enemigo
            print("Tu primer enemigo es " + enemigo1[0])
            #Se coloca un sleep para que usuario alcance a leer la información
            #Una vez ya escogido ambos enemigos distintos se imprime los datos del enemigo restante
            print("Tu segundo enemigo es " + enemigo2[0])
            
        #En el caso que sean tres enemigos a enfrentar
        elif cantidadEnemigos == 3:
            #Se elige un número entre el 0 y el 2 para posteriormente utilizar este número 
            #como indice para determinar un enemigo con el se comparen las velocidades
            enemigo = randint(0,2)
            #Se elige un enemigo entre los tres enemigos disponibles
            enemigo1 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)

            #Se escongen dos enemigos al azar
            enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            enemigo3 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            #En el caso que se repitan los enemigos a enfrentar se escogen otros hasta que sean distintos
            while enemigo1 == enemigo2 or enemigo1 == enemigo3 or enemigo2 == enemigo3 :
                enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                enemigo3 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)

            enemigo1[15] = randint(1,personaje[15])
            enemigo2[15] = randint(1,personaje[15])
            enemigo3[15] = randint(1,personaje[15])
            #En el caso que la vida del personaje sea 1, las vidas de los enemigos quedán definidas como 1
            if personaje[15] == 1:
                enemigo1[15] = 1
                enemigo2[15] = 1
                enemigo3[15] = 1
            
            #En el caso que la vida del personaje sea 2, la vida de los enemigos quedán definidas como 1
            elif personaje[15] == 2:
                enemigo1[15] = 1
                enemigo2[15] = 1
                enemigo3[15] = 1

            #En el caso que la vida del personaje sea 3, la vida de los enemigos quedán definidas como 1
            elif personaje[15] == 3:
                enemigo1[15] = 1
                enemigo2[15] = 1
                enemigo3[15] = 1
                
            #Desde el nivel 4 en adelante 
            else:
                while not(enemigo1[15] + enemigo2[15] + enemigo3[15] < personaje[15]):
                    enemigo1[15] = randint(1,personaje[15]-1)
                    enemigo2[15] = randint(1,personaje[15]-1)
                    enemigo3[15] = randint(1,personaje[15]-1)

            #Se respaldan los datos de los enemigos
            datosEnemigoOriginal1 = enemigo1[:]
            datosEnemigoOriginal2 = enemigo2[:]
            datosEnemigoOriginal3 = enemigo3[:]
            datosEnemigoOriginal1Aumentado = enemigo1[:]
            datosEnemigoOriginal2Aumentado = enemigo2[:]
            datosEnemigoOriginal3Aumentado = enemigo3[:]
            #Se calcula la experiencia del enemigo1 
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[1],enemigo1[15])
            #Se calcula la experiencia del enemigo2, sumandolo al del enemigo 1
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[1],enemigo2[15])
            #Se calcula la experiencia del enemigo 3, sumandola al del enemigo 1 y 2, dando el total
            sumaExperienciaEnemigos += experienciaPorNivel(enemigo3[1],enemigo3[15])
            #Se suman los niveles de los enemigos
            sumaNivelesEnemigos = enemigo1[15] + enemigo2[15] + enemigo3[15]
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 1
            while i <=  enemigo1[15]:
                nivelActual = experienciaPorNivel(enemigo1[1],i)
                if nivelActual < experienciaPorNivel(enemigo1[1],enemigo1[15]):
                    aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                i += 1

            #Se realiza un ciclo para aumentar el nivel del enemigo 2
            i = 1
            nivelActual = 1
            while i <=  enemigo2[15]:
                nivelActual = experienciaPorNivel(enemigo2[1],i)
                if nivelActual < experienciaPorNivel(enemigo2[1],enemigo2[15]):
                    aumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal2Aumentado,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                i+= 1
                
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo 3
            while i <=  enemigo3[15]:
                nivelActual = experienciaPorNivel(enemigo3[1],i)
                if nivelActual < experienciaPorNivel(enemigo3[1],enemigo3[15]):
                    aumentoPorNivel(enemigo3,datosEnemigoOriginal3,datosEnemigoOriginal3Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal3Aumentado,datosEnemigoOriginal3,datosEnemigoOriginal3Aumentado,batalla)

                i+= 1

            #Se coloca un sleep para que usuario alcance a leer la información
            sleep(3)
            #Se agregan los datos de los enemigos a una lista 
            listaEnemigos = [enemigo1,enemigo2,enemigo3]
            enemigo = listaEnemigos[enemigo][:]
            #Se crea una lista en donde se guardan los datos iniciales de todos los enemigos
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2,datosEnemigoOriginal3]
            print("Tu primer enemigo es " + enemigo1[0])
            print("Tu segundo enemigo es " + enemigo2[0])
            print("Tu tercer enemigo es " + enemigo3[0])

    #Para determinar a quien le toca primero se comparan las velocidades del personaje y enemigo1
    #Para determinar cuando empieza y acaba el turno del personaje se crea una variable que vuelve False cuando termina el turno  
    if personaje[3] >= enemigo[3]:
        turno = True
        turnoEnemigo = False
        
    elif enemigo[3] > personaje[3]:
        turno= False
        turnoEnemigo= True
        
    #Mientras la vida de ambos contrincantes sea positiva tendrá a lugar la batalla  
    #Se decide si pelea contra el jefe dependiendo de la cantidad de batallas
    while cantidadEnemigos > 0 and personaje[2]>0:
        #Se elige de una manera pseudo-aleatoria el enemigo que atacará 
        enemigo = choice(listaEnemigos)
        #Se determina en que posición se encuentran los datos del enemigo de la ronda
        posicion = listaEnemigos.index(enemigo)
        #Se determina los datos originales del enemigo en base a la lista que contenia los datos
        #originales de los enemigos y la posición
        datosEnemigoOriginal = listaDatosEnemigosOriginal[posicion]
        #Mientras el turno del personaje sea True, se ejecutara el ciclo
        while turno == True:
            #En el caso que el personaje sea Fighter se elige automaticamente Ataque ya que este no puede
            #realizar hechizos
            if personaje[0] == "Fighter":
                accion = 1
            #En caso que sea otro personaje se escoge el azar
            else:
                accion = randint(1,2)
                
            #Ataque
            #Si la acción es 1 se realiza el ataque         
            if accion == 1:
                #Se escoge un número al azar entre 1 y 20
                numeroAleatorio = randint(1,20)
                #En base al número aleatorio se suma con el ataque del personaje para determinar
                #el número de ataque
                numeroAtaque = numeroAleatorio + personaje[4]
                #Si el número de ataque es mayor a la defensa del enemigo puede atacar
                if numeroAtaque >= enemigo[5] :
                    #Fallo
                    #Si el número al azar es 1 ocurre un excepción el cual beneficia al enemigo
                    if numeroAleatorio == 1:
                        #Se determina el número de fallo entre 1 y 3
                        numeroFallo = randint(1,3)
                        #Se le resta el número de fallo al personaje
                        personaje[2] = personaje[2] - numeroFallo

                    #Crítico
                    #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                    elif numeroAleatorio == 20:
                        #El daño del personaje aumenta 2* por un valor dado por un número al azar entre el daño
                        #mínimo y máximo del personaje
                        daño = 2 * (randint(personaje[10],personaje[11]))
                        #Se le resta el daño calculado al personaje
                        enemigo[2] = enemigo[2] - daño
                        criticosHechos += 1 
                        
                    #Para cualquier otro caso el procedimiento es el normal  
                    else:
                        #Se determina el daño que realiza entre el daño mínimo y máximo del personaje
                        daño = randint(personaje[10],personaje[11])
                        #Se le resta la vida al enemigo
                        enemigo[2] = enemigo[2] - daño
                    
                    #El turno del usuario termino
                    turno = False
                    
                #En el caso de no ser mayor a la defensa el enemigo no puede atacar
                else: 
                    #Al fallar aumenta el contador de fallos
                    fallosHechos+=1
                    #El turno del usuario a terminado
                    turno = False
                    
            #Hechizo
            #Si la accion es 2 se realizara un hechizo
            elif accion == 2:
                #Se determina el umbral del personaje eligiendo un número al azar entre 1 y 20
                umbral = randint(1,20)
                #Si el número es mayor al umbral puede realizar un Hechizo
                if umbral > personaje[6]:
                    valor = randint(1,100)
                    #Hechizo de Ataque
                    if valor < personaje[7]:
                        #Crítico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        if valor == 20:
                            #Se determina el daño que realizará el personaje a través de un número al azar entre el
                            #daño de hechizo máximo y mímino del personaje, este tiene que ser entero
                            daño = int(randint(personaje[12],personaje[13])*1.5)
                            #Se le resta la el daño al enemigo
                            enemigo[2] = enemigo[2]-daño 
                            criticosHechos += 1 
                            
                        #Fallo
                        #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                        elif valor == 1:
                            #Se le resta la mitad de la vida al personaje, tiene que ser entero
                            personaje[2] = int(personaje[2]/2)
                            
                        #Por elcontrario actua con normalidad
                        else:
                            #Se determina el daño que realiza entre el daño de hechizo máximo y mínimo
                            daño = randint(personaje[12],personaje[13])
                            #Se le resta el daño provocado por el personaje al enemigo
                            enemigo[2] = enemigo[2]-daño
                            
                    #Hechizo de Defensa
                    elif valor < personaje[8]:
                        #Crítico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        if valor ==20:
                            #Aumenta la defensa en 2 
                            personaje[5] += 2
                            criticosHechos += 1
                            
                        #Fallo
                        #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                        elif valor ==1:
                            #Aumenta en 1 el valor de la defensa del enemigo
                            enemigo[5] += 1
                            
                        #Por el contario se sigue con normalidad
                        else:
                            #Aumenta en la defensa del personaje en 1
                            personaje[5] += 1
                            
                    #Hechizo de Curación
                    elif valor < personaje[9]:
                        #Crítico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        if valor == 20:
                            #En el caso que el usuario tenga la vida llena no se curará
                            if personaje[2] == datosPersonajeOriginal[2]:
                                criticosHechos += 1
                                
                            #Si no tiene la vida al máximo significa que puede curarse
                            else:
                                #Aumenta en 4 el nivel de vida del personaje
                                personaje[2] += 4
                                #Si los puntos de curación superan los límites originales, quedará con el puntaje original
                                #ya que la vida no puede superar los datos originales
                                if personaje[2] > datosPersonajeOriginal[2]:
                                    personaje[2] = datosPersonajeOriginal[2]
                                    criticosHechos += 1 
                                #En el caso que no superen los datos orginales del personaje quedaran los datos con el aumento
                                else:
                                    criticosHechos += 1 
                                
                        #Fallo
                        #Si el número al azar es 1 ocurre una excepción que beneficia al enemigo
                        elif valor == 1:
                            #En el caso que el enemigo no tenga la vida llena, se curará 
                            if enemigo[2] != datosEnemigoOriginal[0]:
                                #Se le aumenta 4 a la vida del enemigo
                                enemigo [0]+= 4 
                                #Si el puntaje de curado supera el límite de vida, quedará el puntaje original ya que no se pueden
                                #superar esos valores
                                if enemigo[2] > datosEnemigoOriginal[0]:
                                    enemigo[2] = datosEnemigoOriginal

                        #En cualquier otro caso se seguirá con un Hechizo de Curación normal
                        else:
                            #Si la vida no se encuntra completa, se curará
                            if personaje[2] != datosPersonajeOriginal[2]:
                                #Se elige un número al azar entre 1 y 8 con el fin de curar al personaje
                                cura = randint(1,8)
                                personaje[2] = personaje[2] + cura
                                #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                                if personaje[2] > datosPersonajeOriginal[2]:
                                    personaje[2] = datosPersonajeOriginal[2]
                        
                    #Ataque simple
                    #En el caso que no se puede realizar HA, HD y HC, el personaje ataca normalmente
                    else:
                        #Se determina el daño que va a realizar el personaje con un número al azar entre el daño
                        #máximo y mínimo
                        daño = randint(personaje[10],personaje[11])
                        #Se le resta el daño a la vida del enemigo
                        enemigo[2] = enemigo[2] - daño

                #En el caso que el número aleatorio no supere el umbral no podrá realizar Hechizo
                else:
                    #Al fallar aumenta el contador de fallos
                    fallosHechos+=1
                    #Acaba el turno del enemigo aunque no haya podido realizar el hechizo
                    turno = False
                    
                #Acaba el turno del usuario
                turno = False
        
        #Se coloca un sleep para que usuario alcance a leer la información
        
        #Se activa el turno del enemigo
        turnoEnemigo = True
        #Se comprueba que el enemigo se encuentre vivo antes de que empiece su turno
        while turnoEnemigo == True :
            #Se llama la función acción enemigo que realiza los moviemientos del enemigo
            turnoEnemigo = accionEnemigoSkip(enemigo,personaje,turnoEnemigo, datosEnemigoOriginal)
            
        #Se coloca un sleep para que usuario alcance a leer la información
        
        #Se activa el turno del personaje
        turno =  True
        #En el caso que muera uno de los enemigos muera disminuye la cantidad de enemigos
        #totales
        if enemigo[2] <= 0 :
            print("Murió "+ listaEnemigos[posicion][0])
            #Se resta en uno la cantidad de enemigos 
            cantidadEnemigos -=1            #Se elimina de la lista en donde se encuentran los enemigos al que murió
            listaEnemigos.pop(posicion)

    #En el caso que la vida del enemigo sea menor o igual a 0 significa que el enemigo murió
    if enemigo[2] <= 0:
        nivelAnterior = personaje[15]#               
        print()
        print("No quedan más oponentes")
        print("GANASTE")
        print()            
        #Cálculo factorCritic
        #Al terminar la batalla y terminar victoriozo el jugador recibe una bonificación por criticos y 
        #fallos hechos
        #En el caso que el caclulo sea mayor a 0 se asigna un valor de 1.5
        if (criticosHechos - fallosHechos) > 0:
            factorCritic = 1.5
            
        #En el caso que el caclulo sea menor a 0 se asigna un valor de 0.75
        elif (criticosHechos - fallosHechos) < 0:
            factorCritic = 0.75
            
        #En el caso que el caclulo sea igual a 0 se asigna un valor de 1
        elif (criticosHechos - fallosHechos) == 0:
            factorCritic = 1

        #Cálculo factorDaño
        #Bonificación por la salud restante de personaje, se divide la vida restante con la vida total
        factorDaño = int(1 + personaje[2]/ datosPersonajeAumentados[2])
        #Se suma  a la experencia ya calculada la acumulada en esta batalla
        experiencia += calculoExperiencia(sumaExperienciaEnemigos,sumaNivelesEnemigos,personaje[15],factorCritic,factorDaño)
        #Se calcula la experiencia para alcanzar el siguiente nivel   
        experienciaParaNivel = experienciaPorNivel(personaje[1],siguienteNivel)
        #Se redondea los resultados para evitar excesivos decimales
        experienciaParaNivel = round(experienciaParaNivel)
        #Se realiza un ciclo para aumentar nivel
        personaje[14] = experiencia
        while experienciaParaNivel <= experiencia: #Cuando se sube de nivel
            personaje[15] += 1
            #Se aumentan las estadisticas del personaje
            aumentoPorNivel(personaje,datosPersonajeOriginal,datosPersonajeAumentados,batalla)
            #Se aumentan las estadisticas base
            aumentoPorNivel(datosPersonajeAumentados,datosPersonajeOriginal,datosPersonajeAumentados,batalla)
            siguienteNivel += 1
            experienciaParaNivel = experienciaPorNivel(personaje[1],siguienteNivel)
            experienciaParaNivel = round(experienciaParaNivel)
            
        print("Necesitas "+ str(experienciaParaNivel) +" puntos de exp. para subir de nivel")
        sleep(3)
        if (personaje[15] - nivelAnterior) != 0:
            print()
            print("HAS SUBIDO DE NIVEL")
            print() 

    #Por el contrario si la vida del personaje es negativa significa que el personaje murió   
    elif personaje[2] <= 0:
        print("Has muerto")
        print()
        print("PERDISTE")
        print()
    if partidaCargada == False:
        #Se guardan en la variable personajeGuardado la información del personaje
        personajeGuardado = personaje[:]
        i = 0
        personajeGuardado[16] = round(personaje[16])
        #Se convierte a string los valores de esta lista
        while i < len(personajeGuardado):
            personajeGuardado[i] = str(personajeGuardado[i])
            i+=1
        
        #Se convierte a string la lista, separando los valores por comas
        personajeGuardado = ",".join(personajeGuardado)
        #Se asume que que archivo guardado tiene en la primera línea la descrpción 
        #Se obtiene la fecha y hora, convirtiendolo a string para poder juntarlo posteriormente
        fecha = str(datetime.now())
        #Se juntan los valores del personaje con el nombre del usuario y la fecha/hora de la partida
        textoGuardar = personajeGuardado+","+nombre+","+fecha
        #Se lee el contenido ques e tiene hasta el momento en el archivo y se almacena en la variable texto
        texto = lectura("guardado")
        print()
        #Al texto existente se agregan los datos que contienen la información de la partida
        texto.append("\n"+textoGuardar)
        partida = len(texto)-1
        #Se convierte todo a string para poder agregarlo al archivo
        texto = "".join(texto)
        #Al escribir en el archivo se coloca toda la infromación
        escribir("guardado",texto)
        #Tras ser agregado los datos archivo para posteriores guardados se sobrescribe el valor, no se crea otro
        #por lo que cambia el modo de guardado
        partidaCargada = True
    
    #En el caso que exista la partida en el archivo, se sobreescribe
    elif partidaCargada == True:
        personajeGuardado= personaje[:]
        i = 0
        personajeGuardado[16] = round(personaje[16])
        while i < len(personajeGuardado):
            personajeGuardado[i] = str(personajeGuardado[i])
            i+=1
        
        personajeGuardado = ",".join(personajeGuardado)
        listaDescripcionGuardado = ",".join(listaDescripcion)
        listaDescripcionGuardado = listaDescripcionGuardado
        fecha = str(datetime.now())
        textoGuardar = personajeGuardado+","+nombre+","+fecha
        texto = lectura("guardado")
        partida = int(partida)
        if partida != len(texto)-1:
            texto[len(texto)-1]= texto[len(texto)-1] 

        texto.insert(partida,textoGuardar)
        texto.pop(partida+1)
        texto = "".join(texto)
        escribir("guardado",texto)

    #Al finalizar aumenta el número de batalla jugada 
    batalla +=1
    return True

print("1)Iniciar Partida\t2)Continuar partida")
partida = input("(1|2): ")
#Se realiza un ciclo para comprobar que los datos ingresados por el usuario sean correctos
while partida != "1" and partida !="2":
    print("Dato erróneo")
    partida = input("(1|2): ")

if partida == "2":
    partidaCargada = True
    partidasGuardadas = lectura("guardado")
    i = 1
    #Se transforma la lista en una lista de lista, que contiene los valores de cada partidas
    while i < len(partidasGuardadas):
        partidasGuardadas[i] = partidasGuardadas[i].split(",")
        i+=1
    i = 1
    #Los valores que pueden ser transformados de string a enteros, se tranforman para facilitar el cálculo
    #posteriormente 
    while i < len(partidasGuardadas):
        j = 2
        while j < len(partidasGuardadas[i])-2:
            partidasGuardadas[i][j] = int(partidasGuardadas[i][j])
            j+=1
        i+=1

    i = 1
    print()
    print("Las partidas guadadas son:")
    #Se imprimen los nombres de las partidas, junto con su respectivo nivel y fecha
    while i < len(partidasGuardadas):
        print(str(i)+")",partidasGuardadas[i][len(partidasGuardadas[i])-2])
        print("Nivel:",partidasGuardadas[i][15])
        print("Fecha:",partidasGuardadas[i][len(partidasGuardadas[i])-1])
        i +=1

    print()
    partida = int(input("Ingrese el número de la partida que quiere continuar: "))
    personaje = partidasGuardadas[partida]
    nombre = personaje[len(personaje)-2]
    print("Se coontinuará la partida de",nombre)
    print()
    #Se elimina el nombre y la fecha de partida, el nombre será agregado posteriormente al guardar junto con la feha
    personaje.pop()
    personaje.pop()
    datosPersonajeOriginal = personaje[:]
    datosPersonajeAumentados = personaje[:]
    listaDescripcion = partidasGuardadas[0].split(",")

else:
    partidaCargada = False
    nombre = input("Ingrese su nombre: ")
    print()
    nombreArchivo = "jugador"
    #Se llama la función lectura y se almacena la información en una variable
    listaClasesJugador = lectura(nombreArchivo)
    listaClasesJugador = "".join(listaClasesJugador)
    #Se separa por saltos de linea en diferentes listas
    listaClasesJugador = listaClasesJugador.split("\n")
    listaDescripcion = listaClasesJugador[0].split(",")
    i = 1
    #Se convierte cada una de las listas de strings a sub listas de strings
    while i < len(listaClasesJugador):
        #Se separan a traves de comas los valores, para posteriormente ser recorridos
        listaClasesJugador[i] = listaClasesJugador[i].split(",")#
        i += 1 

    i = 1
    #Se realiza un ciclo con el fin de imprimir los datos en forma de tabla
    while i < len(listaClasesJugador):
        #Se imprime el nombre de la clase
        print(str(i)+")" + listaClasesJugador[i][0] + ':')
        print()
        j = 2
        q = 0
        #Se imprime la tabla de cada personaje 
        while j < len(listaClasesJugador[i]):
            print(listaDescripcion[q].ljust(16," "),"|\t",listaClasesJugador[i][j],"\t")
            j+=1
            q+=1
            sleep(1/5)

        sleep(2)
        print()
        i +=1

    #El número que ingrese el usuario corresponde a un personaje
    listaPersonajesSeleccionables = list(range(1,len(listaClasesJugador)))
    personaje = input("Número del personaje: ")
    #Se convierte el dato a un int para facilitar el trabajo
    if personaje.isdigit() == True:
        personaje = int(personaje)

    while not(personaje in listaPersonajesSeleccionables):
        print("Dato erróneo")
        personaje = input("Ingrese nuevamente el número del personaje: ")
        if personaje.isdigit() == True:
            personaje = int(personaje)

    i = 1
    #Se realiza un ciclo para asignar el personaje con el número ingresado por el usuario
    while i < len(listaClasesJugador):
        #En el momento que i sea igual al número ingresado por el usuario se asigna el personaje
        if personaje == i:
            print("Personaje elegido: ",listaClasesJugador[personaje][0])
            print()
            #Se asigna como personaje una lista almacenada en una lista que contiene todo los personajes
            personaje = listaClasesJugador[personaje][:]
            i = len(listaClasesJugador)

        i += 1
    i = 2

    #Se convierte cada valor a entero para poder ser trabajado
    while i < len(personaje):
        personaje[i] = int(personaje[i])
        i+=1

    personaje.append(1)
    personaje.append(1)
    listaDescripcion.append("Experiencia")
    listaDescripcion.append("Nivel")
    personaje.append(experienciaPorNivel(personaje[1],100))
    #Se guardan los datos del personaje 
    datosPersonajeOriginal = personaje[:]
    datosPersonajeAumentados = personaje[:]

nombreArchivo = "enemigos"
#Se llama la función lectura y se almacena la información en una variable
listaClasesEnemigos = lectura(nombreArchivo)
listaClasesEnemigos = "".join(listaClasesEnemigos)
#Se separa por saltos de linea en diferentes listas
listaClasesEnemigos = listaClasesEnemigos.split("\n")
i = 1
#Se convierte cada una de las listas de strings a sub listas de strings
while i < len(listaClasesEnemigos):
    #Se separan a traves de comas los valores, para posteriormente ser recorridos
    listaClasesEnemigos[i] = listaClasesEnemigos[i].split(",")
    i += 1 

i = 1
#Se convierte cada valor a entero para poder ser trabajado
while i < len(listaClasesEnemigos):
    j = 2
    while j < len(listaClasesEnemigos[i]):
        listaClasesEnemigos[i][j] = int(listaClasesEnemigos[i][j])
        j+=1
    i+=1

i = 1
while i < len(listaClasesEnemigos):
    listaClasesEnemigos[i].append(1)
    listaClasesEnemigos[i].append(1)
    listaClasesEnemigos[i].append(experienciaPorNivel(personaje[1],100))
    i+=1
    
nombreArchivo = "jefes"
#Se llama la función lectura y se almacena la información en una variable
listaClasesJefes = lectura(nombreArchivo)
listaClasesJefes = "".join(listaClasesJefes)
#Se separa por saltos de linea en diferentes listas
listaClasesJefes = listaClasesJefes.split("\n")
i = 1
#Se convierte cada una de las listas de strings a sub listas de strings
while i < len(listaClasesJefes):
    #Se separan a traves de comas los valores, para posteriormente ser recorridos
    listaClasesJefes[i] = listaClasesJefes[i].split(",")
    i += 1 

i = 1
#Se convierte cada valor a entero para poder ser trabajado
while i < len(listaClasesJefes):
    j = 2
    while j < len(listaClasesJefes[i])-1:
        listaClasesJefes[i][j] = int(listaClasesJefes[i][j])
        j+=1
        
    i+=1

i = 1
while i < len(listaClasesJefes):
    listaClasesJefes[i].append(1)
    listaClasesJefes[i].append(1)
    listaClasesJefes[i].append(experienciaPorNivel(listaClasesJefes[i][1],100))
    i+=1

#Se le consulta al usuario cuantas batallas desea enfrentar
if personaje[15] == 100:
    print("Has completado el juego, muchisimas gracias por jugar")
numeroBatallas = input("Número de batallas a pelear: ")

#En el caso que el usuario ingrese de manera incorrecta se le pedirá nuevamente el valor
while not numeroBatallas.isnumeric():
    numeroBatallas = input("Ingresa la cantidad de batallas (Solo con digitos): ")

numeroBatallas = int(numeroBatallas)
#Indica el número de batalla que se esta realizando
batalla = 1
experiencia = 0
siguienteNivel = 2

respuesta = ""
#Mientras el número elegido por usuario sea mayor al número de batallas realizadas
#Se ejecutara el ciclo
while batalla <= numeroBatallas and personaje[15]<=100:
    #Se crea la variable en donde se guardarán los los críticos del personaje
    criticosHechos = 0
    #Se crea una variable en donde se guardarán los fallos hechos del personaje
    fallosHechos = 0
    if batalla == 1:
        print()

    print("BATALLA " + str(batalla))
    if batalla == 1:
        print()

    sleep(1/5)
    if batalla > 1:
        print("---------------")

    #Después de la primera batalla se imprime la información del personaje con 
    #los niveles y experiencia correspondiente
    if batalla > 1:
        print("\t\t     ",personaje[0]) 
        print()
        i = 2
        j = 0
        #Se realiza un ciclo con el fin de imprimir los datos en forma de tabla
        while i <= 15:
            print(listaDescripcion[j].ljust(17," "),"|\t",personaje[i])
            sleep(1/10)
            i +=1
            j +=1
        print()
        
    #Se le consulta al usuario si desea saltarse la batalla y sólo visualizar el resultado
    skipBattle = input("¿Quieres saltarte la batalla? (Si/No): ")
    #Se convierte a minúscula la respuesta para realizar posteriormen comprobación de la entrada
    skipBattle = skipBattle.lower() 
    #En el caso que usuario ingrese un dato erróneo sele pedirá nuevamente que ingrese el dato
    while skipBattle !="si" and skipBattle != "no":
        skipBattle = input("¿Quieres skipearte la batalla? (Marque 'Si' o 'No' de acorde al caso): ")
        skipBattle = skipBattle.lower()
        print()
        print("Batalla " + str(batalla))
        print()
        
    #Si el usuario decide omitir la batalla se ejecutará la función omitiendo los prints de la batalla
    if skipBattle == "si":
        #Se llama a la función que contiene la información de la batalla más los prints
        experiencia += skipBatalla(personaje,datosPersonajeOriginal,criticosHechos,fallosHechos,experiencia,siguienteNivel,batalla,partidaCargada,partida)
        partidaCargada = True
        #Se aumenta el valor de batallas jugadas por el jugador
        batalla = batalla + 1

    #Por el contrario se ejecutra la batalla con normalidad
    elif skipBattle == "no" :
        #En el caso que la número de batalla que esta jugando el usuario sea multiplo de 10, se enfrentará a un jefe
        #Se ve si la variable batalla corresponde al enfrentamiento contra el jefe
        sumaExperienciaEnemigos = 0
        if batalla%10 == 0:
            print("¡¡¡SE ACERCA EL JEFE!!!")
            #En el caso de que le toque enfrentarse a un jefe la cantidad de enemigos es 1
            cantidadEnemigos = 1
            listaEnemigos = []
            #Se llama a la función que selecciona el enemigo al azar
            enemigo1  = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
            #Se almacena en la lista destinada a guardar los enemigos
            listaEnemigos = [enemigo1]
            #Se respaldan los datos iniciales del enemigo
            datosEnemigoOriginal1 = enemigo1[:]
            datosEnemigoOriginal1Aumentado = enemigo1[:]
            #Se determina la variable enemigo como enemigo1 ya que no existen más enemigos
            enemigo = enemigo1[:]
            listaDatosEnemigosOriginal = [datosEnemigoOriginal1]
            enemigo1[16] = personaje[15]
            i = 1
            nivelActual = 1
            #Se realiza un ciclo para aumentar el nivel del enemigo
            while i <=  enemigo1[16]:
                nivelActual = experienciaPorNivel(enemigo1[1],i)
                if nivelActual < experienciaPorNivel(enemigo1[1],enemigo1[16]):
                    aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                i+=1
            
            sumaNivelesEnemigos = enemigo[16]
            sumaExperienciaEnemigos += round(experienciaPorNivel(enemigo1[1],enemigo1[16]))
            sleep(1/2)
            print("Te enfrentaras a",enemigo1[14])
            i = 2
            j = 0
            while j < len(listaDescripcion):
                #Se imprime el nivel correspondiente del enemigo
                print(listaDescripcion[j].ljust(17," "),"|\t",enemigo1[i],"\t|")
                sleep(1/5)
                i +=1 
                j+=1
            sleep(3)
        
        #En el caso que no sea una batalla multiplo de 10 se enfrentará a un enemigo normal  
        else:
            #Se determina al azar cuantos enemigos se tiene que enfrentar al usuario
            cantidadEnemigos = randint(1,3)
            #En el caso que la cantidad de enemigos sea 1, imprime en singular
            if cantidadEnemigos == 1: 
                print("Te enfrentaras a",cantidadEnemigos,"enemigo: ")

            #En el caso que la cantidad de enemigos sea mayor a 1, imprime en plural
            else:
                print("Te enfrentaras a",cantidadEnemigos,"enemigos: ")
                
            #Se crea una lista en donde se guardaran los datos de los enemigos
            listaEnemigos = []
            #En el caso que sea un enemigo a enfrentar se crea solo una variable de enemigo
            if cantidadEnemigos == 1:
                #Se llama a la función que selecciona el enemigo al azar
                enemigo1  = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                #Se almacena en la lista destinada a guardar los enemigos
                listaEnemigos = [enemigo1]
                #Se respaldan los datos iniciales del enemigo
                datosEnemigoOriginal1 = enemigo1[:]
                datosEnemigoOriginal1Aumentado = enemigo1[:] 
                #Se determina la variable enemigo como enemigo1 ya que no existen más enemigos
                enemigo = enemigo1[:]
                listaDatosEnemigosOriginal = [datosEnemigoOriginal1]
                if personaje[15] == 1:
                    enemigo1[15] = 1

                else:
                    enemigo1[15] = personaje[15]-1

                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo
                while i <=  enemigo1[15]:
                    nivelActual = experienciaPorNivel(enemigo1[1],i)
                    if nivelActual < experienciaPorNivel(personaje[1],enemigo1[15]):
                        aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                        aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    i+=1
                    
                sumaNivelesEnemigos = enemigo[15]
                sumaExperienciaEnemigos += round(experienciaPorNivel(enemigo1[1],enemigo1[15]))
                #Se imprimen los datos del enemigo en forma de tabla hasta el valor 13
                sleep(1/2)
                print()
                print("Tu primer enemigo es: " + enemigo[0])
                print()
                i = 2
                j = 0
                while j < len(listaDescripcion):
                    #Se imprime el nivel correspondiente del enemigo
                    if j != 14:
                        print(listaDescripcion[j].ljust(17," "),"|\t",enemigo1[i],"\t|")
                        sleep(1/5)
                    i +=1 
                    j+=1
                sleep(3)
                    
            #En el caso que sean dos enemigos a enfrentar
            elif cantidadEnemigos == 2:
                #Se elige un número entre el 0 y el 1 para posteriormente utilizar este número 
                #como indice para determinar un enemigo con el se comparen las velocidades
                enemigo = randint(0,1)
                #Se elige un enemigo entre los tres enemigos disponibles
                enemigo1  = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                #Se escoge el segundo enemigo
                enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                #En el caso que ambos enemigos sean los mismos se escoge otro de los 2 restantes
                while enemigo1 == enemigo2: # Para previnir que se dupliquen enemigos
                    enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                enemigo1[15] = randint(1,personaje[15])
                enemigo2[15] = randint(1,personaje[15])
                #Si el nivel del personaje es 1, el nivel de los enemigos es 1
                if personaje[15] == 1:
                    enemigo1[15] = 1
                    enemigo2[15] = 1

                #Si el nivel del personaje es 2, el nivel de los enemigos es 1
                elif personaje[15] == 2:
                    enemigo1[15] = 1
                    enemigo2[15] = 1
                
                else:    
                    while not(enemigo1[15] + enemigo2[15] < personaje[15]):
                        enemigo1[15] = randint(1,personaje[15]-1)
                        enemigo2[15] = randint(1,personaje[15]-1)
                                
                #Se guardan los datos iniciales de los enemigos
                datosEnemigoOriginal1 = enemigo1[:]
                datosEnemigoOriginal2 = enemigo2[:]
                datosEnemigoOriginal1Aumentado = enemigo1[:]
                datosEnemigoOriginal2Aumentado = enemigo2[:]
                #Se Calcula la experiencia del enemigo 1
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[1],enemigo1[15])
                #Se calcula la experiencia del enemigo 2 y se suma a la del enemigo 1, dando el total
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[1],enemigo2[15])
                #Se calcula la suma de los niveles de los enemigos
                sumaNivelesEnemigos = enemigo1[15] + enemigo2[15]
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 1
                while i <=  enemigo1[15]:
                    nivelActual = experienciaPorNivel(enemigo1[1],i)
                    if nivelActual < experienciaPorNivel(enemigo1[1],enemigo1[15]):
                        aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                        aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    i += 1
                
                #Se realiza un ciclo para aumentar el nivel del enemigo 2
                i = 1
                nivelActual = 1
                while i <=  enemigo2[15]:
                    nivelActual = experienciaPorNivel(enemigo2[1],i)
                    if nivelActual < experienciaPorNivel(enemigo2[1],enemigo2[15]):
                        aumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                        aumentoPorNivel(datosEnemigoOriginal2Aumentado,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                    i+= 1

                #Se colocan ambos datos de los enemigos en una lista
                listaEnemigos = [enemigo1,enemigo2]
                enemigo = listaEnemigos[enemigo][:]
                #Se crea una lista en donde se guardan las listas que contienen los datos iniciales de los enemigps
                listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2]
                #Se coloca un sleep para que usuario alcance a leer la información
                #Se imprime la tabla de descripción del enemigo
                sleep(1)
                print()
                print("Tu primer enemigo es " + enemigo1[0])
                print()
                i = 2
                j = 0
                while j < len(listaDescripcion):
                    if j != 14:
                    #Se imprime el nivel correspondiente del enemigo
                        print(listaDescripcion[j].ljust(17," "),"|\t",enemigo1[i],"\t|")
                        sleep(1/5)
                    i +=1 
                    j+=1
                sleep(3)
                #Se coloca un sleep para que usuario alcance a leer la información
                #Una vez ya escogido ambos enemigos distintos se imprime los datos del enemigo restante
                print()
                print("Tu segundo enemigo es " + enemigo2[0])
                print()
                i = 2
                j= 0
                while j < len(listaDescripcion):
                    if j != 14:
                    #Se imprime el nivel correspondiente del enemigo
                        print(listaDescripcion[j].ljust(17," "),"|\t",enemigo2[i],"\t|")
                        sleep(1/5)
                    i +=1 
                    j+=1
                
            #En el caso que sean tres enemigos a enfrentar
            elif cantidadEnemigos == 3:
                #Se elige un número entre el 0 y el 2 para posteriormente utilizar este número 
                #como indice para determinar un enemigo con el se comparen las velocidades
                enemigo = randint(0,2)
                #Se elige un enemigo entre los tres enemigos disponibles
                enemigo1 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)

                #Se escongen dos enemigos al azar
                enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                enemigo3 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                #En el caso que se repitan los enemigos a enfrentar se escogen otros hasta que sean distintos
                while enemigo1 == enemigo2 or enemigo1 == enemigo3 or enemigo2 == enemigo3 :
                    enemigo2 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)
                    enemigo3 = seleccionEnemigo(batalla,listaClasesEnemigos,listaClasesJefes)

                enemigo1[15] = randint(1,personaje[15])
                enemigo2[15] = randint(1,personaje[15])
                enemigo3[15] = randint(1,personaje[15])
                #En el caso que la vida del personaje sea 1, las vidas de los enemigos quedán definidas como 1
                if personaje[15] == 1:
                    enemigo1[15] = 1
                    enemigo2[15] = 1
                    enemigo3[15] = 1
                
                #En el caso que la vida del personaje sea 2, la vida de los enemigos quedán definidas como 1
                elif personaje[15] == 2:
                    enemigo1[15] = 1
                    enemigo2[15] = 1
                    enemigo3[15] = 1

                #En el caso que la vida del personaje sea 3, la vida de los enemigos quedán definidas como 1
                elif personaje[15] == 3:
                    enemigo1[15] = 1
                    enemigo2[15] = 1
                    enemigo3[15] = 1
                    
                #Desde el nivel 4 en adelante 
                else:
                    while not(enemigo1[15] + enemigo2[15] + enemigo3[15] < personaje[15]):
                        enemigo1[15] = randint(1,personaje[15]-1)
                        enemigo2[15] = randint(1,personaje[15]-1)
                        enemigo3[15] = randint(1,personaje[15]-1)

                #Se respaldan los datos de los enemigos
                datosEnemigoOriginal1 = enemigo1[:]
                datosEnemigoOriginal2 = enemigo2[:]
                datosEnemigoOriginal3 = enemigo3[:]
                datosEnemigoOriginal1Aumentado = enemigo1[:]
                datosEnemigoOriginal2Aumentado = enemigo2[:]
                datosEnemigoOriginal3Aumentado = enemigo3[:]
                #Se calcula la experiencia del enemigo1 
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo1[1],enemigo1[15])
                #Se calcula la experiencia del enemigo2, sumandolo al del enemigo 1
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo2[1],enemigo2[15])
                #Se calcula la experiencia del enemigo 3, sumandola al del enemigo 1 y 2, dando el total
                sumaExperienciaEnemigos += experienciaPorNivel(enemigo3[1],enemigo3[15])
                #Se suman los niveles de los enemigos
                sumaNivelesEnemigos = enemigo1[15] + enemigo2[15] + enemigo3[15]
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 1
                while i <=  enemigo1[15]:
                    nivelActual = experienciaPorNivel(enemigo1[1],i)
                    if nivelActual < experienciaPorNivel(enemigo1[1],enemigo1[15]):
                        aumentoPorNivel(enemigo1,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                        aumentoPorNivel(datosEnemigoOriginal1Aumentado,datosEnemigoOriginal1,datosEnemigoOriginal1Aumentado,batalla)
                    i += 1

                #Se realiza un ciclo para aumentar el nivel del enemigo 2
                i = 1
                nivelActual = 1
                while i <=  enemigo2[15]:
                    nivelActual = experienciaPorNivel(enemigo2[1],i)
                    if nivelActual < experienciaPorNivel(enemigo2[1],enemigo2[15]):
                        aumentoPorNivel(enemigo2,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                        aumentoPorNivel(datosEnemigoOriginal2Aumentado,datosEnemigoOriginal2,datosEnemigoOriginal2Aumentado,batalla)
                    i+= 1
                    
                i = 1
                nivelActual = 1
                #Se realiza un ciclo para aumentar el nivel del enemigo 3
                while i <=  enemigo3[15]:
                    nivelActual = experienciaPorNivel(enemigo3[1],i)
                    if nivelActual < experienciaPorNivel(enemigo3[1],enemigo3[15]):
                        aumentoPorNivel(enemigo3,datosEnemigoOriginal3,datosEnemigoOriginal3Aumentado,batalla)
                        aumentoPorNivel(datosEnemigoOriginal3Aumentado,datosEnemigoOriginal3,datosEnemigoOriginal3Aumentado,batalla)

                    i+= 1

                #Se coloca un sleep para que usuario alcance a leer la información
                sleep(3)
                #Se agregan los datos de los enemigos a una lista 
                listaEnemigos = [enemigo1,enemigo2,enemigo3]
                enemigo = listaEnemigos[enemigo][:]
                #Se crea una lista en donde se guardan los datos iniciales de todos los enemigos
                listaDatosEnemigosOriginal = [datosEnemigoOriginal1,datosEnemigoOriginal2,datosEnemigoOriginal3]
                
                #Se imprimen los datos del primer enemigo a enfrentar
                sleep(3)
                print()
                print("Tu primer enemigo es " + enemigo1[0])
                print()
                i = 2
                j = 0
                while j < len(listaDescripcion):
                    if j != 14:
                    #Se imprime el nivel correspondiente del enemigo
                        print(listaDescripcion[j].ljust(17," "),"|\t",enemigo1[i],"\t|")
                        sleep(1/5)
                    i +=1 
                    j+=1
                sleep(3)
                #Se imprimen los datos del segundo enemigo
                sleep(3)
                print()
                print("Tu segundo enemigo es " + enemigo2[0])
                print()
                i = 2
                j = 0
                while j < len(listaDescripcion)-2:
                    if j != 14:
                    #Se imprime el nivel correspondiente del enemigo
                        print(listaDescripcion[j].ljust(17," "),"|\t",enemigo2[i],"\t|")
                        sleep(1/5)
                    i +=1 
                    j+=1
                sleep(3)
                #Se imprimen los datos del tercer enemigo
                #Se coloca un sleep para que usuario alcance a leer la información
                sleep(1)
                print()
                print("Tu tercer enemigo es " + enemigo3[0])
                print()   
                
                i = 2
                j = 0
                while j < len(listaDescripcion)-2:
                    if j != 14:
                    #Se imprime el nivel correspondiente del enemigo
                        print(listaDescripcion[j].ljust(17," "),"|\t",enemigo3[i],"\t|")
                        sleep(1/5)
                    i +=1 
                    j+=1
                sleep(3)

        #Para determinar a quien le toca primero se comparan las velocidades del personaje y enemigo1
        #Para determinar cuando empieza y acaba el turno del personaje se crea una variable que vuelve False cuando termina el turno  
        if personaje[3] >= enemigo[3]:
            turno = True
            turnoEnemigo = False
            
        elif enemigo[3] > personaje[3]:
            turno= False
            turnoEnemigo= True
            
        print()
        print("BATALLA "+str(batalla))
        print()
        #Mientras la vida de ambos contrincantes sea positiva tendrá a lugar la batalla  
        #Se decide si pelea contra el jefe dependiendo de la cantidad de batallas
        while cantidadEnemigos > 0 and personaje[2]>0:
            #Se elige de una manera pseudo-aleatoria el enemigo que atacará 
            enemigo = choice(listaEnemigos)
            #Se determina en que posición se encuentran los datos del enemigo de la ronda
            posicion = listaEnemigos.index(enemigo)
            #Se determina los datos originales del enemigo en base a la lista que contenia los datos
            #originales de los enemigos y la posición
            datosEnemigoOriginal = listaDatosEnemigosOriginal[posicion]
            #Mientras el turno del personaje sea True, se ejecutara el ciclo
            while turno == True:
                if batalla % 10 == 0:
                    print("Atacaras a " + enemigo[14])

                else :
                    print("Atacarás a " + enemigo[0])

                sleep(1/2)
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
                    sleep(1/personaje[3])
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
                #En el caso que el personaje sea Fighter se elige automaticamente Ataque ya que este no puede
                #realizar hechizos
                if personaje[0] == "Fighter":
                    accion = 1
                #En caso que sea otro personaje se escoge el azar
                else:
                    accion = randint(1,2)
                    
                #Ataque
                #Si la acción es 1 se realiza el ataque         
                if accion == 1:
                    print()
                    print("Si el número de ataque es mayor a la defensa de su enemigo podrá atacar")
                    print("La defensa del enemigo es: ",enemigo[5])
                    #Se escoge un número al azar entre 1 y 20
                    numeroAleatorio = randint(1,20)
                    #En base al número aleatorio se suma con el ataque del personaje para determinar
                    #el número de ataque
                    numeroAtaque = numeroAleatorio + personaje[4]
                    print("Número de ataque: ",numeroAtaque)
                    #Si el número de ataque es mayor a la defensa del enemigo puede atacar
                    if numeroAtaque >= enemigo[5] :
                        #Fallo
                        #Si el número al azar es 1 ocurre un excepción el cual beneficia al enemigo
                        if numeroAleatorio == 1:
                            print("Te quedan",personaje[2],"de vida")
                            #Se determina el número de fallo entre 1 y 3
                            numeroFallo = randint(1,3)
                            #Se le resta el número de fallo al personaje
                            personaje[2] = personaje[2] - numeroFallo
                            print("Eres tan torpe que te has herido a ti mismo quitandote",numeroFallo,"puntos de vida")
                            print("Ahora te quedan",personaje[2],"puntos de vida")
                            print()
                            
                        #Crítico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        elif numeroAleatorio == 20:
                            print("Has realizado un ataque con exito")
                            print()
                            #El daño del personaje aumenta 2* por un valor dado por un número al azar entre el daño
                            #mínimo y máximo del personaje
                            daño = 2 * (randint(personaje[10],personaje[11]))
                            print("ATAQUE CRÍTICO")
                            print()
                            print("La vida del enemigo es:", enemigo[2])
                            print("Has realizado",daño,"de daño")
                            #Se le resta el daño calculado al personaje
                            enemigo[2] = enemigo[2] - daño
                            print("La nueva vida del enemigo es:", enemigo[2])
                            print()
                            criticosHechos += 1 
                            
                        #Para cualquier otro caso el procedimiento es el normal  
                        else:
                            print()
                            print("Has realizado un ataque con éxito")
                            print()
                            #Se determina el daño que realiza entre el daño mínimo y máximo del personaje
                            daño = randint(personaje[10],personaje[11])
                            print("La vida del enemigo es:",enemigo[2])
                            #Se le resta la vida al enemigo
                            enemigo[2] = enemigo[2] - daño
                            print("Has realizado "+ str(daño) +" daño")
                            print("La nueva vida del enemigo es:",enemigo[2])
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
                #Si la accion es 2 se realizara un hechizo
                elif accion == 2:
                    print("Si el número al azar es mayor a su umbral podrá realizar un hechizo")
                    print("Su umbral es:",personaje[6])
                    #Se determina el umbral del personaje eligiendo un número al azar entre 1 y 20
                    umbral = randint(1,20)
                    print("Numero al azar:",umbral)
                    #Si el número es mayor al umbral puede realizar un Hechizo
                    if umbral > personaje[6]:
                        print()
                        print("Puede realizar hechizo")
                        print()
                        valor = randint(1,100)
                        #Hechizo de Ataque
                        if valor < personaje[7]:
                            print("Hechizo de ataque")
                            #Crítico
                            #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                            if valor == 20:
                                print("CRÍTICO")
                                #Se determina el daño que realizará el personaje a través de un número al azar entre el
                                #daño de hechizo máximo y mímino del personaje, este tiene que ser entero
                                daño = int(randint(personaje[12],personaje[13])*1.5)
                                print("La vida del enemigo es:",enemigo[2])
                                print("Has realizado",daño,"de daño")
                                #Se le resta la el daño al enemigo
                                enemigo[2] = enemigo[2]-daño 
                                print("La nueva vida del enemigo es: ", enemigo[2])
                                print()
                                criticosHechos += 1 
                                
                            #Fallo
                            #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                            elif valor == 1:
                                print("FALLO")
                                print("Te quedan",personaje[2],"de vida")
                                #Se le resta la mitad de la vida al personaje, tiene que ser entero
                                personaje[2] = int(personaje[2]/2)
                                print("Su vida se a reducido a la mitad")
                                print("Ahora te quedan",personaje[2],"puntos de vida")
                                print()
                                
                            #Por elcontrario actua con normalidad
                            else:
                                #Se determina el daño que realiza entre el daño de hechizo máximo y mínimo
                                daño = randint(personaje[12],personaje[13])
                                print("La vida del enemigo es:",enemigo[2])
                                print("Has realizado",daño,"de daño")
                                #Se le resta el daño provocado por el personaje al enemigo
                                enemigo[2] = enemigo[2]-daño
                                print("La nueva vida del enemigo es: ", enemigo[2])
                                print()
                                
                        #Hechizo de Defensa
                        elif valor < personaje[8]:
                            print("HECHIZO DE DEFENSA")
                            #Crítico
                            #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                            if valor ==20:
                                print("CRÍTICO")
                                print()
                                print("La defensa actual es:",personaje[5])
                                #Aumenta la defensa en 2 
                                personaje[5] += 2
                                print("A aumentado su defensa en 2")
                                print("Ahora su defensa es:", personaje[5])
                                print()
                                criticosHechos += 1
                                
                            #Fallo
                            #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                            elif valor ==1:
                                print("FALLO")
                                print()
                                print("La defensa del enemigo es:",enemigo[5])
                                #Aumenta en 1 el valor de la defensa del enemigo
                                enemigo[5] += 1
                                print("A aumentado su defensa del enemigo")
                                print("Ahora la defensa del enemigo es:", enemigo[5])
                                print()
                                
                            #Por el contario se sigue con normalidad
                            else:
                                print("La defensa actual es:",personaje[5])
                                #Aumenta en la defensa del personaje en 1
                                personaje[5] += 1
                                print("A aumentado su defensa")
                                print("Ahora su defensa es:", personaje[5])
                                print()
                                
                        #Hechizo de Curación
                        elif valor < personaje[9]:
                            print("Hechizo de curacion")
                            print()
                            #Crítico
                            #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                            if valor == 20:
                                print("CRÍTICO")
                                #En el caso que el usuario tenga la vida llena no se curará
                                if personaje[2] == datosPersonajeOriginal[2]:
                                    print("Usted no se puede curar ya que tiene la vida al máximo")
                                    print()
                                    criticosHechos += 1
                                    
                                #Si no tiene la vida al máximo significa que puede curarse
                                else:
                                    print("La vida actual es:",personaje[2])
                                    #Aumenta en 4 el nivel de vida del personaje
                                    personaje[2] += 4
                                    print("Usted se a curado 4 de vida")
                                    print()
                                    #Si los puntos de curación superan los límites originales, quedará con el puntaje original
                                    #ya que la vida no puede superar los datos originales
                                    if personaje[2] > datosPersonajeOriginal[2]:
                                        personaje[2] = datosPersonajeOriginal[2]
                                        print("Su nueva vida es: ", personaje[2])
                                        print()
                                        criticosHechos += 1 
                                    #En el caso que no superen los datos orginales del personaje quedaran los datos con el aumento
                                    else:
                                        print("Su nueva vida es: ",personaje[2])
                                        criticosHechos += 1 
                                    print()
                                    
                            #Fallo
                            #Si el número al azar es 1 ocurre una excepción que beneficia al enemigo
                            elif valor == 1:
                                print("FALLO")
                                print()
                                print("La vida actual del enemigo es;",enemigo[2])
                                print("Has fallado y has curado al enemigo")
                                #En el caso que el enemigo tenga la vida llena, no se curará 
                                if enemigo[2] == datosEnemigoOriginal[0]:
                                    print("El enemigo no se pudo curar, porque tiene la vida llena")
                                    
                                else:    
                                    #Se le aumenta 4 a la vida del enemigo
                                    enemigo [0]+= 4 
                                    print("El enemigo se a curado 4 de vida")
                                    #Si el puntaje de curado supera el límite de vida, quedará el puntaje original ya que no se pueden
                                    #superar esos valores
                                    if enemigo[2] > datosEnemigoOriginal[0]:
                                        enemigo[2] = datosEnemigoOriginal
                                        print("La nueva vida del enemigo es: ", enemigo[2])
                                        
                                    #Por el contrario se deja con la vida curada
                                    else:
                                        print("La nueva vida del enemigo es: ",personaje[2])
                                        
                                print()
                                
                            #En cualquier otro caso se seguirá con un Hechizo de Curación normal
                            else:
                                print("La vida actual es:",personaje[2])
                                #Si la vida se encuntra completa, no se curara
                                if personaje[2] == datosPersonajeOriginal[2]:
                                    print("Usted no se puede curar ya que tiene la vida al máximo")
                                    print()
                                    
                                else:
                                    #Se elige un número al azar entre 1 y 8 con el fin de curar al personaje
                                    cura = randint(1,8)
                                    print("Numero al azar: ",cura)
                                    print("Usted se va curar ",cura,"de vida")
                                    personaje[2] = personaje[2] + cura
                                    #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                                    if personaje[2] > datosPersonajeOriginal[2]:
                                        personaje[2] = datosPersonajeOriginal[2]
                                        print("Su nueva vida es: ", personaje[2])
                                        
                                    #Por el contrario quedará con el valor aumentado
                                    else:
                                        print("Su nueva vida es: ",personaje[2])
                                        
                                    print()
                            
                        #Ataque simple
                        #En el caso que no se puede realizar HA, HD y HC, el personaje ataca normalmente
                        else:
                            print("Ataque simple")
                            print()
                            #Se determina el daño que va a realizar el personaje con un número al azar entre el daño
                            #máximo y mínimo
                            daño = randint(personaje[10],personaje[11])
                            print("La vida del enemigo es:",enemigo[2])
                            #Se le resta el daño a la vida del enemigo
                            enemigo[2] = enemigo[2] - daño
                            print("Has realizado "+ str(daño) +" puntos de daño")
                            print("Al enemigo le quedan "+str(enemigo[2])+ " puntos de vida")
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
            sleep(3)
            #Se activa el turno del enemigo
            turnoEnemigo = True
            #Se comprueba que el enemigo se encuentre vivo antes de que empiece su turno
            while turnoEnemigo == True :
                #Se llama la función acción enemigo que realiza los moviemientos del enemigo
                turnoEnemigo = accionEnemigo(enemigo,personaje,turnoEnemigo, datosEnemigoOriginal)
                
            #Se coloca un sleep para que usuario alcance a leer la información
            sleep(3)
            #Se activa el turno del personaje
            turno =  True
            #En el caso que muera uno de los enemigos muera disminuye la cantidad de enemigos
            #totales
            if enemigo[2] <= 0 :
                print("Murió "+listaEnemigos[posicion][0])
                print()
                #Se resta en uno la cantidad de enemigos 
                cantidadEnemigos -=1
                #Se elimina de la lista en donde se encuentran los enemigos al que murió
                listaEnemigos.pop(posicion)

        #Salida de datos para el usario
        print("Computo vidas")
        print("Enemigo:",enemigo[2])
        print("Personaje:",personaje[2])
        print()
        #En el caso que la vida del enemigo sea menor o igual a 0 significa que el enemigo murió
        if enemigo[2] <= 0:
            nivelAnterior = personaje[15]#       
            print("No quedan más oponentes")
            print("GANASTE")
            print()            
            #Cálculo factorCritic
            #Al terminar la batalla y terminar victoriozo el jugador recibe una bonificación por criticos y 
            #fallos hechos
            #En el caso que el caclulo sea mayor a 0 se asigna un valor de 1.5
            if (criticosHechos - fallosHechos) > 0:
                factorCritic = 1.5
                
            #En el caso que el caclulo sea menor a 0 se asigna un valor de 0.75
            elif (criticosHechos - fallosHechos) < 0:
                factorCritic = 0.75
                
            #En el caso que el caclulo sea igual a 0 se asigna un valor de 1
            elif (criticosHechos - fallosHechos) == 0:
                factorCritic = 1
            
            #Cálculo factorDaño
            #Bonificación por la salud restante de personaje, se divide la vida restante con la vida total
            factorDaño = int(1 + personaje[2]/ datosPersonajeAumentados[2])
            #Se suma  a la experencia ya calculada la acumulada en esta batalla
            experiencia += calculoExperiencia(sumaExperienciaEnemigos,sumaNivelesEnemigos,personaje[15],factorCritic,factorDaño)
            #Se calcula la experiencia para alcanzar el siguiente nivel   
            experienciaParaNivel = experienciaPorNivel(personaje[1],siguienteNivel)
            #Se redondea los resultados para evitar excesivos decimales
            experienciaParaNivel = round(experienciaParaNivel)
            personaje[14] = experiencia
            #Se realiza un ciclo para aumentar nivel
            while experienciaParaNivel <= experiencia: #Cuando se sube de nivel
                personaje[15] += 1
                #Se aumentan las estadisticas del personaje
                aumentoPorNivel(personaje,datosPersonajeOriginal,datosPersonajeAumentados,batalla)
                #Se aumentan las estadisticas base
                aumentoPorNivel(datosPersonajeAumentados,datosPersonajeOriginal,datosPersonajeAumentados,batalla)
                siguienteNivel += 1
                experienciaParaNivel = experienciaPorNivel(personaje[1],siguienteNivel)
                experienciaParaNivel = round(experienciaParaNivel)
                
            print("Necesitas "+ str(experienciaParaNivel) +" puntos de exp. para subir de nivel")
            if (personaje[15] - nivelAnterior) != 0:
                print()
                print("HAS SUBIDO DE NIVEL")
                print() 

            if personaje[15] == 100:
                batalla = numeroBatallas + 1
                print("Felicidades!!!!! \n Completaste el juego al llegar al último nivel. ")

        #Por el contrario si la vida del personaje es negativa significa que el personaje murió   
        elif personaje[2] <= 0:
            print("Has muerto")
            print()
            print("PERDISTE")
            print()

        #Al final de la batalla se guarda la partida
        #En el caso que la partida no sea cargada(se creo una nueva partida)        
        if partidaCargada == False:
            #Se guardan en la variable personajeGuardado la información del personaje
            personajeGuardado = personaje[:]
            i = 0
            personajeGuardado[16] = round(personaje[16])
            #Se convierte a string los valores de esta lista
            while i < len(personajeGuardado):
                personajeGuardado[i] = str(personajeGuardado[i])
                i+=1
            
            #Se convierte a string la lista, separando los valores por comas
            personajeGuardado = ",".join(personajeGuardado)
            #Se asume que que archivo guardado tiene en la primera línea la descrpción 
            #Se obtiene la fecha y hora, convirtiendolo a string para poder juntarlo posteriormente
            fecha = str(datetime.now())
            #Se juntan los valores del personaje con el nombre del usuario y la fecha/hora de la partida
            textoGuardar = personajeGuardado+","+nombre+","+fecha
            #Se lee el contenido ques e tiene hasta el momento en el archivo y se almacena en la variable texto
            texto = lectura("guardado")
            #Al texto existente se agregan los datos que contienen la información de la partida
            texto.append("\n"+textoGuardar)
            partida = len(texto)-1
            #Se convierte todo a string para poder agregarlo al archivo
            texto = "".join(texto)
            #Al escribir en el archivo se coloca toda la infromación
            escribir("guardado",texto)
            #Tras ser agregado los datos archivo para posteriores guardados se sobrescribe el valor, no se crea otro
            #por lo que cambia el modo de guardado
            partidaCargada = True
        
        #En el caso que exista la partida en el archivo, se sobreescribe
        elif partidaCargada == True:
            #Se guardan en la variable personajeGuardado la información del personaje
            personajeGuardado= personaje[:]
            i = 0
            personajeGuardado[16] = round(personaje[16])
            #Se convierte a string los valores de esta lista
            while i < len(personajeGuardado):
                personajeGuardado[i] = str(personajeGuardado[i])
                i+=1
            #Se convierte a string la lista, separando los valores por comas
            personajeGuardado = ",".join(personajeGuardado)
            #Se asume que que archivo guardado tiene en la primera línea la descrpción 
            #Se obtiene la fecha y hora, convirtiendolo a string para poder juntarlo posteriormente
            fecha = str(datetime.now())
            #Se juntan los valores del personaje con el nombre del usuario y la fecha/hora de la partida
            textoGuardar = personajeGuardado+","+nombre+","+fecha
            #Se lee el contenido ques e tiene hasta el momento en el archivo y se almacena en la variable texto
            texto = lectura("guardado")
            #En el caso que el dato sea el último del archivo se coloca un "\n" al inicio
            if partida != len(texto)-1:
                texto[len(texto)-1]= "\n" +texto[len(texto)-1] 

            #Se inserta en la posición de donde se sacó la información de la partida inicialmente 
            texto.insert(partida,textoGuardar)
            #Se elimina la información anterior de la partida
            texto.pop(partida+1)
            #Se convierte todo a string para poder agregarlo al archivo
            texto = "".join(texto)
            #Al escribir en el archivo se coloca toda la infromación
            escribir("guardado",texto)

        #Al finalizar aumenta el número de batalla jugada 
        batalla +=1

    #Se imprime una barra para separar una batalla de la otra
    print("")
    print("---------------")
    #Si el jugador muere se le da la opcion de esperar para que pueda seguir jugando
    if personaje[2] <=0 and batalla <= numeroBatallas:
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

        print()
        #Se restablece el valor de respuesta para que el usuario al momento de morir pueda elegir si quiere continuar su empresa
        respuesta = ""
        #Los datos del personaje regresan a los originales
        personaje[2] = datosPersonajeAumentados[2]

    #En el caso que el usuario no desee continuar termina el juego.
    elif respuesta == "no":
        batalla = numeroBatallas +1
        
print("La experiencia alcanzada fue:",experiencia)