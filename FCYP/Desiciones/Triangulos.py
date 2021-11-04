#Determinar si un triangulo es isoceles, escaleno o equilatero

angulo_a = float(input("Ingrese un ángulo: "))
angulo_b = float(input("Ingrese otro ángulo: "))

anguloC = 180-(angulo_a+angulo_b)

print()

if (angulo_a > 0) and (angulo_b > 0) and (anguloC > 0):

    print("El otro ángulo es: ", anguloC)

    if (angulo_a == angulo_b) or (angulo_a == anguloC) or (anguloC == angulo_b):
        if angulo_a == angulo_b == anguloC:
            print("El triangulo es Equilatero")
        else:
            print("El triangulo es Isoceles")
    else:
        print("El triangulo es Escaleno")
    print()
else:
    print("Valor no válido")
    print()