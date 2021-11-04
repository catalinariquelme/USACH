// PROFESOR DE LABORATORIO: VIOLETA CHANG
// SECCION: A-1
//
// AUTORA
// NOMBRE: Catalina Riquelme Zamora
// RUT: 20.642.812-0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

typedef struct box{
    int profesionales;//cantidad
    int pacientes;//total pacientes atendidos en un box
    int estadoSanitizacion; // 0 (No se esta sanitizando) 1 (Se esta sanitizando) 
    int sanitizacion; //cada cuantos pacientes sanitizan
    int tiempoSanitizacion; //cuanto tarda en sanitizar
    char* bitacoraBox;//bitacora hora de las personas que entran, hora sanitizacion

}
box;

typedef struct estados{
    box array[4]; //array de box
    int horaSanitizacion[4]; //hora a la empieza a sanitizar
    int id;
    int estadoAnterior;
    char* estado;
    int tiempo;//tiempo transcurrido desde el inicio
}
estados;

int correlativo;
//Entardas:
//Salida: box
//Objetivo: crear un box con sus diversos atributos
box createBox(int profesionales,int pacientes, int sanitizacion,int tiempoSanitizacion, int estadoSanitizacion,char* bitacoraBox){
    box aux;
    aux.profesionales = profesionales;
    aux.pacientes = pacientes;
    aux.estadoSanitizacion = estadoSanitizacion;
    aux.sanitizacion = sanitizacion;
    aux.estadoSanitizacion = estadoSanitizacion;
    aux.tiempoSanitizacion = tiempoSanitizacion;
    aux.bitacoraBox = bitacoraBox;
    return aux;
}

//Entardas: box1(box), box2(box), box3 (box),box4(box), int estadoAnterior,char*estado, tiempo entero
//Salida:
//Objetivo: crear nuevo estado
estados crearEstado(box box1,box box2, box box3, box box4, int estadoAnterior,char*estado, int tiempo){
    estados estadoNuevo;
    estadoNuevo.array[0] = box1;
    estadoNuevo.array[1] = box2;
    estadoNuevo.array[2] = box3;
    estadoNuevo.array[3] = box4;
    estadoNuevo.tiempo = tiempo;
    estadoNuevo.id = correlativo;
    estadoNuevo.estadoAnterior = estadoAnterior;
    estadoNuevo.estado = estado;
    correlativo = correlativo + 1;
    return estadoNuevo;
}

//Entardas: estados* lista (abiertos|cerrados),int* elementos(cantidad abiertos o cerrados), estados estado(estado actual)
//Salida: nuevaLista (lista con nuevo estado)
//Objetivo: agregar un estado
estados * agregarEstado(estados * lista, int * elementos, estados estado){
	estados * nuevaLista = (estados *)malloc(sizeof(estados)*(*elementos+1));
	for (int i = 0; i < *elementos; ++i){
		nuevaLista[i] = lista[i];
	}
	nuevaLista[*elementos] = estado;
	*elementos = *elementos+1;
	free(lista);
	return nuevaLista;
}

//Entardas: estados* lista (abiertos|cerrados),int* elementos(cantidad abiertos o cerrados)
//Salida: nuevaLista (lista con nuevo estado)
//Objetivo: sacar un elemento
estados * sacarElemento(estados * lista, int * elementos){
	estados * nuevaLista = (estados *)malloc(sizeof(estados)*(*elementos-1));
	for (int i = 1; i < *elementos; ++i){
		nuevaLista[i-1]=lista[i];
	}
	*elementos = *elementos-1;
	free(lista);
	return nuevaLista;
}

