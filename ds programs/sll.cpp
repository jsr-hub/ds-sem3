#include<iostream>
using namespace std;
class sll
{
	private:
	struct node
	{
		int data;
		struct node*next;
	}*head,*temp;
	int count;
	public:
	int y;
	sll()
	{
		head=NULL;
		temp=NULL;
	}
	void insertbeg(int val)
	{
		temp=new struct node;
		temp->data=val;
		temp->next=NULL;
		if(head==NULL)
		{
		head=temp;
		}
		else
		{
		temp->next=head;
		head=temp;
		}
	}
	void insertend(int val)
	{
		struct node*temp1;
		temp1=new struct node;
		temp=new struct node;
		temp->data=val;
		temp->next=NULL;
		if(head==NULL)
		{
		head=temp;
		}
		else
		{	
			
			temp1=head;
			while(temp1->next!=NULL)
  			{
				temp1=temp1->next;
			}
			temp1->next=temp;
		}
	}
	void insertpos(int val)
	{
		int pos;
		count=1;
		cout<<"\tEntert the position"<<endl;
		cin>>pos;
		struct node*temp1;
		temp1=new struct node;
		temp=new struct node;
		temp->data=val;
		temp->next=NULL;
		if(head==NULL)
		{
		head=temp;
		}
		else
		{	
			
			temp1=head;
			while(temp1->next!=NULL)
  			{	
				count++;
				if(pos==count)
				break;
				temp1=temp1->next;
				
			}
			temp->next=temp1->next;
			temp1->next=temp;
		
		}
	}
	void del(int val)
	{
		struct node*prev;
		prev=head;
		temp=head;
		while(temp!=NULL && temp->data!=val)
  		{
			prev=temp;
			temp=temp->next;
		}
		if(temp!=NULL && temp->data==val)
		{
			if(temp==head&&temp->next==NULL){
			head=NULL;
			}
			else if(temp==prev)
			{
			head=head->next;
			}
			else
			{
			   prev->next=temp->next;
			}
   			delete temp;
 		 }
  		else	
  		{
  			 cout<<"No such element found";
  		}
	}
	
	void display()
	{
		temp=head;
		while(temp!=NULL)
	  	{
	  		cout<<"\t"<<temp->data;
	   		temp=temp->next;
	  	}
		cout<<endl;
	 }
	
	void search(int val)
	{
		count=1;
		temp=head;
		while(temp!=NULL && temp->data!=val)
		{
			temp=temp->next;
			count++;
		}
		if(temp!=NULL && temp->data==val)
		{
			cout<<"Element found in"<<count;
	  	}
	 	else
	 	{
	 		cout<<"No such element found";
	  	}
	 }
	void call()
	{
		int ch,a,a1,i;
		do
		{
			cout<<"enter 1 for insert \n 2 for delete \n 3 for search  \n 4 for display\n 5 for exit";
			cin>>ch;
			switch(ch)
			{	
				case 1:
					cout<<"enter the value to be inserted";
					cin>>y;
					cout<<"\n enter\n 1.insertbeg \n 2.intestend\n 2.intestpos:"<<endl;	
					cin>>i;
					switch(i)
					{	
						case 1:
							insertbeg(y);	
							break;
						case 2:
							insertend(y);
							break;
						case 3:
							insertpos(y);
							break;
					}break;
				case 2:
					cout<<"enter value to be deleted";
					cin>>a;
					del(a);
					break;
				case 3:
					cout<<"enter value to be searched";
					cin>>a1;
					search(a1);
					break;
				case 4:
					display();		
					break;
				case 5:
					break;
			}
		}while(ch!=5);
	}
};
int main()
{
	sll s;
	s.call();
	return 0;
}
	
	
