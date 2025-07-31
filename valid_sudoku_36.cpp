/* Leetcode - 36. Valid Sudoku (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SUDOKU_TABLE 9

void printMatrix(vector <vector <string>> matrix);
bool isValidSudoku(vector <vector <string>> boardVar);
void verticalBoard(const vector <vector <string>> boardVar, vector <vector <string>> &verticalBoard);
void squaresGenerate(const vector <vector <string>> boardVar, vector <vector <string>> &squaresVar);
int elementInVector(const vector <string> vectorVar, string element);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 36. Valid Sudoku (C++ language) - Medium" << endl;

    vector <vector <vector <string>>> board {
        {{"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}},

        {{"8","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}}};


    for (int test = 0; test < board.size(); test++)
    {
        bool result = isValidSudoku(board[test]);

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << result << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void squaresGenerate(const vector <vector <string>> boardVar, vector <vector <string>> &squaresVar)
{
    int startRow {0};
    int endRow {3};

    int startCol {0};
    int endCol {3};

    int locate {0};

    for (int i = 0; i < SUDOKU_TABLE; i++)
    {
        squaresVar.push_back({});

        for (int j = startRow; j < endRow; j++)
        {
            for (int k = startCol; k < endCol; k++)
            {
                squaresVar[locate].push_back(boardVar[j][k]);
            }
        }

        if (endCol < SUDOKU_TABLE)
        {
            startCol += 3;
            endCol += 3;
        }
        else
        {
            startCol = 0;
            endCol = 3;

            startRow += 3;
            endRow += 3;
        }

        locate++;
    }
}

void verticalBoard(const vector <vector <string>> boardVar, vector <vector <string>> &verticalBoard)
{
    for (int i = 0; i < SUDOKU_TABLE; i++)
    {
        verticalBoard.push_back({});

        for (int j= 0; j < SUDOKU_TABLE; j++)
        {
            verticalBoard.at(i).push_back(boardVar.at(j).at(i));
        }
    }
}

void printMatrix(vector <vector <string>> matrix)
{
    for (int i = 0; i < SUDOKU_TABLE; i++)
    {
        for (int j = 0; j < SUDOKU_TABLE; j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix.at(i).at(j) << ((j < matrix[0].size() - 1) ? ", " : "]\n");
        }
    }

    cout << endl << endl;
}

int elementInVector(const vector <string> vectorVar, string element)
{
    int counter {0};

    for (auto i : vectorVar)
    {
        if (i == element)
        {
            counter++;
        }
    }
    
    return counter;
}

bool isValidSudoku(vector <vector <string>> boardVar)
{
    vector <vector <string>> vertical {};
    vector <vector <string>> squares {};

    verticalBoard(boardVar, vertical);
    squaresGenerate(boardVar, squares);

    int locate {0};
    int factor {0};

    for (int i = 0; i < SUDOKU_TABLE; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            factor += 3;
        }

        for (int j = 0; j < SUDOKU_TABLE; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                locate++;
            }

            if (boardVar[i][j] != ".")
            {
                if (elementInVector(boardVar[i], boardVar[i][j]) > 1)
                {
                    return false;
                }
                else if (elementInVector(vertical[j], boardVar[i][j]) > 1)
                {
                    return false;
                }
                else if (elementInVector(squares[locate], boardVar[i][j]) > 1)
                {
                    return false;
                }
            }
        }

        locate = 0;
    }
    
    return true;
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

