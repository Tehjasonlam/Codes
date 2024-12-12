#include <iostream>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

struct Node{
  int value;
  Node *left;
  Node *right;
  Node(int val): value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into BST
Node *insert(Node *root, int value){
  if(root == nullptr){
    return new Node(value);
  }
  if(value < root->value){
    root->left = insert(root->left, value);
  } else{
    root->right = insert(root->right, value);
  }
  return root;
}

// Function to perform preorder traversal and print nodes
void preorderTraversal(Node *root, const string &location, ofstream &output){
  if(root != nullptr){
    output << "[" << location << "] " << root->value << endl;
    preorderTraversal(root->left, location + "l", output);
    preorderTraversal(root->right, location + "r", output);
  }
}

int main(int argc, char* argv[]){

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
  // ifstream input("input.txt"); //just me testing
  // ofstream output("output.txt");

  Node *root = nullptr;
  int number;
  while(input >> number){
    root = insert(root, number);
  }
  cout << "Root Value: " << root->value << endl;
  preorderTraversal(root, "x", output);

  
}