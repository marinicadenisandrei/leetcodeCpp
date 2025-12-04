/* Leetcode - 341. Flatten Nested List Iterator (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <variant>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

struct NestedInteger {
    std::variant<int, std::vector<NestedInteger>> value;

    NestedInteger(int v) : value(v) {}
    NestedInteger(std::vector<NestedInteger> v) : value(std::move(v)) {}
};

void nestedIterator(const NestedInteger& nestedListVar, std::vector<int>& result);
void printVect(vector<int> vect);

int main()
{   
    yellow();

    cout << "Leetcode - 341. Flatten Nested List Iterator (C++ language) - Medium" << endl;

    std::vector<NestedInteger> nestedList = {
        NestedInteger(std::vector<NestedInteger>{
            std::vector<NestedInteger>{1, 1},   
            2,                                  
            std::vector<NestedInteger>{1, 1}    
        }),

        NestedInteger(std::vector<NestedInteger>{
            1,                                   
            std::vector<NestedInteger>{          
                4,                               
                std::vector<NestedInteger>{      
                    6                            
                }
            }
        })
    };

    for (int test = 0; test < nestedList.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<int> result = {};
        nestedIterator(nestedList[test], result);
        printVect(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVect(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

void nestedIterator(const NestedInteger& nestedListVar, std::vector<int>& result)
{
    if (std::holds_alternative<int>(nestedListVar.value)) {
        result.push_back(std::get<int>(nestedListVar.value));
    } else {
        for (const auto& child :
            std::get<std::vector<NestedInteger>>(nestedListVar.value)) {
            nestedIterator(child, result);
        }
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
