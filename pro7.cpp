#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Linked {
private:
    Node* head;

public:
    Linked() {
        head = NULL;
    }
     void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
        void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
        void insertBeg(int data) {
        Node* newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }
        bool search(int key) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
        void delete_node(int key) {
        Node* temp = head;
        Node* prev = NULL;


        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        
        if (temp == NULL) {
            cout << "Value not found!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
        void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};
#include <iostream>
using namespace std;

int main() {
    Linked list;

    
    list.append(10);
    list.append(20);
    list.append(30);
    list.display();
    list.insertBeg(5);
    list.display();

    if (list.search(20))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    list.delete_node(20);
    list.display();

    list.reverse();
    list.display();

    return 0;
}