#include <iostream>

void reverse_stack(stacki mystack, int v);
void print_rec(point *);

int main()
{
    stacki<int> mystack;
    for (int i = 0; i < 5; i++)
        mystack.push((i + 1) * 7);
    reverse_stack(mystack, v);
}

void reverse_stack(stacki mystack, int v)
{
    stacki<int> yourstack;
    if (mystack.isempty())
        return;
    else
    {
        v = mystack.pop();
        yourstack.push(v);
        reverse_stack(mystack, v);
        mystack.push(v);
    }
}
void print_rec(point *cu)
{
    if (cu == nullptr)
        return;
    else
    {
        cout << cu->one;
        print_rec(cu->next;)
    }
}