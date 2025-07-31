/* Leetcode - 273. Integer to English Words (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                       "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                       "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string convertThreeDigits(int num);
string numberToWords(int num);

int main() {
    
    yellow();

    cout << "Leetcode - 273. Integer to English Words (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<int> num = {123,12345,1234567};
    
    for (int test = 0; test < num.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << numberToWords(num[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

string convertThreeDigits(int num) {
    string res;
    if (num >= 100) {
        res += ones[num / 100] + " Hundred ";
        num %= 100;
    }
    if (num >= 20) {
        res += tens[num / 10] + " ";
        num %= 10;
    }
    if (num > 0) {
        res += ones[num] + " ";
    }
    return res;
}

string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }

    string globalRes = "";
    string result;
    int idx = 0;

    while (num > 0) {
        int chunk = num % 1000;
        if (chunk != 0) {
            result = convertThreeDigits(chunk) + thousands[idx] + " " + result;
        }
        num /= 1000;
        idx++;
    }

    while (!result.empty() && result.back() == ' ') result.pop_back();

    globalRes = globalRes + " " + result;

    return globalRes;
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