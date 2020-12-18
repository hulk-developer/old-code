#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int d, Node *n = nullptr) {
        data = d;
        next = n;
    }
};


class Stack {
public:
    Node *head = nullptr;
    int size = 0;

    int push(int d) {
        Node *node = new Node(d);
        node->next = head;
        head = node;
        return ++size;
    }

    int pop() {
        if (size == 0) {
            cout << "No more data found in the stack" << endl;
            return -1;
        }
        Node *temp = head;
        int ret = temp->data;
        head = temp->next;
        temp->next = nullptr;
        size--;
        delete temp;
        return ret;
    }

    void print() {
        if (size == 0) {
            cout << "No data in the stack!" << endl;
        }
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

};


int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Popping one value: " << s.pop() << endl;
    cout << "Popping one value: " << s.pop() << endl;
    cout << "Popping one value: " << s.pop() << endl;
    s.print();
}