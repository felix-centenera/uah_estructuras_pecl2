#ifndef PECL2_H_INCLUDED
#define PECL2_H_INCLUDED

#include <iostream>
#include <iomanip>
#define N1 10 //Numero de centrales de clasificación.
#define N2 30 // Numero de cajas aleatorias

using namespace std;

// ---------------------------------------------ESTRUCTURAS---------------------------------------------
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

struct Estadistica
{
    int marruecosDestino;
    int libiaDestino;
    int greciaDestino;
    int daganzoOrigen;
    int mecoOrigen;
    int loechesOrigen;
    int torrejonOrigen;
    int harina;
    int pasta;
    int galletas;
    int legumbres;
    int leche;
    int medicinas;
    int higiene;
    int agua;
    int aceite;
    int sal;
    int azucar;
    int latas_cons;
    int iluminacion;
    int herramientas;
    int combustible;
    int tiendas_camp;
    int ropa;
    int mantas;
    int limpieza;
};


// STRUCT Registro de CC:
struct RegistroCentros
{
    int IdCentro;
    string CentroRef;
    Estadistica estadistica;
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
    int numeroDeElementos();
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
        CentroClasificacion BuscarPorIdRecuperarCC(const int dat);
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
    void imprimirDatosMedianteRegistoDeLista(ArbolABB *arbolDeCentros);
    int contarElementosLista();
    bool buscarID(int v);
    bool buscarCentro(string v);
    string buscarIDRecuperarCentroRef(int v);
    int buscarCentroRefRecuperarID(string v);
};


void Mostrar(int&);
void simulacionCentroDeControl(int numSimulaciones, ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
int generarNumeroRandom();
string randomCentrosNoRegistrado (ListaRegistroCentros *listaCentros);
void  estadoCentrosArbol(ArbolABB *arbolDeCentros);


//----------PILA
class NodoPila
{
private:
    Caja valor;
    NodoPila *siguiente;
    friend class Pila;
public:
    NodoPila(Caja v, NodoPila *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef NodoPila *pNodo;

class Pila
{
private:
    pNodo cima;
public:
    Pila() : cima(NULL) {} //Constructor de la Pila
    ~Pila();
    void apilar(Caja v);
    Caja desapilar();
    Caja mostrarCima();
    bool vacia();
    int contarElementosPila();
};

Pila *copiarPila(Pila *pilaOriginal);
Pila* invertirPila(Pila* pilaOriginal);

void simulacionCreacionCajas(int numSimulaciones, ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros,Pila* pilaDeCajas );
void printDatosPilaCajas(Pila* pilaDeCajas);


#endif // PECL2_H_INCLUDED
