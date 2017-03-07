#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
class test
{
    struct node
    {
        int data;
        struct node * l;
        struct node * r;
    };
    public:
    node *root,*root1;
    test()
        {
        root=NULL;
        root1=NULL;
    }
    node * create(node *root,int d)
        {
        node *nn;
        if(root==NULL)
            {
            nn=new node;
            nn->data=d;
            nn->l=nn->r=NULL;
            root=nn;
        }
        else
            {
            if(d>root->data)
                {
                root->r=create(root->r,d);
            }
        
        else if(d<=root->data)
            {
             root->l=create(root->l,d);
        }
        }
       return root; 
    }
       node * mirror(node *root,int d)
        {
           node *nn;
        if(root==NULL)
            {
            nn=new node;
            nn->data=d;
            nn->l=nn->r=NULL;
            root=nn;
        }
        else
            {
            if(d<=root->data)
                {
                root->r=mirror(root->r,d);
            }
        
        else if(d>root->data)
            {
             root->l=mirror(root->l,d);
        }
        }
       return root; 
    }
    int height(node *r)
        {
        if(r==NULL)
            return 0;
        return max(height(r->l)+1,height(r->r)+1);
    }
    void level(node *r,int l)
        {
        if(r==NULL)
            return;
            if(l==1)
            cout<<r->data<<" ";
            else if(l>1)
            {
            level(r->l,l-1);
            level(r->r,l-1);
        }
    }
};
 int main()
    {
    test s1;
    int d;
    cin>>d;
    int a[100],k=0;
    while(d!=-1)
        {
        a[k]=d;
        k++;
        s1.root=s1.create(s1.root,d);
        cin>>d;
    }
    int h=s1.height(s1.root);
    for(int i=1;i<=h;i++)
        {
        s1.level(s1.root,i);
    }
    cout<<endl;
    int j=0;
    while(j!=k)
        {
        s1.root1=s1.mirror(s1.root1,a[j]);
        j++;
    }
    int h1=s1.height(s1.root1);
    for(int i=1;i<=h1;i++)
        {
        s1.level(s1.root1,i);
    }
     return 0;
    
}
