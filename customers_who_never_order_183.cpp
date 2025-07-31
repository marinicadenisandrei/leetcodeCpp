/*Leetcode - 183. Customers Who Never Order (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> customersWhoNeverOrder(vector<string> customersTableVar, vector<int> ordersIDVar);
void printVector(vector<string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 183. Customers Who Never Order (C++ language) - ";

    green();

    cout << "Easy" << endl;

    reset();

    vector<string> customersTable {"Joe", "Henry", "Sam", "Max"};
    vector<int> ordersID {3,1};

    green();

    cout << "Test 1: ";

    reset();

    printVector(customersWhoNeverOrder(customersTable, ordersID));

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void printVector(vector<string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<string> customersWhoNeverOrder(vector<string> customersTableVar, vector<int> ordersIDVar)
{
    vector<string> result {};

    auto indexOrder = [] (int indexID, vector<int> orderVerctor) {
        for (int i : orderVerctor)
        {
            if (i == indexID)
            {
                return true;
            }
        }
        
        return false;
    };

    for (int i = 0; i < customersTableVar.size(); i++)
    {
        if (indexOrder(i, ordersIDVar))
        {
            result.push_back(customersTableVar[i]);
        }
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