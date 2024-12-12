#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    bool hasSquareBracket = false;
    bool hasRoundBracket = false;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
            if (c == '[')
            {
                hasSquareBracket = true;
            }
            else if (c == '(')
            {
                hasRoundBracket = true;
            }
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (st.empty())
            {
                return false;
            }
            char openBracket = st.top();
            st.pop();
            if ((c == ')' && openBracket != '(') || (c == ']' && openBracket != '[') || (c == '}' && openBracket != '{'))
            {
                return false;
            }
        }
        if ((hasSquareBracket && c == '{') || (hasRoundBracket && c == '{'))
        {
            return false; // '{' should not appear after '[' or '(' according to the prompt
        }
    }
    if (!st.empty())
    {
        return false; // Unclosed opening brackets
    }
    return true;
}

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    // ifstream input("input1.txt"); //just me testing
    // ofstream output("output.txt");
    queue<string> invalid_queue; // these are made to put everything into separate sections for output
    queue<string> valid_queue;
    string line;

    while (getline(input, line))
    {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end()); // remove newlines and return characters
        if (isValid(line))
        {
            valid_queue.push(line);
        }
        else
        {
            invalid_queue.push(line);
        }
    }
    if (!invalid_queue.empty())
    { // if there are invalid lines, print them out
        output << "Invalid" << endl;
        while (!invalid_queue.empty())
        {
            output << invalid_queue.front() << endl; // output in order
            invalid_queue.pop();                     // remove from queue
        }
    }
    if (!valid_queue.empty())
    { // if there are valid lines, print them out
        output << "Valid" << endl;
        while (!valid_queue.empty())
        {
            output << valid_queue.front() << endl;
            valid_queue.pop();
        }
    }
    input.close();
    output.close();
}