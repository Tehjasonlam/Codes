#ifndef LISTCARS_H
#define LISTCARS_H

#include <iostream>

using namespace std;

struct car{
    int year;
    float price;
    car *next;
};

class listcars{
    private:
        car *head;
    public:
        listcars() {head = nullptr;}
        void addatbeg(int,float);
        void print();
};

#endif