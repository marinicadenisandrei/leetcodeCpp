/* Leetcode - 332. Reconstruct Itinerary (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<string> findItinerary(vector<vector<string>> ticketsVar);
void printVector(vector<string> vect);

int main()
{
    yellow();
    
    cout << "Leetcode - 332. Reconstruct Itinerary (C++ language) - ";
    
    red();

    cout << "Hard" << endl;

    vector<vector<vector<string>>> tickets = {{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}},
                                     {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}};
    
    for (int test = 0; test < tickets.size(); test++)
    {
        green();

        cout <<  "Test " << test + 1 << ": ";

        reset();

        printVector(findItinerary(tickets[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<string> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");   
    }
}

vector<string> findItinerary(vector<vector<string>> ticketsVar)
{
    vector<vector<string>> formation = {};
    vector<string> result = {};

    formation.push_back(ticketsVar[0]);

    ticketsVar.erase(ticketsVar.begin() + 0);

    bool flag = true;

    while (flag)
    {
        flag = false;
        
        for (int i = 0; i < ticketsVar.size(); i++)
        {
            if (ticketsVar[i][0] == formation[formation.size() - 1][1])
            {
                formation.push_back(ticketsVar[i]);
                ticketsVar.erase(ticketsVar.begin() + i);
                flag = true;

                break;
            }
        }
    }

    for (int i = 0; i < ticketsVar.size(); i++)
    {
        for (int j = 0; j < formation.size(); j++)
        {
            if (ticketsVar[i][1] == formation[j][0])
            {
                formation.insert(formation.begin() + ((j == 0) ? 0 : j - 1), ticketsVar[i]);
                break;
            }   
        }
    }
    

    result.push_back(formation[0][0]);

    for (int i = 0; i < formation.size(); i++)
    {
        result.push_back(formation[i][1]);
    }
    
    
    return result;
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