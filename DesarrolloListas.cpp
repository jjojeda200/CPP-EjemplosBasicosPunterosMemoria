/*
José Juan Ojeda Granados, 06-12-2021
Practica avanzada de manejo de listas, punteros a memoria stack y heap
*/
#include <iostream>
//#include <string.h>
#define NC "\e[0m"
#define Amarillo "\e[0;33m"
#define Azul "\e[0;34m"
#define Blanco "\e[0;37m"
using std::cin;
using std::cout;
using std::endl;
using std::string;
// using namespace std;

struct Nodo // Declaración de la estructura de tipo de dato creado
{
    // Sub Datos que componen el dato "Nodo"
    int Dato = 0;              // Primer tipo de sub dato
    string Elemento;           // Segundo tipo de sub dato
    Nodo *Siguiente = nullptr; // Variable para almacenar el apuntador al siguiente "Nodo"
};

// Definición de dos apuntadores padres (redundancia voluntaria) al primer "Nodo"
struct Nodo *listaElementos = nullptr; // NULL = 0x00000000
struct Nodo *listaA = nullptr;         // NULL = 0x00000000

// Para evitar los problemas de orden de declaración...
// en este caso de las funciones
void MenuManejoNodos();

void MostrarNodos(bool menuSiNo)
{
    struct Nodo *itemI = listaElementos;

    int num = 0;

    cout << endl
         << "\tLista Elementos:" << endl
         << endl;
    cout << "Nodo  Nº Dato\t Elemento\t Dir. Mem.\t Dir. Mem. siguiente";
    for (int i = 1; itemI != nullptr; i++)
    {
        cout << endl
             << NC << "Nodo: " << Blanco << i << "\t  " << itemI->Dato
             << "\t" << itemI->Elemento << "\t" << itemI << "\t" << itemI->Siguiente;

        itemI = itemI->Siguiente;
        num = i; // Número de elementos, tantos como veces se recorre el bucle i
    }
    cout << NC << "\n\n\tTotal Elementos: " << Blanco << num << NC << endl;

    if (menuSiNo)
        MenuManejoNodos();
}

void AnadirNodo(string ElementoNuevo, int DatoNuevo, int Posicion)
{
    struct Nodo *itemI = new Nodo; // struct que almacena los nuevos datos a incorporar
    struct Nodo *itemII;           // struct para navegar entre los datos ya grabados

    itemI->Dato = DatoNuevo;
    itemI->Elemento = ElementoNuevo;
    itemI->Siguiente = nullptr;

    if (listaElementos == nullptr) // Si listaElemento es null, no existe ningún Nodo
    {
        listaElementos = itemI; // Entonces los nuevos datos se añaden como primer Nodo
        listaA = listaElementos;
    }
    else
    {
        itemII = listaElementos; // Adopta el valor del padre

        if (Posicion ==
            1)
        {                                      // Guardamos la dirección del primer Nodo apuntado por listaElementos
            itemI->Siguiente = listaElementos; // Hacemos que el nuevo nodo apunte al anterior primer Nodo
            listaElementos = itemI;
            listaA = listaElementos;
        }
        else
        {
            bool anadido = false; // Falso mientras no se añada el nuevo Nodo
            while (!anadido)
            {
                if (itemII->Siguiente == nullptr) // Si el Nodo es el ultimo
                {
                    itemII->Siguiente = itemI; // Añadimos
                    anadido = true;            // True, se añadío el nuevo Nodo al final
                }
                else
                    itemII = itemII->Siguiente; // Si no es el ultimo avanzamos al siguiente Nodo
            }
        }
    }
    // liberar la memoria utilizada
    itemI = nullptr;
    delete itemI;
    itemII = nullptr;
    delete itemII;
}

//********************************************************************************
void AnadirNodoSimple()
{
    string ElementoNuevo;
    int DatoNuevo;
    char Aux = 'N';
    int Posicion = 0;

    MostrarNodos(false);

    cout << endl
         << "Nombre del Elemento a añadir:\t" << Blanco;
    cin >> ElementoNuevo;
    cout << NC << "Indica la cantidad para Dato:\t" << Blanco;
    cin >> DatoNuevo;

    // Rutina para rellenar de espacios hasta completar una longitud requerida
    int longitud;
    longitud = ElementoNuevo.length();
    for (int i = longitud; i < 10; i++)
        ElementoNuevo += " ";
    if (listaElementos != nullptr)
    {
        cout << NC << "Teclea s/S si quieres insertarlo al principio:\t" << Blanco;
        cin >> Aux;
        if (Aux == 'S' || Aux == 's')
            Posicion = 1;
    }
    AnadirNodo(ElementoNuevo, DatoNuevo, Posicion);
    cout << NC << "Nodo añadido" << endl;

    MenuManejoNodos();
}

