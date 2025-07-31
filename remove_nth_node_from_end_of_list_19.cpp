/* Leetocde - 19. Remove Nth Node From End of List - Medium */

#include <iostream>
#include <vector>

using namespace std;

void removeNthElement(vector <int> &vectorVar, int nthElement);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetocde - 19. Remove Nth Node From End of List - Medium" << endl;

    vector <vector <int>> head {{1,2,3,4,5}, {1}, {1,2}};
    vector <int> n {2, 1, 1};

    for (int test = 0; test < head.size(); test++)
    {
        removeNthElement(head.at(test), n.at(test));

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(head.at(test));  

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void removeNthElement(vector <int> &vectorVar, int nthElement)
{
    auto iteratorToRemove {vectorVar.end() - nthElement};
    vectorVar.erase(iteratorToRemove);
}

void printVector(vector <int> vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
        return;
    }

    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
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


