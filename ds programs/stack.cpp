#include<iostream>

using namespace std;
class stack
{
	public:
	int a[5],top;
	stack()
	{
		top=-1;
	}
	void push()
	{
		int x;
		cout<<"Enter d element to be pushed"<<endl;
		cin>>x;
		if(top==5)
		cout<<"stack is overflow...pop d elements"<<endl;
		else
		{
			top++;
			a[top]=x;
			cout<<"Element is pushed succussfully in index:"<<top<<endl;
		}
		cout<<"stack display:"<<endl;
		display();
	}
	void pop()
	{
		if(top==-1)
		cout<<"stack is underflow....push d elemnts "<<endl;
		else
		top--;
		cout<< " one element is poped succussfully"<<endl;
		cout<<"stack display:"<<endl;
		display();
	}
	void peek()
        {
		if(top<0)
		cout<<"STACK EMPTY";
		else
		cout<<"THE TOP ELEMENT OF THE STACK IS:"<<a[top]<<endl;;
	}

	void display()
	{
		if (top==-1)
		cout<<"stack is underflow....push d elemnts "<<endl;
		else
		for(int i=top;i>=0;i--)
		cout<<"\t"<<a[i];
		cout<<endl;	
	}
}ob;
int main()
{
	int c;
	cout<<"\t\t \tstack"<<endl;
	read:
	cout<<"Enter \n 1.push \n 2.pop \n 3.peep \n 4.display\n 5.Exit"<<endl;
	cin>>c;
	
	switch(c)
	{
		case 1:
			ob.push();
			break;
		case 2:
			ob.pop();
			break;
		case 3:
			ob.peek();
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
