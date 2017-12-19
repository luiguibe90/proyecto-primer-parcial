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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Nodo.h>
#define fondo 3
#define texto 10
using namespace std;


int main(){
    Colas co=new(Nodo);
    Colas frente=new(Nodo);
    Colas fin=new(Nodo);
    Colas cola=new (Nodo);
frente=NULL;
fin=NULL;

    //color(fondo,texto);


    int controlsn,clientes,controlMenu,c=1,dato;
//color(fondo,texto);

    printf("Cuantos Clientes Desea? ");
clientes=co->ObtenerEnteroPositivo();
    do{
        system("cls");
        co->color(fondo,texto);
        controlMenu=co->menu();
        switch (controlMenu)
        {
            case 1:
                srand(time(NULL));
                co->color(fondo,texto);
                co->insertarDatoCola(frente,fin,clientes);
            break;
            case 2:
                system("cls");
                co->color(fondo,texto);
                //eliminar los elementos de la cola
                printf("\n\nQuitando los Nodos de la Cola\n");
                while(frente!=NULL){
                    co->eliminarDatoCola(frente,fin,dato);

                    if(frente!=NULL)
                    {
                        printf("%d ,",dato);
                    }
                    else{
                        printf("%d .",dato);
                    }
                }
                system("pause");
            break;
            case 3:
               co-> mostrarDatos(frente,fin,cola);
                system("pause");
            break;
            case 4:

            break;
        }
        //controlsn=menuSN();
    system("cls");
    }while(controlMenu!=4);
    return 0;
}
