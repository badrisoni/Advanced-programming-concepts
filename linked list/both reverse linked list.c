/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

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
  struct node * app_node=(struct node*)malloc(sizeof(struct node));
 
   app_node->val=n;
   
 app_node->next=NULL;
   struct node * current = (*h);
 
   if(*h==NULL)
  {
   *h=app_node;

    }
 
   else
 {
 while(current->next!=NULL)
   {
        current=current->next;
  }
    current->next=app_node;
 }

}
struct node * reverse_recursive(struct node * x)
{
    struct node * first = x;
    struct node * second = first->next;
    if(second==NULL)
     return first;
    struct node * h=reverse_recursive(second);
     second->next=first;
     first->next=NULL;
    return h; 
}
void reverse_iterative(struct node **h)
 {
     
     
 struct node * prev=NULL;
 struct node * current=(*h);
 struct node * next=NULL;
 if(current!=NULL)
 {
     
     next=current->next;
 
     while(current!=NULL)
     {
         current->next=prev;
         prev=current;
         current=next;
         if(current!=NULL)
         next=next->next;
     }
     (*h)=prev;
 }
    
 }
int main()
{
struct node* head=NULL;
   int num=0;
  while(num!=-1)
  {
   scanf("%d",&num);
   append(&head,num);
   }
  //reverse_iterative(&head);
  head=reverse_recursive(head);
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

