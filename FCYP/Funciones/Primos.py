def es_divisible(numerador,divisor):
    if numerador % divisor == 0:
        divisible = True
    else:
        divisible = False

    return divisible

def es_primo(numero):
    i = 2
    while i < numero:
        primo = es_divisible(numero,i)
        if primo == True:
            return False

        i +=1    
    return True

def primeros_primos(esPrimo):
    i = 2
    listaPrimos=[]
    while i <= esPrimo:
        primo = es_primo(i)
        if primo == True:
            listaPrimos.append(i)      
        i +=1
        
    return listaPrimos

def factores_primos(numeroCompuesto):
    factores = primeros_primos(numeroCompuesto)
    compuesto = True

    while compuesto == True:
        i = 0
        while i < len(factores):
            if numeroCompuesto % factores[i] == 0:
                numeroCompuesto = numeroCompuesto//factores[i]
                factor = factores[i]
                if i == 0:
                    factores = []
                factores.append(numeroCompuesto)
                factores.append(factor)
                if i >0:
                    factores.pop(0)
                numeroCompuesto = factores[0]
                print(numeroCompuesto)
                print(factores)
            print("poto")

            j = 0
            while j < len(factores):
                compuesto= es_primo(factores[j])
                j +=1
            if compuesto == False:
                print(compuesto)
                return factores
            i +=1
            
        print(factores)

    return factores

numero = int(input("Número: "))

print(es_primo(numero))