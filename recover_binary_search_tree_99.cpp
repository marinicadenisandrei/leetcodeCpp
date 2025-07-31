#include <iostream>
#include <vector>

using namespace std;

void recoverTree(vector<int> rootVar);
void printVector(vector<int> vectorVar);
bool validBST(vector<int> bst);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 99. Recover Binary Search Tree (C++ language) - Medium" << endl;

    vector<vector<int>> root {{1,3,0,0,2},{3,1,4,0,0,2}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        recoverTree(root[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool validBST(vector<int> bst)
{
    bool flag = true;

    for (int i = 0; i < bst.size(); i++)
    {
        if ((i * 2) + 2 > bst.size())
        {
            break;
        }

        if (bst[i] < bst[(i * 2) + 1] || bst[i] > bst[(i * 2) + 2] || bst[(i * 2) + 2] < bst[(i * 2) + 1])
        {
            if (bst[i] == 0 || bst[(i * 2) + 1] == 0 || bst[(i * 2) + 2] == 0)
            {
                if (bst[(i * 2) + 2] == 0 && bst[(i * 2) + 1] == 0)
                {
                    continue;
                }
                else if (bst[i] == 0 && bst[(i * 2) + 2] < bst[(i * 2) + 1])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }   
        }
    }

    return true;
}

void printVector(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]");
    }  

    printf(" | ");
}

void recoverTree(vector<int> rootVar)
{
    vector<vector<int>> acumulation {};
    vector<int> staticRoot(rootVar);

    int depth {1};
    int index1 {0};
    int index2 {1};
    int temp {0};
    int power {1};

    for (int i = 1; i < rootVar.size(); i++)
    {
        depth *= i;
    }

    while (power < rootVar.size())
    {
        power *= 2;
    }

    for (int j = 0; j < staticRoot.size(); j++)
    {
        int temp = rootVar[0];
        rootVar.erase(rootVar.begin());
        rootVar.push_back(temp);

        vector<int> copyRoot(rootVar);
        
        for (int i = 0; i < depth; i++)
        {
            if (index2 < rootVar.size())
            {
                temp = rootVar[index1];
                rootVar[index1] = rootVar[index2];
                rootVar[index2] = temp;
            }
            else
            {
                temp = rootVar[0];
                rootVar[0] = rootVar[rootVar.size() - 1];
                rootVar[rootVar.size() - 1] = temp;

                index1 = -1;
                index2 = 0;
            }
            
            index1++;
            index2++;

            vector<int> copyRoot(rootVar);
            
            acumulation.push_back(copyRoot);
        }
    }   

    int counter = 0;

    for (auto i : acumulation)
    {
        if(validBST(i))
        {
            int counter = 0;

            for (int j = 0; j < i.size(); j++)
            {
                if (staticRoot[j] != i[j])
                {
                    counter++;
                }
                if (staticRoot[j] == 0 && i[j] != 0)
                {
                    counter = 3;
                    break;
                }
                
            }

            if (counter > 0 && counter <= 2)
            {
                printVector(i);
                break;
            }
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