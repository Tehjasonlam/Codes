#include "ArgumentManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

struct node
{
    string id;
    node *next;
};

class bar
{
private:
    node *head;

public:
    bar() { head = nullptr; }
    int getSize(node *);
    node *getHead();
    node *addInOrder(node *, string);
    void addAtHead(string);
    void printBar(node *);
    void getDuplicates(node *, node *);
    void checkID(string, node *);
    void removeRepeats(node *);
    void removeCommon(node *, node *);
    void printOutput(ofstream &, node *);
};

int bar::getSize(node *cur)
{
    if (cur == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + getSize(cur->next);
    }
}

node *bar::getHead() { return head; }

// RECURSIVELY ADD A NODE IN ASCENDING ORDER
node *bar::addInOrder(node *h, string id)
{
    if (head == nullptr)
    {
        node *temp = new node;
        temp->id = id;
        temp->next = nullptr;
        head = temp;
        return temp;
    }
    if (stoi(id) < stoi(head->id))
    {
        node *temp = new node;
        temp->id = id;
        temp->next = head;
        head = temp;
        return temp;
    }
    if (h == nullptr)
    {
        node *temp = new node;
        temp->id = id;
        temp->next = nullptr;

        return temp;
    }
    if (stoi(id) > stoi(h->id))
    {
        h->next = addInOrder(h->next, id);
        return h;
    }
    else
    {
        node *temp = new node;
        temp->id = id;
        temp->next = h;

        return temp;
    }
}

void bar::addAtHead(string id)
{
    if (head == nullptr)
    {
        return;
    }
    node *temp = new node;
    temp->id = id;
    temp->next = nullptr;
    temp->next = head;
    head = temp;

    return;
}

void bar::printBar(node *h)
{
    if (h == nullptr)
    {
        return;
    }
    else
    {
        printBar(h->next);
    }
}

void bar::getDuplicates(node *b1, node *b2)
{
    if (b1 == nullptr || b2 == nullptr)
    {
        return;
    }
    else if (stoi(b1->id) == stoi(b2->id))
    {
        addInOrder(head, b1->id);
        getDuplicates(b1->next, b2->next);
        return;
    }
    else if (stoi(b1->id) < stoi(b2->id))
    {
        getDuplicates(b1->next, b2);
    }
    else
    {
        getDuplicates(b1, b2->next);
    }
}

void bar::checkID(string id, node *bar)
{
    if (bar == nullptr)
    {
        return;
    }
    else if (id == bar->id)
    {

        addInOrder(head, id);
        return;
    }
    else
    {
        checkID(id, bar->next);
    }
}

// Removes repeated nodes within a single list
void bar::removeRepeats(node *head)
{
    if (head != nullptr && head->next != nullptr)
    {
        if (head->id == head->next->id)
        {
            node *temp = head->next;
            head->next = temp->next;
            delete temp;
            removeRepeats(head);
        }
        else
        {
            removeRepeats(head->next);
        }
    }
}

// Remove any IDs appearing in guilty from innocent
void bar::removeCommon(node *l1, node *l2)
{
    if (l1 == nullptr && l2 == nullptr)
    {
        return;
    }
    else if (l2 == nullptr)
    {
        addInOrder(head, l1->id);
        removeCommon(l1->next, l2);
        return;
    }
    else if (l1 == nullptr)
    {
        addInOrder(head, l2->id);
        removeCommon(l1, l2->next);
        return;
    }
    else if (stoi(l1->id) < stoi(l2->id))
    {
        addInOrder(head, l1->id);
        removeCommon(l1->next, l2);
    }
    else if (stoi(l1->id) > stoi(l2->id))
    {
        addInOrder(head, l2->id);
        removeCommon(l1, l2->next);
    }
    else
    { // Only occurs if l1->id == l2->id
        removeCommon(l1->next, l2->next);
        return;
    }
}

void bar::printOutput(ofstream &output, node *list)
{
    if (list == nullptr)
    {
        return;
    }
    output << list->id << endl;
    printOutput(output, list->next);
}

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // ifstream input("input2.txt");
    // ofstream output("output2.txt");

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

    bar bar1;
    bar bar2;
    bar all;
    bar innocent;
    bar guilty;
    stack<int> stack;
    string lineIn, decoded, digit;
    int barNum = 0; // Tracks which bar the subsequent IDs belong to

    // Begin parsing IDs from each bar
    while (getline(
        input, lineIn))
    { // Gets current line from input file with each iteration
        if (lineIn.substr(0, 3) ==
            "Bar")
        { // Checks first if current line specifies a bar
            barNum = stoi(lineIn.substr(3, 1));
        }
        else
        {
            // Decode ID
            for (int i = 0; i < lineIn.length();
                 i++)
            { // Parse through each char in ID
                digit = lineIn[i];
                //  Check if an open or close parenthesis occurs
                if (digit == "(")
                {
                    stack.push(i);
                }
                else if (digit == ")")
                {
                    reverse(lineIn.begin() + stack.top() + 1, lineIn.begin() + i);
                    stack.pop();
                }
            }
            decoded = "";
            for (int i = 0; i < lineIn.length(); i++)
            {
                if (lineIn[i] != ')' && lineIn[i] != '(')
                {
                    decoded = decoded + lineIn[i];
                }
            }
            if (decoded != "")
            {
                switch (barNum)
                { // Add ID to appropriate bar based on barNum
                case 1:
                    // Check first if this ID has been added to Bar1 before
                    guilty.checkID(decoded, bar1.getHead());

                    bar1.addInOrder(bar1.getHead(), decoded);
                    all.addInOrder(all.getHead(), decoded);

                    bar1.printBar(bar1.getHead());
                    break;
                case 2:
                    // Check first if this ID has been added to Bar2 before
                    guilty.checkID(decoded, bar2.getHead());

                    bar2.addInOrder(bar2.getHead(), decoded);
                    all.addInOrder(all.getHead(), decoded);

                    bar2.printBar(bar2.getHead());
                    break;
                default:
                    break;
                }
            }
        }
    }

    bar1.printBar(bar1.getHead());
    bar2.printBar(bar2.getHead());

    // Add any duplicates between Bar1 and Bar2 to guilty
    guilty.getDuplicates(bar1.getHead(), bar2.getHead());
    guilty.printBar(guilty.getHead());
    innocent.printBar(all.getHead());

    // Remove any repeats from innocent and guilty

    guilty.removeRepeats(guilty.getHead());
    innocent.removeRepeats(all.getHead());
    guilty.printBar(guilty.getHead());
    innocent.printBar(all.getHead());

    // Remove common elements between innocent and guilty

    innocent.removeCommon(all.getHead(), guilty.getHead());
    guilty.printBar(guilty.getHead());
    innocent.printBar(innocent.getHead());

    // Print final output
    if (guilty.getHead() != nullptr)
    {
        output << "Guilty:" << endl;
    }
    guilty.printOutput(output, guilty.getHead());
    if (innocent.getHead() != nullptr)
    {
        output << "Innocent:" << endl;
    }
    innocent.printOutput(output, innocent.getHead());
}