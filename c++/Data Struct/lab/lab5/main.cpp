#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "ArgumentManager.h"
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // ifstream input("input3.txt");
    // ofstream output("output3.txt");

    if (!input.is_open() || !output.is_open())
    {
        cerr << "Error opening files" << endl;
        return 1;
    }

    string line;
    int number;
    map<string, int> operators;

    input >> number;

    for(int i = 0; i < number; i++)
    {
        input >> line;
        operators[line]++;
    }

    for(auto it = operators.begin(); it!= operators.end(); it++)
    {
        output << it->first << ": " << it->second << endl;
    }

    return 0;
}
