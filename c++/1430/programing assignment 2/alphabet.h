// Write the definition of the alphabet class here
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "symbol.h"
using namespace std;

#ifndef ALPHABET_H
#define ALPHABET_H

class alphabet
{
    public:
        alphabet();
        alphabet(int size);
        ~alphabet();
        alphabet& operator = (const alphabet& rhs);
        alphabet(const alphabet& lhs);
        int nElements() const;
        void addSymbol(const symbol &sym1);
        int readFromFile(const string &filename);
        void printSymbols() const;
        void printHistogram() const;
        void printCodes() const;
        int totalNumberOfBits() const;
        
    private:
        int size;
        int nelements;
        symbol *symbols = nullptr;
};
#endif