
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
void remove_all_duplicates(struct node **h)
{
    struct node * prev;
    struct node * current = (*h);
    struct node * Next=current->next;
    int count=0;
    int flag=0;
    if(*h!=NULL)
    {
        (*h)=NULL;
      while(Next!=NULL)
      {
        if(current->val == Next->val)
        {
            Next=Next->next;
            flag=1;
        }
        else if(flag==0 && count==0)
        {
            (*h)=current;
            count++;
            prev=(*h);
            current=current->next;
            Next=Next->next;
        }
        else if(flag==0)
        {
            prev->next=current;
            prev=prev->next;
            
            current=current->next;
            Next=Next->next;
            prev->next=NULL;
        }
        else
        {
            current=Next;
            Next=Next->next;
            flag=0;
        }
      }
      if(flag==0)
      {
          prev->next=current;
            prev=prev->next;
            prev->next=NULL;
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
  
 remove_all_duplicates(&head);
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
