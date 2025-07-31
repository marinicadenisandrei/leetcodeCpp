/* Leetcode - 129. Sum Root to Leaf Numbers (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sumNumbers(vector<int> rootVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 129. Sum Root to Leaf Numbers (C++ language) - Medium" << endl;

    vector<vector<int>> root {{1,2,3},{4,9,0,5,1}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << sumNumbers(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int sumNumbers(vector<int> rootVar)
{
    vector<vector<int>> acumulation {};

    int depth = {1};
    int numbers = {0};
    int counter = {0};

    while (depth < rootVar.size())
    {
        numbers += depth;
        counter++;
        depth *= 2;
    }

    int step = {depth / 2};
    depth /= 2;
    int index = {0};
    int c = {0};

    for (int i = 0; i < counter; i++)
    {
        vector<int> temp {};

        for (int j = 0; j < depth; j++)
        {
            if (c == step)
            {
                index++;
                c = 0;
            }
            
            c++;
            
            if (index > rootVar.size() - 1)
            {
                break;
            }
            
            temp.push_back(rootVar[index]);
        }
                
        step /= 2;
        index++;
        c = 0;
        
        if (index > rootVar.size() - 1)
        {
            acumulation.push_back(temp);
            break;
        }
        
        acumulation.push_back(temp);
    }
  
    bool flag = {false};
    int result = 0;

    for (int i = 0; i < acumulation[0].size(); i++)
    {
        string numberStr = "";

        for (int j = 0; j < acumulation.size(); j++)
        {
            if (i > acumulation[j].size() - 1)
            {
                flag = true;
                break;
            }

            string temp = to_string(acumulation[j][i]);
            numberStr += temp;
        }

        if (flag)
        {
            result += stoi(numberStr);
            break;
        }
        
        result += stoi(numberStr);
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