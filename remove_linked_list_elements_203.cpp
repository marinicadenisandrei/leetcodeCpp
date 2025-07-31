/* Leetcode - 203. Remove Linked List Elements (C++ language) - Easy */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(const vector<int>& headVar);
void display(struct Node *p);
void removeElements(struct Node*& headVar, int valVar);

void reset ();
void green ();
void yellow ();
void red ();

int main() {
    yellow();

    cout << "Leetcode - 203. Remove Linked List Elements (C++ language) - ";
    
    green();

    cout << "Easy" << endl;
    
    vector<vector<int>> head = {{1,2,6,3,4,5,6},{},{7,7,7,7}};
    vector<int> val = {6,1,7};
    
    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        create(head[test]);
        removeElements(first, val[test]);
        display(first);

        first = NULL;

        green();

        cout << "Passed" << endl;
    }

    reset();

    free(first);

    return 0;
}

void create(const vector<int>& headVar) {
    if (headVar.size() == 0)
    {   
        first = NULL;
        return;
    }

    struct Node *last, *t;
    first = new Node{headVar[0], NULL};
    last = first;

    for (size_t i = 1; i < headVar.size(); i++) {
        t = new Node{headVar[i], NULL};
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    if (p == NULL)
    {
        printf("[] | ");
        return;
    }

    cout << "[";
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) cout << ", ";
        p = p->next;
    }
    cout << "] | ";
}

void removeElements(struct Node*& headVar, int valVar) {
    Node *current = headVar, *prev = NULL;

    while (current != NULL) {
        if (current->data == valVar) {
            if (prev == NULL) {
                Node *temp = current;
                headVar = current->next;
                current = headVar;
                delete temp;
            } else {
                Node *temp = current;
                prev->next = current->next;
                current = current->next;
                delete temp;
            }
        } else {
            prev = current;
            current = current->next;
        }
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
