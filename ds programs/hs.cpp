#include<iostream>
using namespace std;
class hash
{
	private:
	struct node
	{
		int data;
		struct node*next;
	}*temp;
	struct tab
	{
		struct node*next;
	}*t[4];

	int count,a[10],n,m;
	public:
	int y;
	hash(int size)
	{
		for(int i=0;i<4;i++)
			t[i]=new tab;		
		
		temp=NULL;
		n=size;
	}
/*	~hash()
	{
		delete tab;
	}*/
	void insert(int val,int m)
	{
		struct node*temp1;
		//t[m]=new struct tab;
		temp=new struct node;
		temp->data=val;
		temp->next=NULL;
		if(t[m]->next==NULL)
		{
		t[m]->next=temp;
		}
		else
		{	
			
			temp1=t[m]->next;
			while(temp1->next!=NULL)
  			{
				temp1=temp1->next;
			}
			temp1->next=temp;
		}
	}
	void search(int val,int m)
	{
		count=1;
		temp=t[m]->next;
		while(temp!=NULL && temp->data!=val)
		{
			temp=temp->next;
			count++;
		}
		if(temp!=NULL && temp->data==val)
		{
			cout<<"Element found in bucket: "<<m<<"and in index: "<<count<<endl;;
	  	} 
	 	else
	 	{
	 		cout<<"No such element found";
	  	}
	 }
	
	void call()
	{
		int ch=1,y;
		
		cout<<"\nEnter the  elements in array:"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			m=a[i]%4;
			insert(a[i],m);	
		}

		do
		{
			cout<<"enter the element to be searched:";
			cin>>y;
			search(y,(y%n));	
			cout<<"Enter 1 to research"<<endl;
			cin>>ch	;
			
			
		}while(ch!=0);
		
	}
};
int main()
{
	int n;
	cout<<"\nEnter the number of elements in array:"<<endl;
		cin>>n;
		
	hash s(n);
	s.call();
	return 0;
}
