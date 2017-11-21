/******************************************************
*       UNIVERSIDAD DE LAS FUERZAS ARMADAS           **
*                    ESPE                            **
*                                                    **
*   Proyecto Primer Parcial Estructura de Datos      **
*                   Listas Dobles                    **
*Tema:                                               **
*       Venta De Boletos Para Un Bus                 **
*Autores:                                            **
*       Benitez Rodriguez Luis Guillermo             **
*       Vaca Perez Vicente Xavier                    **
*Fecha de Entrega: 2017-11-29                        **
*Carrera: Ingenieria en Sistemas e Informatica       **
*Profesor: Ing Fernando Solis                        **
*******************************************************/


//librerias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13
#define fondo 3
#define texto 10
using namespace std;

//declaracion de estructura para listas dobles

struct Nodo{
    int datoEntero;
    Nodo *siguiente;
    Nodo *anterior;
};
typedef struct Nodo *ListaDoble;


//declaracion de prototipos de funciones

void gotoxy(int,int);
void color(int,int);
int menu();
int menuSN();
int ObtenerEnteroPositivo();
int insElemListaVacia(ListaDoble &);
void insElemInicio(ListaDoble &);
void insElemFin(ListaDoble &);
int insElemAntes(ListaDoble &, int ,int);
int insElemDespues(ListaDoble &,int,int);
int calcularPrimo(int);


//desarrollo de funciones

