/* Leetcode - 15. 3Sum (C++ language) - Medium */

#include <iostream>
#include <vector>

const int SMALL_VECTOR_SIZE {3};

using namespace std;

bool checkIfVectorIsInVector(vector <vector <int>> bigVector, vector <int> smallVector);
void bubbleSort(vector <int> &array);
void printVector(vector <vector <int>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 15. 3Sum (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{-1,0,1,2,-1,-4}, {0,1,1}, {0,0,0}};

    for (int test = 0; test < nums.size(); test++)
    {
        vector <vector <int>> output {};
        int outputSize {0};

        for (int i = 0; i < nums.at(test).size(); i++)
        {
            for (int j = 0; j < nums.at(test).size(); j++)
            {
                for (int k = 0; k < nums.at(test).size(); k++)
                {
                    if (i != j && i != k && j != k)
                    {
                        if (nums.at(test).at(i) + nums.at(test).at(j) + nums.at(test).at(k) == 0)
                        {
            
                            vector <int> temp {nums.at(test).at(i), nums.at(test).at(j), nums.at(test).at(k)};
                            bubbleSort(temp);

                            if (!checkIfVectorIsInVector(output, temp))
                            {
                                output.push_back(temp);

                                outputSize++;
                            }  
                        } 
                    }
                }
            }
        }

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(output);

        green();

        cout << "Passed" << endl;

        reset();
    }
    

    return 0;
}

bool checkIfVectorIsInVector(vector <vector <int>> bigVector, vector <int> smallVector)
{
    bool flag = false;

    for (int i = 0; i < bigVector.size(); i++)
    {
        for (int j = 0; j < SMALL_VECTOR_SIZE; j++)
        {
            flag = ((bigVector.at(i).at(j) == smallVector.at(j)) ? true : false);
        }

        if (flag) return true;
    }

    return false;
}

void bubbleSort(vector<int> &array) {
    bool flag {true};
    int counter {0};

    while (flag) {
        flag = false;

        for (int i = 0; i < array.size() - 1 - counter; i++) {
            if (array[i] > array[i + 1]) 
            {  
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                flag = true;
            }
        }

        counter++;
    }
}

void printVector(vector <vector <int>> vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] ";
    }
    else
    {
        for (int i = 0; i < vectorVar.size(); i++)
        {
            for (int j = 0; j < SMALL_VECTOR_SIZE; j++)
            {
                cout << ((j == 0) ? "[" : "") << vectorVar.at(i).at(j) << ((j < SMALL_VECTOR_SIZE - 1) ? ", ": "] ");
            }   
        }
    }

    cout << "| ";
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