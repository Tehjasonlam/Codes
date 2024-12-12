#include "ArgumentManager.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int start = 0) {
  int length = s.length();
  // If this condition is true, it means that the code has successfully checked
  // all the characters in the string up to the middle point, and therefore, it
  // can conclude that the characters checked so far form a palindrome.

  if (start > length / 2) {
    return true;
  }

  return s[start] == s[length - start - 1] && isPalindrome(s, start + 1);
}

int main(int argc, char *argv[]) {

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

  // test input
  // ifstream input("input6.txt");
  // ofstream output("output6.txt");

  if (!input) {
    cout << "Input file not found" << endl;
    exit(1);
  }

  string line;
  while (getline(input >> ws, line)) {

    // Remove '\n' and '\r' characters

    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    // change to lowercase
    transform(line.begin(), line.end(), line.begin(), ::tolower);

    // remove punctuation
    int lineSize = line.size();
    for (int i = 0; i < lineSize; i++) {
      if (line[i] == ' ' || ispunct(line[i])) {
        line.erase(i, 1); // remove ith char from string
        i--;              // reduce i with one so you don't miss any char
      }
    }

    if (isPalindrome(line, 0))
    {
      cout << line;
    output << "true" << endl;
  }
  else {
    cout << line;
    output << "false" << endl;
  }
}

return 0;
}

