#include <iostream>
#include "alphabet.h"

int main()
{
    string filename;
    int size;

    cin >> size;
    alphabet alphTemp1(size);

    cin >> filename;
    if(alphTemp1.readFromFile(filename)==0)
    {       
        // Testing the copy constructor
        alphabet alphTemp2 = alphTemp1;
        alphabet alph(1);
        // Testing the copy-assignment operator
        alph = alphTemp2;
        cout << "Number of symbols in the alphabet = " << alph.nElements() << endl;
        cout << "Characters in the alphabet = ";
        alph.printSymbols();
        alph.printHistogram();
        alph.printCodes();
        cout << "Total number of bits = " << alph.totalNumberOfBits() << endl; 
    }
    else
        cout << "File not found." << endl;
    return 0;
}