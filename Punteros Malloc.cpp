/***************************************************************************************
    José Juan Ojeda Granados
    Fecha:          24-08-2022
    Titulo:         C++ Templates, No sé cómo funcionan
    Descripción:    Biblioteca de gestión de memoria estilo C
    Referencias:    https://es.cppreference.com/w/cpp/memory/c

    Dependencias:

    Compilar:

    Licencia:       Licencia Atribución de Creative Commons (reutilización permitida)

***************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
int main(){
    int *ptr;
    ptr = (int*)std::malloc(2*sizeof(int));     // Reserva para dos enteros (4 Bytes)
    printf("Dirección de ptr %p\n",&ptr);  // Dirección de memoria de ptr
    printf("Dirección almacenada en ptr %p\n",ptr);   // Primera dirección reservada
    // Desde la posición 2 se está accediendo fuera de la reserva, ¿¡comportamiento indefinido!?)
    *(ptr+4) = 10;

    int i = 0;
    while (i < 5)
    {
        printf("i = %d, contenido %d\t",i, ptr[i]); // Imprimir valores de la memoria
        printf("Dirección %p\n",&ptr[i]);           // Imprimir dirección de memoria
        i++;
    }

    std::free(ptr);     // Fundamental liberar la memoria
}