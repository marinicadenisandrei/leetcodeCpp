/* Leetcode - 391. Perfect Rectangle (Python language) - Hard */

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

bool isRectangleCover(vector<vector<int>>& rectanglesVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 391. Perfect Rectangle (Python language) - " << boolalpha;

    red();

    cout << "Hard" << endl;

    vector<vector<vector<int>>> rectangles = {{{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}},
                                              {{1,1,2,3},{1,3,2,4},{3,1,4,2},{3,2,4,4}},
                                              {{1,1,3,3},{3,1,4,2},{1,3,2,4},{2,2,4,4}}
                                            };
    
    for (int test = 0; test < rectangles.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << isRectangleCover(rectangles[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool isRectangleCover(vector<vector<int>>& rectanglesVar)
{
    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;

    long long areasSum = 0;
    set<pair<int,int>> corners;

    for (const vector<int>& i : rectanglesVar)
    {
        minX = min(minX, i[0]);
        minY = min(minY, i[1]);
        maxX = max(maxX, i[2]);
        maxY = max(maxY, i[3]);

        long long tempArea = (long long)(i[2] - i[0]) * (i[3] - i[1]);
        areasSum += tempArea;

        vector<pair<int,int>> pts = {{i[0], i[1]}, {i[0], i[3]}, {i[2], i[1]}, {i[2], i[3]}};
        for (auto& p : pts)
        {
            if (corners.count(p))
                corners.erase(p);
            else
                corners.insert(p);
        }
    }

    long long bigArea = (long long)(maxX - minX) * (maxY - minY);
    if (areasSum != bigArea)
        return false;

    if (corners.size() != 4)
        return false;

    if (!corners.count({minX, minY})) return false;
    if (!corners.count({minX, maxY})) return false;
    if (!corners.count({maxX, minY})) return false;
    if (!corners.count({maxX, maxY})) return false;

    return true;
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