/* Leetcode - 299. Bulls and Cows (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

string getHint(string secretVar, string guessVar);
int charInString(string str, char c);


int main()
{
    yellow();

    cout << "Leetcode - 299. Bulls and Cows (C++ language) - Medium" << endl;

    vector<string> secret = {"1807","1123"};
    vector<string> guess = {"7810","0111"};

    for (int test = 0; test < secret.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << getHint(secret[test], guess[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

int charInString(string str, char c)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    
    return -1;
}

string getHint(string secretVar, string guessVar)
{
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < secretVar.size(); i++)
    {
        int index = charInString(guessVar, secretVar[i]);

        if (index == -1)
        {
            continue;
        }
        else if (index == i) 
        {
            bulls++;
        }
        else
        {
            cows++;
        }
    }

    return string(to_string(bulls) + "A" + to_string(cows) + "B");
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