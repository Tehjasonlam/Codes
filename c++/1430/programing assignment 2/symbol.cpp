// Write the implementation of the symbol class here
#include "symbol.h"
using namespace std;


symbol::symbol()
{
    
}
symbol::symbol(char ch, int frequency, string code)
{
    this->ch = ch;
    this->frequency = frequency;
    this->code = code;
}
char symbol::getch()
{
    return ch;
}
int symbol::getfre()
{
    return frequency;
}
string symbol::getcode()
{
    return code;
}
void symbol::setch(char ch)
{
    this->ch = ch;
}
void symbol::setfre(int fre)
{
    this->frequency = fre;
}
void symbol::setcode(string code)
{
    this->code = code;
}
istream& operator >> (istream& input, symbol &sym)
{
    input >> sym.ch;
    input >> sym.frequency;
    input >> sym.code;
    return input;
}
bool symbol::operator == (const symbol& sym1)
{
    if (this->ch == sym1.ch)
    {
        return true;
    }
    return false;
}