//Entardas: estados* lista(abiertos|cerrados),int elementos(cantidad abiertos o cerrados), box b(estado)
//Salida: int 1(se encuentra en la lista), int 0(no se encuentra en la lista)
//Objetivo: determinar si un estado se ecuentra en una lista(evitar repetición)
int estaEstado(estados * lista, int elementos, estados b){
	for (int i = 0; i < elementos; ++i){
		if((lista[i].array[1].profesionales == b.array[1].profesionales) && (lista[i].array[2].profesionales == b.array[2].profesionales) 
        && (lista[i].array[3].profesionales == b.array[3].profesionales) && (lista[i].array[4].profesionales == b.array[4].profesionales)
        && (lista[i].array[1].pacientes == b.array[1].pacientes) && (lista[i].array[2].pacientes == b.array[2].pacientes)
        && (lista[i].array[3].pacientes == b.array[3].pacientes) && (lista[i].array[4].pacientes == b.array[4].pacientes)
        && (lista[i].array[1].estadoSanitizacion == b.array[1].estadoSanitizacion) && (lista[i].array[2].estadoSanitizacion == b.array[2].estadoSanitizacion)
        && (lista[i].array[3].estadoSanitizacion == b.array[3].estadoSanitizacion) && (lista[i].array[4].estadoSanitizacion == b.array[4].estadoSanitizacion)
        && (lista[i].array[1].tiempoSanitizacion == b.array[1].tiempoSanitizacion) && (lista[i].array[2].tiempoSanitizacion == b.array[2].tiempoSanitizacion)
        && (lista[i].array[3].tiempoSanitizacion == b.array[3].tiempoSanitizacion) && (lista[i].array[4].tiempoSanitizacion == b.array[4].tiempoSanitizacion))
			return 1;
	}
    return 0;
}

//Entardas: estados b (estado), int tiempoTotal (tiempo total que se tiene para atender)
//Salida: int 1 (se llego al tiempo), int 0(todavia no llega al final del tiempo)
//Objetivo: determina si se cumple el tiempo total
int esFinal(estados b,int tiempoTotal){
	if( b.tiempo < tiempoTotal){
        return 0;
    }
	return 1;
}

//Entardas: estados b   
//Objetivo: mostarar el avance del estado
void imprimirEstado(estados b){
	printf("Id:%d; B1:%d, B2:%d; B3:%d, B4:%d; T:%s, tiempo %d   IdAnt:%d\n", b.id, b.array[0].profesionales, b.array[1].profesionales, 
    b.array[2].profesionales, b.array[3].profesionales,b.estado,b.tiempo, b.estadoAnterior);
    printf("SB1: %d;   SB2: %d;    SB3:%d;    SB4: %d   \n\n",b.array[0].estadoSanitizacion,b.array[1].estadoSanitizacion,
    b.array[2].estadoSanitizacion,b.array[3].estadoSanitizacion);
}

//Entardas: cantidadProfesionales (entero)
//Salida: entero (minutos que tardan)
//Objetivo: Determinar cuanto tardan n profesionales en atander a un paciente
int tiempoSegunPersonal(int cantidadProfesionales){
    if (cantidadProfesionales == 1 ){
        return 4;
    }
    else if (cantidadProfesionales == 2){
        return 2;
    }
    else if (cantidadProfesionales == 3 || cantidadProfesionales > 3){
        return 1;
    }
}

//Entardas: horaSanitizado (entero) int tiempo (entero) sanitizacion (entero)
//Salida: 1(esta sanitizado) 0 (no esta sanitizado)
//Objetivo: Preguntar si el box esta en proceso de sanitización o no
int estaSanitizado (int horaSanitizado,int tiempo,int sanitizacion){
    int tempo;
    tempo = tiempo - horaSanitizado;
    if (tempo >= sanitizacion){
        return 0;
    }
    return 1;
}

//Entardas: int* lista (vácia), minutosOriginal (entero)
//Salida: lista ([horas,minutos])
//Objetivo: pasar minutos a horas (tomando en base 540 minutos)
int minutosAHora (int *lista,int minutosOriginal){
    // Parte desde 9:00 am
    int minutosBase = 540;
    minutosOriginal = minutosBase + minutosOriginal;
    int hora =  minutosOriginal / 60;
    int minutos = minutosOriginal - (hora * 60);
    //[horas,minutos]
    lista[0] = hora;
    lista[1] = minutos;
    return *lista;
}


