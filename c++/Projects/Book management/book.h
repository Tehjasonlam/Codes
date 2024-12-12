#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class book {

    private:
    char *author,*title,*publisher;
	float *price;
	int *stock;
    
    public:
    book()	{
	author = new char[20];
	title = new char[20];
	publisher = new char[20];
	price = new float;
	stock = new int;
	}
	void feeddata(); //input a book
	void editdata(); //edit a book
	void showdata(); //show the book
	int search(char[],char[]); // search the book
	void buybook(); //buy a book
    


};

#endif