#include <stdio.h>
#include <stdlib.h>
/* Experiencia 11:
El problema se resuelve por BES:

Forma general de la solución:
La solución, corresponde a un arreglo de enteros con números del 1 al 9, donde:
    - La primera fila del cuadro corresponde a los primeros tres números, es decir, los números en las posiciones 0, 1 y 2.
    - La segunda fila del cuadro corresponde a los números en las posiciones 3,4,5.
    - La tercera fila del cuadro corresponde a los números en las posiciones 6,7,8.
Ejemplo de solucion:
 Solucion = [2,9,4,7,5,3,6,1,8]
 Salida:
     ______________
    |    |    |    |
    |  2 |  9 |  4 |
    |____|____|____|
    |    |    |    |
    |  7 |  5 |  3 |
    |____|____|____|
    |    |    |    |
    |  6 |  1 |  8 |
    |____|____|____|


Para resolver el problema:
 1. Generar un archivo que contenga todas las combinaciones posibles, para una solución. Como son 9 números, del 1 al 9 estos se pueden ordenar
    de 9! formas distintas, es decir, 362.880.
 2. Leer el archivo, y contar cuántas soluciones cumplen con las condiciones.
    condiciones ----> filas, columnas y diagonales sumen lo mismo.
 3. Se crea arreglo con la cantidad de soluciones, y se copian al arreglo las soluciones validas.
 4. Se imprimen todas las soluciones validas.
  
*/



/*
ENTRADAS: nombre del archivo(permutacionesCuadrado.txt)
SALIDA: archivo "permutacionesCuadrado.txt", que contiene todas las posibles soluciones.
DESCRIPCION: la funcion crea el archivo "permutaciones.txt", y se escriben todas las posibles soluciones, oomo son numeros
del 9 numeros (0-8), se obtienen 9! soluciones, es decir, 362.880 soluciones.
*/
void permutacion(char* nombreArchivo){
	FILE *archivo;
	archivo = fopen(nombreArchivo, "w");

	if (archivo == NULL) {
        printf("Error!");
        exit(1);
    }
	
	int a,b,c,d,e,f,g,h,i;

	for(a=1;a < 10; a++){
		for(b=1;b < 10; b++){
			for(c=1;c < 10; c++){
				for(d=1;d < 10;d++){
					for(e=1;e < 10;e++){
						for(f=1; f < 10;f++){
							for(g=1; g < 10;g++){
								for(h=1; h < 10;h++){
									for(i=1; i < 10;i++){
										if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i && b!=c && b!=d && b!=e 
										 && b!=f && b!=g && b!=h && b!=i && c!=d && c!=e && c!=f && c!=g && c!=h && c!=i && d!=e
										 && d!=f && d!=g && d!=h && d!=i && e!=f && e!=g && e!=h && e!=i && f!=g && f!=h && f!=i
										 && g!=h && g!=i && h!=i){
											 fprintf(archivo,"%d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
											}
									}								
								}
							}
						}
					}	
				}
			}
		}
	}
	fclose(archivo);
}

/*
ENTRADA: nombre del archivo.
SALIDA: cantidad de soluciones.
DESCRIPCION: La funcion lee el archivo, y si cumple las condiciones de solucion se contabiliza en un contador, al finalizar la lectura del 
archivo, se retorna el contador que representa la cantidad de soluciones.
*/

int contarSoluciones(char* archivo){
	FILE *archivoLectura;
	archivoLectura = fopen(archivo, "r");
	int posicion0,posicion1,posicion2,posicion3,posicion4,posicion5,posicion6,posicion7,posicion8;
    int suma_Fila1,suma_Fila2,suma_Fila3,suma_Columna1,suma_Columna2,suma_Columna3,suma_Diagonal1,suma_Diagonal2;
	
    int conteo=0;
	while(feof(archivoLectura) == 0){
		fscanf(archivoLectura,"%d%d%d%d%d%d%d%d%d",&posicion0,&posicion1,&posicion2,&posicion3,&posicion4,&posicion5,&posicion6,&posicion7,&posicion8);
        
        suma_Fila1 = posicion0 + posicion1 + posicion2;
        suma_Fila2 = posicion3 + posicion4 + posicion5;
        suma_Fila3 = posicion6 + posicion7 + posicion8;
        suma_Columna1 = posicion0 + posicion3 + posicion6;
        suma_Columna2 = posicion1 + posicion4 + posicion7;
        suma_Columna3 = posicion2 + posicion5 + posicion8;
        suma_Diagonal1 = posicion0 + posicion4 + posicion8;
        suma_Diagonal2 = posicion2 + posicion4 + posicion6;
        //Condicion/Filtro, se contabiliza como solucion cuando todas las filas, columnas y diagonales suman lo mismo.
        if(suma_Fila1 == suma_Fila2 && suma_Fila2 == suma_Fila3){
            if(suma_Fila3 == suma_Columna1 && suma_Columna1 == suma_Columna2 && suma_Columna2 == suma_Columna3){
                if(suma_Columna3 == suma_Diagonal1 && suma_Diagonal1 == suma_Diagonal2){
                    conteo++;
                }
            }
        }
	}
	fclose(archivoLectura);
	return conteo;
}


