
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
void remove_duplicates(struct node **h)
{
    if(*h!=NULL)
    {
    
    
    struct node * current=(*h)->next;
    struct node * Next=(*h);
    while(current)
    {
        if(Next->val==current->val)
        {
            Next->next=current->next;
            current=current->next;
        }
        else
        {
            current=current->next;
            Next=Next->next;
        }
    }
    }
}
int main()
{
struct node* head=NULL;
   int num=0;
  while(num!=-1)
  {
   scanf("%d",&num);
   if(num!=-1)
   append(&head,num);
   }
  //reverse_iterative(&head);
  //head=reverse_recursive(head);
  remove_duplicates(&head);
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
