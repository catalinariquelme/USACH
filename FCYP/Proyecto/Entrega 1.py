#SECCIÓN DE LABORATORIO: 0-G-3
#PROFESOR DE LABORATORIO: NICOLE HENRÍQUEZ
#PROFESOR DE TEORIA: ALEJANDRO CISTERNA
#INTEGRANTES
#1.
#NOMBRE: Emilio Acuña
#RUT:
#CARRERA: Ingeniería Civil Obras Civiles
#2.
#NOMBRE: Ricardo Avaca
#RUT:
#CARRERA: Ingeniería Civil Informática
#3.
#NOMBRE: Catalina Riquelme Zamora
#RUT: 20.642.812-0    
#CARRERA: Ingeniería de Ejecución en Computación e Informática

# BLOQUE DE DEFINICIONES

#Importación de constantes
# no hay

#Definición de constantes
#no hay

def turno_personaje():
    señalEmpezar= input("Presione enter para continuar:")
    print()
    print("Cuando se complete la barra podrá atacar")

    #Se realiza un ciclo que vaya imprimiendo la actualización cada cierto tiempo de la barra Gauge

    barraOriginal = "| ░ ░ ░ ░ ░ ░ ░ ░ ░|"
    barraLista = barraOriginal.split(" ")

    print("|░░░░░░░░░░|")

    i = 0

    while i < len(barraLista):

        #Se utiliza la función sleep para regular el tiempo con el que se imprime la barra
        time.sleep(1/personaje[1])
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
    accion = input("1)Ataque 2)Hechizo: ")

    #En caso de que el número sea distinto de 1 y 2, se tendrá que ingresar nuevamente
    while accion != "1" and accion !="2":
        print("Dato erróneo")
        accion = input("Ingrese nuevamente el número de la acción: ")

    #Ataque
    # Si el usuario ingresa 1 se realiza el ataque         
    if accion == "1":
        print()
        print("Si el número de ataque es mayor a la defensa de su enemigo podrá atacar")
        print("La defensa del enemigo es: ",enemigo[3])
        
        numeroAleatorio = randint(1,20)
        numeroAtaque = numeroAleatorio + personaje[2]

        print("Número de ataque: ",numeroAtaque)

        #Si el chance es mayor a la defensa del enemigo puede atacar
        if numeroAtaque >= enemigo[3] :

            #Fallo
            #Si el número al azar es 1 ocurre un excepción el cual beneficia al enemigo
            if numeroAleatorio == 1:
                print("Te quedan",personaje[0],"de vida")
                numeroFallo = randint(1,3)
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
                daño = 2 * (randint(personaje[8],personaje[9]))
                print("ATAQUE CRÍTICO")
                print("La vida del enemigo es:", enemigo[0])
                print("Has realizado",daño,"de daño")
                enemigo[0] = enemigo[0] - daño
                print("La nueva vida del enemigo es:", enemigo[0])
                print()

            #Para cualquier otro caso el procedimiento es el normal  
            else:
                print()
                print("Has realizado un ataque con éxito")
                print()
                daño = randint(personaje[8],personaje[9])
                print("La vida del enemigo es:",enemigo[0])
                enemigo[0] = enemigo[0] - daño
                print("Has realizado "+ str(daño) +" daño")
                print("La nueva vida del enemigo es:",enemigo[0])
                print()

            #El tueno del usuario termino
            turno = False
        #En el caso de no ser mayor a la defensa el enemigo no puede atacar
        else:
            print()
            print("Fallaste al Atacar")
            print()

            #El tueno del usuario a terminado
            turno = False

    #Hechizo
    #Si el usuario ingresa 2 se realizara un hechizo
    elif accion == "2":
            print()
            
            #En el caso de que el usuario tenga el personaje Fighter no podrá realizar un hechizo ya que no tiene probabilidades
            #en su tabla, diciendole que escoja ataque
            if personaje == Fighter:
                print("Usted no puede puede realizar hechizo")
                print("Por favor elija Ataque")
                print()
                turno = True
            #En otro caso esta habilitado para realizar Hechizo    
            else:
                print("Si el número al azar es mayor a su umbral podrá realizar un hechizo")
                print("Su umbral es:",personaje[4])
                umbral = randint(1,20)
                print("Numero al azar:",umbral)

                #Si el número es mayor al umbral puede realizar un Hechizo
                if umbral > personaje[4]:
                    print()
                    print("Puede realizar hechizo")
                    print()
                    temp = randint(1,100)

                    #Hechizo de Ataque
                    if temp < personaje[5]:
                        print("Hechizo de ataque")

                        #Crítico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        if temp == 20:
                            print("CRÍTICO")
                            temp = int(randint(personaje[10],personaje[11])*1.5)
                            print("La vida del enemigo es:",enemigo[0])
                            print("Has realizado",temp,"de daño")
                            enemigo[0] = enemigo[0]-temp
                            print("La nueva vida del enemigo es: ", enemigo[0])
                            print()

                        #Fallo
                        #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                        elif temp == 1:
                            print("FALLO")
                            print("Te quedan",personaje[0],"de vida")
                            personaje[0] = int(personaje[0]/2)
                            print("Su vida se a reducido a la mitad")
                            print("Ahora te quedan",personaje[0],"puntos de vida")
                            print()
                        
                        #Por elcontrario actua con normalidad
                        else:
                            temp = randint(personaje[10],personaje[11])
                            print("La vida del enemigo es:",enemigo[0])
                            print("Has realizado",temp,"de daño")
                            enemigo[0] = enemigo[0]-temp
                            print("La nueva vida del enemigo es: ", enemigo[0])
                            print()
                                        
                    #Hechizo de Defensa
                    elif temp < personaje[6]:
                        print("HECHIZO DE DEFENSA")
                        
                        #Crítico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        if temp ==20:
                            print("CRÍTICO")
                            print("La defensa actual es:",personaje[3])
                            personaje[3] += 2
                            print("A aumentado su defensa en 2")
                            print("Ahora su defensa es:", personaje[3])
                            print()
                        #Fallo
                        #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                        elif temp ==1:
                            print("FALLO")
                            print("La defensa del enemigo es:",enemigo[3])
                            enemigo[3] += 1
                            print("A aumentado su defensa del enemigo")
                            print("Ahora la defensa del enemigo es:", enemigo[3])
                            print()
                        #Por el contario se sigue con normalidad
                        else:
                            print("La defensa actual es:",personaje[3])
                            personaje[3] += 1
                            print("A aumentado su defensa")
                            print("Ahora su defensa es:", personaje[3])
                            print()
                        
                    #Hechizo de Curación
                    elif temp < personaje[7]:
                        print("Hechizo de curacion")
                        
                        #Critico
                        #Si el número al azar es 20 ocurre una excepción que beneficia el usuario
                        if temp == 20:
                            print("CRÍTICO")

                            #En el caso que el usuario tenga la vida llena no se curará
                            if personaje[0] == datosPersonajeOriginal[0]:
                                print("Usted no se puede curar ya que tiene la vida al máximo")
                                print()
                            
                            else:
                                print("La vida actual es:",personaje[0])
                                personaje[0] += 4
                                print("Usted se a curado 4 de vida")

                                #Si los puntos de curación superan los limites originales, quedará con el puntaje original
                                if personaje[0] > datosPersonajeOriginal[0]:
                                    personaje[0] = datosPersonajeOriginal
                                    print("Su nueva vida es: ", personaje[0])

                                else:
                                    print("Su nueva vida es: ",personaje[0])
                                print()
                        #Fallo
                        #Si el número al azar es 20 ocurre una excepción que beneficia al enemigo
                        elif temp ==1:
                            print("FALLO")
                            enemigo [0]+= 4
                            print("La vida actual del enemigo es;",enemigo[0])
                            print("Has fallado y has curado al enemigo")
                            #En el caso que el enemigo tenga la vida llena, no se curará
                            if enemigo[0] == datosEnemigoOriginal[0]:
                                print("El enemigo no se pudo curar, porque tiene la vida llena")

                            else:    
                                print("El enemigo se a curado 4 de vida")

                                #Si el puntaje de cura supera el límite de vida, quedará el puntaje original
                                if enemigo[0] > datosEnemigoOriginal[0]:
                                    enemigo[0] = datosEnemigoOriginal
                                    print("La nueva vida del enemigo es: ", enemigo[0])

                                else:
                                    print("La nueva vida del enemigo es: ",personaje[0])
                            print()
                            
                        #En cualquier otro caso se seguirá con normalidad
                        else:
                            print("La vida actual es:",personaje[0])
                            #Si la vida se encuntra completa, no se curara
                            if personaje[0] == datosPersonajeOriginal[0]:
                                print("Usted no se puede curar ya que tiene la vida al máximo")
                                print()
                            
                            else:
                                temp = randint(1,8)
                                print("Numero al azar: ",temp)
                                print("Usted se va curar ", temp,"de vida")
                                personaje[0] = personaje[0] + temp

                                #Si los puntajes de cura superan al puntos inicales, querdarán los originales
                                if personaje[0] > datosPersonajeOriginal[0]:
                                    personaje[0] = datosPersonajeOriginal
                                    print("Su nueva vida es: ", personaje[0])

                                else:
                                    print("Su nueva vida es: ",personaje[0])
                                print()
                        
                    #Ataque simple
                    #En el caso que no se puede realizar HA, HD y HC, el personaje ataca normalmente
                    else:
                        print("Ataque simple")
                        print()
                        daño = randint(personaje[8],personaje[9])
                        print("La vida del enemigo es:",enemigo[0])
                        enemigo[0] = enemigo[0] - daño
                        print("Has realizado "+ str(daño) +" puntos de daño")
                        print("Al enemigo le quedan "+str(enemigo[0])+ " puntos de vida")
                        print()
                
                #En el caso que el número aleatorio no supere el umbral no podrá realizar Hechizo
                else:
                    print()
                    print("Fallaste al realizar el hechizo")
                    #Acaba el turno del enemigo aunque no haya podido realizar el hechizo
                    turno = False
                #Acaba el turno del usuario
                turno = False

    return True


