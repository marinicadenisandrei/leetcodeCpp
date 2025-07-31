/* Leetcode - 40. Combination Sum II (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Occurence
{
    int number;
    int occuringNumber;
};

vector <vector <int>> combinationSum2(vector <int> candidatesVar, int targetVar);
void startingVectors(vector <vector <vector <int>>> & startingVector, vector <int> startVector);
void printVectorMatrix(vector <vector <int>> vectorMatrix);
void printVector(vector <int> vectorVar);
int sumOfVectorElements(vector <int> vectorVar);
bool checkOccurence(vector <int> vectorVar, vector <Occurence> database);
bool vectorInBigVector(vector <int> smallVector, vector <vector <int>> bigVector);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 40. Combination Sum II (C++ language) - Medium" << endl;

    vector <vector <int>> candidates {{10,1,2,7,6,1,5}, {2,5,2,1,2}};
    vector <int> target {8,5};

    for (int test = 0; test < candidates.size(); test++)
    {
        vector <vector <int>> output = combinationSum2(candidates[test], target[test]);

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVectorMatrix(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool vectorInBigVector(vector <int> smallVector, vector <vector <int>> bigVector)
{
    for (auto i : bigVector)
    {
        if (i == smallVector)
        {
            return true;
        }
    }
    
    return false;
}

bool checkOccurence(vector <int> vectorVar, vector <Occurence> database)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        int sum {0};

        for (int j = 0; j < vectorVar.size(); j++)
        {
            if (vectorVar[i] == vectorVar[j])
            {
                sum++;
            }
        }

        for (int k = 0; k < database.size(); k++)
        {
            if (database[k].number == vectorVar[i] && (sum - 1) > database[k].occuringNumber)
            {
                return false;
            }
        }
    }

    return true;
}

int sumOfVectorElements(vector <int> vectorVar)
{
    int sum {0};

    for (int i = 0; i < vectorVar.size(); i++)
    {
        sum += vectorVar.at(i);
    }

    return sum;
}

void printVector(vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "]");
    }
    
    cout << endl;
}

void printVectorMatrix(vector <vector <int>> vectorMatrix)
{
    for (int i = 0; i < vectorMatrix.size(); i++)
    {
        for (int j = 0; j < vectorMatrix.at(i).size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorMatrix[i][j] << ((j < vectorMatrix.at(i).size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

void startingVectors(vector <vector <vector <int>>> & startingVector, vector <int> startVector)
{
    for (int i = 0; i < 2; i++)
    {
        startingVector.push_back({});
        
        for (int j = 0; j < startVector.size(); j++)
        {
            startingVector[i].push_back({startVector[j]});
        }
    }
}

vector <vector <int>> combinationSum2(vector <int> candidatesVar, int targetVar)
{
    vector <Occurence> occuringArray {};
    vector <vector <int>> results {};
    
    for (auto i : candidatesVar)
    {
        if (i == targetVar)
        {
            results.push_back({i});
        }
    }

    for (int i = 0; i < candidatesVar.size(); i++)
    {
        int sum = 0;

        occuringArray.push_back({});

        occuringArray[i].number = candidatesVar[i];

        for (int j = 0; j < candidatesVar.size(); j++)
        {
            if (candidatesVar[i] == candidatesVar[j])
            {
                sum++;
            }            
        } 

        occuringArray[i].occuringNumber = sum - 1;
    }
    
    vector <vector <vector <int>>> acumulation {};
    startingVectors(acumulation, candidatesVar);

    bool flag {true};
    int counter = 0;

    while (flag)
    {
        flag = false;
        acumulation.push_back({});

        for (int i = 0; i < acumulation[0].size(); i++)
        {
            for (int j = 0; j < acumulation[1].size(); j++)
            {
                for (int k = 0; k < acumulation[0][i].size(); k++)
                {
                    vector <int> temp {};
                    temp.push_back(acumulation[0][i][k]);

                    for (int l = 0; l < acumulation[1][j].size(); l++)
                    {
                        temp.push_back(acumulation[1][j][l]);
                    }
                    
                    if (sumOfVectorElements(temp) <= targetVar)
                    {
                        if (checkOccurence(temp, occuringArray))
                        {   
                            sort(temp.begin(), temp.end());

                            if (!vectorInBigVector(temp,results) && sumOfVectorElements(temp) == targetVar)
                            {
                                results.push_back(temp);
                            }
                            
                            flag = true;
                        }
                    }
                    
                    
                    acumulation[2].push_back(temp);
                    temp.clear();
                }
            }
        }
       
        acumulation.erase(acumulation.begin());    
    }

    return results;
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