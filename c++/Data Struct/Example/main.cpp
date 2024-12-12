#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[]) {
  // *** You need to open files using argumentmanager when submit your assignment ***
  ArgumentManager am(argc, argv);
  // ifstream input(am.get("input"));
  // ofstream output(am.get("output"));

  // *** Use this if you need to test each input individually, but you need to change back to using argumentmanager when you submit the assignment ***
  ifstream input("input1.txt");
  ofstream output("output1.txt");

  string in = "";

  while(getline(input, in)) {
    in.erase(remove(in.begin(), in.end(), '\n'), in.end());
    in.erase(remove(in.begin(), in.end(), '\r'), in.end());
    in.erase(remove(in.begin(), in.end(), ' '), in.end());
    if (in.size() == 0) continue;

    cout << in << endl;
    output << in << endl;
  }
    
  input.close();
  output.close();
  return 0;
}