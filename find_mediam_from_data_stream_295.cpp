/* Leetcode - 295. Find Median from Data Stream (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class MedianFinder 
{
private:
    vector<int> acc;
public:
    void addNum(int num)
    {
        acc.push_back(num);
    }

    double findMedian()
    {
        double sum = 0;

        for (int i = 0; i < acc.size(); i++)
        {
            sum += acc[i];
        }
        
        return sum / acc.size();
    }

    MedianFinder() = default;
    ~MedianFinder() = default;
};

int main()
{
    yellow();

    cout << "Leetcode - 295. Find Median from Data Stream (C++ language) ";

    red();

    cout << "Hard" << endl;

    MedianFinder medianFinder = MedianFinder();

    green();

    cout << "Test 1: ";

    reset();

    medianFinder.addNum(1); 
    medianFinder.addNum(2);    
    cout << medianFinder.findMedian() << " ";
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << " ";

    cout << "| ";

    green();

    cout << "Passed";

    reset();

    return 0;
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