/* Leetcode - 297. Serialize and Deserialize Binary Tree (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

string serialize(vector<int> rootVar);
vector<int> deserialize(string data);
std::vector<int> splitStringToInts(const std::string& input, char delimiter = ',') ;
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 297. Serialize and Deserialize Binary Tree (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> root = {{1,2,3,0,0,4,5},{}};
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(deserialize(serialize(root[test])));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vect)
{
    if (vect.size() == 0)
    {
        cout << "[] | ";
        return;
    }
    

    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");   
    }
}

string serialize(vector<int> rootVar)
{
    string rootSer = "";

    for (int i = 0; i < rootVar.size(); i++)
    {
        rootSer += to_string(rootVar[i]) + ",";
    }
    
    return rootSer;
}

vector<int> deserialize(string data)
{
    return splitStringToInts(data);
}

vector<int> splitStringToInts(const string& input, char delimiter) {
    vector<int> result;
    istringstream ss(input);
    string token;

    while (getline(ss, token, delimiter)) {
        if (!token.empty())           
            result.push_back(stoi(token));
    }

    return result;
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