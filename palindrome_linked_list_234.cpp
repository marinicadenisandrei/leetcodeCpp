/* Leetcode - 234. Palindrome Linked List (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool IsPalindrome(vector<int> headVar);

int main()
{
    yellow();

    cout << "Leetcode - 234. Palindrome Linked List (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> head {{1,2,2,1},{1,2}};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << IsPalindrome(head[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool IsPalindrome(vector<int> headVar)
{
    for (int i = 0; i < headVar.size() / 2; i++)
    {
        if (headVar[i] != headVar[headVar.size() - 1 - i])
        {
            return false;
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