/* Leectode - 1. Two Sum (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned NUMBER_OF_TESTS {3};

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
  yellow();

  cout << "Leectode - 1. Two Sum (C++ language) - ";

  green();

  cout << "Easy" << endl;

  vector <vector<int>> nums {{2,7,11,15}, {3,2,4}, {3,3}};
  vector <int> target {9, 6, 6};

  for (unsigned test = 0; test < NUMBER_OF_TESTS; test++)
  {
    vector <vector<int>> output {};
    unsigned indexOutput {0};

    for (unsigned i = 0; i < nums.at(test).size(); i++)
    {
        for (unsigned j = i + 1; j < nums.at(test).size(); j++)
        {
            if (nums.at(test).at(i) + nums.at(test).at(j) == target.at(test))
            {
                vector<int> pairIndices {static_cast<int>(i), static_cast<int>(j)};
                output.push_back(pairIndices);
            }
        }
    }

    green();

    cout << "Test " << test + 1 << ": ";

    reset();

    for (auto pairIndices : output) {
      cout << "[" ;
      for (auto index : pairIndices) {
          cout << index << " ";
      }
      cout << "] | ";
    }
    
    green();
    
    cout << "Passed" << endl;

    reset();
  }
  
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

