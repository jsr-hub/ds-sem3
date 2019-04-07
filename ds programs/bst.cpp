#include<iostream>
using namespace std;
class bst
{
	struct node
	{
		int data;
		struct node *l;
		struct node *r;
	}**root,*par,*walk,*temp;
	public:
	bst()
	{*root=NULL;par=NULL;walk=NULL;}
	void insert(int x)
	{
		temp=new struct node;
		temp->data=x;
		temp->l=temp->r=NULL;
		if(*root==NULL)
		{   
		    *root=temp;
		    return;
		}

		walk=*root;
		par=NULL;
		while(walk!=NULL)
		{
			par=walk;
			if(temp->data<walk->data)
				{walk=walk->l;}
			else if(temp->data>walk->data)
				{walk=walk->r;}
		}
		if(temp->data<par->data)
		{par->l=temp;}
		else
		{par->r=temp;}
		return ;
	}
	int bstdel(struct node **root,int x )
	{
	
		if(*root==NULL)
		{
			cout<<"\n no elements exist"<<endl;
			return 0 ;
		}
		if(x<(*root)->data)
			{ return bstdel(&(*root)->l,x);}
		else if(x>(*root)->data)
			{ return bstdel(&(*root)->r,x);}
		else
		{
			if((*root)->l==NULL)
			{	
				temp=*root;
				*root=(*root)->r;
				delete(temp);
				cout<<"\ndeleted"<<endl;
				return 0;
			}
			else if((*root)->r==NULL)
			{	
				temp=*root;
				*root=(*root)->l;
				delete(temp);
				cout<<"\ndeleted"<<endl;
				return 0 ;
			}
			else 
			{
				temp=(*root)->l;
				while(temp->r!=NULL)
					temp=temp->r;
				(*root)->data=temp->data;
			    return	bstdel(&(*root)->l,temp->data);
			}
		}
	}
	void preorder(node **r)
	{
		if((*r)==NULL)
			return;
		cout<<"\t "<<(*r)->data;
		preorder(&(*r)->l);
		preorder(&(*r)->r);
	}
	void inorder(node **r)
	{
		if((*r)==NULL)
			return;
		inorder(&(*r)->l);
		cout<<"\t "<<(*r)->data;
		inorder(&(*r)->r);
	}
	void postorder(node **r)
	{
		if((*r)==NULL)
			return;
		postorder(&(*r)->l);
		postorder(&(*r)->r);
		cout<<"\t "<<(*r)->data;
		
	}
	void call()
	{	
		int ch,a,a1,i,y;
		do
		{
			cout<<"\n Enter 1 for insert \n 2 for delete \n 3 for travasal  \n4. for exit";
			cin>>ch;
			switch(ch)
			{	
				case 1:
					cout<<"\n Enter the value to be inserted:";
					cin>>y;
					insert(y);
					break;
					
				case 2:
					cout<<"Enter value to be deleted";
					cin>>a;
					cout<<bstdel(&(*root),a);
					break;
				case 3:
					cout<<"\n Enter\n 1.inorder \n 2.preorder \n 3.postorder:"<<endl;	
					cin>>i;
					switch(i)
					{	
						case 1:
							inorder(&(*root));	
							break;
						case 2:
							preorder(&(*root));
							break;
						case 3:
							postorder(&(*root));
							break;
					}break;
				case 4:	
					break;
				
			}
		}while(ch!=4);
	}
};
int main()
{
	bst s;
	s.call();
	return 0;
}

	
