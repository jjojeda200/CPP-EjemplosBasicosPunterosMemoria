/***************************************************************************************
    José Juan Ojeda Granados
    Fecha:        10-10-2022
    Titulo:       00ViewMem.hpp
    Descripción:  Análisis de uso de la memoria visualizando zonas usando punteros

    Uso:
    
      std::uint8_t *VariablePuntero{&DirecciónVisualizar};

      // si es necesarios cast -->
      auto *varPTR = reinterpret_cast<std::uint8_t const *>(&VariablePuntero);

      // llamada al método con cast
      muestra(varPTR , 40);

      // llamada al método con cast
      muestra(VariablePuntero, 40);

***************************************************************************************/
#ifndef __00VIEWMEM_HPP
#define __00VIEWMEM_HPP

#pragma once

#include <iostream>
#include <stdio.h>

constexpr std::size_t colPorDefecto{16};

std::size_t calculaLineas(std::size_t size, std::size_t const ancho = colPorDefecto)
{
      auto const lineas{size / ancho};
      /*
      Con (size & 0xF) nos quedamos únicamente con los 4 últimos bits de size. Si uno
      (o varios) de esos 4 últimos bits fuese uno, ya se cumpliría la condición de ser
      distinto de cero y se devolvería lines+1  -->
      */
      if ((size & 0xf) != 0)
            return lineas + 1;
      return lineas;
}

void muestraLinea(std::uint8_t const *mem, bool const ascii, std::size_t const ancho)
{
      std::printf("%16p |", (void*)mem);
      for (std::size_t i{}; i < ancho; ++i) { std::printf(" %02x", mem[i]); }
      if (ascii)
      {
            std::printf(" | ");
            for (std::size_t i{}; i < ancho; ++i)
            {
                  auto varChar = (mem[i] > 32 && mem[i] < 126) ? mem[i] : '.';
                  std::printf(" %c", varChar);
            }
      }
      std::printf("\n");
}

void muestra(std::uint8_t const *mem, std::size_t const size, bool const ascii = false, std::size_t const ancho = colPorDefecto)
{
      std::printf("\033[33m");
      std::printf("   Dir. Memoria  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
      std::printf("  -------------- | -----------------------------------------------\n");
      auto const lineas{calculaLineas(size)};
      for (std::size_t i{}; i < lineas; ++i)
      {
            muestraLinea(mem, ascii, ancho);
            mem += ancho;
      }
      std::printf("  ---------------|------------------------------------------------\n");
      printf("\033[0m");
}

#endif      // __00VIEWMEM_HPP