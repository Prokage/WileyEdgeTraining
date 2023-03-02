#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
struct DownNode{
	int data;
	struct DownNode *down;
	struct Node *next;
};

DownNode *head;
int downCnt;

void DownNodeInsert(int ele)
{
	DownNode* temp = new DownNode();
	temp->data = ele;
	temp->down = NULL;
	if(!head){
		head=temp;
	}
	else{
		DownNode* lastNode = head;
		while(lastNode->down){
			lastNode = lastNode->down;
		}
		lastNode->down = temp;
	}
	downCnt++;
}

void Reset()
{
	head = NULL;
	for(int i = 0; i < 4; i++){
		DownNodeInsert(i);
	}
}

void NodeInsert(int ele)
{
	int r = ele%4;
	DownNode* lastNode = head;
	Node* insertNode = new Node();
	insertNode->data = ele;
	insertNode->next = NULL;
	while(lastNode && lastNode->data != r) {
        lastNode = lastNode->down;
    }
    if(lastNode) {
        if(!lastNode->next) {
            lastNode->next = insertNode;
        } else {
            Node* lastNodeNext = lastNode->next;
            while(lastNodeNext->next) {
                lastNodeNext = lastNodeNext->next;
            }
            lastNodeNext->next = insertNode;
        }
    } else {
        // handle case where r is not found in the list
        delete insertNode;
        cerr << "Error: r value not found in list" << endl;
    }
}

void DisplayAll()
{
    DownNode* downNode = head;
    while(downNode) {
        cout << downNode->data << ": ";
        Node* node = downNode->next;
        while(node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
        downNode = downNode->down;
    }
}

