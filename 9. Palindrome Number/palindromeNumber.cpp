/* Leetdode - 9. Palindrome Number (C++) */

#include <iostream>
#include <sstream>

using namespace std;

#define NUMBER_OF_TESTS 3

int main()
{

    cout << "Leetdode - 9. Palindrome Number (C++)" << endl;

    int x[10] = {121, -121, -10};
    int elementList[10] = {};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int sizeElementList = 0;
        bool flagPalindrome = true;

        if (x[test] > 0)
        {
            while (x[test] > 0)
            {   
                elementList[sizeElementList] = x[test] % 10;
                x[test] = x[test] / 10;
                sizeElementList++;
            }

            for (int i = 0; i < sizeElementList; i++)
            {
                flagPalindrome = (elementList[i] != elementList[sizeElementList-i-1]) ? false : flagPalindrome;
            }
        }
        else
        {
            flagPalindrome = false;
        }
        
        (flagPalindrome == true) ? cout << "Test " << test+1 << ": true | Passed\n" :  cout << "Test " << test+1 << ": flase | Passed\n";
    }
}