#include <iostream>
using namespace std;
struct book
{
    int price;
    book *next;
};
class pile
{
private:
    book *top;

public:
    pile() { top = nullptr; }
    bool isempty() { return (top == nullptr); }
    book *gettop() { return top; }
    void push(int);
    void pop(int &);
    void print();
};
