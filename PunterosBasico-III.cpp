/*
José Juan Ojeda Granados, 04-12-2021
Practica básica III de manejo de punteros a memoria
*/
#include <iostream>
#include <stdio.h>
#define NC "\e[0m"
#define Blanco "\e[0;37m"
#define Azul "\e[0;34m"
using namespace std;

/*
Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     & Para mostrar la dirección de memoria de cualquier variable.

El operador flecha (->) se utiliza cuando se dispone de la dirección de un
objeto (en el puntero correspondiente), en lugar del nombre del objeto.
Es más habitual utilizar el operador flecha que el operador punto.
La sintaxis (*puntero).miembro es incómoda de leer y escribir, así que usa la
sintaxis flecha (->) de manera que puntero->miembro es equivalente a (*puntero).miembro.
Ambas opciones son validas pero se aconseja usar el operador flecha (->).
*/

int main()
{
    system("clear");

    cout << "\tManejo básico de punteros a zonas de memoria III" << endl;
    cout << "\tMemoria Stack" << endl << endl;
    int *punA;
    int varA;

    cout << Azul << "¿Valor para la variable varA?\t" << Blanco;
    cin >> varA;

    cout << NC << "Variable varA contiene: \t" << Blanco << varA << NC << endl;
    cout << "Dirección de &varA: \t\t" << Blanco << &varA << NC << endl;
    punA = nullptr;
    cout << "Variable puntero *punA a null: \t" << Blanco << punA << NC << endl;
    cout << "Dirección de &punA: \t\t" << Azul << &punA << NC << endl;
    punA = &varA; // Asignar puntero a la dirección del objeto
    cout << "Almacena punA = &varA: \t\t" << Blanco << punA << NC << endl << endl;

    cout << "Desreferencia punA es recuperar la dirección de memoria de varA" << endl;
    cout << "Cambiamos valor contenido en varA modificando directamente la posición" << endl;
    cout << "de memoria de varA modificando *punA (solicitado por terminal)" << endl << endl;

    cout << Azul << "Ingresa nuevo valor para *punA\t" << Blanco;
    cin >> *punA;

    cout << NC << "Nuevo valor almacenado en varA \t" << Blanco << varA << NC << endl;
    cout << endl;
    cout << "\n********************************************************************************" << endl;
    cout << "\tMemoria Heap" << endl << endl;

    int *punB = new int;
    cout << Azul << "Ingresa un valor para almacenar en *punB\t\t" << Blanco;
    cin >> *punB;
    // *punB = 12;
    int *punC = new int;
    cout << Azul << "Ingresa un valor para almacenar en *punC\t\t" << Blanco;
    cin >> *punC;
    // *punC = 14;

    cout << NC;
    cout << "Dirección a la que apunta punB (int* punB = new int): \t" << Blanco << punB << NC << endl;
    cout << "Dirección a la que apunta punC (int* punC = new int): \t" << Blanco << punC << NC << endl;
    cout << "Dirección de memoria stack de punB: \t\t\t" << Azul << &punB << NC << endl;
    cout << "Dirección de memoria stack de punC: \t\t\t" << Azul << &punC << NC << endl;
    cout << "Valor Almacenado en la dirección apuntada por *punB \t" << Blanco << *punB << NC << endl;
    cout << "Valor Almacenado en la dirección apuntada por *punC \t" << Blanco << *punC << NC << endl;
    cout << endl;

    cout << "Copiando el valor contenido en la dirección de memoria apuntada por punB" << endl;
    cout << "en la dirección de memoria apuntada por punC  (*punC = *punB)\t" << endl;

    *punC = *punB;
    cout << "Valor Almacenado en la dirección apuntada por *punB \t" << Blanco << *punB << NC << endl;
    cout << "Valor Almacenado en la dirección apuntada por *punC \t" << Blanco << *punC << NC << endl;
    cout << endl;

    *punB = 0;
    *punC = 0;
    delete punB;
    delete punC;

    return 0;
}
