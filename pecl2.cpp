#include "pecl2.h"



// ----------------------------------------------- LISTA RegistoCentros -----------------------------------------------
ListaRegistroCentros::~ListaRegistroCentros()
{
    pnodo aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}


void ListaRegistroCentros::insertarNodo(RegistroCentros v)
{
    pnodo aux;
    if (listaVacia())
    {
        cabeza = new NodoRegistroCentro(v, NULL);
        final=cabeza;
    }
    else
    {
        aux= new NodoRegistroCentro(v,NULL);
        final->siguiente=aux;
        final=aux;
    }
}


void ListaRegistroCentros::borrarNodo(RegistroCentros v)
{
    pnodo
    anterior;
    actual = cabeza;
    while (actual->valor.IdCentro != v.IdCentro && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if (actual->valor.IdCentro == v.IdCentro){
        if(actual==cabeza) // Primer elemento
            cabeza = actual->siguiente;
        else
        {
            anterior->siguiente = actual->siguiente;
            if(actual==final) final=anterior;
        }
        actual->siguiente=NULL;
        delete actual;
}
}

void ListaRegistroCentros::borrarNodoPorRegistroID(int v)
{
    pnodo
    anterior;
    actual = cabeza;
    while (actual->valor.IdCentro != v && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if (actual->valor.IdCentro == v){
        if(actual==cabeza) // Primer elemento
            cabeza = actual->siguiente;
        else
        {
            anterior->siguiente = actual->siguiente;
            if(actual==final) final=anterior;
        }
        actual->siguiente=NULL;
        delete actual;
}
}


bool ListaRegistroCentros::listaVacia()
{
    return cabeza == NULL;
}
void ListaRegistroCentros::esCabeza()
{
    actual = cabeza;
}
void ListaRegistroCentros::esFinal()
{
    esCabeza();
    if(!listaVacia()) // Más sencillo
        while(actual->siguiente) // actual = final;
            esSiguiente();
}


void ListaRegistroCentros::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}
bool ListaRegistroCentros::esActual()
{
    return actual != NULL;
}
RegistroCentros ListaRegistroCentros::valorActual()
{
    return actual->valor;
}


void ListaRegistroCentros::recorrerLista()
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        cout << aux->valor.IdCentro << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}




// ----------------------------------------------- LISTA Cajas -----------------------------------------------

Lista::~Lista()
{
    pnodocaja aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}


void Lista::insertarNodo(Caja v)
{
    pnodocaja aux;
    if (listaVacia())
    {
        cabeza = new Nodo(v, NULL);
        final=cabeza;
    }
    else
    {
        aux= new Nodo(v,NULL);
        final->siguiente=aux;
        final=aux;
    }
}


void Lista::borrarNodo(Caja v)
{
    pnodocaja
    anterior;
    actual = cabeza;
    while (actual->valor.Id !=v.Id && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if (actual->valor.Id == v.Id){
        if(actual==cabeza) // Primer elemento
            cabeza = actual->siguiente;
        else
        {
            anterior->siguiente = actual->siguiente;
            if(actual==final) final=anterior;
        }
        actual->siguiente=NULL;
        delete actual;
}
}

void Lista::borrarNodoPorCajaID(string v)
{
    pnodocaja
    anterior;
    actual = cabeza;
    while (actual->valor.Id !=v && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if (actual->valor.Id == v){
        if(actual==cabeza) // Primer elemento
            cabeza = actual->siguiente;
        else
        {
            anterior->siguiente = actual->siguiente;
            if(actual==final) final=anterior;
        }
        actual->siguiente=NULL;
        delete actual;
}
}


bool Lista::listaVacia()
{
    return cabeza == NULL;
}
void Lista::esCabeza()
{
    actual = cabeza;
}
void Lista::esFinal()
{
    esCabeza();
    if(!listaVacia()) // Más sencillo
        while(actual->siguiente) // actual = final;
            esSiguiente();
}


void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}
bool Lista::esActual()
{
    return actual != NULL;
}
Caja Lista::valorActual()
{
    return actual->valor;
}


void Lista::recorrerLista()
{
    pnodocaja aux;
    aux = cabeza;
    while(aux)
    {
        cout << aux->valor.Id << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}

