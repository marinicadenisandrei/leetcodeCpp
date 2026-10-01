/* Leetcode - 388. Longest Absolute File Path (C++ language) - Medium */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthLongestPath(string inputVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    cout << "Leetcode - 388. Longest Absolute File Path (C++ language) - Medium" << endl;

    vector<string> input = {"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext","dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext","a"};
    
    for (int test = 0; test < input.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << lengthLongestPath(input[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int lengthLongestPath(string input)
{
    stringstream ss(input);
    string line;

    vector<int> pathLength(input.size() + 1, 0);

    int maxLength = 0;

    while (getline(ss, line))
    {
        int depth = 0;

        while (depth < line.size() && line[depth] == '\t')
        {
            depth++;
        }

        string name = line.substr(depth);

        if (name.find('.') != string::npos)
        {
            int currentLength =
                pathLength[depth] + name.length();

            maxLength = max(maxLength, currentLength);
        }
        else
        {
            pathLength[depth + 1] =
                pathLength[depth] + name.length() + 1;
        }
    }

    return maxLength;
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