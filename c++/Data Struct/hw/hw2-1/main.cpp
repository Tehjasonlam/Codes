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
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to remove credentials with a specific attribute value
void removeCredentials(Node *&head, const string &attribute, int value)
{
    Node *current = head;
    Node *prev = nullptr;

    // Debugging output to check the received attribute and value
    cout << "Checking attribute: " << attribute << ", value: " << value << endl;

    // ...

    while (current != nullptr)
    {
        // Check the specified attribute and value for removal
        if (attribute == "age" && current->data.age == value)
        {
            // Remove the node with matching age
            if (prev != nullptr)
                prev->next = current->next;
            else
                head = current->next;
            delete current;
            current = prev != nullptr ? prev->next : head;
        }
        else if (attribute == "deposit" && current->data.deposit == value)
        {
            // Remove the node with matching deposit
            if (prev != nullptr)
                prev->next = current->next;
            else
                head = current->next;
            delete current;
            current = prev != nullptr ? prev->next : head;
        }
        else if (attribute == "number of drinks" && current->data.numDrinks == value)
        {
            // Remove the node with matching numDrinks
            if (prev != nullptr)
                prev->next = current->next;
            else
                head = current->next;
            delete current;
            current = prev != nullptr ? prev->next : head;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

// Function to compare two credentials for sorting based on the specified attribute
bool compareCredentials(const Credential &cred1, const Credential &cred2, const string &attribute)
{
    if (attribute == "deposit")
    {
        return cred1.deposit < cred2.deposit;
    }
    else if (attribute == "name")
    {
        return cred1.name < cred2.name;
    }
    // Add additional cases for other attributes if needed
    else
    {
        // Default case, no sorting needed
        return false;
    }
}

// Function to sort the linked list based on the given attribute
void sortCredentials(Node *&head, const string &attribute)
{
    if (head == nullptr)
    {
        // Nothing to sort if the list is empty
        return;
    }

    Node *current = head;
    Node *sortedList = nullptr;

    while (current != nullptr)
    {
        Node *next = current->next;
        if (sortedList == nullptr || compareCredentials(current->data, sortedList->data, attribute))
        {
            // Insert at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        }
        else
        {
            // Insert elsewhere in the sorted list
            Node *prevSorted = sortedList;
            Node *sorted = sortedList->next;

            while (sorted != nullptr && !compareCredentials(current->data, sorted->data, attribute))
            {
                prevSorted = sorted;
                sorted = sorted->next;
            }

            prevSorted->next = current;
            current->next = sorted;
        }
        current = next;
    }

    // Update the head to point to the sorted list
    head = sortedList;
}

// Function to display the credentials in the linked list and write to an output file
void displayCredentials(const Node *head, ostream &output)
{
    const Node *current = head;
    while (current != nullptr)
    {
        const Credential &cred = current->data;
        output << "[name: " << cred.name << "age: " << cred.age
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
    // ifstream commandFile(am.get("command"));

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

    string command;
    while (getline(commandFile, command))
    {
        command.erase(remove(command.begin(), command.end(), '\n'), command.end());
        command.erase(remove(command.begin(), command.end(), '\r'), command.end());

        if (command.find("Add") == 0)
        {
            // Parse the Add command
            size_t openParen = command.find("(");
            size_t closeParen = command.find(")");
            if (openParen == string::npos || closeParen == string::npos)
            {
                cerr << "Invalid Add command format: " << command << endl;
                continue;
            }

            int index = stoi(command.substr(openParen + 1, closeParen - openParen - 1));
            string credentialStr = command.substr(closeParen + 2); // Extract credential data

            // Parse credentialStr to extract credential attributes
            size_t namePos = credentialStr.find("name: ");
            size_t agePos = credentialStr.find("age: ");
            size_t depositPos = credentialStr.find("deposit: ");
            size_t drinksPos = credentialStr.find("number of drinks: ");

            if (namePos == string::npos || agePos == string::npos || depositPos == string::npos || drinksPos == string::npos)
            {
                cerr << "Invalid credential format: " << credentialStr << endl;
                continue;
            }

            string name = credentialStr.substr(namePos + 6, agePos - namePos - 6);
            int age = stoi(credentialStr.substr(agePos + 5, depositPos - agePos - 5));
            int deposit = stoi(credentialStr.substr(depositPos + 8, drinksPos - depositPos - 8));
            int numDrinks = stoi(credentialStr.substr(drinksPos + 18));

            // Create a new Credential object
            Credential newCredential(name, age, deposit, numDrinks);

            // Handle adding to the linked list based on the specified index
            if (index <= 0)
            {
                // Add at the beginning of the linked list
                Node *newNode = new Node(newCredential);
                newNode->next = head;
                head = newNode;
            }
            else
            {
                Node *current = head;
                Node *prev = nullptr;
                int currentIndex = 0;

                // Traverse the list to find the appropriate position to insert
                while (current != nullptr && currentIndex < index)
                {
                    prev = current;
                    current = current->next;
                    currentIndex++;
                }

                // Add after the specified index or at the end if index is greater than list size
                Node *newNode = new Node(newCredential);
                newNode->next = current;
                if (prev != nullptr)
                {
                    prev->next = newNode;
                }
                else
                {
                    // Adding at the beginning
                    head = newNode;
                }
            }
        }
        else if (command.find("Remove (") == 0 && command.back() == ')')
        {
            // Parse the Remove command
            size_t openParen = command.find("(");
            size_t closeParen = command.find(")");
            if (openParen == string::npos || closeParen == string::npos)
            {
                cerr << "Invalid Remove command format: " << command << endl;
                continue;
            }

            string attributeValueStr = command.substr(openParen + 1, closeParen - openParen - 1);
            size_t colonPos = attributeValueStr.find(":");
            if (colonPos == string::npos)
            {
                cerr << "Invalid attribute format in Remove command: " << attributeValueStr << endl;
                continue;
            }

            string attribute = attributeValueStr.substr(0, colonPos);
            int value = stoi(attributeValueStr.substr(colonPos + 1));

            // Call the removeCredentials function to remove matching credentials
            removeCredentials(head, attribute, value);
        }
        else if (command.find("Sort") == 0)
        {
            size_t openParen = command.find("(");
            size_t closeParen = command.find(")");
            if (openParen == string::npos || closeParen == string::npos)
            {
                cerr << "Invalid Sort command format: " << command << endl;
                continue;
            }

            string attribute = command.substr(openParen + 1, closeParen - openParen - 1);

            // Call the sortCredentials function to sort the linked list based on the specified attribute
            sortCredentials(head, attribute);
        }
    }

    // Display the credentials stored in the linked list and write to the output file
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