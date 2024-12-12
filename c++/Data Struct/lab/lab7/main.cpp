#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "ArgumentManager.h"

using namespace std;

//
bool hasloop(int **graph, int source, int size)
{
    queue<int> q;
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;
    q.push(source);
    int v;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (!visited[v])
        {
            visited[v] = true;
        }
        for (int i = 0; i < size; i++)
        {
            if (graph[v][source])
            {
                return true;
            }
            if (graph[v][i] != 0 && !visited[i])
                q.push(i);
        }
    }

    delete[] visited;
    return false;
}

int main(int argc, char *argv[])
{
    // *** You need to open files using argumentmanager when submit your assignment ***
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // *** Use this if you need to test each input individually, but you need to change back to using argumentmanager when you submit the assignment ***
    // ifstream input("input2.txt");
    // ofstream output("output2.txt");

    int num;
    input >> num;

    //
    int **graph = new int *[num];
    for (int i = 0; i < num; i++)
    {
        graph[i] = new int[num]();
    }

    int n1, n2;
    while (input >> n1 >> n2)
    {
        graph[n1][n2] = 1;
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    bool result = false;
    for (int i = 0; i < num; i++)
    {
        if (hasloop(graph, i, num))
            result = true;
    }

    if (result)
    {
        output << "TRUE" << endl;
    }
    else
    {
        output << "FALSE" << endl;
    }

    for (int i = 0; i < num; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}