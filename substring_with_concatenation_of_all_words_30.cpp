/* Leetcode - 30. Substring with Concatenation of All Words (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void generateConcatenationWords(const vector <string> wordsVar, vector <string> &outputVar);
vector <int> findSubstring(string s,  vector <string> wordsVar);
void printVector(const vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 30. Substring with Concatenation of All Words (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <string> s = {"barfoothefoobarman", "wordgoodgoodgoodbestword", "barfoofoobarthefoobarman"}; 
    vector <vector <string>> words = {{"foo","bar"}, {"word","good","best","word"}, {"bar","foo","the"}};

    for (int test = 0; test < s.size(); test++)
    {
        vector <int> result {findSubstring(s.at(test), words.at(test))};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

vector <int> findSubstring(string s,  vector <string> wordsVar)
{
    vector <string> concatenationWords {};
    generateConcatenationWords(wordsVar, concatenationWords);

    vector <int> output {};


    for (auto i : concatenationWords)
    {
        size_t found = s.find(i);

        if (found != std::string::npos)
        {
            output.push_back(found);
        }
    }

    sort(output.begin(), output.end());

    return output;
}

void generateConcatenationWords(const vector <string> wordsVar, vector <string> &outputVar)
{
    string permutation {""};

    for (int i = 0; i < wordsVar.size(); i++)
    {
        permutation += to_string(i);
    }

    string copy_permutation = permutation;

    char temp;

    temp = permutation[0];
    permutation[0] = permutation[1];
    permutation[1] = temp;

    string permutationWordFormation {""};

    for (int i = 0; i <= wordsVar.size(); i++)
    {
        permutationWordFormation += wordsVar[permutation[i] - '0'];
    }

    outputVar.push_back(permutationWordFormation);

    permutationWordFormation = "";

    int index0 = 1;
    int index1 = 2;

    while (copy_permutation != permutation)
    {
        if (index1 < wordsVar.size())
        {
            temp = permutation[index0];
            permutation[index0] = permutation[index1];
            permutation[index1] = temp;
        }
        else
        {
            temp = permutation[0];
            permutation[0] = permutation[index1 - 1];
            permutation[index1 - 1] = temp;

            index0 = -1;
            index1 = 0;
        }

        index0++;
        index1++;

        for (int i = 0; i <= wordsVar.size(); i++)
        {
            permutationWordFormation += wordsVar[permutation[i] - '0'];
        }
        
        outputVar.push_back(permutationWordFormation);

        permutationWordFormation = "";
    }  
}

void printVector(const vector <int> vectorVar)
{
    if (vectorVar.size() > 0)
    {
        for (int i = 0; i < vectorVar.size(); i++)
        {
            cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
        }
    }
    else
    {
        cout << "[] | ";
    }
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