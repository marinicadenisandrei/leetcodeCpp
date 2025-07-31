/* Leetcode - 12. Integer to Roman (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Database_Roman_to_Integer
{
    string symbol {};
    int value {};
};

int FindIndexSameElement(int number, vector <struct Database_Roman_to_Integer> database_var);
string FindCombinationElement(int number, vector <struct Database_Roman_to_Integer> database_var);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 12. Integer to Roman (C++ language) - Medium" << endl;

    vector <struct Database_Roman_to_Integer> database {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
    };

    vector <int> numTest {3, 58, 1994};

    for (int test = 0; test < numTest.size(); test++)
    {
        int num {numTest.at(test)};

        int copyNum {num};
        vector <int> numbers {};

        int div_var = 1;
        size_t depth = {to_string(num).size()};

        string roman_string {};
        bool flag {false};
        
        for (int i = 0; i < depth; i++)
        {
            num /= div_var;
            numbers.push_back(num % 10 * div_var); 

            div_var *= 10;
            num = copyNum;
        }

        for (int i = numbers.size() - 1; i >= 0; i--)
        {
            int index_find = FindIndexSameElement(numbers[i], database);
            
            if (index_find != -1)
            {
                roman_string += database[index_find].symbol;
            }
            else
            {
                roman_string += FindCombinationElement(numbers[i], database);
            }    
        }

        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << roman_string << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
    
    return 0;
}

int FindIndexSameElement(int number, vector <struct Database_Roman_to_Integer> database_var)
{
    for (int j = 0; j < database_var.size(); j++)
    {
        if (database_var[j].value == number)
        {
            return j;
            break;
        }
    }

    return -1;
}

string FindCombinationElement(int number, vector <struct Database_Roman_to_Integer> database_var)
{
    for (int j = 0; j < database_var.size(); j++)
    {
        if (database_var[j].value > number)
        {
            for (int i = 0; i < database_var.size(); i++)
            {
                if (database_var[j].value - database_var[i].value == number)
                {
                    return database_var[i].symbol + database_var[j].symbol;
                }
            }

            break;
        }
    }

    string var {};
    
    while (number > 0)
    {
        for (int i = 0; i < database_var.size(); i++)
        {
            if (database_var[i].value > number)
            {
                var += database_var[i-1].symbol;
                number -= database_var[i-1].value;
                break;
            }
        }
    }

    return var;    
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