/*
ENTRADAS: nombre del archivo(permutacionesCuadrado.txt), cantidad de soluciones. 
SALIDAS: array** de enteros.
DESCRIPCION: Una vez aplicados los filtros, de acuerdo con la cantidad de soluciones, se crea un array** de enteros,
se vuelve a leer el archivo y cada vez que se encuentre una solucion que cumpla con los filtros, se registra en el array.
*/

int** registrarSoluciones(char* archivo, int cantidadSoluciones){
	FILE *archivoLectura;
	archivoLectura = fopen(archivo, "r");
	int posicion0,posicion1,posicion2,posicion3,posicion4,posicion5,posicion6,posicion7,posicion8;
    int suma_Fila1,suma_Fila2,suma_Fila3,suma_Columna1,suma_Columna2,suma_Columna3,suma_Diagonal1,suma_Diagonal2;
	int** salida = (int**)malloc(sizeof(int*)* cantidadSoluciones);

	int j=0;
	while(feof(archivoLectura) == 0){
		fscanf(archivoLectura,"%d%d%d%d%d%d%d%d%d",&posicion0,&posicion1,&posicion2,&posicion3,&posicion4,&posicion5,&posicion6,&posicion7,&posicion8);
        
        suma_Fila1 = posicion0 + posicion1 + posicion2;
        suma_Fila2 = posicion3 + posicion4 + posicion5;
        suma_Fila3 = posicion6 + posicion7 + posicion8;
        suma_Columna1 = posicion0 + posicion3 + posicion6;
        suma_Columna2 = posicion1 + posicion4 + posicion7;
        suma_Columna3 = posicion2 + posicion5 + posicion8;
        suma_Diagonal1 = posicion0 + posicion4 + posicion8;
        suma_Diagonal2 = posicion2 + posicion4 + posicion6;

        if(suma_Fila1 == suma_Fila2 && suma_Fila2 == suma_Fila3){
            if(suma_Fila3 == suma_Columna1 && suma_Columna1 == suma_Columna2 && suma_Columna2 == suma_Columna3){
                if(suma_Columna3 == suma_Diagonal1 && suma_Diagonal1 == suma_Diagonal2){
                    
                    int* salidaAux = (int*)malloc(sizeof(int)*9);
                    salidaAux[0] = posicion0;
                    salidaAux[1] = posicion1;
                    salidaAux[2] = posicion2;
                    salidaAux[3] = posicion3;
                    salidaAux[4] = posicion4;
                    salidaAux[5] = posicion5;
                    salidaAux[6] = posicion6;
                    salidaAux[7] = posicion7;
                    salidaAux[8] = posicion8;
                    salida[j]= salidaAux;
                    j++;                    
                }
            }
        }
	}
	fclose(archivoLectura);
	return salida;
}

/*
ENTRADAS: arreglo de enteros que contiene una solucion, numero de solucion.
"SALIDA": Se imprime en pantalla, el cuadrado magico que representa la solucion.
DESCRIPCION: La funcion, lee la solucion dada y la presenta en pantalla, como cuadrado magico donde
cada fila, columna y diagonal suman lo mismo.
*/
void imprimir_en_pantalla(int* solucion,int numero){
    printf("Solucion Numero %d:\n",numero);
    printf(" ______________\n");
    printf("|    |    |    |\n");
    printf("|  %d |  %d |  %d |\n",solucion[0],solucion[1],solucion[2]);
    printf("|____|____|____|\n");
    printf("|    |    |    |\n");
    printf("|  %d |  %d |  %d |\n",solucion[3],solucion[4],solucion[5]);
    printf("|____|____|____|\n");
    printf("|    |    |    |\n");
    printf("|  %d |  %d |  %d |\n",solucion[6],solucion[7],solucion[8]);
    printf("|____|____|____|\n"); 
    printf("\n\n");
}


int main(){
	char* nombreArchivo = "permutacionesCuadrado.txt";
	permutacion(nombreArchivo);
    int cantidad_Soluciones = contarSoluciones(nombreArchivo);
    int** soluciones = registrarSoluciones(nombreArchivo,cantidad_Soluciones);
    
    printf("\n");
    printf("                 Cuadrado Magico 3x3\n");
    printf("Diego Garrido\n");
    printf("\nLa cantidad de soluciones son: %d\n\n",cantidad_Soluciones);
	for(int i = 0; i < cantidad_Soluciones; i++){
        imprimir_en_pantalla(soluciones[i],(i+1));
	}

    for(int i=0; i < cantidad_Soluciones; i++){
        free(soluciones[i]);
    }
    free(soluciones);   
}