#Determinar la cantidad de vocales consecutivas dentro de una palabra
#Sin tilde ni mayuscula

#palabra a analizar
palabra = "oiseauxhhgfsaeaeaeopkioni"
#vocales del abecedario
vocales = "aeiou"
#lista en donde se guardará vocales consecutivas mas largas 
poto =" "
j = 0 
#variable temporal donde se guardan las secuencias de vocales
cadenaVocales = ""

#Se recorre la palabra 
while j < len(palabra):
    i = 0
    #En el caso que no se encuentre ninguna vocal la letra será automaticamente
    #falsa ==> silaba
    esVocal = False
    #Recorre diceindo si determinada letra es vocal o no
    while i < len(vocales):
        #En el caso que sea vocal se agrega a lo que ya tenga acumulado
        #la variable cadenaVocales
        if vocales[i]==palabra[j]:
            esVocal = True
            cadenaVocales = cadenaVocales+palabra[j]
        i+=1
    #En el caso que la cadena temporal sea  más larga a la definitiva se
    #formatea y se reemplaza por la temporal hasta que se encuentra una
    #con un largo superior
    if len(cadenaVocales) > len(poto):
        poto = ""
        poto = cadenaVocales
    
    #En el caso que la letra no sea vocal se reinicia la cadena temporal 
    #de vocales ya que se encontro una silaba
    if esVocal ==False:
        cadenaVocales = ""
    #Una vez listo todo se aumenta el contador para seguir con la siguiente letra
    j+=1
#Se imprime el string y el largo de este
print("Cadena de vocales más larga:",poto,"\nCantidad de vocales:",len(poto))
