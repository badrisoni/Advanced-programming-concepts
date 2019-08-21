/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int val;
    struct node * next;
};
void append(struct node **h,int n)
{
    struct node * new_node=(struct node *)malloc(sizeof(struct node));
    new_node->val=n;
    new_node->next=NULL;
    struct node * current = (*h);
    if(*h==NULL)
    {
        *h = new_node; 
    }
    else
    {
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=new_node;
    }
}
struct node * swap_adjacent(struct node * first)
{
    struct node * second=NULL;
    if(first)
    second=first->next;
    
    if(first==NULL || second==NULL)
    {
        return first;
    }
    struct node * x=swap_adjacent(second->next);
    second->next=first;
    first->next=x;
    return second;
}
int main()
{
  struct node * head=NULL;
  int num=0;
  while(num!=-1)
  {
      scanf("%d",&num);
      append(&head,num);
  }
  head=swap_adjacent(head);
 if(head==NULL)
   {
       printf("EMPTY");
   }
   else
   {
       while(head!=NULL)
  {
  printf("%d ",head->val);
   head=head->next;
  }
   }
    return 0;
}