#Importación de funciones
from random import randint
from time import sleep
import time
#BLOQUE PRINCIPAL

#Se definen 4 listas, la primera con descripción de lo que contienen en cierta posición el resto de listas 
listaDescripcion = ["Ptos. de vida ","Velocidad     ","Ataque        ","Defensa       ","Umbral de H.  ","Prob. H.A.    ","Prob. H.D.    ","Prob. H.C.    ","Daño minimo   ","Daño maximo   ","Daño H. min   ","Daño H max    "]
Fighter = ["12"," 3"," 5","14","20"," 0"," 0"," 0"," 2"," 8"," 0"," 0"]#1
Wizard = [" 6"," 2"," 2","12","10","20","40"," 0"," 1"," 4"," 4","12"]#2
Cleric = [" 8"," 2"," 4","12","12"," 0","20","40"," 1"," 6"," 0"," 0"]#3
print()

i = 0
print("                    1)FIGTHER         2)WIZARD         3)CLERIC") 
print()

#Se realiza un ciclo con el fin de imprimir los datos en forma de tabla
while i < len(listaDescripcion):
    print(listaDescripcion[i],"|\t",Fighter[i],"\t","|\t",Wizard[i],"\t","|\t",Cleric[i], "\t|")
    i +=1
i = 0

#El número que ingrese el usuario corresponde a un personaje
personaje = input("Numero de personaje: ")

