#Solicitar edades e imprimir "La primera persona es x menor que la segunda por ej"

edad_1 = int(input("Edad de la primera persona: "))
edad_2 = int(input("Edad de la segunda persona: "))

diferencia_edades = ((edad_1 - edad_2)**2)**(1/2)
diferencia_edades2 = int(diferencia_edades)

if edad_1 > edad_2:
    print("La segunda persona es {} años menor que la primera persona" .format(diferencia_edades2))

else:
    print("La primera persona es {} años menor que la segunda persona" .formmat(diferencia_edades2))