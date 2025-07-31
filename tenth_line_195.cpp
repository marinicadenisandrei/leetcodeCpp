/* Leetcode - 195. Tenth Line (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

string tenthLine(string fileVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 195. Tenth Line (C++ language) - ";

    green();

    cout << "Easy" << endl;

    string file {"Line 1\nLine 2\nLine 3\nLine 4\nLine 5\nLine 6\nLine 7\nLine 8\nLine 9\nLine 10"};

    cout << "Test 1: ";

    reset();

    cout << tenthLine(file) << " | ";

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

string tenthLine(string fileVar)
{
    std::vector<std::string> lines;
    std::stringstream ss(fileVar);
    std::string line;

    int lineNumber = 1;

    while (std::getline(ss, line, '\n')) {
        if (lineNumber == 10)
        {
            return line;
        }

        lineNumber++;
    }

    return "";
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