#En el caso que el número sea distinto de 1,2 y 3 le pedira que ingrese núevamente el dato
while personaje != "1" and personaje !="2" and personaje !="3":
    print("Dato erróneo")
    personaje = input("Ingrese nuevamente el número del personaje: ")

#Se convierte el dato a un entero para facilitar el trabajo
personaje = int(personaje)

#Personajes
Fighter = [12,3,5,14,20,0,0,0,2,8,0,0]#1
Wizard = [6,2,2,12,10,20,40,0,1,4,4,12]#2
Cleric = [8,2,4,12,12,0,20,40,1,6,0,0]#3

#Según el número que ingresa el usuario se le asignan los datoss del personaje a la variable "personaje"
print()
if personaje == 1:
    print("Personaje elegido: FIGHTER")
    print()
    personaje = Fighter
elif personaje == 2:
    print("Personaje elegido: WIZARD")
    print()
    personaje = Wizard
elif personaje == 3:
    print("Personaje elegido: CLERIC")
    print()
    personaje = Cleric

#Oponentes
Kobold = [4,2,2,12,20,0,0,4,1,6,0,0]#1
Goblin = [6,4,1,12,0,0,0,0,1,4,0,0]#2
GuerreroOrco = [12,2,5,14,0,0,0,0,1,8,0,0]#3

