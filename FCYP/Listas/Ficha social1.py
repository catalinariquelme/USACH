#Ejercicio 4

# Para crear una ficha de ayuda social a personas necesitadas, la Organización COBERTIZO realiza el siguiente análisis:
#Para una familia de cuatro miembros estudia sus edades y asigna puntajes de riesgo por persona.

#En caso de edades entre los 0 y los 5 años asigna un puntaje de 50
#Para edades entre los 6 y los 17 asigna puntaje de 30
#Para edades entre 50 y 59 el puntaje es 10
#Para mayores de 60 años el puntaje es 60.
#Construya un programa que pida la edad de los cuatro miembros de una familia e indique el puntaje total que le corresponde.


primerMiembro = int(input("Ingrese la edad del primer miembro del hogar: "))
segundoMiembro = int(input("Ingrese la edad del segundo miembro del hogar: "))
tercerMiembro = int(input("Ingrese la edad del tercer miembro del hogar: "))
cuartoMiembro = int(input("Ingrese la edad del cuarto miembro del hogar: "))

listaFamilia = [primerMiembro, segundoMiembro, tercerMiembro,cuartoMiembro]

puntajeFamilia = 0

miembro = 0 #parte en cero por la primera posición de la lista
# El ciclo se ejecutará hasta pasar por todos los elementos de la lista.

while(miembro < len(listaFamilia)):
#Al consultar en cada decisión, tomaré el valor de la lista en la
#posición actual. El primero será listaFamilia[0], con miembro = 0

    if (0 <= listaFamilia[miembro] <= 5):
        puntajeFamilia = puntajeFamilia + 50

    elif (6 <= listaFamilia[miembro] <= 17):
        puntajeFamilia = puntajeFamilia + 30

    elif (50 <= listaFamilia[miembro] <= 59):
        puntajeFamilia = puntajeFamilia + 10

    elif (60 <= listaFamilia[miembro]):
        puntajeFamilia = puntajeFamilia + 60
#Luego de evaluar al primer miembro aumento el iterador para continuar.
    miembro = miembro + 1
#Salida

print("El puntaje total de la familia es", puntajeFamilia)