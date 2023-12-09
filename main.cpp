//
#include "pecl2.h"

using namespace std;

int main(){
    int opcion=0;
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
    simulacionCreacionCajas(N2,arbolDeCentros,listaCentros,pilaDeCajas);

    Pila *pilaDeCajasCopia = copiarPila(pilaDeCajas);
    pilaDeCajas = invertirPila(pilaDeCajas);
    pilaDeCajasCopia = invertirPila(pilaDeCajasCopia);
    printDatosPilaCajas(pilaDeCajasCopia);

    cout << "Presiona Enter para continuar...\n";
    cin.ignore();  // Espera a que el usuario presione Enter

    cout << "Cajas repartidas. Estado del arbol:\n" << endl;

    repartirCajas(arbolDeCentros,listaCentros, pilaDeCajas );

    listaCentros->imprimirDatosMedianteRegistoDeLista(arbolDeCentros);

    cout << "Listado de intentificadores de CC creados: ";
    arbolDeCentros->InOrden(Mostrar);
    cout << "\n" << endl;


    do {
        printMenu(opcion);
        switch (opcion) {
            case 1:
                cin.ignore();
                cout << "Opcion1" << endl;
                crearCCmanual(listaCentros,arbolDeCentros);
            case 2:
                cout << "Opcion2" << endl;
                borrarCC(listaCentros, arbolDeCentros);
                break;
            case 3:
                    cout << "Opcion3" << endl;
                    mostrarDatosCC(listaCentros,arbolDeCentros);
                    break;
            case 4:
                    cout << "Opcion4" << endl;
                    buscarCajaPorID(listaCentros,arbolDeCentros);
                    break;
            case 5:
                    cout << "Opcion5" << endl;
                    break;
            case 6:
                    cout << "Opcion6" << endl;
                    break;
            case 7:
                    cout << "Opcion7" << endl;
                    break;
            case 8:
                    cout << "Opcion8" << endl;
                    listaCentros->imprimirDatosMedianteRegistoDeLista(arbolDeCentros);
                    break;
            case 0:
                    cout << "Nos vemos. ;) " << endl ;
                    break;
            default:
                    cout << "La opcion no estaba en el menu" << endl;
                    break;
            }
        } while(opcion!=0);


    cout << "FIN:\n" << endl;


    /*


    //DEBUG

    //repartir cajas
    //repartirCajas(arbolDeCentros,listaCentros, pilaDeCajas );
    int a=pilaDeCajas->mostrarCima().IdCentro;
    Caja nuevaCaja1;
    nuevaCaja1.CentroRef="hola";
    nuevaCaja1.Contenido="patatas";
    nuevaCaja1.FechaConsumo="mañana";
    nuevaCaja1.FechaRecogida=2;
    nuevaCaja1.Id="asdasd";
    nuevaCaja1.IdCentro=111;

    Caja nuevaCaja2;
    nuevaCaja2.CentroRef="adios";
    nuevaCaja2.Contenido="tomates";
    nuevaCaja2.FechaConsumo="ayer";
    nuevaCaja2.FechaRecogida=3;
    nuevaCaja2.Id="tomya";
    nuevaCaja2.IdCentro=222;

    CentroClasificacion centro;
    centro.CentroRef="probandoCentro";
    centro.IdCentro=111;
    centro.listaDeCajas.insertarNodo(nuevaCaja1);
    centro.listaDeCajas.insertarNodo(nuevaCaja2);
    centro.listaDeCajas.recorrerLista();
    arbolDeCentros->Insertar(centro);
    arbolDeCentros->PreOrden(Mostrar);

    CentroClasificacion centro2=arbolDeCentros->BuscarPorIdRecuperarCC(111);
    //cout << centro2.CentroRef << endl;
    //cout << centro2.IdCentro << endl;
    //cout << centro2.listaDeCajas.numeroDeElementos() << endl;
    centro2.listaDeCajas.recorrerLista();

    cout << "mi ultimo debug" << endl;

    arbolDeCentros->BuscarPorIdRecuperarCC(111).listaDeCajas.recorrerLista();
    cout << arbolDeCentros->BuscarPorIdRecuperarCC(111).listaDeCajas.numeroDeElementos()  << endl;

    //DEBUG
    //arbolDeCentros->BuscarPorIdRecuperarCC(a).listaDeCajas.insertarNodo(pilaDeCajas->desapilar());

/*
    arbolDeCentros->BuscarPorIdRecuperarCC(a).listaDeCajas.recorrerLista();
    if (arbolDeCentros->BuscarPorIdRecuperarCC(a).listaDeCajas.listaVacia()){
        cout << "la lista esta como uno solar" << endl;
    }
    cout << a <<endl;
*/
    //listaCentros->imprimirDatosMedianteRegistoDeLista(arbolDeCentros);

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
