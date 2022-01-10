/*
    José Juan Ojeda Granados, 10-01-2022
    Repaso pasando parámetros a funciones por medio de punteros memoria

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria 
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

    Compilar con -lstdc++
    gcc Repa02.cpp -o Repa02 -lstdc++
*/
#include <iostream>

void funsionPunteros(int *punA, int *punB)
{
    printf("\e[0;33mFunción Punteros\e[0m\n");
    printf("\e[0;34mSumamos 10 a cada variable\e[0m\n");
    printf("*punA\t%p\n", punA);
    *punA = *punA + 10;
    printf("*punB\t%p\n", punB);
    *punB = *punB + 10;
    printf("punA\t%d\n", *punA);
    printf("punB\t%d\n", *punB);

    printf("\e[0;34mpunA y punB son variables locales de la función\e[0m\n");

    // return;
}

int main(int argc, char *argv[])
{
    system("clear");
    printf("\e[0;33mFunción Main\e[0m\n");

    printf("\e[0;34mSe crean varA y varB y se almacena los valores 20 y 40 respectivamente\e[0m\n");
    int varA = 20;
    int varB = 40;
    printf("varA =\t%d\n", varA);
    printf("varB =\t%d\n", varB);

    int *punA = nullptr;
    int *punB = nullptr;
    printf("*punA = nullptr\t%p\n", punA);
    printf("*punB = nullptr\t%p\n", punB);

    printf("\e[0;34mSe llama a la función Punteros pasando las direcciones de memoria de varA y varB\e[0m\n");
    funsionPunteros(&varA, &varB);

    printf("\e[0;33mContinua Función Main\e[0m\n");
    printf("\e[0;34mSe muestra el nuevo valor de varA y varB modificados por la función\e[0m\n");
    printf("varA\t%d\n", varA);
    printf("varB\t%d\n", varB);
    printf("*punA = nullptr\t%p\n", punA);
    printf("*punB = nullptr\t%p\n", punB);

    return 0;
}