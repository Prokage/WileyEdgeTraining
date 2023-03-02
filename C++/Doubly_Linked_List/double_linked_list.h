#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

Node *head;
int cnt;

void insertBegin(int ele) {
    Node *temp = new Node();
    temp->data = ele;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
    }
    else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    cnt++;    
}

void insertEnd(int ele) {
    Node *temp = new Node();
    temp->data = ele;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
    }
    else {
        Node *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = temp;
        temp->prev = lastNode;
    }
    cnt++;
}

void insertPos(int pos, int ele) {
    if (pos == 1) {
        insertBegin(ele);
    }
    else if (pos > cnt) {
        insertEnd(ele);
    }
    else {
        Node *temp = new Node();
        temp->data = ele;
        temp->next = NULL;
        temp->prev = NULL;

        Node *p = head;
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
        temp->prev = p;
        cnt++;
    }
}

void display() {
    if (head == NULL) {
        cout << "\n No elements in list \n";
    }
    else {
        cout << "\n List ele = \n";
        for (Node *p = head; p != NULL; p = p->next) {
        	cout << p->data << "<-->";
        }
    }
}
