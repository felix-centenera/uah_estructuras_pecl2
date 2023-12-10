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


void ListaRegistroCentros::insertarNodo(RegistroCentros * v)
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
    while (actual->valor->IdCentro != v.IdCentro && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if (actual->valor->IdCentro == v.IdCentro){
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
    while (actual->valor->IdCentro != v && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if (actual->valor->IdCentro == v){
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
RegistroCentros* ListaRegistroCentros::valorActual()
{

    return actual->valor;
}


void ListaRegistroCentros::recorrerLista()
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        cout << aux->valor->IdCentro << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}

void ListaRegistroCentros::imprimirDatosMedianteRegistoDeLista(ArbolABB *arbolDeCentros)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (arbolDeCentros->BuscarPorId(aux->valor->IdCentro)){
            //cout << aux->valor.IdCentro << "-> se encontro";
            //cout << "el id es yeah: " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor.IdCentro).CentroRef << endl;
            cout << "ID: " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor->IdCentro)->IdCentro << "   Localidad:   " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor->IdCentro)->CentroRef << "  Num cajas:  " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor->IdCentro)->listaDeCajas.numeroDeElementos() << endl;
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

void ListaRegistroCentros::imprimirDatosEstadisticaMedianteRegistoDeLista(ArbolABB *arbolDeCentros, Estadistica *estadisticaTota)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (arbolDeCentros->BuscarPorId(aux->valor->IdCentro)){

            //cout << aux->valor.IdCentro << "-> se encontro";
            //cout << "el id es yeah: " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor.IdCentro).CentroRef << endl;
            //cout << "ID: " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor->IdCentro)->IdCentro << "   Localidad:   " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor->IdCentro)->CentroRef << "  Num cajas:  " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor->IdCentro)->listaDeCajas.numeroDeElementos() << endl;
            cout << "+------------------------+----------------+\n";
            //cout << "|" << setw(5) << "ID:" <<aux->valor->IdCentro << setw(13) << "  LOCALIZACION:" << aux->valor->CentroRef  <<setw(12) << "|\n";
            cout << "|" << setw(2) << "ID:" << setw(4) << aux->valor->IdCentro << setw(8) << "  LOCALIZACION:" << setw(9) << aux->valor->CentroRef << setw(12) << "|\n";

            cout << "+------------------------+----------------+\n";
           printEstadisticas(aux->valor->estadistica);

        }
        aux = aux->siguiente;
    }
    cout << endl;
    cout << "+------------------------+----------------+\n";
    cout << "|" << setw(2) << "ESTADISTICA TOTAL DE TODOS LOS CC:" << setw(10) << "|\n";
    cout << "+------------------------+----------------+\n";
    printEstadisticas(estadisticaTota);
}
/*
Caja ListaRegistroCentros::buscarCajaMedianteRegistroDeCajas(string idCaja,ArbolABB *arbolDeCentros){
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        if (arbolDeCentros->BuscarPorId(aux->valor.IdCentro)){
            Pila *pilaDeCajas = new Pila();
            pilaDeCajas=arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor.IdCentro)->listaDeCajas.recorrerListaCajas(pilaDeCajas);
            while(!pilaDeCajas->vacia()) {
                    if (idCaja==pilaDeCajas->mostrarCima().Id){
                        return pilaDeCajas->desapilar();
                    }
                    pilaDeCajas->desapilar();
            }
        }
        aux = aux->siguiente;
    }
    Caja cajaNoEncontrada;
    cajaNoEncontrada.Id = "CajaNoEncontrada";
    return cajaNoEncontrada;
}
*/

Caja ListaRegistroCentros::buscarCajaMedianteRegistroDeCajas(string idCaja,ArbolABB *arbolDeCentros){
    pnodo aux;
    aux = cabeza;
    Caja caja;
    while(aux)
    {
        if (arbolDeCentros->BuscarPorId(aux->valor->IdCentro)){
            //Lista listaDeCajasParaBuscar;
            //listaDeCajasParaBuscar=
            caja=arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor->IdCentro)->listaDeCajas.recorrerListaBuscandoCaja(idCaja);
            if (caja.Id==idCaja){
                return caja;
            }
        }
        aux = aux->siguiente;
    }
    if (caja.Id=="CajaNoEncontrada"){
                return caja;
            }

}

bool ListaRegistroCentros::buscarID(int v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor->IdCentro == v){
            return true;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
    return false;
}

//WIPPPPPP
string ListaRegistroCentros::randomIDCentro() {
    int numeroElementos=this->contarElementosLista();
    int numeroAleatorio = rand() % numeroElementos;
    //int numeroElementos=3;
    int contadorNodos = 0;
    pnodo aux;
    aux = cabeza;
    //cout << numeroElementos << endl;
    while(aux && contadorNodos < numeroAleatorio  ){
        contadorNodos++;
        aux = aux->siguiente;
    }
    //return aux->valor->IdCentro;
    //cout << aux->valor->IdCentro << endl;
    return aux->valor->CentroRef;
}

string ListaRegistroCentros::buscarIDRecuperarCentroRef(int v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor->IdCentro == v){
            return aux->valor->CentroRef;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
}

RegistroCentros * ListaRegistroCentros::buscarIDRecuperarCentroRefCompleto(int v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor->IdCentro == v){
            //return aux->valor->CentroRef;
            return aux->valor;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
}

bool ListaRegistroCentros::buscarCentro(string v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor->CentroRef == v){
            return true;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
    return false;
}

int ListaRegistroCentros::buscarCentroRefRecuperarID(string v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor->CentroRef == v){
            return aux->valor->IdCentro;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
}

Estadistica* ListaRegistroCentros::buscarCentroRefRecuperarEstadistica(int v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor->IdCentro == v){
            return aux->valor->estadistica;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
}


