#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "ArgumentManager.h"

using namespace std;

class HashTable
{
private:
    int *table;
    int size;
    string probingType;

public:
    HashTable(int tableSize, string type)
    {
        size = tableSize;
        probingType = type;
        table = new int[size];
        fill(table, table + size, -1);
    }

    int hash(int key, int i)
    {
        if (probingType == "Linear probing")
        {
            return (key + i) % size;
        }
        else if (probingType == "Quadratic probing")
        {
            return (key + i * i) % size;
        }
        return -1;
    }

    void insert(int key)
    {
        if (probingType == "Linear probing")
        {
            int i = 0;
            int index;
            do
            {
                index = (key + i) % size;
                if (table[index] == -1)
                {
                    table[index] = key;
                    return;
                }
                i++;
            } while (i < size);
        }
        else if (probingType == "Quadratic probing")
        {
            int i = 0;
            int index;
            do
            {
                index = (key + i * i) % size;
                if (table[index] == -1)
                {
                    table[index] = key;
                    return;
                }
                i++;
            } while (i < size);
        }
    }

    bool search(int key)
    {
        int i = 0;
        int index;
        do
        {
            index = hash(key, i);
            if (table[index] == key)
            {
                return true;
            }
            i++;
        } while (i < size);
        return false;
    }

    int *getTable()
    {
        return table;
    }

    void linear(int key)
    {
        int i = 0;
        int index;
        do
        {
            index = hash(key, i);
            if (table[index] == -1)
            {
                table[index] = key;
                break;
            }
            i++;
        } while (i < size);
    }

    void quad(int key, int c1 = 3, int c2 = 5)
    {
        int initialIndex = key % size;
        int index = initialIndex;

        if (table[index] == -1)
        {
            table[index] = key;
            return;
        }

        cout << "Collision occurred at index: " << initialIndex << ". Quadratic probing sequence: ";
        for (int i = 1; i < size; i++)
        {
            index = (initialIndex + c1 * i + c2 * i * i) % size;
            cout << index << " ";
            if (table[index] == -1)
            {
                table[index] = key;
                cout << endl;
                return;
            }
        }

        cout << "Unable to insert element " << key << ". Hash table is full." << endl;
    }

    int numAtIndex(int index)
    {
        return table[index];
    }

    void printTable(ofstream &output)
    {
        for (int i = 0; i < size; ++i)
        {
            output << table[i];
            if (i < size - 1)
            {
                output << ",";
            }
        }
        output << endl;
    }
};

void heapify(int array[], int n, int i)
{
    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && array[l] < array[min])
    {
        min = l;
    }
    if (r < n && array[r] < array[min])
    {
        min = r;
    }
    if (min != i)
    {
        swap(array[i], array[min]);
        heapify(array, n, min);
    }
}

void heapSort(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }
}

void printHeap(int array[], int n, ofstream &output)
{
    for (int i = 0; i < n; ++i)
    {
        output << array[i];
        if (i < n - 1)
        {
            output << ",";
        }
    }
    output << endl;
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

    int tableSize;
    string probingType;
    string integerList;

    input >> tableSize;
    input.ignore();
    getline(input, probingType);
    getline(input, integerList);

    HashTable hashTable(tableSize, probingType);

    vector<int> numbers;
    istringstream streams(integerList);
    int num;

    while (streams >> num)
    {
        if (streams.peek() == ',')
            streams.ignore();
        numbers.push_back(num);
    }

    if (probingType == "Quadratic probing") {
        for (int num : numbers) {
            hashTable.quad(num); // Use quad method for quadratic probing
        }
    } else {
        for (int num : numbers) {
            hashTable.insert(num); // Use insert method for linear probing
        }
    }

    int *hashTableArray = hashTable.getTable();
    hashTable.printTable(output);

    heapSort(hashTableArray, tableSize);
    printHeap(hashTableArray, tableSize, output);

    delete[] hashTableArray;

    input.close();
    output.close();
    return 0;
}