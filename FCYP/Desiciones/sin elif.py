#Pide número e indica día de la semana

dia = int(input("Ingrese un número del 1 al 7: "))

if dia >= 1 and dia <= 7 :

    if dia == 1 :
        print("Lunes")

    else:
         if dia == 2:
            print("Martes")

         else: 
            if dia == 3:
                print("Miercoles")

            else:
                if dia == 4:
                    print("Jueves")

                else:
                    if dia == 5:
                        print("Viernes")

                    else:
                        if dia == 6:
                            print("Sábado")

                        else:
                            if dia == 7:
                                print("Domingo")

else :
    print("Número no valido")