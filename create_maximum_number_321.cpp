/* Leetcode - 321. Create Maximum Number (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int maxNumber(vector<int> nums1Var, vector<int> nums2Var, int kVar);

int main()
{
    yellow();

    cout << "Leetcode - 321. Create Maximum Number (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums1 = {{3,4,6,5},{6,7},{3,9}};
    vector<vector<int>> nums2 = {{9,1,2,5,8,3},{6,0,4},{8,9}};
    vector<int> k = {5,5,3};

    for (int test = 0; test < nums1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();
        
        cout << maxNumber(nums1[test], nums2[test], k[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

int maxNumber(vector<int> nums1Var, vector<int> nums2Var, int kVar)
{
    vector<int> unionVec = {};
    vector<int> candidates = {};
    string result = "";

    vector<int> results = {};

    for (int i = 0; i < nums1Var.size(); i++)
    {
        unionVec.push_back(nums1Var[i]);
    }
    
    for (int i = 0; i < nums2Var.size(); i++)
    {
        unionVec.push_back(nums2Var[i]);
    }

    int first_index = 0;
    int second_index = 0;

    bool flag = true;

    while (flag)
    {
        flag = false;
        int max_first = -1;
        int max_second = -1;

        for (int i = first_index; i < nums1Var.size(); i++)
        {
            if (max_first < nums1Var[i])
            {
                max_first = nums1Var[i];
                first_index = i + 1;
                flag = true;
            }
        }

        for (int i = second_index; i < nums2Var.size(); i++)
        {
            if (nums2Var[i] > max_second)
            {
                max_second = nums2Var[i];
                second_index = i + 1;
                flag = true;
            } 
        }

        if (max_first > max_second)
        {
            if (max_first != -1)
            {
                result += to_string(max_first);
                candidates.push_back(max_first);
            }
            
            if (max_second != -1)
            {
                result += to_string(max_second);
                candidates.push_back(max_second);
            }
        }
        else 
        {
            if (max_second != -1)
            {
                result += to_string(max_second);
                candidates.push_back(max_second);
            }

            if (max_first != -1)
            {
                result += to_string(max_first);
                candidates.push_back(max_first);
            }
        }
    }

    result = result.substr(0 ,kVar);
    sort(result.begin(), result.end(), std::greater<char>());
    results.push_back(stoi(result));

    result = "";

    for (int i = 0; i < unionVec.size(); i++)
    {
        result += to_string(unionVec[i]);   
    }

    result = result.substr(0 ,kVar);
    results.push_back(stoi(result));

    string formationString = "";

    for (int i = 0; i < unionVec.size(); i++)
    {
        formationString += to_string(unionVec[i]);
    }
    
    for (int i = 0; i < formationString.size(); i++)
    {   
        string temp = formationString.substr(i, kVar);
        results.push_back(stoi(temp));
    }

    sort(results.begin(), results.end(), greater<int>());
    
    return results[0];
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