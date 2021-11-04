Los códigos son para la lectura y escritura de archivos. 

Las funciones que se tienen que tener en cuenta son:

- fopen: Abre el archivo, de no existir retorna NULL.
- fclose: Cierra el archivo.
- feof: Indica si se ha llegado al final del archivo. Retorna un valor distinto de 0 si es que el archivo 
llego a su fin. 

Para fopen tener en consideracion el parametro para indicar el tipo de lectura, los que mas podrian necesitar son:

- w: Abre un archivo para escritura, de no existir crea el archivo.
- w+: Crea un archivo para escritura y lectura, de no existir se crea el archivo pero si existe se sobreescribe el existente.
- r: Abre un archivo en formato de lectura, el archivo debe existir.
- r+: Abre un archivo en para escritura y lectura, debe existir el archivo.
- a: Abre un archivo para escritura pero este se va a escribir al final del archivo. 

Para la lectura de archivos se tienen las siguientes funciones:

- fgetc: lee solo caracter por caracter.
- fgets: lee un tamaño determinado por linea. 
- fscanf: lee linea por linea, pero tiene la ventaja de indicar el formato de esta. 

En cuanto a la escritura: 

- fscanf: Permite escribir en el archivo dado un cierto formato.
- fputs: Escribe el contenido de la variable en el archivo. 

Tener en consideracion lo siguiente: 

- Siempre incluir la libreria <stdlib.h>
- Inicializar archivo tipo FILE*
- Abrir y cerrar archivos.
- Tener en cuenta saltos de linea. 

############### PARA MAS INFORMACION ########################

https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Manejo_de_archivos

#############################################################

