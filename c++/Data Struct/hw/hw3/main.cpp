#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "ArgumentManager.h"

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void link(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void selectionSort(ofstream& output) {
        int i = 1;

        if (!head || !head->next) {
            return;
        }

        Node* current = head;

        while (current) {
            Node* minNode = current;
            Node* temp = current->next;

            while (temp) {
                if (temp->data < minNode->data) {
                    minNode = temp;
                }
                temp = temp->next;
            }

            // Swap the values of the current node and the minimum node.
            int tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;

            if (i != 1) {  // Skip printing the initial state on the first iteration.
                out(output);
                if (current->next) {
                    output << endl;
                }
            }

            i++;
            current = current->next;
        }
    }

    void insertionSort(ofstream &output)
    {
        int i = 1;
        if (!head || !head->next)
        {
            return;
        }

        Node *current = head->next;

        while (current)
        {
            Node *prevNode = current->prev;
            Node *currentNode = current;
            int j = current->data;

            while (prevNode && prevNode->data > j)
            {
                prevNode->next->data = prevNode->data;
                currentNode = prevNode;
                prevNode = prevNode->prev;
            }

            currentNode->data = j;
            out(output);

            if (current->next)
            {
                output << endl;
            }

            i++;
            current = current->next;
        }
    }

    void out(ofstream &os)
    {
        Node *current = head;
        os << "[";
        while (current)
        {
            os << current->data;
            if (current->next)
            {
                os << ",";
            }
            current = current->next;
        }
        os << "]";
    }
};

bool is_valid_numbers_line(const string &line)
{
    istringstream iss(line);
    int val;
    while (iss >> val)
    {
        if (iss.fail())
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    // *** You need to open files using ArgumentManager when submitting your assignment ***
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // *** Use this if you need to test each input individually, but you need to change back to using ArgumentManager when you submit the assignment ***
    // ifstream input("input1.txt");
    // ofstream output("output1.txt");

    if (!input.is_open())
    {
        cerr << "Failed to open input file." << endl;
        return 1;
    }
    if (!output.is_open())
    {
        cerr << "Failed to open output file." << endl;
        return 1;
    }

    string line;
    if (getline(input, line))
    {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());

        if (line.empty() || !is_valid_numbers_line(line))
        {
            output << "Input is invalid." << endl;
        }
        else
        {
            string expressionType;
            if (getline(input, expressionType))
            {
                expressionType.erase(expressionType.find_last_not_of(" \t\n\r\f\v") + 1);
                if (expressionType == "Selection")
                {
                    DoublyLinkedList list;
                    istringstream iss(line);
                    int val;
                    while (iss >> val)
                    {
                        list.link(val);
                    }
                    list.selectionSort(output);
                }
                else if (expressionType == "Insertion")
                {
                    DoublyLinkedList list;
                    istringstream iss(line);
                    int val;
                    while (iss >> val)
                    {
                        list.link(val);
                    }
                    list.insertionSort(output);
                }
                else
                {
                    output << "Input is invalid." << endl;
                }
            }
            else
            {
                output << "Input is invalid." << endl;
            }
        }
    }
    else
    {
        output << "Input is invalid." << endl;
    }

    input.close();
    output.close();
    return 0;
}
