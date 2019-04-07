#include<iostream>
using namespace std;
class sll
{
	private:
	struct node
	{
		int data;
		struct node*slink;
		struct node*plink;
	}*head,*temp,*end;
	int count;
	public:
	int y;
	sll()
	{
		head=NULL;
		end=NULL;
	}
	void insertbeg(int val)
	{
		temp=new struct node;
		temp->slink=temp;
		temp->plink=temp;
		temp->data=val;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			
			temp->plink=head->plink;
			temp->slink=head;
	t		head->plink->slink=temp;
			head->plink=temp;
			head=temp;
		}		
	}
	void insertend(int val)
	{
		struct node*temp1;
		temp1=head;
		temp=new struct node;
		temp->data=val;
		temp->slink=temp;
		temp->plink=temp;
		
		if(head==NULL)
		{
		head=temp;
		}
		else
		{	
			while(temp1!=NULL)
			temp1=temp1->slink
			temp1=head->plink;
			temp->slink=head;
			head->plink=temp;
			temp1->slink=temp;
			
		}
	}
	void insertpos(int val)
	{
		int pos;
		count=0;
		cout<<"\tEntert the position"<<endl;
		cin>>pos;
		struct node*temp1;
		temp=new struct node;
		temp->data=val;
		temp->slink=temp;
		temp->plink=temp;
		if(head==NULL)
		{
		head=temp;
		}
		else
		{	
			
			temp1=head;
			while(temp1!=NULL)
  			{	
				count++;
				if(pos==count)
				break;
				temp1=temp1->slink;
				
			}
			
			temp->plink=temp1;
			temp->slink=temp1->slink;
			temp1->slink->plink=temp;
			temp1->slink=temp;
			
		
		}
	}
	void del(int val)
	{
		if(head==NULL){
			 cout<<"No such element found";
			return;}
		
		if(head->slink==head && head->data==val){
			delete(head);
			head=NULL;
			return;
		}
		temp=head;
		while(temp!=NULL && temp->data!=val)
  		{
			
			temp=temp->slink;
			if(temp==head)
			break;
		}
		if(temp!=NULL && temp->data==val)
		{
			
			if(temp==head)
			{
			head=temp->slink;
			head->plink=temp->plink;
			temp->plink->slink=head;
			}
			else
			{
				
				 	temp->plink->slink=temp->slink;
					temp->slink->plink=temp->plink;
				
				
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
	   		temp=temp->slink;
			if(temp==head)
			break;
	  	}
		cout<<endl;
	 }
	
	
	void search(int l)
	{
		count=1;
		int f=0;
		temp=head;
		while(temp!=NULL)
		{
			
			if(temp!=NULL && l==count)
			{
				cout<<"Element found is"<<temp->data<<endl;
				f=1;
	  		}
	 		
	 			
			temp=temp->slink;
		count++;
		if(temp==head)
			break;
		}
		if(f==0)
		cout<<"No such element found";
	  		
		
	 }
	void call()
	{
		int ch,a,a1,i;
		do
		{
			cout<<"\n Enter 1 for insert \n 2 for delete \n 3 for search  \n 4 for display\n 5 for exit";
			cin>>ch;
			switch(ch)
			{	
				case 1:
					cout<<"\n Enter the value to be inserted:";
					cin>>y;
					cout<<"\n Enter\n 1.insertbeg \n 2.intestend\n 2.intestpos:"<<endl;	
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
					cout<<"Enter value to be deleted";
					cin>>a;
					del(a);
					break;
				case 3:
					cout<<"Enter location of element to display";
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
	
	
