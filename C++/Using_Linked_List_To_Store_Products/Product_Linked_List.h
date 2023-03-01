#include<iostream>
using namespace std;
struct Product{
		int PID;
		string PNAME;
		int PRICE;
		string CATEGORY;
	};
struct Node
{
	Product product;
	struct Node *next;
};
Node *head;
int cnt;
void push_back(Product product){
	Node* temp = new Node();
	temp->product = product;
	temp->next=NULL;
	if(!head){
		head=temp;
	}
	else{
		Node* lastNode = head;
		while(lastNode->next){
			lastNode = lastNode->next;
		}
		lastNode->next = temp;
	}
	cnt++;
}
Node* pop_back() {
    if (!head) {
        cout << "List is empty" << endl;
        return NULL;
    } else if (head->next == NULL) {
        Node* temp = head;
        head = NULL;
        cnt = 0;
        return temp;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        Node* poppedNode = temp->next;
        temp->next = NULL;
        cnt--;
        return poppedNode;
    }
}
int calculate_total_price() {
    int total_price = 0;
    Node* temp = head;
    while (temp) {
        total_price += temp->product.PRICE;
        temp = temp->next;
    }
    return total_price;
}

void displayNode(Node* node) {
    cout << "PID: " << node->product.PID << endl;
    cout << "PNAME: " << node->product.PNAME << endl;
    cout << "PRICE: " << node->product.PRICE << endl;
    cout << "CATEGORY: " << node->product.CATEGORY << endl;
}

void displayAll(){
	if(head == NULL)
		cout<<"\n No elements in list \n";
	else
	{
		cout<<"Displaying all elements in the linked list: "<<endl;
		for(Node *p=head;p!=NULL;p=p->next)
		{
			displayNode(p);
		}
	}
}

void orderByCategory() {
    if (!head || !head->next) {
        // the list is empty or has only one node, no need to sort
        return;
    }
    
    // use insertion sort to sort the linked list by category
    Node* current = head->next;
    while (current) {
        Node* temp = current->next;
        Node* prev = head;
        while (prev != current) {
            if (prev->product.CATEGORY > current->product.CATEGORY) {
                // swap the two nodes
                Product tempProduct = prev->product;
                prev->product = current->product;
                current->product = tempProduct;
            }
            prev = prev->next;
        }
        current = temp;
    }
}
