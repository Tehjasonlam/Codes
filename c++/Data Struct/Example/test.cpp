#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

struct Credential
{
    string name;
    int age;
    int deposit;
    int numDrinks;

    Credential(const string &n, int a, int d, int drinks)
        : name(n), age(a), deposit(d), numDrinks(drinks) {}
};

// Define a structure to represent a node in the linked list
struct Node
{
    Credential data;
    Node *next;

    Node(const Credential &cred)
        : data(cred), next(nullptr) {}
};

// Function to add a credential to the linked list
void addCredential(Node *&head, const Credential &newCredential)
{
    Node *newNode = new Node(newCredential);
    newNode->next = head;
    head = newNode;
}


// Function to display the credentials in the linked list and write to an output file
void displayCredentials(const Node *head, ostream &output)
{
    const Node *current = head;
    while (current != nullptr)
    {
        const Credential &cred = current->data;
        output << "[name: " << cred.name << "; age: " << cred.age
               << "; deposit: " << cred.deposit << "; number of drinks: " << cred.numDrinks << "]\n";
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    // *** You need to open files using argumentmanager when submit your assignment ***
    ArgumentManager am(argc, argv);
    // ifstream input(am.get("input"));
    // ofstream output(am.get("output"));

    // *** Use this if you need to test each input individually, but you need to change back to using argumentmanager when you submit the assignment ***
    ifstream input("input1.txt");
    ofstream output("output1.txt");
    ifstream commandFile("command1.txt");

    Node *head = nullptr; // Initialize the linked list as empty

    if (!input.is_open())
    {
        cerr << "Failed to open input file." << endl;
        return 1; // Return an error code
    }
    if (!output.is_open())
    {
        cerr << "Failed to open output file." << endl;
        return 1; // Return an error code
    }

    // Read credentials from the input file and store them in the linked list
    string in;
    while (getline(input, in))
    {
        in.erase(remove(in.begin(), in.end(), '\n'), in.end());
        in.erase(remove(in.begin(), in.end(), '\r'), in.end());

        // Parse the in to extract credential attributes
        size_t namePos = in.find("name: ");
        size_t agePos = in.find("age: ");
        size_t depositPos = in.find("deposit: ");
        size_t drinksPos = in.find("number of drinks: ");

        // Extract credential attributes
        if (namePos == string::npos || agePos == string::npos || depositPos == string::npos || drinksPos == string::npos)
        {
            cerr << "Invalid input format: " << in << endl;
            continue; // Skip invalid ins
        }

        string name = in.substr(namePos + 6, agePos - namePos - 6);
        int age = stoi(in.substr(agePos + 5, depositPos - agePos - 5));
        int deposit = stoi(in.substr(depositPos + 8, drinksPos - depositPos - 8));
        int numDrinks = stoi(in.substr(drinksPos + 18));

        // Create a new Credential object and add it to the linked list
        Credential newCredential(name, age, deposit, numDrinks);
        addCredential(head, newCredential);
    }

    
    displayCredentials(head, output);

    // Clean up the linked list (free memory)
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Close the input file, output file, and command file.
    input.close();
    output.close();

    return 0;
}