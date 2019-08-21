
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


struct node * reverse(struct node * ptr1,struct node * ptr2)
 {
     
     
 struct node * prev=ptr2->next;
 struct node * last=ptr2->next;
 struct node * current=ptr1;
 struct node * next=NULL;
 if(current!=NULL)
 {
     
     next=current->next;
 
     while(current!=last)
     {
         current->next=prev;
         prev=current;
         current=next;
         if(current!=last)
         next=next->next;
     }
    return prev;
 }
    
 }
int main()
{
struct node* head=NULL;
struct node * ptr1;
struct node * ptr2;
struct node * temp;
struct node * x;
int count=0;
   int num=0;
  while(num!=-1)
  {
   scanf("%d",&num);
   append(&head,num);
   }
   int k=0;
   scanf("%d",&k);
   ptr1=head;
      ptr2=head;
  while(ptr2!=NULL)
  {
     
    for(int i=1;i<k;i++)
    {   
        if(ptr2->next!=NULL)
        {
            ptr2=ptr2->next;
        }
        else
        break;
        
    }
    temp=reverse(ptr1,ptr2);
    if(count==0)
    {
    head=temp;
    count++;
    }
    else
    {
      x->next=temp;
    }
    x=ptr1;
    ptr1=ptr1->next;
    ptr2=ptr1;
    
    
  }
  
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