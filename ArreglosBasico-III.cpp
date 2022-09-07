/*
    José Juan Ojeda Granados, 03-02-2022
    Práctica básica III de manejo de Vectores

    Entendiendo y optimizando std::vector

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

*/
#include <vector>
#include <iostream>
using std::cout;

const uint32_t size = 1000;

struct GameObject
{
    uint8_t granDato[size];
    // int granDato;
};

using VGO = std::vector<GameObject>;

void modoUso()
{
    system("clear");
    cout << "\t\033[33mEntendiendo y optimizando std::vector\033[0m\n\n";
    cout << "\t\e[0;31mUso: Indica el número de GameObjecta crear\e[0m\n\n";
    exit(0);
}

void imprimeVectorPorCopia(const VGO vecA) // Mal, muy mal ;-()
{
    cout << "Tamaño vector\033[34m " << vecA.size() <<  "\033[0m Capacidad \033[34m" << vecA.capacity() << "\033[0m\n";
}

void imprimeVectorPorReferencia(const VGO &vecA) // Bien ;-)
{
    cout << "Dir. de la primera posición del vector : \033[34m"<< &vecA[0]
         << "\033[0m Tamaño \033[34m" << vecA.size() 
         << "\033[0m Capacidad \033[34m" << vecA.capacity() << "\033[0m\n";
}

int main(int argc, char *argv[])
{
    system("clear");

    if (argc != 2)
    {
        modoUso();
    }

    // ***************************************************************************
    cout << "\t\033[33mEntendiendo y optimizando std::vector\033[0m\n\n";

    VGO vGameObject;

    
    // vGameObject.reserve(100); // <-- Para optimizar memoria, calcular la necesaria y reservar

    if (atoi(argv[1]) != 0)
    {
        cout << "\033[36mBucle for para rellenar el vector\033[0m\n";
        for (size_t i = 0; i < atoi(argv[1]); i++)
        {
            imprimeVectorPorReferencia(vGameObject);
            vGameObject.push_back(GameObject());
        }
    }
    imprimeVectorPorReferencia(vGameObject);
    cout << "\n";

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        cout << "Dirección en memoria de las posiciones en el vector: \033[34m" << &vGameObject[i] << "\033[0m\n";
    }
    cout << "\n";

    return 0;
}