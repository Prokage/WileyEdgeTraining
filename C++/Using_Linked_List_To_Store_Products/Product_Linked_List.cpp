#include<iostream>
#include<string>
#include "Product_Linked_List.h"
int main()
{
	head = NULL;
	cnt = 0;
	int ch, PID, PRICE;
	string CATEGORY, PNAME;
	do
	{
		cout<<"\n1 push_back";
		cout<<"\n2 pop_back";
		cout<<"\n3 calculate_total_price";
		cout<<"\n4 order_by_category";
		cout<<"\n7 display_all";
		cout<<"\n9 Exit";
		cout<<"\n Enter choice = ";
		cin>>ch;
		switch(ch)
		{
			case 1:{
					Product p;
				    cout<<"Enter the Product ID: "<<endl;
				    cin>>PID;
				    cout<<"Enter the Product Name: "<<endl;
				    cin>>PNAME;
				    cout<<"Enter the Product Price: "<<endl;
				    cin>>PRICE;
				    cout<<"Enter the Product Category: "<<endl;
				    cin>>CATEGORY;
				    p.PID = PID;
					p.PNAME = PNAME;
					p.PRICE = PRICE;
					p.CATEGORY = CATEGORY;
					
					push_back(p);

			}
				break;
			case 2:{
					Node* poppedNode = pop_back();
					cout<<"Deleted: "<<endl;
					displayNode(poppedNode);
				}
				break;
			case 3:{
					cout<<"Total Price: "<<calculate_total_price()<<endl;
				}
					break;
			case 4:{
					orderByCategory();
					displayAll();
				break;
			}
			case 7:displayAll();break;
			case 9:break;
			default:cout<<"\n Invalid choice \n";
		}
	}while(ch!=9);
	
}
