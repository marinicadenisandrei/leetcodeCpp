/* Leetcode - 352. Data Stream as Disjoint Intervals (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class SummaryRanges {
private:
    vector<int> arr = {};
public:
    SummaryRanges() {}
    ~SummaryRanges() {}

    void addNum(int x) {
        this->arr.push_back(x);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        if (arr.empty()) return result;

        vector<int> v = arr;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int start = v[0], end = v[0];

        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] == end + 1) {
                end = v[i];
            } else {
                result.push_back({start, end});
                start = end = v[i];
            }
        }
        result.push_back({start, end});
        return result;
    }
};

void print2DArray(vector<vector<int>> arr);

int main()
{
    yellow();

    cout << "Leetcode - 352. Data Stream as Disjoint Intervals (C++ language) -";

    red();

    cout << "Hard" << endl;

    green();

    cout << "Test 1: ";

    reset();

    SummaryRanges summaryRanges = SummaryRanges();

    summaryRanges.addNum(1);      
    print2DArray(summaryRanges.getIntervals());
    summaryRanges.addNum(3);      
    print2DArray(summaryRanges.getIntervals());
    summaryRanges.addNum(7);      
    print2DArray(summaryRanges.getIntervals()); 
    summaryRanges.addNum(2);   
    print2DArray(summaryRanges.getIntervals());
    summaryRanges.addNum(6);      
    print2DArray(summaryRanges.getIntervals()); 

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void print2DArray(vector<vector<int>> arr)
{
    cout << "[";

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << arr[i][j] << ((j < arr[i].size() - 1) ? ", " : "]");
        }
    }

    cout << "] | "; 
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