#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <bitset>

std::mutex mtx;

void calculateFrequency(const std::string &message, std::map<char, int> &frequency)
{
    for (char ch : message)
    {
        std::lock_guard<std::mutex> lock(mtx);
        frequency[ch]++;
    }
}

void generateShannonCodes(const std::vector<std::pair<char, int>> &symbols, std::map<char, std::string> &codes, int start, int end)
{
    if (start >= end)
        return;

    // This is a simplified version, assuming binary tree split based on frequencies.
    int total = 0;
    for (int i = start; i < end; ++i)
    {
        total += symbols[i].second;
    }

    int cumulative = 0;
    int splitIndex = start;
    while (splitIndex < end && cumulative + symbols[splitIndex].second <= total / 2)
    {
        cumulative += symbols[splitIndex].second;
        splitIndex++;
    }

    // Assign codes
    for (int i = start; i < splitIndex; ++i)
    {
        codes[symbols[i].first] = "0" + codes[symbols[i].first];
    }
    for (int i = splitIndex; i < end; ++i)
    {
        codes[symbols[i].first] = "1" + codes[symbols[i].first];
    }

    // Recur for left and right subtrees
    std::thread leftThread(generateShannonCodes, std::ref(symbols), std::ref(codes), start, splitIndex);
    std::thread rightThread(generateShannonCodes, std::ref(symbols), std::ref(codes), splitIndex, end);

    leftThread.join();
    rightThread.join();
}

std::string encodeMessage(const std::string &message, const std::map<char, std::string> &codes)
{
    std::string encoded;
    for (char ch : message)
    {
        encoded += codes.at(ch);
    }
    return encoded;
}

int main()
{
    std::string message = "AAABAAABAAAAMMAAAAAU";
    std::map<char, int> frequency;

    // Calculate frequency in a separate thread
    std::thread frequencyThread(calculateFrequency, std::ref(message), std::ref(frequency));
    frequencyThread.join();

    // Prepare symbols for Shannon coding
    std::vector<std::pair<char, int>> symbols(frequency.begin(), frequency.end());
    std::sort(symbols.begin(), symbols.end(), [](const auto &a, const auto &b)
              {
                  return a.second > b.second; // Sort by frequency
              });

    std::map<char, std::string> codes;
    generateShannonCodes(symbols, codes, 0, symbols.size());

    // Output the results
    std::cout << "Message: " << message << std::endl;
    std::cout << "Alphabet: " << std::endl;
    for (const auto &pair : symbols)
    {
        std::cout << "Symbol: " << pair.first << ", Frequency: " << pair.second
                  << ", Shannon code: " << codes[pair.first] << std::endl;
    }

    std::string encodedMessage = encodeMessage(message, codes);
    std::cout << "Encoded message: " << encodedMessage << std::endl;

    return 0;
}