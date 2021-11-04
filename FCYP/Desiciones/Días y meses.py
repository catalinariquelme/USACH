#Pide número e indica día de la semana

dia = int(input("Ingrese un número del 1 al 7: "))

if dia >= 1 and dia <= 7 :
    if dia == 1 :
        print("Lunes")
    elif dia == 2:
        print("Martes")
    elif dia == 3:
        print("Miercoles")
    elif dia == 4:
        print("Jueves")
    elif dia == 5:
        print("Viernes")
    elif dia == 6:
        print("Sábado")
    elif dia == 7:
        print("Domingo")

else :
    print("Número no valido")

#Pide número e indica el mes

mes = int(input("Ingrese un número del 1 al 12: "))

if mes >= 1 and mes <= 12 :
    if mes == 1:
        print("Enero")
    elif mes == 2:
        print("Febrero")
    elif mes == 3:
        print("Marzo")
    elif mes == 4:
        print("Abril")
    elif mes == 5:
        print("Mayo")
    elif mes == 6:
        print("Junio")
    elif mes == 7:
        print("Julio")
    elif mes == 8:
        print("Agosto")
    elif mes == 9:
        print("Septiembre")
    elif mes == 10:
        print("Octubre")
    elif mes == 11:
        print("Noviembre")
    elif mes == 12:
        print("Diciembre")

else :
    print("El número ingresado no es válido")
    