#include <iostream>
using namespace std;
#include "word.h"

int main()
{
  word english;
  english.insertatbeg('e');
  english.insertatbeg('y');
  english.insertatbeg('b');
  english.print();
  english.printrec(); //using next
  english.printprev(); //prev
  english.del_c('y');
}