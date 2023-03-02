#include<iostream>
#include<string>
#include "vertical_horizontal_linked_lists.h"
int main()
{
	downCnt = 0;
	Reset();
	int ch, ele;
	do
	{
		cout<<"\n1 Insert Node";
		cout<<"\n2 Display";
		cout<<"\n3 Reset";
		cout<<"\n Enter choice = ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					cout<<"Enter the data element: "<<endl;
					cin>>ele;
					NodeInsert(ele);
				break;
			case 2:
					DisplayAll();
				break;
			case 3:
					Reset();
				break;
			default:cout<<"\n Invalid choice \n";
		}
	}while(ch!=9);
	
}
