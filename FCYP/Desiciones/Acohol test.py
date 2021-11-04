#Indicar el estado en el que esta

cantidad = float(input("Ingrese cantidad de alcohol en la sangre: "))

if cantidad >= 0 and cantidad <= 6.0:
    if cantidad >= 0 and cantidad <=0.1:
        print("Normal")
    if cantidad >= 0.5 and cantidad <= 0.5:
        print("Happy")
    if cantidad >= 0.5 and cantidad <= 1.5:
        print("Curao' manejo mejor")
    if cantidad >= 1.5 and cantidad <= 3.0:
        print("No tomo más")
    if cantidad >= 3.0 and cantidad <= 5.0:
        print("La pálida")
    if cantidad >= 5.0 and cantidad <= 6.0:
        print("Coma etílicco")
    if cantidad > 6.0:
        print("Rip")

if cantidad <= 0: 
    print("Error")

