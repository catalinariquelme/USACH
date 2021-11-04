# SECCIÓN DE LABORATORIO: 0-G-3
# PROFESOR DE LABORATORIO: NICOLE HENRÍQUEZ
# PROFESOR DE TEORIA: ALEJANDRO CISTERNA
#
# AUTORES
# NOMBRE: Ricardo Avaca Montecinos
# RUT:20.655.745-1
# CARRERA: Ingeniería Civil Informática
# NOMBRE: Catalina Riquelme Zamora
# RUT: 20.642.812-0
# CARRERA: Ingeniería de Ejecución en Computación e Informática

# Fecha: 24/09/2020
# VERSION: 3.0
# Objetivo:Desarrollar un programa capaz de resumir la infromación respecto a los datos de ingreso de los nuevos estudiantes

##BLOQUE DE FUNCIONES

#Importación de constantes
#no hay

#Definición de constantes
#no hay

#Importación de funciones
import matplotlib.pyplot as plotter

#Definición de Funciones
#Objetivo: leer un archivo
#Entrada: nombre del archivo(string)
#Salida: lista con string con el contenido del archivo
def lectura (nombreArchivo):
    nombreArchivo = nombreArchivo + ".csv"
    nombreArchivo = open(nombreArchivo,"r", encoding='utf-8')
    datosArchivo = nombreArchivo.readlines()
    nombreArchivo.close()
    return datosArchivo

#Objetivo: escribir en un archivo
#Entrada: nombre del archivo(string), texto a escribir en el archivo(string)
#Salida: booleano True
def escritura(nombre,texto):
    nombre = nombre + ".csv"
    archivo = open(nombre,"w")
    archivo.write(texto)
    archivo.close()
    return True

#Objetivo: calcular el primedio de cierto aspecto en una carrera o facultad
#Entrada: listaEstudiantes(lista),totalEstudiantes(entero),datoAPromediar(entero)(posición en lista)
#Salida: promedio en el aspecto señalado
def promedioFacultadCarrera(listaEstudiantes,totalEstudiantes,datoAPromediar):
    sumaPromedio = 0
    i= 0
    while i < len(listaEstudiantes):
        sumaPromedio += float(listaEstudiantes[i][datoAPromediar])
        i+=1
    promedio = sumaPromedio/totalEstudiantes
    return promedio

#Objetivo: calcular el primedio de cierto aspecto en la Univesidad
#Entrada: listaEstudiantes(lista),totalEstudiantes(entero),datoAPromediar(entero)(posición en lista)
#Salida: promedio en el aspecto señalado
def promedioUniversidad(listaEstudiantes,totalEstudiantes,datoAPromediar):
    sumaPromedio = 0
    i= 1
    while i < len(listaEstudiantes):
        sumaPromedio += float(listaEstudiantes[i][datoAPromediar])
        i+=1
    promedio = sumaPromedio/totalEstudiantes
    return promedio

#Objetivo: entregar el/los mejores puntajes de acorde a lo que se ingrese
#Entrada: una lista con los datos de cada estudiante y la posicion del puntaje dentro de esa lista 
#Salida: una lista de listas
def mejorEnCiertaCategoria(listaCarrera,posicionDelDato):
    datos = listaCarrera[:]#Datos de los estudiantes de la carrera
    datoMasAltoDeTodos = [0,0,0,0,0,0,0,0,0,0,0,0,0]
    todosLosDatos = []
    for potencialDatoAlto in datos:#se realiza un ciclo para obtener el mayor dato y una lista de todos los datos
        if float(datoMasAltoDeTodos[posicionDelDato]) <= float(potencialDatoAlto[posicionDelDato]):
            datoMasAltoDeTodos = potencialDatoAlto#Se guarda el dato más alto 

        todosLosDatos.append(potencialDatoAlto)#Los datos se añaden a una lista 
            
    listaDatosAltos = []
    for dato in todosLosDatos:
        if float(dato[posicionDelDato]) == float(datoMasAltoDeTodos[posicionDelDato]):
            listaDatosAltos.append(dato)#Se determinan los datos más altos comparando con la variable sacada anteriormente "datoMasAltoDeTodos"
    
    contadorPrimario = 0
    while contadorPrimario < len(listaDatosAltos):#Se realiza un ciclo para eliminar las los datos que no sean el/los datos más altos
        contadorSecundario = 0
        while contadorSecundario < len(listaDatosAltos):
            if contadorPrimario == contadorSecundario:
                contadorSecundario += 1

            elif listaDatosAltos[contadorSecundario][posicionDelDato] < listaDatosAltos[contadorPrimario][posicionDelDato]:
                listaDatosAltos.pop(contadorSecundario)

            else:
                contadorSecundario +=1
                
        contadorPrimario += 1

    listaDatos = []
    for estudiante in listaDatosAltos: #Se añade a una lista los datos que se mostrarán al usuario
        datosAMostrar = estudiante[1]+" "+ estudiante[2] + " " + str(estudiante[0])
        listaDatos.append(datosAMostrar)

    return listaDatos
        
