#Escriba la función invertir_digitos(n) que reciba un número entero n 
# y entregue como resultado el número n con los dígitos en el orden inverso:

#A continuación, escriba un programa que indique si el número ingresado es 
# palíndromo o no, usando la función invertir_digitos:

def crearLista(n):
    i = 0
    listaOriginal = []
    while i < len(n):     
        listaOriginal.append(int(n[i]))
        i +=1
    return listaOriginal

def invertir_digitos(listaCopia):
    i = 0
    j = 1
    
    while i < len(listaCopia):
        listaCopia.insert(len(listaCopia)-j,listaCopia.pop(0))
        i +=1
        j +=1
    return listaCopia

n = input("Ingrese algo (Números plzzz): ")

original = crearLista(n)
copia= crearLista(n)

alReves= invertir_digitos(original)

print(copia)
print(alReves)

i = 0
while i < len(copia):
    if copia[i] == alReves[i]:
        polindromo = True
    else :
        polindromo = False
        break
    i +=1

if polindromo == True:
    print("Es polindromo")
else:
    print("No es polindromodo")
