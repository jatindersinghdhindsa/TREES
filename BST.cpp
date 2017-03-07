#include<iostream>
#include<queue>
using namespace std;
class bst
{
	struct node
	{
		int data;
		struct node *l,*r;
	};
	public:
		int h;
	struct node *root;
	struct node *parent;
	public:
		bst()
		{
			h=0;
		root=NULL;
			
	    }
		struct node * create(node *root,int d)
		{
	
				if(root==NULL)
			     {
			     	root=newnode(root,d);
				 }
				else
				{
				 	if(d>root->data)
				 	{
				 		root->r=create(root->r,d);
					}
					else if(d<root->data)
					{
						root->l=create(root->l,d);
					}
				 }
			return root;
		}
			struct node * newnode(struct node *nn,int d)
		{
		//	struct node *nn;
			nn=new node;
			nn->data=d;
			nn->r=NULL;
			nn->l=NULL;
			return nn;
		}
		void show()
		{
			display(root);
		}
		void display(node *root)
		{
			if(root==NULL)
			{
				return;
			}
			else{
		    cout<<root->data<<" ";
			display(root->l);
			
			display(root->r);
		}
		}
	struct node * search(int it)
		{
			int flag=0;
			node *ptr;
			if(root==NULL)
			{
				cout<<"empty\n";
			}
			else
			{
				ptr=root;
				while(ptr!=NULL){
				if(it>ptr->data)
				{
					parent=ptr;
					ptr=ptr->r;
				}
				else if(it<ptr->data)
				{
					parent=ptr;
					ptr=ptr->l;
				}
				else if(ptr->data==it)
				{
					flag=1;
					cout<<"found\n";
					break;
				}
			}
		}
		if(flag==0)
		{
			cout<<"not found\n";
		}
		return ptr;
		}
		void min_max()
		{
			node *p=root;
			while(p->l!=NULL)
			{
				p=p->l;
			}
			cout<<"minimun element="<<p->data<<endl;
			p=root;
			while(p->r!=NULL)
			{
				p=p->r;
			}
			cout<<"maximum element="<<p->data<<endl;
		}
		void deletee(int it)
		{
			struct node *q,*p;
			if(root==NULL)
			{
				cout<<"empty\n";
			}
			else
			{
			    p=search(it);
			    if(p==NULL)
			    {
			    	cout<<"element not found\n";
			    	return;
				}    
				
					if(p->l==NULL && p->r==NULL)
					{
						delete_null(p);
					}
					else if(p->l!=NULL &&p->r==NULL)
					{
						delete_left(p);
					}
					else if(p->r!=NULL && p->l==NULL)
					{
						delete_right(p);
					}
				    else if(p->l!=NULL && p->r!=NULL)
				    {
				    	delete_B(p,it);
					}
					}	
	}
	void delete_right(node *p)
	{
		if(p->r!=NULL && parent->r==p)
		{
			parent->r=p->l;
		}
	}
	void delete_left(node *p)
	{
		if(p->l!=NULL && p->r==NULL && parent->l==p)
		{
			parent->l=p->l;
		}
			if(p->l!=NULL && p->r==NULL && parent->r==p)
		{
			parent->r=p->l;
		}
		
	}
	void delete_null(node *p)
	{
		if(p->l==NULL && p->r==NULL &&parent->l==p)
		{
			parent->l=NULL;
		}
		else if(p->l==NULL && p->r==NULL &&parent->r==p)
		{
			parent->r=NULL;
		}
	}
	void delete_A(node *p)
	{
		node *child;
	  if(p->l==NULL && p->r==NULL)
	  {
	  	parent->l=NULL;
	  }
	  if(p->l!=NULL)
	  {
	  	parent->l=p->l;
		  }
		  else if(p->r!=NULL)	
		  {
		  	parent->r=p->r;
		  }	
	}	
	void delete_B(node *p,int it)
	{
			node *q,*s;
			//p=root;
			q=root;
			
			p=search(it);
			q=p->r;
			while(q->l!=NULL)
			{
				s=q;
				q=q->l;
			}
			p->data=q->data;
			q->l=NULL;
			
	}
		void level_print(int h)
		{
		
		for(int i=1;i<=h;i++)
		{
			level(root,i);
		}
		}
		void level(node *root,int l)
		{
	    
		if(root==NULL)
		{
			return;
		}
		if(l==1)
		{
			cout<<root->data<<" ";
		}
		else if(l>1){
	
			level(root->l,l-1);
			level(root->r,l-1);
		
		}
	}
		int height(node *root)
		{
			node *p;
			p=root;
			
			if(root==NULL)
			{
				return 0;
			}
			else
			{
			   int	c1=height(root->l);
				int c2=height(root->r);
				if(c1>c2)
				{
					return c1+1;
				}
				else
				{
				return c2+1;
				}
			}
		
		}

int height1(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	return max(height1(root->l),height1(root->r)+1);
}
node * insert_proper(node * root, int value)
{

   if(root==NULL)
       {
       node *nn;
       nn=new node;
       nn->data=value;
       nn->l=nn->r=NULL;
       root=nn;
       return root;
   }
    else
        {
        if(value>root->data)
            {
            root->r=insert_proper(root->r,value);
        }
        else
            {
            root->l=insert_proper(root->l,value);
        }
    }
   return root;
}
int isBST(struct node* node) 
{ 
  return (isBSTUtil(node, INT_MIN, INT_MAX)); 
} 

int isBSTUtil(struct node* node, int min, int max) 
{ 
  if (node==NULL) 
     return 1;
       
  if (node->data < min || node->data > max) 
     return 0; 
  return
    isBSTUtil(node->l, min, node->data-1) && isBSTUtil(node->r, node->data+1, max);  
} 
};
main()
{
	bst s1;
	int n,d,h;
	while(n!=-1){
	cout<<"\nenter 1 to create\n";
	cout<<"enter 2 to display\n";
	cout<<"enter 3 to search\n";
	cout<<"enter 4 to to find max and min element\n";
	cout<<"enter 5 to delete \n";
	cout<<"enter 6 to print level\n";
	cout<<" 7 to print height\n";
	cout<<"8 to insert at proper position\n";
	cout<<"9 to check bst or not\n";
	cin>>n;
	switch(n)
	{
		case 1:
			{
				cin>>d;
			while(d!=-1){
			s1.root=s1.create(s1.root,d);
			cin>>d;
		}
			break;
		}
		case 2:
			{
			s1.display(s1.root);
			break;
		}
		case 3:
			{
				int g;
				cout<<"enter data to search\n";
				cin>>g;
				s1.search(g);
				break;
			}
			case 4:
				{
					s1.min_max();
					break;
				}
				case 5:
					{
						int it;
						cout<<"enter element to delete\n";
						cin>>it;
						s1.deletee(it);
						break;
					}
					case 6:
						{
							s1.level_print(h);
							break;
						}	
						case 7:
							{
								h=s1.height1(s1.root);
								cout<<"height=="<<h<<endl;
								break;
							}
							case 8:
								{
									int s;
									cout<<"enter value to insert\n";
									cin>>s;
									s1.insert_proper(s1.root,s);
									break;
								}
								case 9:
									{
										if(s1.isBST(s1.root))
										cout<<"bst\n";
										else 
										cout<<"not\n";
										break;
									}
	}
}
}
