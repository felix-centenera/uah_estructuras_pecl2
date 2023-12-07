#ifndef PECL2_H_INCLUDED
#define PECL2_H_INCLUDED

#include <iostream>
#define N1 10 //Numero de centrales de clasificación.
#define N2 30 // Numero de cajas aleatorias

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



// ----------------------------------------------- Arbol de CentrosClasificación -----------------------------------------------


class NodoArbol
{
    private:
        // Miembros:
        CentroClasificacion dato;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
        friend class ArbolABB;

    public:
        // Constructor:
        NodoArbol(const CentroClasificacion dat, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
            dato(dat), izquierdo(izq), derecho(der) {}

};

class ArbolABB
{
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        NodoArbol *raiz;
        NodoArbol *actual;
        int contador;
        int altura;

    public:
        // Constructor y destructor básicos:
        ArbolABB() : raiz(NULL), actual(NULL) {}
        ~ArbolABB();
         // Insertar en árbol ordenado:
        void Insertar(const CentroClasificacion dat);
        // Borrar un elemento del árbol:
        void Borrar(const CentroClasificacion dat);
        void BorrarPorId(const int dat);
        // Función de búsqueda:
        bool Buscar(const CentroClasificacion dat);
        bool BuscarPorId(const int dat);
        // Comprobar si el árbol está vacío:
        bool Vacio(NodoArbol *r);
        // Comprobar si es un nodo hoja:
        bool EsHoja(NodoArbol *r);
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(const CentroClasificacion dat);
        // Moverse al nodo raiz:
        void Raiz();
        CentroClasificacion VerRaiz();
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(int&), NodoArbol *nodo=NULL, bool r=true);
        void PreOrden(void (*func)(int&), NodoArbol *nodo=NULL, bool r=true);
        void PostOrden(void (*func)(int&), NodoArbol *nodo=NULL, bool r=true);

    private:
        // Funciones auxiliares
        void Podar(NodoArbol* &);
        void auxContador(NodoArbol*);
        void auxAltura(NodoArbol*, int);
};


void Mostrar(int&);

#endif // PECL2_H_INCLUDED
