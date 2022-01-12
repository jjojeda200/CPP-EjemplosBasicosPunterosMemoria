/*
    José Juan Ojeda Granados, 12-01-2022
    Repaso pasando parámetros a funciones por medio de referencia

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria 
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

    Crear y utilizar Referencias
    Usar el Operador Address-Of (&) en Referencias
    Las Referencias no pueden reasignarse
    Pasar Argumentos a Funciones por Referencia con Punteros y pasar Argumentos a Funciones por Referencia con Referencias.

    Compilar con -lstdc++
    gcc PunterosFunciones00.cpp -o PunterosFunciones00 -lstdc++
*/
#include <iostream>

void funsionPuntero(int *punA, int *punB)
{
    printf("\n\e[0;33mFunción Puntero\e[0m\n");
    printf("\e[0;34mSumamos 10 a la variable\e[0m\n");
    printf("punA:\t%p\n", punA);
    *punA = *punA + 10;
    printf("*punA = *punA + 10\t%d\n", *punA);

    printf("\e[0;34mpunA es variable local de la función\e[0m\n");
    printf("\e[0;34mInicializa con la dirección pasada al llamar a la función\e[0m\n");

    // return; // no necesario al no devolver ningún valor ;-)
}

void funsionReferencia(int *punB)
{
    printf("\e[0;33mFunción Referencia\e[0m\n");
    printf("\e[0;34mSumamos 10 a la variable\e[0m\n");
    printf("punB:\t%p\n", punB);
    *punB = *punB + 10;
    printf("*punB = *punB + 10\t%d\n", *punB);

    printf("\e[0;34mpunB son variables locales de la función\e[0m\n");
    printf("\e[0;34mInicializan con las direcciones pasadas al llamar a la función\e[0m\n");

    // return; // no necesario al no devolver ningún valor ;-)
}

int main(int argc, char *argv[])
{
    system("clear");
    printf("\e[0;33mFunción Main\e[0m\n");

    printf("\e[0;34mSe crean varA y varB y se almacena los valores 20 y 40 respectivamente\e[0m\n");
    int varA = 20;
    int varB = 40;
    printf("int varA =\t%d\n", varA);
    printf("int varB =\t%d\n", varB);

    int *punA = nullptr;
    int *punB = nullptr;
    printf("*punA = nullptr\t%p\n", punA);
    printf("*punB = nullptr\t%p\n", punB);

    printf("\e[0;34mLlamada a la función Punteros pasando las direcciones de memoria de varA y varB\e[0m\n");
    funsionPunteros(&varA, &varB);

    printf("\e[0;33mContinua Función Main\e[0m\n");
    printf("\e[0;34mSe muestra el nuevo valor de varA y varB modificados por la función\e[0m\n");
    printf("varA =\t%d\n", varA);
    printf("varB =\t%d\n", varB);
    printf("*punA = nullptr\t%p\n", punA);
    printf("*punB = nullptr\t%p\n", punB);

    printf("\e[0;33mDetalle Varios\e[0m\n");
    int varX{};
    int* punX{&varX};
    printf ("int varX{}; donde varX = %d\n", varX);
    printf ("int *punx{&varX}; donde punX = %p\n", punX);

    return 0;
}