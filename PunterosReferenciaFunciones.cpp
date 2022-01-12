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
    gcc PunterosReferenciaFunciones.cpp -o PunterosReferenciaFunciones -lstdc++
*/
#include <iostream>

void funsionPuntero(int *punA)
{
    printf("\e[0;33mFunción Puntero\e[0m\n");
    printf("\e[0;34mSumamos 10 a la variable\e[0m\n");
    printf("punA:\t%p\n", punA);
    *punA = *punA + 10;
    printf("*punA = *punA + 10\t%d\n", *punA);

    printf("\e[0;34mpunA es variable local de la función\e[0m\n");
    printf("\e[0;34mInicializa con la dirección pasada al llamar a la función\e[0m\n");

    // return; // no necesario al no devolver ningún valor ;-)
}

void funsionReferencia(int &refB)
{
    printf("\e[0;33mFunción Referencia\e[0m\n");
    printf("\e[0;34mSumamos 10 a la variable\e[0m\n");
    printf("refB:\t%d\n", refB);
    refB = refB + 10;
    printf("refB = refB + 10\t%d\n", refB);

    printf("\e[0;34mrefB es una variable referenciada a varB local de la función\e[0m\n");
    printf("\e[0;34mrefB es una referencia a varB, que no una copia, por ello\e[0m\n");
    printf("\e[0;34mno es necesario devolver ningún valor\e[0m\n");

    // return; //  ;-)
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
    printf("*punA = nullptr\t%p\n", punA);

    printf("\n\e[0;34mLlamada a la función Puntero pasando la dirección de memoria de varA\e[0m\n");
    funsionPuntero(&varA);

    printf("\n\e[0;34mLlamada a la función Referencia pasando varB\e[0m\n");
    funsionReferencia(varB);

    printf("\n\e[0;33mContinua Función Main\e[0m\n");
    printf("\e[0;34mSe muestra el nuevo valor de varA y varB modificados por las funciones\e[0m\n");
    printf("varA =\t%d\n", varA);
    printf("varB =\t%d\n", varB);

    printf("\n\e[0;33mDetalle Varios\e[0m\n");
    int varX{};
    int* punX{&varX};
    printf ("int varX{}; donde varX = %d\n", varX);
    printf ("int *punx{&varX}; donde punX = %p\n", punX);

    return 0;
}