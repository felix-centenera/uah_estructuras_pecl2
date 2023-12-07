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
    string CentroRef;
    string Contenido;
    string FechaConsumo;
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

#endif // PECL2_H_INCLUDED
