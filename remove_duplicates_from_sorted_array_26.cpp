/* Leetcode - 26. Remove Duplicates from Sorted Array (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector <int> &vectorVar);
bool elementInVector(vector <int> vectorVar, int element);
void copyAVectorInAnother(vector <int> firstVector, vector <int> &secondVector);
void printIntVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 26. Remove Duplicates from Sorted Array (C++ language) - ";
    
    green();

    cout << "Easy" << endl;

    vector <vector <int>> nums {{1,1,2}, {0,0,1,1,1,2,2,3,3,4}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        removeDuplicates(nums.at(test));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void removeDuplicates(vector <int> &vectorVar)
{
    vector <int> tempVector {};

    for (int i = 0; i < vectorVar.size(); i++)
    {
        if (!elementInVector(tempVector, vectorVar.at(i)))
        {
            tempVector.push_back(vectorVar.at(i));
        }
    }

    copyAVectorInAnother(tempVector, vectorVar);
    printIntVector(vectorVar);
}

bool elementInVector(vector <int> vectorVar, int element)
{
    for (auto i : vectorVar)
    {
        if (i == element)
        {
            return true;
        }
    }

    return false;
}

void copyAVectorInAnother(vector <int> firstVector, vector <int> &secondVector)
{
    secondVector.clear();

    for (int i = 0; i < firstVector.size(); i++)
    {
        secondVector.push_back(firstVector.at(i));
    }    
}

void printIntVector(const vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++) cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
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