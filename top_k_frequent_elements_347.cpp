/* Leetcode - 347. Top K Frequent Elements (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> topKFrequent(vector<int> numsVar, int kVar);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 347. Top K Frequent Elements (C++ language) - Medium" << endl;

    vector<vector<int>> nums = {{1,1,1,2,2,3},{1},{1,2,1,2,1,2,3,1,3,2}};
    vector<int> k = {2,1,2};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(topKFrequent(nums[test], k[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");   
    }
}

vector<int> topKFrequent(vector<int> numsVar, int kVar)
{
    vector<int> result = {};

    std::vector<int> noDuplicates = numsVar;
    std::sort(noDuplicates.begin(), noDuplicates.end());
    noDuplicates.erase(std::unique(noDuplicates.begin(), noDuplicates.end()), noDuplicates.end());

    std::vector<int> occ(noDuplicates.size(), 0);
    for (size_t i = 0; i < noDuplicates.size(); ++i) {
        for (int x : numsVar) {
            if (x == noDuplicates[i]) occ[i]++;
        }
    }

    std::vector<std::pair<int,int>> zipped;
    zipped.reserve(noDuplicates.size());
    for (size_t i = 0; i < noDuplicates.size(); ++i) {
        zipped.push_back({occ[i], noDuplicates[i]});
    }

    std::sort(zipped.begin(), zipped.end(),
            [](const auto& a, const auto& b) {
                if (a.first != b.first) return a.first > b.first; 
                return a.second < b.second;                       
            });

    for (size_t i = 0; i < zipped.size(); ++i) {
        occ[i] = zipped[i].first;
        noDuplicates[i] = zipped[i].second;
    }

    for (int i = 0; i < kVar; i++)
    {
        result.push_back(noDuplicates[i]);
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