/* Leetcode - 329. Longest Increasing Path in a Matrix (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;    

void reset ();
void green ();
void yellow ();
void red ();

int longestIncreasingPath(vector<vector<int>> matrixVar);

int main()
{
    yellow();

    cout << "Leetcode - 329. Longest Increasing Path in a Matrix (C++ language) - ";
    
    red();

    cout << "Hard" << endl;

    vector<vector<vector<int>>> matrix = {{{9,9,4},{6,6,8},{2,1,1}},{{3,4,5},{3,2,6},{2,2,1}}};
    
    for (int test = 0; test < matrix.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << longestIncreasingPath(matrix[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int longestIncreasingPath(vector<vector<int>> matrixVar)
{
    int result = 0;

    const int m = (int)matrixVar.size();
    const int n = (int)matrixVar[0].size();

    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            int i_pos = i;          
            int j_pos = j;
            int current = matrixVar[i_pos][j_pos];
            int counter = 0;

            while (true)
            {
                int next_i = -1, next_j = -1;
                int best_val = current;

                if (i_pos - 1 >= 0) {
                    int v = matrixVar[i_pos - 1][j_pos];
                    if (v > best_val) { best_val = v; next_i = i_pos - 1; next_j = j_pos; }
                }
                
                if (i_pos + 1 < m) {
                    int v = matrixVar[i_pos + 1][j_pos];
                    if (v > best_val) { best_val = v; next_i = i_pos + 1; next_j = j_pos; }
                }
                
                if (j_pos - 1 >= 0) {
                    int v = matrixVar[i_pos][j_pos - 1];
                    if (v > best_val) { best_val = v; next_i = i_pos; next_j = j_pos - 1; }
                }
                

                if (j_pos + 1 < n) {
                    int v = matrixVar[i_pos][j_pos + 1];
                    if (v > best_val) { best_val = v; next_i = i_pos; next_j = j_pos + 1; }
                }

                if (next_i == -1) break;

                i_pos = next_i;
                j_pos = next_j;
                current = best_val;
                counter++;
            }

            result = ((result < counter) ? counter : result);
        }        
    }

    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            int i_pos = i;          
            int j_pos = j;
            int current = matrixVar[i_pos][j_pos];
            int counter = 0;

            while (true)
            {
                int next_i = -1, next_j = -1;
                int best_val = current;

                if (i_pos - 1 >= 0) {
                    int v = matrixVar[i_pos - 1][j_pos];
                    if (v < best_val) { best_val = v; next_i = i_pos - 1; next_j = j_pos; }
                }
                
                if (i_pos + 1 < m) {
                    int v = matrixVar[i_pos + 1][j_pos];
                    if (v < best_val) { best_val = v; next_i = i_pos + 1; next_j = j_pos; }
                }
                
                if (j_pos - 1 >= 0) {
                    int v = matrixVar[i_pos][j_pos - 1];
                    if (v < best_val) { best_val = v; next_i = i_pos; next_j = j_pos - 1; }
                }
                

                if (j_pos + 1 < n) {
                    int v = matrixVar[i_pos][j_pos + 1];
                    if (v < best_val) { best_val = v; next_i = i_pos; next_j = j_pos + 1; }
                }

                if (next_i == -1) break;

                i_pos = next_i;
                j_pos = next_j;
                current = best_val;
                counter++;
            }

            result = ((result < counter) ? counter : result);
        }        
    }

    return result + 1;
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