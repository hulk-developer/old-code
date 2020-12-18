#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next = nullptr;

    Node(int d, Node *n = nullptr) {
        data = d;
        next = n;
    }
};


class Queue {
public:
    int size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

    int enqueue(int d) {
        Node *node = new Node(d);
        if (size == 0) {
            head = node;
            tail = node;
            return ++size;
        }
        tail->next = node;
        tail = node;
        return ++size;
    }

    int dequeue() {
        if (size == 0) {
            cout << "No more data in the Queue" << endl;
            return -1;
        } else if (size == 1) {
            Node *temp = head;
            int data = temp->data;
            head = nullptr;
            tail = nullptr;
            size--;
            delete temp;
            return data;
        }
        Node *temp = head;
        int data = temp->data;
        head = temp->next;
        size--;
        delete temp;
        return data;
    }

    void print() {
        if (size == 0) {
            cout << "No data found to print" << endl;
        }
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.print();
    cout << "Removing -> " << q.dequeue() << endl;
    cout << "Removing -> " << q.dequeue() << endl;
    cout << "Pushing 100. Now size = " << q.enqueue(100) << endl;
    q.print();
    cout << "Removing -> " << q.dequeue() << endl;
}