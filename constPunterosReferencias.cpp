/*
    José Juan Ojeda Granados, 12-01-2022
    const -> punteros memoria y referencias

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

    Compilar con -lstdc++
    gcc constPunterosReferencias.cpp -o constPunterosReferencias.cpp -lstdc++
*/
#include <iostream>

void funcionCasos()
{
  printf("\e[0;33mPunteros:\e[0m\n");
  printf("\e[0;33mCaso 1º    const int        constante = 10;\e[0m\n");
  printf("\e[0;33mCaso 2º    const int       *puntero_a_constante = &constante;\e[0m\n");
  printf("\e[0;33mCaso 3º          int *const puntero_constante_a_variable = &variable;\e[0m\n");
  printf("\e[0;33mCaso 4º    const int *const puntero_constante_a_constante = &constante;\e[0m\n");
  printf("\e[0;33mReferencias:\e[0m\n");
  printf("\e[0;33mCaso 5º    const int &      referencia_a_constante = constante;\e[0m\n");
  printf("\e[0;33mCaso 6º          int &const referencia_constante_a_variable = variable;\e[0m\n");
  printf("\e[0;33mCaso 7º    const int &const referencia_constante_a_constante = constante;\e[0m\n\n");
}

void modoUso()
{
  printf("\t\t\e[0;33mCaracteristicas de const Punteros y Referencias\e[0m\n\n");
  printf("\e[0;31mUso: Indica el número de caso a mostrar (1 al 4)\e[0m\n\n");
  funcionCasos();
  exit(0);
}

