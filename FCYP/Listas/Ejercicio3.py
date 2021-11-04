
#Ejercicios laboratorio clase 18/05/2020
#Nombre: Catalina Riquelme
#Sección: G3
#Fecha: 18/05/2020

#Ejercicio1
#Construya un programa que pida al nombre del usuario y luego responda con la frase
#“Buenas tardes NOMBRE, que tengas un buen dia” SOLO si el nombre ingresado es Andrea o Ben

print("Ejercicio 1")
#Datos de entrada
nombre = input("Ingrese su nombre: ")

#Procesamiento 
nombreOriginal = nombre
nombre = nombre.upper()
BenAndrea = False

if nombre == "ANDREA" or nombre == "BEN":
    BenAndrea = True

#Salida
if BenAndrea == True:
    print("Buenas tardes {}, que tengas un buen día".format(nombreOriginal))

else:
    print("Buenas tardes")

print()

#Ejercicio2
#Construya un programa que pida al usuario ingresar dos números enteros y 
#luego le permita escoger una de las siguientes operaciones
#Sumar
#Restar
#Multiplicar
#Dividir
#Mostrar el resultado de la forma “El resultado de la NOMBRE OPERACION es: ”

print("Ejercicio2")
#Datos de entrada
continuar = True

while continuar == True:
    
    numero1 = float(input("Ingrese el primer número: "))
    numero2 = float(input("Ingrese el segundo número: "))
    operacion = input("¿Qué operación desea realizar?(Suma, resta, multiplicación o división): ")

    operacionOriginal = operacion
    operacion = operacion.upper()

#Procesamiento

    if operacion == "SUMA" :
        resultado = numero1 + numero2

    elif operacion == "RESTA" :
        resultado = numero1 - numero2

    elif operacion == "MULTIPLICACION" :
        resultado = numero1 * numero2
    
    elif operacion == "DIVISION" :
        resultado = numero1/ numero2

    #Datos de salida
    print("El resultado de la {} es: {}" .format(operacionOriginal,resultado))

    print()
    continuar = input("Continuar(Si/No): ")

    continuar = continuar.upper()

    if continuar == "SI":
        continuar = True
    else:
        continuar = False

print()

#Ejercicio 3

#Construya un programa que pida al usuario ingresar un número entero y entregue el listado 
#de todos los números pares desde 0 hasta el número ingresado y la suma de estos.

print("Ejercicio 3")

#Datos de entrada
n = int(input("Ingrese un número: "))
i = 1
Par = True
lista = []

#Procesamiento
while i < n:
    if i % 2 == 0:
        Par == True
        lista.append(i)
    i+= 1
suma = sum(lista)

#Datos de salida
print("Los números pares son:",lista)

print("La suma de estos números es:",suma)
print()

#Ejercicio 4

# Para crear una ficha de ayuda social a personas necesitadas, la Organización COBERTIZO realiza el siguiente análisis:
#Para una familia de cuatro miembros estudia sus edades y asigna puntajes de riesgo por persona.

#En caso de edades entre los 0 y los 5 años asigna un puntaje de 50
#Para edades entre los 6 y los 17 asigna puntaje de 30
#Para edades entre 50 y 59 el puntaje es 10
#Para mayores de 60 años el puntaje es 60.
#Construya un programa que pida la edad de los cuatro miembros de una familia e indique el puntaje total que le corresponde.

print("Ejercicio 4")

edad = 3#int(input("Ingrese edad: "))
#edad2 = int(input("Ingrese edad: "))
#edad3 = int(input("Ingrese edad: "))

lista1=[0,1,2,3,4,5]
lista2=[6,7,8,9,10,11,12,13,14,15,16,17]
lista3=[50,51,52,53,54,55,56,57,58,59]

print(lista1)
i = 0

while i < len(lista1):
    
    j= 0

    while j < len(lista1[j]):

        if lista1[j] == edad:
            puntaje = 50

        j += 1
        print( puntaje)

    i += 1   
    
print(i)

