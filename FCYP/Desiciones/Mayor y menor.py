#Pide tres numeros e imprima de menor a mayor

a = int(input("Ingrese el primer número: "))
b = int(input("Ingrese el segundo número: "))
c = int(input("Ingrese el tercer número: "))

print("De menor a mayor")

if a < b and a < c :
    if b < c:
        print(a, b, c)
    else:
        print(a, c, b)

if b < a and b < c :
    if a < c:
        print(b, a, c)
    else:
        print(b, c, a)

if c < b and c < a:
    if b < a:
        print(c, b, a)
    else:
        print(c, a, b)

#Pide tres numero e imprime de mayor a menor

print("De mayor a menor")

if a > b and a > c :
    if b > c:
        print(a, b, c)
    else:
        print(a, c, b)

if b > a and b > c :
    if a > c:
        print(b, a, c)
    else:
        print(b, c, a)

if c > b and c > a:
    if b > a:
        print(c, b, a)
    else:
        print(c, a, b)