int main(int argc, char *argv[])
{
  system("clear");

  if (argc != 2)
  {
    modoUso();
  }
  else 
  {
    int varX = atoi(argv[1]);
    if (varX < 1 || varX > 7)
    {
    modoUso();
    }
  }
  int varX = atoi(argv[1]);

  /*
    Punteros:
          int        variable = 1;
    const int        constante = 2;
    const int *      puntero_a_constante = &constante;
          int *const puntero_constante_a_variable = &variable;
    const int *const puntero_constante_a_constante = &constante;

    * El puntero_a_constante puede apuntar a varios objetos, pero no puede modificarlos.
      Cadenas de caracteres se definen típicamente así: como const char*.
    * Un puntero_constante_a_variable puede modificar el objeto a que apunta, pero no puede apuntar a otra cosa.
    * Finalmente, un puntero_constante_a_constante ni puede modificar el objeto a que apunta ni apuntar a otro objeto.
      Por este punto de vista una cadena de texto hardcoded tiene realmente el tipo const char *const. Sin embargo, se usa poco.
    
    Referencias:
          int        variable = 1;
    const int        constante = 2;
    const int &      referencia_a_constante = constante;
// &const es permitido pero innecesario. Por eso nunca se usa.
          int &const referencia_constante_a_variable = variable;
    const int &const referencia_constante_a_constante = constante;
  */
  printf("\t\t\e[0;33mCaracteristicas de const Punteros y Referencias\e[0m\n\n");
  funcionCasos();
  printf("Se crea:\t\t\t\e[0;34mint varX = %d;\e[0m", varX);

  if (varX == 1)
  { // const int        constante = 10;
    printf("\n\e[0;33mCaso 1º con Punteros\e[0m\n");
    int varA = 10;
    printf("Se crea:\t\t\t\e[0;34mint varA = %d;\e[0m\n", varA);
    varA = 20;
    printf("Se puede:\t\t\t\e[0;34mvarA = %d;\e[0m\n", varA);
    printf("Se crea:\t\t\t\e[0;34mconst int *punA;\e[0m\n");
    const int *punA;
    printf("Se puede:\t\t\t\e[0;34mpunA = &varA;\e[0m\n");
    punA = &varA;
    printf("punA =\t\t\t\t%p\e[0m\n", punA);
    printf("No se puede (*punA RO):\t\t\e[0;31m*punA = 100;\e[0m\n");
    printf("Se puede:\t\t\t\e[0;34mpunA = &varX;\e[0m\n");
    punA = &varX;
    printf("punA =\t\t\t\t%p\e[0m\n", punA);
  }
  else if (varX == 2)
  { // const int *      puntero_a_constante = &constante;
    printf("\n\e[0;33mCaso 2º con Punteros\e[0m\n");
    const int varA = 10;
    printf("Se crea:\t\t\t\e[0;34mconst int varA = %d;\e[0m\n", varA);
    // varA = 20;
    printf("No se puede:\t\t\t\e[0;31mvarA = 20;\e[0m\n");
    printf("Se crea:\t\t\t\e[0;34mconst int *punA\e[0m\n");
    const int *punA;
    printf("Se puede:\t\t\t\e[0;34mpunA = &varA;\e[0m\n");
    punA = &varA;
    printf("punA =\t\t\t\t%p\e[0m\n", punA);
    // *punA = 100;
    printf("No se puede (*punA RO):\t\t\e[0;31m*punA = 100;\e[0m\n");

    printf("Se puede:\t\t\t\e[0;34mpunA = &varX;\e[0m\n");
    punA = &varX;
    printf("punA =\t\t\t\t%p\e[0m\n", punA);
  }
  else if (varX == 3)
  { //       int *const puntero_constante_a_variable = &variable;
    printf("\n\e[0;33mCaso 3º con Punteros\e[0m\n");
    int varA = 10;
    printf("Se crea:\t\t\t\e[0;34mint varA = %d;\e[0m\n", varA);
    varA = 20;
    printf("Se puede:\t\t\t\e[0;34mvarA = %d;\e[0m\n", varA);
    printf("Se debe asignar al crear:\t\e[0;34mint *const punA = &varA;\e[0m\n");
    int *const punA = &varA;
    printf("punA =\t\t\t\t%p\e[0m\n", punA);
    printf("No se puede:\t\t\t\e[0;31mpunA = &varA;\e[0m\n");
    // punA= &varA;
    *punA = 100;
    printf("Se puede:\t\t\t\e[0;34m*punA = %d;\e[0m\n", varA);
    // punA = &varX;
    printf("No se puede:\t\t\t\e[0;31mpunA = &varA;\e[0m\n");
  }
  else if (varX == 4)
  { // const int *const puntero_constante_a_constante = &constante;
    printf("\n\e[0;33mCaso 4º con Punteros\e[0m\n");
    const int varA = 10;
    printf("Se crea:\t\t\t\e[0;34mconst int varA = %d;\e[0m\n", varA);
    // varA = 20;
    printf("No se puede:\t\t\t\e[0;31mvarA = 20;\e[0m\n");
    printf("Se debe asignar al crear:\t\e[0;34mconst int *const punA = &varA;\e[0m\n");
    const int *const punA = &varA;
    printf("punA =\t\t\t\t%p\e[0m\n", punA);
    printf("No se puede:\t\t\t\e[0;31mpunA = &varA;\e[0m\n");
    // punA= &varA;
    // *punA = 100;
    printf("No se puede (*punA RO):\t\t\e[0;31m*punA = 100;\e[0m\n");
    // punA = &varX;
    printf("No se puede:\t\t\t\e[0;31mpunA = &varA;\e[0m\n");
  }
  else if (varX == 5)
  { // const int &      referencia_a_constante = constante;
    printf("\n\e[0;33mCaso 5º con Referencias\e[0m\n");
    const int varA = 10;
    printf("Se crea:\t\t\t\e[0;34mconst int varA = %d;\e[0m\n", varA);
    // varA = 20;
    printf("No se puede:\t\t\t\e[0;31mvarA = 20;\e[0m\n");
    printf("Se crear:\t\t\t\e[0;34mconst int &refA = varA;\e[0m\n");
    const int &refA = varA;
    printf("\t\t\t\trefA = %d\e[0m\n", refA);
    // refA = 20;
    printf("No se puede:\t\t\t\e[0;31mrefA = 20;\e[0m\n");
    // &refA = varX;
    printf("No se puede:\t\t\t\e[0;31m&refA = varX;\e[0m\n");
  }
  else if (varX == 6)
  { // int &const referencia_constante_a_variable = variable;
    printf("\n\e[0;33mCaso 6º con Referencias\e[0m\n");
    int varA = 10;
    printf("Se crea:\t\t\t\e[0;34mint varA = %d;\e[0m\n", varA);
    varA = 20;
    printf("Se puede:\t\t\t\e[0;34mvarA = 20;\e[0m\n");
    printf("Se crear:\t\t\t\e[0;34mconst int &refA = varA;\e[0m\n");
    // int &const refA = varA; FORMATO NO ADMITIDO POR GCC
    int const &refA = varA;
    printf("\t\t\t\trefA = %d\e[0m\n", refA);
    // refA = 20;
    printf("No se puede:\t\t\t\e[0;31mrefA = 20;\e[0m\n");
    // &refA = varX;
    printf("No se puede:\t\t\t\e[0;31m&refA = varX;\e[0m\n");
  }
  else if (varX == 7)
  { // const int &const referencia_constante_a_constante = constante;
    printf("\n\e[0;33mCaso 7º con Referencias\e[0m\n");
    const int varA = 10;
    printf("Se crea:\t\t\t\e[0;34mconst int varA = %d;\e[0m\n", varA);
    // varA = 20;
    printf("No se puede:\t\t\t\e[0;31mvarA = 20;\e[0m\n");

    printf("Se crear:\t\t\t\e[0;34mconst int &refA = varA;\e[0m\n");
    // const int &const refA = varA; FORMATO NO ADMITIDO POR GCC
    // const int const &refA; = varA; ERROR DE GCC "duplicate ‘const’"
    int const &refA = varA;       // int const &ref = const int &ref
    printf("\t\t\t\trefA = %d\e[0m\n", refA);
    // refA = 20;
    printf("No se puede:\t\t\t\e[0;31mrefA = 20;\e[0m\n");
    // &refA = varX;
    printf("No se puede:\t\t\t\e[0;31m&refA = varX;\e[0m\n");
  }

  printf("\n\n");
  return 0;
}