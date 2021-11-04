#Encontrar el 85 numero primo fabricado por la formula

def es_primo(numero):
    i = 2

    while i < numero:
        
        if numero % i == 0:
            return False    
        i +=1
    return True

numeroPrimo = 0
i = 1
while numeroPrimo<86:
    intento = i**2+((i+1)**2)
    numero = es_primo(intento)
    if numero == True:
        numeroPrimo+=1
    i+=1
    
print(intento)