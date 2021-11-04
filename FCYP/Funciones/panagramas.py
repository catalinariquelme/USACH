
#BLOQUE DEFINCIONES

#Definición:Función que recorre la frase, preguntando si la letra de determinada posición se encuentra
#en el abecedario
#Entrada:frase(str),abc(str),i(int)
#Salida:Booleano
def recorrer_frase(frase,abc,i):
    j = 0
    while j < len(frase):
        #En el caso que encuentre coincidendia rompe el ciclo y entrega True
        if abc[i]==frase[j]:
            return True
        else:
            esta = False
        j+=1
    return esta

#Definición:Función que recorre el abecedario preguntandose si determianda letra esta en la frase preguntada
#Entrada:abc(str),frase(str)
#Salida:Booleano
def Panagrama(abc,frase):
    i = 0
    while i < len(abecedario):
        esta = recorrer_frase(frase,abc,i)
        #En el caso que sea Falso rompe el ciclo ya que ya no piede ser panagrama, porque ya existe una que 
        #no se encuentra
        if esta == False:
            return False
        i+=1
    return True

#BLOQUE PRINCIPAL

#Entrada
frase = "“Whisky bueno: ¡excitad mi pequeña y frágil vejez!”"#input("Ingrese algo:")
abecedario= "qwertyuiopasdfghjklzxcvbnm"
original = frase

#Procesamiento
frase = frase.lower()
panagrama = Panagrama(abecedario,frase)

#Salida
if panagrama == True:
    print(original+" es panagrama")
else:
    print(original+" no es panagrama")