#Se elige un número al azar para determinar enemigo a enfrentar
enemigo = randint(1,3)

#Determinando la variable enemigo e imprimiendo su respectiva tabla
if enemigo == 1:
    print("Enemigo a enfrentar: Kobold")
    enemigo = Kobold
    i = 0
    while i < len(listaDescripcion):
        print(listaDescripcion[i],"|\t",Kobold[i],"\t|")
        i +=1

elif enemigo == 2:
    print("Enemigo a enfrentar: Goblin")
    enemigo = Goblin
    i = 0
    while i < len(listaDescripcion):
        print(listaDescripcion[i],"|\t",Goblin[i],"\t|")
        i +=1

elif enemigo == 3:
    print("Enemigo a enfrentar: Guerrero Orco")
    enemigo = GuerreroOrco
    i = 0
    while i < len(listaDescripcion):
        print(listaDescripcion[i],"|\t",GuerreroOrco[i],"\t|")
        i +=1

#Respaldo datos originales
datosPersonajeOriginal = personaje
datosEnemigoOriginal = enemigo

print()
#Para determinar a quien le toca primero se comparan las velocidades
#Para determinar cuando empieza y acaba el turno del personaje se crea una variable que vuelve False cuando termina el turno 
if personaje [1] >= enemigo[1]:
    turno = True
    turnoEnemigo = False
elif enemigo[1] > personaje[1]:
    turno= False
    turnoEnemigo= True

