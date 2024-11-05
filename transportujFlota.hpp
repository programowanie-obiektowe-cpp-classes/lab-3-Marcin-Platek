#pragma once

#include "Stocznia.hpp"
#include "Statki.hpp"
#include "ObjCounter.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    // Implementacja własnej funkcji

    // Od razu wrzucamy pętle, która zapewni, że nie stworzy się żaden statek bez wartości towar różnej od 0
    if (towar == 0) 
        return 0;
    

    Stocznia stocznia;                              // Tworzymy "fabrykę" statków
    Stocznia::resetTotalCap();                      // Resetujemy całkowitą pojemność przed rozpoczęciem transportu
    CountThis<Zaglowiec>::reset();                  // Resetujemy licznik żaglowców przed rozpoczęciem transportu

    unsigned int transported = 0;                   // Wprowadzamy licznik przetransportowanego towaru

    // Wykonujemy pętle aż do momentu, gdy nie załadujemy całego towaru
    while (transported < towar) 
    {
        Statek* ship = stocznia();                  // Tworzymy nowy statek za pomocą "fabryki"
        transported += ship->transportuj();         // Dodajemy ilość towaru przetransportowaną przez ten statek
        delete ship;                                // Usuwamy utworzony statek, czyścimy miejsce
    }

    return CountThis<Zaglowiec>::get();             // Poprzez zastosowanie funkcji zwracamy liczbę żaglowców, których użyliśmy do transportu
}
