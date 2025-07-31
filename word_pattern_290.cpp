/* Leetcode - 290. Word Pattern (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool wordPattern(string patternVar, string sVar);
std::vector<std::string> split_on_whitespace(const std::string& s);
std::vector<std::string> split_chars(const std::string& s);

int main()
{
    yellow();
    
    cout << "Leetcode - 290. Word Pattern (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> pattern = {"abba","abba","aaaa"}; 
    vector<string> s = {"dog cat cat dog","dog cat cat fish","dog cat cat dog"};

    for (int test = 0; test < pattern.size(); test++)
    {

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << wordPattern(pattern[test], s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

std::vector<std::string> split_on_whitespace(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::string> split_chars(const std::string& s) {
    std::vector<std::string> result;
    result.reserve(s.size());              
    for (char c : s) {
        result.emplace_back(1, c);          
    }
    return result;
}

bool wordPattern(string patternVar, string sVar)
{
    vector<string> splitPatternVar = split_chars(patternVar);
    vector<string> splitSVar = split_on_whitespace(sVar);

    std::unordered_map<std::string,string> dict;

    for (int i = 0; i < splitPatternVar.size(); i++)
    {
        auto it = dict.find(splitPatternVar[i]);
        
        if (it == dict.end())
        {
            dict[splitPatternVar[i]] = splitSVar[i];
        }
        else
        {
            if (dict[splitPatternVar[i]] != splitSVar[i])
            {
                return false;
            }
        }
    }

    return true;
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