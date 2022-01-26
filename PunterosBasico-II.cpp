/*
José Juan Ojeda Granados, 04-12-2021
Práctica básica II de manejo de punteros a memoria
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

struct Nodo // Declaración de la estructura de tipo de dato creado
{
  // SubDatos que componen el dato "Nodo"
  int Dato;        // Primer tipo de subdato
//  string Elemento; // Segundo tipo de subdato
  Nodo *Siguiente; // Variable para almacenar el apuntador al siguiente "Nodo"
};

struct Nodo *listaA = nullptr;

int main()
{
  system("clear");

  cout << "\tManejo básico de punteros a zonas de memoria II\n";
  cout << "Declaramos un struct de datos (Global) llamado Nodo, compuesto por:" << endl;
  cout << "un entero, un string y un puntero al siguiente Nodo, en este ejemplo." << endl;

  cout << "El struct en Global\t" << Azul << "struct Nodo {}" << NC << endl;
  cout << "Entre los corchetes añadimos los componentes" << endl;
  cout << "El entero Dato\t\t" << Azul << "int Dato;" << NC << endl;
//  cout << "La cadena Elemento\t" << Azul << "string Elemento;" << NC << endl;
  cout << "El puntero *Siguiente\t" << Azul << "Nodo *Siguiente;" << NC << endl;
  cout << "\n********************************************************************************" << endl;

  cout << "Declaramos una variable puntero padre en Global \"listaA\" que apuntara a la zona" << endl;
  cout << "de memoria del primer Nodo (cuando exista) y se inicializa a NULL con:\n\t\t\t";
  cout << Azul << "struct Nodo *listaA = nullptr;" << NC << endl;

  cout << "\n********************************************************************************" << endl;
  cout << "Creamos un Nodo para poder analizar el manejo de los distintos apuntadores" << endl;
  cout << "con la instrucción:\n\t\t\t" << Azul << "Nodo *Nuevo = new Nodo;" << NC << endl;
  Nodo *Nuevo = new Nodo;
  cout << "Añadimos 100 a (*Nuevo).Dato\n\t\t\t" << Azul << "Nuevo->Dato = 100;" << NC << endl;
  Nuevo->Dato = 100;
//  cout << "Añadimos Elemento100 a (*Nuevo).Elemento\n\t\t\t" << Azul << "Nuevo->Elemento = Elemento100;" << NC << endl;
//  Nuevo->Elemento = "Elemento100";
  cout << "Colocamos el apuntador (*Nuevo).Siguiente a NULL\n\t\t\t" << Azul << "Nuevo->Siguiente = nullptr;" << NC << endl;
  Nuevo->Siguiente = nullptr;
  cout << "El apuntador (*Nuevo).Siguiente apuntaria a la dirección del siguiente Nodo" << NC << endl;

  cout << "\n********************************************************************************" << endl;
  //  int *DatoNuevo = &Nuevo->Dato;
  //  *DatoNuevo = 200;
  cout << "Contenido de Nuevo->Dato: \t" << Blanco << Nuevo->Dato << NC << endl;
  cout << "Dirección de &Nuevo->Dato: \t" << Blanco << &Nuevo->Dato << NC << endl;
  //  cout << "Dirección de DatoNuevo: \t" << Blanco << *DatoNuevo << NC << endl;

  cout << "\n********************************************************************************" << endl;
  //  cout << "Contenido de Nuevo->Elemento: \t" << Blanco << Nuevo->Elemento << NC << endl;
  //  cout << "Dirección de &Nuevo->Elemento: \t" << Blanco << &Nuevo->Elemento << NC << endl;
  cout << "Contenido de Nuevo->Siguiente: \t" << Blanco << Nuevo->Siguiente << NC << endl;
  cout << "Dirección de &Nuevo->Siguiente: " << Blanco << &Nuevo->Siguiente << NC << endl;

  cout << "\n********************************************************************************" << endl;
  cout << "Contenido de *Nuevo: \t\t" << Blanco << Nuevo << NC << endl;
  cout << "Dirección de &nuevo: \t\t" << Blanco << &Nuevo << NC << endl;

  cout << "\n********************************************************************************" << endl;
  cout << "Asignamos la dirección del nuevo Nodo a listaA para poder acceder a el\n\t\t\t" << Azul << "listaA = Nuevo;" << NC << endl;
  listaA = Nuevo;
  cout << "Contenido de *listaA: \t\t" << Blanco << listaA << NC << endl;
  cout << "Dirección de &listaA: \t\t" << Blanco << &listaA << NC << endl;

  delete Nuevo;

  return 0;
}
