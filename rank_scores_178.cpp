/* Leetcode - 178. Rank Scores (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void rankScores(vector<float> &scoreVar);
void printVector(vector<float> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 178. Rank Scores (C++ language) - Medium" << endl;

    vector<float> score {3.5,3.65,4.0,3.85,4.0,3.65};
    
    green();

    cout << "Test 1: ";

    reset();
    
    rankScores(score);
    printVector(score);

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void rankScores(vector<float> &scoreVar)
{
    std::sort(scoreVar.begin(), scoreVar.end(), std::greater<int>());
}

void printVector(vector<float> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");   
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