/* Leetcode - 208. Implement Trie (Prefix Tree) (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();


class Trie 
{
private:
    vector<string> trieVector {};
public:
    Trie() = default;
    ~Trie() = default;

    void insert(string word)
    {
        trieVector.push_back(word);
    }

    bool search(string word) 
    {
        for (string stringVar : trieVector)
        {
            if (stringVar == word)
            {
                return true;
            }
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        for (string stringVar : trieVector)
        {
            string substrVar = stringVar.substr(0, prefix.size());
            if (prefix == substrVar)
            {
                return true;
            }
        }
        return false; 
    }
};

int main()
{
    yellow();

    cout << "Leetcode - 208. Implement Trie (Prefix Tree) (C++ language) - Medium" << endl;

    green();

    cout << "Test 1: ";

    reset();

    Trie trie = Trie();
    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << " ";
    cout << boolalpha << trie.search("app") << " ";     
    cout << boolalpha << trie.startsWith("app") << " "; 
    trie.insert("app");
    cout << boolalpha << trie.search("app") << " | ";

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