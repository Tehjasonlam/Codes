// Write the implementation of the alphabet class here
#include "alphabet.h"
#include "symbol.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


alphabet :: alphabet()
{
    
}
alphabet :: alphabet(int size)
{
    this->size = size;
    
}
alphabet ::~alphabet()
{
    if(symbols!=nullptr)
    {
        delete [] symbols;
    }
}
alphabet& alphabet::operator =  (const alphabet& lhs)
{
    
}
alphabet ::alphabet(const alphabet& rhs)
{
    for (int i = 0; i < size; i++)
    {
        size = rhs.size;
        nelements = rhs.nelements;
        if(symbols!=nullptr)
        delete [] symbols;
        symbols = new symbol[size];
        for(int i = 0; i < rhs.size;i++)
        {
            symbols[i]= rhs.symbols[i];
        }
    }
}
int alphabet::nElements() const
{
    return nelements;
}
void alphabet::addSymbol(const symbol &sym1)
{

    if (nelements < size)
    {
        for (int i = 0; i < nelements; i++)
        {
            if(symbols[i] == sym1)
            {
                break;
            }
            symbols[nelements] = sym1;
            nelements++;
        }
    }
}

int alphabet::readFromFile(const string &filename) 
{

    ifstream myfile;
    myfile.open(filename);
    if (myfile.is_open())
    {
        int count = 0;
        while (myfile >> symbols[count])
        {
            if (size > count)
            {
                count++;
                if (size == count)
                {
                    break;
                }
            }
        }
        myfile.close();
        return 0;
    }
    else
    {
        return -1;
    }

}
void alphabet::printSymbols() const
{

    for (int i = 0; i < nelements; i++)
    {
        cout << symbols[i].getch() << ", ";
    }
    cout << endl;

}
void alphabet::printHistogram() const
{

    cout << "Histogram showing the frequency of the symbols in the alphabet" << endl;
    for (int i = 0; i < nelements ; i++)
    {
        cout << symbols[i].getch() << " | "<< endl;
        
        for(int j = 0; j < symbols[i].getfre(); j++)
        {
            cout << "*";
        }
        cout << endl;
        
    }

}
void alphabet::printCodes() const
{

    cout << "Alphabet codes:" << endl;
    for (int i = 0; i < nelements ; i++)
    {
        cout << symbols[i].getch() << " | "<<  symbols[i].getcode() << endl;
    }

}
int alphabet::totalNumberOfBits() const
{

    int total = 0;
    for (int i = 0; i < nelements; i++)
    {
        
        total += symbols[i].getfre() * symbols[i].getcode().length();
    }
    return total;

} 