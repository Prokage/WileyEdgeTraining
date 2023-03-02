#include<iostream>
#include"double_linked_list.h"
using namespace std;
int main()
{
	head = NULL;
	cnt =0;
	int ch,ele,pos,start,end;
	do
	{
		cout<<"\n1 InsertBegin";
		cout<<"\n2 InsertEnd";
		cout<<"\n3 InsertPos";
		cout<<"\n4 Display";
		cout<<"\n9 Exit";
		cout<<"\n Enter choice = ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				    cout<<"\n Enter the ele = ";
				    cin>>ele;
					insertBegin(ele);
			       break;
			case 2:
					cout<<"\n Enter the ele = ";
					cin>>ele;
					insertEnd(ele);
					break;
			case 3:
					cout<<"\n Enter the position = ";
					cin>>pos;
					cout<<"\n Enter the ele = ";
					cin>>ele;
					insertPos(pos,ele);
					break;
			case 4:
					display();break;
			case 9:break;
			default:cout<<"\n Invalid choice \n";
		}
	}while(ch!=9);
	
}
