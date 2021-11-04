#Pedir cuatro nombres y dar puntaje

a = 4#int(input("Ingrese la primera edad"))
b = 4#int(input("Ingrese la segunda edad"))
c = 4#int(input("Ingrese la tercera edad"))
d = 4#int(input("Ingrese la cuarta edad"))

if a > 0 and b > 0 and c >0 and d >0:

    if (a > 0 and a < 6) or (b > 0 and b < 6) or (c > 0 and c < 6) or (d > 0 and d < 6):

        if ((a > 0 and a < 6) and (b > 0 and b < 6)) or ((a > 0 and a < 6) and (c > 0 and c < 6)) or ((a > 0 and a < 6) and (d > 0 and d < 6)) or ((b > 0 and b < 6) and (c > 0 and c < 6)) or ((b > 0 and b < 6) and (d > 0 and d < 6)) or ((c > 0 and c < 6) and (d > 0 and d < 6)):
            n = 2

            if ((a > 0 and a < 6) and (b > 0 and b < 6) and (c > 0 and c < 6)) or ((a > 0 and a < 6) and (b > 0 and b < 6) and (d > 0 and d < 6)) or ((a > 0 and a < 6) and (c > 0 and c < 6) and (d > 0 and d < 6)) or ((b > 0 and b < 6) and (c > 0 and c < 6) and (d > 0 and d < 6)):
                n =3

                if (a > 0 and a < 6) and (b > 0 and b < 6) and (c > 0 and c < 6) and (d > 0 and d < 6):
                    n = 4
            else:
                n =1        
        else: 
            n = 0

        puntaje1 = 50 * n
        print("1", puntaje1)

    if (a > 6 and a <= 17) or (b > 6 and b <= 17) or (c > 6 and c <= 17) or (d > 6 and d <= 17):

        if ((a > 6 and a <= 17) and (b > 6 and b <= 17)) or ((a > 6 and a <= 17) and (c > 6 and c <= 17)) or ((a > 6 and a <= 17) and (d > 6 and d <= 17)) or ((b > 6 and b <= 17) and (c > 6 and c <= 17)) or ((b > 6 and b <= 17) and (d > 6 and d <= 17)) or ((c > 6 and c <= 17) and (d > 6 and d <= 17)):
            n = 2

            if ((a > 6 and a <= 17) and (b > 6 and b <= 17) and (c > 6 and c <= 17)) or ((a > 6 and a <= 17) and (b > 6 and b <= 17) and (d > 6 and d <= 17)) or ((a > 6 and a <= 17) and (c > 6 and c <= 17) and (d > 6 and d <= 17)) or ((b > 6 and b <= 17) and (c > 6 and c <= 17) and (d > 6 and d <= 17)):
                n =3

                if (a > 6 and a <= 17) and (b > 6 and b <= 17) and (c > 6 and c <= 17) and (d > 6 and d <= 17):
                    n = 4
            else:
                n =1        
        else: 
            n = 0

    puntaje2 = 30 * n
    print("2",puntaje2)
        
    if (a >= 50 and a < 60) or (b >= 50 and b < 60) or (c >= 50 and c < 60) or (d >= 50 and d < 60):

        if ((a >= 50 and a < 60) and (b >= 50 and b < 60)) or ((a >= 50 and a < 60) and (c >= 50 and c < 60)) or ((a >= 50 and a < 60) and (d >= 50 and d < 60)) or ((b >= 50 and b < 60) and (c >= 50 and c < 60)) or ((b >= 50 and b <= 60) and (d >= 50 and d < 60)) or ((c >= 50 and c < 60) and (d >= 50 and d < 60)):
            n = 2

            if ((a >= 50 and a < 60) and (b >= 50 and b < 60) and (c >= 50 and c < 60)) or ((a >= 50 and a < 60) and (b >= 50 and b < 60) and (d >= 50 and d < 60)) or ((a >= 50 and a < 60) and (c >= 50 and c < 60) and (d >= 50 and d < 60)) or ((b >= 50 and b < 60) and (c >= 50 and c < 60) and (d >= 50 and d < 60)):
                n =3

                if (a >= 50 and a < 60) and (b >= 50 and b < 60) and (c >= 50 and c < 60) and (d >= 50 and d < 60):
                    n = 4
            else:
                n =1        
        else: 
            n = 0

    puntaje3 = 10 * n
    print("3", puntaje3)

    if (a >= 60) or (b >= 60) or (c >= 60) or (d >= 60):

        if ((a >=60) and (b >= 60)) or ((a >= 60) and (c >= 60)) or ((a >= 60) and (d >= 60)) or ((b >= 60) and (c >= 60)) or ((b >= 60) and (d >= 60)) or ((c >= 60) and (d >= 60)):
            n = 2

            if ((a >= 60) and (b >= 60) and (c >= 60)) or ((a >= 60) and (b >= 60) and (d >= 60)) or ((a >= 60) and (c >= 60) and (d >= 60)) or ((b >= 60) and (c >= 60) and (d >= 60)):
                n =3

                if (a >=  60) and (b >= 60) and (c >= 60) and (d >= 60):
                    n = 4
            else:
                n =1        
        else: 
            n = 0

    puntaje4 = 60 * n
    print("4",puntaje4)
else:
    print("Edad no válida")

puntajeT = puntaje1 + puntaje2 + puntaje3 + puntaje4

print("El puntaje total es:", puntajeT)
