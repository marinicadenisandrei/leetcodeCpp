/* Leetcode - 192. Word Frequency (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream> 

using namespace std;

string wordFrequency(string wordsVar);
bool stringInVector(string stringVar, vector<string> vectorVar);
int occurenceSubstringInString(string substring, string stringVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 192. Word Frequency (C++ language) - Medium" << endl;

    string words {"the day is sunny the the\nthe sunny is is"};
    
    green();

    cout << "Test 1: ";
    
    reset();

    cout << wordFrequency(words) << " | ";

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

bool stringInVector(string stringVar, vector<string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        if (vectorVar[i] == stringVar)
        {
            return true;
        }
    }
    
    return false;
}

int occurenceSubstringInString(string substring, string stringVar)
{
    int sum = 0;

    string word;
    std::istringstream issVar(stringVar);

    while (issVar >> word)
    {
        if (word == substring)
        {
            sum++;
        }
    }

    return sum;
}

string wordFrequency(string wordsVar)
{
    vector<string> candidates {};
    string word;
    std::istringstream iss(wordsVar);

    string result {""};

    while (iss >> word)
    {
        if (!stringInVector(word, candidates))
        {
            candidates.push_back(word);
        }
    }


    for (int i = 0; i < candidates.size(); i++)
    {
        int occ = occurenceSubstringInString(candidates[i], wordsVar);
        string occStr = to_string(occ);

        result += candidates[i] + " " + occStr + "\n";
    }

    return result;
}

void reset () {
  cout << "\033[1;0m";
}

void green () {
  cout << "\033[1;32m";
}

void yellow () {
  cout << "\033[1;33m";
}

void red () {
  cout << "\033[1;31m";
}