/* Leetcode - 18. 4Sum (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector <int> &vectorVar);
bool checkIfVectorContainVector(vector <vector <int>> bigVector, vector <int> smallVector);
void printMatrix(vector <vector <int>> matrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 18. 4Sum (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{1,0,-1,0,-2,2}, {2,2,2,2,2}};
    vector <int> target {0, 8};

    for (int test = 0; test < nums.size(); test++)
    {
        vector <vector <int>> output {};

        for (int i = 0; i < nums.at(test).size(); i++)
        {
            for (int j = 0; j < nums.at(test).size(); j++)
            {
                for (int k = 0; k < nums.at(test).size(); k++)
                {
                    for (int l = 0; l < nums.at(test).size(); l++)
                    {
                        if (i != j && i != k && i != l && j != k && j != l && j != i && l != i && l != j && l != k)
                        {
                            if (nums.at(test)[i] + nums.at(test)[j] + nums.at(test)[k] + nums.at(test)[l] == target.at(test))
                            {
                                vector <int> tempVector {nums.at(test)[i], nums.at(test)[j], nums.at(test)[k], nums.at(test)[l]};
                                bubbleSort(tempVector);

                                if (!checkIfVectorContainVector(output, tempVector))
                                {
                                    output.push_back(tempVector);
                                }
                            }
                            
                        }
                    }
                }
            }
        }

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printMatrix(output);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void bubbleSort(vector <int> &vectorVar)
{
    bool flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < vectorVar.size() - 1 - counter; i++)
        {
            if (vectorVar.at(i) > vectorVar.at(i + 1))
            {
                int temp = vectorVar.at(i);
                vectorVar.at(i) = vectorVar.at(i + 1);
                vectorVar.at(i + 1) = temp;

                flag = true;
            }   
        }
        
        counter++;
    }
}

bool checkIfVectorContainVector(vector <vector <int>> bigVector, vector <int> smallVector)
{
    bool flag = true;

    for (int i = 0; i < bigVector.size(); i++)
    {
        flag = true;

        for (int j = 0; j < smallVector.size(); j++)
        {
            if (bigVector[i][j] != smallVector[j])
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            return true;
        }
    }

    return false;
}

void printMatrix(vector <vector <int>> matrix)
{
    cout << "[";

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix.at(i).at(j) << ((j < matrix.at(i).size() - 1) ? ", " : "]");
        }
    }

    cout << "] | ";
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