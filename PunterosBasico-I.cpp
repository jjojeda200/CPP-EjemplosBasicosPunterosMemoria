/*
     José Juan Ojeda Granados, 04-12-2021
     Práctica básica I de manejo de punteros de memoria
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

struct Nodo // Declaración de una estructura de tipo de dato llamada Nodo
{
     // SubDatos que componen el dato "Nodo"
     int Dato;        // Primer tipo de subdato
     string Elemento; // Segundo tipo de subdato
     Nodo *Siguiente; // Variable para almacenar el apuntador al siguiente "Nodo"
};

struct Nodo *listaA = nullptr;

int main()
{
     system("clear");

     string *varA = nullptr;
     cout << "\tManejo básico de punteros a zonas de memoria I\n";
     cout << "Declaramos una variable puntero string varA que apuntara a una zona" << endl;
     cout << "de memoria y se inicializa a NULL con: " << Azul << "string *varA = nullptr" << NC << endl;

     cout << "Mostramos el contenido de varA, que debe ser NULL (0):" << endl;
     cout << "\t" << Blanco << varA << NC << endl;
     cout << "Mostramos la dirección de memoria (stack) que guarda varA con: " << Azul << "&varA" << NC << endl;
     cout << "\t" << Blanco << &varA << NC << endl;
     cout << "\n********************************************************************************" << endl;
     string varB = "Contenido inicial :-)";
     cout << "Declaramos un string varB y almacenamos la cadena " << Blanco << varB << NC << endl;

     cout << "Mostramos la dirección de la memoria en que se guardo varB con: " << Azul << "&varB" << NC << endl;
     cout << "\t" << Blanco << &varB << NC << endl;
     cout << "\n********************************************************************************" << endl;
     cout << "Hacemos que varA deje de apuntar a NULL y que hora apunte a la dirección" << endl;
     cout << "de memoria donde se almacena valB con: " Azul "varA = &varB " NC "y mostramos varA" << endl;
     varA = &varB;
     cout << "\t" << Blanco << varA << NC << endl;
     cout << "\n********************************************************************************" << endl;
     // Dereferenciar es trabajar con el dato al que apunta un puntero *
     cout << "Modificamos el contenido de varB escribiendo directamente en la zona de memoria" << endl;
     cout << "que lo almacena, usando *varA con: " Azul "*varA = \"contenido nuevo ;-)\" " NC << endl
          << endl;
     cout << "\n********************************************************************************" << endl;
     cout << "El contenido inicial de varB:\t" << Blanco << varB << NC << endl;
     *varA = "Contenido nuevo ;-)";
     cout << "El contenido posterior de varB:\t" << Blanco << varB << NC << endl
          << endl;

     string *varC;
     varC = &varB;

     cout << "Dos punteros \"varA y varC\" a la misma zona de memoria de varB" << endl;
     cout << "El contenido de varA:\t" << Blanco << varA << NC << endl;
     cout << "El contenido de varC:\t" << Blanco << varC << NC << endl;

     cout << "\n********************************************************************************" << endl;

     cout << endl
          << endl;

     return 0;
}
