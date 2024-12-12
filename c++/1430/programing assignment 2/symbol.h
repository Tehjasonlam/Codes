// Write the definition of the symbol class here
#pragma once

#include <iostream>
#include <string>
using namespace std;

#ifndef SYMBOL_H
#define SYMBOL_H

#define MAXSIZE 256
class symbol
{
    private:
        char ch;
        int frequency;
        string code;

    public:
        symbol();
        symbol(char ch, int frequency, string code);
        char getch();
        int getfre();
        string getcode();
        void setch(char ch);
        void setfre(int fre);
        void setcode(string code);
        friend istream& operator >> (istream& input, symbol &sym);
        bool operator == (const symbol& sym1);
        

};
#endif