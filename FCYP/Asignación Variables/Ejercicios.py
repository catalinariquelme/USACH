#Ejercicios laboratorio clase 04/05/2020
#Nombre: Catalina Riquelme Zamora
#Sección: G-3
#Fecha: 04/05/2020

#Ejercicio 4
#Haga un programa que pida al nombre del usuario y luego responda con la frase “Buenas tardes NOMBRE, que tengas un buen dia”

#Datos de entrada
nombre = input("Ingrese su nombre: ")

#Salida
print("Buenas tardes {}, que tengas un buen día".format(nombre))

#Ejercicio 5
#Escriba un programa que reciba un número entero a y un número entero b. El programa debe responder
#“La suma de los números es: ”
#“La multiplicación de los números es: ”

#Datos de entrada
a = int(input("Ingrese el número entero a: "))
b = int(input("Ingrese el número entero b: "))

 #Procesamiento
suma = a + b
multiplicacion = a * b

#Salida
print("La suma de los números es: ", suma)
print("La multiplicación de los números es: ", multiplicacion)
