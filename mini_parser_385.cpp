/* Leetcode - 385. Mini Parser (C++ language) - Medium */

#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class NestedInteger {
    std::variant<int, std::vector<NestedInteger>> data;
public:
    NestedInteger() : data(std::vector<NestedInteger>{}) {}   
    explicit NestedInteger(int v) : data(v) {}

    bool isInteger() const { return std::holds_alternative<int>(data); }
    int  getInteger() const { return std::get<int>(data); }

    const std::vector<NestedInteger>& getList() const {
        return std::get<std::vector<NestedInteger>>(data);
    }

    void setInteger(int v) { data = v; }

    void add(NestedInteger ni) {
        if (isInteger()) data = std::vector<NestedInteger>{};
        std::get<std::vector<NestedInteger>>(data).push_back(std::move(ni));
    }
};

NestedInteger deserialize(string sVar);
void printNestedInteger(const NestedInteger &ni);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 385. Mini Parser (C++ language) - Medium" << endl;

    vector<string> s = {"324","[123,[456,[789]]]"};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printNestedInteger(deserialize(s[test]));

        cout << " | ";

        green();
        
        cout << "Passed\n";
    }

    reset();

    return 0;
}

NestedInteger deserialize(string sVar)
{
    if (sVar.empty()) return NestedInteger();
    if (sVar[0] != '[') return NestedInteger(stoi(sVar));

    vector<NestedInteger> path(1);
    int indent = 0;

    for (int i = 1; i < (int)sVar.size(); i++)
    {
        if (isdigit((unsigned char)sVar[i]) ||
            (sVar[i] == '-' && isdigit((unsigned char)sVar[i + 1])))
        {
            string temp = "";
            temp += sVar[i];

            int j = i + 1;

            while (j < (int)sVar.size() && isdigit((unsigned char)sVar[j]))
            {
                temp += sVar[j];
                j++;
            }

            path[indent].add(NestedInteger(stoi(temp)));
            i = j - 1;
        }
        else if (sVar[i] == '[')
        {
            indent++;
            if ((int)path.size() <= indent) path.resize(indent + 1);
            path[indent] = NestedInteger();
        }
        else if (sVar[i] == ']')
        {
            indent--;
            if (indent < 0) break;              
            path[indent].add(path[indent + 1]);
        }
    }

    return path[0];
}

void printNestedInteger(const NestedInteger &ni)
{
    if (ni.isInteger())
    {
        cout << ni.getInteger();
        return;
    }

    cout << '[';
    const vector<NestedInteger> &list = ni.getList();
    for (size_t i = 0; i < list.size(); i++)
    {
        if (i > 0) cout << ',';
        printNestedInteger(list[i]);
    }
    cout << ']';
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