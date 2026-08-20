/* Leetcode - 382. Linked List Random Node (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <random>

void reset ();
void green ();
void yellow ();
void red ();

class LinkedList {
private:
    int length = 0;
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* head;

    static int randomIndex(int min, int max) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }

public:
    LinkedList() : head(nullptr) {}

    LinkedList(const std::vector<int>& values) : head(nullptr) {
        length = values.size();
        for (auto it = values.rbegin(); it != values.rend(); ++it)
            head = new Node(*it, head);
    }

    ~LinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int getRandom() const {
        Node* temp = head;
        int idx = randomIndex(0, length - 1);

        for (int i = 0; i < idx; i++)
            temp = temp->next;

        return temp->data;
    }

    void pushFront(int value) {
        head = new Node(value, head);
        length++;
    }

    void print() const {
        std::cout << "[";
        for (Node* cur = head; cur; cur = cur->next)
            std::cout << cur->data << ((cur->next != nullptr) ? ", " : "");
        std::cout << "]\n";
    }
};

int main() {
    yellow();

    std::cout << "Leetcode - 382. Linked List Random Node (C++ language) - Medium\n";

    green();

    std::cout << "Test 1: ";

    reset();

    std::vector<int> v = {1, 2, 3};
    LinkedList list(v);
    std::cout << list.getRandom() << " ";
    std::cout << list.getRandom() << " ";
    std::cout << list.getRandom() << " ";
    std::cout << list.getRandom() << " ";
    std::cout << list.getRandom();

    std::cout << " | ";

    green();

    std::cout << "Passed\n";

    reset();
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}