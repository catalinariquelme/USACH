El programa funciona con dos archivos de lectura en texto plano, el primero corresponde a las filas y el segundo a las columnas del respectivo Nonograma que se desea encontrar. Las opciones pueden ser solamente: 00, 01, 02, 03, 04, 05, 11, 12, 13, 21, 22 y 31, en donde a modo de ejemplo 02 significa que existen dos cuadros pintados de manera consecutiva en el nonograma, por el contrario 21 significa que existen 2 cuadros pintados, un espacio de n cuadrados vácios para posteriormente 1 pintado. 

------------EN EL ARCHIVO 1------------- 
El formato de este archivo debe ser el siguiente:

La primera línea correspone a la fila 1
La segunda línea correspone a la fila 2
La tercera línea correspone a la fila 3
La cuarta línea correspone a la fila 4
La quinta línea correspone a la fila 5
----------------------------------------

------------EN EL ARCHIVO 2-------------
El formato de este archivo debe ser el siguiente:

La primera línea correspone a la columna 1
La segunda línea correspone a la columna 2
La tercera línea correspone a la columna 3
La cuarta línea correspone a la columna 4
La quinta línea correspone a la columna 5
----------------------------------------

Al momento de ingresar el programa se presentan dos opciones, que son iniciar programa y salir del programa para responder a esto se requiere ingresar un número entero que sea 1 o 2.

IMPORTANTE: Al momento de ingresar el nombre del archivo ya sea correspondiente a columnas o filas es necesario agregar la extension.Un ejemplo es si el archivo tiene nombre entrada1 con extension txt, lo que debe ser ingresado es entrada1.txt.

El programa funciona a base de BES, búsqueda en espacio de soluciones, en el momento de generar las soluciones iniciales para el problema planteado se utiliza iteración.