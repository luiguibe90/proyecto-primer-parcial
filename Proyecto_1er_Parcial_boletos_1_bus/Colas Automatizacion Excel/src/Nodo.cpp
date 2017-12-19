/******************************************************
*       UNIVERSIDAD DE LAS FUERZAS ARMADAS           **
*                    ESPE                            **
*                                                    **
*                   COLAS                            **
*                                                    **
*                                                    **
*Autor:                                              **
*       Benitez Rodriguez Luis Guillermo             **
*                                                    **
*Fecha de Creacion: 2017-12-16                       **
*Carrera: Ingenieria en Sistemas e Informatica       **
*Profesor: Ing Fernando Solis                        **
*******************************************************/
#include "Nodo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13
#define fondo 3
#define texto 10
Nodo::Nodo()
{
    //ctor
}

Nodo::~Nodo()
{
    //dtor
}



int Nodo::ObtenerEnteroPositivo(){
    color(fondo,texto);
    char digito,cadenaDelEntero[5];
    int entero,iterador=0;
    while((digito=getch())!=13||iterador==0){
        if(digito>='0'&&digito<='9'&&iterador<5){
            printf("%c",digito);
            cadenaDelEntero[iterador++]=digito;
        }
        if(iterador==5)
            break;
    }
    cadenaDelEntero[iterador]='\0';
    return entero=atoi(cadenaDelEntero);
}
bool Nodo::cola_vacia(Nodo *frente){//funcion para determinar si la cola esta vacia
    //esto
    return (frente==NULL)? true:false;
    //o

    /*
    if(frente==NULL)
    {
        return true;
    }
    else{
        return false;
    }*/
}
void Nodo::insertarDatoCola(Nodo *&frente,Nodo *&fin,int clientes){//insertar dato cola
    int c=1,tiempoLL,tiempoSer,auxTLLegadaAnterior,auxTSalidaClienteAnterior,auxTLLegadaAnterior1,auxTSalidaClienteAnterior1;
    for(int i=0;i<clientes;i++)
    {
        //1ero  crear nuevo nodo y Asignar Espacio
        Nodo *nuevo_nodo=new (Nodo);
        if(c==1)
        {
            tiempoLL=1 + rand() % (25);
             //2do asignar a nuevo nodo el dato
            nuevo_nodo->tLLegada=tiempoLL;
            auxTLLegadaAnterior=nuevo_nodo->tLLegada;//
            nuevo_nodo->tEsperaCliente=0;
            nuevo_nodo->tDescansoCajero=0;
            tiempoSer=1 + rand() % (16);
            nuevo_nodo->tServicio=tiempoSer;
            nuevo_nodo->tSalidaCliente=nuevo_nodo->tLLegada+nuevo_nodo->tEsperaCliente+nuevo_nodo->tServicio;
            auxTSalidaClienteAnterior=nuevo_nodo->tSalidaCliente;//
            nuevo_nodo->tEntreLlegadaCliente=nuevo_nodo->tLLegada;
            //
            nuevo_nodo->siguiente=NULL;

            //3ero ver si cola esta vacia o no

            if(cola_vacia(frente))
            {
                frente=nuevo_nodo;
            }
            else
            {
                fin->siguiente=nuevo_nodo;
            }
            c++;
        }
        else
        {
            if(c==2)
            {
               tiempoLL=1 + rand() % (25);
                 //2do asignar a nuevo nodo el dato
                nuevo_nodo->tLLegada=tiempoLL+auxTLLegadaAnterior;
                auxTLLegadaAnterior1=nuevo_nodo->tLLegada;
                if(auxTSalidaClienteAnterior>nuevo_nodo->tLLegada)
                {
                    nuevo_nodo->tEsperaCliente=auxTSalidaClienteAnterior-nuevo_nodo->tLLegada;
                }
                else
                {
                    nuevo_nodo->tEsperaCliente=nuevo_nodo->tLLegada-nuevo_nodo->tLLegada;
                }
                //
                if(nuevo_nodo->tLLegada>auxTSalidaClienteAnterior)
                {
                    nuevo_nodo->tDescansoCajero=nuevo_nodo->tLLegada-auxTSalidaClienteAnterior;
                }
                else
                {
                    nuevo_nodo->tDescansoCajero=auxTSalidaClienteAnterior-auxTSalidaClienteAnterior;
                }


                tiempoSer=1 + rand() % (16);
                nuevo_nodo->tServicio=tiempoSer;
                nuevo_nodo->tSalidaCliente=nuevo_nodo->tLLegada+nuevo_nodo->tEsperaCliente+nuevo_nodo->tServicio;
                auxTSalidaClienteAnterior1=nuevo_nodo->tSalidaCliente;
                nuevo_nodo->tEntreLlegadaCliente=nuevo_nodo->tLLegada-auxTLLegadaAnterior;
                //
                nuevo_nodo->siguiente=NULL;


                //3ero ver si cola esta vacia o no

                if(cola_vacia(frente))
                {
                    frente=nuevo_nodo;
                }
                else
                {
                    fin->siguiente=nuevo_nodo;
                }
                c++;
            }
            else
            {

                 tiempoLL=1 + rand() % (25);
                 //2do asignar a nuevo nodo el dato
                nuevo_nodo->tLLegada=tiempoLL+auxTLLegadaAnterior1;
                if(auxTSalidaClienteAnterior1>nuevo_nodo->tLLegada)
                {
                    nuevo_nodo->tEsperaCliente=auxTSalidaClienteAnterior1-nuevo_nodo->tLLegada;
                }
                else
                {
                    nuevo_nodo->tEsperaCliente=nuevo_nodo->tLLegada-nuevo_nodo->tLLegada;
                }
                //
                if(nuevo_nodo->tLLegada>auxTSalidaClienteAnterior1)
                {
                    nuevo_nodo->tDescansoCajero=nuevo_nodo->tLLegada-auxTSalidaClienteAnterior1;
                }
                else
                {
                    nuevo_nodo->tDescansoCajero=auxTSalidaClienteAnterior1-auxTSalidaClienteAnterior1;
                }


                tiempoSer=1 + rand() % (16);
                nuevo_nodo->tServicio=tiempoSer;
                nuevo_nodo->tSalidaCliente=nuevo_nodo->tLLegada+nuevo_nodo->tEsperaCliente+nuevo_nodo->tServicio;
                nuevo_nodo->tEntreLlegadaCliente=nuevo_nodo->tLLegada-auxTLLegadaAnterior1;
                //
                nuevo_nodo->siguiente=NULL;


                //3ero ver si cola esta vacia o no

                if(cola_vacia(frente))
                {
                    frente=nuevo_nodo;
                }
                else
                {
                    fin->siguiente=nuevo_nodo;
                }
                c++;
            }


        }

            fin=nuevo_nodo;
    }
   // printf("\nElemento Insertado Correctamente");
}
void Nodo::eliminarDatoCola(Nodo *&frente,Nodo *&fin,int &n){ //eliminar dato de cola

   //1ero
    n=frente->tLLegada;
    //2do
    Nodo *aux=frente;
    //3ero eliminar
    //ver si hay un solo elemento o varios
    if(frente==fin){
        frente=NULL;
        fin=NULL;
    }
    else{
        frente=frente->siguiente;
    }
    delete aux;
}
void Nodo::mostrarDatos(Nodo *frente,Nodo *fin,Nodo *cola){
    int i=1;
    system("cls");
    if(fin==NULL)
    {
        printf("\nLa Cola Esta Vacia\n");
    }
    cola=frente;
    printf("Cliente  TLLegada  TEspera  TDescanso  TServicio  TSalida  TEntreLlegada\n");
    while(cola!=NULL)
    {
        printf("%d\t    %d\t      %d\t        %d\t    %d\t    %d\t      %d\n ",i,cola->tLLegada,cola->tEsperaCliente,cola->tDescansoCajero,cola->tServicio,cola->tSalidaCliente,cola->tEntreLlegadaCliente);
        cola=cola->siguiente;
        i++;

    }
}




