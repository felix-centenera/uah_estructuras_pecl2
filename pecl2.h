#ifndef PECL2_H_INCLUDED
#define PECL2_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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

// STRUCT Estadistica:
struct Estadistica
{
    int marruecosDestino=0;
    int libiaDestino=0;
    int greciaDestino=0;
    int daganzoOrigen=0;
    int mecoOrigen=0;
    int loechesOrigen=0;
    int torrejonOrigen=0;
    int harina=0;
    int pasta=0;
    int galletas=0;
    int legumbres=0;
    int leche=0;
    int medicinas=0;
    int higiene=0;
    int agua=0;
    int aceite=0;
    int sal=0;
    int azucar=0;
    int latas_cons=0;
    int iluminacion=0;
    int herramientas=0;
    int combustible=0;
    int tiendas_camp=0;
    int ropa=0;
    int mantas=0;
    int limpieza=0;
};


// STRUCT Registro de CC:
struct RegistroCentros
{
    int IdCentro;
    string CentroRef;
    Estadistica *estadistica;
};


//----------------------------------------------PILA---------------------------------------------------//
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


//----------------------------------------------LISTA-Cajas---------------------------------------------------//

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
    //Caja recorrerListaCajas();
    Pila * recorrerListaCajas(Pila *pilaDeCajas);
    Caja recorrerListaBuscandoCaja(string idCaja);
    int numeroDeElementos();
};

// STRUCT Registro de CC:
struct CentroClasificacion
{
    int IdCentro;
    string CentroRef;
    Lista listaDeCajas;
};



//----------------------------------------------Arbol-De-CentrosClasificación---------------------------------------------------//

class NodoArbol
{
    private:
        // Miembros:
        CentroClasificacion * dato;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
        friend class ArbolABB;

    public:
        // Constructor:
        NodoArbol( CentroClasificacion *dat, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
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
        void Insertar( CentroClasificacion* dat);
        // Borrar un elemento del árbol:
        void Borrar(const CentroClasificacion dat);
        void BorrarPorId(const int dat);
        // Función de búsqueda:
        bool Buscar(const CentroClasificacion dat);
        bool BuscarPorId(const int dat);
        CentroClasificacion * BuscarPorIdRecuperarCC(const int dat);
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
        CentroClasificacion* VerRaiz();
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

//----------------------------------------------Lista-RegistroCentros---------------------------------------------------//

class NodoRegistroCentro
{
private:
    RegistroCentros * valor;
    NodoRegistroCentro *siguiente;
    friend class ListaRegistroCentros;
public:
    NodoRegistroCentro(RegistroCentros * v, NodoRegistroCentro *sig = NULL)
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
    void insertarNodo(RegistroCentros * v);
    void borrarNodo(RegistroCentros v);
    void borrarNodoPorRegistroID(int v);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    RegistroCentros *valorActual();
    void recorrerLista();
    void imprimirDatosMedianteRegistoDeLista(ArbolABB *arbolDeCentros);
    int contarElementosLista();
    bool buscarID(int v);
    bool buscarCentro(string v);
    string buscarIDRecuperarCentroRef(int v);
    int buscarCentroRefRecuperarID(string v);
    Caja buscarCajaMedianteRegistroDeCajas(string idCaja,ArbolABB *arbolDeCentros);
    RegistroCentros * buscarIDRecuperarCentroRefCompleto(int v);
    Estadistica *buscarCentroRefRecuperarEstadistica(int v);
    void imprimirDatosEstadisticaMedianteRegistoDeLista(ArbolABB *arbolDeCentros,Estadistica *estadisticaTotal);
    string randomIDCentro();
};



//----------------------------------------------Funciones-transversales---------------------------------------------------//
void Mostrar(int&);
void simulacionCentroDeControl(int numSimulaciones, ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
int generarNumeroRandom();
string randomCentrosNoRegistrado (ListaRegistroCentros *listaCentros);
void  estadoCentrosArbol(ArbolABB *arbolDeCentros);
void simulacionCreacionCajas(int numSimulaciones, ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros,Pila* pilaDeCajas );
void printDatosPilaCajas(Pila* pilaDeCajas);
void repartirCajas(ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros,Pila* pilaDeCajas,Estadistica *estadisticaTotal);
void printMenu(int &opcion);
void crearCCmanual(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
void borrarCC(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
void mostrarDatosCC(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
void buscarCajaPorID(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
void buscarCajaPorIDyBorrar(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
void buscarCajaPorIDyMoverlaCC(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros);
void actualizareEstadisitcas(Caja caja, RegistroCentros * centro,Estadistica *estadisticaTotal);
void printEstadisticas(Estadistica* estadistica);
void anadirCajasCentro(ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros, Estadistica *estadisticaTotal);

//OLD FUNCTION:
//void actualizareEstadisitcas(Caja caja, CentroClasificacion * centroClasificacion);
//void actualizareEstadisitcas(Caja caja, Estadistica * estadistica);
//void actualizareEstadisitcas(Caja caja, RegistroCentros * centro);

#endif // PECL2_H_INCLUDED
