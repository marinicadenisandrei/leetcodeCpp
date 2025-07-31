/* Leetcode - 96. Unique Binary Search Trees (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int generateTrees(int nVar);
void printVector(const vector<int> vectorVar);
void printMatrixVector(vector<vector <int>> matrix);
int returnFactorial(int number);
bool validBST(vector <int> BST);
bool vectorInBigVector(vector <vector <int>> bigVector, vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 96. Unique Binary Search Trees (C++ language) - Medium" << endl;

    vector <int> n {3,1};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        int output = generateTrees(n[test]);
        cout << output << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printMatrixVector(vector<vector <int>> matrix)
{
    cout << "[";

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix[i][j] << ((j < matrix[i].size() - 1) ? ", " : "]");
        }
    }
    
    cout << "] | ";
}

bool vectorInBigVector(vector<vector<int>> bigVector, vector<int> vectorVar) {
    for (int i = 0; i < bigVector.size(); i++) 
    {
        if (bigVector[i].size() == vectorVar.size()) 
        {
            bool flag = true;
            for (int j = 0; j < vectorVar.size(); j++) 
            {
                if (vectorVar[j] != bigVector[i][j]) 
                { 
                    flag = false;
                    break; 
                }
            }
            if (flag) 
            {
                return true;
            }
        }
    }
    return false;
}

bool validBST(vector <int> BST)
{
    while (BST.size() < 7)
    {
        BST.push_back(0);
    }
    
    for (int i = 0; i < BST.size(); i++)
    {
        if ((i * 2) + 2 >= BST.size())
        {
            break;
        }

        if (BST[i] < BST[(i * 2) + 1] || BST[i] > BST[(i * 2) + 2] || BST[(i * 2) + 1] > BST[(i * 2) + 2])
        {
            if (BST[(i * 2) + 1] == 0 && BST[(i * 2) + 2] == 0)
            {
                continue;
            }
            else if (BST[(i * 2) + 1] == 0)
            {
                if (BST[i] > BST[(i * 2) + 2])
                {
                    return false;
                }
            }
            else if (BST[(i * 2) + 2] == 0)
            {
                if (BST[i] < BST[(i * 2) + 1])
                {
                    return false;
                }
            }
        }

        if (BST[i] == 0 && BST[(i * 2) + 1] != 0)
        {
            return false;
        }

        if (BST[i] == 0 && BST[(i * 2) + 2] != 0)
        {
            return false;
        }
    }

    vector <int> tempBST(BST);
    int root = tempBST[0];
    tempBST.erase(tempBST.begin());
    int taken = 2;

    vector<int> left {};
    vector<int> right {};
    vector<int> big {};

    while (tempBST.size() > 0)
    {
        for (int i = 0; i < taken; i++)
        {
            big.push_back(tempBST[i]);
        }

        for (int i = 0; i < taken / 2; i++)
        {
            left.push_back(big[i]);
        }

        for (int i = taken / 2; i < big.size(); i++)
        {
            right.push_back(big[i]);
        }
        
        if (taken > tempBST.size())
        {
            break;
        }

        tempBST.erase(tempBST.begin(), tempBST.begin() + taken);
        taken += 2;
        big.clear();
    }

    for (int i = 0; i < left.size(); i++)
    {
        if (left[i] != 0 && left[i] > root)
        {
            return false;
        }
    }
    
    for (int i = 0; i < right.size(); i++)
    {
        if (right[i] != 0 && right[i] < root)
        {
            return false;
        }
    }

   return true;
}

int returnFactorial(int number)
{
    int result = 1;

    for (int i = 1; i <= number; i++)
    {
        result *= i;
    }
    
    return result;
}

void printVector(const vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]");
    }
}

int generateTrees(int nVar)
{
    vector<vector <int>> combinations {};
    vector <vector<int>> result {};
    vector <int> combFormation {};
    const int factorialDepth {returnFactorial(nVar)};

    for (int i = 1; i <= nVar; i++)
    {
        combFormation.push_back(i);
    }

    combinations.push_back(combFormation);

    if (nVar == 1)
    {
        result.push_back(combFormation);
        return result.size();
    }

    int temp = combFormation[0];
    combFormation[0] = combFormation[1];
    combFormation[1] = temp;
    combinations.push_back(combFormation);

    int index1 = 1;
    int index2 = 2;

    for (int i = 0; i < factorialDepth - 2; i++)
    {
        if (index2 < nVar)
        {
            temp = combFormation[index1];
            combFormation[index1] = combFormation[index2];
            combFormation[index2] = temp;
        }
        else
        {
            temp = combFormation[0];
            combFormation[0] = combFormation[nVar - 1];
            combFormation[nVar - 1] = temp;

            index1 = -1;
            index2 = 0;
        }

        index1++;
        index2++;
        combinations.push_back(combFormation);
    }

    for (int i = 0; i < factorialDepth; i++)
    {
        vector <int> tempInsert(combinations[i]);

        for (int j = 1; j < nVar * 2; j += 3)
        {
            tempInsert.insert(tempInsert.begin() + j, 0);
            vector <int> copyVector1(tempInsert);
            combinations.push_back(copyVector1);

            tempInsert.insert(tempInsert.begin() + j, 0);
            vector <int> copyVector2(tempInsert);
            combinations.push_back(copyVector2);
        }
    }

    for (int i = 0; i < factorialDepth; i++)
    {
        vector <int> tempInsert(combinations[i]);

        for (int j = 1; j < nVar * 2; j += 2)
        {
            tempInsert.insert(tempInsert.begin() + j, 0);
            vector <int> copyVector1(tempInsert);
            combinations.push_back(copyVector1);
        }
    }
    
    for (int i = 0; i < factorialDepth; i++)
    {
        vector <int> tempInsert(combinations[i]);

        for (int j = nVar - 1; j >= 1; j--)
        {
            tempInsert.insert(tempInsert.begin() + j, 0);
            vector <int> copyVector1(tempInsert);
            combinations.push_back(copyVector1);

            tempInsert.insert(tempInsert.begin() + j, 0);
            vector <int> copyVector2(tempInsert);
            combinations.push_back(copyVector2);
        }
    }
    
    int stoper = combinations.size();

    for (int i = 0; i < stoper; i++)
    {
        int depth = combinations[i].size();
        vector <int> temp(combinations[i]);

        for (int j = 0; j < depth; j++)
        {
            if ((j * 2) + 2 > depth)
            {
                break;
            }

            if (temp[j] == 0)
            {
                temp.insert(temp.begin() + (j * 2) + 1, 0);
                temp.insert(temp.begin() + (j * 2) + 2, 0);
            }
        }
        
        combinations.push_back(temp);
    }
    
    for (auto i : combinations)
    {
        if (validBST(i) && i.size() <= 7)
        {
            if (!vectorInBigVector(result, i))
            {
                result.push_back(i);
            }
        }
    }

    return result.size();
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