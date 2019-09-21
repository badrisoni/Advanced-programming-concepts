//  max heap
#include <stdio.h>
void swap(int * a,int * b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
void sink(int *arr,int i,int size)
{
    if(i>=size)
    return;
    int max=i;
    int L=i*2;
    int R=i*2+1;
    if(L<size && arr[L]>arr[max])
     max=L;
    if(R<size && arr[R]>arr[max])
    max=R;
    if(max!=i)
    {
        swap(&arr[i],&arr[max]);
        sink(arr,max,size);
    }
}
void swim(int *arr,int i)
{
    if(i==0)
    return;
    int parent=i/2;
    if(arr[i]>arr[parent])
    {
    swap(&arr[i],&arr[parent]);
    swim(arr,parent);
    }
}
void heapify(int * arr,int size)
{
    for(int i=size/2;i>=0;i--)
    {
        sink(arr,i,size);
    }
}
void insert(int * arr,int *size,int val)
{
    
   arr[*size]=val;
   *size=*size+1;
   swim(arr,*size-1);
}
void delete(int * arr,int* size)
{
    swap(&arr[0],&arr[(*size)-1]);
    (*size)--;
    sink(arr,0,*size);
}
void print(int * arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
void sort(int *arr,int* size,int n)
{
    heapify(arr,*size);
    for(int i=0;i<n;i++)
    {
        delete(arr,size);
    }
}
int main()
{
   int arr[]={10,20,15,12,40,25,18};
   int size=7;
   int n=size;
   //heapify(arr,7);
   sort(arr,&size,n);
   print(arr,n);
   
   insert(arr,&size,25);
  
   insert(arr,&size,48);
   insert(arr,&size,14);
   insert(arr,&size,630);
   insert(arr,&size,-2);
   //printf("%d",arr[0]);
   delete(arr,&size);
   print(arr,size);
   

    return 0;
}
