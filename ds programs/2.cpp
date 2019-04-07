#include<iostream>
using namespace std;
int binsearch(int a[],int n,int x)
{	
	int l=0,h=n-1,m;
	
        
	while(l<=h)
	{	
		m=(l+h)/2;
		if(a[m]==x)
		return m+1;
		else
		{
		if(a[m]>x)
		h=m-1;
		
		else if(a[m]<x)
		    l=m+1;
		
		else
			cout<<"error";
		}     
                 	
        }

	
return 0;
}		
int main()
{
	int a[20],x,n,pos,t;
	cout<<"\t binary search"<<endl;
	cout<<"enter the number of elements:"<<endl;
	cin>>n;
	cout<<"Eneter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	
	cout<<"Enter the elements to be searched:";
	cin>>x;
	for(int i=0;i<n;i++)
	for(int j=0;j<n-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	for(int i=0;i<n;i++)
		{
		cout<<a[i]<<endl;
		}
	
	pos=binsearch(a,n,x);
	if(pos==0)
	cout<<"\nelement not found"<<endl;
	else
	cout<<"\nelement found "<<x<<" at index: "<<pos-1<<endl;
	return 0;
}

