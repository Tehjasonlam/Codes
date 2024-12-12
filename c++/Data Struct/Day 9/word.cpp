#include "word.h"
#include <iostream>
using namespace std;

void word::insertatbeg(char x)
{
    // 1-create
    onechar *tmp = new onechar;
    // 2- fill
    tmp->l = x;
    tmp->prev = tmp->next = nullptr;
    // 3- update the links
    if (isempty())
        head = tmp;
    else
    {
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
}
void word::print()
{
    onechar *cu = head;
    while (cu != nullptr)
    {
        cout << cu->l << endl;
        cu = cu->next;
    }
}

void word::printrec(onechar *cu)
{
    if (cu != nullptr)
    {
        cout << cu->l << endl;
        printrec(cu->next);
    }
}

void word::printprev(){
   onechar *cu = head;
    while (cu != nullptr)
    {
        cout << cu->l << endl;
        cu = cu->prev;
    }
}

void word::del_c(char x)
{
    // 1- find the node
    onechar *cu = head;
    while (cu!= nullptr)
    {
        if (cu->l == x)
        {
            break;
        }
        cu = cu->next;
    }
    // 2- update the links
    if (cu == head)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else if (cu == nullptr)
    {
        cout << "the letter is not in the list" << endl;
    }
    else
    {
        cu->prev->next = cu->next;
        cu->next->prev = cu->prev;
        cout << "the letter is deleted" << cu << endl;
        delete cu;
    }
}