void Nodo::gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
void Nodo::color(int a,int b){
    int color= (a*16)+b;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),color);
}
int Nodo::menu(){

    const char *titulo="\t\t\tCOLAS - AUTOMATIZACION";
	const char *opciones[]={/*1*/"Ingresar Clientes",/*2*/"Eliminar Datos De Cola",/*3*/"Mostrar Datos",/*4*/"Salir"};
    int opcionSeleccionada = 1,numerodeopciones=4;
    int tecla;
    bool repite=true;
    int i=0;
    do{
        system ("cls");
        gotoxy(7, 3 + opcionSeleccionada);
        color(fondo,texto);
        gotoxy(15,2);
        printf ("%s",titulo);
        gotoxy(5, 3 + opcionSeleccionada);
        for (int i = 0; i < numerodeopciones; ++i) {
            gotoxy(15,4+i);
            color (fondo,texto);
            printf("%s  ",opciones[i]);
        }
        gotoxy(15, 3 + opcionSeleccionada);
        color(12,15);
        printf("%s",opciones[i]);
        color(fondo,texto);
        do{
            tecla=getch();
        }while((tecla!=TECLA_ARRIBA)&&(tecla!=TECLA_ABAJO)&&(tecla!=TECLA_ENTER));

        switch(tecla){
            case TECLA_ARRIBA:
                opcionSeleccionada--;
                i--;
                if (opcionSeleccionada<1){
                    opcionSeleccionada= numerodeopciones;
                    i=numerodeopciones-1;

                }
                break;
            case TECLA_ABAJO:
                opcionSeleccionada++;
                i++;
                if (opcionSeleccionada>numerodeopciones){
                	opcionSeleccionada=1;
                   i=0;
                }
                break;
            case TECLA_ENTER:
                repite=false;
                break;
        }
    }while(repite);
    return opcionSeleccionada;
}
int Nodo::menuSN(){

    const char *titulo="\tDesea Ingresar Otro Dato?\n";
	const char *opciones[]={"SI","NO"};
    int opcionSeleccionada = 1,numerodeopciones=2;
    int tecla;
    bool repite=true;
    int i=0;
    do{
        system ("cls");
        gotoxy(7, 3 + opcionSeleccionada);
        color(fondo,texto);
        gotoxy(15,2);
        printf ("%s",titulo);
        gotoxy(5, 3 + opcionSeleccionada);
        for (int i = 0; i < numerodeopciones; ++i) {
            gotoxy(15,4+i);
            color (fondo,texto);
            printf("%s  ",opciones[i]);
        }
        gotoxy(15, 3 + opcionSeleccionada);
        color(12,15);
        printf("%s",opciones[i]);
        color(fondo,texto);
        do{
            tecla=getch();
        }while((tecla!=TECLA_ARRIBA)&&(tecla!=TECLA_ABAJO)&&(tecla!=TECLA_ENTER));

        switch(tecla){
            case TECLA_ARRIBA:
                opcionSeleccionada--;
                i--;
                if (opcionSeleccionada<1){
                    opcionSeleccionada= numerodeopciones;
                    i=numerodeopciones-1;

                }
                break;
            case TECLA_ABAJO:
                opcionSeleccionada++;
                i++;
                if (opcionSeleccionada>numerodeopciones){
                	opcionSeleccionada=1;
                   i=0;
                }
                break;
            case TECLA_ENTER:
                repite=false;
                break;
        }
    }while(repite);
    return opcionSeleccionada;
}
