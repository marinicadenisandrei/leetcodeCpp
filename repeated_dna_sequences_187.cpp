/* Leetcode - 187. Repeated DNA Sequences (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> findRepeatedDnaSequences(string sVar);
int countOccurrences(const std::string& str, const std::string& sub);
bool stringInArray(vector<string> &arrayStr, string strVar);
void printArrayOfStr(vector<string> arrayStr);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 187. Repeated DNA Sequences (C++ language) - Medium" << endl;

    vector<string> s = {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT","AAAAAAAAAAAAA"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printArrayOfStr(findRepeatedDnaSequences(s[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printArrayOfStr(vector<string> arrayStr)
{
    for (int i = 0; i < arrayStr.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << arrayStr[i] << ((i < arrayStr.size() - 1) ? ", " : "] | ");
    }
    
}

vector<string> findRepeatedDnaSequences(string sVar)
{
    int index = 0;
    vector<string> result {};

    while (index < (sVar.size() - 11))
    {
        string substring = sVar.substr(index, 10);
        if (countOccurrences(sVar, substring) > 1 && !stringInArray(result, substring))
        {
            result.push_back(substring);
        }

        index++;
    }

    return result;
}

bool stringInArray(vector<string> &arrayStr, string strVar)
{
    for (string str : arrayStr)
    {
        if (str == strVar)
        {
            return true;
        }
    }
    
    return false;
}

int countOccurrences(const std::string& str, const std::string& sub) {
    int count = 0;
    size_t pos = str.find(sub);
    
    while (pos != std::string::npos) {
        ++count;
        pos = str.find(sub, pos + 1);
    }
    
    return count;
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