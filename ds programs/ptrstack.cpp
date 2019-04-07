#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *link;
};
class stack
{
	node *head;
	int top;
	public:
	stack()
	{top=-1;
         head=NULL;}
	void push()
	{
		int datain;
		cout<<"Enter d element to be pushed"<<endl;
		cin>>datain;
		if(top<5)
		{
			node *newnode = new node;
			
			newnode->data=datain;
			newnode->link=head;
			head=newnode;
			top++;
		}
		else
		{
			
				cout<<"stack overflow"<<endl;
				return;	
			
		}
	}
	void display()
	{
		
		node *temp;
		temp=head;
		if(top<0)
		{
			cout<<"underflow"<<endl;
			return;
		}
		while(temp!=NULL)
		{
			cout<<"\t"<<temp->data;
			temp=temp->link;
		}
	}
};
int main()
{
	stack o;
	o.push();
	o.push();
	o.push();
	o.display();
	return 0;
}

			
