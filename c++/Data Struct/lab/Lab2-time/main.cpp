#include "ArgumentManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Node
{
  string data;
  Node *next;
  Node(const string &d) : data(d), next(nullptr) {}
};

class LinkedList
{
private:
  Node *head;
  Node *tail;

public:
  LinkedList() : head(nullptr), tail(nullptr) {}

  // Insert a node at the head of the list
  void insertHead(const string &data)
  {
    Node *newNode = new Node(data);
    if (!head)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }

  // Insert a node at the tail of the list
  void insertTail(const string &data)
  {
    Node *newNode = new Node(data);
    if (!head)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void insert(int position, const string &data)
  {
    if (position < 0)
    {
      return;
    }

    Node *newNode = new Node(data);

    if (position == 0)
    {
      // Insert at the head
      newNode->next = head;
      head = newNode;
      if (!tail)
      {
        tail = newNode;
      }
    }
    else
    {
      Node *current = head;
      Node *prev = nullptr;
      int index = 0;

      while (current && index < position)
      {
        prev = current;
        current = current->next;
        index++;
      }

      if (current)
      {
        prev->next = newNode;
        newNode->next = current;

        if (current == head)
        {
          head = newNode;
        }
        if (!current->next)
        {
          tail = current;
        }
      }
      else
      {
      }
    }
  }
  // Remove the node at a given position (0-based index)
  void remove(int position)
  {
    if (!head)
      return;

    if (position == 0)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      if (!head)
        tail = nullptr;
    }
    else
    {
      Node *current = head;
      Node *prev = nullptr;
      int index = 0;
      while (current && index < position)
      {
        prev = current;
        current = current->next;
        index++;
      }
      if (current)
      {
        prev->next = current->next;
        if (current == tail)
          tail = prev;
        delete current;
      }
    }
  }

  // Remove the node at the head of the list
  void removeHead()
  {
    if (!head)
      return;
    Node *temp = head;
    head = head->next;
    delete temp;
    if (!head)
      tail = nullptr;
  }

  // Remove the node at the tail of the list
  void removeTail()
  {
    Node *current = head;
    Node *prev = nullptr;
    if (current == nullptr)
    {
      return;
    }
    else if (current->next == nullptr)
    {
      head = nullptr;
    }
    else
    {
      while (current->next != nullptr)
      {
        prev = current;
        current = current->next;
      }
      prev->next = nullptr;
      delete current;
    }
  }

  // Print the data at the head of the list
  void printHead(ofstream &output)
  {
    if (!head)
      return;
    output << head->data << " " << endl;
  }

  // Print the data at the tail of the list
  void printTail(ofstream &output)
  {
    if (!tail)
      return;
    output << tail->data << " " << endl;
  }

  // Print the Data at the Postion of the list
  void printPos(ofstream &output, int position)
  {
    if (!head)
    {
      return;
    }

    Node *current = head;
    int index = 0;

    while (current && index < position)
    {
      current = current->next;
      index++;
    }

    if (current)
    {
      output << current->data << " " << endl;
    }
    else
    {
    }
  }
};

int main(int argc, char *argv[])
{
  // *** You need to open files using argumentmanager when submit your
  // assignment ***
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

  // *** Use this if you need to test each input individually, but you need to
  // change back to using argumentmanager when you submit the assignment ***
  // ifstream input("input8.txt");
  // ofstream output("output8.txt");

  LinkedList myList;

  string line;

  while (getline(input, line))
  {
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(remove(line.begin(), line.end(), '\r'), line.end());

    if (line.find("Insert Head") == 0)
    {
      string data = line.substr(12);
      myList.insertHead(data);
    }
    else if (line.find("Insert Tail") == 0)
    {
      string data = line.substr(12);
      myList.insertTail(data);
    }
    else if (line.find("Insert") == 0)
    {

      // Find the position by looking for the first space
      size_t spacePos = line.find(" ");

      if (spacePos != string::npos)
      {
        string positionStr = line.substr(spacePos + 1);
        try
        {
          // Extract the integer position
          int position = stoi(positionStr);

          // Find the last space (data separator)
          size_t lastSpacePos = line.rfind(" ");
          if (lastSpacePos != string::npos)
          {
            string data = line.substr(lastSpacePos + 1);
            myList.insert(position, data);
          }
          else
          {
          }
        }
        catch (const invalid_argument &e)
        {
        }
      }
    }

    else if (line.find("Remove Head") == 0)
    {
      myList.removeHead();
    }
    else if (line.find("Remove Tail") == 0)
    {
      myList.removeTail();
    }
    if (line.find("Remove") == 0)
    {
      int position;
      // Find the position of the space character in the string
      size_t spacePos = line.find(" ");
      if (spacePos != string::npos)
      {
        // Extract the substring after the space
        string numberStr = line.substr(spacePos + 1);
        // Convert the extracted substring to an integer using stoi with error handling
        try
        {
          position = stoi(numberStr);
        }
        catch (const invalid_argument &e)
        {
          // Handle the error, e.g., by ignoring the invalid command or exiting the program
        }
        catch (const out_of_range &e)
        {
          // Handle the error, e.g., by ignoring the invalid command or exiting the program
        }
      }
      myList.remove(position);
    }
    else if (line.find("Print [Head]") == 0)
    {
      myList.printHead(output);
    }
    else if (line.find("Print [Tail]") == 0)
    {
      myList.printTail(output);
    }
    else if (line.find("Print [") == 0)
    {
      // Find the position enclosed in square brackets
      size_t openBracketPos = line.find("[");
      size_t closeBracketPos = line.find("]");

      if (openBracketPos != string::npos && closeBracketPos != string::npos)
      {
        string positionStr = line.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);
        try
        {
          int position = stoi(positionStr);
          myList.printPos(output, position); // Call the printPos function with the specified position
        }
        catch (const invalid_argument &e)
        {
        }
      }
    }
  }

  input.close();
  output.close();
  return 0;
}