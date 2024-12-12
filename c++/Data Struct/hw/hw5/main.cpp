#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>

using namespace std;

// struct node
struct node
{
    int val;
    node *left;
    node *right;
    node(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// class avl
class avl
{
public:
    // Constructor
    int getHeight(node *curr)
    {
        if (curr == nullptr)
            return -1;

        int lh = getHeight(curr->left) + 1;
        int rh = getHeight(curr->right) + 1;

        if (lh > rh)
            return lh;
        return rh;
    }

    // Function to calculate the balance factor of a node
    int getBF(node *curr)
    {
        if (curr == nullptr)
            return 0;

        int lh = getHeight(curr->left) + 1;
        int rh = getHeight(curr->right) + 1;

        return lh - rh;
    }

    // Function to perform left rotation
    node *left(node *curr)
    {
        node *newRoot = curr->right;
        curr->right = newRoot->left;
        newRoot->left = curr;
        return newRoot;
    }

    // Function to perform right rotation
    node *right(node *curr)
    {
        node *newRoot = curr->left;
        curr->left = newRoot->right;
        newRoot->right = curr;
        return newRoot;
    }
    // Function to insert a node in the tree
    node *insert(node *curr, int x)
    {
        if (curr == nullptr)
        {
            node *temp = new node(x);
            return temp;
        }
        else if (x < curr->val)
        {
            curr->left = insert(curr->left, x);
        }
        else if (x > curr->val)
        {
            curr->right = insert(curr->right, x);
        }
        else
        {
            return curr;
        }

        int bf = getBF(curr);

        if (bf > 1 && x < curr->left->val)
        {
            return right(curr);
        }
        else if (bf < -1 && x > curr->right->val)
        {
            return left(curr);
        }
        else if (bf > 1 && x > curr->left->val)
        {
            curr->left = left(curr->left);
            return right(curr);
        }
        else if (bf < -1 && x < curr->right->val)
        {
            curr->right = right(curr->right);
            return left(curr);
        }
        return curr;
    }

    // Function to find the minimum element in the tree
    node *min(node *curr)
    {
        if (curr == nullptr)
            return curr;
        node *temp = curr;
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    // Function to remove a node from the tree
    node *remove(node *curr, int x)
    {
        if (curr == nullptr)
            return curr;
        if (x < curr->val)
            curr->left = remove(curr->left, x);
        else if (x > curr->val)
            curr->right = remove(curr->right, x);
        else
        {
            if (curr->left == nullptr && curr->right == nullptr)
            {
                delete curr;
                return nullptr;
            }
            else if (curr->left == nullptr)
            {
                node *temp = curr->right;
                delete curr;
                return temp;
            }
            else if (curr->right == nullptr)
            {
                node *temp = curr->left;
                delete curr;
                return temp;
            }
            else
            {
                node *temp = min(curr->right);
                curr->val = temp->val;
                curr->right = remove(curr->right, temp->val);
            }
        }

        int bf = getBF(curr);

        if (bf > 1 && x < curr->left->val)
        {
            return right(curr);
        }
        else if (bf < -1 && x > curr->right->val)
        {
            return left(curr);
        }
        else if (bf > 1 && x > curr->left->val)
        {
            curr->left = left(curr->left);
            return right(curr);
        }
        else if (bf < -1 && x < curr->right->val)
        {
            curr->right = right(curr->right);
            return left(curr);
        }
        return curr;
    }

    // Function to print the tree
    void print(node *curr, ofstream &output)
    {
        // If the tree is empty, print "Empty"
        if (curr == nullptr)
        {
            cout << "Empty" << endl;
            return;
        }
        queue<node *> q;
        q.push(curr);
        
        // Print the tree in level order
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                node *temp = q.front();
                q.pop();
                cout << temp->val << " ";
                output << temp->val << " ";
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
            cout << endl;
            output << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    // *** You need to open files using ArgumentManager when submitting your assignment ***
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // *** Use this if you need to test each input individually, but you need to change back to using ArgumentManager when you submit the assignment ***
    // ifstream input("input1.txt");
    // ofstream output("output1.txt");

    avl tree;
    node *root = nullptr;
    string in;

    // *** Read in the input ***
    while (input >> in)
    {
        // *** Use this if you need to test each input individually, but you need to change back to using ArgumentManager when you submit the assignment ***
        if (in.substr(0, 6) == "Insert")
        {
            cout << "inserting " << in.substr(7, in.length() - 8) << endl;
            root = tree.insert(root, stoi(in.substr(7, in.length() - 8)));
        }
        else if (in.substr(0, 6) == "Remove")
        {
            cout << "removing " << in.substr(7, in.length() - 8) << endl;
            root = tree.remove(root, stoi(in.substr(7, in.length() - 8)));
        }
    }

    tree.print(root, output);

    return 0;
}
