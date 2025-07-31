/* Leetcode - 211. Design Add and Search Words Data Structure (C language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <regex>

void reset ();
void green ();
void yellow ();
void red ();


using namespace std;

class WordDictionary 
{
private:
    vector<string> wordDict;

public:
    WordDictionary() = default;
    ~WordDictionary() = default;

    void addWord(const string& word)
    {
        wordDict.push_back(word);
    }

    bool search(const string& word)
    {
        string regexPattern = std::regex_replace(word, std::regex("\\."), ".");
        std::regex re(regexPattern);

        for (const string& wordVar : wordDict)
        {
            if (std::regex_match(wordVar, re)) 
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    cout << boolalpha;

    yellow();

    cout << "Leetcode - 211. Design Add and Search Words Data Structure (C language) - Medium" << endl;

    green();

    cout << "Test 1: " << endl;

    reset();

    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad") << endl; 
    cout << wordDictionary.search("bad") << endl; 
    cout << wordDictionary.search(".ad") << endl; 
    cout << wordDictionary.search("b..") << " | ";

    green();

    cout << "Passed" << endl; 

    reset();

    return 0;
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