#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "book.h"

using namespace std;

int main(){
    book *B[20];
    int i=0,r,t,count;
	char titlebuy[20],authorbuy[20];
    while (1)
    {
        cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
        cin >> count;
        switch(count)
        {
            case 1: B[i] = new book;
				B[i]->feeddata();
				i++;
                break;
            case 2:
                cout << "2";
                break;
            case 3:
                cout << "3";
                break;
            case 4:
                cout << "4";
                break;
            case 5:exit(0);
            default: cout<<"\nInvalid Choice Entered";
                
        }
    }

    return 0;
}