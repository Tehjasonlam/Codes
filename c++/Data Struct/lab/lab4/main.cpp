#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "ArgumentManager.h"

using namespace std;

struct Door
{
  bool isOpen;
  bool isLocked;

  Door() : isOpen(false), isLocked(false) {}
};

class Queue
{
private:
  struct Node
  {
    int prio;
    string cmd;
    Node *next;
  };
  Node *head;

public:
  Queue() : head(nullptr) {}

  string getHead()
  {
    return head->cmd;
  }

  bool isEmpty()
  {
    return head == nullptr;
  }

  void insertHead(int x, string y);
  void insertTail(int x, string y);
  void insertPosition(int x, string y);
  void deleteHead();
  void print();
};

void Queue::insertHead(int x, string y)
{
  Node *new_head = new Node;
  new_head->prio = x;
  new_head->cmd = y;

  if (isEmpty())
  {
    head = new_head;
  }
  else
  {
    new_head->next = head;
    head = new_head;
  }
}

void Queue::deleteHead()
{
  Node *temp = head;
  if (head->next == nullptr)
  {
    delete temp;
    head = nullptr;
  }
  else
  {
    head = head->next;
    delete temp;
  }
}

void Queue::insertTail(int x, string y)
{
  Node *new_tail = new Node;
  new_tail->prio = x;
  new_tail->cmd = y;

  if (isEmpty())
  {
    head = new_tail;
  }
  else
  {
    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = new_tail;
  }
}

void Queue::insertPosition(int x, string y)
{
  Node *new_node = new Node;
  new_node->cmd = y;
  new_node->prio = x;

  if (isEmpty())
  {
    insertHead(x, y);
  }

  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }

  if (x < head->prio)
  {
    insertHead(x, y);
  }
  else if (x > tail->prio)
  {
    insertTail(x, y);
  }
  else
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      if (temp->next != nullptr && x > temp->prio && x < temp->next->prio)
      {
        Node *temp1 = temp->next;
        temp->next = new_node;
        new_node->next = temp1;
        break;
      }
      temp = temp->next;
    }
  }
}

void Queue::print()
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->cmd << " " << temp->prio << endl;
    temp = temp->next;
  }
}

bool isValidLine(string input)
{
  int close = input.find("closethedoor");
  int open = input.find("openthedoor");
  int lock = input.find("lockthedoor");
  int unlock = input.find("unlockthedoor");
  if (input.find('(') == 0)
    return false;
  if (input.find('(') == string::npos)
    return false;
  if (close == string::npos && open == string::npos && lock == string::npos && unlock == string::npos)
    return false;
  return true;
}

int main(int argc, char *argv[])
{
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

  // ifstream input("input1.txt");
  // ofstream output("output1.txt");

  string line;
  Door h_door;
  Queue queue;

  while (getline(input, line))
  {
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    if (isValidLine(line))
    {
      string cmd = line.substr(0, line.find('('));
      int num = stoi(line.substr(line.find('(') + 1, line.find(')') - 1));
      queue.insertPosition(num, cmd);
    }
  }

  while (!queue.isEmpty())
  {
    string curr_cmd = queue.getHead();
    if (h_door.isLocked)
    {
      if (curr_cmd.find("unlock") != string::npos)
      {
        h_door.isLocked = false;
      }
    }
    else if (!h_door.isLocked)
    {
      if (curr_cmd.find("lock") != string::npos && curr_cmd.find("unlock") == string::npos)
      {
        h_door.isLocked = true;
      }
      else if (curr_cmd.find("open") != string::npos)
      {
        h_door.isOpen = true;
      }
      else if (curr_cmd.find("close") != string::npos)
      {
        h_door.isOpen = false;
      }
    }
    queue.deleteHead();
  }

  if (h_door.isOpen)
  {
    output << "the door is open";
  }
  else
  {
    output << "the door is closed";
  }

  return 0;
}