int ObtenerEnteroPositivo(){
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

int insElemListaVacia(ListaDoble &lista)
{
    ListaDoble nuevoElemento;
    nuevoElemento=new(Nodo);
    system("cls");
    printf("\t----------------------------\n");
    printf("\t   INGRESAR PRIMER NUMERO\n");
    printf("\t----------------------------\n\n");

    if(lista==NULL)
    {
        printf("Ingrese el primer numero:\n\n");
        nuevoElemento->datoEntero=ObtenerEnteroPositivo();
        nuevoElemento->siguiente=nuevoElemento->anterior=NULL;
        lista=nuevoElemento;
        printf("\n\nPrimer numero ingresado!\n\n");
    }else{
        printf("Ya ingreso el primer elemento!\n\n");
    }
    return 0;
}


void insElemInicio(ListaDoble &lista)
{
    ListaDoble nuevoElemento,nuevoAux;
    nuevoElemento=new(Nodo);

    system("cls");
    printf("\t-------------------------------\n");
    printf("\t   INGRESAR NUMERO AL INICIO\n");
    printf("\t-------------------------------\n\n");

    if(lista!=NULL)
    {
        printf("Ingrese el numero:\n\n");
        nuevoElemento->datoEntero=ObtenerEnteroPositivo();//asigno el dato
        nuevoAux=lista;
        nuevoElemento->siguiente=nuevoAux;
        nuevoElemento->anterior=nuevoAux->anterior;
        nuevoAux->anterior=nuevoElemento;
        lista=nuevoElemento;
        printf("\n\nDato ingresado!\n\n");
    }else{
        printf("Debe ingresar el primer elemento!\n\n");
    }
}

void insElemFin(ListaDoble &lista)
{
    ListaDoble nuevoElemento,nuevoAux;
    nuevoElemento=new(Nodo);
    system("cls");
    printf("\t------------------------------\n");
    printf("\t   INGRESAR NUMERO AL FINAL\n");
    printf("\t------------------------------\n\n");
    if(lista!=NULL){
        printf("Ingrese el numero:\n\n");
        nuevoElemento->datoEntero=ObtenerEnteroPositivo();
        nuevoAux=lista;
        while(nuevoAux->siguiente!=NULL){
            nuevoAux=nuevoAux->siguiente;
        }
        nuevoElemento->siguiente=nuevoAux->siguiente;
        nuevoAux->siguiente=nuevoElemento;
        nuevoElemento->anterior=nuevoAux;
        printf("\n\nDato ingresado!\n\n");
    }else{
        printf("Debe ingresar el primer elemento!\n\n");
    }
}

void insElemAntes(ListaDoble &lista)
{
    int i=1,posicion,dato,bandera=0;//i es 1 porque no se podria poner en la posicion -1
    if(lista!=NULL)
    {
        do
        {
            system("cls");
            printf("\t---------------------------\n");
            printf("\t   INGRESAR NUMERO ANTES DE POSICION\n");
            printf("\t---------------------------\n\n");
            printf("Ingrese la posicion:\n\n");
            posicion=ObtenerEnteroPositivo();
        }while(posicion==0);
        ListaDoble aux2=lista;//creamos el aux2 de lista y asignamos memoria
        while(aux2->siguiente!=NULL)
        {
            if(posicion==i)
            {
                ListaDoble aux1=new (Nodo);//creamos el aux1 de lista y asignamos memoria
                printf("\n\nDigite el numero a ingresar:\n\n");
                aux1->datoEntero=ObtenerEnteroPositivo();
                //recorriendo la lista
                aux1->siguiente=aux2->siguiente;
                aux2->siguiente=aux1;
                aux1->anterior=aux2;
                aux1->siguiente->anterior=aux1;
                printf("\n\nDato ingresado!\n\n");

                while(aux2->anterior!=NULL)
                {
                    aux2=aux2->anterior;
                }
                lista=aux2;
                bandera=1;
                break;
            }
            aux2=aux2->siguiente;
            i++;
        }

        if(posicion==i&&bandera==0)
        {
            printf("\n\nUsted intenta ingresar un dato al final de la lista!\n\n");
            system("pause");
            //insElemFin(lista);
        }
        else
        {
            if(i<posicion&&bandera==0)
            {
                printf("\n\nLa posicion ingresada es superior al numero de los elementos de la lista!\n\n");
            }
        }
    }
    else
    {
        printf("Debe ingresar el primer elemento!\n\n");
    }

}
void insElemDespues(ListaDoble &lista)
{
    int i=1,posicion,dato,bandera=0;//i es 1 porque no se podria poner en la posicion -1
    if(lista!=NULL)
    {
        do
        {
            system("cls");
            printf("\t---------------------------\n");
            printf("\t   INGRESAR NUMERO DESPUES DE POSICION\n");
            printf("\t---------------------------\n\n");
            printf("Ingrese la posicion:\n\n");
            posicion=ObtenerEnteroPositivo();
        }while(posicion==0);
        ListaDoble aux2=lista;//creamos el aux2 de lista y asignamos memoria
        while(aux2->siguiente!=NULL)
        {
            if((posicion+1)==i)
            {
                ListaDoble aux1=new (Nodo);//creamos el aux1 de lista y asignamos memoria
                printf("\n\nDigite el numero a ingresar:\n\n");
                aux1->datoEntero=ObtenerEnteroPositivo();
                //recorriendo la lista
                aux1->siguiente=aux2->siguiente;
                aux2->siguiente=aux1;
                aux1->anterior=aux2;
                aux1->siguiente->anterior=aux1;
                printf("\n\nDato ingresado!\n\n");

                while(aux2->anterior!=NULL)
                {
                    aux2=aux2->anterior;
                }
                lista=aux2;
                bandera=1;
                break;
            }
            aux2=aux2->siguiente;
            i++;
        }

        if(posicion+1==i&&bandera==0)
        {
            printf("\n\nUsted intenta ingresar un dato al final de la lista!\n\n");
            system("pause");
            insElemFin(lista);
        }
        else
        {
            if(i<posicion&&bandera==0)
            {
                printf("\n\nLa posicion ingresada es superior al numero de los elementos de la lista!\n\n");
            }
        }


    }
    else
    {
        printf("Debe ingresar el primer elemento!\n\n");
    }

}
void eliminarDato(ListaDoble &lista,int valor)
{
    ListaDoble aux=new(Nodo);
    ListaDoble anterior=new(Nodo);
    aux=lista;
    anterior=NULL;
    int control=0;

    if(lista!=NULL){
       // printf("Ingrese Numero A Eliminar\n");
           // valor=ObtenerEnteroPositivo();
        while(aux!=NULL)
        {
            if(aux->datoEntero==valor)
            {
                if(anterior==NULL)
                {
                    lista=lista->siguiente;
                    printf("\nDato eliminado: %d",aux->datoEntero);
                    control=1;
                    return;
                }
                if(aux->siguiente==NULL)
                {
                    aux->anterior->siguiente=NULL;
                    printf("\nDato eliminado: %d",aux->datoEntero);
                    control=1;
                    return;
                }
                anterior->siguiente=aux->siguiente;
                aux->siguiente->anterior=anterior;
                printf("\nDato eliminado: %d",aux->datoEntero);
                control=1;
            }
            anterior=aux;
            aux=aux->siguiente;
        }
        if(control==0)
        {
             printf("\nNo se encontro el dato");
        }
    }
    else
    {
        printf("\nDebe ingresar el primer elemento!\n\n");
    }
}
void mostrarDatos(ListaDoble lista)
{
     system("cls");
    printf("\t----------------------\n");
    printf("\t   LISTA DE NUMEROS INICIAL\n");
    printf("\t----------------------\n\n");
    if(lista==NULL)
    {
        printf("No hay elementos en la lista!\n\n");
    }
    else
    {
        int iterador=1;
        while(lista!=NULL){
            printf("Elemento # %d:\n",iterador);iterador++;
            printf("* Numero: %d\n\n",lista->datoEntero);
            lista=lista->siguiente;
        }
    }



}
void liberarMemoria(ListaDoble &lista){
    if(lista!=NULL){
        ListaDoble punteroAuxiliar;
        while(lista!=NULL){
            punteroAuxiliar=lista->siguiente;
            delete(lista);
            lista=punteroAuxiliar;
        }
        printf("Memoria liberada!\n\n");
    }
}
int main()
{
    ListaDoble lista=NULL;

    color (fondo,texto);
	int opcion,numero=0,control=0;
	do{
		opcion=menu();
		system("cls");
		switch (opcion){
            case 1:
                insElemListaVacia(lista);
                control=1;
                system("pause");
                break;
            case 2:
                insElemInicio(lista);
                system("pause");
                break;
            case 3:
                insElemFin(lista);
                system("pause");
                break;
            case 4:
                insElemAntes(lista);
                system("pause");

                break;
            case 5:
                insElemDespues(lista);
                system("pause");

                break;
            case 6:
                if(control==0)
                {
                    printf("Primero Debe Ingresar Datos a la lista\n");
                }
                else
                {
                    do
                    {
                        printf("\nIngrese Dato a Buscar: \n");
                        numero=ObtenerEnteroPositivo();
                    }while(numero<0);
                    eliminarDato(lista,numero);
                }
                system("pause");

                break;
            case 7:

                system("pause");

                break;
            case 8:
                mostrarDatos(lista);
                system("pause");
                break;
            case 9:
                liberarMemoria(lista);
                system("pause");
                break;
            case 10:
                 system("AyudaHash.chm");
                //system("pause");
                break;
            case 11:
                system("20161224_133008.jpg");
                break;

        }


	}while(opcion!=11);

return 0;
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
void color(int a,int b){
    int color= (a*16)+b;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),color);
}

int menu(){

    const char *titulo="\t\t\tLISTAS DOBLES";
	const char *opciones[]={/*1*/"INGRESAR DATOS DE CLIENTE",/*2*/"CANCELACION BOLETO(ELIMINAR)"
                            ,/*3*/"INGRESAR DATO ENTERO POSITIVO AL FINAL DE LA LISTA",/*4*/"INGRESAR DATO ENTERO POSITIVO ANTES DE UNA POSICION",
                            /*5*/"INGRESAR DATO ENTERO POSITIVO DESPUES DE UNA POSICION",/*6*/"ELIMINAR DATO DE LISTA",
                            /*7*/"NUMEROS PRIMOS DE LISTA", /*8*/"MOSTRAR ELEMENTOS DE LISTA",/*9*/"SALIR",/*10*/"ayuda",/*11*/"foto"};
    int opcionSeleccionada = 1,numerodeopciones=11;
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
int menuSN(){

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
