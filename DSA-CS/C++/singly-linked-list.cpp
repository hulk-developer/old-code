#include <iostream>

using namespace std;

class Node {
public:
    int _data;
    Node *_next;

    explicit Node(int data, Node *next = nullptr) {
        _data = data;
        if (next != nullptr) {
            _next = next;
        }
    }
};


class SLL {
public:
    Node *head = nullptr;
    int size = 0;

    void insertFirst(int data) {
        head = new Node(data, head);
        size++;
    }

    void printList() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->_data << "  ";
            current = current->_next;
        }
        cout << endl;
    }

    void insertLast(int data) {
        Node *temp = new Node(data);
        Node *current = head;
        Node *prev = nullptr;
        while (current != nullptr) {
            prev = current;
            current = current->_next;
        }
        if (prev != nullptr) {
            prev->_next = temp;
            size++;
        }
    }

    void at(int pos) {
        Node *temp = head;
        try {
            for (int i = 0; i < pos; i++) {
                if(temp == nullptr) {
                    throw -1;
                }
                temp = temp->_next;
            }
            cout << temp->_data << endl;
        } catch (int z) {
            cout << "Linked list only contains " << size << " nodes" << endl;
        }
    }

    void removeAt(int pos) {
        Node* current = head;
        Node* prev = nullptr;
        try {
            if(pos >= size) {
                throw -1;
            }

            if(pos == 0) {
                head = current->_next;
                delete current;
                return;
            }

            for(int i=0; i<pos; i++){
                prev = current;
                current = current->_next;
            }
            prev->_next = current->_next;
            size--;
            delete current;
        } catch (int z) {
            cout << "No element at the specified position" << endl;
        }
    }
};

