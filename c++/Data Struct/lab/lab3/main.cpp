#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <iomanip>
#include "ArgumentManager.h"
#include <string>
#include <vector> 
#include <cmath>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

string InfixtoPostfix(const string &infixExpression)
{
    stack<char> operatorStack;
    stringstream postfixStream;
    stringstream input(infixExpression);

    string token;
    while (input >> token)
    {
        for (char c : token)
        {
            if (isdigit(c) || isalpha(c))
            {
                postfixStream << c;
            }
            else if (c == '(')
            {
                operatorStack.push(c);
            }
            else if (c == ')')
            {
                while (!operatorStack.empty() && operatorStack.top() != '(')
                {
                    postfixStream << ' ' << operatorStack.top();
                    operatorStack.pop();
                }
                if (!operatorStack.empty() && operatorStack.top() == '(')
                    operatorStack.pop();
            }
            else if (isOperator(c))
            {
                while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.top()))
                {
                    postfixStream << ' ' << operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(c);
            }
        }
        postfixStream << ' '; // Add a space between tokens
    }

    while (!operatorStack.empty())
    {
        postfixStream << ' ' << operatorStack.top();
        operatorStack.pop();
    }

    return postfixStream.str();
}

double evaluatePostfix(const string &expression)
{
    stack<double> operandStack;
    istringstream iss(expression);
    string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            operandStack.push(stod(token));
        }
        else
        {
            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            switch (token[0])
            {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            case '^':
            {
                double base = operand1;
                double exponent = operand2;
                double result = 1.0;
                for (int i = 0; i < exponent; i++)
                {
                    result *= base;
                }
                operandStack.push(result);
            }
            break;
            default:
                cerr << "Invalid operator: " << token << endl;
                exit(1);
            }
        }
    }

    if (!operandStack.empty())
    {
        return operandStack.top();
    }
    else
    {
        cerr << "Expression is empty" << endl;
        exit(1);
    }
}

double evaluatePrefix(const string &prefixExpression)
{
    stack<double> operandStack;
    istringstream iss(prefixExpression);
    string token;

    // Tokenize the prefix expression
    vector<string> tokens;
    while (iss >> token)
    {
        tokens.push_back(token);
    }

    // Process tokens in reverse order (from right to left)
    for (int i = tokens.size() - 1; i >= 0; --i)
    {
        token = tokens[i];
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1])))
        {
            operandStack.push(stod(token));
        }
        else if (isOperator(token[0]))
        {
            double operand1, operand2;
            if (!operandStack.empty())
            {
                operand1 = operandStack.top();
                operandStack.pop();
            }
            else
            {
                cerr << "Not enough operands for operator: " << token << endl;
                exit(1);
            }

            if (!operandStack.empty())
            {
                operand2 = operandStack.top();
                operandStack.pop();
            }
            else
            {
                cerr << "Not enough operands for operator: " << token << endl;
                exit(1);
            }

            switch (token[0])
            {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            case '^':
                operandStack.push(pow(operand1, operand2));
                break;
            default:
                cerr << "Invalid operator: " << token << endl;
                exit(1);
            }
        }
        else
        {
            cerr << "Invalid token: " << token << endl;
            exit(1);
        }
    }

    if (!operandStack.empty())
    {
        return operandStack.top();
    }
    else
    {
        cerr << "Expression is empty" << endl;
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    // *** You need to open files using argumentmanager when submit your assignment ***
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // *** Use this if you need to test each input individually, but you need to change back to using argumentmanager when you submit the assignment ***

    // ifstream input("input3.txt");
    // ofstream output("output3.txt");

    if (!input.is_open() || !output.is_open())
    {
        cerr << "Error opening files" << endl;
        return 1;
    }

    string expressionType, expression;
    getline(input, expressionType);
    getline(input, expression);

    expressionType.erase(expressionType.find_last_not_of(" \t\n\r\f\v") + 1);

    double result;

    if (expressionType == "postfix")
    {
        result = evaluatePostfix(expression);
    }
    else if (expressionType == "prefix")
    {
        result = evaluatePrefix(expression);
    }
    else if (expressionType == "infix")
    {
        string postfixExpression = InfixtoPostfix(expression);
        result = evaluatePostfix(postfixExpression);
    }
    else
    {
        cerr << "Invalid expression type: " << expressionType << endl;
        return 1;
    }

    output << fixed << setprecision(2) << result << endl;

    input.close();
    output.close();

    return 0;
}