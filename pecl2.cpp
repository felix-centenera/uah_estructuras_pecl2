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
    if(!listaVacia()) // M�s sencillo
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

void ListaRegistroCentros::imprimirDatosMedianteRegistoDeLista(ArbolABB *arbolDeCentros)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (arbolDeCentros->BuscarPorId(aux->valor.IdCentro)){
            //cout << aux->valor.IdCentro << "-> se encontro";
            //cout << "el id es yeah: " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor.IdCentro).CentroRef << endl;
            cout << "ID: " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor.IdCentro).IdCentro << "   Localidad:   " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor.IdCentro).CentroRef << "    Num cajas:  " << arbolDeCentros->BuscarPorIdRecuperarCC(aux->valor.IdCentro).listaDeCajas.numeroDeElementos() << endl;
        }
        aux = aux->siguiente;
    }
    cout << endl;
}


bool ListaRegistroCentros::buscarID(int v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor.IdCentro == v){
            return true;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
    return false;
}

bool ListaRegistroCentros::buscarCentro(string v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor.CentroRef == v){
            return true;
        }
        aux = aux->siguiente;
    }
    //cout << endl;
    return false;
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
    if(!listaVacia()) // M�s sencillo
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



// ----------------------------------------------- Arbol de CentrosClasificaci�n -----------------------------------------------
//Destructor
ArbolABB::~ArbolABB()
        {
            Podar(raiz);
        }

//�rbol vac�o
bool ArbolABB::Vacio(NodoArbol *r)
        {
            return r==NULL;
        }

//NodoArbol es de tipo hoja
bool ArbolABB::EsHoja(NodoArbol *r)
        {
            return !r->derecho && !r->izquierdo;
        }

//Coloca el nodo actual en ra�z
void ArbolABB::Raiz()
        {
            actual = raiz;
        }

CentroClasificacion ArbolABB::VerRaiz()
{
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

// Insertar un CentroClasificacion en el �rbol ABB
void ArbolABB::Insertar(const CentroClasificacion dat)
{
   NodoArbol *padre = NULL;

   actual = raiz;
   // Buscar el int/CentroClasificacion en el �rbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat.IdCentro != actual->dato.IdCentro) {
      padre = actual;
      if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho;
      else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoArbol(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat.IdCentro < padre->dato.IdCentro) padre->izquierdo = new NodoArbol(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat.IdCentro > padre->dato.IdCentro) padre->derecho = new NodoArbol(dat);
}

// Eliminar un elemento de un �rbol ABB
void ArbolABB::Borrar(const CentroClasificacion dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor est� en el �rbol
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato.IdCentro) { // Si el valor est� en el nodo actual
         if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
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
         else { // Si el valor est� en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo m�s izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo m�s derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que s�lo se eliminan nodos hoja.
            aux = actual->dato.IdCentro;
            actual->dato.IdCentro = nodo->dato.IdCentro;
            nodo->dato.IdCentro = aux;
            actual = nodo;
         }
      }
      else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
         padre = actual;
         if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho;
         else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
      }
   }
}


// Eliminar un elemento de un �rbol ABB
void ArbolABB::BorrarPorId(const int dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor est� en el �rbol
   while(!Vacio(actual)) {
      if(dat == actual->dato.IdCentro) { // Si el valor est� en el nodo actual
         if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
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
         else { // Si el valor est� en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo m�s izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo m�s derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que s�lo se eliminan nodos hoja.
            aux = actual->dato.IdCentro;
            actual->dato.IdCentro = nodo->dato.IdCentro;
            nodo->dato.IdCentro = aux;
            actual = nodo;
         }
      }
      else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
         padre = actual;
         if(dat > actual->dato.IdCentro) actual = actual->derecho;
         else if(dat < actual->dato.IdCentro) actual = actual->izquierdo;
      }
   }
}

// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) , NodoArbol *nodo, bool r)
{
  if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato.IdCentro);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(int&), NodoArbol *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   func(nodo->dato.IdCentro);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(int&), NodoArbol *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato.IdCentro);
}

// Buscar un valor en el �rbol
bool ArbolABB::Buscar(const CentroClasificacion dat)
{
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato.IdCentro) return true; // int encontrado
      else if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho; // Seguir
      else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
   }
   return false; // No est� en �rbol
}

