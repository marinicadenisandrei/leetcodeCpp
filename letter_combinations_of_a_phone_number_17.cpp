/* Leetcode - 17. Letter Combinations of a Phone Number (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct DataBasePhoneKeyboard
{
    string number {""};
    string chars {""};
};

void generateCombinations(string digitsStart, vector <struct DataBasePhoneKeyboard> databaseVar, vector <vector <string>> &outputVector, vector <string> &current, int index);
void printVector(vector <string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 17. Letter Combinations of a Phone Number (C++ language) - Medium" << endl;

    vector <struct DataBasePhoneKeyboard> database {
        {"1", ""},
        {"2", "abc"},
        {"3", "def"},
        {"4", "ghi"},
        {"5", "jkl"},
        {"6", "mno"},
        {"7", "pqrs"},
        {"8", "tuv"},
        {"9", "wxyz"}
    };

    vector <string> digits {"23", "", "2"};

    for (int test = 0; test < digits.size(); test++)
    {
        vector <vector <string>> output;
        vector <string> current;

        if (digits[test].size() > 0)
        {
            generateCombinations(digits[test], database, output, current, 0);
            
        }
        else
        {
            output.push_back({""});
        }

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(output.back());

        green();

        cout << "Passed" << endl;

        reset();
    }
    
    return 0;
}

void generateCombinations(string digitsStart, vector <struct DataBasePhoneKeyboard> databaseVar, vector <vector <string>> &outputVector, vector <string> &current, int index)
{
    int digitsIndex = digitsStart[index] - '0' - 1;

    if (index == digitsStart.size())
    {
        return;
    }
    
    if (index == 0)
    {
        outputVector.push_back({});

        if (digitsStart.size() == 1)
        {
            for (int i = 0; i < databaseVar[digitsIndex].chars.size(); i++)
            {
                string combination {""}; 
                combination.append(1, databaseVar[digitsIndex].chars[i]);

                outputVector.back().push_back(combination);
            }
        }
        else
        {
            for (int i = 0; i < databaseVar[digitsIndex].chars.size(); i++)
            {
                for (int j = 0; j < databaseVar[digitsIndex + 1].chars.size(); j++)
                {
                    string combination {""}; 
                    combination.append(1, databaseVar[digitsIndex].chars[i]);
                    combination.append(1, databaseVar[digitsIndex + 1].chars[j]);

                    current.push_back(combination);
                }
            }

            outputVector.push_back(current);
            current.clear();
        
            return generateCombinations(digitsStart, databaseVar, outputVector, current, index + 2);
        }
    }
    else
    {
        for (int i = 0; i < databaseVar[digitsIndex].chars.size(); i++)
        {
            for (int j = 0; j < outputVector.back().size(); j++)
            {
                string combination {""}; 
                combination.append(1, databaseVar[digitsIndex].chars[i]);
                combination += outputVector.back()[j];

                current.push_back(combination);
            }
        }

        outputVector.pop_back();
        outputVector.push_back(current);
        current.clear();

        return generateCombinations(digitsStart, databaseVar, outputVector, current, index + 1);
    }
}

void printVector(vector <string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
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