##BLOQUE PRINCIPAL

#Datos de entrada

nombreCarrera = input("Ingrese el nombre de carrera: ")

#Procesamiento
nombreCarrera = nombreCarrera.upper()
archivoMatriculas = lectura("matriculas") #Se asume que el archivo tendra el nombre de "matriculas" (de ser el caso cotrario cambie el string )
archivoMatriculas = "".join(archivoMatriculas)
contadorSaltosDeLinea = archivoMatriculas.count("\n")
i = 0 
archivoCorrecto = True
#En el caso que existan dos líneas(uno correspondiente a la descripción y otro a la información) tomará como error
#debido a que para que el programa funcione necesita los datos separados por saltos de línea
if contadorSaltosDeLinea <= 1:
    print("El archivo no contiene los datos correctamente posicionados")

#De lo contrario funciona con normalidad
elif contadorSaltosDeLinea > 1:
    archivoMatriculas = archivoMatriculas.split("\n")
    i = 0
    #Se realiza un ciclo para transformar el archivo en una lista de listas de listas
    while i < len(archivoMatriculas):
        archivoMatriculas[i] = archivoMatriculas[i].split("\n")
        archivoMatriculas[i] = archivoMatriculas[i][0].split(",")
        i+=1

    i = 0
    #Se realiza un ciclo para verificar que exista la carrera ingresada por el usuario
    while i < len(archivoMatriculas):
        #En el caso que se encuentre la carrera se le asigna a i el valor del largo de la lista
        #para que logre salir del ciclo
        if archivoMatriculas[i][7] == nombreCarrera:
            i = len(archivoMatriculas)

        i+=1
        #En el caso que llegue al final de de la lista y no encuentre la carrera, le pedirá que 
        #ingrese otro nombre de carrera
        if i == len(archivoMatriculas):
            print("No se encuentra la carrera en el archivo")
            nombreCarrera = input("Ingrese el nombre de carrera: ")
            nombreCarrera = nombreCarrera.upper()
            i = 0
        
    #Se crea una lista que contendrá toda la información de los estudiantes de cierta carrera
    listaCarrera = []
    i = 0
    #Se recorre la lista que contiene la información de todos los estudiantes de la universidad

    #Agregando a la lista carrera solo las personas que pertenecen 
    while i < len(archivoMatriculas):
        if archivoMatriculas[i][7] == nombreCarrera:
            listaCarrera.append(archivoMatriculas[i])
        i+=1 

    facultad = listaCarrera[0][6]
    listaFacultad = []
    i = 0
    #Se recorre la lista que contiene la información de todos los estudiantes de la universidad
    #Agregando a la lista facultad solo las personas que pertenecen 
    while i < len(archivoMatriculas):
        if archivoMatriculas[i][6] == facultad:
            listaFacultad.append(archivoMatriculas[i])
        i+=1 

    totalEstudiantesCarrera = len(listaCarrera)
    totalEstudiantesFacultad = len(listaFacultad)
    totalEstudiantesUniversidad = len(archivoMatriculas)
    numeroFemenino = 0
    numeroMasculino = 0
    i = 0
    while i < len(listaCarrera):
        if listaCarrera[i][4] == "FEMENINO":
            numeroFemenino+=1
        elif listaCarrera[i][4] == "MASCULINO":
            numeroMasculino +=1
        i+=1 

    #Porcentaje estudiante femeninos
    porcentajeFemenino = round((numeroFemenino/totalEstudiantesCarrera)*100,2)
    #Porcentaje estudiantes masculinos
    porcentajeMasculino = round((numeroMasculino/totalEstudiantesCarrera)*100,2)
    nes = mejorEnCiertaCategoria(listaCarrera,10)
    mejorLenguaje = mejorEnCiertaCategoria(listaCarrera,11)
    mejorMatematica = mejorEnCiertaCategoria(listaCarrera,12)
    #Promedio de todos los estudiantes de la facultad (NES)
    promedioNesCarrera = round(promedioFacultadCarrera(listaCarrera,totalEstudiantesCarrera,10),2)
    #Promedio de todos los estudiantes de la facultad (Lenguaje)
    promedioLenguajeCarrera = round(promedioFacultadCarrera(listaCarrera,totalEstudiantesCarrera,11),2)
    #Promedio de todos los estudiantes de la facultad (Matematicas)
    promedioMatematicasCarrera = round(promedioFacultadCarrera(listaCarrera,totalEstudiantesCarrera,12),2)
    #Promedio de todos los estudiantes de la Universidad (NES)
    #Promedio de todos los estudiantes de la facultad (NES)
    promedioNesFacultad = round(promedioFacultadCarrera(listaFacultad,totalEstudiantesFacultad,10),2)
    #Promedio de todos los estudiantes de la facultad (Lenguaje)
    promedioLenguajeFacultad = round(promedioFacultadCarrera(listaFacultad,totalEstudiantesFacultad,11),2)
    #Promedio de todos los estudiantes de la facultad (Matematicas)
    promedioMatematicasFacultad = round(promedioFacultadCarrera(listaFacultad,totalEstudiantesFacultad,12),2)
    #Promedio de todos los estudiantes de la Universidad (NES)
    promedioNesUniversidad = round(promedioUniversidad(archivoMatriculas,totalEstudiantesUniversidad,10),2)
    #Promedio de todos los estudiantes de la Universidad (Lenguaje)
    promedioLenguajeUniversidad = round(promedioUniversidad(archivoMatriculas,totalEstudiantesUniversidad,11),2)
    #Promedio de todos los estudiantes de la Universidad (Matematicas)
    promedioMatematicasUniversidad = round(promedioUniversidad(archivoMatriculas,totalEstudiantesUniversidad,12),2)
    etiquetas = ["Porcentaje femenino","Porcentaje masculino"]
    valores = [numeroFemenino, numeroMasculino]
    if numeroFemenino <= numeroMasculino:
        explode = [0.1, 0]
    else:
        explode = [0, 0.1]

    plotter.pie(valores, explode=explode, labels=etiquetas, autopct='%2.2f%%', startangle=90)
    plotter.title("Porcentaje femenino/masculino")
    plotter.show()
    guardado = list(range(15))
    guardado[0] = "CARRERA: " + nombreCarrera + "\n"
    guardado[1] = "PORCENTAJE DE ESTUDIANTES SEXO FEMENINO: "+str(porcentajeFemenino)+"%" + "\n"
    guardado[2] = "PORCENTAJE DE ESTUDIANTES SEXO MASCULINO: " +str(porcentajeMasculino)+"%" + "\n"
    guardado[3] = "MEJOR NES: " + ", ".join(nes) + "\n"
    guardado[4] = "MEJOR LENGUAJE: " + ", ".join(mejorLenguaje) + "\n"
    guardado[5] = "MEJOR MATEMÁTICA: " +", ".join(mejorMatematica) + "\n"
    guardado[6] = "PROMEDIO NES CARRERA: " + str(promedioNesCarrera) + "\n"
    guardado[7] = "PROMEDIO NES FACULTAD: " + str(promedioNesFacultad) + "\n"
    guardado[8] = "PROMEDIO NES UNIVERSIDAD: " + str(promedioNesUniversidad) + "\n"
    guardado[9] = "PROMEDIO LENGUAJE CARRERA: " + str(promedioLenguajeCarrera) + "\n"
    guardado[10] = "PROMEDIO LENGUAJE FACULTAD: " + str(promedioLenguajeFacultad) + "\n"
    guardado[11] = "PROMEDIO LENGUAJE UNIVERSIDAD: " + str(promedioLenguajeUniversidad) + "\n"
    guardado[12] = "PROMEDIO MATEMÁTICAS CARRERA: " + str(promedioMatematicasUniversidad) + "\n"
    guardado[13] = "PROMEDIO MATEMÁTICAS FACULTAD: " + str(promedioMatematicasFacultad) + "\n"
    guardado[14] = "PROMEDIO MATEMÁTICAS UNIVERSIDAD: " + str(promedioMatematicasUniversidad) + "\n"
    guardado = "".join(guardado)
    escritura("Información resumida",guardado)
    print("Su archivo se guardó con éxito")