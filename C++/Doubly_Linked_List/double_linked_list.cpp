#include<iostream>
#include "double_linked_list.h"
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
		cout<<"\n4 DeleteBegin";
		cout<<"\n5 Swap Alternate";
		cout<<"\n6 Sort from start to end pos";
		cout<<"\n7 Display";
		cout<<"\n8 Reverse Print";
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
					deleteBegin();
					break;
			case 5:
					swapAlternate();
					break;
			case 6: 
					cout<<"choose start pos: ";
					cin>>start;
					cout<<"choose end pos: ";
					cin>>end;
					sortList(start,end);
			case 7:display();break;
			case 8:printBackToFront();break;
			case 9:break;
			default:cout<<"\n Invalid choice \n";
		}
	}while(ch!=9);
	
}
