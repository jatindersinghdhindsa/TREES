#include<iostream>
using namespace std;
class hello
{
	struct node
	{
	int data;
	node *r,*l;	
	};
	public:
		struct node *par=NULL;

		int flag;
		node *root;
		hello()
		{
			root=NULL;
			flag=0;
		}
		void create()
		{
			int d;
			cout<<"enter data\n";
			cin>>d;
			node *nn;
			while(d!=-1)
			{
				if(root==NULL)
				{
					nn=new node;
					nn->data=d;
					nn->r=NULL;
					nn->l=NULL;
					root=nn;
					
				}
				else
				{
					node *c;
					c=root;
					while(root!=NULL){
					if(d>root->data)
					{
						if(c->r==NULL)
						{
							nn=new node;
							nn->data=d;
							nn->r=NULL;
							nn->l=NULL;
							c->r=nn;
							break;
						}
						else
						{
						   c=c->r;	
						}
					}
					else
					{
						if(c->l==NULL)
						{
							nn=new node;
							nn->data=d;
							nn->r=NULL;
							nn->l=NULL;
							c->l=nn;
							break;
						}
						else
						{
						c=c->l;	
						}
						
					}
					
				}
			}
				cin>>d;
			}
		}
		void display1()
		{
			display(root);
		}
		void display(node *p)
		{
			if(root==NULL)
			{
			cout<<"empty\n";	
			}
			if(p!=NULL)
			{
				display(p->l);
				cout<<p->data<<" ";
				display(p->r);
			}
		}
		node* search(node *p,int g)
		{
		   node *loc,*ptr;
		   flag=0;
			if(p==NULL)
			{
			cout<<"empty tree\n";
			return p;
			}
			else
			{
				ptr=root;
				while(ptr!=N)
				if(g>ptr->data)
				{
					par=ptr;
					ptr=ptr->r;
				}
				else if(g<ptr->data)
				{
					par=ptr;
					ptr=ptr->l;
				}
				else
				{
					cout<<"element found\n";
				}
				return ptr;
			}
			
		}
	void min_max(node *temp)
{
    while (temp->l != NULL)
        temp = temp->l;
    cout<<"Minimum value =\n"<<temp->data;
    temp = root;
    while (temp->r != NULL)
        temp = temp->r;
    cout<<"Maximum value  = \n"<<temp->data;
}
};
main()
{
	hello s1;
	int n,g;
	struct node *f;
	while(n!=-1){
	cout<<"\nenter 1 to create tree\n";
	cout<<"enter 2 to display\n";
	cout<<"enter 3 to search\n";
	cout<<"enter 4 to min and max\n";
	cin>>n;
	switch(n)
	{
		case 1:
			{
				s1.create();
				break;
			}
			case 2:
				{
					s1.display1();
					break;
				}
				case 3:
					{
						cout<<"enter element to search\n";
						cin>>g;
					s1.search(s1.root,g);
					break;
					}
					case 4:
						{
						s1.min_max(s1.root);
						break;	
						}
						case 5:
							{
								//s1.deletee();
								break;
							}
	}
}
}
