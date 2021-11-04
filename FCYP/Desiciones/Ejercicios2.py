#Ejercicios laboratorio clase 11/05/2020
#Nombre: Catalina Riquelme
#Sección; G3
#Fecha; 11/05/2020

#Ejercicio 1
#Construya un programa que pida al nombre del usuario luego responda con la frase
#“Buenas tardes NOMBRE, que tengas un buen dia.” SOLO si el nombre ingresado
#es Andrea o Ben. Si el nombre es otro solo indicar “Buenas tardes.”

#Datos de entrada
nombre = input("Ingrese su nombre: ")

#Procesamiento y salida
if nombre == "Andrea" or nombre == "Ben":
    print("Buenos tardes {}, que tengas un buen día".format(nombre))
else:
    print("Buenas tardes")

print("************")

#Ejercicio 2
#Construya un programa que pida al usuario ingresar dos números enteros y 
#luego le permita escoger una de las siguientes operaciones.

#Sumar
#Restar
#Multiplicar
#Dividir

#Datos de entrada
numero1 = float(input("Ingrese el primer número: "))
numero2 = float(input("Ingrese el segundo número: "))
operacion = input("¿Qué operación desea realizar?(Suma, resta, multiplicación o división): ")

#Procesamiento
if operacion == "suma" or operacion == "Suma" or operacion == "+" :
    resultado = numero1 + numero2

if operacion == "resta" or operacion == "Resta" or operacion == "-":
    resultado = numero1 - numero2

if operacion == "multiplicacion" or operacion == "Multiplicacion" or operacion == "x":
    resultado = numero1 * numero2
    
if operacion == "division" or operacion == "Division" or operacion == "/" :
    resultado = numero1/ numero2

#Datos de salida
print("El resultado de la {} es: {}" .format(operacion,resultado))
print("************") 

#Ejercicio 3
#Construya un programa que pida al usuario ingresar tres número
#enteros e indique cuántos de estos números son pares.

#Datos de entrada
numero1 = float(input("Ingrese el primer número: "))
numero2 = float(input("Ingrese el segundo número: "))
numero3 = float(input("Ingrese el tercer número: "))

#Procesamiento
paridad1 = numero1 % 2
paridad2 = numero2 % 2
paridad3 = numero3 % 2

if (paridad1 == 0) or (paridad2 == 0) or (paridad3 == 0):
    if ((paridad1 == 0) and (paridad2 == 0)) or ((paridad1 == 0) and (paridad3 == 0)) or ((paridad2 == 0) and (paridad3 == 0)):
        resultado2 = "2 de ellos son pares"

        if (paridad1 == 0) and (paridad2 == 0) and (paridad3 == 0):
            resultado2 = "3 de ellos son pares"
    else:
        resultado2 = "1 de ellos es par"
else:
    resultado2 = "Ninguno es par"

#Salida    
print(resultado2)
print("************")

#Ejercicio 5
#Construya un programa que determine si un triángulo es válido
#o no dependiendo de los ángulos ingresados por el usuario. 

#Datos de entrada
angulo1 = float(input("Ingrese el primer ángulo: "))
angulo2 = float(input("Ingrese el segundo ángulo: "))
angulo3 = float(input("Ingrese el tercer angulo: "))

#Procesamiento
if angulo1 > 0 and angulo2 >0 and angulo3 > 0:

    if angulo1 < 180 and angulo2 < 180 and angulo3 < 180:
        
        if (angulo1 + angulo2 + angulo3) == 180:
            resultado3 = "valido"
        else:
            resultado3 = "invalido"
    else:
        resultado3 ="invalido"
else:
    resultado3 = "invalido"

#Datos de salida
print("El triangulo es", resultado3)

#Ejercicio 4
#Para crear una ficha de ayuda social a personas necesitadas, la Organización COBERTIZO realiza el siguiente análisis: 
#Para una familia de cuatro miembros estudia sus edades y asigna puntajes de riesgo por persona.
#En caso de edades entre los 0 y los 5 años asigna un puntaje de 50
#Para edades entre los 6 y los 17 asigna puntaje de 30
#Para edades entre 50 y 59 el puntaje es 10
#Para mayores de 60 años el puntaje es 60.
#Construya un programa que pida la edad de los cuatro miembros de una familia e indique el puntaje total que le corresponde.

#Sin repetición de intervalo

#Datos de entrada
a = int(input("Ingrese la primera edad"))
b = int(input("Ingrese la segunda edad"))
c = int(input("Ingrese la tercera edad"))
d = int(input("Ingrese la cuarta edad"))

#Procesamiento
if a > 0 and b > 0 and c >0 and d >0:

    if (a > 0 and a < 6) or (b > 0 and b < 6) or (c > 0 and c < 6) or (d > 0 and d < 6):
        n = 1
    else: 
        n = 0

    puntaje1 = 50 * n
    

    if (a > 6 and a <= 17) or (b > 6 and b <= 17) or (c > 6 and c <= 17) or (d > 6 and d <= 17):
        n =1        
    else: 
        n = 0

    puntaje2 = 30 * n
    
        
    if (a >= 50 and a < 60) or (b >= 50 and b < 60) or (c >= 50 and c < 60) or (d >= 50 and d < 60):
        n =1   

    else: 
        n = 0

    puntaje3 = 10 * n
    

    if (a >= 60) or (b >= 60) or (c >= 60) or (d >= 60):
        n =1        
    else: 
        n = 0

    puntaje4 = 60 * n
    

    if (a > 17 and a < 50) or (b > 17 and b < 50) or (c > 17 and c < 50) or (d > 17 and d < 50):
        n =0   

    puntaje5 = 10 * n
    
else:
    print("Edad no válida")

puntajeT =  puntaje1 + puntaje2 + puntaje3 + puntaje4 + puntaje5

#Salida
print("El puntaje total es:", puntajeT)
