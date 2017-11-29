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

//declaracion de estructura para listas dobles

//estructuras anidadas
struct datos_Fecha{
   char *fecha;
   char salida[25];
};

//estructura principal
struct Nodo{
    char nombre[25];
    char apellido[25];
    int cedula;
    int nroAsiento;
    int datoEntero;
    datos_Fecha ingresofecha; //estructuras anidadas
    Nodo *siguiente;
    Nodo *anterior;
};
typedef struct Nodo *ListaDoble;


//declaracion de prototipos de funciones
int ingreso_usuario();
void incializarDatos(ListaDoble &);
int ObtenerEnteroPositivo();
char *ingresarString(char *);
void insertarDatosClientePosicion(ListaDoble &);
void cancelarBoleto(ListaDoble &,int);
void buscarCliente(ListaDoble );
void mostrarAsientos(ListaDoble );
void mostrarDatos(ListaDoble );
void creaBackup(ListaDoble ,FILE *);
void ayuda();
void about();
void qr();
void insElemInicio(ListaDoble &);
void insElemFin(ListaDoble &);
int insElemAntes(ListaDoble &, int ,int);
int insElemDespues(ListaDoble &,int,int);
int validarCedula(int*,int *);
void gotoxy(int,int);
void color(int,int);
int menu();
int menuSN();
int menuRV();
void inicio ();

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