int ListaRegistroCentros::contarElementosLista()
{
    pnodo aux;
    int contador=0;
    aux = cabeza;
    while(aux)
    {
        contador= contador +1;
        aux = aux->siguiente;
    }
    return contador;
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
        //cout << "VOUY A INTENTARLOOOOOOO aunque este vacias" << endl;
    }
    else
    {
        //cout << "VOUY A INTENTARLOOOOOOO" << endl;
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


void Lista::recorrerLista() //CAmbiar nombre mas descriptivo, haciendo print de  los id.
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


Caja Lista::recorrerListaBuscandoCaja(string idCaja)
{
    pnodocaja aux;
    aux = cabeza;
    while(aux)
    {
        if (aux->valor.Id == idCaja){
            return aux->valor;
        }
        aux = aux->siguiente;
    }
    Caja cajaNoEncontrada;
    cajaNoEncontrada.Id = "CajaNoEncontrada";
    return cajaNoEncontrada;
}


// Devolver pila de cajas lista para impresion Pila *pilaDeCajas = new Pila();
Pila * Lista::recorrerListaCajas(Pila *pilaDeCajas)
{
    pnodocaja aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.Id << "-> ";
        pilaDeCajas->apilar(aux->valor);
        //return aux->valor;
        aux = aux->siguiente;
    }
    return pilaDeCajas;
}

int Lista::numeroDeElementos()
{
    int contar=0;
    pnodocaja aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.Id << "-> ";
        contar=contar +1;
        aux = aux->siguiente;
    }
    return contar;
}



// ----------------------------------------------- Arbol de CentrosClasificación -----------------------------------------------
//Destructor
ArbolABB::~ArbolABB()
        {
            Podar(raiz);
        }

//Árbol vacío
bool ArbolABB::Vacio(NodoArbol *r)
        {
            return r==NULL;
        }

//NodoArbol es de tipo hoja
bool ArbolABB::EsHoja(NodoArbol *r)
        {
            return !r->derecho && !r->izquierdo;
        }

//Coloca el nodo actual en raíz
void ArbolABB::Raiz()
        {
            actual = raiz;
        }

CentroClasificacion *ArbolABB::VerRaiz()
{
   // return raiz->dato;
    return raiz->dato;
}

// Poda: borrar todos los nodos a partir de uno incluido
void ArbolABB::Podar(NodoArbol* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un CentroClasificacion en el árbol ABB
void ArbolABB::Insertar( CentroClasificacion* dat)
{
   NodoArbol *padre = NULL;

   actual = raiz;
   // Buscar el int/CentroClasificacion en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat->IdCentro != actual->dato->IdCentro) {
      padre = actual;
      if(dat->IdCentro > actual->dato->IdCentro) actual = actual->derecho;
      else if(dat->IdCentro < actual->dato->IdCentro) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoArbol(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat->IdCentro < padre->dato->IdCentro) padre->izquierdo = new NodoArbol(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat->IdCentro > padre->dato->IdCentro) padre->derecho = new NodoArbol(dat);
}

// Eliminar un elemento de un árbol ABB
void ArbolABB::Borrar(const CentroClasificacion dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   CentroClasificacion *aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato->IdCentro) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre){ // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            }
            else raiz=NULL;

            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.

            //OJO LO SIGUENTE ES LO QUE HABIA
            //aux = actual->dato->IdCentro;
            //actual->dato->IdCentro = nodo->dato->IdCentro;
            //nodo->dato->IdCentro = aux;
            //actual = nodo;
            //OJO LO ANTERIOR ES LO QUE HABIA
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;

         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat.IdCentro > actual->dato->IdCentro) actual = actual->derecho;
         else if(dat.IdCentro < actual->dato->IdCentro) actual = actual->izquierdo;
      }
   }
}


// Eliminar un elemento de un árbol ABB
void ArbolABB::BorrarPorId(const int dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   CentroClasificacion *aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->dato->IdCentro) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre){ // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) {
                    padre->derecho = NULL;
                    cout << "DEBUG 1" << endl;
                }

               else if(padre->izquierdo == actual){
                    padre->izquierdo = NULL;
                cout << "DEBUG 2" << endl;
            }
            }
            else raiz=NULL;

            delete actual; // Borrar el nodo
                cout << "DEBUG 3" << endl;
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            //OJO LO SIGUENTE ES LO QUE HABIA
            //aux = actual->dato->IdCentro;
            //actual->dato->IdCentro = nodo->dato->IdCentro;
            //nodo->dato->IdCentro = aux;
            //actual = nodo;
            //OJO LO ANTERIOR ES LO QUE HABIA
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;

         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->dato->IdCentro) actual = actual->derecho;
         else if(dat < actual->dato->IdCentro) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) , NodoArbol *nodo, bool r)
{
  if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato->IdCentro);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(int&), NodoArbol *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   func(nodo->dato->IdCentro);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(int&), NodoArbol *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato->IdCentro);
}

// Buscar un valor en el árbol
bool ArbolABB::Buscar(const CentroClasificacion dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato->IdCentro) return true; // int encontrado
      else if(dat.IdCentro > actual->dato->IdCentro) actual = actual->derecho; // Seguir
      else if(dat.IdCentro < actual->dato->IdCentro) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Buscar un valor en el árbol
bool ArbolABB::BuscarPorId(const int dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato->IdCentro) return true; // int encontrado
      else if(dat > actual->dato->IdCentro) actual = actual->derecho; // Seguir
      else if(dat < actual->dato->IdCentro) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}


// Buscar por id en el arbol y devolver el centro de clasificación.
CentroClasificacion * ArbolABB::BuscarPorIdRecuperarCC(const int dat)
{
   actual = raiz;
   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato->IdCentro) return actual->dato; // int encontrado
      else if(dat > actual->dato->IdCentro) actual = actual->derecho; // Seguir
      else if(dat < actual->dato->IdCentro) actual = actual->izquierdo;
   }
   // No está en árbol
}



// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const CentroClasificacion dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato->IdCentro) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat.IdCentro > actual->dato->IdCentro) actual = actual->derecho;
         else if(dat.IdCentro < actual->dato->IdCentro) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(NodoArbol *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ArbolABB::auxAltura(NodoArbol *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
   cout << d << ",";
}

// Funciones PILA:

//Destructor de la Pila
Pila::~Pila()
{
    while(cima) desapilar();
}
//Meter elemento en la Pila
void Pila::apilar(Caja v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
//Se crea un nodo nuevo
    nuevo = new NodoPila(v, cima);
//El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}

//Sacar elemento de la Pila
Caja Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    Caja v; //Var aux para el retorno del valor del nodo
    Caja vacio={"","","",""};

    if(!cima) return vacio; // Si no hay nodos en la pila se devuelve 0, lo asumimos solo para este ejemplo.
// Nodo apunta al primer elemento de la pila
    nodo = cima;
//Se asigna a pila toda la pila menos el primer elemento
    cima= nodo->siguiente;
//Se guarda el retorno del valor del nodo
    v = nodo->valor;
//Se borra el nodo
    delete nodo;
    nodo = nullptr;
    return v;
}

//Mostrar cima Pila
Caja Pila::mostrarCima()
{
    Caja vacio={"","","",""};
    if(!cima) return vacio; // Si no hay nodos en la pila se devuelve 0, lo asumimos solo para este ejemplo.
    return (cima->valor);
}

bool Pila::vacia(){
    if (cima==NULL){
        return true;
    }
    else{
        return false;
    }
}

int Pila::contarElementosPila(){
    int contador =0;
    pNodo actual = cima;
    while (actual != NULL)
    {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

/* Opción recursiva: (Al crearlo en la memoria estática, parece optimo usar iterativa).
int contarElementosPila(Pila pila){
    if (pila.vacia()){
        return 0;
    }
    else {
        pila.desapilar();
        return 1 + contarElementosPila(pila);
    }
}
*/

Pila *copiarPila(Pila *pilaOriginal) {
    Pila *pilaCopia = new Pila();
    Pila *pilaTemporal = new Pila();

    while (!pilaOriginal->vacia()) {
        Caja elemento = pilaOriginal->desapilar();
        pilaTemporal->apilar(elemento);
    }

    while (!pilaTemporal->vacia()) {
        Caja elemento = pilaTemporal->desapilar();
        pilaCopia->apilar(elemento);
        pilaOriginal->apilar(elemento);
    }
    delete pilaTemporal;

    return pilaCopia;
}

Pila* invertirPila(Pila* pilaOriginal) {
    Pila* pilaInvertida = new Pila();
    Pila* pilaTemporal = new Pila();

    while (!pilaOriginal->vacia()) {
        Caja elemento = pilaOriginal->desapilar();
        pilaTemporal->apilar(elemento);
    }

    while (!pilaTemporal->vacia()) {
        Caja elemento = pilaTemporal->desapilar();
        pilaInvertida->apilar(elemento);
    }

    delete pilaTemporal;

    return pilaInvertida;
}


//-------------------------------------------------------------------




string centrosPosibles[] = {  "Mostoles", "Alcala", "Leganes", "Fuenlabrada", "Getafe", "Alcorcon", "Torrejon",

                            "Parla", "Alcobendas", "Coslada", "Pozuelo", "Rivas", "Valdemoro",

                            "Majadahonda", "Aranjuez", "Arganda", "Boadilla", "Pinto", "Colmenar", "Tres Cantos"

                        };

string randomCentros (ListaRegistroCentros *listaCentros){

    //string centro = centrosPosibles[rand() % (sizeof(centrosPosibles) /sizeof(centrosPosibles[0])) ];
    string centro = listaCentros->randomIDCentro();
    return centro;

}

bool comprobarCentrosPosibles(ListaRegistroCentros *listaCentros){
    int longitud = sizeof(centrosPosibles) / sizeof(centrosPosibles[0]);
    for (int i = 0; i < longitud; ++i) {
        //cout << centrosPosibles[i] << endl;
        if (!listaCentros->buscarCentro(centrosPosibles[i])){
            return true;
        }
    }
    return false;
}

string randomCentrosNoRegistrado (ListaRegistroCentros *listaCentros){
    string centroAleatorio;
    if (comprobarCentrosPosibles(listaCentros)){
        //cout << "HAY CENTROS POR DEFECTO SIN REGISTRAR ELIJO UNO" << endl;
        do {
            centroAleatorio = centrosPosibles[rand() % (sizeof(centrosPosibles) /sizeof(centrosPosibles[0])) ];
        } while (listaCentros->buscarCentro(centroAleatorio));
    }
    else {
        do {
        //cin.ignore();
        cout << "Por favor, ingrese un nombre de centro ya no hay disponibles por defecto: ";
        getline(cin, centroAleatorio);
        if (listaCentros->buscarCentro(centroAleatorio)) {
            cout << "El nombre ingresado ya esta registrado. Intenta de nuevo." << endl;
        }
    } while (listaCentros->buscarCentro(centroAleatorio));
    }

    return centroAleatorio;
}

int generarNumeroRandom() {
    // Generar un número aleatorio en el rango [0, 999]
    int numeroRandom = rand() % 1000;
    return numeroRandom;
}

int generarNumeroRandomNoRegistrado(ListaRegistroCentros *listaCentros) {
    // Generar un número aleatorio en el rango [0, 999]
    int numeroRandom;
    do {
        numeroRandom = rand() % 1000;
    } while (listaCentros->buscarID(numeroRandom));
    return numeroRandom;
}

string randomProductos (){

    string productos[] = {  "harina", "pasta", "legumbres", "leche", "medicinas", "higiene", "agua",
                            "aceite", "sal", "azucar", "galletas", "latas_cons", "iluminacion",
                            "herramientas", "combustible", "tiendas_camp", "ropa", "mantas", "limpieza"
                        };
    string producto = productos[rand() % 19];
    return producto;
}

string fechaCaducidad(string producto) {

    string fechaCaducidad;

    if (producto == "higiene" || producto == "iluminacion" || producto == "herramientas" ||
        producto == "combustible" || producto == "tiendas_camp" || producto == "ropa" ||
        producto == "mantas" || producto == "limpieza" || producto == "azúcar" || producto == "sal") {
        fechaCaducidad = "12/2100";
    } else if (producto == "harina" || producto == "leche" || producto == "galletas") {
        int anyo = 2023;
        int mes = 1 + (std::rand() % 12);
        fechaCaducidad = std::to_string(mes) + "/" + std::to_string(anyo);
    } else if (producto == "pasta" || producto == "legumbres" || producto == "medicinas" ||
               producto == "aceite" || producto == "agua" || producto == "latas_cons") {
        int anyo = 2023 + (std::rand() % 5);
        int mes = 1 + (std::rand() % 12);
        fechaCaducidad = std::to_string(mes) + "/" + std::to_string(anyo);
    }
    else {
        fechaCaducidad = "12/2100";
    }
    return fechaCaducidad;
}

string generadorIDCaja(){
    string id="";
    string localizaciones[] = { "MAR", "GRE", "LIB"};
    id = localizaciones[rand() % 3];
    int idnumber = rand() % 10000;
    id = id + to_string(idnumber);

    string origenes[] = { "Daganzo", "Meco", "Loeches","Torrejon"};
    id = id + origenes[rand() % 4][0];
    return id;
}

int generarNumeroAleatorio() {
    return rand() % 31 + 1; // Genera un número entre 1 y 31
}

// Función generadora de centros y asocación al arbol.

void simulacionCentroDeControl(int numSimulaciones, ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros){
    for (int i=0; i< numSimulaciones; i++){

        //BUG EN CASO DE QUE SE AÑADAN MANUALMENTE CENTROS: SOlucionado comentado el if y modificando funcion randomCentrosNoRegistrado;
        //if (  (sizeof(centrosPosibles) /sizeof(centrosPosibles[0]))  > (listaCentros->contarElementosLista()) ){
            //cout << " hay centro disponibles" << endl;
            //cout << (listaCentros->contarElementosLista()) << endl;
            //cout << randomCentros() << endl;
            //RegistroCentros centroRegistro;
            RegistroCentros *centroRegistro= new  RegistroCentros();
            string centroReferencia=randomCentrosNoRegistrado (listaCentros);
            int centroReferenciaId=generarNumeroRandomNoRegistrado (listaCentros);
            centroRegistro->CentroRef=centroReferencia;
            centroRegistro->IdCentro=centroReferenciaId;
            centroRegistro->estadistica= new Estadistica;
            listaCentros->insertarNodo(centroRegistro);

            // antes de borrar debug
            /*
            CentroClasificacion centro;
            centro.CentroRef=centroReferencia;
            centro.IdCentro=centroReferenciaId;
            arbolDeCentros->Insertar(centro);
            */

            //HECHO TRANSFORMAR EL ARBOL O NO PARA QUE LOS NODOS SEAN PUNTEROS A CENTROS DE CLASFICACION;
            CentroClasificacion *centro= new CentroClasificacion();
            centro->CentroRef=centroReferencia;
            centro->IdCentro=centroReferenciaId;
            arbolDeCentros->Insertar(centro);

        //}
        //else {
         //   cout << " NO hay centro disponibles" << endl;
        //}
    }
    cout << "Arbol vacio creado:\n" << endl;
}

//OPCION 1 menu
void crearCCmanual(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros){

    int centroReferenciaId;
    string centroReferencia;
    do {
        cout << "Por favor, ingrese un numero de tres cifras: ";
        cin >> centroReferenciaId;

        if (centroReferenciaId < 100 || centroReferenciaId > 999) {
            cout << "El numero ingresado no tiene tres cifras. Intenta de nuevo." << endl;
        }

        if (listaCentros->buscarID(centroReferenciaId) ) {
            cout << "El numero ingresado ya esta registrado. Intenta de nuevo." << endl;
        }

    } while (listaCentros->buscarID(centroReferenciaId)  || centroReferenciaId < 100 || centroReferenciaId > 999  );


    do {
        cin.ignore();
        cout << "Por favor, ingrese un nombre de centro: ";
        getline(cin, centroReferencia);
        if (listaCentros->buscarCentro(centroReferencia)) {
            cout << "El nombre ingresado ya esta registrado. Intenta de nuevo." << endl;
        }
    } while (listaCentros->buscarCentro(centroReferencia));

    //RegistroCentros centroRegistro;
    RegistroCentros *centroRegistro= new  RegistroCentros();
    centroRegistro->CentroRef=centroReferencia;
    centroRegistro->IdCentro=centroReferenciaId;
    centroRegistro->estadistica= new Estadistica;
    listaCentros->insertarNodo(centroRegistro);

    CentroClasificacion *centro= new CentroClasificacion();
    centro->CentroRef=centroReferencia;
    centro->IdCentro=centroReferenciaId;
    arbolDeCentros->Insertar(centro);

}


//OPCION 2 menu

void borrarCC(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros) {
    int centroReferenciaId;
    cout << "Listado de intentificadores de CC disponibles: ";
    arbolDeCentros->InOrden(Mostrar);

    cout << "Por favor, ingrese el numero de indentificacion del centro: ";
    cin >> centroReferenciaId;

    if (!listaCentros->buscarID(centroReferenciaId) ) {
            cout << "El numero ingresado no esta registrado. No se borrara nigun centro." << endl;
        }
    if (listaCentros->buscarID(centroReferenciaId) ) {
            cout << "El numero ingresado  esta registrado. Se borrara ese centro." << endl;
            listaCentros->borrarNodoPorRegistroID(centroReferenciaId);
            arbolDeCentros->BorrarPorId(centroReferenciaId);
        }



}

//OPCION 3 menu
void mostrarDatosCC(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros) {

    int centroReferenciaId;
    cout << "Listado de intentificadores de CC disponibles: " << endl;
    arbolDeCentros->InOrden(Mostrar);
    cout << "\n";
    cout << "Introduzca ID del Centro de Clasificacion que desea buscar: ";
    cin >> centroReferenciaId;

    if (!listaCentros->buscarID(centroReferenciaId) ) {
            cout << "El ID ingresado no esta registrado. No se encuentra el centro." << endl;
        }
    if (listaCentros->buscarID(centroReferenciaId) ) {
            cout << "Centro encontrado." << endl;
            //listaCentros->borrarNodoPorRegistroID(centroReferenciaId);
            //arbolDeCentros->BorrarPorId(centroReferenciaId);
            cout << "ID Central: " << arbolDeCentros->BuscarPorIdRecuperarCC(centroReferenciaId)->IdCentro << endl;
            cout  << "Localidad: " << arbolDeCentros->BuscarPorIdRecuperarCC(centroReferenciaId)->CentroRef << endl;
            cout  << "Num cajas: " << arbolDeCentros->BuscarPorIdRecuperarCC(centroReferenciaId)->listaDeCajas.numeroDeElementos() << endl;
            //arbolDeCentros->BuscarPorIdRecuperarCC(centroReferenciaId)->listaDeCajas.recorrerLista()

            Pila *pilaDeCajas = new Pila();
            pilaDeCajas=arbolDeCentros->BuscarPorIdRecuperarCC(centroReferenciaId)->listaDeCajas.recorrerListaCajas(pilaDeCajas);
            printDatosPilaCajas(pilaDeCajas);

            //pilaDeCajas->apilar(arbolDeCentros->BuscarPorIdRecuperarCC(centroReferenciaId)->listaDeCajas.recorrerListaCajas());
            //printDatosPilaCajas(pilaDeCajas);
            //arbolDeCentros->BuscarPorIdRecuperarCC(centroReferenciaId)->listaDeCajas.
        }
}

//OPCION 4 menu
void buscarCajaPorID(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros) {
    string idCaja;
    cin.ignore();
    cout << "Introduzca ID de la caja que desea buscar: " << endl;
    getline(cin, idCaja);
    Caja caja;
    caja=listaCentros->buscarCajaMedianteRegistroDeCajas(idCaja,arbolDeCentros);
    if (caja.Id=="CajaNoEncontrada"){
        cout << "La caja no fue encontrar" << endl;
    }
    else{
        cout << "Centro de referncia: " << caja.CentroRef << endl;
        cout << "Contenido: " << caja.Contenido << endl;
        cout << "Fecha de consumo: " <<  caja.FechaConsumo << endl;
        cout << "Fecha de recogida: " << caja.FechaRecogida << endl;
        cout << "ID de la caja: " << caja.Id << endl;
        cout << "ID del centro: " <<caja.IdCentro << endl;

    }
}


//OPCION 5 menu
void buscarCajaPorIDyBorrar(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros) {
    string idCaja;
    cin.ignore();
    cout << "Introduzca ID de la caja que desea borrar: " << endl;
    getline(cin, idCaja);
    Caja caja;
    caja=listaCentros->buscarCajaMedianteRegistroDeCajas(idCaja,arbolDeCentros);
    if (caja.Id=="CajaNoEncontrada"){
        cout << "La caja no fue encontrar" << endl;
    }
    else{
        cout << "La caja fue encontrada y se borrara" << endl;
        cout << "Centro de referncia: " << caja.CentroRef << endl;
        cout << "Contenido: " << caja.Contenido << endl;
        cout << "Fecha de consumo: " <<  caja.FechaConsumo << endl;
        cout << "Fecha de recogida: " << caja.FechaRecogida << endl;
        cout << "ID de la caja: " << caja.Id << endl;
        cout << "ID del centro: " <<caja.IdCentro << endl;
        //arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro).listaDeCajas->borrarNodoPorCajaID(caja.Id);
        CentroClasificacion* centroEncontrado = arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro);
        centroEncontrado->listaDeCajas.borrarNodoPorCajaID(caja.Id);
        //arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro)->listaDeCajas->borrarNodoPorCajaID(caja.Id);
    }
}


//OPCION 6
void buscarCajaPorIDyMoverlaCC(ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros) {
    int centroReferenciaId;
    string idCaja;
    cout << "Listado de intentificadores de CC disponibles: " << endl;
    arbolDeCentros->InOrden(Mostrar);
    cout << "\n";
    cout << "Introduzca ID del Centro de Clasificacion al que desea mover la caja: ";
    cin >> centroReferenciaId;

    if (listaCentros->buscarID(centroReferenciaId) ) {
            cout << "El numero ingresado  esta registrado." << endl;
            cout << "Introduzca ID de la caja que desea mover: ";
            cin.ignore();
            getline(cin, idCaja);
            Caja caja;
        caja=listaCentros->buscarCajaMedianteRegistroDeCajas(idCaja,arbolDeCentros);
        if (caja.Id=="CajaNoEncontrada"){
            cout << "La caja no fue encontrar" << endl;
        }
        else{
            cout << "La caja fue encontrada y se movera desde el centro" << caja.IdCentro  << "al" <<centroReferenciaId <<endl;
            CentroClasificacion* centroEncontrado = arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro);
            centroEncontrado->listaDeCajas.borrarNodoPorCajaID(caja.Id);
            caja.IdCentro=centroReferenciaId;
            caja.CentroRef=listaCentros->buscarIDRecuperarCentroRef(centroReferenciaId);
            arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro)->listaDeCajas.insertarNodo(caja);

            //arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro).listaDeCajas->borrarNodoPorCajaID(caja.Id);
            //CentroClasificacion* centroEncontrado = arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro);
            //centroEncontrado->listaDeCajas.borrarNodoPorCajaID(caja.Id);
            //arbolDeCentros->BuscarPorIdRecuperarCC(caja.IdCentro)->listaDeCajas->borrarNodoPorCajaID(caja.Id);
        }
    }
    else{
        cout << "El numero ingresado no esta registrado." << endl;
    }
}

