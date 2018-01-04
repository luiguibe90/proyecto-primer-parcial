/******************************************************
*       UNIVERSIDAD DE LAS FUERZAS ARMADAS           **
*                    ESPE                            **
*                                                    **
*   Proyecto Primer Parcial Estructura de Datos      **
*                    Pilas                           **
*Tema:                                               **
*                  Polaca Inversa                    **
*Autores:                                            **
*       Benitez Rodriguez Luis Guillermo             **
*       Vaca Perez Vicente Xavier                    **
*Fecha de Entrega: 2018-01-15                        **
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

struct Nodo{

    int datoEntero;

    Nodo *siguiente;
    Nodo *anterior;
};
typedef struct Nodo *Pila;


//prototipo de funciones
void gotoxy(int x,int y);
void color(int a,int b);
void inicio ();
int menu();
int menuSN();
void ayuda();
void about();
void qr();
void guardardatos(Pila lista);
int ObtenerEnteroPositivo();

//desarrollo de funciones
static HWND  hConWnd;

HWND BCX_Bitmap(char*, HWND = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
HWND GetConsoleWndHandle(void);
// draw the bitmap
HWND BCX_Bitmap(char* Text, HWND hWnd, int id, int X, int Y, int W, int H, int Res, int Style, int Exstyle){
    fflush(stdin);
	HWND A;
	HBITMAP hBitmap;

	// set default style
	if (!Style) Style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_TABSTOP;

	// form for the image
	A = CreateWindowEx(Exstyle, "static", NULL, Style, X, Y, 0, 0, hWnd, (HMENU)id, GetModuleHandle(0), NULL);

	// Text contains filename
	hBitmap = (HBITMAP)LoadImage(0, Text, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// auto-adjust width and height
	if (W || H) hBitmap = (HBITMAP)CopyImage(hBitmap, IMAGE_BITMAP, W, H, LR_COPYRETURNORG);
	SendMessage(A, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
	if (W || H) SetWindowPos(A, HWND_TOP, X, Y, W, H, SWP_DRAWFRAME);

	return A;
}
HWND GetConsoleWndHandle(void){// tricking Windows just a little ...
    fflush(stdin);
	HWND hConWnd;
	OSVERSIONINFO os;
	char szTempTitle[800], szClassName[800], szOriginalTitle[1024];

	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	// may not work on WIN9x
	if (os.dwPlatformId == VER_PLATFORM_WIN32s) return 0;

	GetConsoleTitle(szOriginalTitle, sizeof(szOriginalTitle));
	sprintf(szTempTitle, "%u - %u", GetTickCount(), GetCurrentProcessId());
	SetConsoleTitle(szTempTitle);
	//Sleep(100);
	// handle for NT and XP
	hConWnd = FindWindow(NULL, szTempTitle);
	SetConsoleTitle(szOriginalTitle);

	// may not work on WIN9x
	if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
	{
	    fflush(stdin);
		hConWnd = GetWindow(hConWnd, GW_CHILD);
		if (hConWnd == NULL) return 0;
		GetClassName(hConWnd, szClassName, sizeof(szClassName));
		// while ( _stricmp( szClassName, "ttyGrab" ) != 0 )
		while (strcmp(szClassName, "ttyGrab") != 0)
		{
			hConWnd = GetNextWindow(hConWnd, GW_HWNDNEXT);
			if (hConWnd == NULL) return 0;
			GetClassName(hConWnd, szClassName, sizeof(szClassName));
		}

	}

	return hConWnd;
}


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


int main()
{
    int opcion;
     inicio();

     opcion=menu();
		system("cls");
    cout << "Hello world!" << endl;
    return 0;
}
void ayuda(){
    system("ayuda.chm");
}
void about(){
    char c;
	hConWnd = GetConsoleWndHandle();
	if (hConWnd)// qr github
	{
		// select a bitmap file you have or use one of the files in the Windows folder
		// nombre del archivo, handle, ID, coord X, coord Y, ancho, altura   si 0,0=ajustes automaticos
		//BCX_Bitmap("taday.bmp", hConWnd, 0, 20, 20, 200, 100);
		do{
			BCX_Bitmap("aboutl.bmp", hConWnd, 0, 0,0, 400, 400);
			c=getch();
		}while(c!=13);
	}
    system("pause");
	system("cls");
	hConWnd = GetConsoleWndHandle();
    // imagen qr github codigo del proyecto
    if (hConWnd)
	{

		BCX_Bitmap("  ", hConWnd, 0,0, 0, 400, 400);
		//Sleep(200);
		getchar();  // wait
	}
fflush(stdin);
}
void qr(){
     char c;
	hConWnd = GetConsoleWndHandle();
    // imagen qr github codigo del proyecto
    if (hConWnd)
	{

		BCX_Bitmap("qrgithub.bmp", hConWnd, 0, 500, 50, 100, 100);
		//Sleep(200);
		getchar();  // wait
	}
	system("pause");
	system("cls");
	hConWnd = GetConsoleWndHandle();
    // imagen qr github codigo del proyecto
    if (hConWnd)
	{

		BCX_Bitmap("  ", hConWnd, 0, 500, 50, 100, 100);
		//Sleep(200);
		getchar();  // wait
	}
	fflush(stdin);
}
void guardardatos(Pila lista){
    FILE *archivo=NULL;
    archivo=fopen("Datos Pila.txt","w+");
    system("cls");
    printf("\t\t----------------------------\n");
    printf("\t\t     LISTA DE PASAJEROS \n");
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

    const char *titulo="\t\t\tLISTAS DOBLES";
	const char *opciones[]={/*1*/"INGRESAR DATOS DE CLIENTE (NUEVO BOLETO)",/*2*/"CANCELACION BOLETO (ELIMINAR)"
                            ,/*3*/"BUSCAR CLIENTE",/*4*/"MOSTRAR ASIENTOS DISPONIBLES",
                            /*5*/"IMPRIMIR DATOS",/*6*/"GUARDAR DATOS",/*7*/"AYUDA",/*8*/"GENERAR QR",/*9*/"SALIR"};
    int opcionSeleccionada = 1,numerodeopciones=9;
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
    int tesp=15,x=3,y=4;
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
          for (int i=1;i<15;i++) //horizontal
        {
            gotoxy(117,i);printf("%c",219);
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
    gotoxy(41,25);printf("VENTA DE BOLETOS DE UN BUS\n");
    //barra cargando

    gotoxy(30,29);//1er numero mueve hacia izq o der 2do arriba abajo

    printf("\tCARGANDO...\n");
    for(int i=20;i<70;i++)//80 marca el tamanio
    {
        gotoxy(i,30);//1er numero mueve hacia izq o der 2do arriba abajo
        printf("%c",219);//valor de caracter a imprimir para la barra mediante asccii
        for(int x=50;x<70;x++)
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
