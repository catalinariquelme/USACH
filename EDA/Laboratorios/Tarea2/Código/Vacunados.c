// PROFESOR DE LABORATORIO: VIOLETA CHANG
// SECCION: A-1
//
// AUTORA
// NOMBRE: Catalina Riquelme Zamora
// RUT: 20.642.812-0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vacunados1D.h"
#include "vacunados2D.h"
#include "vacunas.h"

typedef struct year{
  int enero;
  int febrero;
  int marzo;
  int abril;
  int mayo;
  int junio;
  int julio;
  int agosto;
  int septiembre;
  int octubre;
  int noviembre; 
  int diciembre;
  
}year;


time_t mktime(struct tm *timeptr);

/*
Entardas: fecha(fecha a modificar)
Salida: fechaSalida(int*)
Objetivo: convierte de char a int* una fecha
*/
int* convertirFecha(char fecha[80]){
  int* fechaSalida = (int*)malloc(sizeof(int)*3);
  char* token;
  //Se separa a tráves de /
  token = strtok(fecha, "/");
  int i = 0;
  fechaSalida[i] = atoi(token);
  i++;
  while (token!= NULL){
    token = strtok(NULL,"/");
    if (token != NULL){
      fechaSalida[i] = atoi(token);
      i++;
    }
  }
  return fechaSalida;
}

/*
Entradas: date fecha(fecha inicial)
Salida: date fecha(fecha tras determinado tiempo)
Objetivo: calcular la fecha tras n semanas
*/
int* proximaVacuna(int *fecha,int semanas){
  //Se utiliza mktime de la libreria time para calcular proxima dosis
   int ret;
   struct tm info;
   char buffer[80];
   info.tm_year = fecha[2]+ 2000 - 1900;
   info.tm_mon = fecha[1];
   info.tm_mday = fecha[0] + (semanas*7);
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 0;
   info.tm_isdst = 0;

   ret = mktime(&info);
   int* fechaSalida = (int*)malloc(sizeof(int)*3);
   if( ret == -1 ) {
      printf("Error: mktime\n");
   } else {
      strftime(buffer, sizeof(buffer), "%c", &info );
      fechaSalida = convertirFecha(buffer);
   }
   return fechaSalida;
}

/*
Entardas: nombre(nombre del archivo a leer), lista(cabeza de la lista)
Salida: -
Objetivo: leer y almacenar en una lista enlazada
*/
void lecturaVacunados1D(char* nombre,nodo1D* lista){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunados1D;
  fscanf(arch,"%d",&cantidadVacunados1D);
  while(feof(arch) == 0){
    vacunados1dosis vacunados;
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));
    char aux5[80];
    char* aux6 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    vacunados.rut = aux;
    vacunados.nombre = aux2;
    vacunados.apellido = aux3;
    vacunados.edad = aux4;
    strcpy(vacunados.fecha1dosis,aux5);
    vacunados.idVacuna = aux6;
    printf("Fecha %s\n",vacunados.fecha1dosis);
    insertarNodoFinal1D(lista,vacunados);
  }
  fclose(arch);
}

/*
Entardas: nombre(nombre del archivo a leer), lista(cabeza de la lista)
Salida: -
Objetivo: leer y almacenar en una lista enlazada
*/
void lecturaVacunados2D(char* nombre,nodo2D* lista){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunados2D;
  fscanf(arch,"%d",&cantidadVacunados2D);
  int i =0;
  while(feof(arch) == 0){
    vacunados2dosis vacunados;
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));
    char* aux5 = (char*)malloc(100*sizeof(char));
    char* aux6 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    vacunados.rut = aux;
    vacunados.nombre = aux2;
    vacunados.apellido = aux3;
    vacunados.edad = aux4;
    vacunados.fecha2dosis = aux5;
    vacunados.idVacuna = aux6;

    insertarNodoFinal2D(lista,vacunados);
  }

  fclose(arch);
}

