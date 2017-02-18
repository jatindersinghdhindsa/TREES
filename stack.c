#include<stdio.h>
#define MAX 5
int a[100],top = -1;

void push(int x)
{ 
    if(top == -1)
    {
        a[++top] = x;
    }
    else if(top == MAX-1)
    {
        printf("Stack FUll\n");
    }
    else
    {
        a[++top] = x;
    } 

}
int pop()
{
    if(top == -1)
    {
        printf("underfow\n");
        return -1;
    }
    return a[top--];
}
void show()
{
   int i;
   for(i = top; i >= 0; i-- ) 
   printf("%d\n",a[i]);
}
main()
{
    int n,x;
    printf("Enter 1 to Push element\n");
    printf("Enter 2 to POP element\n");
    printf("Enter 3 to PRINT stack\n");
    printf("Enter -1 to end\n");
    scanf("%d",&n);
    while(n != -1)
    {
    if(n == 1)
    {
        printf("Enter element to push\n");
        scanf("%d",&x);
        push(x);    
    }
    else if(n == 2)
    { 
        x = pop();
        printf("%d\n",x);
    }
    else
    {
        show();
    }
    printf("Enter 1 to Push element\n");
    printf("Enter 2 to POP element\n");
    printf("Enter 3 to PRINT stack\n");
    printf("Enter -1 to end\n");

    scanf("%d",&n);
    }

    
}
