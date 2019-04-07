#include<iostream>

using namespace std;
class queue
{
	public:
	int a[5],front,rear;
	queue()
	{
		front=-1;
		rear=-1;
	}
	void enqueue()
	{
		int x;
		cout<<"Enter d element to be enqueued"<<endl;
		cin>>x;
		if(rear==4)
		{
		cout<<"queue is overflow...pop d elements and retry"<<endl;
		
		}		
		else
		{
			if(front==-1)
			front++;
			rear++;
			a[rear]=x;
			cout<<"Element is pushed succussfully in index:"<<rear<<endl;
		}
		cout<<"queue display:"<<endl;
		display();
	}
	void dequeue()
	{
		if((front==-1)||(front>rear))
		{
			cout<<"queue is underflow....push d elemnts "<<endl;
			if(rear<=front)
			{
				front=-1;
				rear=-1;
			}
		}		
		else
		front++;
		cout<< " one element is poped succussfully"<<endl;
		cout<<"queue display:"<<endl;
		display();
	}
	void search()
	{
		if((front==-1)||(front>rear))
		{
			cout<<"queue is underflow....push d elemnts "<<endl;
		}
		else 
		{	int x,i=front,f=0;
			cout<<"Enter d element to be searched"<<endl;
			cin>>x;
			while(i<=rear)
			{
				if(a[i]==x)
				cout<<"element found at "<<i-front<<" is"<<a[i]<<endl;
				else
				f=1
				i++;
			}
			if(f==1)
			cout<<"element not found"<<endl;
		}
	}
		
	void display()
	{
		if (rear==-1)
		cout<<"stack is underflow....push d elemnts "<<endl;
		else
		
		cout<<"\n correct:"<<endl;
		for(int i=front;i<=rear;i++)
		cout<<"\t"<<a[i];
		cout<<endl;	
	}
}ob;
int main()
{
	int c;
	cout<<"\t\t \tqueue"<<endl;
	read:
	cout<<"Enter \n 1.Enqueue \n 2.Dequeue \n 3.search \n 4.display\n 5.Exit"<<endl;
	cin>>c;
	
	switch(c)
	{
		case 1:
			ob.enqueue();
			break;
		case 2:
			ob.dequeue();
			break;
		case 3:
			ob.search();
			break;
		case 4:
			ob.display();
			break;
		case 5: 
			return 0;
		
		default:
			cout<<"something went wrong.........re-enter"<<endl;
	}
	goto read;
	return 0;
}
