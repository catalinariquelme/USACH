#Ejercicios laboratorio clase 10/08/2020
#Nombre: Catalina Riquelme Zamora
#Sección: G3
#Fecha: 10/08/2020
#Versión: 2

#BLOQUE DE DEFINICIONES

#Importacion de Ctes
# no hay

#Definición de Ctes
# no hay

#Importación de funciones
# no hay

#Entrada:Enteros(numerador, divisor)
#Salida:Booleano(True si es divible, False si no es divisible)
#Función que determina si un número es divisible por algún otro número que se de
def es_divisible(numerador,divisor):
    if numerador % divisor == 0:
        divisible = True
    else:
        divisible = False

    return divisible

#Entrada:Entero (número a determinar si es primo)
#Salida:Booleano(True si es primo, False si no primo)
#Función que determina si un número es primo devolviendo un booleano
def es_primo(numero):
    i = 2
    #Se recorren los números [2-número[
    while i < numero:
        #Se llama la función divisible por cada número 
        primo = es_divisible(numero,i)
        #En el caso que el número sea divible significa que ya no puede ser primo por lo que retorna automaticamente Falso
        if primo == True:
            return False
        i +=1   
    #En el caso que haya recorrido todo y no se encuentre con ningun número divisible significa que es primo 
    return True

#Entrada:Entero (número n)
#Salida:Lista (con los números primos hasta n)
#Función que indica los n primeros numeros primos
def primos_hasta(esPrimo):
    i = 2
    listaPrimos=[]
    while i <= esPrimo:
        primo = es_primo(i)
        if primo == True:
            listaPrimos.append(i)      
        i +=1
    print("Para el valor n=",esPrimo)
    print("Los numeros primos hasta el",esPrimo,"son:",listaPrimos)
    return listaPrimos

#Entrada:Entero (números m)
#Salida:Lista (con los m primeros números primos)
#Indica los m primeros primos 
def primeros_primos(esPrimo):
    i = 2
    j =2
    listaPrimos=[]
    #A diferencia de la función primos_hasta el contador j de esta función aumenta solamente cuando encuentra
    #Un número primo, mientras que el contador i aumenta en cada ciclo del while
    while j <= esPrimo+1:
        primo = es_primo(i)
        if primo == True:
            listaPrimos.append(i)
            j+=1
        i +=1
    return listaPrimos

#Entrada:Entero (número n)
#Salida:Listas (con los factores primos de n)
#Entrega los factores primos de un número n(En el caso que sea primo no puede descomponerse en número primos, por lo que no retorna nada)
def factores_primos(compuesto):
    factores = [compuesto]
    listaPrimos = primos_hasta(compuesto)
    #Se llama la función de primeros_primos para imprimir en el orden pedido
    print("Los primeros",compuesto,"números primos son:",primeros_primos(compuesto))
    esPrimo = es_primo(compuesto)
    j =0
    while esPrimo == False:
        i =0
        while i < len(listaPrimos):
            if factores[j]%listaPrimos[i]==0:
                factores[j] = factores[j] // listaPrimos[i]
                factores.append(listaPrimos[i])
                break
            i+=1
        #Se virzualiza si la descomposicion esta en numeros primos
        k = 0
        while k < len(factores):
            compuesto= es_primo(factores[j])
            if compuesto == False:
                break
            else:
                factores.sort()
                return factores
            k +=1
    print("El número",compuesto,"es primo por lo que no se puede descomponer")
    #En el caso que sea primo no retorna nada
    return
#BLOQUE PRINCIPAL

#Datos de entrada
numero = input("Número: ")

#Procesamiento 
esDigito = numero.isdigit()
#Mientras lo ingresado por el usuario sea distinto a un número le pedirá otro
while esDigito == False:
    print("Ingrese un número")
    numero = input("Número:")
    esDigito = numero.isdigit()
numero = int(numero)
salida =factores_primos(numero)

#Salida
if salida != None:
    print("El número",numero,"en factores primos puede descomponerse como:",salida)
