/*
    José Juan Ojeda Granados, 11-01-2022
    Punteros dobles, puntero de puntero - Memoria estática y dinámica

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria 
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

    Compilar con -lstdc++
    gcc PunterosDobles00.cpp -o PunterosDobles00 -lstdc++
*/
#include <iostream>

void funsionPuntero(int *punA)
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

void funsionPunteroDoble(int **punB)
{
    printf("\n\e[0;33mFunción Puntero Doble\e[0m\n");
    printf("\e[0;34mSumamos 10 a la variable\e[0m\n");
    printf("punB:\t%p\n", *punB);
    **punB = **punB + 10;
    printf("**punB = **punB + 10\t%d\n", **punB);

    printf("\e[0;34mpunB es variable local de la función\e[0m\n");

    // return; // no necesario al no devolver ningún valor ;-)
}

void funsionPunteroMemDinamica(int **punC)
{
    printf("\n\e[0;33mFunción Puntero Doble Memoria Dinámica\e[0m\n");
    printf("\e[0;34mSumamos 10 a la variable\e[0m\n");
    printf("punC:\t%p\n", *punC);
    **punC = **punC + 10;
    printf("**punC = **punC + 10\t%d\n", **punC);

    printf("\e[0;34mpunC es variable local de la función\e[0m\n");

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
    int *punB{&varB};;
    printf("*punA = nullptr\t%p\n", punA);
    printf("*punB = Dirección memoria de varB\t%p\n", punB);

    printf("\e[0;34mLlamada a la función Puntero pasando la dirección de memoria de varA\e[0m\n");
    funsionPuntero(&varA);

    printf("\e[0;34mLlamada a la función Puntero Doble pasando la dirección de memoria de punB");
    printf("que a su vez contiene la dirección de varA\e[0m\n");
    funsionPunteroDoble(&punB);

    printf("\n\e[0;33mContinua Función Main\e[0m\n");
    printf("\e[0;34mNuevos valores de varA y varB modificados por las funciones\e[0m\n");
    printf("varA =\t%d\n", varA);
    printf("varB =\t%d\n", varB);

    printf("\n\e[0;36mMemoria Heap\e[0m\n");
    printf("\e[0;34mSe crea *punC y se devuelve la dirección de memoria heap asignada en él\e[0m\n");
    int *punC = new int;
    printf("*punC\t%p\n", punC);
    printf("\e[0;34mPor desreferencia se almacena en esa dirección de memoria el valor 60\e[0m\n");
    *punC = 60;
    printf("\e[0;34mMostramos nuevamente la dirección de memoria y su contenido\e[0m\n");
    printf("punC\t%p\n", punC);
    printf("*punC\t%d\n", *punC);

    funsionPunteroMemDinamica(&punC);
    
    printf("\n\e[0;33mContinua Función Main\e[0m\n");
    printf("\e[0;34mMostramos nuevamente la dirección de memoria y su contenido\e[0m\n");
    printf("punC\t%p\n", punC);
    printf("*punC\t%d\n", *punC);

    printf("\e[0;34mSe borra el contenido del puntero y el puntero con delete\e[0m\n\n");
    punC = nullptr;
    delete punC;


/* 
    printf("\e[0;33mDetalle Varios\e[0m\n");
    int varX{};
    int* punX{&varX};
    printf ("int varX{}; donde varX = %d\n", varX);
    printf ("int *punx{&varX}; donde punX = %p\n", punX);
 */
    return 0;
}