/***************************************************************************************
    José Juan Ojeda Granados
    Fecha:        10-10-2022
    Titulo:       00ViewMem.hpp
    Descripción:  Análisis de uso de la memoria visualizando zonas usando punteros

    Referencias:
    https://es.cppreference.com/w/cpp/container/array
    https://es.cppreference.com/w/cpp/container/vector
    https://en.cppreference.com/w/c/io/fprintf

***************************************************************************************/
#include <iostream>
using namespace std;

void imprime(int x)
{
      printf("Imprimiendo un número: %d\n", x);
}

int addition(int a, int b)
{
      printf("Función de suma\n");
      return (a + b);
}

int subtraction(int a, int b)
{
      printf("Función de resta\n");
      return (a - b);
}

int operation(int x, int y, int (*functocall)(int, int))
{
      int g;
      g = (*functocall)(x, y);
      return (g);
}


int main()
{
      system("clear");
      void (*ptr_funct)(int) = imprime;
      printf("La dirección de ptr_funct es %p\n", ptr_funct);
      ptr_funct(8);     // Llama a imprime

      int m, n;
      int (*minus)(int, int) = subtraction;

      m = operation(6, 12, addition);
      n = operation(20, m, minus);
      printf("Resultado de ejecutar las funciones = %d \n", n);

      return 0;
}