#Se reliza el ciclo mientras ambos contincantes se encuentren vivos
while enemigo[0] >0 and personaje[0]>0:
    #Mientras el turno del personaje sea True, se ejecutara el ciclo
    while turno == True:
        turnoEnemigo = turno_personaje()
    
    #Se comprueba que el enemigo se encuentre vivo antes de que empiece su turno
    while turnoEnemigo == True :

        if enemigo[0] <= 0:
            turnoEnemigo = False

        else:
            print("Turno enemigo")
            #Se le pide al usuario que presione enter para tener un mejor control del terminal
            #Y evitar que demasiado texto se imprima en poco tiempo
            señalInicio= input("Presione enter para continuar: ")
            print()
            print("Cuando se complete la barra el enemigo podrá atacar")

            #Se realiza un ciclo que vaya imprimiendo la actualización cada cierto tiempo de la barra Gauge
            
            barraOriginal = "| ░ ░ ░ ░ ░ ░ ░ ░ ░|"
            barraLista = barraOriginal.split(" ")

            print("|░░░░░░░░░░|")

            i = 0 

            while i < len(barraLista):
                
                #Se utiliza la función sleep para regular el tiempo con el que se imprime la barra
                time.sleep(1/enemigo[1]) 
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
        
            #Se va a elegir por el enemigo entre ataque y hechizo
            ataqueHechizo = randint(1,2)

            #Se repite el mismo proceso que en el turno de usuario pero con el enemigo
            
            #Ataque
            if ataqueHechizo == 1:
                print()
                print("Enemigo a escogido Ataque")

                numeroAleatorio = randint(0,20)
                numeroAtaque = enemigo[2] + numeroAleatorio

                if numeroAtaque >= personaje[3]:
                    
                    #Fallo
                    if  numeroAleatorio == 1: 
                        print("La vida del enemigo es de ",enemigo[0],"de vida")
                        numeroFallo = randint(1,3)
                        enemigo[0] = enemigo[0]-numeroFallo       
                        print("El enemigo fallo el ataque y se hizo daño a el mismo")
                        print("Le quedan",enemigo[0],"de vida al enemigo")

                    #Crítico
                    elif numeroAleatorio == 20:
                        print()
                        print("El enemigo logro realizarte daño")
                        print()
                        print("CRÍTICO")
                        print("Te quedan",personaje[0],"de vida")
                        daño= 2*(randint(enemigo[8],enemigo[9]))
                        personaje[0] = personaje[0] - daño
                        print("El enemigo te hizo",daño,"de daño")
                        print("Te queda ",personaje[0],"de vida")
                        print()

                    #Para cualquiero otro caso el procedimiento es normal
                    else:
                        print()
                        print("El enemigo realizar un ataque con éxito")
                        print()
                        daño = randint(enemigo[8],enemigo[9])
                        print("Tú vida actual es:",personaje[0])
                        print("El enemigo te realizado",daño,"de daño")
                        personaje[0] = personaje[0] - daño
                        print("Tú vida ahora es:", personaje[0])
                        print()
                
                else:
                    print()
                    print("El enemigo fallo el ataque")
                    print()
                turnoEnemigo= False

            #Hechizo
            elif ataqueHechizo ==2:
                print()
                print("Enemigo a escogido Hechizo")
                print()

                temp = randint(1,20)

                if temp > enemigo[4]:
                    
                    temp = randint(0,100)

                    #Hechizo de Ataque
                    if temp < enemigo[5]:
                        print("El enemigo va a realizar Hechizo de ataque")
                        #Crítico
                        if temp == 20: 
                            print("CRÍTICO")
                            temp= int(randint(enemigo[10],enemigo[11])*1.5)
                            print("Tú vida actual es:",personaje[0])
                            print("El enemigo logro realizarte",temp,"de daño")
                            personaje[0] = personaje[0] - temp
                            print("Tú nueva vida es de:",personaje[0])

                        #Fallo
                        elif temp ==1:
                            print("La vida del enemigo es de:",enemigo[0])
                            print("El enemigo fallo al realizar Hechizo de Ataque")
                            enemigo[0] = int(enemigo[0]/2)
                            print("Realizandose el Hechizo de Ataque contra el mismo")
                            print("La vida del enemigo se redujo a la mitad")
                            print("La vida actual del enemigo es:",enemigo[0],)

                        #Para cualquier otro caso el procedimiento es el mismo
                        else:
                            temp = randint(enemigo[10],enemigo[11])
                            print("Tu vida es:",personaje[0])
                            print("El enemigo realizó",temp,"de daño")
                            personaje[0] = personaje[0] - temp
                            print("Tú nueva vida es:", personaje[0])
                            print()
                
                    #Hechizo de Defensa
                    elif temp < enemigo[6]:
                        print("Enemigo va a realizar Hechizo de Defensa")
                        
                        #Crítico
                        if temp == 20:
                            print("CRÍTICO")
                            print("La defensa del enemigo es:",enemigo[3])
                            enemigo[3]= enemigo[3] + 2
                            print("La defensa del enemigo a aumentado en 2")
                            print("La nueva defensa del enemigo es",enemigo[3])
                            print()
                        
                        #Fallo
                        elif temp == 1:
                            print("FALLO")
                            print("Tú defensa es: ",personaje[3])
                            personaje[3] = personaje[3] +1
                            print("El enemigo a fallado el Hechizo")
                            print("A aumentado tú defensa")
                            print("Tú nueva defensa es: ",personaje[3])
                            print()

                        #En cualquier otro caso el procedimiento es el normal
                        else:
                            print("La defesa del enemigo es:",enemigo[3])
                            enemigo[3] += 1
                            print("A aumentado la defensa del enemigo")
                            print("Ahora su defensa es :",enemigo[3])
                            print()

                    #Hechizo de Curación
                    elif temp < enemigo[7]:
                        print("El enemigo va a realizar Hechizo de Curación")

                        #Crítico
                        if temp == 20:
                            print("CRÍTICO")
                            print("La vida del enemigo es: ",enemigo[0])

                            if enemigo[0] == datosEnemigoOriginal[0]:
                                print("Enemigo no se pudo curar ya que tiene vida al máximo")
                                print()
                            
                            else:
                                enemigo[0] +=4
                                print("El enemigo se a curado 4 de vida")

                                if enemigo[0] > datosEnemigoOriginal[0]:
                                    enemigo[0] = datosEnemigoOriginal
                                    print("La nueva vida del enemigo es: ",enemigo[0])
                                else:
                                    print("La nueva vida del enemigo es: ",enemigo[0])
                                print()

                        #Fallo
                        elif temp == 1:

                            print("El enemigo a fallado el Hechizo de curación y te curo a ti")
                            print("Tú vida actual es:",personaje[0])
                            personaje[0]+=4

                            if personaje[0] == datosPersonajeOriginal:
                                print("No te has podido curar porque tienes la vida al máximo")
                            
                            else:
                                print("Y te a curado 4 de vida")

                                if personaje[0] >datosPersonajeOriginal[0]:
                                    personaje[0]= datosPersonajeOriginal
                                    print("Tu nuevo nivel de vida es: ",personaje[0])
                                
                                else:
                                    print("Tu nuevo nivel de vida es: ",personaje[0])
                            print()
                        
                        else:
                            if enemigo[0] == datosEnemigoOriginal[0]:
                                print("El enemigo no se pudo curar ya que tiene la vida al máximo")
                                print()
                            else:
                                temp = randint(1,8)
                                print("Se va curar ", temp,"de vida")
                                enemigo[0]= enemigo[0] + temp

                                if enemigo[0] > datosEnemigoOriginal[0]:
                                    enemigo[0] = datosEnemigoOriginal[0]
                                    print("La nueva vida del enemigo es:",enemigo[0])
                                else:
                                    print("La nueva vida del enemigo es:",enemigo[0])
                                print()
                        
                    #Ataque Simple
                    else:
                        print("El enemigo realizó Ataque Simple")
                        print()
                        daño = randint(enemigo[8],enemigo[9])
                        print("Tú vida actual es:",personaje[0])
                        personaje[0] = personaje[0] - daño
                        print("El enemigo te ha quitado ",daño," de vida")
                        print("Ahora te quedan",personaje[0], "puntos de vida")
                        print()
                    
                    #Termina el turno de enemigo
                    turnoEnemigo = False
                else:
                    print("El enemigo fallo al realizar el Hechizo")
                    print()
                turnoEnemigo = False

    #Se activa el turno del personaje
    turno =  True


#Salida
print("Computo vidas")
print("Enemigo:",enemigo[0])
print("Personaje:",personaje[0])

print()
if enemigo[0] <= 0:
    print("El enemigo a muerto")
    print("GANASTE")
    print()
    
elif personaje[0] <= 0:
    print("Has muerto")
    print("PERDISTE")
    print()