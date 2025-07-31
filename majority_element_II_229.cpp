/* Leetcode - 229. Majority Element II (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> MajorityElement(vector<int> numsVar);
void sort2Vectors(vector<int> &vect1, vector<int> &vect2);
void printVector(vector<int> vec);

int main()
{
    yellow();

    cout << "Leetcode - 229. Majority Element II (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{3,2,3},{1},{1,2}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(MajorityElement(nums[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vec[i] << ((i < vec.size() - 1) ? ", " : "] | ");
    }
}

void sort2Vectors(vector<int> &vect1, vector<int> &vect2)
{
    int c = 0;
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < vect1.size() - 1 - c; i++)
        {
            if (vect1[i] < vect1[i + 1])
            {
                int temp = vect1[i];
                vect1[i] = vect1[i + 1];
                vect1[i + 1] = temp;   

                temp = vect2[i];
                vect2[i] = vect2[i + 1];
                vect2[i + 1] = temp; 
            }
        }
        
        c++;
    }
}

vector<int> MajorityElement(vector<int> numsVar)
{   
    vector<int> result = {};
    vector<int> number = {};
    vector<int> maxVar = {};
    
    for (int i = 0; i < numsVar.size(); i++)
    {
        int counter = 0;

        for (int j = 0; j < numsVar.size(); j++)
        {
            if (numsVar[i] == numsVar[j])
            {
                counter++;
            }
        }

        number.push_back(numsVar[i]);
        maxVar.push_back(counter);
    }

    sort2Vectors(number, maxVar);
    result.push_back(number[0]);
    
    for (int i = 1; maxVar[0] == maxVar[i]; i++)
    {
        if (number[i - 1] != number[i])
        {
            result.push_back(number[i]);
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
  