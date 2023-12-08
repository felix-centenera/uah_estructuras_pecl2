//
#include "pecl2.h"

using namespace std;

int main(){
    //Creamos una lista de tipo RegistroDeCentros.
    //ListaRegistroCentros *lista= new ListaRegistroCentros();
    ListaRegistroCentros *listaCentros= new ListaRegistroCentros();
    ArbolABB *arbolDeCentros= new ArbolABB();
    Pila *pilaDeCajas = new Pila();

    cout << "Creado el ABB con los siguientes 10 nodos:\n" << endl;
    simulacionCentroDeControl(N1, listaCentros, arbolDeCentros);


    listaCentros->imprimirDatosMedianteRegistoDeLista(arbolDeCentros);
    //estadoCentrosArbol(arbolDeCentros);



    cout << "Creando las siguientes cajas nuevas:\n" << endl;
    //simulacionCreacionCajas(int numSimulaciones, ArbolABB *arbolDeCentros, ListaRegistroCentros *listaCentros,Pila* cajas )
    simulacionCreacionCajas(N2,arbolDeCentros,listaCentros,pilaDeCajas);

    Pila *pilaDeCajasCopia = copiarPila(pilaDeCajas);
    pilaDeCajas = invertirPila(pilaDeCajas);
    pilaDeCajasCopia = invertirPila(pilaDeCajasCopia);

    printDatosPilaCajas(pilaDeCajasCopia);

      /*
    CentroClasificacion centro1;
    centro1.CentroRef="mi primer centro";
    centro1.IdCentro=10;
    CentroClasificacion centro2;
    centro2.CentroRef="mi segundo centro";
    centro2.IdCentro=12;

    CentroClasificacion centro3;
    centro3.CentroRef="mi tercer centro";
    centro3.IdCentro=13;

    CentroClasificacion centro4;
    centro4.CentroRef="mi cuarto centro";
    centro4.IdCentro=9;

    ArbolABB ArbolInt;

    ArbolInt.Insertar(centro1);
    ArbolInt.Insertar(centro2);
    ArbolInt.Insertar(centro3);
    ArbolInt.Insertar(centro4);

      // Veamos algunos parámetros
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura de 10 " << ArbolInt.Altura(centro1) << endl;
   cout << "Altura de  12 " << ArbolInt.Altura(centro2) << endl;
   cout << "Altura de  13 " << ArbolInt.Altura(centro3) << endl;
   cout << "Altura de  9 " << ArbolInt.Altura(centro4) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   cout << "Raiz " << ArbolInt.VerRaiz().CentroRef << endl;
   cout << "Raiz " << ArbolInt.VerRaiz().IdCentro << endl;
   //cout << "Raiz " << ArbolInt.VerRaiz().listaDeCajas.actual.Nodo << endl;
   cout << endl;


   // Mostrar el árbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   if (ArbolInt.BuscarPorId(13)) {
        cout << "esta el nodo de id 13" << endl;
   }

    if (ArbolInt.BuscarPorId(15)) {
        cout << "esta el nodo de id 15" << endl;
   }
   else {
        cout << "NO esta el nodo de id 15" << endl;
   }


    // Borraremos algunos elementos:
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   ArbolInt.Borrar(centro4);
   cout << "Borrar   4: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(centro1);
   cout << "Borrar   1: ";
   ArbolInt.InOrden(Mostrar);
    cout << endl;

    cout << "Raiz " << ArbolInt.VerRaiz().IdCentro << endl;


    RegistroCentros prueba;
    prueba.CentroRef="holamundo";
    prueba.IdCentro=111;

    RegistroCentros prueba2;
    prueba2.CentroRef="holamundo2";
    prueba2.IdCentro=222;

    ListaRegistroCentros *lista= new ListaRegistroCentros();
    lista->insertarNodo(prueba);
    lista->insertarNodo(prueba2);
    lista->recorrerLista();
    cout << "Lista de elementos:" << endl;
    lista->esCabeza();

    while(lista->esActual())
    {
        //cout << lista.valorActual() << endl;
        cout << lista->valorActual().CentroRef << lista->valorActual().IdCentro << endl;
        lista->esSiguiente();
    }
        lista->esCabeza();
        cout << "Primero: " << lista->valorActual().CentroRef << lista->valorActual().IdCentro << endl;
        lista->esFinal();
        cout << "Ultimo: " << lista->valorActual().CentroRef << lista->valorActual().IdCentro << endl;
        lista->borrarNodoPorRegistroID(111);
        //lista.borrarNodo(prueba);
        //lista.borrarNodo(15);
        //lista.borrarNodo(45);
        //lista.borrarNodo(30);
        //lista.borrarNodo(40);
        lista->recorrerLista();

    */

    /*
    RegistroCentros prueba;
    prueba.CentroRef="holamundo";
    prueba.IdCentro=111;

    RegistroCentros prueba2;
    prueba2.CentroRef="holamundo2";
    prueba2.IdCentro=222;

    ListaRegistroCentros lista;
    lista.insertarNodo(prueba);
    lista.insertarNodo(prueba2);
    lista.recorrerLista();
    cout << "Lista de elementos:" << endl;
    lista.esCabeza();

    while(lista.esActual())
    {
        //cout << lista.valorActual() << endl;
        cout << lista.valorActual().CentroRef << lista.valorActual().IdCentro << endl;
        lista.esSiguiente();
    }
        lista.esCabeza();
        cout << "Primero: " << lista.valorActual().CentroRef << lista.valorActual().IdCentro << endl;
        lista.esFinal();
        cout << "Ultimo: " << lista.valorActual().CentroRef << lista.valorActual().IdCentro << endl;
        lista.borrarNodoPorRegistroID(111);
        //lista.borrarNodo(prueba);
        //lista.borrarNodo(15);
        //lista.borrarNodo(45);
        //lista.borrarNodo(30);
        //lista.borrarNodo(40);
        lista.recorrerLista();

    */
    return 0;
}
