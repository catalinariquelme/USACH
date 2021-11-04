// SECCIÓN: L-11
// PROFESOR DE LABORATORIO: IGNACIO IBÁÑEZ ALIAGA
//
// AUTORA
// NOMBRE: Catalina Riquelme Zamora
// RUT: 20.642.812-0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutacion(char* nombreArchivo);
void mostrarSolucion(int* solucion,int numero);
void lecturaArch(char* nombre, int** data);

//Entrada: int** arrayColumnas(pistas columnas), int* array(posible combinacion a analizar)
//Salida: int 1 (en el caso que exista) int 2 (en el caso que no exista)
//Función que analiza una columna o una fila determinando si cumple la condición de la pista
int verificadorColumnasFilas(int* arrayColumnas,int* array){
    //las opciones pueden ser solamente: 00, 01, 02, 03, 04, 05, 11, 12, 13, 21, 22 y 31
    int contador;
    int registro;

    if (arrayColumnas[0] == 0 && arrayColumnas[1]== 0){
        int i =0;
        while (i < 5){
            if (array[i] == 1){
                return 0;
            }
            i++;
        }
        return 1;
    }

    else if (arrayColumnas[0] == 0 && arrayColumnas[1]== 1){
        int i =0;
        while (i < 5){
            if (array[i] == 1){
                return 1;
            }
            i++;
        }
        return 0;
    }
    
    else if (arrayColumnas[0] == 0 && arrayColumnas[1]== 2){
        int i =0;
        while (i < 4){
            if (array[i] == 1 && array[i+1] == 1){
                return 1;
            }
            i++;
        }
        return 0;
    }

    else if (arrayColumnas[0] == 0 && arrayColumnas[1]== 3){
        int i =0;
        while (i < 3){
                if (array[i]== 1 && array[i+1] == 1 && array[i+2] == 1){
                return 1;
            }
            i++;
        }
        return 0;
    }   
    
    else if (arrayColumnas[0] == 0 && arrayColumnas[1]== 4){
        int i =0;
        while (i < 2){
            if (array[i]== 1 && array[i+1] == 1 && array[i+2] == 1 && array[i+3] == 1){
                return 1;
            }
            i++;
        }
        return 0;
    }
    
    else if (arrayColumnas[0] == 0 && arrayColumnas[1]== 5){
    int i =0;
        while (i < 5){
            if (array[i] == 0){
                return 0;
            }
            i++;
        }
        return 1;
    }

    else if (arrayColumnas[0] == 1 && arrayColumnas[1]== 1){
        int i =0;
        while (i < 4){
            if (array[i] == 1 && array[i+1] == 0){
                int j = i+1;
                while(j < 5){
                    if (array[j] == 1){
                        return 1;
                    }
                    j++;
                }   
            }
            i++;
        }
        return 0;
    }

    else if (arrayColumnas[0] == 1 && arrayColumnas[1]== 2){
        int i =0;
        while (i < 4){
            if (array[i] == 1 && array[i+1] == 0){
                int j = i+1;
                while(j < 4){
                    if (array[j] == 1 && array[j+1] == 1){
                        return 1;
                    }
                    j++;
                }
            }
            i++;
        }
        return 0;
    }

    else if (arrayColumnas[0] == 1 && arrayColumnas[1]== 3){
        int i =0;
        while (i < 4){
            if (array[i] == 1 && array[i+1] == 0){
                 int j = i+1;
                while(j < 3){
                    if (array[j] == 1 && array[j+1] == 1 && array[j+2] == 1){
                        return 1;
                    }
                    j++;
                }
            }
            i++;
        }
        return 0;
    }   

    else if (arrayColumnas[0] == 2 && arrayColumnas[1]== 1){
        int i =0;
        while (i < 3){
            if (array[i] == 1 && array[i+1] == 1 && array[i+2] == 0){
                int j = i+1;
                while(j < 4){
                    if (array[j] == 0 && array[j+1] == 1){
                        return 1;
                    }
                    j++;
                }
            }
            i++;
        }
        return 0;
    }

    else if (arrayColumnas[0] == 2 && arrayColumnas[1]== 2){
        int i =0;
        while (i < 3){
            if (array[i] == 1 && array[i+1] == 1 && array[i+2] == 0){
                int j = i+1;
                while(j < 4){
                    if (array[j] == 1 && array[j+1] == 1){
                        return 1;
                    }
                    j++;
                }
            }
            i++;
        }
        return 0;
    }   

    else if (arrayColumnas[0] == 3 && arrayColumnas[1]== 1){
        int i =0;
        while (i < 2){
            if (array[i] == 1 && array[i+1] == 1 && array[i+2] == 1 && array[i+3] == 0){
                int j = i+1;
                while(j < 4){
                    if (array[j] == 0 && array[j+1] == 1){
                        return 1;
                    }
                    j++;
                }
            }
            i++;
        }
        return 0;
    }
    
    return -1;
}

