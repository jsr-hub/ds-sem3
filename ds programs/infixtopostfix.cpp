#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

char* conv(char* s,int n);

int pri(char s)
{
	if(s=='+'||s=='-')
		return 1;
	else if(s=='*'||s=='/')
		return 2;
	else if(s=='^')
		return 3;
}

void push(char* s,int &top,char x,int n)
{
	if(top>=n-1)
		cout<<"Stack Overflow";
	else
	{
		top++;
		s[top]=x;
	}
}

char pop(char* s,int &top)
{
	char temp;
	if(top==-1)
		cout<<"Stack UNderflow";
	else
	{
		temp=s[top];
		top--;
		return temp;
	}
}

char peek(char* s,int top)
{
	if(top==-1)
		cout<<"Stack Empty";
	else
	{
		return(s[top]);
	}
}

int main()
{
	char* s;
	int n;
	char* post;
	/**/cout<<"enter the size of the infix expression";	
	cin>>n;	
	s=new char[n];
	post=new char[n];/**/
	cout<<"Enter the infix expression";
	cin>>s;
	//n=strlen(s);
	cout<<n;
	post=conv(s,n);
	cout<<"The postfix expression is"<<post;
	return 0;
}

char* conv(char* s,int n)
{
	char* stk;int top;
	char* post;int t;
	char temp;
	post=new char[n];
	stk=new char[n];	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
			push(stk,top,s[i],n);
		else if(s[i]==')')
		{
			do
			{
				temp=pop(stk,top);
				if(temp!='('||temp!=')')
					push(post,t,temp,n);
			}while(peek(stk,top)!='(');
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
		{
			while((pri(s[i])<=pri(peek(stk,top)))&&top!=-1)
			{
				temp=pop(stk,top);
				push(post,t,temp,n);
			}
			push(stk,top,s[i],n);
		}
		else if(isalpha(s[i]))
		{
			push(post,t,s[i],n);
		}
		else if(s[i]=='\0')
		{
			while(top!=-1)
			{
				temp=pop(stk,top);
				push(post,t,temp,n);
			}
		}
	}
	return post;
}