//OPCION 7 TO_DO



//OPCION 8 en main.



//void  estadoCentrosArbol(ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros){
    //listaCentros.recorrerLista
    //arbolDeCentros->PreOrden(Mostrar);

//}

void simulacionCreacionCajas(int numSimulaciones, ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros,Pila* pilaDeCajas ){
    for (int i=0; i< numSimulaciones; i++){
        Caja nuevaCaja;
        do{
            nuevaCaja.CentroRef=randomCentros (listaCentros);
        } while (!arbolDeCentros->BuscarPorId(listaCentros->buscarCentroRefRecuperarID(nuevaCaja.CentroRef))); //Sacamos el ID del centro y confirmamos que existe en el arbol.
        nuevaCaja.IdCentro=listaCentros->buscarCentroRefRecuperarID(nuevaCaja.CentroRef);
        nuevaCaja.Contenido=randomProductos();
        nuevaCaja.FechaConsumo=fechaCaducidad(nuevaCaja.Contenido);
        nuevaCaja.Id=generadorIDCaja();
        nuevaCaja.FechaRecogida=generarNumeroAleatorio();

        //cout << nuevaCaja.CentroRef << " " << nuevaCaja.Contenido << " " << nuevaCaja.FechaConsumo << " " << nuevaCaja.FechaRecogida << " " << nuevaCaja.Id << " " << nuevaCaja.IdCentro << endl;
        pilaDeCajas->apilar(nuevaCaja);
    }
    //listaCentros->buscarIDRecuperarCentroRef
    //buscarIDRecuperarCentroRef
    //while (!listaCentros->buscarCentro(nuevaCaja.CentroRef)); && arbolDeCentros->BuscarPorId(nuevaCaja.CentroRef)

    //listaCentros->buscarID(nuevaCaja.CentroRef) && arbolDeCentros.BuscarPorId(nuevaCaja.CentroRef);
    //listaCentros->buscarID(nuevaCaja.CentroRef);
    //arbolDeCentros->

}