// Buscar un valor en el �rbol
bool ArbolABB::BuscarPorId(const int dat)
{
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato.IdCentro) return true; // int encontrado
      else if(dat > actual->dato.IdCentro) actual = actual->derecho; // Seguir
      else if(dat < actual->dato.IdCentro) actual = actual->izquierdo;
   }
   return false; // No est� en �rbol
}


// Buscar por id en el arbol y devolver el centro de clasificaci�n.
CentroClasificacion ArbolABB::BuscarPorIdRecuperarCC(const int dat)
{
   actual = raiz;
   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato.IdCentro) return actual->dato; // int encontrado
      else if(dat > actual->dato.IdCentro) actual = actual->derecho; // Seguir
      else if(dat < actual->dato.IdCentro) actual = actual->izquierdo;
   }
   // No est� en �rbol
}



// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const CentroClasificacion dat)
{
   int altura = 0;
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato.IdCentro) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho;
         else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
      }
   }
   return -1; // No est� en �rbol
}

// Contar el n�mero de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnci�n auxiliar
   return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(NodoArbol *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Funci�n auxiliar
   return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual
void ArbolABB::auxAltura(NodoArbol *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // �rbol, actualizamos la altura actual del �rbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Funci�n de prueba para recorridos del �rbol
void Mostrar(int &d)
{
   cout << d << ",";
}

string centrosPosibles[] = {  "Mostoles", "Alcala", "Leganes", "Fuenlabrada", "Getafe", "Alcorcon", "Torrejon",

                            "Parla", "Alcobendas", "Coslada", "Pozuelo", "Rivas", "Valdemoro",

                            "Majadahonda", "Aranjuez", "Arganda", "Boadilla", "Pinto", "Colmenar", "Tres Cantos"

                        };

string randomCentros (){

    string centro = centrosPosibles[rand() % (sizeof(centrosPosibles) /sizeof(centrosPosibles[0])) ];
    return centro;

}

string randomCentrosNoRegistrado (ListaRegistroCentros *listaCentros){
    string centroAleatorio;
    do {
        centroAleatorio = centrosPosibles[rand() % (sizeof(centrosPosibles) /sizeof(centrosPosibles[0])) ];
    } while (listaCentros->buscarCentro(centroAleatorio));
    return centroAleatorio;
}

int generarNumeroRandom() {
    // Generar un n�mero aleatorio en el rango [0, 999]
    int numeroRandom = rand() % 1000;
    return numeroRandom;
}

int generarNumeroRandomNoRegistrado(ListaRegistroCentros *listaCentros) {
    // Generar un n�mero aleatorio en el rango [0, 999]
    int numeroRandom;
    do {
        numeroRandom = rand() % 1000;
    } while (listaCentros->buscarID(numeroRandom));
    return numeroRandom;
}


// Funci�n generadora de centros y asocaci�n al arbol.

void simulacionCentroDeControl(int numSimulaciones, ListaRegistroCentros *listaCentros, ArbolABB *arbolDeCentros){
    for (int i=0; i< numSimulaciones; i++){
        if (  (sizeof(centrosPosibles) /sizeof(centrosPosibles[0]))  > (listaCentros->contarElementosLista()) ){
            //cout << " hay centro disponibles" << endl;
            //cout << (listaCentros->contarElementosLista()) << endl;
            //cout << randomCentros() << endl;
            RegistroCentros centroRegistro;
            string centroReferencia=randomCentrosNoRegistrado (listaCentros);
            int centroReferenciaId=generarNumeroRandomNoRegistrado (listaCentros);
            centroRegistro.CentroRef=centroReferencia;
            centroRegistro.IdCentro=centroReferenciaId;
            listaCentros->insertarNodo(centroRegistro);

            CentroClasificacion centro;
            centro.CentroRef=centroReferencia;
            centro.IdCentro=centroReferenciaId;
            arbolDeCentros->Insertar(centro);
            //PENSAR TRANSFORMAR EL ARBOL O NO PARA QUE LOS NODOS SEAN PUNTEROS A CENTROS DE CLASFICACION;
            //CentroClasificacion *centro= new CentroClasificacion();
           // centro->CentroRef=centroReferencia;
           // centro->IdCentro=centroReferenciaId;
           //  arbolDeCentros->Insertar(centro);
        }
        else {
            cout << " NO hay centro disponibles" << endl;
        }
    }
    cout << "Arbol vacio creado:\n" << endl;
}

//void  estadoCentrosArbol(ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros){
    //listaCentros.recorrerLista
    //arbolDeCentros->PreOrden(Mostrar);

//}

