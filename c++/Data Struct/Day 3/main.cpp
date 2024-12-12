#include <iostream>
#include <string>
#include "listcars.h"
using namespace std;

int main()
{
    listcars mydealership; 
    mydealership.addatbeg(2020,20000);
    mydealership.addatbeg(2019,10000);
    mydealership.addatbeg(2023,50000);
    mydealership.print();

    return 0;
}