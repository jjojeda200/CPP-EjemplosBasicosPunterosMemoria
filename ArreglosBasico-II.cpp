/*
    José Juan Ojeda Granados, 22-01-2022
    Notas conversiones cast :--)
*/
#include <vector>
#include <iostream>
using std::cout;
using std::string;

struct sUno
{
    const char *fUno() const
    {
        return "Función uno de la struct sUno!\n";
    }
};

struct sDos : sUno
{
    const char *fUno() const
    {
        return "Función uno de la struct sDos!\n";
    }
};

int main()
{
    system("clear");

    // ***************************************************************************
    printf("\t\n\033[33mConversión de datos: explicita\033[0m\n");
    int valA = 10.2;
    int valB = valA + 5.0;
    printf("imprime int valB --> valA + 5.0; = %d\n", valB);
    // Operadores de molde (cast)
    // cast en tiempo de compilación --> tipo_de_dato (expresión)
    valB = int(44.59);
    printf("imprime valB --> int(44.59); = %d\n", valB);
    valB = 2.5 - float(18.0 + 8) + 5;
    printf("imprime valB --> 2.5 - float(18.0 + 8) + 5; = %d\n", valB);

    // ***************************************************************************
    printf("\t\n\033[33mConversión de datos: implícita\033[0m\n");
    // cast en tiempo de ejecución --> static_cast < nuevo-tipo > ( expresión )
    valB = static_cast<int>(5.5);
    printf("imprime valB --> static_cast<int>(5.5); = %d\n", valB);
    int valC = static_cast<int>(3.14);
    printf("imprime valC --> int valC = static_cast<int>(3.14); = %d\n", valC);

    // ***************************************************************************
    cout << "\n";
    std::vector<int> v = static_cast<std::vector<int>>(6);
    std::cout << "Ejecuta --> std::vector<int> v = static_cast<std::vector<int>>(6);\n";
    std::cout << "Imprime --> v.size() = " << v.size() << "\n\n";

    // v[i] es equivalente a: *((&v[0]) + i)
    for (int i = 0; i <= v.size(); i++)
    {
        v[i] = i;
    }
    

    for (int i = 0; i <= v.size() + 2; i++)
        std::cout << v[i] << " " << &v[i] << "\n";

    cout << "\n";
    // ***************************************************************************
    /*
            Manejo básico de punteros a zonas de memoria
             * Para declarar variable apuntadora.
             * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria
               almacenada en una variable puntero.
             & Para mostrar la dirección de memoria de cualquier variable.
        */
    std::cout << "Crea --> sDos Objeto;\n";
    std::cout << "Ejecuta --> sUno &dMemoria = Objeto;\n";
    sDos Objeto;
    sUno &dMemoria = Objeto; // upcast vía conversión implícita
    std::cout << "Dirección de memoria de Objeto:\t\033[31m" << &dMemoria << "\033[0m\n";
    std::cout << "Llama a función --> dMemoria.fUno();\n" << dMemoria.fUno();
    sDos &dMemoria_sc = static_cast<sDos &>(dMemoria); // downcast vía conversión implícita
    std::cout << "Dirección de memoria de Objeto:\t\033[31m" << &dMemoria_sc << "\033[0m\n";
    std::cout << "Llama a función --> dMemoria_sc.fUno();\n" << dMemoria_sc.fUno();
}