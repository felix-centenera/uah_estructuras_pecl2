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

string ListaRegistroCentros::buscarIDRecuperarCentroRef(int v)
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        //cout << aux->valor.IdCentro << "-> ";
        if (aux->valor.IdCentro == v){
            return aux->valor.CentroRef;
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
        if (aux->valor.CentroRef == v){
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
        if (aux->valor.CentroRef == v){
            return aux->valor.IdCentro;
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

// Insertar un CentroClasificacion en el árbol ABB
void ArbolABB::Insertar(const CentroClasificacion dat)
{
   NodoArbol *padre = NULL;

   actual = raiz;
   // Buscar el int/CentroClasificacion en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat.IdCentro != actual->dato.IdCentro) {
      padre = actual;
      if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho;
      else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoArbol(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat.IdCentro < padre->dato.IdCentro) padre->izquierdo = new NodoArbol(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat.IdCentro > padre->dato.IdCentro) padre->derecho = new NodoArbol(dat);
}

// Eliminar un elemento de un árbol ABB
void ArbolABB::Borrar(const CentroClasificacion dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato.IdCentro) { // Si el valor está en el nodo actual
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
            aux = actual->dato.IdCentro;
            actual->dato.IdCentro = nodo->dato.IdCentro;
            nodo->dato.IdCentro = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho;
         else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
      }
   }
}


// Eliminar un elemento de un árbol ABB
void ArbolABB::BorrarPorId(const int dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->dato.IdCentro) { // Si el valor está en el nodo actual
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
            aux = actual->dato.IdCentro;
            actual->dato.IdCentro = nodo->dato.IdCentro;
            nodo->dato.IdCentro = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->dato.IdCentro) actual = actual->derecho;
         else if(dat < actual->dato.IdCentro) actual = actual->izquierdo;
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
   func(nodo->dato.IdCentro);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
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

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
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

// Buscar un valor en el árbol
bool ArbolABB::Buscar(const CentroClasificacion dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.IdCentro == actual->dato.IdCentro) return true; // int encontrado
      else if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho; // Seguir
      else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Buscar un valor en el árbol
bool ArbolABB::BuscarPorId(const int dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato.IdCentro) return true; // int encontrado
      else if(dat > actual->dato.IdCentro) actual = actual->derecho; // Seguir
      else if(dat < actual->dato.IdCentro) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}


// Buscar por id en el arbol y devolver el centro de clasificación.
CentroClasificacion ArbolABB::BuscarPorIdRecuperarCC(const int dat)
{
   actual = raiz;
   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato.IdCentro) return actual->dato; // int encontrado
      else if(dat > actual->dato.IdCentro) actual = actual->derecho; // Seguir
      else if(dat < actual->dato.IdCentro) actual = actual->izquierdo;
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
      if(dat.IdCentro == actual->dato.IdCentro) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat.IdCentro > actual->dato.IdCentro) actual = actual->derecho;
         else if(dat.IdCentro < actual->dato.IdCentro) actual = actual->izquierdo;
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

void simulacionCreacionCajas(int numSimulaciones, ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros,Pila* pilaDeCajas ){
    for (int i=0; i< numSimulaciones; i++){
        Caja nuevaCaja;
        do{
            nuevaCaja.CentroRef=randomCentros ();
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




void printDatosPilaCajas(Pila* pilaDeCajas){


cout << "----------------------------------------------------------------------" << endl;
cout << "|" << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(12) << "ID centro |"
     << setw(16) << "Contenido |"
     << setw(14) << "Fecha cons |"
     << setw(4) << "Dia |" << endl;
cout << "----------------------------------------------------------------------" << endl;
for (int i=0; i < N2; i++) {
    if (pilaDeCajas->vacia()) {
        cout << "|" << setw(10) << "--- |"
                    << setw(12) << "--- |"
                    << setw(14) << "--- |"
                    << setw(14) << "--- |"
                    << setw(14) << "--- |"
                    << setw(14) << "--- |" << endl;
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

