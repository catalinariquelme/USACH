//EXP 10

//Catalina Riquelme Z.
//20.642.812-0

//PSEUDOCODIGO

#include <stdio.h>
#include <stdlib.h>

void permutacion(char* nombreArchivo);
void mostrarSolucion(int* solucion,int numero);

//Entrada: char* (nombre del archivo)
//Salida: archivo (soluciones.txt(todas las permutaciones de la solución))
//Función que crea un archivo .txt con las posibles soluciones al problema
void permutacion(char* nombreArchivo){
	FILE *arch;
	arch = fopen(nombreArchivo, "w");

	if (arch == NULL) {
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
											 fprintf(arch,"%d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
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
	fclose(arch);
}

//Entrada: char* (nombre del archivo)
//Salida: int (número de soluciones)
//Función cuenta las soluciones, aplicando las restricciones
int contarSoluciones(char* arch){
	FILE *archivoLectura;
	archivoLectura = fopen(arch, "r");
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

//Entrada: char* (nombre del archivo)
//Salida: int** (con las soluciones almacenadas)
//Función que almacena las soluciones posibles
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

//Entrada: int* (array con las soluciones)
//Función que imprime los resultados
void mostrarSolucion(int* solucion,int numero){
}


int main(){
	char* nombreArchivo = "soluciones.txt";
	permutacion(nombreArchivo);
    int numeroSoluciones = contarSoluciones(nombreArchivo);
    int** soluciones = registrarSoluciones(nombreArchivo,numeroSoluciones);
    

    printf("\nLa soluciones: %d\n\n",numeroSoluciones);
	for(int i = 0; i < numeroSoluciones; i++){
        mostrarSolucion(soluciones[i],(i+1));
	}

    free(soluciones);   
}