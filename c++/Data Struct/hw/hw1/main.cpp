#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "ArgumentManager.h"

using namespace std;

void findLargestPermutation(vector<int> &nums, string &permutation)
{
    if (nums.empty())
    {
        return; // Base case: No more numbers to consider
    }
    else
    {
        string largest = to_string(nums[0]);
        int largestIndex = 0;

        // Find the largest number in the current list
        for (int i = 1; i < nums.size(); ++i)
        {
            string current = to_string(nums[i]);
            if (current + largest > largest + current)
            {
                largest = current;
                largestIndex = i;
            }
            // if (nums[i] % 10  > current % 10)
            //     largest = nums[i];
        }

        permutation += largest;

        nums.erase(nums.begin() + largestIndex);

        // Recursively find the next largest number
        findLargestPermutation(nums, permutation);
    }
}

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // test input
    // ifstream input("input3.txt");
    // ofstream output("output3.txt");

    if (!input)
    {
        cout << "Input file not found" << endl;
        exit(1);
    }

    vector<int> numbers;
    int num;

    // Read numbers from input file
    while (input >> num)
    {
        numbers.push_back(num);
    }

    string largestPermutation = "";

    findLargestPermutation(numbers, largestPermutation);

    // Write the largest permutation to the output file
    output << largestPermutation << endl;

    return 0;
}
