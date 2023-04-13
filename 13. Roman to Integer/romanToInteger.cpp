/* Leetcode - 13. Roman to Integer (C++ language) */

#include <iostream>
  
using namespace std; 

    int roman_to_integer(string rstr) {
        int n = int(rstr.length());
        if (0 == n) {
            return 0;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            switch (rstr[i]) {
                case 'I':
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }

        for (int i = 1; i < n; i++) {
            if ((rstr[i] == 'V' || rstr[i] == 'X') && rstr[i - 1] == 'I') {
                result -= 1 + 1;
            }

            if ((rstr[i] == 'L' || rstr[i] == 'C') && rstr[i - 1] == 'X') {
                result -= 10 + 10;
            }

            if ((rstr[i] == 'D' || rstr[i] == 'M') && rstr[i - 1] == 'C') {
                result -= 100 + 100;
            }
        }
        return result;
    }

  
int main()  
{  
    cout << "Leetcode - 13. Roman to Integer (C++ language)" << endl;
    string s = "VII";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;
    s = "XIX";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;  
    s = "DCCLXXXIX";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;   
    s = "MXCIX";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl; 
    s = "MMMMMMMMMMMMMMMMMMMMMMMCDLVI";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;

    return 0;  
}  