int ingreso_usuario(){
    string usuario, password;
    int contador = 0;
    bool ingresa = false;
    char caracter;
    int contrasena_correcta=0;
    do {
        system("cls");
        system("color 03");//color fondo-letra
        for (int i=5;i<51;i++)//inicio barras de menu
        {
            gotoxy(i,3);printf("%c",223);
        }
        for (int i=1;i<9;i++)
        {
            gotoxy(5,i);printf("%c",219);
        }
        for (int i=1;i<9;i++)
        {
            gotoxy(50,i);printf("%c",219);
        }
        for (int i=5;i<51;i++)
        {
            gotoxy(i,9);printf("%c",223);
        }//fin barras de menu

        gotoxy(20,1);cout<<"LOGIN DE USUARIO";
        gotoxy(8,4);cout<<"USUARIO: ";
                    fflush(stdin);
                    getline(cin, usuario);
        gotoxy(8,5);cout<<"PASSWORD: ";
        fflush(stdin);
        caracter = getch();
        password = "";
        while((caracter)!=13)
     // while (caracter != ENTER)
        {
         if (caracter != BACKSPACE) {
             password.push_back(caracter);
             cout << "*";
            } else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
      }
      if (usuario == USER && password == PASS) {
         ingresa = true;
         contrasena_correcta=1;
      } else {
         gotoxy(8,8);cout << "El usuario y/o password son incorrectos";
         cin.get();
         contador++;
         contrasena_correcta=0;
      }
    } while (ingresa == false && contador < 3);

    if (ingresa == false)
    {
      gotoxy(8,8);cout << "Usted no pudo ingresar al sistema. ADIOS";
      contrasena_correcta=0;
    }
    else {
      contrasena_correcta=1;
    }
    //cin.get();
return contrasena_correcta;
}
void incializarDatos(ListaDoble &lista){
    ListaDoble nuevoElemento,nuevoAux;
    nuevoElemento=new(Nodo);
    int iterador=1;

    if(lista==NULL)
    {
        while(iterador<=numeroAsientos){
        nuevoElemento=new(Nodo);
                if(lista==NULL)
                {
                nuevoElemento->nroAsiento=iterador;iterador++;
                fflush(stdin);
                strcpy(nuevoElemento->nombre,"Disponible");
                fflush(stdin);
                strcpy(nuevoElemento->apellido,"---");
                fflush(stdin);
                nuevoElemento->cedula=0;
                fflush(stdin);
                nuevoElemento->ingresofecha.fecha="---";
                fflush(stdin);
                nuevoElemento->siguiente=nuevoElemento->anterior=NULL;
                lista=nuevoElemento;
                //system("pause");
                }
                else
                {
                    nuevoElemento->nroAsiento=iterador;iterador++;
                    fflush(stdin);
                    strcpy(nuevoElemento->nombre,"Disponible");
                    fflush(stdin);
                    strcpy(nuevoElemento->apellido,"---");
                    fflush(stdin);
                    nuevoElemento->cedula=0;
                    fflush(stdin);
                    nuevoElemento->ingresofecha.fecha="---";
                    fflush(stdin);
                    nuevoAux=lista;
                    while(nuevoAux->siguiente!=NULL){
                        nuevoAux=nuevoAux->siguiente;
                    }
                    nuevoElemento->siguiente=nuevoAux->siguiente;
                    nuevoAux->siguiente=nuevoElemento;
                    nuevoElemento->anterior=nuevoAux;
              //  system("pause");

                }
        }

    }



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
char *ingresarString(char *msg){
	char dato[15];
	char c;

	int i = 0,iterador=0;

	printf("%s",msg);

	  while((c=getch())!=13||iterador==0){
		/*if(c==8)
       {

           dato[ i ] = '\0';
           i--;
           printf("\b \b");
       }
		 else*/
            //strupr(c);
            if(c==F1)
            {
                system("ayuda.chm");
            }
            if((c>='a'&&c<='z')){
			printf("%c",c);
			dato[i++]=c;
			iterador=1;
		}
		dato[i]='\0';
	}
	return dato;
}
void insertarDatosClientePosicion(ListaDoble &lista){
    char* nombre,*apellido;
	//nombre=&nombret[0];

    int C[10],B[ced];//CEDULA
    int cedula,*cedu,*q,controlCedula=0,controlOcupado=0;
    char salida[]={"29-11-2017 18H00"};
    q=B;
    cedu=&cedula;
    time_t tAct = time(NULL);//para capturar hora sistema
    ListaDoble actual=new (Nodo);
    actual=lista;
    bool encontrado=false;
    int nodoBuscado=0,nuevo=0;
    system("cls");
    printf("\t\t--------------------------------\n");
    printf("\t\t   INGRESO DE DATOS DEL CLIENTE \n");
    printf("\t\t---------------------------------\n\n");

    printf("\n\t\tQUE NUMERO DE ASIENTO DESEA?: ");
    nodoBuscado=ObtenerEnteroPositivo();
    if(lista!=NULL)
    {
        while(actual!=NULL&&encontrado!=true)
        {
            if(actual->nroAsiento==nodoBuscado)
            {
                controlOcupado=stricmp(actual->nombre,"Disponible");
                if(controlOcupado==0)
                {
                    fflush(stdin);
                    //printf("\n\tNOMBRE: ");
                    nombre=ingresarString("\n\tNOMBRE: ");
                    strcpy(actual->nombre,nombre);
                    //scanf("%s",actual->nombre);

                    fflush(stdin);
                    apellido=ingresarString("\n\tAPELLIDO: ");
                    strcpy(actual->apellido,apellido);
                    do{
                        fflush(stdin);
                        printf("\n\tCEDULA: ");
                        scanf("%ld",&actual->cedula);
                        *cedu=actual->cedula;
                        controlCedula=validarCedula(cedu,q);
                        //fflush(stdin);
                    }while(controlCedula==0);
                    actual->ingresofecha.fecha=asctime(localtime(&tAct));
                    strcpy(actual->ingresofecha.salida,salida);
                    encontrado=true;
                }
                else
                {
                    printf("\n\tEL ASIENTO YA SE ENCUENTRA OCUPADO\n");
                }
            }
            actual=actual->siguiente;
        }
        if(nodoBuscado>numeroAsientos||nodoBuscado==0)
        {
            printf("\n\n\tNUMERO DE ASIENTO MAYOR A CAPACIDAD DE BUS\n\tPOR FAVOR INGRESE Nro DE ASIENTO CORRECTO\n");
        }
    }
    else
    {
        printf("\nLa Lista esta vacia\n");
    }
}
void cancelarBoleto(ListaDoble &lista,int valor){

    ListaDoble actual=new (Nodo);
    actual=lista;
    bool encontrado=false;
    int nodoBuscado=0,nuevo=0;
    ListaDoble aux=new(Nodo);
    ListaDoble anterior=new(Nodo);
    aux=lista;
    anterior=NULL;
    int control=0,asiento,controlCancelado=0;
    int C[10],B[ced];//CEDULA
    int cedula,*cedu,*q,controlCedula=0,NroCed;
    q=B;
    cedu=&cedula;
    system("cls");
    printf("\t\t\t------------------------------------------------\n");
    printf("\t\t\t   INGRESO DE DATOS CLIENTE PARA CANCELAR BOLETO \n");
    printf("\t\t\t--------------------------------------------------\n\n");

            do
            {
                fflush(stdin);
                printf("\n\t\tCEDULA: ");
                scanf("%d",&NroCed);
                *cedu=NroCed;
                controlCedula=validarCedula(cedu,q);
            }while(controlCedula==0);
            printf("\n\t\tASIENTO Nro: ");
            asiento=ObtenerEnteroPositivo();

    if(lista!=NULL)
    {
        while(actual!=NULL&&encontrado!=true)
        {
            if(actual->nroAsiento==asiento&&actual->cedula==NroCed)
            {
                    fflush(stdin);
                    strcpy(actual->nombre,"Disponible");
                    fflush(stdin);
                    strcpy(actual->apellido,"---");
                    fflush(stdin);
                    actual->cedula=0;
                    fflush(stdin);
                    actual->ingresofecha.fecha="---";
                    fflush(stdin);
                    encontrado=true;

                    printf("\n\tBOLETO CANCELADO - EL ASIENTO SE ENCUENTRA DISPONIBLE\n");
                    controlCancelado=1;

            }
            actual=actual->siguiente;
        }
        if(controlCancelado==0)
        {
             printf("\n\tNO HAY CLIENTES REGISTRADOS CON ESOS DATOS\n");
        }
    }
    else
    {
        printf("\nLa Lista esta vacia\n");
    }
}
void buscarCliente(ListaDoble lista){
    int C[10],B[ced];//CEDULA
    int cedula,*cedu,*q,controlCedula=0,NroCed;
    q=B;
    cedu=&cedula;
    int iterador=1,control=0;
    system("cls");
    printf("\t\t----------------------------\n");
    printf("\t\t       DATOS DE CLIENTE \n");
    printf("\t\t----------------------------\n\n");

     do
    {
        fflush(stdin);
        printf("\n\t\tCEDULA: ");
        scanf("%d",&NroCed);
        *cedu=NroCed;
        controlCedula=validarCedula(cedu,q);
    }while(controlCedula==0);
    if(lista==NULL)
    {
        printf("\n\tNo hay elementos en la lista!\n\n");
    }
    else
    {

        while(lista!=NULL){
                if(lista->cedula==NroCed)
                {
                    printf("\n\n\t\tCLIENTE # %d:\n",lista->nroAsiento);
                    printf("\t\t\tNOMBRE: %s\n",lista->nombre);
                    printf("\t\t\tAPELLIDO: %s\n",lista->apellido);
                    printf("\t\t\tCEDULA: %d\n",lista->cedula);
                    printf("\t\t\tNro. Asiento: %d\n",lista->nroAsiento);
                    printf("\t\t\tHora De Compra: %s\n",lista->ingresofecha.fecha);
                    control=1;
                }
            //recorridos lista
            lista=lista->siguiente;
        }
        if(control==0)
        {
            printf("\n\n\t\tNO HAY CLIENTES REGISTRADOS CON CI INGRESADA\n ");
        }
    }
}
void mostrarAsientos(ListaDoble lista){
        int iterador=1;
    int controlOcupado;
     system("cls");
    printf("\t\t----------------------------\n");
    printf("\t\t     LISTA DE ASIENTOS       \n");
    printf("\t\t----------------------------\n\n");
    if(lista==NULL)
    {
        printf("\t\tNo hay elementos en la lista!\n\n");
    }
    else
    {
        while(lista!=NULL)
        {
            controlOcupado=stricmp(lista->nombre,"Disponible");
            if(controlOcupado==0)
            {
                printf("\t\t #%d: Disponible\n",iterador);iterador++;
            }
            else
            {
                printf("\t\t #%d: Ocupado\n",iterador);iterador++;
            }
            //recorridos lista

            lista=lista->siguiente;
        }
    }


}
void mostrarDatos(ListaDoble lista){
    int controlDisponible=0;
    system("cls");
    printf("\t\t----------------------------\n");
    printf("\t\t     LISTA DE PASAJEROS \n");
    printf("\t\t----------------------------\n\n");
    if(lista==NULL)
    {
        printf("\t\tNo hay elementos en la lista!\n\n");
    }
    else
    {
        int iterador=1;
        while(lista!=NULL){
                controlDisponible=stricmp(lista->nombre,"Disponible");
            if(controlDisponible==0)
            {
                printf("\t\tASIENTO # %d:\n",iterador);iterador++;
                printf("\t\t\tESTADO: %s\n",lista->nombre);

            }else{
                printf("\t\tASIENTO # %d:\n",iterador);iterador++;
                printf("\t\t\tNOMBRE: ");
                strupr(lista->nombre);
                puts(lista->nombre);
                printf("\t\t\tAPELLIDO: ");
                strupr(lista->apellido);
                puts(lista->apellido);
                printf("\t\t\tCEDULA: %ld\n",lista->cedula);
                printf("\t\t\tHora De Compra: %s",lista->ingresofecha.fecha);
                printf("\t\t\tNro. Asiento: %d\n",lista->nroAsiento);
                printf("\t\t\tHora De Salida: %s\n\n",lista->ingresofecha.salida);
            }
                //recorridos lista
            lista=lista->siguiente;
        }
    }
}
void creaBackup(ListaDoble lista){
    FILE *archivo=NULL;
    archivo=fopen("ListaPasajeros.txt","w+");
    system("cls");
    printf("\t\t----------------------------\n");
    printf("\t\t     LISTA DE PASAJEROS \n");
    printf("\t\t----------------------------\n\n");
    if(lista==NULL)
    {
        printf("\t\tNo hay elementos en la lista!\n\n");
    }
    else
    {
        int iterador=1;
        while(lista!=NULL){
            fprintf(archivo,"===============================\n");
            fprintf(archivo,"ASIENTO # %d:\n",iterador);iterador++;
            fprintf(archivo,"\tNOMBRE: %s\n",lista->nombre);
            fprintf(archivo,"\tAPELLIDO: %s\n",lista->apellido);
            fprintf(archivo,"\tCEDULA: %d\n",lista->cedula);
            fprintf(archivo,"\tHora De Compra: %s\n",lista->ingresofecha.fecha);
            fprintf(archivo,"\tNro. Asiento: %d\n",lista->nroAsiento);
            fprintf(archivo,"\tHora De Salida: %s\n",lista->ingresofecha.salida);
            fprintf(archivo,"===============================\n\n");
        //recorridos lista
            lista=lista->siguiente;
        }
    }
    fclose(archivo);

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
void insElemInicio(ListaDoble &lista){
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
void insElemFin(ListaDoble &lista){
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
void insElemAntes(ListaDoble &lista){
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
void insElemDespues(ListaDoble &lista){
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
int validarCedula(int *p,int *q){


     int total=0,pares=0,impares=0,m,resp=0,r=0,control=0;
    int i=9,comp,mul=1,v,coc;//los acumuladores siempre se inicializa
                            //si vas asumar es =0 si vas a multiplicar es =1

    do{
        coc=(*p)/10;
     *(q+i)=((*p)%10);//aqui asignas al nuevo arreglo cada digito ingresado
       i--;
        *p=coc;
    }while(coc!=0);
    for(i=0;i<ced;i+=2)//aqui es mas dos para que coja las posiciones pares
    {
        mul=(*(q+i))*2;
        if(mul>9)
        {
            mul=mul-9;
        }
        pares=pares+mul;
    }
    for(i=1;i<9;i+=2)
    {
        impares=impares+(*(q+i));
    }
      total=pares+impares;

      resp=total%10;
      if(resp==0)
        {
            resp=10;
        }
      r=10-resp;
      if(r==(*(q+9)))
        {
        //printf("\ncedula valida");
            control=1;
        }
        else
        {
            printf("\ncedula no valida");
            control=0;
        }
return control;
}
int main(){
    int opcion,numero=0,control=0,controlRuta=0,asiento=1,usuario=0;
    ListaDoble lista=NULL;
    inicio();
    usuario=ingreso_usuario();
    if(usuario==1)
    {

        incializarDatos(lista);
	do{
		opcion=menu();
		system("cls");
		switch (opcion){
            case 1:
                controlRuta=menuRV();
                system("cls");
                insertarDatosClientePosicion(lista);
                control=1;
                asiento++;
                system("pause");
                break;
            case 2:
                cancelarBoleto(lista,numero);
                system("pause");
                break;
            case 3:
                buscarCliente(lista);
                system("pause");
                break;
            case 4:
                mostrarAsientos(lista);
                system("pause");
                break;
            case 5:
                mostrarDatos(lista);
                system("pause");
                break;
            case 6:
                creaBackup(lista);
                printf("\nDatos Guardados Exitosamente\n\tPuede Visulizar los Datos al Salir\n");
                system("pause");
                break;
            case 7:
                ayuda();
                system("pause");
                break;
            case 8:
                qr();
                break;
            case 9:
                about();
                system("ListaPasajeros.txt");
                break;
            }
	}while(opcion!=9);
    }else{
        //printf("\nVERIFIQUE SUS DATOS\n");
        printf("\n\n\n\n");
        system("pause");
    }

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
int menuRV(){

    const char *titulo="\tPOR FAVOR SELECCIONE EL DESTINO DEL VIAJE!\n\tPRESIONE ENTER PARA CONTINUAR\n\n";
	const char *opciones[]={"\n\t\tQUITO - GUAYAQUIL\t$20"};
    int opcionSeleccionada = 1,numerodeopciones=1;
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