//********************************************************************************
void EliminaNodo()
{
    struct Nodo *itemI;   // struct auxiliar para borrar Nodo
    struct Nodo *itemAux; // struct auxiliar para borrar Nodo

    int NodoBorrar;
    int Aux;
    // int Posicion;

    if (listaElementos == nullptr) // Si listaElemento es null, no existe ningún Nodo
    {
        cout << Blanco << "\n No existe ningún nodo, ¡Que quieres borrar!" << NC << endl;
        MenuManejoNodos();
    }
    else
    {
        MostrarNodos(false);
        cout << NC << "\n Indica el número de nodo a borrar:\t" << Blanco;
        cin >> NodoBorrar;
        cout << NC << endl;

        itemI = listaElementos;
        itemAux = listaElementos;
        Aux = 1;

        if (NodoBorrar == Aux)
        {
            listaElementos = listaElementos->Siguiente;
            MostrarNodos(false);
        }
        else
        {
            while (Aux != NodoBorrar && itemI->Siguiente != nullptr)
            {
                // Recorrido en carrusel para comprobar movimiento de las variables apuntadoras uxiliares
                cout << "*****************************************************" << endl;
                cout << Amarillo << itemI << "\t" << itemI->Siguiente << "\t" << itemI->Siguiente->Siguiente << NC
                     << endl;
                cout << Azul << itemAux << "\t" << itemAux->Siguiente << "\t" << itemAux->Siguiente->Siguiente << NC
                     << endl;
                itemAux = itemI;
                itemI = itemI->Siguiente;

                Aux++;
            }
            if (itemI->Siguiente == nullptr)
            {
                cout << Blanco << "\n El número indicado de nodo a borrar no existe\t" << NC << endl;
            }
            else
            {
                cout << "*****************************************************" << endl;
                cout << Amarillo << itemI << "\t" << itemI->Siguiente << "\t" << itemI->Siguiente->Siguiente << NC
                     << endl;
                cout << Azul << itemAux << "\t" << itemAux->Siguiente << "\t" << itemAux->Siguiente->Siguiente << NC
                     << endl;
                itemAux->Siguiente = itemAux->Siguiente->Siguiente;
                cout << Blanco << itemAux << "\t" << itemAux->Siguiente << "\t" << itemAux->Siguiente->Siguiente << NC
                     << endl;
            }
        }
    }

    // liberar la memoria utilizada
    itemI = nullptr;
    delete itemI;
    itemAux = nullptr;
    delete itemAux;

    MenuManejoNodos();
}

//********************************************************************************
void CarruselNodo()
{
    struct Nodo *itemI; // struct auxiliar para navegar por los Nodos

    if (listaElementos != nullptr)
    {
        itemI = listaElementos;
        cout << "*****************************************************" << endl;

        while (itemI->Siguiente->Siguiente != nullptr)
        {
            cout << Amarillo << itemI << "\t" << itemI->Siguiente << "\t" << itemI->Siguiente->Siguiente << NC << endl;
            itemI = itemI->Siguiente;
        }
    }
    else
    {
        cout << Azul << "\n Puntero padre a NULL! (lista vacía)" << NC << endl;
        cout << "\n**************************************************" << endl;
    }

    // liberar la memoria utilizada
    itemI = nullptr;
    delete itemI;

    MenuManejoNodos();
}

//********************************************************************************
void CreaNodosDefecto()
{
    // Metodo usando la función insertElementList
    AnadirNodo("Elemento-10", 10, false);
    AnadirNodo("Elemento-20", 20, false);
    AnadirNodo("Elemento-30", 30, false);

    cout << endl
         << Blanco << "Lista de Nodos por defecto añadidos" << NC << endl;

    MenuManejoNodos();
    /*  // crear un solo nodo al principio para pruebas
        Nodo *nuevo = new Nodo;
        nuevo->Dato = 10;
        nuevo->Elemento = "Elemento-10";
        nuevo->Siguiente = nullptr;
        listaA = nuevo;
        listaElementos = nuevo;

        nuevo = nullptr;
        delete nuevo;
        MenuManejoNodos();
    */
}

//********************************************************************************
void ImprimeNodoVariables()
{
    if (listaElementos != nullptr)
    {
        MostrarNodos(false);
    }
    else
    {
        cout << Azul << "\n Puntero padre a NULL! (lista vacía)" << NC << endl;
    }
    cout << "\n********************************************************************************" << endl;
    cout << "Variable padre listaElementos almacenando la dirección NULL o al primer nodo" << endl;
    cout << "Variable padre listaA redundante de listaElementos:" << endl;
    cout << "Contenido variable listaElementos:\t\t\t" << Blanco << listaElementos << NC << endl;
    cout << "Dirección de memoria de &listaElementos (stack):\t" << Azul << &listaElementos << NC << endl;
    cout << "Contenido variable listaA:\t\t\t\t" << Blanco << listaA << NC << endl;
    cout << "Dirección de memoria de &listaA (stack):\t\t" << Azul << &listaA << NC << endl;

    cout << endl;

    MenuManejoNodos();
}

//********************************************************************************
void MenuManejoNodos()
{
    int opcion;
    do
    {
        cout << endl
             << "Gestionar lista Nodos (Elementos):" << endl;
        cout << "1 - Mostrar lista de Nodos." << endl;
        cout << "2 - Añadir un Nodo." << endl;
        cout << "3 - Elimina un Nodo." << endl;
        cout << "4 - Carrusel punteros de Nodos." << endl;
        cout << "5 - Crear lista de Nodos por defecto." << endl;
        cout << "6 - Menú Impresión variables." << endl
             << endl;
        cout << "9 - Salir." << endl
             << endl;
        cout << "Teclea opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            MostrarNodos(true);
            break;
        case 2:
            AnadirNodoSimple();
            break;
        case 3:
            EliminaNodo();
            break;
        case 4:
            CarruselNodo();
            break;
        case 5:
            CreaNodosDefecto();
            break;
        case 6:
            ImprimeNodoVariables();
            break;
        case 9:
            break;
        default:
            cout << "La opción no es válida.\n";
        }
    } while (opcion < 1 || opcion > 9);
}

int main()
{
    system("clear");
    MenuManejoNodos();
    return 0;
}