void actualizareEstadisitcas(Caja caja, RegistroCentros * centro, Estadistica *estadisticaTotal){
    if  (caja.Id.substr(0, 3) == "MAR"){
            //centro->estadistica->aceite=1;
            centro->estadistica->marruecosDestino+=1;
            estadisticaTotal->marruecosDestino+=1;

    }
    if  (caja.Id.substr(0, 3) == "GRE"){
            //estadistica->libiaDestino+=1;
            centro->estadistica->greciaDestino+=1;
             estadisticaTotal->greciaDestino+=1;
    }
    if  (caja.Id.substr(0, 3) == "LIB"){
            //estadistica->greciaDestino+=1;
             centro->estadistica->libiaDestino+=1;
            estadisticaTotal->libiaDestino+=1;
    }
    if  (caja.Id.back() == 'D'){
            //estadistica->daganzoOrigen+=1;
            centro->estadistica->daganzoOrigen+=1;
             estadisticaTotal->daganzoOrigen+=1;
    }
    if  (caja.Id.back() == 'M'){
            //estadistica->mecoOrigen+=1;
            centro->estadistica->mecoOrigen+=1;
             estadisticaTotal->mecoOrigen+=1;
    }
    if  (caja.Id.back() == 'L'){
            //estadistica->loechesOrigen+=1;
            centro->estadistica->loechesOrigen+=1;
             estadisticaTotal->loechesOrigen+=1;
    }
    if  (caja.Id.back() == 'T'){
            //estadistica->torrejonOrigen+=1;
            centro->estadistica->torrejonOrigen+=1;
            estadisticaTotal->torrejonOrigen+=1;
    }
    if  (caja.Contenido == "harina"){
            //estadistica->harina+=1;
            centro->estadistica->harina+=1;
            estadisticaTotal->harina+=1;
    }
    if  (caja.Contenido == "pasta"){
            //estadistica->pasta+=1;
            centro->estadistica->pasta+=1;
            estadisticaTotal->pasta+=1;
    }
    if  (caja.Contenido == "legumbres"){
            //estadistica->legumbres+=1;
            centro->estadistica->legumbres+=1;
            estadisticaTotal->legumbres+=1;
    }
    if  (caja.Contenido == "leche"){
            //estadistica->leche+=1;
            centro->estadistica->leche+=1;
            estadisticaTotal->leche+=1;
    }
    if  (caja.Contenido == "medicinas"){
            //estadistica->medicinas+=1;
            centro->estadistica->medicinas+=1;
             estadisticaTotal->medicinas+=1;
    }
    if  (caja.Contenido == "higiene"){
            //estadistica->higiene+=1;
            centro->estadistica->higiene+=1;
             estadisticaTotal->higiene+=1;
    }
    if  (caja.Contenido == "agua"){
            //estadistica->agua+=1;
            centro->estadistica->agua+=1;
             estadisticaTotal->agua+=1;
    }
    if  (caja.Contenido == "aceite"){
            //estadistica->aceite+=1;
            centro->estadistica->aceite+=1;
             estadisticaTotal->aceite+=1;
    }
    if  (caja.Contenido == "sal"){
            //estadistica->sal+=1;
            centro->estadistica->sal+=1;
            estadisticaTotal->sal+=1;
    }
    if  (caja.Contenido == "azucar"){
            //estadistica->azucar+=1;
            centro->estadistica->azucar+=1;
            estadisticaTotal->azucar+=1;
    }
    if  (caja.Contenido == "galletas"){
            //estadistica->galletas+=1;
            centro->estadistica->galletas+=1;
            estadisticaTotal->galletas+=1;
    }
    if  (caja.Contenido == "latas_cons"){
            //estadistica->latas_cons+=1;
            centro->estadistica->latas_cons+=1;
            estadisticaTotal->latas_cons+=1;
    }
    if  (caja.Contenido == "iluminacion"){
            //estadistica->iluminacion+=1;
            centro->estadistica->iluminacion+=1;
            estadisticaTotal->iluminacion+=1;
    }
    if  (caja.Contenido == "herramientas"){
            //estadistica->herramientas+=1;
            centro->estadistica->herramientas+=1;
            estadisticaTotal->herramientas+=1;
    }
    if  (caja.Contenido == "combustible"){
            //estadistica->combustible+=1;
            centro->estadistica->combustible+=1;
            estadisticaTotal->combustible+=1;
    }
    if  (caja.Contenido == "tiendas_camp"){
            //estadistica->tiendas_camp+=1;
            centro->estadistica->tiendas_camp+=1;
            estadisticaTotal->tiendas_camp+=1;
    }
    if  (caja.Contenido == "ropa"){
            //estadistica->ropa+=1;
            centro->estadistica->ropa+=1;
            estadisticaTotal->ropa+=1;
    }
    if  (caja.Contenido == "mantas"){
            //estadistica->mantas+=1;
            centro->estadistica->mantas+=1;
            estadisticaTotal->mantas+=1;
    }
    if  (caja.Contenido == "limpieza"){
            //estadistica->limpieza+=1;
            centro->estadistica->limpieza+=1;
            estadisticaTotal->limpieza+=1;
    }
 }


