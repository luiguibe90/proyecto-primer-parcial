/******************************************************
*       UNIVERSIDAD DE LAS FUERZAS ARMADAS           **
*                    ESPE                            **
*                                                    **
*   Proyecto Segundo Parcial Estructura de Datos     **
*                    Pilas                           **
*Tema:                                               **
*                  Polaca Inversa                    **
*Autores:                                            **
*       Benitez Rodriguez Luis Guillermo             **
*       Vaca Perez Vicente Xavier                    **
*Fecha de Entrega: 2018-01-19                        **
*Carrera: Ingenieria en Sistemas e Informatica       **
*Profesor: Ing Fernando Solis                        **
*******************************************************/


//librerias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string>
#include<fstream>
#include <locale.h>
#define ENTER 13//login
#define BACKSPACE 8//login
#define USER "espe"
#define PASS "sistemas"
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13
#define fondo 0
#define texto 3
#define ced 10
#define numeroAsientos 10
#define F1 59
#define letras 50//para imagen
#define dimp 10//para imagen
#define KEY_ESC 27
#define _CRT_SECURE_NO_DEPRECATE

using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
};

typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )


//prototipo de funciones
void gotoxy(int x,int y);
void color(int a,int b);
void inicio ();
int menu();
int menuSN();
void ayuda();
void about();
void qr();
void guardardatos(ptrPila lista);
int ObtenerEnteroPositivo();
int calculadora();
int sonidos();
int backup();
void menuMouse();
//desarrollo de funciones


int ObtenerEnteroPositivo(){
    char digito,cadenaDelEntero[5];
    int entero,iterador=0;
    while((digito=getch())!=13||iterador==0){
        if(digito==F1)
        {
            system("ayuda.chm");
        }
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
int calculadora(){
return 0;
}
int sonidos(){
return 0;
}
int backup(){
return 0;
}
void agentes(){
    system("WinAppManejoMSAgente.exe");
}
//funciones para el manejo de la pila
void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;

     aux->sgte = p ;
     p = aux ;
}

/*                Desapilar elemento(devuelve elemento)
---------------------------------------------------------------------*/
int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;

     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila

     p = aux->sgte ;
     delete(aux);

     return num;
}

/*                     Muestra elementos de la pila
---------------------------------------------------------------------*/
void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista

     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->sgte;
     }
}

/*                Eliminar todos los elementos de la pila
---------------------------------------------------------------------*/
void destruir_pila( ptrPila &p)
{
     ptrPila aux;

     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}

//fin manejo pila
//inicio funciones trigonometricas
float factorial(int n){
    int i,fact=1;

        for(i = 1; i <= n; i++)
            fact = fact * i;
    return (fact);
}
float ConversionGradesToRadians(float mX){
     mX = ((mX * 3.141592 )/ 180);
    return mX;
}
float SerieSin(float mNum){
    int i;float mX=0, sum = 0;
    mX = ConversionGradesToRadians(mNum);

        for (i = 1; i <= 8; i++)
        {
            sum = sum + (( (pow(-1, i + 1) * pow(mX, (2 * i - 1)))) /
            factorial(2 * i - 1));
        }
return sum;
}
float SerieCos(float mNum){
    int i; float mX,sum;
    mX = ConversionGradesToRadians(mNum);
    for(i = 0; i <= 7; i++)
    {
        sum = sum + ((pow(-1,i)* pow(mX, 2 * i )) /factorial(2 * i ));
    }
return sum;
}
double SerieTan(double mNum){
    int i; float mX,sum,sum1;
    for (i = 1; i <= 8; i++)
    {
        sum = sum + (( (pow(-1, i + 1) * pow(mX, (2 * i - 1)))) /
        factorial(2 * i - 1));

    }
return sum/SerieCos(mNum);
}

//fin funciones trigonometricas
int main()
{
    int opcion;
   //  inicio();
   menuMouse();
/*
    do{
        opcion=menu();
        system("cls");
        switch (opcion)
        {
            case 1:
                calculadora();
                system("pause");

            break;
            case 2:
                ayuda();
                system("pause");
            break;
            case 3:
                qr();
                system("pause");

            break;
            case 4:
                about();
                system("pause");

            break;
            case 5:
                //system("WinAppManejoMSAgente.exe");
                agentes();
                system("pause");
            break;
            case 6:
                sonidos();
                system("pause");

            break;
            case 7:
                backup();
                system("pause");

            break;
            case 8:

            break;

        }

    }
    while(opcion!=8);*/
return 0;
}