//VERIFICACIONES
//Entardas: estados estado(estado a analizar)
//Salida: int 1(se puede entrar al box) int 0(no se puede entrar al box)
//Objetivo: verificar si los profesionales pueden dirigirse a determinado box

// TRANSICIONES
//Entardas: estado (estados),cantidadProfesionales (entero)
//Salida: crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"",estado.tiempo);
//Objetivo: crear un estado con la transicion realizada

//BOX 0 (para entrar)
int verificarB0B1(estados estado){
    //Verifica que el box de llegada este vacio y el tiempo sea el inicial
    if(estado.array[0].profesionales == 0 && estado.tiempo == 0){
        return 1;
    }
    return 0;
}
estados B0B1(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[0].sanitizacion;
    estado.array[0].profesionales = cantidadProfesionales;
    estado.array[0].pacientes = estado.array[0].pacientes + estado.array[0].sanitizacion;
    estado.array[0].estadoSanitizacion = 1;
    estado.horaSanitizacion[0] = estado.tiempo+tiempo;

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[0].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[0].bitacoraBox = bitacora;

    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B0B1",estado.tiempo+tiempo+1);
}

int verificarB0B2(estados estado){
    //Verificar que el box de destino este vácio
    if(estado.array[1].profesionales == 0 && estado.tiempo == 0){
        return 1;
    }
    return 0;
}
estados B0B2(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[1].sanitizacion;
    estado.array[1].profesionales = cantidadProfesionales;
    estado.array[1].pacientes = estado.array[1].pacientes + estado.array[1].sanitizacion;
    estado.array[1].estadoSanitizacion = 1;
    estado.horaSanitizacion[1] = estado.tiempo+tiempo;

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[1].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[1].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B0B2",estado.tiempo+tiempo+1);
}

int verificarB0B3(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[2].profesionales == 0 && estado.tiempo == 0){
        return 1;
    }
    return 0;
}
estados B0B3(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[2].sanitizacion;
    estado.array[2].profesionales = cantidadProfesionales;
    estado.array[2].pacientes = estado.array[2].pacientes + estado.array[2].sanitizacion;
    estado.array[2].estadoSanitizacion = 1;
    estado.horaSanitizacion[2] = estado.tiempo+tiempo;

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[2].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[2].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B0B3",estado.tiempo+tiempo+1);
}

int verificarB0B4(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[3].profesionales == 0 && estado.tiempo == 0){
        return 1;
    }
    return 0;
}
estados B0B4(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[3].sanitizacion;
    estado.array[3].profesionales = cantidadProfesionales;
    estado.array[3].pacientes = estado.array[3].pacientes + estado.array[3].sanitizacion;
    estado.array[3].estadoSanitizacion = 1;
    estado.horaSanitizacion[3] = estado.tiempo+tiempo;

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[3].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[3].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B0B4",estado.tiempo+tiempo+1);
}

//BOX 1
int verificarB1B2(estados estado){
    //Verifica que el box de llegada este vacio y que el de partida existan personas en el
    if(estado.array[1].profesionales == 0 && estado.array[0].profesionales != 0 && estado.array[1].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B1B2(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[1].sanitizacion;
    estado.array[0].profesionales = 0;
    estado.array[1].profesionales = cantidadProfesionales;
    estado.array[1].pacientes = estado.array[1].pacientes + estado.array[1].sanitizacion;
    estado.array[1].estadoSanitizacion = 1;
    estado.horaSanitizacion[1] = estado.tiempo+tiempo;

    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[3].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[3],estado.tiempo+tiempo,estado.array[3].sanitizacion);


    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[1].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[1].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B1B2",estado.tiempo+tiempo+1);
}

int verificarB1B3(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[2].profesionales == 0 && estado.array[0].profesionales != 0 && estado.array[2].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B1B3(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[2].sanitizacion;
    estado.array[0].profesionales = 0;
    estado.array[2].profesionales = cantidadProfesionales;
    estado.array[2].pacientes = estado.array[2].pacientes + estado.array[2].sanitizacion;

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[2].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[2].bitacoraBox = bitacora;
    

    
    estado.array[2].estadoSanitizacion = 1; 
    estado.horaSanitizacion[2] = estado.tiempo+tiempo;

    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);
    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[3].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[3],estado.tiempo+tiempo,estado.array[3].sanitizacion);

    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B1B3",estado.tiempo+tiempo+1);
}

