/*
    José Juan Ojeda Granados, 26-01-2022
    Práctica básica II de manejo de arreglos

    Manejo básico de Arrays, Arreglos, Matriz, Vectores

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.
*/
#include <vector>
#include <iostream>
using std::cout;
using std::vector;

int main()
{

     system("clear");
    // ***************************************************************************
    cout << "\t\033[33mVectores y Vectores de Punteros\033[0m\n\n";
    int LongVector{6};

    vector<int> vUno = static_cast<vector<int>>(LongVector);
    cout << "Crea vector vector utilizando static_cast;\n";
    cout << "Ejecuta --> vector<int> vUno = static_cast<vector<int>>(LongVector);\n";
    cout << "Imprime --> vUno.size() = " << vUno.size() << "\n\n";

    cout << "Bucle for para rellenar e imprimir todo el vector\n";
    // vUno[i] es equivalente a: *((&vUno[0]) + i)
    for (int i = 0; i < vUno.size(); i++)
    {
        vUno[i] = i;
        cout << "Valor almacenado en el vector: \033[34m" << vUno[i] 
        << "\033[0m Dirección en memoria: \033[34m" << &vUno[i] << "\033[0m\n";
    }
    cout << "\n";

    // ***************************************************************************
    vector<int *> vpUno(LongVector, nullptr);
    cout << "Crea vector de punteros \"vpUno\" e inicializa a nullptr);\n";
    cout << "Ejecuta --> vector<int *> vpUno(LongVector, nullptr);\n\n";
    
    cout << "Bucle for para rellenar e imprimir todo el vector\n";
    for (int i = 0; i < LongVector; i++)
    {
        vpUno[i] = &vUno[i];
        cout << "Dirección almacenada en el vector: \033[36m" << &vpUno[i] 
        << "\033[0m -->  \033[34m" << vpUno[i] << "\033[0m\n";
    }
    cout << "\n";
    cout << "Modificando el valor del vector vUno desreferenciando con vpUno\n";
    for (int i = 0; i < LongVector; i++)
    {
        *vpUno[i] = 10 + i ;
        cout << "Valor modificado en el vector: \033[34m" << vUno[i] << "\033[0m\n";
    }
}