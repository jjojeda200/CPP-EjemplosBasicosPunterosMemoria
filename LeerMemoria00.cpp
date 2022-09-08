/***************************************************************************************
    José Juan Ojeda Granados
    Fecha:        06-09-2022
    Titulo:       Leer Memoria
    Descripción:  Análisis del uso de la memoria en array imprimiendo zonas usando
                  punteros
    Referencias:
    https://www.youtube.com/watch?v=c9Tow7Wx7qI&list=PLmxqg54iaXrjamduSxTicxzLYC9tQeaFl&index=2
    https://es.cppreference.com/w/cpp/container/array
    https://es.cppreference.com/w/cpp/container/vector
    https://en.cppreference.com/w/c/io/fprintf

    Dependencias:

    Compilar:     g++ -fdiagnostics-color=always -std=c++17 LeerMemoria00.cpp -o LeerMemoria

***************************************************************************************/
#include <iostream>
#include <array>
#include <vector>
#include <cstdint>

constexpr std::size_t colPorDefecto {16};

std::size_t calculaLineas(std::size_t size, std::size_t const ancho = colPorDefecto)
{
      auto const lineas {size/ancho};
      /*
      Con (size & 0xF) nos quedamos únicamente con los 4 últimos bits de size. Si uno
      (o varios) de esos 4 últimos bits fuese uno, ya se cumpliría la condición de ser
      distinto de cero y se devolvería lines+1  -->
      */
      if ((size & 0xf) != 0)
            return lineas + 1;
      return lineas;
}

void muestraLineaMem(std::uint8_t const *mem, std::size_t const ancho = colPorDefecto)
{
      std::printf("%16p ||", (void*)mem);
      for (std::size_t i{}; i < ancho; ++i)
      {
            std::printf(" %02x", mem[i]);
      }
      std::printf("\n");
}

void muestraMem(std::uint8_t const *mem, std::size_t const size, std::size_t const ancho = colPorDefecto)
{
      std::printf("   Dir. Memoria  || 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
      std::printf("  -------------- || -----------------------------------------------\n");
      auto const lineas{calculaLineas(size)};
      for (std::size_t i{}; i < lineas; ++i)
      {
            muestraLineaMem(mem, ancho);
            mem += ancho;
      }
      std::printf("  -----------------------------------------------------------------\n");
}

int main()
{
      system("clear");

      std::array<int, 8> varAarray{1, 2, 4, 8, 16, 32, 64, 128};
      /*
      varAarray es de tipo std::array<int, 8UL>
      Restando 48, vemos 48 bytes de memoria antes del array, por lo tanto vemos la
      dirección de memoria donde esta la varPRT almacenada.
      */
      std::printf("  Zona de memoria del Array (menos 32 bytes)\n");
      auto *varPTR = reinterpret_cast<std::uint8_t const *>(&varAarray);
      muestraMem(varPTR-32, 64, 16);
      std::printf("\n");
      std::printf("Dirección de varPTR                       (%p)\n",&varPTR);
      std::printf("Dirección contenida en varPTR, que es:\n");
      std::printf("La dirección de inicio del array          (%p)\n",varPTR);
      std::printf("Dirección contenida en varPTR, que es:\n");
      std::printf("La dirección de inicio del array menos 32 (%p)\n",varPTR-32);

      std::printf("\n");
}
