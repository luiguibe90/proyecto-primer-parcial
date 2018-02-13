/******************************************************
*       UNIVERSIDAD DE LAS FUERZAS ARMADAS           **
*                    ESPE                            **
*                                                    **
*   Proyecto Tercer Parcial Estructura de Datos      **
*                   Arboles		                     **
*Tema:                                               **
*       Graficacion de Arboles Binario, B, B+ AVL    **
*Autores:                                            **
*       Benitez Rodriguez Luis Guillermo             **
*       Vaca Perez Vicente Xavier                    **
*Fecha de Entrega: 2018-02-16                        **
*Carrera: Ingenieria en Sistemas e Informatica       **
*Profesor: Ing Fernando Solis                        **
*******************************************************/
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
#include "qrcodegen.h"
#define fondo 0
#define texto 10
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
//2-6-7-9
using namespace std;

//prototipo de funciones
void inicio();
void menuTeclas();
void menuMouse();
int menuGeneralArboles();
void guardar(string , char *archivo);
void  generarQr(char *);
static void generarQrBasico(char dato1[]);
static void printQr(const uint8_t qrcode[]);
void crear_carpeta();
void leertxt();
string leertxt1();
void guardarAg(string , char *);


//desarrollo de funciones
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
void ayuda(){
	system("ayuda.chm");
}
void about(){
	system("about.jpg");
}
void agente(){
	system("WinAppManejoMSAgente.exe");
}
int main(){
	color(fondo, texto);
	//system("color 0A");
	inicio();
	menuMouse();
	//system("color 0A");
	return 0;
}
void guardarAg(string expresion, char *archivo) {
	color(fondo, texto);
	//system("color 0A");
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

void leertxt(){
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
string leertxt1(){
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
void crear_carpeta(){
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

void menuMouse() {
	string palabra1;
	system("cls");
	color(fondo, texto);
	//color(3, 15);
	cout << "\n\n\n\n\n\n\n\t\t\t ";
	cout << "_______________________ARBOLES_______________________" << endl;
	gotoxy(22,10); printf("\t\t\t 1. ARBOL BINARIO\n");
	gotoxy(22, 11); printf("\t\t\t 2. ARBOL B\n");
	gotoxy(22, 12); printf("\t\t\t 3. ARBOL B+\n");
	gotoxy(22, 13); printf("\t\t\t 4. ARBOL AVL\n");
	gotoxy(22, 14); printf("\t\t\t 5. VER DATOS INGRESADOS\n");
	gotoxy(22, 15); printf("\t\t\t 6. AYUDA\n");
	gotoxy(22, 16); printf("\t\t\t 7. ABOUT\n");
	gotoxy(22, 17); printf("\t\t\t 8. AGENTE\n");
	gotoxy(22, 18); printf("\t\t\t 9. SALIR - GENERAR PDF\n");
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
				if (coordenadas.X >=40 && coordenadas.X <= 62 && coordenadas.Y == 10)//1
				{
					system("cls");
					printf("\n\t\t  ===================ARBOL BINARIO ===================\n");
					menuGeneralArboles();
					menuMouse();
				}

				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 11)//2
				{
					system("cls");
					printf("\n\t\t  =================== ARBOL B ===================\n");
					menuGeneralArboles();
					menuMouse();

				}
				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 12)//3
				{
					system("cls");
					printf("\n\t\t  =================== ARBOL B+ ===================\n");
					menuGeneralArboles();
					menuMouse();

				}
				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 13)//4
				{
					system("cls");
					printf("\n\t\t  ===================ARBOL AVL===================\n");
					menuGeneralArboles();
					menuMouse();

				}
				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 14)//5
				{
					system("cls");
					leertxt();
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 15)//6
				{
					system("cls");
					ayuda();
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 16)//7
				{
					//system("color 0A");
					system("cls");
					about();
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 17)//8
				{
					//system("color 0A");
					system("cls");
					agente();
					system("cls");
					system("pause");
					menuMouse();
				}
				if (coordenadas.X >= 40 && coordenadas.X <= 62 && coordenadas.Y == 18)//9
				{
					//system("color 0A");
					system("cls");
					//system("pause");
					system("respaldo.txt");
					exit(0);
				}
			}
		}
	}
}
int menuGeneralArboles() {

	const char *titulo = "__________________________________________________________";
	const char *opciones[] = { "INSERTAR CLAVE","ELIMINAR CLAVE","BUSCAR CLAVE","MOSTRAR ARBOL ","GRAFICAR ARBOL", "REGRESAR"};
	int opcionSeleccionada = 1, numerodeopciones = 6;
	int tecla;
	bool repite = true;
	int i = 0;
	do {
		//system("cls");
		gotoxy(7, 3 + opcionSeleccionada);
		color(fondo, texto);
		gotoxy(15, 2);
		printf("%s", titulo);
		gotoxy(5, 3 + opcionSeleccionada);
		for (int i = 0; i < numerodeopciones; ++i) {
			gotoxy(15, 4 + i);
			color(fondo, texto);
			printf("%s  ", opciones[i]);
		}//2-6-7-9-12rojo-14-15
		gotoxy(15, 3 + opcionSeleccionada);
		color(9, 15);
		//color(12, 15);
		printf("%s", opciones[i]);
		color(fondo, texto);
		do {
			tecla = getch();
		} while ((tecla != TECLA_ARRIBA) && (tecla != TECLA_ABAJO) && (tecla != ENTER));

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
		case ENTER:
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
	gotoxy(40, 25); printf("ARBOLES-> BINARIO - B - B+ - AVL\n");
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