void repartirCajas(ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros,Pila* pilaDeCajas, Estadistica *estadisticaTotal) {
    //cout << listaCentros->valorActual().estadistica.aceite << endl;

    while (!pilaDeCajas->vacia()){

        //arbolDeCentros->BuscarPorIdRecuperarCC();
        //cout << pilaDeCajas->mostrarCima().IdCentro << endl;

        //CentroClasificacion centro2=arbolDeCentros->BuscarPorIdRecuperarCC( pilaDeCajas->mostrarCima().IdCentro);
        //cout << arbolDeCentros->BuscarPorIdRecuperarCC( pilaDeCajas->mostrarCima().IdCentro)->listaDeCajas.numeroDeElementos() << endl;

        //listaCentros->buscarCentroRefRecuperarEstadistica(pilaDeCajas->mostrarCima().IdCentro).greciaDestino="hola";

        //WIP
        //Estadistica estadistica = listaCentros->buscarCentroRefRecuperarEstadistica(pilaDeCajas->mostrarCima().IdCentro);
        //estadistica.greciaDestino=10;
        //estadistica.aceite=20;

        //listaCentros->buscarCentroRefRecuperarEstadistica(pilaDeCajas->mostrarCima().IdCentro)->aceite=1;

        //WIP   ListaRegistroCentros *listaCentros= new ListaRegistroCentros();

        Caja caja= pilaDeCajas->mostrarCima();
        //listaCentros->

        //actualizareEstadisitcas(caja,listaCentros->buscarCentroRefRecuperarEstadistica(pilaDeCajas->mostrarCima().IdCentro));

        //actualizareEstadisitcas(caja,listaCentros->buscarIDRecuperarCentroRefCompleto(caja.IdCentro));
        //cout << listaCentros->buscarIDRecuperarCentroRefCompleto(caja.IdCentro)->estadistica->aceite;
        //cout << listaCentros->buscarIDRecuperarCentroRefCompleto(caja.IdCentro)->estadistica->aceite;
        //estadisticaTotal
        actualizareEstadisitcas(caja,listaCentros->buscarIDRecuperarCentroRefCompleto(caja.IdCentro),estadisticaTotal);





        arbolDeCentros->BuscarPorIdRecuperarCC( pilaDeCajas->mostrarCima().IdCentro)->listaDeCajas.insertarNodo(pilaDeCajas->desapilar());
        //actualizareEstadisitcas(caja,listaCentros->buscarCentroRefRecuperarEstadistica(caja.IdCentro));
        //WIP

        //WIP
        //cout << arbolDeCentros->BuscarPorIdRecuperarCC( pilaDeCajas->mostrarCima().IdCentro)->listaDeCajas.numeroDeElementos() << endl;
    }
}

