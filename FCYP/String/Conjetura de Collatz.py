numero = int(input("Número: "))
string =""
while numero > 1:
    if numero % 2 == 0:
        numero /=2
    else:
        numero *=3
        numero +=1
    numero = int(numero)
    numero2 = str(numero)
    string = string+" "+(numero2)
print(string)
