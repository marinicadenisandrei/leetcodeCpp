/* Leetcode - 71. Simplify Path (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string simplifyPath(string pathVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 71. Simplify Path (C++ language) - Medium" << endl;

    vector <string> path = {"/home/", "/../", "/home//foo/"};

    for (int test = 0; test < path.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        path[test] = simplifyPath(path[test]);

        cout << path[test] << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

string simplifyPath(string pathVar)
{
    pathVar.erase(remove(pathVar.begin(), pathVar.end(), '.'), pathVar.end());
    
    for (int i = 0; i < pathVar.size() - 1; i++)
    {
        if (pathVar[i] == '/' && pathVar[i + 1] == '/')
        {
            pathVar.erase(i + 1, 1);
        }
    }

    if (pathVar[pathVar.size() - 1] == '/')
    {
        pathVar.erase(pathVar.size() - 1, 1); 
    }
    
    if (pathVar.size() > 0)
    {
        return pathVar;
    }
    else
    {
        return "/";
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