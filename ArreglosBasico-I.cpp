/*
    José Juan Ojeda Granados, 25-01-2022
    Práctica básica I de manejo de arreglos

    Manejo básico de Arrays, Arreglos, Matriz, Vectores

*/
#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;
// using namespace std;

int potAlg(int a, int b)
{
    int valor = 0;
    while (a > 0)
    {
        valor += b; // valor = valor + b;
        a--;
    }
    return valor;
}

void staticMA()
{
    cout << "\e[0;33m  Arreglo estático\e[0m\n";
    int ma[9][3];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ma[i][j] = potAlg(i + 1, j + 1);
            cout << ma[i][j] << "\t";
        }
        cout << '\n';
    }
}

// Manejos de índices de matrices
void showMA3x3(int ma[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ma[i][j] << "\t";
        }
        cout << '\n';
    }
}

void multMA()
{
    cout << "\e[0;33m  Manejos de índices de matrices\e[0m\n";
    cout << "\e[0;33m  Ejemplo multiplicando\e[0m\n";
    int a[3][3] = {{3, 1, -2}, {0, 4, 2}, {7, 5, 1}};
    int b[3][3] = {{-1, 0, 8}, {3, 6, 9}, {0, 0, 3}};
    int c[3][3] = {0};

    showMA3x3(a);
    cout << "\e[0;31m\tx\n\e[0m";

    showMA3x3(b);
    cout << "\e[0;31m\t=\n\e[0m";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
        }
    }

    showMA3x3(c);
}

void dinamicMA() // Matrices Dinámicas
{
    cout << "\n\e[0;33m  Matrices Dinámicas\e[0m\n";
    int rows;

    cout << "Indica el número de filas: ";
    cin >> rows;

    int **ma = new int *[rows];
    int *columns = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        cout << "\nIndica el número de columnas para cada fila " << i + 1 << ": ";
        cin >> columns[i];
        ma[i] = new int[columns[i]];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            ma[i][j] = potAlg(i + 1, j + 1);
            cout << ma[i][j] << "\t";
        }
        cout << '\n';
    }

    for (int i = 0; i < rows; i++)
        delete[] ma[i];

    delete[] columns;
    delete[] ma;
}

int main()
{
    system("clear");
    staticMA();         // Matrices Dinámicas
    cout << '\n';
    multMA();
    dinamicMA();
}