//Entardas: char*nombre(nombre del archivo a leer),char**data(char en donde se alamacenará la información leída)
//Objetivo: leer y almacenar la información del archivo
void lecturaArch(char* nombre, int** data){
    char carpeta[100] = "Pistas/";
    nombre = strcat(carpeta,nombre);

    FILE* arch;
    arch = fopen(nombre,"r");
    int i = 0;
    while(feof(arch) == 0){
        char* aux = (char*)malloc(100*sizeof(char));
        int* arr = (int*)malloc(2*sizeof(int));
        char posicion0,posicion1;

        fscanf(arch,"%c%c\n",&posicion0,&posicion1);
        posicion0 = posicion0 - '0';
        posicion1 = posicion1 - '0';
        arr[0] = posicion0;
        arr[1] = posicion1;
        data[i] = arr;
        i++;
    }
    fclose(arch);
}

//Entrada: int**data (array a analizar)
//Salida: int 1 (en el caso cumpla) int 2 (en el caso que no cumpla)
//Función que determina si el archivo entrgado por el usuaruio cumple con las restricciones impuestas
int validacionArch(int** data){
    int contador = 0;
    for (int i=0; i<5;i++){
        if (data[i][0] == 0 && data[i][1]== 0){
            contador++;
        }   
        if (data[i][0] == 0 && data[i][1] == 1){
            contador++;
        }
        if (data[i][0] == 0 && data[i][1] == 2){
            contador++;
        }   
        if (data[i][0] == 0 && data[i][1]== 3){
            contador++;
        }   
        if (data[i][0] == 0 && data[i][1]== 4){
            contador++;
        }   
        if (data[i][0] == 0 && data[i][1]== 5){
            contador++;
        }   
        if (data[i][0] == 1 && data[i][1]== 1){
            contador++;
        }
        if (data[i][0] == 1 && data[i][1]== 2){
            contador++;
        }   
        if (data[i][0] == 1 && data[i][1]== 3){
            contador++;
        }   
        if (data[i][0] == 2 && data[i][1]== 1){
            contador++;
        }   
        if (data[i][0] == 2 && data[i][1]== 2){
            contador++;
        }   
        if (data[i][0] == 3 && data[i][1]== 1){
            contador++;
        }
    }
    if (contador == 5){
        return 1;
    }
    return 0;
}

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
    //Para calcular todas las soluciones posibles se escribe un archivo en donde cada fila contenga 25 numero, lo que
    //reprensenta una matriz de 5x5 variando cada número entre 0 y 1
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y;
	for(a=0;a < 2; a++){
		for(b=0;b < 2; b++){
			for(c=0;c < 2; c++){
				for(d=0;d < 2;d++){
					for(e=0;e < 2;e++){
						for(f=0; f < 2;f++){
							for(g=0; g < 2;g++){
								for(h=0; h < 2;h++){
									for(i=0; i < 2;i++){
                                        for(j=0;j < 2; j++){
                                            for(k=0;k < 2; k++){
                                                for(l=0;l < 2; l++){
                                                    for(m=0;m < 2;m++){
                                                        for(n=0;n < 2;n++){
                                                            for(o=0; o < 2;o++){
                                                                for(p=0; p < 2;p++){
                                                                    for(q=0; q < 2;q++){
                                                                        for(r=0; r < 2;r++){
                                                                            for(s=0;s < 2; ++s){
                                                                                for(t=0;t < 2;t++){
                                                                                    for(u=0;u < 2;u++){
                                                                                        for(v=0; v < 2;v++){
                                                                                            for(w=0; w < 2;w++){
                                                                                                for(x=0; x < 2;x++){
                                                                                                    for(y=0; y < 2;y++){
                                                                                                        fprintf(arch,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y);
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
					}	
				}
			}
		}
	}
	fclose(arch);
}

//Entrada: char*arch (nombre del archivo),int** arrayFilas(pistas filas), int** arrayColumnas(pistas columnas)
//Salida: int (número de soluciones)
//Función que aplica restricciones al total de posibles soluciones con el fin de filtrar las soluciones y entregar la cantidad que existe
int contarSol(char* arch,int** arrayFilas,int** arrayColumnas){
    FILE *archivoLectura;
	archivoLectura = fopen(arch, "r");
    //Se definen 25 posiciones
	int posicion1,posicion2,posicion3,posicion4,posicion5,posicion6,posicion7,posicion8,posicion9,posicion10;
    int posicion11,posicion12,posicion13,posicion14,posicion15,posicion16,posicion17,posicion18,posicion19,posicion20;
    int posicion21,posicion22,posicion23,posicion24,posicion25;
    //Se definen variables en donde se almacenarán las sumas de cada fila y columna
    int sumaF1,sumaF2,sumaF3,sumaF4,sumaF5,sumaC1,sumaC2,sumaC3,sumaC4,sumaC5;
    //Se definen variables en donde se almacenan la suma de las pistas dadas respecto a cada fila y columna
    int pistasF1,pistasF2,pistasF3,pistasF4,pistasF5;
    int pistasC1,pistasC2,pistasC3,pistasC4,pistasC5;

    pistasF1 = arrayFilas[0][0] + arrayFilas[0][1];
    pistasF2 = arrayFilas[1][0] + arrayFilas[1][1];
    pistasF3 = arrayFilas[2][0] + arrayFilas[2][1];
    pistasF4 = arrayFilas[3][0] + arrayFilas[3][1];
    pistasF5 = arrayFilas[4][0] + arrayFilas[4][1];

    pistasC1 = arrayColumnas[0][0] + arrayColumnas[0][1];
    pistasC2 = arrayColumnas[1][0] + arrayColumnas[1][1];
    pistasC3 = arrayColumnas[2][0] + arrayColumnas[2][1];
    pistasC4 = arrayColumnas[3][0] + arrayColumnas[3][1];
    pistasC5 = arrayColumnas[4][0] + arrayColumnas[4][1];

    int registro=0;
	while(feof(archivoLectura) == 0){

		fscanf(archivoLectura,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&posicion1,&posicion2,&posicion3,&posicion4,&posicion5,&posicion6,&posicion7,&posicion8,&posicion9,&posicion10,&posicion11,&posicion12,&posicion13,&posicion14,&posicion15,&posicion16,&posicion17,&posicion18,&posicion19,&posicion20,&posicion21,&posicion22,&posicion23,&posicion24,&posicion25);
        
        //Suma de las filas
        sumaF1 = posicion1 + posicion2 + posicion3 + posicion4 + posicion5;
        sumaF2 = posicion6 + posicion7 + posicion8 + posicion9 + posicion10;
        sumaF3 = posicion11 + posicion12 + posicion13 + posicion14 + posicion15;
        sumaF4 = posicion16 + posicion17 + posicion18 + posicion19 + posicion20;
        sumaF5 = posicion21 + posicion22 + posicion23 + posicion24 + posicion25;

        //Suma de las columnas
        sumaC1 = posicion1 + posicion6 + posicion11 + posicion16 + posicion21;
        sumaC2 = posicion2 + posicion7 + posicion12 + posicion17 + posicion22;
        sumaC3 = posicion3 + posicion8 + posicion13 + posicion18 + posicion23;
        sumaC4 = posicion4 + posicion9 + posicion14 + posicion19 + posicion24;
        sumaC5 = posicion5 + posicion10 + posicion15 + posicion20 + posicion25;
        
        int array[5][5] = {{posicion1,posicion2,posicion3,posicion4,posicion5},{posicion6,posicion7,posicion8,posicion9,posicion10},{posicion11,posicion12,posicion13,posicion14,posicion15},{posicion16,posicion17,posicion18,posicion19,posicion20},{posicion21,posicion22,posicion23,posicion24,posicion25}};
       
        // Posiciones Fila 1,2,3,4,5
        int f1[5] = {posicion1,posicion2,posicion3,posicion4,posicion5};
        int f2[5] = {posicion6,posicion7,posicion8,posicion9,posicion10};
        int f3[5] = {posicion11,posicion12,posicion13,posicion14,posicion15};
        int f4[5] = {posicion16,posicion17,posicion18,posicion19,posicion20};
        int f5[5] = {posicion21,posicion22,posicion23,posicion24,posicion25};
        
        //Posiciones Column 1,2,3,4,5
        int c1[5] = {posicion1,posicion6,posicion11,posicion16,posicion21};
        int c2[5] = {posicion2,posicion7,posicion12,posicion17,posicion22};
        int c3[5] = {posicion3,posicion8,posicion13,posicion18,posicion23};
        int c4[5] = {posicion4,posicion9,posicion14,posicion19,posicion24};
        int c5[5] = {posicion5,posicion10,posicion15,posicion20,posicion25};

        //Se aplican las restricciones con el fin de filtrar hasta encontrar la(s) respuesta(s) correcta(s)
        if ((pistasF1 == sumaF1) && (pistasF2 == sumaF2) && (pistasF3 == sumaF3) && (pistasF4 == sumaF4) && (pistasF5 == sumaF5)){
            
            if ((pistasC1 == sumaC1) && (pistasC2 == sumaC2) && (pistasC3 == sumaC3) && (pistasC4 == sumaC4) && (pistasC5 == sumaC5)){
                
                if ((verificadorColumnasFilas(arrayFilas[0],f1)== 1) && (verificadorColumnasFilas(arrayFilas[1],f2) == 1) && (verificadorColumnasFilas(arrayFilas[2],f3) == 1) && (verificadorColumnasFilas(arrayFilas[3],f4) == 1) && (verificadorColumnasFilas(arrayFilas[4],f5) == 1)){
                    
                    if ((verificadorColumnasFilas(arrayColumnas[0],c1) == 1) && (verificadorColumnasFilas(arrayColumnas[1],c2) == 1) && (verificadorColumnasFilas(arrayColumnas[2],c3) == 1) && (verificadorColumnasFilas(arrayColumnas[3],c4) == 1) && (verificadorColumnasFilas(arrayColumnas[4],c5) == 1)){
        
                    registro +=1;
                    } 
                }
            }
        }
        
    }
    fclose(archivoLectura);
    printf("Se encontraron %d posible(s) solucion(es)\n\n",registro);
    return registro;
}

//Entrada: char*arcg (nombre del archivo),int cantidadSoluciones(número de soluciones existentes),int** arrayFilas(pistas filas), int** arrayColumnas(pistas columnas)
//Salida: int** (con las soluciones almacenadas)
//Función que aplica restricciones al total de posibles soluciones con el fin de filtrar las soluciones y almacenar las existentes
int** registrocontarSol(char* arch, int cantidadSoluciones,int** arrayColumnas,int** arrayFilas){
    FILE *archivoLectura;
	archivoLectura = fopen(arch, "r");
    //Se definen 25 posiciones
	int posicion1,posicion2,posicion3,posicion4,posicion5,posicion6,posicion7,posicion8,posicion9,posicion10;
    int posicion11,posicion12,posicion13,posicion14,posicion15,posicion16,posicion17,posicion18,posicion19,posicion20;
    int posicion21,posicion22,posicion23,posicion24,posicion25;
    //Se definen variables en donde se almacenarán las sumas de cada fila y columna
    int sumaF1,sumaF2,sumaF3,sumaF4,sumaF5,sumaC1,sumaC2,sumaC3,sumaC4,sumaC5;
    //Se definen variables en donde se almacenan la suma de las pistas dadas respecto a cada fila y columna
    int pistasF1,pistasF2,pistasF3,pistasF4,pistasF5;
    int pistasC1,pistasC2,pistasC3,pistasC4,pistasC5;

    pistasF1 = arrayFilas[0][0] + arrayFilas[0][1];
    pistasF2 = arrayFilas[1][0] + arrayFilas[1][1];
    pistasF3 = arrayFilas[2][0] + arrayFilas[2][1];
    pistasF4 = arrayFilas[3][0] + arrayFilas[3][1];
    pistasF5 = arrayFilas[4][0] + arrayFilas[4][1];

    pistasC1 = arrayColumnas[0][0] + arrayColumnas[0][1];
    pistasC2 = arrayColumnas[1][0] + arrayColumnas[1][1];
    pistasC3 = arrayColumnas[2][0] + arrayColumnas[2][1];
    pistasC4 = arrayColumnas[3][0] + arrayColumnas[3][1];
    pistasC5 = arrayColumnas[4][0] + arrayColumnas[4][1];

	int** salida = (int**)malloc(sizeof(int*)* cantidadSoluciones);
	int j=0;
	while(feof(archivoLectura) == 0){
		fscanf(archivoLectura,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&posicion1,&posicion2,&posicion3,&posicion4,&posicion5,&posicion6,&posicion7,&posicion8,&posicion9,&posicion10,&posicion11,&posicion12,&posicion13,&posicion14,&posicion15,&posicion16,&posicion17,&posicion18,&posicion19,&posicion20,&posicion21,&posicion22,&posicion23,&posicion24,&posicion25);
        
        //Suma de las filas
        sumaF1 = posicion1 + posicion2 + posicion3 + posicion4 + posicion5;
        sumaF2 = posicion6 + posicion7 + posicion8 + posicion9 + posicion10;
        sumaF3 = posicion11 + posicion12 + posicion13 + posicion14 + posicion15;
        sumaF4 = posicion16 + posicion17 + posicion18 + posicion19 + posicion20;
        sumaF5 = posicion21 + posicion22 + posicion23 + posicion24 + posicion25;

        //Suma de las columnas
        sumaC1 = posicion1 + posicion6 + posicion11 + posicion16 + posicion21;
        sumaC2 = posicion2 + posicion7 + posicion12 + posicion17 + posicion22;
        sumaC3 = posicion3 + posicion8 + posicion13 + posicion18 + posicion23;
        sumaC4 = posicion4 + posicion9 + posicion14 + posicion19 + posicion24;
        sumaC5 = posicion5 + posicion10 + posicion15 + posicion20 + posicion25;

        // Posiciones Fila 1,2,3,4,5
        int f1[5] = {posicion1,posicion2,posicion3,posicion4,posicion5};
        int f2[5] = {posicion6,posicion7,posicion8,posicion9,posicion10};
        int f3[5] = {posicion11,posicion12,posicion13,posicion14,posicion15};
        int f4[5] = {posicion16,posicion17,posicion18,posicion19,posicion20};
        int f5[5] = {posicion21,posicion22,posicion23,posicion24,posicion25};

        //Posiciones Column 1,2,3,4,5
        int c1[5] = {posicion1,posicion6,posicion11,posicion16,posicion21};
        int c2[5] = {posicion2,posicion7,posicion12,posicion17,posicion22};
        int c3[5] = {posicion3,posicion8,posicion13,posicion18,posicion23};
        int c4[5] = {posicion4,posicion9,posicion14,posicion19,posicion24};
        int c5[5] = {posicion5,posicion10,posicion15,posicion20,posicion25};

        //Se aplican las restricciones con el fin de filtrar hasta registrar la(s) respuesta(s) correcta(s)
        if ((pistasF1 == sumaF1) && (pistasF2 == sumaF2) && (pistasF3 == sumaF3) && (pistasF4 == sumaF4) && (pistasF5 == sumaF5)){
            
            if ((pistasC1 == sumaC1) && (pistasC2 == sumaC2) && (pistasC3 == sumaC3) && (pistasC4 == sumaC4) && (pistasC5 == sumaC5)){

                if ((verificadorColumnasFilas(arrayFilas[0],f1)== 1) && (verificadorColumnasFilas(arrayFilas[1],f2) == 1) && (verificadorColumnasFilas(arrayFilas[2],f3) == 1) && (verificadorColumnasFilas(arrayFilas[3],f4) == 1) && (verificadorColumnasFilas(arrayFilas[4],f5) == 1)){
                    
                    if ((verificadorColumnasFilas(arrayColumnas[0],c1) == 1) && (verificadorColumnasFilas(arrayColumnas[1],c2) == 1) && (verificadorColumnasFilas(arrayColumnas[2],c3) == 1) && (verificadorColumnasFilas(arrayColumnas[3],c4) == 1) && (verificadorColumnasFilas(arrayColumnas[4],c5) == 1)){
                        
                        //Se almacena
                        int* salidaPosicion = (int*)malloc(sizeof(int)*25);
                        salidaPosicion[0] = posicion1;
                        salidaPosicion[1] = posicion2;
                        salidaPosicion[2] = posicion3;
                        salidaPosicion[3] = posicion4;
                        salidaPosicion[4] = posicion5;
                        salidaPosicion[5] = posicion6;
                        salidaPosicion[6] = posicion7;
                        salidaPosicion[7] = posicion8;
                        salidaPosicion[8] = posicion9;
                        salidaPosicion[9] = posicion10;
                        salidaPosicion[10] = posicion11;
                        salidaPosicion[11] = posicion12;
                        salidaPosicion[12] = posicion13;
                        salidaPosicion[13] = posicion14;
                        salidaPosicion[14] = posicion15;
                        salidaPosicion[15] = posicion16;
                        salidaPosicion[16] = posicion17;
                        salidaPosicion[17] = posicion18;
                        salidaPosicion[18] = posicion19;
                        salidaPosicion[19] = posicion20;
                        salidaPosicion[20] = posicion21;
                        salidaPosicion[21] = posicion22;
                        salidaPosicion[22] = posicion23;
                        salidaPosicion[23] = posicion24;
                        salidaPosicion[24] = posicion25;
                        salida[j]= salidaPosicion;
                        j+=1;          
                    }
                }
            }
        }
    }
fclose(archivoLectura);
return salida;
}

//Entrada: int*solucion (array con las soluciones), int numero(numero de la solucion)
//Función que imprime los resultados
void mostrarSolucion(int* solucion,int numero){
    printf("%d Solucion\n",numero);

    for(int i=0;i<25;i++){
        if (solucion[i] == 1){
            printf("X ");
        }
        else{
            printf("_ ");
        }

        if (((i+1 )% 5) == 0){
            printf("\n");
        }
    }
    printf("\n");
}

//Entrada: 
//Salida: int** (retorno para el main)
//Función que llama al resto de las funciones
int programa(){
    //Se crean los arreglos que almacenaran las pistas tanto de las filas como el de las columnas
    int** arrayFilas = (int**)malloc(5*sizeof(int*));
    for(int i=0;i<100;i++){
        arrayFilas[i] = (int*)malloc(5*sizeof(int));
    }
    int** arrayColumnas = (int**)malloc(5*sizeof(int*));
    for(int i=0;i<100;i++){
        arrayColumnas[i] = (int*)malloc(5*sizeof(int));
    }
    //Nombre de los archivos (filas y columnas)
    char nombreFilas[100];
    printf("\nIMPORTANTE: Recuerde agregar la extension junto al nombre del archivo\n");
    printf("Ingrese el nombre del archivo de las FILAS: ");
    scanf("%s",&nombreFilas);
    char nombreColumnas[100];
    printf("Ingrese el nombre del archivo de las COLUMNAS: ");
    scanf("%s",&nombreColumnas);
    printf("\n");

    //Se leen y se almacenan los archivos con las pistas
    lecturaArch(nombreFilas,arrayFilas);
    lecturaArch(nombreColumnas,arrayColumnas);
    //Se verifica que los valores del archivo se encuentren buenos
    
    //Filas
    if (validacionArch(arrayFilas) == 0){
        printf("Existe un error en el archivo de las columnas\n");
        printf("RECUERDE: Solamente se puede colocar 00, 01, 02, 03, 04, 05, 11, 12, 13, 21, 22 y 31\n");
        return -1;
    }
    //Columnas
    if (validacionArch(arrayColumnas) == 0){
        printf("Existe un error en el archivo de las filas\n");
        printf("RECUERDE: Solamente se puede colocar 00, 01, 02, 03, 04, 05, 11, 12, 13, 21, 22 y 31\n");
        return -1;      
    }
    printf("Se calcularan las posibles soluciones a las pistas dadas\n");
    //Se asigna un nombre para el archivo que contendra las posibles soluciones del problema
	char* nombreArchivo = "soluciones.txt";
    //Se generan todas las posibles combinaciones
    permutacion(nombreArchivo);
    //Se filtran los resultados segun las pistas entregadas
    int numeroSoluciones = contarSol(nombreArchivo,arrayFilas,arrayColumnas);
    //Se finaliza el programa en caso que no se encuentren soluciones
    if (numeroSoluciones == 0){
        printf("No se encontraron solciones a las pistas dadas\n");
        return -2;
    }
    int** soluciones = registrocontarSol(nombreArchivo,numeroSoluciones,arrayColumnas,arrayFilas);
    
    //Se muestra por pantalla las soluciones
	for(int i = 0; i < numeroSoluciones; i++){
        mostrarSolucion(soluciones[i],(i+1));
	}
    printf("El programa finalizo\n");
    free(soluciones);
    return 0;
}

int main(){

    printf(" ____    ___   ____    ___    ____  ____    ____  ___ ___   ____  _____\n");
    printf("|    \\  /   \\ |    \\  /   \\  /    ||    \\  /    ||   |   | /    |/ ___/\n");
    printf("|  _  ||     ||  _  ||     ||   __||  D  )|  o  || _   _ ||  o  (   \\_ \n");
    printf("|  |  ||  O  ||  |  ||  O  ||  |  ||    / |     ||  \\_/  ||     |\\__  |\n");
    printf("|  |  ||     ||  |  ||     ||  |_ ||    \\ |  _  ||   |   ||  _  |/  \\ |\n");
    printf("|  |  ||     ||  |  ||     ||     ||  .  \\|  |  ||   |   ||  |  |\\    |\n");
    printf("|__|__| \\___/ |__|__| \\___/ |___,_||__|\\_||__|__||___|___||__|__| \\___|\n\n");
                                                                       
    int finPrograma = 0;
    int respuestaPrograma = 0;
    while(finPrograma == 0){
        printf("\n1)Iniciar programa\n");
        printf("2)Salir del programa\n\n");
        printf("Indique la opcion (1|2):");
        int opcion;
        scanf("%d",&opcion);

        //En el caso que se desee salir del juego
        if (opcion == 2){
            printf("Gracias por usar el programa");
            finPrograma = 1;
            return 0;
        }
        else if (opcion == 1){
            respuestaPrograma = programa();
        }
    }
}