/*
Entardas: nombre(nombre del archivo a leer), lista(cabeza de la lista)
Salida: -
Objetivo: leer y almacenar en una lista enlazada
*/
void lecturaVacunas(char* nombre,nodoVacunas* lista){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunas;
  fscanf(arch,"%d",&cantidadVacunas);
  int i =0;
  while(feof(arch) == 0){
    vacunas vacunasExistentes;
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s",aux,aux2,aux3,aux4);
    vacunasExistentes.numero = aux;
    vacunasExistentes.nombre = aux2;
    vacunasExistentes.fabricante = aux3;
    vacunasExistentes.periodo = aux4;
    insertarNodoFinalVacunas(lista,vacunasExistentes);
  }

  fclose(arch);
}

/*
Entardas: inicio(cabeza de la lista)
Salida: -
Objetivo: aplica bubblesort sobre una lista con el fin de ordenar de manera ascendente por nombre
*/
void ordenAbecedarioNombre(struct nodo1D *inicio){
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    if (inicio == NULL)
      return;

    do{
      swapped = 0;
      nodo1 = inicio;
      while (nodo1->siguiente != nodo2){
        int ret = strcmp(nodo1->vacunados1D.nombre,nodo1->siguiente->vacunados1D.nombre);
        if (ret>0){ 
            intercambio1D(nodo1, nodo1->siguiente);
            return;
            swapped = 1;
        }
        else{
          return;
        }
        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

/*
Entardas: inicio(cabeza de la lista)
Salida: -
Objetivo: aplica bubblesort sobre una lista con el fin de ordenar de manera ascendente por apellido
*/
void ordenAbecedarioApellido(struct nodo1D *inicio){
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    do{
      swapped = 0;
      nodo1 = inicio;
      while (nodo1->siguiente != nodo2){
        int ret = strcmp(nodo1->vacunados1D.apellido,nodo1->siguiente->vacunados1D.apellido);
        if (ret == 0){
          ordenAbecedarioNombre(nodo1);
        }
        else if (ret > 0){ 
          intercambio1D(nodo1, nodo1->siguiente);
          return;
          swapped = 1;
        }
        else{
          return;
        }
        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

/*
Entardas: inicio(cabeza de la lista)
Salida: -
Objetivo: aplica bubblesort sobre una lista con el fin de ordenar de manera ascendente por año
*/
void ordenCronologicoYear(struct nodo1D *inicio){
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    do{
      swapped = 0;
      nodo1 = inicio->siguiente;
      while (nodo1->siguiente != nodo2){
        
        nodo1D *aux = nodo1;
        int* fecha = (int*)malloc(sizeof(int)*3);
        char fechaChar[80];
        strcpy(fechaChar,aux->vacunados1D.fecha1dosis);
        fecha = convertirFecha(fechaChar);

        int* fecha2 = (int*)malloc(sizeof(int)*3);
        char fecha2Char[80];
        strcpy(fecha2Char,aux->siguiente->vacunados1D.fecha1dosis);
        fecha2 = convertirFecha(fecha2Char);

        if (fecha[2]>fecha2[2]){ 
          intercambio1D(nodo1, nodo1->siguiente);
          swapped = 1;
        }

        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

/*
Entardas: inicio(cabeza de la lista)
Salida: -
Objetivo: aplica bubblesort sobre una lista con el fin de ordenar de manera ascendente por mes
*/
void ordenCronologicoMes(struct nodo1D *inicio){
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    do{
      swapped = 0;
      nodo1 = inicio->siguiente;
      while (nodo1->siguiente != nodo2){
        
        nodo1D *aux = nodo1;
        int* fecha = (int*)malloc(sizeof(int)*3);
        char fechaChar[80];
        strcpy(fechaChar,aux->vacunados1D.fecha1dosis);
        fecha = convertirFecha(fechaChar);

        int* fecha2 = (int*)malloc(sizeof(int)*3);
        char fecha2Char[80];
        strcpy(fecha2Char,aux->siguiente->vacunados1D.fecha1dosis);
        fecha2 = convertirFecha(fecha2Char);
        if (fecha[2] == fecha2[2]){
          if (fecha[1]>fecha2[1]){ 
            intercambio1D(nodo1, nodo1->siguiente);
            swapped = 1;
          }
        }
        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

/*
Entardas: inicio(cabeza de la lista)
Salida: -
Objetivo: aplica bubblesort sobre una lista con el fin de ordenar de manera ascendente por dia
*/
void ordenCronologicoDia(struct nodo1D *inicio){
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    do{
      swapped = 0;
      nodo1 = inicio->siguiente;
      while (nodo1->siguiente != nodo2){
        
        nodo1D *aux = nodo1;
        int* fecha = (int*)malloc(sizeof(int)*3);
        char fechaChar[80];
        strcpy(fechaChar,aux->vacunados1D.fecha1dosis);
        fecha = convertirFecha(fechaChar);

        int* fecha2 = (int*)malloc(sizeof(int)*3);
        char fecha2Char[80];
        strcpy(fecha2Char,aux->siguiente->vacunados1D.fecha1dosis);
        fecha2 = convertirFecha(fecha2Char);
        if (fecha[2] == fecha2[2]){
          if (fecha[1] == fecha2[1]){
            if (fecha[0]==fecha2[0]){
              ordenAbecedarioApellido(nodo1);
            }
            else if (fecha[0]>fecha2[0]){ 
              intercambio1D(nodo1, nodo1->siguiente);
              swapped = 1;
            }
          }
        }
        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

/*
Entardas: inicio(cabeza de la lista),buffer(id vauncuna)
Salida: int(semanas para poner segunda dosis)
Objetivo: dada el id de la vacuna busca en la lista el periodo y lo retorna
*/
int peridoSegunVacuna(nodoVacunas *lista,char* buffer){
  if (!esListaVaciaVcunas(lista)){
    nodoVacunas* auxiliar=lista->siguiente;
    while (auxiliar!=NULL){
      if (strcmp(buffer, auxiliar->vacunas.numero)==0){
        return(atoi(auxiliar->vacunas.periodo));
      }
      auxiliar=auxiliar->siguiente;
    }
  }
}

/*
Entardas: inicio(cabeza de la lista),buffer(id vauncuna)
Salida: int(semanas para poner segunda dosis)
Objetivo: dada el id de la vacuna busca en la lista el nombre y lo retorna
*/
char* nombreSegunVacuna(nodoVacunas *lista,char* buffer){
  if (!esListaVaciaVcunas(lista)){
    nodoVacunas* auxiliar=lista->siguiente;
    while (auxiliar!=NULL){
      if (strcmp(buffer, auxiliar->vacunas.numero)==0){
        return(auxiliar->vacunas.nombre);
      }
      auxiliar=auxiliar->siguiente;
    }
  }
}

/*
Entardas: inicio(cabeza de la lista),vacunasPorMes(estructura con el número de vacuanas por mes),inicioVacuna(cabeza lista vacunas)
Salida: -
Objetivo: escribe el el listado de personas con primera dosis
*/
void salidaListado(nodo1D *inicio,year vacunasPorMes,nodoVacunas *inicioVacunas){
  FILE* arch;
  arch = fopen("listado.out","w");
  if (!esListaVacia1D(inicio)){
    nodo1D* auxiliar=inicio->siguiente;
    int mes1 = -1;
    while (auxiliar!=NULL){
      int mes;

      int* fecha = (int*)malloc(sizeof(int)*3);
      char fechaChar[80];
      strcpy(fechaChar,auxiliar->vacunados1D.fecha1dosis);
      fecha = convertirFecha(fechaChar);
      mes = fecha[1];
      if (mes != mes1){
        mes1 = mes;
        if (mes == 1){
          fputs("Enero: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.enero,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        
        else if (mes == 2){
          fputs("Febrero: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.febrero,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 3){
          fputs("Marzo: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.marzo,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 4){
          fputs("Abril: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.abril,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 5){
          fputs("Mayo: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.mayo,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 6){
          fputs("Junio: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.junio,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 7){
          fputs("Julio: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.julio,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 8){
          fputs("Agosto: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.agosto,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 9){
          fputs("Agosto: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.septiembre,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 10){
          fputs("Octubre: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.octubre,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 11){
          fputs("Noviembre: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.noviembre,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
        else if (mes == 12){
          fputs("Diciembre: ",arch);
          char buffer[20];
          itoa(vacunasPorMes.diciembre,buffer,10);
          fputs(buffer,arch);
          fputs("\n",arch);
        }
      }

      fputs(auxiliar->vacunados1D.rut,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.nombre,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.apellido,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.edad,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.fecha1dosis,arch);
      fputs(" ",arch);

      //Se calcula la próxima vacuna
      int* fecha1 = (int*)malloc(sizeof(int)*3);
      char fechaChar1[80];
      strcpy(fechaChar1,auxiliar->vacunados1D.fecha1dosis);
      fecha1 = convertirFecha(fechaChar1);
      int* fechaSalida = (int*)malloc(sizeof(int)*3);
      //Se busca el periodo en las lista que contiene todas las vacunas
      int periodo = peridoSegunVacuna(inicioVacunas,auxiliar->vacunados1D.idVacuna);
      fechaSalida = proximaVacuna(fecha1,periodo);

      //S escribe la fecha pbtenida en el archivo
      char buffer[20];
      itoa(fechaSalida[0],buffer,10);
      fputs(buffer,arch);
      fputs("/",arch);
      itoa(fechaSalida[1],buffer,10);
      fputs(buffer,arch);
      fputs("/",arch);
      itoa(fechaSalida[2],buffer,10);
      fputs(buffer,arch);
      fputs("/",arch);
      fputs(" ",arch);

      //Se busca nombre de las vacunas
      char*nombre = nombreSegunVacuna(inicioVacunas,auxiliar->vacunados1D.idVacuna);
      fputs(nombre,arch);
      fputs("\n",arch);
      auxiliar=auxiliar->siguiente;
    }
  }
  fclose(arch);
}
/*
Entradas: nodo2D *inicio(cabeza lista vacunados con dos dosis), nodo1D *inicio(cabeza lista vacunados con una dosis),*inicioVacunas(cabeza lista vacunados)
Salida: -
Objetivo: escribir .out que contenga las personas que tengan una vacunación completa
*/
void salidaVacunacionCompleta(nodo2D *inicio, nodo1D *inicio1D,nodoVacunas *inicioVacunas){
  FILE* arch;
  arch = fopen("vacunacionCompleta.out","w");
  if (!esListaVacia2D(inicio)){
    nodo2D* auxiliar=inicio->siguiente;
    while (auxiliar!=NULL){
      fputs(auxiliar->vacunados2D.rut,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados2D.nombre,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados2D.apellido,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados2D.edad,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados2D.fecha2dosis,arch);
      fputs(" ",arch);
      //Se busca nombre de las vacunas
      char*nombre = nombreSegunVacuna(inicioVacunas,auxiliar->vacunados2D.idVacuna);
      fputs(nombre,arch);
      fputs("\n",arch);

      //Se busca si la persona fue vacunada en el mismo recinto con la primera dosis
      nodo1D* inicio2=inicio1D;
      nodo2D* persona=auxiliar;
      if (!esListaVacia1D(inicio1D)){
      nodo1D* auxiliar2=inicio1D;
        while (auxiliar2!=NULL){
          if (strcmp(auxiliar2->vacunados1D.rut,persona->vacunados2D.rut)== 0){
            fputs(auxiliar2->vacunados1D.rut,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.nombre,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.apellido,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.edad,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.fecha1dosis,arch);
            fputs(" ",arch);
            //Se busca nombre de las vacunas
            char*nombre = nombreSegunVacuna(inicioVacunas,auxiliar2->vacunados1D.idVacuna);
            fputs(nombre,arch);
            fputs("\n",arch);

            break;
          }
          auxiliar2=auxiliar2->siguiente;
        }
      }
      auxiliar=auxiliar->siguiente;
    }
  }
  fclose(arch);
}

/*
Entardas: mes(numero mes), meses(estructura con los meses)
Salida: estructura year
Objetivo: dado un mes, aumenta en uno en la estructura dependiendo del mes
*/
year aumentoMes(int mes,year meses){
  if (mes==1){
    meses.enero = meses.enero + 1;
  }
  else if(mes==2){
    meses.febrero = meses.febrero + 1;
  }
  else if(mes==3){
    meses.marzo = meses.marzo + 1;
  }
  else if(mes==4){
    meses.abril = meses.abril + 1;
  }
  else if(mes==5){
    meses.mayo = meses.mayo + 1;
  }
  else if(mes==6){
    meses.junio = meses.junio + 1;
  }
  else if(mes==7){
    meses.julio = meses.julio + 1;
  }
  else if(mes==8){
    meses.agosto = meses.agosto + 1;
  }
  else if(mes==9){
    meses.septiembre = meses.septiembre + 1;
  }
  else if(mes==10){
    meses.octubre = meses.octubre + 1;
  }
  else if(mes==11){
    meses.noviembre = meses.noviembre + 1;
  }
  else if(mes==12){
    meses.diciembre = meses.diciembre +1;
  }
  return meses;
}

/*
Entardas: lista(cabeza lista), vacunasPorMes(eestructura con los vacunas por mes)
Salida: estructura year
Objetivo: dada una lista almacena las vacunas por mes en la estructura
*/
year vacunasMes(nodo1D *lista,year vacunasPorMes){
  if (!esListaVacia1D(lista)){
    nodo1D* auxiliar=lista;
    //Se recorre la lista que neceseitarán una segunda dosis (vacunados con una dosis)
    while (auxiliar!=NULL){
      int* fecha = (int*)malloc(sizeof(int)*3);
      char fechaChar[80];
      strcpy(fechaChar,auxiliar->vacunados1D.fecha1dosis);
      fecha = convertirFecha(fechaChar);
      //Se calcula en que fecha debe ser administrada la segunda dosis 
      vacunasPorMes = aumentoMes(fecha[1],vacunasPorMes);
      auxiliar=auxiliar->siguiente;
    }
  }
  return vacunasPorMes;
}

/*
Entardas: lista(cabeza lista una dosis), inicioVacunas(cabeza lista vacunas)
Salida: estructura year
Objetivo: dada una lista almacena las vacunas que se deberán admkinistrar por mes en la estructura
*/
year calculoProvision(nodo1D *lista,nodoVacunas *inicioVacunas){
  year provisiones;
  provisiones.enero = 0;
  provisiones.febrero = 0;
  provisiones.marzo = 0;
  provisiones.abril = 0;
  provisiones.mayo = 0;
  provisiones.junio = 0;
  provisiones.julio = 0;
  provisiones.agosto = 0;
  provisiones.septiembre = 0;
  provisiones.octubre = 0;
  provisiones.noviembre = 0;
  provisiones.diciembre = 0;
  //Se recorre la lista con una dosis calculando cuando será la proxima dosis y almacenandola en el mes
  //que corresponde
  if (!esListaVacia1D(lista)){
    nodo1D* auxiliar=lista->siguiente;
    //Se recorre la lista que neceseitarán una segunda dosis (vacunados con una dosis)
    while (auxiliar!=NULL){
      //Se calcula la próxima vacuna
      int* fecha1 = (int*)malloc(sizeof(int)*3);
      char fechaChar1[80];
      strcpy(fechaChar1,auxiliar->vacunados1D.fecha1dosis);
      fecha1 = convertirFecha(fechaChar1);
      int* fechaSalida = (int*)malloc(sizeof(int)*3);
      //Se busca el periodo en las lista que contiene todas las vacunas
      int periodo = peridoSegunVacuna(inicioVacunas,auxiliar->vacunados1D.idVacuna);
      //Se calcula fecha segunda dosis
      fechaSalida = proximaVacuna(fecha1,periodo);
      //Se almacena en la estructura
      provisiones= aumentoMes(fechaSalida[0],provisiones);
      auxiliar=auxiliar->siguiente;

    }
  }
  return provisiones;
}

void salidaProvisiones( year provisiones){
  FILE* arch;
  arch = fopen("provision.out","w");
  if(provisiones.enero !=0){
    fputs("Enero: ",arch);
    char buffer[20];
    itoa(provisiones.enero,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }
  if(provisiones.febrero !=0){
    fputs("Febrero: ",arch);
    char buffer[20];
    itoa(provisiones.febrero,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }
  if(provisiones.marzo !=0){
    fputs("Marzo: ",arch);
    char buffer[20];
    itoa(provisiones.marzo,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.abril !=0){
    fputs("Abril: ",arch);
    char buffer[20];
    itoa(provisiones.abril,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.mayo !=0){
    fputs("Mayo: ",arch);
    char buffer[20];
    itoa(provisiones.mayo,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.junio !=0){
    fputs("Junio: ",arch);
    char buffer[20];
    itoa(provisiones.junio,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.julio !=0){
    fputs("Julio: ",arch);
    char buffer[20];
    itoa(provisiones.julio,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.agosto !=0){
    fputs("Agosto: ",arch);
    char buffer[20];
    itoa(provisiones.agosto,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.septiembre !=0){
    fputs("Septiembre: ",arch);
    char buffer[20];
    itoa(provisiones.septiembre,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.octubre !=0){
    fputs("Octubre: ",arch);
    char buffer[20];
    itoa(provisiones.octubre,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.noviembre !=0){
    fputs("Noviembre: ",arch);
    char buffer[20];
    itoa(provisiones.noviembre,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  if(provisiones.diciembre !=0){
    fputs("Diciembre: ",arch);
    char buffer[20];
    itoa(provisiones.diciembre,buffer,10);
    fputs(buffer,arch);
    fputs("\n",arch);
  }  
  fclose(arch);
}

int main(){
  clock_t start, finish, duration;
  start = clock();
  nodo1D* vacunados1D=(nodo1D*)malloc(sizeof(nodo1D));
  lecturaVacunados1D("vacunados1D.in",vacunados1D);

  nodo2D* vacunados2D=(nodo2D*)malloc(sizeof(nodo2D));
  lecturaVacunados2D("vacunados2D.in",vacunados2D);

  nodoVacunas* vacunasE=(nodoVacunas*)malloc(sizeof(nodoVacunas));
  lecturaVacunas("vacunas.in",vacunasE);

  //Se ordenan de manera cornologica la lista vacunados con una dosis (vacunados1D)
  ordenCronologicoYear(vacunados1D);
  ordenCronologicoMes(vacunados1D);
  ordenCronologicoDia(vacunados1D);

  year vacunasPorMes;
  vacunasPorMes.enero = 0;
  vacunasPorMes.febrero = 0;
  vacunasPorMes.marzo = 0;
  vacunasPorMes.abril = 0;
  vacunasPorMes.mayo = 0;
  vacunasPorMes.junio = 0;
  vacunasPorMes.julio = 0;
  vacunasPorMes.agosto = 0;
  vacunasPorMes.septiembre = 0;
  vacunasPorMes.octubre = 0;
  vacunasPorMes.noviembre = 0;
  vacunasPorMes.diciembre = 0;

  vacunasPorMes = vacunasMes(vacunados1D,vacunasPorMes);

  printf("\n\nESTADO ESCRITURA ARCHIVOS\n\n");

  salidaListado(vacunados1D,vacunasPorMes,vacunasE);
  printf("Lista.out escrito\n");
  salidaVacunacionCompleta(vacunados2D,vacunados1D,vacunasE);
  printf("VacunacionCompleta.out escrito\n");
  year provisiones = calculoProvision(vacunados1D,vacunasE);
  salidaProvisiones(provisiones);
  printf("Provision.out escrito\n");
  //finish = clock();
  //printf("process() took %f seconds to execute\n", ((double) (finish - start)) / CLOCKS_PER_SEC );
  return 0;
}