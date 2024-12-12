#include <iostream>
using namespace std;
//extra_8_4_1

int main(int argc, char *argv[]) {
  cout << "Hello World!\n";
  cout << argc << endl; // argument counter
  cout << "the first element of the vector array is " << argv[0] << endl;

  for(int i = 0; i <argc ;i++)
    cout << argv[i] << endl;
}