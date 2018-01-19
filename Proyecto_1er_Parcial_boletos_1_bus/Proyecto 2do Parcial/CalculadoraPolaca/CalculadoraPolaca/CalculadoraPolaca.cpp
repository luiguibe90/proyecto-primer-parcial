// CalculadoraPolaca.cpp : Defines the entry point for the console application.
//

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

#include "stdafx.h"
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
#include <direct.h>//mkdir
#include "Pila.h"
#include "Nodo.h"
#include "PilaGenerica.h"
#include "PilaGenericaD.h"
#include "qrcodegen.h"

#define ENTER 13//login
#define BACKSPACE 8;//login
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

struct Elemento {
	string ope;
	bool operador;
};
struct Expresion {
	Elemento* expr;
	int n;
};

//prototipo de funciones
void gotoxy(int , int );
void color(int , int );
void inicio();
int menuSN();
void ayuda();
void about();
void qr();
int ObtenerEnteroPositivo();
int calculadora();
int backup();
void menuMouse();
void menuTeclas();
void menuTeclasPre();
void asignar(string);
bool valido(string);
bool operando(string c);
int prdadDentro(string operador);
int prdadFuera(string operando);
string postfija(string, int);
string separarDato(string, char *dato, int &pos);
void guardar(string, char *archivo);
double Evalua(Expresion postfija, double v[]);

//void  generarQr(char *);
//static void generarQrBasico(char dato1[]);
//static void printQr(const uint8_t qrcode[]);

string Prefija(string expresion, int num);
int prdadDentroPre(string operador);
int prdadFueraPre(string operando);
void crear_carpeta();
void recuperar_carpeta();
void menuMouse();
void leertxt();



//desarrollo de funciones


int ObtenerEnteroPositivo() {
	char digito, cadenaDelEntero[5];
	int entero, iterador = 0;
	while ((digito = _getch()) != 13 || iterador == 0) {
		if (digito == F1)
		{
			system("ayuda.chm");
		}
		if (digito >= '0'&&digito <= '9'&&iterador<5) {
			printf("%c", digito);
			cadenaDelEntero[iterador++] = digito;
		}
		if (iterador == 5)
			break;
	}
	cadenaDelEntero[iterador] = '\0';
	return entero = atoi(cadenaDelEntero);
}
int calculadora() {
	return 0;
}
int sonidos() {
	return 0;
}
int backup() {
	return 0;
}
void agentes() {
	system("WinAppManejoMSAgente.exe");
}



