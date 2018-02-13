/******************************************************
*       UNIVERSIDAD DE LAS FUERZAS ARMADAS           **
*                    ESPE                            **
*                                                    **
*   Proyecto Segundo Parcial Estructura de Datos      **
*                   pilas			                 **
*Tema:                                               **
*       calculadora polaca                           **
*Autores:                                            **
*       Benitez Rodriguez Luis Guillermo             **
*       Vaca Perez Vicente Xavier                    **
*Fecha de Entrega: 2018-01-22                        **
*Carrera: Ingenieria en Sistemas e Informatica       **
*Profesor: Ing Fernando Solis                        **
*******************************************************/



// ProyectoPolaca.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>//mkdir
#include <time.h>
#include <ctime>
#include "Pila.h"
#include "Nodo.h"
#include "PilaGenerica.h"
#include "PilaGenericaD.h"
#include "qrcodegen.h"
#define fondo 0
#define texto 3

struct Elemento {
	string ope;
	bool operador;
};

struct Expresion {
	Elemento* expr;
	int n;
};

using namespace std;
void inicio();
void menuTeclas();
void menuTeclasPre();
void asignar(string);
bool valido(string);
bool operando(string c);
int prdadDentro(string operador);
int prdadFuera(string operando);
string postfija(string, int);
string separarDato(string , char *dato, int &pos);
void guardar(string , char *archivo);
double Evalua(Expresion postfija, double v[]);
void  generarQr(char *);
static void generarQrBasico(char dato1[]);
static void printQr(const uint8_t qrcode[]);
string Prefija(string expresion, int num);
int prdadDentroPre(string operador);
int prdadFueraPre(string operando);
void crear_carpeta();
void menuMouse();
void leertxt();
void guardarAg(string expresion, char *archivo);

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

void ayuda()
{
	system("ayuda.chm");
}
void about()
{
	system("about.jpg");
}
void agente()
{
	system("WinAppManejoMSAgente.exe");
}
int main() {
	system("color 0A");
	inicio();
	menuMouse();
	system("color 0A");
	return 0;
}

void guardarAg(string expresion, char *archivo) {
	system("color 0A");
	FILE *ptr;
	string nombre;

	ptr = fopen(archivo, "w"); //REALIZO LA APERTURA DEL ARCHIVO
	if (ptr == NULL)
	{
		printf("ERROR.\n");
	}
	else
	{
		nombre = expresion.c_str();
		//fputs(nombre,ptr);
		fprintf(ptr, "%s \n", nombre.c_str());
		fclose(ptr);
	}
}

void menuMouse() {
	string palabra1;
	system("cls");
	system("color 0A");
	cout << "\t\t\t ";
	cout << " CALCULADORA POLACA" << endl;
	printf(" 1. Prefijo\n");
	printf(" 2. Posfijo\n");
	printf(" 3. Ver Expresion Ingresada\n");
	printf(" 4. Ayuda\n");
	printf(" 5. About\n");
	printf(" 6. Agente\n");
	printf(" 7. Salir\n");
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
					printf("\n===================Conversion Prefijo===================\n");
					menuTeclasPre();
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 2)
				{
					system("cls");
					printf("\n===================Conversion Postfijo===================\n");
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
					system("color 0A");
					system("cls");
					about();
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 6)
				{
					system("color 0A");
					system("cls");
					agente();
					system("cls");
					system("pause");
					menuMouse();
				
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 7)
				{
					
					system("color 0A");
					system("cls");
					//system("pause");
					system("respaldo.txt");
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
string leertxt1()
{
	char cadena[20];
	FILE *fichero;
	fichero = fopen("respaldo.txt", "r");
	while (!feof(fichero)) {
		fgets(cadena, 20, fichero);
	}
	fclose(fichero);
	cout << "Expresion =" << cadena;
	return cadena;
}
void menuTeclas() {
	system("color 0A");
	string menu1[] = {
		"1.- Ingresar Expresion",
		"2.- Generar Backup",
		"3.- Regresar" };
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
	int n = -1, i = 0,num;
	char dato[25] = "";
	for (;;) {
		system("color 0A");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		system("color 0A");
		cout << "===================CALCULADORA POLACA===================" << endl;
		for (int i = 0; i < 3; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
				cout << menu1[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu1[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 3)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = 2;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("color 0A");
					system("cls");
					printf("\n\n===================INFIJA A POSTFIJA===================\n\n");
					cout << "Ingrese funcion: " << endl;
					cin >> cadena;
					num = cadena.size();
					cverdad=postfija(cadena,num);
					guardar("EXPRESION POSTFIJA =", nombreArchivo);
					guardar(cadena, nombreArchivo);
					printf("\nPulse Enter para generar codigo QR...");
					system("pause");
					//getch();
					system("color F0");
					for (i = 0; i < cverdad.size(); i++)
						cadena1[i] = cverdad[i];
					cadena1[i] = '\0';
					generarQr(cadena1);
					pila.limpiarPila();
					getch();
					menuTeclas();
					break;
				case 1:
					system("color 0A");
					system("cls");
					crear_carpeta();
					printf("Respaldo guardado con exito\n");
					system("pause");
					break;
				case 2:
					menuMouse();
					break;
				}
				break;
			}
		}
	}
}