int verificarB1B4(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[3].profesionales == 0 && estado.array[0].profesionales != 0 && estado.array[3].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B1B4(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[3].sanitizacion;
    estado.array[0].profesionales = 0;
    estado.array[3].profesionales = cantidadProfesionales;
    estado.array[3].pacientes = estado.array[3].pacientes + estado.array[3].sanitizacion;
    estado.array[3].estadoSanitizacion = 1; 
    estado.horaSanitizacion[3] = estado.tiempo+tiempo;

    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);
    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[3].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[3].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B1B4",estado.tiempo+tiempo+1);
}

//BOX 2
int verificarB2B1(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[0].profesionales == 0 && estado.array[1].profesionales != 0 && estado.array[0].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B2B1(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[0].sanitizacion;
    estado.array[1].profesionales = 0;
    estado.array[0].profesionales = cantidadProfesionales;
    estado.array[0].pacientes = estado.array[0].pacientes + estado.array[0].sanitizacion;
    estado.array[0].estadoSanitizacion = 1; 
    estado.horaSanitizacion[0] = estado.tiempo+tiempo;

    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[3].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[3],estado.tiempo+tiempo,estado.array[3].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[0].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[0].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B2B1",estado.tiempo+tiempo+1);
}

int verificarB2B3(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[2].profesionales == 0 && estado.array[1].profesionales != 0 && estado.array[2].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B2B3(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[2].sanitizacion;
    estado.array[1].profesionales = 0;
    estado.array[2].profesionales = cantidadProfesionales;
    estado.array[2].pacientes = estado.array[2].pacientes + estado.array[2].sanitizacion;
    estado.array[2].estadoSanitizacion = 1; 
    estado.horaSanitizacion[2] = estado.tiempo+tiempo;

    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);
    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[3].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[3],estado.tiempo+tiempo,estado.array[3].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[2].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[2].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B2B3",estado.tiempo+tiempo+1);
}

int verificarB2B4(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[3].profesionales == 0 && estado.array[1].profesionales != 0 && estado.array[3].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B2B4(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[3].sanitizacion;
    estado.array[1].profesionales = 0;
    estado.array[3].profesionales = cantidadProfesionales;
    estado.array[3].pacientes = estado.array[4].pacientes + estado.array[3].sanitizacion;
    estado.array[3].estadoSanitizacion = 1; 
    estado.horaSanitizacion[3] = estado.tiempo+tiempo;

    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[3].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[3].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B2B4",estado.tiempo+tiempo+1);
}

//BOX 3
int verificarB3B1(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[0].profesionales == 0 && estado.array[2].profesionales != 0 && estado.array[0].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B3B1(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[0].sanitizacion;
    estado.array[2].profesionales = 0;
    estado.array[0].profesionales = cantidadProfesionales;
    estado.array[0].pacientes = estado.array[0].pacientes + estado.array[0].sanitizacion;
    estado.array[3].estadoSanitizacion = 1; 
    estado.horaSanitizacion[3] = estado.tiempo+tiempo;

    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[0].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[0].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B3B1",estado.tiempo+tiempo+1);
}

int verificarB3B2(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[1].profesionales == 0 && estado.array[2].profesionales != 0 && estado.array[1].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B3B2(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[1].sanitizacion;
    estado.array[2].profesionales = 0;
    estado.array[1].profesionales = cantidadProfesionales;
    estado.array[1].pacientes = estado.array[1].pacientes + estado.array[1].sanitizacion;
    estado.array[1].estadoSanitizacion = 1; 
    estado.horaSanitizacion[1] = estado.tiempo+tiempo;

    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[3].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[3],estado.tiempo+tiempo,estado.array[3].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[1].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[1].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B3B2",estado.tiempo+tiempo+1);
}

int verificarB3B4(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[3].profesionales == 0 && estado.array[2].profesionales != 0 && estado.array[3].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B3B4(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[3].sanitizacion;
    estado.array[2].profesionales = 0;
    estado.array[3].profesionales = cantidadProfesionales;
    estado.array[3].pacientes = estado.array[3].pacientes + estado.array[3].sanitizacion;
    estado.array[3].estadoSanitizacion = 1; 
    estado.horaSanitizacion[3] = estado.tiempo+tiempo;

    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[3].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[3].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B3B4",estado.tiempo+tiempo+1);
}

//BOX 4
int verificarB4B1(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[0].profesionales == 0 && estado.array[3].profesionales != 0 && estado.array[0].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B4B1(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[0].sanitizacion;
    estado.array[3].profesionales = 0;
    estado.array[0].profesionales = cantidadProfesionales;
    estado.array[0].pacientes = estado.array[0].pacientes + estado.array[0].sanitizacion;
    estado.array[3].estadoSanitizacion = 1; 
    estado.horaSanitizacion[3] = estado.tiempo+tiempo;

    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[0].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[0].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B4B1",estado.tiempo+tiempo+1);
}

int verificarB4B2(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[1].profesionales == 0 && estado.array[3].profesionales != 0 && estado.array[1].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B4B2(estados estado,int cantidadProfesionales){
    int tiempo = tiempoSegunPersonal(cantidadProfesionales)*estado.array[1].sanitizacion;
    estado.array[3].profesionales = 0;
    estado.array[1].profesionales = cantidadProfesionales;
    estado.array[1].pacientes = estado.array[1].pacientes + estado.array[1].sanitizacion;
    estado.array[1].estadoSanitizacion = 1; 
    estado.horaSanitizacion[1] = estado.tiempo+tiempo;

    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);
    estado.array[2].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[2],estado.tiempo+tiempo,estado.array[2].sanitizacion);
    estado.array[3].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[3],estado.tiempo+tiempo,estado.array[3].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[1].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[1].bitacoraBox = bitacora;
    
    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B4B2",estado.tiempo+tiempo+1);
}

int verificarB4B3(estados estado){
    //Verificar que los profesionales no se encuentren antes en el box
    if(estado.array[2].profesionales == 0 && estado.array[3].profesionales != 0 && estado.array[2].estadoSanitizacion == 0){
        return 1;
    }
    return 0;
}
estados B4B3(estados estado,int cantidadProfesionales){
    int tiempo =  tiempoSegunPersonal(cantidadProfesionales)*estado.array[2].sanitizacion;
    estado.array[3].profesionales = 0;
    estado.array[2].profesionales = cantidadProfesionales;
    estado.array[2].pacientes = estado.array[2].pacientes + estado.array[2].sanitizacion;
    estado.array[2].estadoSanitizacion = 1; 
    estado.horaSanitizacion[2] = estado.tiempo+tiempo;

    estado.array[0].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[0],estado.tiempo+tiempo,estado.array[0].sanitizacion);
    estado.array[1].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[1],estado.tiempo+tiempo,estado.array[1].sanitizacion);
    estado.array[3].estadoSanitizacion = estaSanitizado(estado.horaSanitizacion[3],estado.tiempo+tiempo,estado.array[3].sanitizacion);

    //Tiempo al entrar al box
    int tEntrada = estado.tiempo;
    int tSalida = estado.tiempo+tiempo;
    int tSanitizacion = tSalida + estado.array[2].sanitizacion;//A que hora se terminará de sanitizar
    //[horas,minutos] lista que alamacena horas y minutos
    int listaHoraEntrada[2];
    int listaHoraSalida[2];
    int listaHoraSanitizacion[2];//Hasta que hora se estará sanitizando el box
    //Se pasa a horas y minutos el tiempo de entrada y salida
    minutosAHora(listaHoraEntrada,tEntrada);
    minutosAHora(listaHoraSalida,tSalida);
    minutosAHora(listaHoraSanitizacion,tSanitizacion);
    //Concatenar toda la información
    char bitacora[60];
    sprintf(bitacora,"%d:%d  %d:%d || %d:%d  %d:%d  SANITIZACION ",listaHoraEntrada[0],listaHoraEntrada[1],
    listaHoraSalida[0],listaHoraSalida[1],listaHoraSalida[0],listaHoraSalida[1],listaHoraSanitizacion[0],listaHoraSanitizacion[0]);
    //Se alamcena
    estado.array[2].bitacoraBox = bitacora;

    return crearEstado(estado.array[0],estado.array[1],estado.array[2],estado.array[3],estado.id,"B4B3",estado.tiempo+tiempo+1);
}

//Entardas: lista(estados), ultimo (entero)
//Objetivo: mostar por pantalla los movimientos
void mostrarSolucion(estados * lista, int ultimo){

    int ultimo2 = ultimo;
    int pacientes = lista[ultimo].array[0].pacientes + lista[ultimo].array[1].pacientes + lista[ultimo].array[2].pacientes + lista[ultimo].array[3].pacientes;

    printf("\nPacientes atendidos: %d\n",pacientes);
    printf("Tiempo: %d\n",lista[ultimo].tiempo);
    printf("De atras hacia adelante\n");
    printf("Los movimientos del grupo de profesionales son: \n");
    
    while(lista[ultimo].id != 0){
        printf("-");
        if (lista[ultimo].estado == "B0B1"){
            printf("B0B1");
        }
        else if(lista[ultimo].estado == "B0B2"){
            printf("B0B2");
        }
        else if(lista[ultimo].estado == "B0B3"){
            printf("B0B3");
        }
        else if(lista[ultimo].estado == "B0B4"){
            printf("B0B4");
        }
        else if(lista[ultimo].estado == "B1B2"){
            printf("B1B2");
        }
        else if(lista[ultimo].estado == "B1B3"){
            printf("B1B3");
        }
        else if(lista[ultimo].estado == "B1B4"){
            printf("B1B4");
        }
        else if(lista[ultimo].estado == "B2B1"){
            printf("B2B1");
        }
        else if(lista[ultimo].estado == "B2B3"){
            printf("B2B3");
        }
        else if(lista[ultimo].estado == "B2B4"){
            printf("B2B4");
        }
        else if(lista[ultimo].estado == "B3B1"){
            printf("B3B1");
        }
        else if(lista[ultimo].estado == "B3B2"){
            printf("B3B2");
        }
        else if(lista[ultimo].estado == "B3B4"){
            printf("B3B4");
        }
        else if(lista[ultimo].estado == "B4B1"){
            printf("B4B1");
        }
        else if(lista[ultimo].estado == "B4B2"){
            printf("B4B2");
        }
        else if(lista[ultimo].estado == "B4B3"){
            printf("B4B3");
        }
        else{
            printf("Algo no calza\n");
        }

        ultimo = lista[ultimo].estadoAnterior;
	}


    //printf("\n%s \n",lista[ultimo2].array[0].bitacoraBox);
    //Aqui deberia imprimir el hroario almacenado en bitacoraBox de cada box pero no logre hacer que funcionará
    //Posterior a eso se escribiría con una función escribir en diversos archivos


}


int main(){
    //En caso que se requiera medir el tiempo de ejecución del programa
    //clock_t start, finish, duration;
    //start = clock();
    printf("Campana de vacunacion\n");
    int tiempoTotal = 240; //minutos -> 3 horas (9:00- 13:00)
    int numeroProfesionales;
    printf("Ingrese numero de profesionales: ");
    scanf("%d",&numeroProfesionales);
    //Estado inicales de los box
    box box1 = createBox(0,0,12,4,0,"B1 ");
    box box2 = createBox(0,0,12,4,0,"B2 ");
    box box3 = createBox(0,0,21,6,0,"B3 ");
    box box4 = createBox(0,0,27,8,0,"B4 ");
    
    correlativo = 0;
    //Variable para guardar la cantidad estados se encuentran dentro del arreglo abiertos
    int canAbiertos = 0;
    //Variable para guardar la cantidad estados se encuentran dentro del arreglo cerrados
    int canCerrados = 0;
    estados bActual, bSiguiente;
    estados * abiertos = (estados *)malloc(sizeof(estados)*canAbiertos);
    estados * cerrados = (estados *)malloc(sizeof(estados)*canCerrados);
    //Estados iniciales de los estados
    estados inicial = crearEstado(box1,box2,box3,box4,correlativo,"",0);
    //En abiertos se agregar el estado inical
    abiertos = agregarEstado(abiertos, &canAbiertos, inicial);
    //Mientras queden estados abiertos se ejecutará
    while(canAbiertos > 0){
        bActual = abiertos[0];
        abiertos = sacarElemento(abiertos, &canAbiertos);
        cerrados = agregarEstado(cerrados, &canCerrados, bActual);
        
        //Estado final
        if(esFinal(bActual,tiempoTotal) == 1){
            
            //finish = clock();
            //printf("process() took %f seconds to execute\n", ((double) (finish - start)) / CLOCKS_PER_SEC );
            mostrarSolucion(cerrados,canCerrados-1);
            
            return 0;
        }

        else{
            //BOX 0
            if (verificarB0B1(bActual) == 1){
                bSiguiente = B0B1(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }      
            if (verificarB0B2(bActual) == 1){
                bSiguiente = B0B2(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }
            if (verificarB0B3(bActual) == 1){
                bSiguiente = B0B3(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }
            if (verificarB0B4(bActual) == 1){
                bSiguiente = B0B4(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }
            
            //BOX 1
            if (verificarB1B2(bActual) == 1){
                bSiguiente = B1B2(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }
            if (verificarB1B3(bActual) == 1){
                bSiguiente = B1B3(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }
            if (verificarB1B4(bActual) == 1){
                bSiguiente = B1B4(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }
            
            //BOX 2
            if (verificarB2B1(bActual) == 1){
                bSiguiente = B2B1(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }        
            if (verificarB2B3(bActual) == 1){
                bSiguiente = B2B3(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }        
            if (verificarB2B4(bActual) == 1){
                bSiguiente = B2B4(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }        
            
            //BOX 3
            if (verificarB3B1(bActual) == 1){
                bSiguiente = B3B1(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }        
            if (verificarB3B2(bActual) == 1){
                bSiguiente = B3B2(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }      
            if (verificarB3B4(bActual) == 1){
                bSiguiente = B3B4(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }        

            //BOX 4
            if (verificarB4B1(bActual) == 1){
                bSiguiente = B4B1(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }        
            if (verificarB4B2(bActual) == 1){
                bSiguiente = B4B2(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }
            if (verificarB4B3(bActual) == 1){
                bSiguiente = B4B3(bActual,numeroProfesionales);

                if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
                    abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
                }else{
                    correlativo = correlativo - 1;
                }
            }

        }
        /*
		printf("ABIERTOS:");
		for (int i = 0; i < canAbiertos; ++i)
		{
			imprimirEstado(abiertos[i]);
		}
		
		printf("\nCERRADOS:");
		for (int i = 0; i < canCerrados; ++i)
		{
			imprimirEstado(cerrados[i]);
		}
		printf("\n\n");*/

        /*  realizar un doble ciclo, para los box y los los profesionales, 
        generando así todas la combinaciones posibles respecto a la sub division de grupos dado un número mayor a 3
        para que sea optimo en esos caso el proceso de asignamiento de box*/
	}
	
}