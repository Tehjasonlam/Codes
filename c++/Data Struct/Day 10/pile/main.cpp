#include <iostream>

using namespace std;
//repeat stack of books
//reverse your name 9_5_1
//convert in fix to 9_5_2
//evaluate postfix stack 9_5_3
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
    int peek();
};

void pile::push(int np)
{
    // 1-create
    book *tmp = new book;

    // 2-fill
    tmp->price = np;
    tmp->next = nullptr;
    // link it
    tmp->next = top;
    top = tmp;
}
void pile::print()
{
    book *cu = top;
    while (cu != nullptr)
    {
        cout << cu->price;
        cu = cu->next;
    }
}
void pile::pop(int &v)
{
    book *tmp = top;
    v = top->price;
    top = tmp->next;
    delete tmp;
}
int pile::peek()
{
    return top->price;
}

int priority(char x)
{
    switch (x)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }
}

int main()
{
    pile lib;
    int retv = 0;
    for (int i = 1; i <= 5; i++){
        lib.push(i * 100 / 7);
        lib.print();
    }

    while (!lib.isempty())
    {
        lib.pop(retv);
        cout << " I just deleted " << retv << endl;
    }
}