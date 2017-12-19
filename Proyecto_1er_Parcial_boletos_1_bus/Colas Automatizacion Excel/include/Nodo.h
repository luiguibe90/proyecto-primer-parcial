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
#ifndef NODO_H
#define NODO_H


class Nodo
{
    typedef struct Nodo *Colas;
    public:

int menuSN();
int menu();
void gotoxy(int,int);
void color(int,int);
int ObtenerEnteroPositivo();
bool cola_vacia(Nodo *);
void insertarDatoCola(Nodo *&,Nodo *&,int);
void eliminarDatoCola(Nodo *&,Nodo *&,int &);
void mostrarDatos(Nodo *,Nodo *,Nodo *);

        Nodo();
        virtual ~Nodo();

    protected:

    private:
        int tLLegada;
    int tEsperaCliente;
    int tDescansoCajero;
    int tServicio;
    int tSalidaCliente;
    int tEntreLlegadaCliente;
    Nodo *siguiente;

};
typedef struct Nodo *Colas;
#endif // NODO_H
