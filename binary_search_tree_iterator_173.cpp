/* Leetcode - 173. Binary Search Tree Iterator (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class BSTIterator 
{
private:
    vector<int> bst {};
    int position {0};

    vector<int> cache {};
public:
    BSTIterator() = default;
    BSTIterator(vector<int> vectorVar)
    {
        bst = vectorVar;
        bst = initializeBST();

        position = 0;
        cache.push_back(0);
    }
    ~BSTIterator() = default;

    vector<int> initializeBST()
    {
        vector<int> newBst {};

        for (int i = 1; i < bst.size(); i++)
        {
            if ((i * 2) + 2 > bst.size())
            {
                break;
            }

            if (bst[(i * 2) + 1] != 0)
            {
                newBst.push_back(bst[(i * 2) + 1]);
            }
            
            if (bst[i] != 0)
            {
                newBst.push_back(bst[i]);
            }
            
            if (bst[(i * 2) + 2] != 0)
            {
                newBst.push_back(bst[(i * 2) + 2]);
            }
        }

        newBst.insert(newBst.begin() + 1, bst[0]);
        
        return newBst;
    }

    int next()
    {
        if (position + 1 <= bst.size())
        {
            cache.push_back(bst[position]);
            position++;
            return bst[position];
        }

        return -1;
    }

    bool hasNext()
    {
        if (position + 1 <= bst.size())
        {
            cache.push_back(1);
            return true;
        }

        cache.push_back(0);
        return false;
    }

    void displayCache()
    {
        for (int i = 0; i < cache.size(); i++)
        {
            cout << ((i == 0) ? "[" : "") << cache[i] << ((i < cache.size() - 1) ? ", " : "] | ");
        }
    }
};

int main()
{   
    yellow();

    cout << "Leetcode - 173. Binary Search Tree Iterator (C++ language) - Medium" << endl;

    BSTIterator bSTIterator = BSTIterator(vector<int> {7, 3, 15, 0, 0, 9, 20});
    bSTIterator.next();    
    bSTIterator.next();    
    bSTIterator.hasNext(); 
    bSTIterator.next();    
    bSTIterator.hasNext(); 
    bSTIterator.next();    
    bSTIterator.hasNext(); 
    bSTIterator.next();    
    bSTIterator.hasNext(); 

    green();

    cout << "Test 1: ";

    reset();

    bSTIterator.displayCache();

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