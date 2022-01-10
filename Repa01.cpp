/*
    José Juan Ojeda Granados, 10-01-2022
    Repaso punteros memoria y utilización en clase

    Manejo básico de punteros a zonas de memoria
     * Para declarar variable apuntadora.
     * Para desreferenciar, acceder directamente al contenido de una ubicación de memoria 
       almacenada en una variable puntero.
     & Para mostrar la dirección de memoria de cualquier variable.

*/
#include <iostream>

class Numero
{
public:
    Numero();
    ~Numero();
    int obtenerNumero();
    void configurarNumero(int numero);
    void pintar();
private:
    int elNumero;
};

Numero::Numero()    // Constructor
{
    printf("\e[0;37mConstructor ...\e[0m\n");
}

Numero::~Numero()   // Destructor
{
    printf("\e[0;37mDestructor ...\e[0m\n");
}

int Numero::obtenerNumero() // Metodo
{
    return elNumero;
}

void Numero::configurarNumero(int numero)
{
    elNumero = numero;
}

void Numero::pintar()
{
    printf("\e[0;36mEl número %d\e[0m\n", elNumero);
}

int main(int argc, char *argv[])
{
    system("clear");
    printf("\n\t\e[0;33mBloque main\e[0m\n");

    // Crea el objeto Primer y lanza el constructor, se cierra con el destructor automático
    Numero Primer;
    printf("Se crea el objeto Primer, se almacena el número 10 y se muestra\n");
    Primer.configurarNumero(10);
    Primer.pintar();

    printf("\nSe crea el objeto por puntero en heap, y se muestra la dirección\n");
     // Crea el objeto por puntero y lanza el constructor, se cierra con el delete
    Numero *pNumero = new Numero;
    printf("pNumero\t\t\e[0;33m%p\e[0m\n", pNumero);

    printf("Se llama al método guardar numero por puntero y se almacena el 20, se muestra\n");
    (*pNumero).configurarNumero(20);
    (*pNumero).pintar();

    // destructor del constructor lanzado al crear *pNumero
    delete pNumero;

    // ultimo destructor automático
    return 0;
}