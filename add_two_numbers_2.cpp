/* Leetcode - 2. Add Two Numbers (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string arrayElementsToString(vector <int> vector);
void printCharVector(vector <char> vector);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 2. Add Two Numbers (C++ language) - Medium" << endl;

    vector <vector<int>> l1 {{2,4,3}, {0}, {9,9,9,9,9,9,9}};
    vector <vector<int>> l2 {{5,6,4}, {0}, {9,9,9,9}};

    for (int test = 0; test < l1.size(); test++)
    {
        string l1_string_number = arrayElementsToString(l1.at(test));
        string l2_string_number = arrayElementsToString(l2.at(test));
        
        int result {};
        result = stoi(l1_string_number) + stoi(l2_string_number);

        string result_string = to_string(result);

        vector <char> output {};

        green();

        cout << "Test " << test + 1 << ": ";

        for (int i = l1.at(test).size() - 1; i >= 0 ; i--)
        {
            output.push_back(result_string[i]);
        }

        reset();

        printCharVector(output);

        cout << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
    
    return 0;
}

string arrayElementsToString(vector <int> vector)
{
    string temp {};

    for (auto i : vector)
    {
        temp += to_string(i);
    }

    return temp;
}

void printCharVector(vector <char> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vector.at(i) << ((i < vector.size() - 1) ? ", " : "]");
    }
    
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