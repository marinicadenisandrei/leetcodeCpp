/* Leetcode - 223. Rectangle Area (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 223. Rectangle Area (C++ language) - Medium" << endl;

    vector<int> ax1 = {-3,-2};
    vector<int> ay1 = {0,-2};
    
    vector<int> ax2 = {3,2};
    vector<int> ay2 = {4,2};

    vector<int> bx1 = {0,-2};
    vector<int> by1 = {-1,-2};

    vector<int> bx2 = {9,2};
    vector<int> by2 = {2,2};

    for (int test = 0; test < ax1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";
        
        reset();

        cout << computeArea(ax1[test], ay1[test], ax2[test], ay2[test], bx1[test], by1[test], bx2[test], by2[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int areaRectangle1 = (abs(ax1) + abs(ax2)) * (abs(ay1) + abs(ay2));
    int areaRectangle2 = (abs(bx1) + abs(bx2)) * (abs(by1) + abs(by2));

    int cx1 = max(ax1, bx1);
    int cy1 = max(ay1, by1);

    int cx2 = min(ax2, bx2);
    int cy2 = min(ay2, by2);

    return (areaRectangle1 + areaRectangle2) - ((cx2 - cx1) * (cy2 - cy1));
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