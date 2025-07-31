/* Leetcode - 68. Text Justification (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> fullJustify(vector <string> wordsVar, int maxWidthVar);
void printStringVector(vector <string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 68. Text Justification (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <vector <string>> words = {{"This", "is", "an", "example", "of", "text", "justification."}, {"What","must","be","acknowledgment","shall","be"}, {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}};
    vector <int> maxWidth = {16, 16, 20};

    for (int test = 0; test < words.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();
        
        vector <string> output {fullJustify(words[test], maxWidth[test])};
        printStringVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printStringVector(vector <string> vectorVar)
{
    cout << endl << "[";

    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << "|" << vectorVar[i] << "|" << ((i < vectorVar.size() - 1) ? "\n" : "] | ");
    }
}

vector <string> fullJustify(vector <string> wordsVar, int maxWidthVar)
{
    vector <string> formation {""};

    int jusSum {0};

    for (int i = 0; i < wordsVar.size(); i++)
    {
        if (formation[formation.size() - 1].size() + wordsVar[i].size() <= maxWidthVar)
        {
            formation[formation.size() - 1] += wordsVar[i] + " ";
        }
        else
        {
            formation[formation.size() - 1].pop_back();
            formation.push_back("");
            jusSum = 0;
            i--;
        }
    }

    for (int i = 0; i < formation.size(); i++)
    {
        while (formation[i][formation[i].size() - 1] == ' ')
        {
            formation[i].pop_back();
        }
    }

    for (int i = 0; i < formation.size(); i++)
    {
        int counter {0};

        for (int j = 0; j < formation[i].size(); j++)
        {
            if (formation[i][j] == ' ')
            {
                counter++;
            }
        }

        while (formation[i].size() < maxWidthVar)
        {
            if (counter > 0 && i == formation.size() - 1)
            {
                while (formation[i].size() < maxWidthVar)
                {
                    formation[i] += " ";
                }

                break;
            }
            else if (counter > 0)
            {
                for (int j = 0; j < formation[i].size(); j++)
                {
                    if (formation[i][j - 1] != ' ' && formation[i][j] == ' ')
                    {
                        formation[i].insert(j, " ");

                        if (formation[i].size() == maxWidthVar)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                while (formation[i].size() < maxWidthVar)
                {
                    formation[i] += " ";
                }

                break;
            }
        }
    }

    return formation;
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
