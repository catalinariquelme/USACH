//EXP 11

//Catalina Riquelme Z.
//20.642.812-0

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
        printf("Error");
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
										if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i 
                                        && b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i 
                                        && c!=d && c!=e && c!=f && c!=g && c!=h && c!=i 
                                        && d!=e && d!=f && d!=g && d!=h && d!=i 
                                        && e!=f && e!=g && e!=h && e!=i
                                        && f!=g && f!=h && f!=i
										&& g!=h && g!=i 
                                        && h!=i){
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
    int sumaF1,sumaF2,sumaF3,sumaC1,sumaC2,sumaC3,sumaD1,sumaD2;
	
    int registro=0;
	while(feof(archivoLectura) == 0){
		fscanf(archivoLectura,"%d%d%d%d%d%d%d%d%d",&posicion0,&posicion1,&posicion2,&posicion3,&posicion4,&posicion5,&posicion6,&posicion7,&posicion8);
        
        //Suma de las filas
        sumaF1 = posicion0 + posicion1 + posicion2;
        sumaF2 = posicion3 + posicion4 + posicion5;
        sumaF3 = posicion6 + posicion7 + posicion8;
        //Suma de las columnas
        sumaC1 = posicion0 + posicion3 + posicion6;
        sumaC2 = posicion1 + posicion4 + posicion7;
        sumaC3 = posicion2 + posicion5 + posicion8;
        //Suma de las diagonales
        sumaD1 = posicion0 + posicion4 + posicion8;
        sumaD2 = posicion2 + posicion4 + posicion6;

        if(sumaF1 == sumaF2 && sumaF2 == sumaF3){
            if(sumaF3 == sumaC1 && sumaC1 == sumaC2 && sumaC2 == sumaC3){
                if(sumaC3 == sumaD1 && sumaD1 == sumaD2){
                    registro +=1;
                }
            }
        }
	}
	fclose(archivoLectura);
	return registro;
}

//Entrada: char* (nombre del archivo)
//Salida: int** (con las soluciones almacenadas)
//Función que almacena las soluciones posibles
int** registrarSoluciones(char* archivo, int cantidadSoluciones){
    FILE *archivoLectura;
	archivoLectura = fopen(archivo, "r");
	int posicion0,posicion1,posicion2,posicion3,posicion4,posicion5,posicion6,posicion7,posicion8;
    int sumaF1,sumaF2,sumaF3,sumaC1,sumaC2,sumaC3,sumaD1,sumaD2;
    //Dependiendo de las soluciones que encuentra el programa asigna memoria 
	int** salida = (int**)malloc(sizeof(int*)* cantidadSoluciones);
	int j=0;
	while(feof(archivoLectura) == 0){
        
        fscanf(archivoLectura,"%d%d%d%d%d%d%d%d%d",&posicion0,&posicion1,&posicion2,&posicion3,&posicion4,&posicion5,&posicion6,&posicion7,&posicion8);
        //Suma de las filas
        sumaF1 = posicion0 + posicion1 + posicion2;
        sumaF2 = posicion3 + posicion4 + posicion5;
        sumaF3 = posicion6 + posicion7 + posicion8;
        //Suma de las columnas
        sumaC1 = posicion0 + posicion3 + posicion6;
        sumaC2 = posicion1 + posicion4 + posicion7;
        sumaC3 = posicion2 + posicion5 + posicion8;
        //Suma de las diagonales
        sumaD1 = posicion0 + posicion4 + posicion8;
        sumaD2 = posicion2 + posicion4 + posicion6;

        if(sumaF1 == sumaF2 && sumaF2 == sumaF3){
            if(sumaF3 == sumaC1 && sumaC1 == sumaC2 && sumaC2 == sumaC3){
                if(sumaC3 == sumaD1 && sumaD1 == sumaD2){
                    
                    int* salidaPosicion = (int*)malloc(sizeof(int)*9);
                    salidaPosicion[0] = posicion0;
                    salidaPosicion[1] = posicion1;
                    salidaPosicion[2] = posicion2;
                    salidaPosicion[3] = posicion3;
                    salidaPosicion[4] = posicion4;
                    salidaPosicion[5] = posicion5;
                    salidaPosicion[6] = posicion6;
                    salidaPosicion[7] = posicion7;
                    salidaPosicion[8] = posicion8;
                    salida[j]= salidaPosicion;
                    j+=1;                    
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
    printf("  %d SOLUCION\n",numero);
    printf("| %d | %d | %d |\n",solucion[0],solucion[1],solucion[2]);
    printf("| %d | %d | %d |\n",solucion[3],solucion[4],solucion[5]);
    printf("| %d | %d | %d |\n\n",solucion[6],solucion[7],solucion[8]);
}


int main(){
	char* nombreArchivo = "soluciones.txt";
	permutacion(nombreArchivo);
    int numeroSoluciones = contarSoluciones(nombreArchivo);
    int** soluciones = registrarSoluciones(nombreArchivo,numeroSoluciones);
    //Se muestra por pantala las soluciones
	for(int i = 0; i < numeroSoluciones; i++){
        mostrarSolucion(soluciones[i],(i+1));
	}
    free(soluciones);   
}