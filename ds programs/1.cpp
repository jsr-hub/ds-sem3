#include<iostream>
using namespace std;
int linear_search(int a[],int n,int x)
{
        
	for(int i=0;i<n;i++)
	{	
		if(a[i]==x)
		return i+1;
		
	}
return 0;
}		
int main()
{
	int a[20],x,n,pos;
	cout<<"\t linear search"<<endl;
	cout<<"enter the number of elements:"<<endl;
	cin>>n;
	cout<<"Eneter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	
	cout<<"Enter the elements to be searched:";
	cin>>x;
	pos=linear_search(a,n,x);
	
	if(pos==0)
	cout<<"\nelement not found"<<endl;
	else
	cout<<"\nelement found "<<x<<" at index: "<<pos-1<<endl;
	return 0;
}