void menuTeclasPre() {
	system("color 0A");
	string menu1[] = {
		"1.- Ingrese Expresion",
		"2.- Generar Backup",
		"3.- Regresar" };
	Pila *pila1 = NULL;
	int cursor = 0;
	string cad;
	char tecla;
	system("color 0A");
	char nombreArchivo[14] ="prefija.txt";
	system("color 0A");
	PilaGenerica pila;
	Expresion post;
	string cadena, cverdad;
	char cadena1[30];
	bool desapila;
	int n = -1, i = 0, num;

	for (;;) {
		system("color 0A");
		system("cls");
		system("color 0A");
		//FOREGROUND_GREEN
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250);
		system("color 0A");
		cout << "===================CALCULADORA POLACA===================" << endl;
		//system("color 0A");
		for (int i = 0; i < 3; i++) {
			//
			if (cursor == i) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
				cout << menu1[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu1[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 3)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = 2;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("color 0A");
					system("cls");
					system("color 0A");
					printf("\n\n===================INFIJA A PREFIJA===================\n\n");
					system("color 0A");
					cout << "Ingrese funcion: " << endl;
					system("color 0A");
					//
					cin >> cadena;
					num = cadena.size();
					cverdad = Prefija(cadena, num);
					guardar(cadena, nombreArchivo);

					getch();
					menuTeclas();
					//
					/*
					cin >> cadena;
					num = cadena.size();
					cverdad = Prefija(cadena, num);
					guardar(cadena, nombreArchivo);
					system("pause");
					menuTeclas();*/
					break;
				case 1:
					system("color 0A");
					system("cls");
					crear_carpeta();
					printf("Respaldo guardado con exito\n");
					system("pause");
					
					break;
				case 2:
					system("color 0A");
					system("cls");

					menuMouse();
					break;
				/*case 3:
					system("color 0A");
					system("cls");
					menuTeclasPre();
					break;				
				case 4:
					system("color 0A");
					menuMouse();//exit(1);
					break;*/
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
	/*bool sw = true;
	for (int i = 0; (i<strlen(expr) && sw); i++) {


		
		char c;
		c = expr[i];
		sw = sw && (
			//(c >= 'A' && c <= 'Z') ||
			//(c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9') ||
			(c == '^') || (c == '/') || (c == '*') ||
			(c == '+') || (c == '-') || (c == '\n') ||
			(c == '(') || (c == ')')
			);
	}
	return sw;*/
}

bool operando(char c) { //determina si el caracter es un operando
	return(c >= '0'&& c <= '9');
}

int prdadDentro(char operador) { //prioridad del operador en la expresion
	int pdp=0;
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
	int pfp=0;
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
	system("color 0A");
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
	/*if (!valido(expresion)) {
		system("color 0A");
		system("cls");
		printf("\nCaracter no valido en la expresion\nIntente ingresando nuevamente la cadena");
		getch();
		menuTeclas();
	}*/
		

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
				} while (opeCima != "(" );
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
	guardarAg(cverdad, nombreArchivo);

	system("Start G:/Documentos/GitHub/proyecto-primer-parcial/Proyecto_1er_Parcial_boletos_1_bus/Proyecto2doParcial/CalculadoraPolaca/ProyectoPolaca/WinAppMSAgentsManagement/WinAppMSAgentsManagement/bin/Debug/WinAppMSAgentsManagement.exe");
	valor = Evalua(post, v);
	cout << "\n\tValor de la expresion =  " << valor;
	
	return cverdad;
}

string Prefija(string expresion,int num) {
	PilaGenerica pila;
	Expresion pre;
	Elemento elemento[25];
	string tokens[25];
	string ch, opeCima, expresionV;
	char dato[25] = "";
	int cont = 0, n = -1, i = 0,h;
	bool desapila;
	char nombreArchivo[13] = "respaldo.txt";
	system("color 0A");
	//Valido que la expresion sea valida
	if (!valido(expresion))
	{
		system("cls");
		printf("\nCaracter no valido en la expresion\n");
		//system("pause");
		getch();		
		menuTeclasPre();
	}
		

	for (int j = 0; j < num; j++) {
		//separo la expresion
		tokens[j] = separarDato(expresion, dato, j);
	}
	for (int k = num-1; k >= 0; k--) {
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
	guardarAg(cverdad, nombreArchivo);

	system("Start G:/Documentos/GitHub/proyecto-primer-parcial/Proyecto_1er_Parcial_boletos_1_bus/Proyecto2doParcial/CalculadoraPolaca/ProyectoPolaca/WinAppMSAgentsManagement/WinAppMSAgentsManagement/bin/Debug/WinAppMSAgentsManagement.exe");
	
	/*valor = Evalua(post, v);
	cout << "\n Valor de la expresion =  " << valor;*/
	//cout << "EXPRE" << cverdad;
	
	return cverdad;
}

double Evalua(Expresion postfija, double v[]) {
	/*
	PilaGenericaD pilaGen;
	double valor, a, b;
	int cont = 0;
	for (int i = 0; i <= postfija.n ; i++) {
		string op;
		if (postfija.expr[i].operador) {
			op = postfija.expr[i].ope;
			///printf("operador: %s\n", op.c_str());
			if (!op.compare("sen") || !op.compare("cos") || !op.compare("tan")) {
				if (cont != 1) {
					b = pilaGen.pop();
					a = pilaGen.pop();
					//printf(" \na: %f\n", a);
					//printf(" \nb:%f\n", b);
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
			else if(!op.compare("+") || !op.compare("-") || !op.compare("*") || !op.compare("/") || !op.compare("^")) {
				b = pilaGen.pop();
				a = pilaGen.pop();
				///printf(" \nImprimen en else a: %f\n", a);
				//printf(" \nImprime en else b:%f\n", b);
				//printf("operador: %s\n", op.c_str());
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
						getch();
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

	return pilaGen.pop();*/


	PilaGenericaD pilaGen;
	double valor, a, b;
	int cont = 0;
	/*string ep = postfija.expr[0].ope;
	if (!ep.compare("+") || !ep.compare("-") || !ep.compare("*") || !ep.compare("/") || !ep.compare("^")) {
	printf("\t\nNo se puede evaluar un solo signo\n\tIntente ingresando nuevamente\n");
	getch();
	menuPrefija();
	}*/
	/*else {
	string aux1;
	string aux = postfija.expr[1].ope;
	if (!aux.compare("+") || !ep.compare("-")) {
	aux1.append(aux);
	aux1.append(ep);
	return atof(aux1.c_str());
	}
	else
	return atof(ep.c_str());
	}*/
	//else {
	for (int i = 0; i <= postfija.n; i++) {
		string op;
		if (postfija.expr[i].operador) {
			op = postfija.expr[i].ope;
			/*printf("operador: %s\n", op.c_str());*/
			if (!op.compare("sen") || !op.compare("cos") || !op.compare("tan") || !op.compare("sqrt")) {
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
					else if (!op.compare("sqrt")) {
						valor = sqrt(b);
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
					else if (!op.compare("sqrt")) {
						valor = sqrt(a);
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
						getch();
						menuTeclasPre();
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
{/*
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
	return aux;*/

	//
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
			//printf(" \np es: %c \n", p);
			pos++;
		} while (true);
		pos--;
		//if (strcmp(dato, "sen") == 0) strcpy(dato, "sen");
		//if (strcmp(dato, "cos") == 0) strcpy(dato, "cos");
		//if (strcmp(dato, "tan") == 0) strcpy(dato, "tan");
	}

	//cout << "\ndato: " << dato<< "posicion"<< pos;
	aux = dato;
	return aux;

	//
}

bool valido(string expr) {
	bool sw = true;
	printf("expresion %s:", expr.c_str());
	system("pause");
	for (int i = 0; (i<expr.size() && sw); i++) {
		string c;
		c = expr[i];
		sw = sw && (
			(c >= "a" || c <= "z") ||
			(c >= "0" && c <= "9") ||
			(c == "^") || (c == "/") || (c == "*") ||
			(c == "+") || (c == "-") || (c == "\n") ||
			(c == "(") || (c == ")")
			);
	}
	return sw;
	/*
	bool sw = true;
	for (int i = 0; (i<expr.size() && sw); i++) {
		string c;
		c = expr[i];
		sw = sw && (			
			(c >= "0" && c <= "9") ||
			(c == "^") || (c == "/") || (c == "*") ||
			(c == "+") || (c == "-") || (c == "\n") ||
			(c == "(") || (c == ")") || (c == "s") || (c == "e") || (c == "n")
			|| (c == "c") || (c == "o")|| (c == "t") || (c == "a")
			);
	}
	return sw;*/
}


bool valido2(string expresion[25]) {
	bool sw = true;
	for (int i = 0; i<25; i++) {
		if (!expresion[i].compare("sen") || !expresion[i].compare("0") || !expresion[i].compare("1") || !expresion[i].compare("2") || !expresion[i].compare("3") ||
			!expresion[i].compare("4") || !expresion[i].compare("5") || !expresion[i].compare("6") || !expresion[i].compare("7") || !expresion[i].compare("8") ||
			!expresion[i].compare("(") || !expresion[i].compare(")") || !expresion[i].compare("+") || !expresion[i].compare("-") || !expresion[i].compare("*") ||
			!expresion[i].compare("/") || !expresion[i].compare("cos") || !expresion[i].compare("tan") || !expresion[i].compare("\0") || !expresion[i].compare("^") || !expresion[i].compare("sqrt"))
		{
			sw = sw && true;
			//printf("validar en funcion = %d", sw);
		}
		else if (operando(expresion[i])) {
			sw = sw && true;
		}
		else {
			sw = sw && false;
			printf("validar en funcion = %d", sw);
		}
	}

	return sw;
}
bool operando(string c) { //determina si el caracter es un operando
	
	return(c >= "0" && c <= "999");
}

int prdadDentro(string operador) { //prioridad del operador en la expresion (dentro de la pila)
	int pdp = 0;

	if (operador == "^" || operador == "sen" || operador =="cos" || operador =="tan")
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
	if (operando == "^" || operando == "sen" || operando=="cos"|| operando=="tan")
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
}

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

static void generarQr(char *mensaje)
{
	printf("GENERADOR DE QR\n");
	generarQrBasico(mensaje);
	system("pause");
}

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
	string ruta, nombre_carpeta, ruta_absoluta,rutaprueba;

	//INGRESAR RUTA ABSOLUTA
	//printf("Ingrese Ruta Donde crear carpeta\n");
	fflush(stdin);
	//getline(cin, ruta);
	fflush(stdin);
	// printf("Ingrese Nombre de la carpeta\n");
	//fflush(stdin);
	// getline(cin,nombre_carpeta);
	rutaprueba += "C:\\Users\\luigu\\Desktop\\RespaldoPolaca\\";
	ruta_absoluta = rutaprueba + "H" + timeString + "F" + fechayhora;
	if (mkdir(ruta_absoluta.c_str()) == 0)//para comprobar si se cre la carpeta 0 si esta correcta
	{
		printf("\ncarpeta creada correctamente\n");
	}
	else {
		printf("\nerror al crear carpeta\n");
	}
	//creacion de archivo en la carpeta creada
	string nombre_archivo = "rsp", ruta_absoluta_archivo, o,cad;
	//printf("Ingrese Nombre para el archivo de respaldo\n");
	fflush(stdin);
	// getline(cin,nombre_archivo);
	ruta_absoluta_archivo = ruta_absoluta + "\\" + nombre_archivo + "-" + timeString + "-" + fechayhora + ".txt";
	FILE *arch;
	if (arch = fopen(ruta_absoluta_archivo.c_str(), "a"))
	{
		printf("\nArchivo creado ");
		cad = leertxt1();
		fprintf(arch, " %s", cad.c_str());
	}
	else {
		printf("error al crear archivo");
	}
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
	FILE *INICIO;
	INICIO = fopen("ARCHIVOS/INICIO.txt", "r");
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
	while (!feof(INICIO))
	{
		fgets(caracter, 130, INICIO);
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
