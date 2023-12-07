#ifndef PECL2_H_INCLUDED
#define PECL2_H_INCLUDED

#include <iostream>

using namespace std;

// ---------------------------------------------ESTRUCTUTAS---------------------------------------------
// -----------------------------------------------------------------------------------------------------

// STRUCT Caja:
struct Caja
{
    string Id;
    string Contenido;
    string FechaConsumo;
    string CentroRef;
    int IdCentro;
    int FechaRecogida;
};




// STRUCT Registro de CC:
struct RegistroCentros
{
    int IdCentro;
    string CentroRef;
};

// ----------------------------------------------- LISTA RegistoCentros -----------------------------------------------

class NodoRegistroCentro
{
private:
    RegistroCentros valor;
    NodoRegistroCentro *siguiente;
    friend class ListaRegistroCentros;
public:
    NodoRegistroCentro(RegistroCentros v, NodoRegistroCentro *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef NodoRegistroCentro *pnodo;

class ListaRegistroCentros
{
private:
    pnodo cabeza, actual, final;
public:
    ListaRegistroCentros()
    {
        cabeza = actual = final = NULL;
    }
    ~ListaRegistroCentros();
    void insertarNodo(RegistroCentros v);
    void borrarNodo(RegistroCentros v);
    void borrarNodoPorRegistroID(int v);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    RegistroCentros valorActual();
    void recorrerLista();
};


// ----------------------------------------------- LISTA Cajas -----------------------------------------------

class Nodo
{
private:
    Caja valor;
    Nodo *siguiente;
    friend class Lista;
public:
    Nodo(Caja v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pnodocaja;

class Lista
{
private:
    pnodocaja cabeza, actual, final;
public:
    Lista()
    {
        cabeza = actual = final = NULL;
    }
    ~Lista();
    void insertarNodo(Caja v);
    void borrarNodo(Caja v);
    void borrarNodoPorCajaID(string v);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    Caja valorActual();
    void recorrerLista();
};

// STRUCT Registro de CC:
struct CentroClasificacion
{
    int IdCentro;
    string CentroRef;
    Lista listaDeCajas;
};

#endif // PECL2_H_INCLUDED
