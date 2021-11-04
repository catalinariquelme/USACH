#Catetos e hipotenusas

cateto_a = float(input("Ingrese medida del cateto a: "))
cateto_b = float(input("Ingrese medida del cateto b: "))

#Ojo con la elevación de 1/2, necesita parentesis
hipotenusa = (cateto_a**2 + cateto_b**2) ** (1/2)

print(hipotenusa)