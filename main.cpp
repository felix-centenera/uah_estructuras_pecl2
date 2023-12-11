//
#include "pecl2.h"

using namespace std;

int main(){
    //Semilla para random data.
    srand(time(NULL));
    //Opcion por defecto al menu.
    int opcion=0;
    //Se crea una lista que registra los nodos (Estos nodos no tienen las cajas, solo la estadística, id y nombre del centro).
    ListaRegistroCentros *listaCentros= new ListaRegistroCentros();
    // Se crea un arbol donde se registran los nodos. Estos nodos sí tienen las cajas.
    ArbolABB *arbolDeCentros= new ArbolABB();
    // Se crea una pila para acumular las cajas que se crean.
    Pila *pilaDeCajas = new Pila();
    // Se crea una estructura estadistica total, que guarda el acumulado de las estaditicas, cada centro tiene su estructura particular.
    Estadistica *estadisticaTotal=new Estadistica();

    cout << "Creado el ABB con los siguientes 10 nodos:\n" << endl;
    // Creación de Centros, y registro de los mismo en la lista de centros y arbol de centros.
    simulacionCentroDeControl(N1, listaCentros, arbolDeCentros);
    // impresion de centros, se utiliza la lista de centros registrados para sacar los id y recorrer el arbol.
    listaCentros->imprimirDatosMedianteRegistoDeLista(arbolDeCentros);

    cout << "Creando las siguientes cajas nuevas:\n" << endl;
    // Creacion de cajas, las lista de centros se utiliza para obtener un id de centro, con el arbol verificamos  que existe el centro con el ID, y la apilamos en una pila, a la espera de ser repartidas.
    simulacionCreacionCajas(N2,arbolDeCentros,listaCentros,pilaDeCajas);

    // Creamos una pila en la que copiar, se utiliza para la impresion, debe ser invertida si queremos conservar el orden de cración.
    Pila *pilaDeCajasCopia = copiarPila(pilaDeCajas);
    pilaDeCajas = invertirPila(pilaDeCajas);
    pilaDeCajasCopia = invertirPila(pilaDeCajasCopia);
    printDatosPilaCajas(pilaDeCajasCopia);

    cout << "Presiona Enter para continuar...\n";
    cin.ignore();  // Espera a que el usuario presione Enter

    cout << "Cajas repartidas. Estado del arbol:\n" << endl;
    // Las cajas son repartidas desde la pila, la lista de centros se utiliza para actualizar la estadistica propia de cada centro, el arbol para insertar las cajas en la lista de los nodos. Estadistica todal registra el total de cajas generadas independientemente del centro.
    repartirCajas(arbolDeCentros,listaCentros, pilaDeCajas,estadisticaTotal);

    // Imprimimos el estado del arbol con las cajas que han recogido. La lista de centros se utiliza para recorrer el arbol. Podria optarse por hacer un recorrido inorden,preorden o postorden, recoger los id en otra estructura, y recorrer el arbol, pero teniendo un listado, no tendria mucho sentido.
    listaCentros->imprimirDatosMedianteRegistoDeLista(arbolDeCentros);

    cout << "Listado de intentificadores de CC creados: ";
    arbolDeCentros->InOrden(Mostrar);
    cout << "\n" << endl;

    cout << "**************************************************" << endl;
    cout << "*             BIENVENIDO AL SERVICIO             *" << endl;
    cout << "*               DE AYUDA HUMANITARIA             *" << endl;
    cout << "**************************************************" << endl;

    //Entramos en fase menu. Opcion 10 no se muestra al usuario, se deja para debug.
    do {
        printMenu(opcion);
        switch (opcion) {
            case 1:
                cin.ignore();
                cout << "Opcion1" << endl;
                crearCCmanual(listaCentros,arbolDeCentros);
                break;
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
                    buscarCajaPorIDyBorrar(listaCentros,arbolDeCentros);
                    break;
            case 6:
                    cout << "Opcion6" << endl;
                    buscarCajaPorIDyMoverlaCC(listaCentros, arbolDeCentros);
                    break;
            case 7:
                    cout << "Opcion7" << endl;
                    //void ListaRegistroCentros::imprimirDatosEstadisticaMedianteRegistoDeLista(ArbolABB *arbolDeCentros)
                    //cout << "BUG" << endl;
                    listaCentros->imprimirDatosEstadisticaMedianteRegistoDeLista(arbolDeCentros,estadisticaTotal);
                    break;
            case 8:
                    cout << "Opcion8" << endl;
                    simulacionCreacionCajas(N2,arbolDeCentros,listaCentros,pilaDeCajas);
                    pilaDeCajasCopia = copiarPila(pilaDeCajas);
                    pilaDeCajas = invertirPila(pilaDeCajas);
                    pilaDeCajasCopia = invertirPila(pilaDeCajasCopia);
                    printDatosPilaCajas(pilaDeCajasCopia);
                    repartirCajas(arbolDeCentros,listaCentros, pilaDeCajas,estadisticaTotal );
                    break;
            case 10:
                    cout << "Opcion10" << endl;
                    listaCentros->imprimirDatosMedianteRegistoDeLista(arbolDeCentros);
                    //cout << listaCentros->randomIDCentro() << endl;
                    break;
            case 0:
                    cout << "Nos vemos. ;) " << endl ;
                    break;
            default:
                    cout << "La opcion no estaba en el menu" << endl;
                    break;
            }
        } while(opcion!=0);


    cout << "Gracias por usar la simulación:\n" << endl;

    return 0;
}
