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

void deleteBegin() {
    if (head == NULL) {
        cout << "\n No elements in list \n";
    } else {
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        cnt--;
    }
}

void printBackToFront() {
    if (head == NULL) {
        cout << "\n No elements in list \n";
    } else {
        Node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        cout << "\n List ele = \n";
        while (p != NULL) {
            cout << p->data << "-->";
            p = p->prev;
        }
    }
}

void deleteEnd() {
    if (!head) {
        cout << "\n No elements in list \n";
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
        cnt = 0;
    } else {
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cnt--;
    }
}

void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
    }
    else if (pos == cnt) {
        deleteEnd();
    }
    else {
        Node *p = head;
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        Node *temp = p->next;
        p->next = temp->next;
        temp->next->prev = p;
        delete temp;
        cnt--;
    }
}

int getNodeValue(int pos) {
    if (pos < 1 || pos > cnt) {
        return -1;
    } else {
        Node *p = head;
        for (int i = 1; i < pos; i++) {
            p = p->next;
        }
        return p->data;
    }
}

Node* getMaxNode() {
    if (!head) {
        return NULL;
    } else {
        int maxVal = head->data;
        Node *maxNode = head;
        for (Node *p = head->next; p != NULL; p = p->next) {
            if (p->data > maxVal) {
                maxVal = p->data;
                maxNode = p;
            }
        }
        return maxNode;
    }
}
Node* getMinNode() {
    if (!head) {
        return NULL;
    } else {
        int minVal = head->data;
        Node *minNode = head;
        for (Node *p = head->next; p != NULL; p = p->next) {
            if (p->data < minVal) {
                minVal = p->data;
                minNode = p;
            }
        }
        return minNode;
    }
}
void swapAlternate() {
    if (!head || !head->next) {
        return;
    } else {
        for (Node *p = head; p != NULL && p->next != NULL; p = p->next->next) {
            int temp = p->data;
            p->data = p->next->data;
            p->next->data = temp;
        }
    }
}
void sortList(int startPos, int endPos) {
    if (startPos < 1 || endPos > cnt || startPos >= endPos) {
        return;
    } else {
        Node *p, *q;
        p = head;
        for (int i = 1; i < startPos; i++) {
            p = p->next;
        }
        for (int i = startPos; i < endPos; i++) {
            q = p->next;
            for (int j = i + 1; j <= endPos; j++) {
                if (p->data > q->data) {
                    int temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->next;
            }
            p = p->next;
        }
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
