/*
    José Juan Ojeda Granados, 10-01-2022
    Repaso punteros memoria

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria 
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

*/
#include <iostream>


int main(int argc, char *argv[])
{
    system("clear");

    printf("\t\e[0;33mMemoria Stack\e[0m\n");
    printf("\e[0;34mSe crea la variable puntero *punA y se guarda a null\e[0m\n");
    int *punA = nullptr;
    printf("*punA\t%p\n", punA);
    printf("\e[0;34mSe crea la variable varA y se almacena el valor 20\e[0m\n");
    int varA = 20;
    printf("varA\t%d\n", varA);
    printf("\e[0;34mSe almacena en punA la dirección de memoria que el sistema asigno a varA\e[0m\n");
    punA = &varA;
    printf("\e[0;34mMostramos la dirección de memoria de varA y su contenido\e[0m\n");
    printf("punA\t%p\n", punA);
    printf("*punA\t%d\n", *punA);

    printf("\n\t\e[0;33mMemoria Heap\e[0m\n");
    printf("\e[0;34mSe crea *punB y se devuelve la dirección de memoria heap asignada en él\e[0m\n");
    int *punB = new int;
    printf("*punB\t%p\n", punB);
    printf("\e[0;34mPor desreferencia se almacena en esa dirección de memoria el valor 40\e[0m\n");
    *punB = 40;
    printf("\e[0;34mMostramos nuevamente la dirección de memoria y su contenido\e[0m\n");
    printf("punB\t%p\n", punB);
    printf("*punB\t%d\n", *punB);

    printf("\e[0;34mSe borra el contenido del puntero y el puntero con delete\e[0m\n\n");
    punB = nullptr;
    delete punB;

    return 0;
}