//inicio funciones trigonometricas
float factorial(int n) {
	int i, fact = 1;

	for (i = 1; i <= n; i++)
		fact = fact * i;
	return (fact);
}
float ConversionGradesToRadians(float mX) {
	mX = ((mX * 3.141592) / 180);
	return mX;
}
float SerieSin(float mNum) {
	int i; float mX = 0, sum = 0;
	mX = ConversionGradesToRadians(mNum);

	for (i = 1; i <= 8; i++)
	{
		sum = sum + (((pow(-1, i + 1) * pow(mX, (2 * i - 1)))) /
			factorial(2 * i - 1));
	}
	return sum;
}
float SerieCos(float mNum) {
	int i; float mX, sum=0;
	mX = ConversionGradesToRadians(mNum);
	for (i = 0; i <= 7; i++)
	{
		sum = sum + ((pow(-1, i)* pow(mX, 2 * i)) / factorial(2 * i));
	}
	return sum;
}
double SerieTan(double mNum) {
	int i=0; float mX=0, sum=0, sum1=0;
	for (i = 1; i <= 8; i++)
	{
		sum = sum + (((pow(-1, i + 1) * pow(mX, (2 * i - 1)))) /
			factorial(2 * i - 1));

	}
	return sum / SerieCos(mNum);
}
//fin funciones trigonometricas
int main()
{
	int opcion;
	// inicio();
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

/*
void menuMouse() {

	system("cls");
	system("color 0A");
	cout << "\t\t\t Calculadora Polaca\n";
	printf("/1/ => CALCULADORA\n");
	printf("/2/ => AYUDA\n");
	printf("/3/ => QR\n");
	printf("/4/ => ABOUT\n");
	printf("/5/ => AGENTES\n");
	printf("/6/ => BACKUP\n");
	printf("/7/ => Salir\n");

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
					printf("2");
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
}*/
void ayuda() {
	system("ayuda.chm");
}
void about() {
	system("aboutl.bmp");
	fflush(stdin);
}
void qr() {

}
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void color(int a, int b) {
	int color = (a * 16) + b;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/*int menu() {//teclas direccionales

	const char *titulo = "\t\t\tCALCULADORA POLACA";
	const char *opciones[] = {//1//"CALCULADORA",//2//"AYUDA"
		,//3//"QR",//4//"ABOUT",
		//5//"AGENTES",//6//"SONIDOS",//7//"BACKUP",//8//"SALIR" };
	int opcionSeleccionada = 1, numerodeopciones = 8;
	int tecla;
	bool repite = true;
	int i = 0;
	do {
		system("cls");
		gotoxy(7, 3 + opcionSeleccionada);
		color(fondo, texto);
		gotoxy(15, 2);
		printf("%s", titulo);
		gotoxy(5, 3 + opcionSeleccionada);
		for (int i = 0; i < numerodeopciones; ++i) {
			gotoxy(15, 4 + i);
			color(fondo, texto);
			printf("%s  ", opciones[i]);
		}
		gotoxy(15, 3 + opcionSeleccionada);
		color(12, 15);
		printf("%s", opciones[i]);
		color(fondo, texto);
		do {
			tecla = _getch();
		} while ((tecla != TECLA_ARRIBA) && (tecla != TECLA_ABAJO) && (tecla != TECLA_ENTER));

		switch (tecla) {
		case TECLA_ARRIBA:
			opcionSeleccionada--;
			i--;
			if (opcionSeleccionada<1) {
				opcionSeleccionada = numerodeopciones;
				i = numerodeopciones - 1;

			}
			break;
		case TECLA_ABAJO:
			opcionSeleccionada++;
			i++;
			if (opcionSeleccionada>numerodeopciones) {
				opcionSeleccionada = 1;
				i = 0;
			}
			break;
		case TECLA_ENTER:
			repite = false;
			break;
		}
	} while (repite);
	return opcionSeleccionada;
}*/
int menuSN() {

	const char *titulo = "\tDesea Ingresar Otro Dato?\n";
	const char *opciones[] = { "SI","NO" };
	int opcionSeleccionada = 1, numerodeopciones = 2;
	int tecla;
	bool repite = true;
	int i = 0;
	do {
		system("cls");
		gotoxy(7, 3 + opcionSeleccionada);
		color(fondo, texto);
		gotoxy(15, 2);
		printf("%s", titulo);
		gotoxy(5, 3 + opcionSeleccionada);
		for (int i = 0; i < numerodeopciones; ++i) {
			gotoxy(15, 4 + i);
			color(fondo, texto);
			printf("%s  ", opciones[i]);
		}
		gotoxy(15, 3 + opcionSeleccionada);
		color(12, 15);
		printf("%s", opciones[i]);
		color(fondo, texto);
		do {
			tecla = _getch();
		} while ((tecla != TECLA_ARRIBA) && (tecla != TECLA_ABAJO) && (tecla != TECLA_ENTER));

		switch (tecla) {
		case TECLA_ARRIBA:
			opcionSeleccionada--;
			i--;
			if (opcionSeleccionada<1) {
				opcionSeleccionada = numerodeopciones;
				i = numerodeopciones - 1;

			}
			break;
		case TECLA_ABAJO:
			opcionSeleccionada++;
			i++;
			if (opcionSeleccionada>numerodeopciones) {
				opcionSeleccionada = 1;
				i = 0;
			}
			break;
		case TECLA_ENTER:
			repite = false;
			break;
		}
	} while (repite);
	return opcionSeleccionada;
}
void inicio() {
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
	int tesp = 15, x = 6, y = 1;
	char caracter[130];
	color(fondo, texto);
	char archivo[30]= "ARCHIVOS/INICIO.txt";
	FILE *ptr = fopen(archivo, "r");
	//barra superior y barra izquierda
	for (int i = 1; i<78; i++) //horizontal
	{
		gotoxy(i, 1); printf("%c", 223);
	}
	for (int i = 1; i<16; i++) //vertical
	{
		gotoxy(1, i); printf("%c", 219);
	}
	//barra inferior y barra derecha
	for (int i = 1; i<15; i++) //vertical
	{
		gotoxy(78, i); printf("%c", 219);
	}
	for (int i = 1; i <= 78; i++) //barra inferior horizonatal
	{
		gotoxy(i, 15); printf("%c", 223);
	}
	// printf ("\n");
	while (!feof(ptr))
	{
		fgets(caracter, 130, ptr);
		gotoxy(x, y); cout << caracter;
		Sleep(125);
		y++;
	}
	printf("\n\n\n");
	//system("pause");
	Sleep(3000);
	Beep(330, 200);
	system("cls");
	system("color 0A");
	//letras espe
	//E

	gotoxy(43, 10); printf("%c", 219); Sleep(tesp);
	gotoxy(43, 11); printf("%c", 219); Sleep(tesp);
	gotoxy(43, 12); printf("%c", 219); Sleep(tesp);
	gotoxy(43, 13); printf("%c", 219); Sleep(tesp);
	gotoxy(43, 14); printf("%c", 219); Sleep(tesp);
	gotoxy(43, 15); printf("%c", 219); Sleep(tesp);
	//gotoxy(43,16);printf("%c",219);Sleep(tesp);

	gotoxy(44, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(45, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(46, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(47, 10); printf("%c", 223); Sleep(tesp);


	gotoxy(44, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(45, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(46, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(47, 13); printf("%c", 223); Sleep(tesp);


	gotoxy(43, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(44, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(45, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(46, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(47, 16); printf("%c", 223); Sleep(tesp);
	Beep(800, 300);
	//S
	gotoxy(50, 10); printf("%c", 219); Sleep(tesp);
	gotoxy(50, 11); printf("%c", 219); Sleep(tesp);
	gotoxy(50, 12); printf("%c", 219); Sleep(tesp);
	//gotoxy(50,13);printf("%c",219);Sleep(tesp);
	gotoxy(54, 13); printf("%c", 219); Sleep(tesp);
	gotoxy(54, 14); printf("%c", 219); Sleep(tesp);
	gotoxy(54, 15); printf("%c", 219); Sleep(tesp);

	gotoxy(51, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(52, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(53, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(54, 10); printf("%c", 223); Sleep(tesp);

	gotoxy(50, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(51, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(52, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(52, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(53, 13); printf("%c", 223); Sleep(tesp);

	gotoxy(50, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(51, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(52, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(53, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(54, 16); printf("%c", 223); Sleep(tesp);
	Beep(800, 300);

	//P
	gotoxy(57, 10); printf("%c", 219); Sleep(tesp);
	gotoxy(57, 11); printf("%c", 219); Sleep(tesp);
	gotoxy(57, 12); printf("%c", 219); Sleep(tesp);
	gotoxy(57, 13); printf("%c", 219); Sleep(tesp);
	gotoxy(57, 14); printf("%c", 219); Sleep(tesp);
	gotoxy(57, 15); printf("%c", 219); Sleep(tesp);
	gotoxy(57, 16); printf("%c", 219); Sleep(tesp);

	gotoxy(58, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(59, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(60, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(61, 10); printf("%c", 223); Sleep(tesp);


	gotoxy(61, 10); printf("%c", 219); Sleep(tesp);
	gotoxy(61, 11); printf("%c", 219); Sleep(tesp);
	gotoxy(61, 12); printf("%c", 219); Sleep(tesp);
	//gotoxy(61,13);printf("%c",219);Sleep(tesp);


	gotoxy(61, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(60, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(59, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(58, 13); printf("%c", 223); Sleep(tesp);
	Beep(800, 300);

	//E
	gotoxy(64, 10); printf("%c", 219); Sleep(tesp);
	gotoxy(64, 11); printf("%c", 219); Sleep(tesp);
	gotoxy(64, 12); printf("%c", 219); Sleep(tesp);
	gotoxy(64, 13); printf("%c", 219); Sleep(tesp);
	gotoxy(64, 14); printf("%c", 219); Sleep(tesp);
	gotoxy(64, 15); printf("%c", 219); Sleep(tesp);
	//gotoxy(64,16);printf("%c",219);Sleep(tesp);

	gotoxy(65, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(66, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(67, 10); printf("%c", 223); Sleep(tesp);
	gotoxy(68, 10); printf("%c", 223); Sleep(tesp);


	gotoxy(65, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(66, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(67, 13); printf("%c", 223); Sleep(tesp);
	gotoxy(68, 13); printf("%c", 223); Sleep(tesp);


	gotoxy(64, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(65, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(66, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(67, 16); printf("%c", 223); Sleep(tesp);
	gotoxy(68, 16); printf("%c", 223); Sleep(tesp);
	Beep(800, 300);
	gotoxy(46, 25); printf("CALCULADORA POLACA\n");
	//barra cargando

	gotoxy(40, 29);//1er numero mueve hacia izq o der 2do arriba abajo

	printf("\tCARGANDO...\n");
	for (int i = 30; i<80; i++)//80 marca el tamanio
	{
		gotoxy(i, 30);//1er numero mueve hacia izq o der 2do arriba abajo
		printf("%c", 219);//valor de caracter a imprimir para la barra mediante asccii
		for (int x = 50; x<90; x++)
		{//los espacios que va a recorre la barra en la pantalla
			for (int y = 1; y<30; y++)
			{//determina el tiempo de movimiento de la barra
				gotoxy(y + 180, 34);
			}
		}
	}
	Beep(262, 150);
	Beep(262, 150);
	Beep(262, 150);
	printf("\n\n");
	Sleep(1000);
	//system("pause");
	system("cls");
	Beep(330, 200);
}



//funciones

void menuMouse() {
	string palabra1;
	system("cls");
	system("color f0");
	cout << "================CALCULADORA POLACA================" << endl;
	printf("== 1. Prefijo\n");
	printf("== 2. Posfijo\n");
	printf("== 3. Ver Operacion Ingresada\n");
	printf("== 4. Ayuda\n");
	printf("== 5. About\n");
	printf("== 6. QR\n");
	printf("== 7. Agentes\n");
	printf("== 8. Generar Backup\n");
	printf("== 9. Recuperar Backup\n");
	printf("== 10. Salir\n");
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
					printf("\n================Conversion Prefijo================\n");
					menuTeclasPre();
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 2)
				{
					system("cls");
					printf("\n================Conversion Postfijo================\n");
					menuTeclas();
					menuMouse();

				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 3)
				{
					system("cls");
					leertxt();
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 4)
				{
					system("cls");
					ayuda();
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 5)
				{
					system("cls");
					about();
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 6)
				{
					system("cls");
					qr();
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 7)
				{
					system("cls");
					agentes();
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 8)
				{
					system("cls");
					crear_carpeta();
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 9)
				{
					system("cls");
					recuperar_carpeta();
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 10)
				{
					system("cls");
					printf("6");
					system("cls");
					printf("gracias por usar el programa");
					system("pause");
					exit(0);
				}
			}
		}
	}
}

void leertxt()
{
	char cadena[20];
	FILE *fichero;
	fichero = fopen("respaldo.txt", "r");
	while (!feof(fichero)) {
		fgets(cadena, 20, fichero);
	}
	fclose(fichero);
	cout << "Expresion =" << cadena;
	system("pause");
}

void menu() {
	int cont = 3;
	system("color f0");
	system("cls");
	string menu[] = {
		"1.- Conversion prefijo",
		"2.- Conversion postfijo",
		"3.- Salir             " };
	int cursor = 0;
	char tecla;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "                         CALCULADORA POLACA" << endl;
		for (int i = 0; i < 3; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == cont)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = cont - 1;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("cls");
					printf("\n================Conversion Prefijo================\n");
					menuTeclasPre();
					break;
				case 1:
					system("cls");
					printf("\n================Conversion Postfijo================\n");
					menuTeclas();
					break;
				case 2:
					system("cls");
					exit(1);
					break;
				}
			}
		}
	}
}

void menuTeclas() {
	system("color f0");
	string menu1[] = {
		"1.- Insertar Expresion",
		"2.- Ver datos (QR)    ",
		"3.- Calcular          ",
		"4.- Pdf               ",
		"5.- About             ",
		"6.- Regresar          " };
	Pila *pila1 = NULL;
	int cursor = 0;
	string cad;
	char tecla;
	char nombreArchivo[15] = "respaldo.txt";
	PilaGenerica pila;
	Expresion post;
	string cadena, cverdad;
	char cadena1[30];
	bool desapila;
	int n = -1, i = 0, num;
	char dato[25] = "";
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "                         CALCULADORA POLACA" << endl;
		cout << "                 Daniel Corral  -  Abigail Carvajal" << endl << endl;
		for (int i = 0; i < 6; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu1[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu1[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 6)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = 5;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("cls");
					printf("\n\n***************INFIJA A POSTFIJA***************\n\n");
					cout << "Ingrese funcion: " << endl;
					cin >> cadena;
					num = cadena.size();
					cverdad = postfija(cadena, num);
					guardar("EXPRESION POSTFIJA =", nombreArchivo);
					guardar(cadena, nombreArchivo);
					printf("\nPulse cualquier tecla para generar codigo QR...");
					_getch();

					for (i = 0; i < cverdad.size(); i++)
						cadena1[i] = cverdad[i];
					cadena1[i] = '\0';
					//generarQr(cadena1);
					pila.limpiarPila();
					menuTeclas();
					break;
				case 1:
					system("cls");
					crear_carpeta();
					printf("Respaldo guardado con exito\n");
					system("pause");
					break;
				case 2:
					system("cls");

					system("pause");
					menuTeclas();
					break;
				case 3:
					system("cls");
					menuTeclas();
					break;
				case 4:
					menuTeclas();
					break;
				case 5:
					menuMouse();//exit(1);
					break;
				}
				break;
			}
		}
	}
}

void menuTeclasPre() {
	system("color f0");
	string menu1[] = {
		"1.- Insertar Expresion",
		"2.- Ver datos (QR)    ",
		"3.- Calcular          ",
		"4.- Pdf               ",
		"5.- About             ",
		"6.- Regresar          " };
	Pila *pila1 = NULL;
	int cursor = 0;
	string cad;
	char tecla;
	char nombreArchivo[14] = "respaldo.txt";
	PilaGenerica pila;
	Expresion post;
	string cadena, cverdad;
	char cadena1[30];
	bool desapila;
	int n = -1, i = 0, num;

	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "                         CALCULADORA POLACA" << endl;
		cout << "                 Daniel Corral  -  Abigail Carvajal" << endl << endl;
		for (int i = 0; i < 6; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu1[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu1[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 6)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = 5;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("cls");
					printf("\n\n***************INFIJA A PREFIJA***************\n\n");
					cout << "Ingrese funcion: " << endl;
					cin >> cadena;
					num = cadena.size();
					cverdad = Prefija(cadena, num);
					//guardar("Prefija: ", nombreArchivo);
					guardar(cadena, nombreArchivo);
					system("pause");
					menuTeclas();
					break;
				case 1:
					system("cls");

					break;
				case 2:
					system("cls");

					menuTeclasPre();
					break;
				case 3:
					system("cls");
					menuTeclasPre();
					break;
				case 4:
					menuTeclasPre();
					break;
				case 5:
					menuMouse();//exit(1);
					break;
				}
				break;
			}
		}
	}
}

void asignar(string ope)
{
	string aux;
	string aux1;
	for (int i = 0; i < ope.length(); i++) //obtengo la longitud de la cadena ingresada
	{
		stringstream ss;
		Pila *auxp = pila;
		int ba = 0;
		ss << ope[i];
		ss >> aux;
		if (aux == "*" || aux == "+" || aux == "/" || aux == "^" || aux == "-" || aux == "(") //Identifico si esa posicion es un signo de interrogacion o un número
		{
			if (pila == NULL)
			{
				poner(aux);
			}
			else
			{
				switch (aux[0])
				{
					ba = 0;
				case '+':
					if (pila != NULL || pila->getDat() != "(" || pila->getDat() != "+")
					{
						do
						{
							aux1 = aux1 + pila->getDat();
							pila = pila->getSgt();
							if (pila != NULL)
							{
								if (pila->getDat() == "c")
									ba = 1;
							}
						} while (pila != NULL&&ba == 0);
					}
					if (pila == NULL || aux == "(")
					{
						poner(aux);

					}
					break;
				case '-':
				{
					if (pila != NULL || pila->getDat() != "(")
					{
						do
						{
							aux1 = aux1 + pila->getDat();
							pila = pila->getSgt();
							if (pila != NULL)
							{
								if (pila->getDat() == "c")
									ba = 1;
							}
						} while (pila != NULL&&ba == 0);
					}
					if (pila == NULL || aux == "(")
					{
						poner(aux);

					}
					break;
				case '*':
					if (pila != NULL || pila->getDat() != "(" || pila->getDat() != "+" || pila->getDat() != "-")
					{
						do
						{
							aux1 = aux1 + pila->getDat();
							pila = pila->getSgt();
							if (pila != NULL)
							{
								if (pila->getDat() == "c" || pila->getDat() != "+" || pila->getDat() != "-")
									ba = 1;
							}
						} while (pila != NULL&&ba == 0);
					}
					if (pila == NULL || aux == "(" || pila->getDat() != "+" || pila->getDat() != "-")
					{
						poner(aux);

					}
					break;
				case '/':
					if (pila != NULL || pila->getDat() != "(" || pila->getDat() != "+" || pila->getDat() != "-")
					{
						do
						{
							aux1 = aux1 + pila->getDat();
							pila = pila->getSgt();
							if (pila != NULL)
							{
								if (pila->getDat() == "c" || pila->getDat() != "+" || pila->getDat() != "-")
									ba = 1;
							}
						} while (pila != NULL&&ba == 0);
					}
					if (pila == NULL || aux == "(" || pila->getDat() != "+" || pila->getDat() != "-")
					{
						poner(aux);

					}
					break;
				}
				}
			}
		}
		else
		{
			aux1 = aux1 + aux;
		}
	}
	if (pila != NULL)
	{
		do
		{
			aux1 = aux1 + pila->getDat();

			pila = pila->getSgt();
		} while (pila != NULL);
	}

	printf("\n\t");
	cout << aux1;
}

bool valido(char expr[20]) {
	bool sw = true;
	for (int i = 0; (i<strlen(expr) && sw); i++) {
		char c;
		c = expr[i];
		sw = sw && (
			(c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9') ||
			(c == '^') || (c == '/') || (c == '*') ||
			(c == '+') || (c == '-') || (c == '\n') ||
			(c == '(') || (c == ')')
			);
	}
	return sw;
}

bool operando(char c) { //determina si el caracter es un operando
	return(c >= '0'&& c <= '9');
}

int prdadDentro(char operador) { //prioridad del operador en la expresion
	int pdp = 0;
	switch (operador) {
	case '^':
		pdp = 3;
		break;
	case '*': case '/':
		pdp = 2;
		break;
	case '+': case '-':
		pdp = 1;
		break;
	case '(':
		pdp = 0;

	}
	return pdp;
}

int prdadFuera(char operando) { //prioridad del operador en la expresion infija
	int pfp = 0;
	switch (operando)
	{
	case '^':
		pfp = 4;
		break;
	case '*': case '/':
		pfp = 2;
		break;
	case '+': case '-':
		pfp = 1;
		break;
	case '(':
		pfp = 5;
	}
	return pfp;
}

string postfija(string expresion, int num) {
	PilaGenerica pila;
	Expresion post;
	Elemento elemento[25];
	string tokens[25];
	char nombreArchivo[14] = "polaca.txt";
	string ch, opeCima;
	char dato[25] = "";
	int cont = 0, n = -1, i = 0;
	bool desapila;
	//Valido que la expresion sea valida
	if (!valido(expresion))
		printf("Caracter no valido en la expresion");

	for (int j = 0; j < num; j++) {
		//separo la expresion
		tokens[j] = separarDato(expresion, dato, j);
		ch = tokens[j];
		//cout << "\ntoken = " << ch.c_str();
		//printf("\n");
		if (operando(ch.c_str())) {
			n++;
			elemento[n].ope = ch.c_str();
			elemento[n].operador = false;
			guardar("Expresion :", nombreArchivo);
			guardar(elemento[n].ope.c_str(), nombreArchivo);
			//printf("\nELEMENTO = %s Operando = %d\n", elemento[n].ope.c_str(), elemento[n].operador);
		}
		else if (ch.compare(")")) {
			desapila = true;
			while (desapila) {
				opeCima = " ";
				if (!pila.pilaVacia()) {
					opeCima = pila.cimaPila();
				}
				if (pila.pilaVacia() || (prdadFuera(ch.c_str()) > prdadDentro(opeCima))) { //si la pila esta vacia o si la prioridad del caracter de fuera > prioridad que el que esta dentro
																						   //printf("\naqui llego 4 ch = %s", ch.c_str());
					pila.push(ch.c_str());
					desapila = false;

				}
				else if (prdadFuera(ch.c_str()) <= prdadDentro(opeCima)) {
					elemento[++n].ope = pila.pop();
					elemento[n].operador = true;
					guardar("Pila :", nombreArchivo);
					guardar(elemento[n].ope.c_str(), nombreArchivo);
					//printf("\naqui llego 5");
				}
			}
		}

		else { //si es )
			opeCima = pila.pop();
			if (opeCima.compare("(")) {
				//printf("\n\nOPECIMA = %s", opeCima.c_str());
				do {
					if (!pila.pilaVacia()) {
						elemento[++n].ope = opeCima;
						elemento[n].operador = true;
						opeCima = pila.pop();
						guardar("Pila :", nombreArchivo);
						guardar(elemento[n].ope.c_str(), nombreArchivo);
					}
					//printf("\n\nOPECIMA = %s",opeCima.c_str());
				} while (opeCima != "(");
			}
		}

	}

	while (!pila.pilaVacia()) {
		elemento[++n].ope = pila.pop();
		elemento[n].operador = true;
		guardar("Expresion :", nombreArchivo);
		guardar(elemento[n].ope.c_str(), nombreArchivo);
	}
	//Expresion post;
	post.expr = elemento;
	post.n = n;
	string cverdad;
	double valor, v[26];
	//printf("\ntotal elementos %d\n", n);
	cout << "\n\tExpresion Postfija:\t";
	for (int i = 0; i <= post.n; i++)
	{
		printf("%s ", post.expr[i].ope.c_str());
		cverdad.append(post.expr[i].ope.c_str());
	}

	valor = Evalua(post, v);
	cout << "\n\tValor de la expresion =  " << valor;

	return cverdad;
}

string Prefija(string expresion, int num) {
	PilaGenerica pila;
	Expresion pre;
	Elemento elemento[25];
	string tokens[25];
	string ch, opeCima, expresionV;
	char dato[25] = "";
	int cont = 0, n = -1, i = 0, h;
	bool desapila;
	char nombreArchivo[12] = "prefija.txt";

	//Valido que la expresion sea valida
	if (!valido(expresion))
		printf("Caracter no valido en la expresion");

	for (int j = 0; j < num; j++) {
		//separo la expresion
		tokens[j] = separarDato(expresion, dato, j);
	}
	for (int k = num - 1; k >= 0; k--) {
		ch = tokens[k];
		//cout << "\ntoken = " << ch.c_str();
		//printf("\n");
		if (operando(ch.c_str())) {
			n++;
			elemento[n].ope = ch.c_str();
			elemento[n].operador = false;
			guardar("Expresion :", nombreArchivo);
			guardar(elemento[n].ope.c_str(), nombreArchivo);
			//printf("\nELEMENTO = %s Operando = %d\n", elemento[n].ope.c_str(), elemento[n].operador);
		}
		else if (ch.compare("(")) {
			desapila = true;
			while (desapila) {
				opeCima = " ";
				if (!pila.pilaVacia()) {
					opeCima = pila.cimaPila();
				}
				if (pila.pilaVacia() || (prdadFueraPre(ch.c_str()) >= prdadDentroPre(opeCima))) { //si la pila esta vacia o si la prioridad del caracter de fuera > prioridad que el que esta dentro
																								  //printf("\naqui llego 4 ch = %s", ch.c_str());
					pila.push(ch.c_str());
					desapila = false;

				}
				else if (prdadFueraPre(ch.c_str()) < prdadDentroPre(opeCima)) {
					elemento[++n].ope = pila.pop();
					elemento[n].operador = true;
					guardar("Pila :", nombreArchivo);
					guardar(elemento[n].ope.c_str(), nombreArchivo);
					//printf("\naqui llego 5");
				}
			}
		}

		else { //si es (
			opeCima = pila.pop();
			if (opeCima.compare(")")) {
				//printf("\n\nOPECIMA = %s", opeCima.c_str());
				do {
					elemento[++n].ope = opeCima;
					elemento[n].operador = true;
					opeCima = pila.pop();
					guardar("Expresion :", nombreArchivo);
					guardar(elemento[n].ope.c_str(), nombreArchivo);
					//printf("\n\nOPECIMA = %s",opeCima.c_str());
				} while (opeCima != ")");
			}
		}
	}

	while (!pila.pilaVacia()) {
		elemento[++n].ope = pila.pop();
		elemento[n].operador = true;
		guardar("Expresion :", nombreArchivo);
		guardar(elemento[n].ope.c_str(), nombreArchivo);
	}
	//Expresion pre;
	pre.expr = elemento;
	pre.n = n;
	string cverdad;
	double valor, v[26];
	//printf("\ntotal elementos %d\n", n);
	cout << "\n\tExpresion Prefija:\t";
	for (int i = pre.n; i >= 0; i--)
	{
		printf("%s ", pre.expr[i].ope.c_str());
		cverdad.append(pre.expr[i].ope.c_str());
	}
	postfija(expresion, num);
	/*valor = Evalua(post, v);
	cout << "\n Valor de la expresion =  " << valor;*/
	/*cout << "EXPRE" << cverdad;
	system("pause");*/
	return cverdad;
}

double Evalua(Expresion postfija, double v[]) {
	PilaGenericaD pilaGen;
	double valor, a, b;
	int cont = 0;
	for (int i = 0; i <= postfija.n; i++) {
		string op;
		if (postfija.expr[i].operador) {
			op = postfija.expr[i].ope;
			/*printf("operador: %s\n", op.c_str());*/
			if (!op.compare("sen") || !op.compare("cos") || !op.compare("tan")) {
				if (cont != 1) {
					b = pilaGen.pop();
					a = pilaGen.pop();
					/*printf(" \na: %f\n", a);
					printf(" \nb:%f\n", b);*/
					if (!op.compare("sen")) {
						valor = sin(b);
					}
					else if (!op.compare("cos")) {
						valor = cos(b);
					}
					else if (!op.compare("tan")) {
						valor = tan(b);
					}
					pilaGen.push(a);
					pilaGen.push(valor);
				}
				else {
					a = pilaGen.pop();
					if (!op.compare("sen")) {
						valor = sin(a);
					}
					else if (!op.compare("cos")) {
						valor = cos(a);
					}
					else if (!op.compare("tan")) {
						valor = tan(a);
					}
					pilaGen.push(valor);
				}


			}
			else if (!op.compare("+") || !op.compare("-") || !op.compare("*") || !op.compare("/") || !op.compare("^")) {
				b = pilaGen.pop();
				a = pilaGen.pop();
				/*printf(" \nImprimen en else a: %f\n", a);
				printf(" \nImprime en else b:%f\n", b);
				printf("operador: %s\n", op.c_str());*/
				if (!op.compare("^")) {
					valor = pow(a, b);
				}
				else if (!op.compare("*")) {
					valor = a*b;
				}
				else if (!op.compare("/")) {
					if (b != 0.0)
						valor = a / b;
					else {
						printf("\nNo se puede realizar division para cero\nIntente ingresando otra expresion!");
						_getch();
						menuTeclas();
						break;
					}

				}
				else if (!op.compare("+")) {
					valor = a + b;
				}
				else if (!op.compare("-")) {
					valor = a - b;
				}
				pilaGen.push(valor);
			}

		}
		else {
			int indice;
			double aa;
			op = postfija.expr[i].ope;
			aa = atof(op.c_str());
			pilaGen.push(aa);
			cont++;
		}
	}

	return pilaGen.pop();
}

string separarDato(string expresion, char *dato, int &pos)
{
	string aux;
	char p, p1[2];
	p = expresion[pos];
	//printf("\np : %c\n", p);
	if (p == '+' || p == '-' || p == '*' || p == '/' || p == '^' || p == '(' || p == ')')
	{
		p1[0] = p;
		p1[1] = '\0';
		strcpy(dato, p1);
		//pos++;
		aux = dato;
		//cout << "\nen if dato: " << dato<<"posicion ="<<pos;
		return aux;
	}
	else
	{
		p1[0] = '\0';
		strcpy(dato, p1);
		do
		{
			p = expresion[pos];
			if (p == '\0' || p == '+' || p == '-' || p == '*' || p == '/' || p == '^' || p == '(' || p == ')')break;
			p1[0] = p;
			p1[1] = '\0';
			strcat(dato, p1);
			//printf(" p es: %c \n", p);
			pos++;
		} while (true);
		pos--;
		//if (strcmp(dato, "sen") == 0) strcpy(dato, "sen");
		//if (strcmp(dato, "cos") == 0) strcpy(dato, "cos");
		//if (strcmp(dato, "tan") == 0) strcpy(dato, "tan");
	}

	//cout << "\ndato: " << dato;
	aux = dato;
	return aux;
}

bool valido(string expr) {
	bool sw = true;
	for (int i = 0; (i<expr.size() && sw); i++) {
		string c;
		c = expr[i];
		sw = sw && (
			(c >= "A" && c <= "Z") ||
			(c >= "a" && c <= "z") ||
			(c >= "0" && c <= "9") ||
			(c == "^") || (c == "/") || (c == "*") ||
			(c == "+") || (c == "-") || (c == "\n") ||
			(c == "(") || (c == ")")
			);
	}
	return sw;
}

bool operando(string c) { //determina si el caracter es un operando
	return(c >= "0" && c <= "999");
}

int prdadDentro(string operador) { //prioridad del operador en la expresion (dentro de la pila)
	int pdp = 0;

	if (operador == "^" || operador == "sen" || operador == "cos" || operador == "tan")
		pdp = 3;
	else if (operador == "*" || operador == "/")
		pdp = 2;
	else if (operador == "+" || operador == "-")
		pdp = 1;
	else if (operador == "(")
		pdp = 0;
	return pdp;
}

int prdadFuera(string operando) { //prioridad del operador en la expresion infija
	int pfp = 0;
	if (operando == "^" || operando == "sen" || operando == "cos" || operando == "tan")
		pfp = 4;
	else if (operando == "*" || operando == "/")
		pfp = 2;
	else if (operando == "+" || operando == "-")
		pfp = 1;
	else if (operando == "(")
		pfp = 5;
	return pfp;
}

void guardar(string expresion, char *archivo) {
	FILE *ptr;
	string nombre;

	ptr = fopen(archivo, "a"); //REALIZO LA APERTURA DEL ARCHIVO
	if (ptr == NULL)
	{
		printf("ERROR.\n");
	}
	else
	{
		expresion += "\n";
		nombre = expresion.c_str();
		//fputs(nombre,ptr);
		fprintf(ptr, " %s", nombre.c_str());

		fclose(ptr);
	}
}

/*
void generarQrBasico(char dato1[]) {
	char *dato = dato1;  // User-supplied text
	enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;  // Error correction level

													   // Make and print the QR Code symbol
	uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
	uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
	bool ok = qrcodegen_encodeText(dato, tempBuffer, qrcode, errCorLvl,
		qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
	if (ok)
		printQr(qrcode);
}*/

static void printQr(const uint8_t qrcode[]) {
	int size = qrcodegen_getSize(qrcode);
	int border = 4;
	for (int y = -border; y < size + border; y++) {
		for (int x = -border; x < size + border; x++) {
			fputs((qrcodegen_getModule(qrcode, x, y) ? "\333\333" : "  "), stdout);
		}
		fputs("\n", stdout);
	}
}
/*
static void generarQr(char *mensaje)
{
	printf("GENERADOR DE QR\n");
	generarQrBasico(mensaje);
	system("pause");
}
*/
int prdadDentroPre(string operador) { //prioridad del operador en la expresion (dentro de la pila)
	int pdp = 0;

	if (operador == "^" || operador == "sen" || operador == "cos" || operador == "tan")
		pdp = 3;
	else if (operador == "*" || operador == "/")
		pdp = 2;
	else if (operador == "+" || operador == "-")
		pdp = 1;
	else if (operador == ")")
		pdp = 0;
	return pdp;
}

int prdadFueraPre(string operando) { //prioridad del operador en la expresion infija
	int pfp = 0;
	if (operando == "^" || operando == "sen" || operando == "cos" || operando == "tan")
		pfp = 4;
	else if (operando == "*" || operando == "/")
		pfp = 2;
	else if (operando == "+" || operando == "-")
		pfp = 1;
	else if (operando == ")")
		pfp = 5;
	return pfp;
}

void crear_carpeta()
{
	//genera dia mes año
	time_t t;
	struct tm *tm;
	char fechayhora[100];

	t = time(NULL);
	tm = localtime(&t);
	strftime(fechayhora, 100, "%d-%m-%Y", tm);

	//genera hora minutos segundos
	time_t current_time;
	struct tm * time_info;
	char timeString[9];

	time(&current_time);
	time_info = localtime(&current_time);

	strftime(timeString, sizeof(timeString), "%H-%M-%S", time_info);
	//puts(timeString);

	//creacion de carpeta en directorio especifico
	string ruta, nombre_carpeta, ruta_absoluta, rutaprueba;

	//INGRESAR RUTA ABSOLUTA
	printf("Ingrese Ruta Donde crear carpeta\n");
	fflush(stdin);
	//getline(cin, ruta);
	fflush(stdin);
	// printf("Ingrese Nombre de la carpeta\n");
	//fflush(stdin);
	// getline(cin,nombre_carpeta);
	rutaprueba += "C:\\Users\\Administrador1\\Desktop\\pp1\\Carvajal_Corral_C.Polaca\\Carvajal_Corral_C.Polaca\\ProyectoPolaca\\Respaldos\\";
	ruta_absoluta = rutaprueba + "Hora " + timeString + " Fecha " + fechayhora;
	if (_mkdir(ruta_absoluta.c_str()) == 0)//para comprobar si se cre la carpeta 0 si esta correcta
	{
		printf("\ncarpeta creada correctamente\n");
	}
	else {
		printf("\nerror al crear carpeta\n");
	}
	//creacion de archivo en la carpeta creada
	string nombre_archivo = "respaldo ", ruta_absoluta_archivo, o;
	printf("Ingrese Nombre para el archivo de respaldo\n");
	fflush(stdin);
	// getline(cin,nombre_archivo);
	ruta_absoluta_archivo = ruta_absoluta + "\\" + nombre_archivo + "-" + timeString + " - " + fechayhora + ".txt";
	FILE *arch;
	if (arch = fopen(ruta_absoluta_archivo.c_str(), "a"))
	{
		printf("\nArchivo creado ");
	}
	else {
		printf("error al crear archivo");
	}
}


void recuperar_carpeta(){


}
