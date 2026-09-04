/* Leetcode - 384. Shuffle an Array (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class Solution {
private:
    std::vector<int> arr;
    std::vector<int> copy_arr;
    std::mt19937 g{std::random_device{}()};  // seeded once, reused

public:
    explicit Solution(std::vector<int> nums)
        : arr(nums), copy_arr(std::move(nums)) {}

    void shuffle() {
        std::shuffle(arr.begin(), arr.end(), g);
    }

    void reset() {
        arr = copy_arr;
    }

    void printArr() const {
        std::cout << '[';
        for (std::size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i];
            if (i + 1 < arr.size()) std::cout << ", ";
        }
        std::cout << "] ";
    }
};

int main() {
    yellow();

    cout << "Leetcode - 384. Shuffle an Array (C++ language) - Medium" << endl;

    green();

    cout << "Test 1: ";

    reset();

    Solution solution({1, 2, 3});

    solution.shuffle();
    solution.printArr();

    solution.reset();
    solution.printArr();

    solution.shuffle();
    solution.printArr();

    cout << " | ";

    green();

    cout << "Passed" << endl;

    reset();
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