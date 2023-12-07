//
#include "pecl2.h"

using namespace std;

int main(){
    //Creamos una lista de tipo RegistroDeCentros.
    ListaRegistroCentros *lista= new ListaRegistroCentros();

    cout << "Creado el ABB con los siguientes 10 nodos:\n" << endl;

    cout << "Creando las siguientes cajas nuevas:\n" << endl;


    /*
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