void menuMouse(){

    system("cls");
	system("color 0A");
	cout << "\t\t\t Calculadora Polaca\n";
	printf("/*1*/ => CALCULADORA\n");
	printf("/*2*/ => AYUDA\n");
	printf("/*3*/ => QR\n");
	printf("/*4*/ => ABOUT\n");
	printf("/*5*/ => AGENTES\n");
	printf("/*6*/ => BACKUP\n");
	printf("/*7*/ => Salir\n");

	HANDLE paraEntrada = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD regEntrada;
	DWORD evento;
	COORD coordenadas;
	SetConsoleMode(paraEntrada, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(paraEntrada, &regEntrada, 1, &evento);
		if (regEntrada.EventType == MOUSE_EVENT)
		{
			if (regEntrada.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				coordenadas.X = regEntrada.Event.MouseEvent.dwMousePosition.X;
				coordenadas.Y = regEntrada.Event.MouseEvent.dwMousePosition.Y;
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 1)
				{
					system("cls");
					calculadora();
					//printf("1");
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 2)
				{
				    system("cls");
				    ayuda();
					//printf("2");
					system("pause");
					system("cls");
					menuMouse();

				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 3)//(coordenadas.X >0 && coordenadas.X <= 9 && coordenadas.Y == 3)
				{
					system("cls");
					qr();
					//printf("3");
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 4)
				{
					system("cls");
					about();
					//printf("4");
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 5)
				{
					system("cls");
					agentes();
					//printf("5");
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 6)
				{
				    system("cls");
				    backup();
					//printf("6");
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 7)
				{
				    system("cls");
					printf("gracias por usar el programa");
					system("pause");
					exit(0);
				}
			}
		}
	}
}
void ayuda(){
    system("ayuda.chm");
}
void about(){
  system("aboutl.bmp");
    fflush(stdin);
}
void qr(){

}
void guardardatos(ptrPila lista){
    FILE *archivo=NULL;
    archivo=fopen("Datos Pila.txt","w+");
    system("cls");
    printf("\t\t----------------------------\n");
    printf("\t\t                             \n");
    printf("\t\t----------------------------\n\n");

    fclose(archivo);

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

    const char *titulo="\t\t\tCALCULADORA POLACA";
	const char *opciones[]={/*1*/"CALCULADORA",/*2*/"AYUDA"
                            ,/*3*/"QR",/*4*/"ABOUT",
                            /*5*/"AGENTES",/*6*/"SONIDOS",/*7*/"BACKUP",/*8*/"SALIR"};
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
        CYAN			3 Cían
        RED				4 Rojo
        MAGENTA			5 Magenta
        BROWN			6 Marrón
        LIGHTGRAY		7 Gris Claro
        DARKGRAY		8 Gris Oscuro
        LIGHTBLUE		9 Azul Claro
        LIGHTGREEN		A Verde Claro
        LIGHTCYAN		B Cían Claro
        LIGHTRED		C Rojo Claro
        LIGHTMAGENTA	D Magenta Claro
        YELLOW			E Amarillo
        WHITE			F Blanco
        */
    int tesp=15,x=6,y=1;
    char caracter[130];
    color (fondo,texto);
    FILE *INICIO;
    INICIO=fopen("ARCHIVOS/INICIO.txt","r");
    //barra superior y barra izquierda
         for (int i=1;i<78;i++) //horizontal
        {
            gotoxy(i,1);printf("%c",223);
        }
        for (int i=1;i<16;i++) //vertical
        {
            gotoxy(1,i);printf("%c",219);
        }
    //barra inferior y barra derecha
          for (int i=1;i<15;i++) //vertical
        {
            gotoxy(78,i);printf("%c",219);
        }
        for (int i=1;i<=78;i++) //barra inferior horizonatal
        {
            gotoxy(i,15);printf("%c",223);
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
    gotoxy(46,25);printf("CALCULADORA POLACA\n");
    //barra cargando

    gotoxy(40,29);//1er numero mueve hacia izq o der 2do arriba abajo

    printf("\tCARGANDO...\n");
    for(int i=30;i<80;i++)//80 marca el tamanio
    {
        gotoxy(i,30);//1er numero mueve hacia izq o der 2do arriba abajo
        printf("%c",219);//valor de caracter a imprimir para la barra mediante asccii
        for(int x=50;x<90;x++)
        {//los espacios que va a recorre la barra en la pantalla
            for(int y=1;y<30;y++)
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
