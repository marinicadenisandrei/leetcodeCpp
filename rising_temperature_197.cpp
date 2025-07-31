/* Leetcode - 197. Rising Temperature (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void risingTemperature(vector<int> temperatureVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 197. Rising Temperature (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> temperature = {10,25,20,30};
    
    cout << "Test 1: ";

    reset();
    
    risingTemperature(temperature);

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void risingTemperature(vector<int> temperatureVar)
{
    for (int i = 0; i < temperatureVar.size() - 1; i++)
    {
        if (temperatureVar[i] < temperatureVar[i + 1])
        {
            cout << i + 2 << " ";
        }
    }   

    cout << " | ";
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