void printMenu(int &opcion){
    cout << "Opciones disponibles:" << endl;
    cout << "1- Insertar un CC de forma manual." << endl;
    cout << "2- Borrar un CC del arbol." << endl;
    cout << "3- Mostrar los datos de las cajas que se distribuiran desde un CC dado." << endl;
    cout << "4- Buscar una caja concreta por su ID." << endl;
    cout << "5- Extraer una caja concreta." << endl;
    cout << "6- Llevar una caja concreta de un CC a otro." << endl;
    cout << "7- Mostrar una estadistica de los CC de la ONG." << endl;
    cout << "8- Continuar con la distribucion de cajas." << endl;
    cout << "0) Salir del programa." << endl;

    cout << "Seleccione una opcion del menu:"  << endl;
    cin >> opcion;

}

void printDatosPilaCajas(Pila* pilaDeCajas){


cout << "----------------------------------------------------------------------" << endl;
cout << "|" << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(12) << "ID centro |"
     << setw(16) << "Contenido |"
     << setw(14) << "Fecha cons |"
     << setw(4) << "Dia |" << endl;
cout << "----------------------------------------------------------------------" << endl;
int numCajas=pilaDeCajas->contarElementosPila();
for (int i=0; i < numCajas; i++) {
    if (pilaDeCajas->vacia()) {
        cout << "|" << setw(10) << "--- |"
                    << setw(12) << "--- |"
                    << setw(12) << "--- |"
                    << setw(16) << "--- |"
                    << setw(14) << "--- |"
                    << setw(4) << "--- |" << endl;
    }
    else {
        cout << "|" << setw(10) << pilaDeCajas->mostrarCima().Id + "|"
        << setw(10) << pilaDeCajas->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(10) << pilaDeCajas->mostrarCima().IdCentro
        << setw(2) << "|"
        << setw(14) << pilaDeCajas->mostrarCima().Contenido
        << setw(2) << "|"
        << setw(13) << pilaDeCajas->mostrarCima().FechaConsumo << "|"
        << setw(4) << pilaDeCajas->mostrarCima().FechaRecogida << "|" << endl;
    }
    pilaDeCajas->desapilar();
}
cout << "----------------------------------------------------------------------" << endl;
cout << "\n" ;
cout << "\n" ;
}

