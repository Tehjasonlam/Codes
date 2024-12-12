#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

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

class bst
{
private:
    node *root;

public:
    bst()
    {
        root = nullptr;
    }

    node *getRoot()
    {
        return root;
    }

    void insert(node *curr, int x)
    {
        if (root == nullptr)
        {
            root = new node(x);
            return;
        }
        else if (x < curr->val)
        {
            if (curr->left == nullptr)
                curr->left = new node(x);
            else
                insert(curr->left, x);
        }
        else if (x > curr->val)
        {
            if (curr->right == nullptr)
                curr->right = new node(x);
            else
                insert(curr->right, x);
        }
    }

    node *min(node *root)
    {
        if (root == nullptr)
            return root;
        node *curr = root;
        while (curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    node *max(node *root)
    {
        if (root == nullptr)
            return root;
        node *curr = root;
        while (curr->right != nullptr)
            curr = curr->right;
        return curr;
    }

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
                if (curr == root)
                    root = nullptr;
                return nullptr;
            }
            else if (curr->left == nullptr)
            {
                node *temp = curr->right;
                if (curr == root)
                    root = temp;
                delete curr;
                return temp;
            }
            else if (curr->right == nullptr)
            {
                node *temp = curr->left;
                if (curr == root)
                    root = temp;
                delete curr;
                return temp;
            }
            else
            {
                node *temp = max(curr->left);
                curr->val = temp->val;
                curr->left = remove(curr->left, temp->val);
            }
        }
        return curr;
    }

    void inorder(node *curr, string *x)
    {
        if (curr == nullptr)
            return;
        inorder(curr->left, x);
        *x += to_string(curr->val) + " ";
        inorder(curr->right, x);
    }

    void preorder(node *curr, string *x)
    {
        if (curr == nullptr)
            return;
        *x += to_string(curr->val) + " ";
        preorder(curr->left, x);
        preorder(curr->right, x);
    }

    void postorder(node *curr, string *x)
    {
        if (curr == nullptr)
            return;
        postorder(curr->left, x);
        postorder(curr->right, x);
        *x += to_string(curr->val) + " ";
    }

    int compareTraversal(const string &input, const string &traversal)
    {
        if (input == traversal)
            return 0;
        size_t pos = traversal.find(input);
        if (pos == 0)
            return 1; // input is a prefix of traversal
        return -1;    // no match
    }
};

int main(int argc, char *argv[])
{
    // *** You need to open files using argumentmanager when submit your assignment ***
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // *** Use this if you need to test each input individually, but you need to change back to using argumentmanager when you submit the assignment ***
    // ifstream input("input1.txt");
    // ofstream output("output1.txt");

    bst tree;
    string in;
    string num;
    string search;
    string preorder;
    string inorder;
    string postorder;

    while (!input.eof())
    {
        num = "";
        getline(input, in);
        cout << in << endl;
        if (!in.empty() && (in[in.size() - 1] == '\r' || in[in.size() - 1] == '\n'))
            in.erase(in.size() - 1);
        if (in == "Insert")
        {
            cout << "inserting" << endl;
            getline(input, in);

            if (!in.empty() && (in[in.size() - 1] == '\r' || in[in.size() - 1] == '\n'))
                in.erase(in.size() - 1);

            in += " ";
            cout << "values: " << in << endl;
            for (int i = 0; i < in.length(); i++)
            {
                if (in[i] != ' ')
                {
                    num += in[i];
                }
                else
                {
                    cout << "insert: " << num << endl;
                    tree.insert(tree.getRoot(), stoi(num));
                    num = "";
                }
            }
        }
        else if (in == "Traverse")
        {
            cout << "traversing" << endl;
            getline(input, in);

            if (!in.empty() && (in[in.size() - 1] == '\r' || in[in.size() - 1] == '\n'))
                in.erase(in.size() - 1);

            in += " ";
            cout << "search: " << in << endl;

            search = "";
            tree.inorder(tree.getRoot(), &search);
            inorder = search;
            cout << "inorder: " << inorder << endl;

            search = "";
            tree.preorder(tree.getRoot(), &search);
            preorder = search;
            cout << "preorder: " << preorder << endl;

            search = "";
            tree.postorder(tree.getRoot(), &search);
            postorder = search;
            cout << "postorder: " << postorder << endl;

            if (in == inorder)
            {
                output << "Inorder" << endl;
                cout << "Matches inorder" << endl;
            }
            if (in == preorder)
            {
                output << "Preorder" << endl;
                cout << "Matches preorder" << endl;
            }
            if (in == postorder)
            {
                output << "Postorder" << endl;
                cout << "Matches postorder" << endl;
            }
            if (in != inorder && in != preorder && in != postorder)
            {
                output << "False" << endl;
                cout << "FALSE MATCH" << endl;
            }
        }
        else if (in == "Remove")
        {
            cout << "removing" << endl;
            getline(input, in);

            if (!in.empty() && (in[in.size() - 1] == '\r' || in[in.size() - 1] == '\n'))
                in.erase(in.size() - 1);

            in += " ";
            cout << "values: " << in << endl;
            for (int i = 0; i < in.length(); i++)
            {
                if (in[i] != ' ')
                {
                    num += in[i];
                }
                else
                {
                    cout << "remove: " << num << endl;
                    tree.remove(tree.getRoot(), stoi(num));
                    num = "";
                }
            }
        }
    }
}