#include <stdio.h>
#include<stdlib.h>
typedef struct bst
{ 
    int val;
    struct bst *left;
    struct bst *right;
    
}BST;
BST * insert(BST * root,int num)
{
    if(root==NULL)
    {
        
        BST *nn=(BST *)malloc(sizeof(BST));
        nn->val=num;
        nn->left=NULL;
        nn->right=NULL;
       
        return nn;
    }
    else if(root->val>num)
    {
        root->left=insert(root->left,num);
    }
    else
    {
        root->right=insert(root->right,num);
    }
    return root;
}
int getmin(BST * root)
{
   if(root==NULL)
    {
        printf("EMPTY");
        return -1;
    }
   else if(root->left == NULL)
   {
       return root->val; 
   }
   return getmin(root->left);
}
int getmax(BST * root)
{
    if(root==NULL)
    {
        printf("EMPTY");
        return -1;
    }
    else if (root->right==NULL)
    {
        return root->val;
    }
    return getmax(root->right);
}
void delmin(BST * *root)
{
    if(*root==NULL)
     {
         printf("EMPTY");
         return;
     }
    else if((*root)->left==NULL)
    {
       
        *root=(*root)->right;
        
      
        
    }
    else if((*root)->left->left==NULL)
    {
        (*root)->left=(*root)->left->right;
    }
    else
    delmin(&((*root)->left));
}
void delmax(BST * *root)
{
    if(*root==NULL)
     {
         printf("EMPTY");
         return;
     }
    else if((*root)->right==NULL)
    {
       
        *root=(*root)->left;
        
      
        
    }
    else if((*root)->right->right==NULL)
    {
        (*root)->right=(*root)->right->left;
    }
    else
    delmax(&((*root)->right));
}
int search(BST *node,int num)
{
    if(!node)
    return 0;
    if(node->val==num)
     return 1;
    if(node->val>num)
     return search(node->left,num);
     
     return search(node->right,num);
}
BST * delete(BST * root,int num)
{
    if(root==NULL)
      {
          printf("Not Found");
          return NULL;
      }      
    if(root->val>num)
     root->left=delete(root->left,num);
    else if(root->val<num)
    root->right=delete(root->right,num);
    else
    {
        if(root->right==NULL)
         return root->left;
         else
         {
             BST *temp=(BST*)malloc(sizeof(BST));
             temp->val=getmin(root->right);
             delmin(&(root->right));
             temp->right=root->right;
             temp->left=root->left;
             return temp;
         }
    }
}
void inOrder(BST * root)
{
    if(!root)
    return;
    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}
int main()
{
    BST * root=NULL;
    root=insert(root,20);
   root=insert(root,30);
    root=insert(root,5);
    root=insert(root,41);
    root=insert(root,22);
    root=insert(root,15);
    root=insert(root,3);
    root=insert(root,34);
    //printf("%d ",root->val);
    //printf("%d ",root->left->right->val);
    //printf("%d ",root->right->right->val);
   printf("%d ",getmin(root));
   //printf("%d ",getmax(root));
   delmin(&root);
  printf("%d ",getmin(root));
  printf("%d ",getmax(root));
  delmax(&root);
  printf("%d ",getmax(root));
  
  if(search(root,34))
  printf("EXITS");
  else
  printf("Doesn't Exist");
  printf("\n");
  inOrder(root);
  root=delete(root,20);
   printf("\n");
  inOrder(root);
    return 0;
}
