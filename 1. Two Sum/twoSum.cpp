/* Leetcode - 1. Two Sum */

#include <iostream>
using namespace std;

#define NUMBER_OF_TESTS 3

int main(){
    
    cout << "Leetcode - 1. Two Sum\n";

    int nums[20][20] = {{2,7,11,15},{3,2,4},{3,3}};
    int target[10] = {9,6,6};
    int testSizes[10] = {4,3,2}; 

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int output[10] = {};
        int sizeOutput = 0;
        int sizeNums = testSizes[test];
        int flagFinder = 0;
        
        for(int i = 0; i < sizeNums; i++){
            for(int j = 0; j < sizeNums; j++){
                if (i != j && nums[test][i] + nums[test][j] == target[test]){
                    output[sizeOutput] = i;
                    sizeOutput++;
                    output[sizeOutput] = j;
                    sizeOutput++;
                    flagFinder = 1;
                    break;
                }
            }
            if (flagFinder == 1){
                break;
            }
        }
        
        cout << "Test " << test+1 << " : " << "[ ";
        for (int i = 0; i < sizeOutput; i++){
            cout << output[i] << " ";
        }
        cout << "] | Passed\n";
    }
    
   
    
    return 0;
}