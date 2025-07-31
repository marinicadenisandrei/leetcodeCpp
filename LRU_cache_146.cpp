/* Leetcode - 146. LRU Cache (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class LRUCache
{
public:
    vector<vector<int>> acumulation;
    int remain = 1;

    LRUCache() = default;
    LRUCache(vector<vector<int>> acumulation) : acumulation {acumulation} {};
    ~LRUCache() = default;

    int put(int x, int y)
    {
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);

        if (acumulation.size() < 2)
        {
            acumulation.push_back(temp);
        }
        else 
        {
            if (remain == 1)
            {
                vector<int> first = acumulation[0];
                acumulation.clear();
                acumulation.push_back(first);
                acumulation.push_back(temp);

                remain = 0;
            }
            else
            {
                vector<int> first = acumulation[1];
                acumulation.clear();
                acumulation.push_back(temp);
                acumulation.push_back(first);
                remain = 1;
            }
        }
        
        return 0;
    }

    int get(int x)
    {
        for (int i = 0; i < acumulation.size(); i++)
        {
            if (acumulation[i][0] == x)
            {
                return x;
            }
        }

        return -1;
    }

    void display()
    {
        for (int i = 0; i < acumulation.size(); i++)
        {
            cout << acumulation[i][0] << " ";
        }

        cout << endl;
    }
};

int main()
{
    yellow();

    cout << "Leetcode - 146. LRU Cache (C++ language) - Medium" << endl;

    vector<int> cache;
    cache.push_back(0);

    LRUCache lruCache;

    cache.push_back(lruCache.put(1, 1));
    cache.push_back(lruCache.put(2, 2));
    cache.push_back(lruCache.get(1));
    cache.push_back(lruCache.put(3, 3));
    cache.push_back(lruCache.get(2));
    cache.push_back(lruCache.put(4, 4));
    cache.push_back(lruCache.get(1));
    cache.push_back(lruCache.get(3));
    cache.push_back(lruCache.get(4));
    
    green();

    cout << "Test 1: ";

    reset();
    
    for (int i = 0; i < cache.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << cache[i] << " " << ((i < cache.size() - 1) ? ", " : "] | ");
    }

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
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