void printEstadisticas(Estadistica* estadistica){

    cout << "+------------------------+----------------+\n";
    cout << "|       Destino          |      Cantidad  |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Marruecos              | " << setw(14) << estadistica->marruecosDestino << " |\n";
    cout << "| Libia                  | " << setw(14) << estadistica->libiaDestino << " |\n";
    cout << "| Grecia                 | " << setw(14) << estadistica->greciaDestino << " |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Origen                 |      Cantidad  |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Daganzo                | " << setw(14) << estadistica->daganzoOrigen << " |\n";
    cout << "| Meco                   | " << setw(14) << estadistica->mecoOrigen << " |\n";
    cout << "| Loeches                | " << setw(14) << estadistica->loechesOrigen << " |\n";
    cout << "| Torrejon               | " << setw(14) << estadistica->torrejonOrigen << " |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Productos              |      Cantidad  |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Harina                 | " << setw(14) << estadistica->harina << " |\n";
    cout << "| Pasta                  | " << setw(14) << estadistica->pasta << " |\n";
    cout << "| Galletas               | " << setw(14) << estadistica->galletas << " |\n";
    cout << "| Legumbres              | " << setw(14) << estadistica->legumbres << " |\n";
    cout << "| Leche                  | " << setw(14) << estadistica->leche << " |\n";
    cout << "| medicinas              | " << setw(14) << estadistica->medicinas << " |\n";
    cout << "| higiene                | " << setw(14) << estadistica->higiene << " |\n";
    cout << "| agua                   | " << setw(14) << estadistica->agua << " |\n";
    cout << "| aceite                 | " << setw(14) << estadistica->aceite << " |\n";
    cout << "| sal                    | " << setw(14) << estadistica->sal << " |\n";
    cout << "| azucar                 | " << setw(14) << estadistica->azucar << " |\n";
    cout << "| galletas               | " << setw(14) << estadistica->galletas << " |\n";
    cout << "| latas_cons             | " << setw(14) << estadistica->latas_cons << " |\n";
    cout << "| iluminacion            | " << setw(14) << estadistica->iluminacion << " |\n";
    cout << "| herramientas           | " << setw(14) << estadistica->herramientas << " |\n";
    cout << "| combustible            | " << setw(14) << estadistica->combustible << " |\n";
    cout << "| tiendas_camp           | " << setw(14) << estadistica->tiendas_camp << " |\n";
    cout << "| ropa                   | " << setw(14) << estadistica->ropa << " |\n";
    cout << "| mantas                 | " << setw(14) << estadistica->mantas << " |\n";
    cout << "| limpieza               | " << setw(14) << estadistica->limpieza << " |\n";
    cout << "+------------------------+----------------+\n";
    cout << "\n" ;

    int max_valor_pais = max({estadistica->marruecosDestino, estadistica->libiaDestino, estadistica->greciaDestino});
     if (max_valor_pais == 0 ){
            cout << "Aun no tenemos datos suficientes." << endl;
     }
     else if (max_valor_pais == (estadistica->marruecosDestino) ){
            cout << "La gente esta siendo mas solidaria con la poblacion de  Marruecos." << endl;
     }
     else if (max_valor_pais == (estadistica->libiaDestino) ){
            cout << "La gente esta siendo mas solidaria con la poblacion de  Libia." << endl;
     }
     else{
            cout << "La gente esta siendo mas solidaria con la poblacion de  Grecia." << endl;
     }

     int max_valor_origen = max({estadistica->daganzoOrigen, estadistica->mecoOrigen, estadistica->loechesOrigen, estadistica->torrejonOrigen});
     if (max_valor_origen == 0 ){
            cout << "Aun no tenemos datos suficientes." << endl;
     }
     else if (max_valor_origen == (estadistica->daganzoOrigen) ){
            cout << "La poblacion mas solidaria es Danzo." << endl;
     }
     else if (max_valor_origen == (estadistica->mecoOrigen) ){
            cout << "La poblacion mas solidaria es Meco." << endl;
     }
     else if (max_valor_origen == (estadistica->loechesOrigen) ){
            cout << "La poblacion mas solidaria es Loeche." << endl;
     }
     else{
            cout << "La poblacion mas solidaria es Torrejon." << endl;
     }
     cout << "\n" ;
}

