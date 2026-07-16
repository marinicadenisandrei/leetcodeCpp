/* Leetcode - 380. Insert Delete GetRandom O(1) (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class RandomizedSet
{
private:
    vector<int> set = {};
    std::mt19937 gen{std::random_device{}()};

public:
    RandomizedSet() = default;
    ~RandomizedSet() = default;

    bool insert(int value)
    {
        bool exists = std::find(set.begin(), set.end(), value) != set.end();

        if (exists)
        {
            return false;
        }

        set.push_back(value);

        return true;
    }

    bool remove(int value)
    {
        if (std::find(set.begin(), set.end(), value) != set.end())
        {
            set.erase(std::remove(set.begin(), set.end(), value), set.end());
            return true;
        }

        return false;
    }

    int getRandom()
    {
        std::uniform_int_distribution<size_t> dist(0, set.size() - 1);

        int randomElement = set[dist(gen)];

        return randomElement;
    }
};

int main()
{
    yellow();

    cout << "Leetcode - 380. Insert Delete GetRandom O(1) (C++ language) - Medium" << endl;

    cout << boolalpha;

    green();

    cout << "Test 1: ";

    reset();

    RandomizedSet randomizedSet;
    cout << "[";
    cout << randomizedSet.insert(1) << ", ";
    cout << randomizedSet.remove(2) << ", ";
    cout << randomizedSet.insert(2) << ", ";
    cout << randomizedSet.getRandom() << ", ";
    cout << randomizedSet.remove(1) << ", ";
    cout << randomizedSet.insert(2) << ", ";
    cout << randomizedSet.getRandom();
    cout << "] | ";

    green();

    cout << "Passed" << endl;

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