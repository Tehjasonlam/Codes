#include "book.h"
#include <iostream>

using namespace std;

void book::feeddata()
{
    cin.ignore();
	cout << "\nEnter Author Name: ";    
	cin.getline(author,20);
	cout << "Enter Title Name: ";       
	cin.getline(title,20);
	cout << "Enter Publisher Name: ";   
	cin.getline(publisher,20);
	cout << "Enter Price: ";            
	cin >> *price;
	cout << "Enter Stock Position: ";   
	cin >> *stock;

}
void book::editdata() //edit a book
{
    
}
void book::showdata() //show the book
{

}
int book::search(char[],char[]) // search the book
{
	return 0;
}
void book::buybook() //buy a book
{

}