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
void inicio ();
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

void buscarCliente(ListaDoble &lista){

}

void insertarDatosClientePosicion(ListaDoble &lista){

}
void insDatosCliente(ListaDoble &lista)
{
    ListaDoble nuevoElemento,nuevoAux;
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
    }
    else{

         nuevoElemento->datoEntero=ObtenerEnteroPositivo();
        nuevoAux=lista;
        while(nuevoAux->siguiente!=NULL){
            nuevoAux=nuevoAux->siguiente;
        }
        nuevoElemento->siguiente=nuevoAux->siguiente;
        nuevoAux->siguiente=nuevoElemento;
        nuevoElemento->anterior=nuevoAux;
        printf("\n\nDato ingresado!\n\n");
    }
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
void cancelarBoleto(ListaDoble &lista,int valor)
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
    inicio();
    color (fondo,texto);
	int opcion,numero=0,control=0;
	do{
		opcion=menu();
		system("cls");
		switch (opcion){
            case 1:
                insDatosCliente(lista);
                control=1;
                system("pause");
                break;
            case 2:
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
                    cancelarBoleto(lista,numero);
                }
                system("pause");
                break;
            case 3:
                buscarCliente(lista);
                system("pause");
                break;
            case 4:
                insertarDatosClientePosicion(lista);
                system("pause");

                break;
            case 5:
                mostrarDatos(lista);
                system("pause");

                break;
            case 6:

               // ayuda();
                system("AyudaHash.chm");
                system("pause");
                break;
            case 7:
                //about();
                system("20161224_133008.jpg");
                system("pause");

                break;
            case 8:

                break;
        }
	}while(opcion!=8);
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
                            ,/*3*/"BUSCAR CLIENTE",/*4*/"INGRESAR DATOS CLIENTE EN DETERMINADO ASIENTO",
                            /*5*/"IMPRIMIR DATOS",/*6*/"AYUDA", /*7*/"ABOUT",/*8*/"SALIR"};
    int opcionSeleccionada = 1,numerodeopciones=8;
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
void inicio (){
    /* LIBRERIA COLORES
        Colores :
        BLACK			0 Negro
        BLUE			1 Azul
        GREEN			2 Verde
        CYAN			3 C�an
        RED				4 Rojo
        MAGENTA			5 Magenta
        BROWN			6 Marr�n
        LIGHTGRAY		7 Gris Claro
        DARKGRAY		8 Gris Oscuro
        LIGHTBLUE		9 Azul Claro
        LIGHTGREEN		A Verde Claro
        LIGHTCYAN		B C�an Claro
        LIGHTRED		C Rojo Claro
        LIGHTMAGENTA	D Magenta Claro
        YELLOW			E Amarillo
        WHITE			F Blanco
        */
    int tesp=15,x=3,y=4;
    char caracter[130];
    system("color 0A");//color fondo-letra
    FILE *INICIO;
    INICIO=fopen("INICIO.txt","r");
    //barra superior y barra izquierda
         for (int i=1;i<117;i++) //horizontal
        {
            gotoxy(i,1);printf("%c",223);
        }
        for (int i=1;i<17;i++) //vertical
        {
            gotoxy(1,i);printf("%c",219);
        }
    //barra inferior y barra derecha
          for (int i=1;i<17;i++) //horizontal
        {
            gotoxy(117,i);printf("%c",219);
        }
        for (int i=1;i<=117;i++) //barra inferior horizonatal
        {
            gotoxy(i,17);printf("%c",223);
        }
     // printf ("\n");
        while (!feof(INICIO))
        {
            fgets(caracter,130,INICIO);
            gotoxy(x,y);cout<<caracter;
            Sleep(125);
            y++;
        }
        printf("\n\n\n");
        //system("pause");
        Sleep(3000);
        Beep(330,200);
        system("cls");
    system("color 0A");
    //letras espe
    //E

        gotoxy(43,10);printf("%c",219);Sleep(tesp);
        gotoxy(43,11);printf("%c",219);Sleep(tesp);
        gotoxy(43,12);printf("%c",219);Sleep(tesp);
        gotoxy(43,13);printf("%c",219);Sleep(tesp);
        gotoxy(43,14);printf("%c",219);Sleep(tesp);
        gotoxy(43,15);printf("%c",219);Sleep(tesp);
        //gotoxy(43,16);printf("%c",219);Sleep(tesp);

        gotoxy(44,10);printf("%c",223);Sleep(tesp);
        gotoxy(45,10);printf("%c",223);Sleep(tesp);
        gotoxy(46,10);printf("%c",223);Sleep(tesp);
        gotoxy(47,10);printf("%c",223);Sleep(tesp);


        gotoxy(44,13);printf("%c",223);Sleep(tesp);
        gotoxy(45,13);printf("%c",223);Sleep(tesp);
        gotoxy(46,13);printf("%c",223);Sleep(tesp);
        gotoxy(47,13);printf("%c",223);Sleep(tesp);


        gotoxy(43,16);printf("%c",223);Sleep(tesp);
        gotoxy(44,16);printf("%c",223);Sleep(tesp);
        gotoxy(45,16);printf("%c",223);Sleep(tesp);
        gotoxy(46,16);printf("%c",223);Sleep(tesp);
        gotoxy(47,16);printf("%c",223);Sleep(tesp);
    Beep(800,300);
        //S
        gotoxy(50,10);printf("%c",219);Sleep(tesp);
        gotoxy(50,11);printf("%c",219);Sleep(tesp);
        gotoxy(50,12);printf("%c",219);Sleep(tesp);
        //gotoxy(50,13);printf("%c",219);Sleep(tesp);
        gotoxy(54,13);printf("%c",219);Sleep(tesp);
        gotoxy(54,14);printf("%c",219);Sleep(tesp);
        gotoxy(54,15);printf("%c",219);Sleep(tesp);

        gotoxy(51,10);printf("%c",223);Sleep(tesp);
        gotoxy(52,10);printf("%c",223);Sleep(tesp);
        gotoxy(53,10);printf("%c",223);Sleep(tesp);
        gotoxy(54,10);printf("%c",223);Sleep(tesp);

        gotoxy(50,13);printf("%c",223);Sleep(tesp);
        gotoxy(51,13);printf("%c",223);Sleep(tesp);
        gotoxy(52,13);printf("%c",223);Sleep(tesp);
        gotoxy(52,13);printf("%c",223);Sleep(tesp);
        gotoxy(53,13);printf("%c",223);Sleep(tesp);

        gotoxy(50,16);printf("%c",223);Sleep(tesp);
        gotoxy(51,16);printf("%c",223);Sleep(tesp);
        gotoxy(52,16);printf("%c",223);Sleep(tesp);
        gotoxy(53,16);printf("%c",223);Sleep(tesp);
        gotoxy(54,16);printf("%c",223);Sleep(tesp);
    Beep(800,300);

        //P
        gotoxy(57,10);printf("%c",219);Sleep(tesp);
        gotoxy(57,11);printf("%c",219);Sleep(tesp);
        gotoxy(57,12);printf("%c",219);Sleep(tesp);
        gotoxy(57,13);printf("%c",219);Sleep(tesp);
        gotoxy(57,14);printf("%c",219);Sleep(tesp);
        gotoxy(57,15);printf("%c",219);Sleep(tesp);
        gotoxy(57,16);printf("%c",219);Sleep(tesp);

        gotoxy(58,10);printf("%c",223);Sleep(tesp);
        gotoxy(59,10);printf("%c",223);Sleep(tesp);
        gotoxy(60,10);printf("%c",223);Sleep(tesp);
        gotoxy(61,10);printf("%c",223);Sleep(tesp);


        gotoxy(61,10);printf("%c",219);Sleep(tesp);
        gotoxy(61,11);printf("%c",219);Sleep(tesp);
        gotoxy(61,12);printf("%c",219);Sleep(tesp);
        //gotoxy(61,13);printf("%c",219);Sleep(tesp);


        gotoxy(61,13);printf("%c",223);Sleep(tesp);
        gotoxy(60,13);printf("%c",223);Sleep(tesp);
        gotoxy(59,13);printf("%c",223);Sleep(tesp);
        gotoxy(58,13);printf("%c",223);Sleep(tesp);
    Beep(800,300);

        //E
        gotoxy(64,10);printf("%c",219);Sleep(tesp);
        gotoxy(64,11);printf("%c",219);Sleep(tesp);
        gotoxy(64,12);printf("%c",219);Sleep(tesp);
        gotoxy(64,13);printf("%c",219);Sleep(tesp);
        gotoxy(64,14);printf("%c",219);Sleep(tesp);
        gotoxy(64,15);printf("%c",219);Sleep(tesp);
        //gotoxy(64,16);printf("%c",219);Sleep(tesp);

        gotoxy(65,10);printf("%c",223);Sleep(tesp);
        gotoxy(66,10);printf("%c",223);Sleep(tesp);
        gotoxy(67,10);printf("%c",223);Sleep(tesp);
        gotoxy(68,10);printf("%c",223);Sleep(tesp);


        gotoxy(65,13);printf("%c",223);Sleep(tesp);
        gotoxy(66,13);printf("%c",223);Sleep(tesp);
        gotoxy(67,13);printf("%c",223);Sleep(tesp);
        gotoxy(68,13);printf("%c",223);Sleep(tesp);


        gotoxy(64,16);printf("%c",223);Sleep(tesp);
        gotoxy(65,16);printf("%c",223);Sleep(tesp);
        gotoxy(66,16);printf("%c",223);Sleep(tesp);
        gotoxy(67,16);printf("%c",223);Sleep(tesp);
        gotoxy(68,16);printf("%c",223);Sleep(tesp);
    Beep(800,300);
    gotoxy(41,25);printf("VENTA DE BOLETOS DE UN BUS\n");
    //barra cargando

    gotoxy(40,29);//1er numero mueve hacia izq o der 2do arriba abajo

    printf("\tCARGANDO...\n");
    for(int i=20;i<90;i++)//80 marca el tamanio
    {
        gotoxy(i,30);//1er numero mueve hacia izq o der 2do arriba abajo
        printf("%c",219);//valor de caracter a imprimir para la barra mediante asccii
        for(int x=50;x<90;x++)
        {//los espacios que va a recorre la barra en la pantalla
            for(int y=1;y<20;y++)
            {//determina el tiempo de movimiento de la barra
                gotoxy(y+180,34);
            }
        }
    }
    Beep(262,150);
    Beep(262,150);
    Beep(262,150);
    printf("\n\n");
    Sleep(1000);
    //system("pause");
    system("cls");
    Beep(330,200);
}