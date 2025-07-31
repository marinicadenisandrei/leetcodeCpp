/* Leetcode - 206. Reverse Linked List (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
    int size = 0;

public:
    LinkedList() { first = nullptr; }
    LinkedList(vector<int> A);
    ~LinkedList();

    void Display();
    void Reverse();
};

LinkedList::LinkedList(vector<int> A)
{
    if (A.empty())
    {
        first = nullptr;
        return;
    }

    Node *last, *t;
    this->size = A.size();

    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < A.size(); i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (p)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
}

void LinkedList::Display()
{
    Node *p = first;

    cout << (p ? "[" : "[] | ");

    while (p)
    {
        cout << p->data << (p->next ? ", " : "] | ");
        p = p->next;
    }
}

void LinkedList::Reverse()
{
    if (!first) return;

    int *A = new int[size];
    int i = 0;

    Node *q = first;
    while (q != nullptr)
    {
        A[i++] = q->data;
        q = q->next;
    }

    q = first;
    i--;
    while (q != nullptr)
    {
        q->data = A[i--];
        q = q->next;
    }

    delete[] A;
}

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 206. Reverse Linked List (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> head = {{1, 2, 3, 4, 5}, {1, 2}, {}};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        LinkedList l(head[test]);
        l.Reverse();
        l.Display();

        green();

        cout << "Passed" << endl;
    }

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