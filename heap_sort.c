#include<stdio.h>
#include<stdlib.h>
#include "sort.h"


void make_arr(heap* h,int n)
{
    h->h_arr=(int*)malloc(sizeof(int)*n);
    h->heapsize=n;
}

void removekeys(int n, heap* H, int* arr)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        arr[i]=root(H);
    }
}
void siftdown(heap* H,int i)
{
    int parent,largerchild;
    int siftkey;
    int spotfound;

    siftkey=H->h_arr[i-1];
    parent=i-1;
    spotfound=0;
    while(2*parent<=H->heapsize && !spotfound)
    {
        if(2*parent<H->heapsize && H->h_arr[2*parent]<H->h_arr[2*parent+1]){
            largerchild=2*parent+1;
        } else{
           largerchild=2*parent;
        } 
        
        if(siftkey<H->h_arr[largerchild]){
            H->h_arr[parent]=H->h_arr[largerchild];
            parent=largerchild;
        } else{
            spotfound=1;
        }
    }
    H->h_arr[parent]=siftkey;
}

int root(heap* H)
{
    int keyout;

    keyout=H->h_arr[0];
    H->h_arr[0]=H->h_arr[H->heapsize-1];
    H->heapsize=H->heapsize-1;
    siftdown(H,1);
    return keyout;
}

int makeheap(int n, heap*H)
{
    int i;
    H->heapsize=n;
    for(i=n/2;i>=0;i--)
    {
        siftdown(H,i);
    }
    
}



void heapsort(int n,heap* H)
{
    makeheap(n,H);
    removekeys(n,H,H->h_arr);
}
/*
int main()
{
    heap h;
    make_arr(&h,10);
    h.h_arr[0]=25;
    h.h_arr[1]=18;
    h.h_arr[2]=12;
    h.h_arr[3]=19;
    h.h_arr[4]=30;
    h.h_arr[5]=16;
    h.h_arr[6]=17;
    h.h_arr[7]=11;
    h.h_arr[8]=14;
    h.h_arr[9]=20;

    printf("Heap sort\n");

    for(int i=0;i<10;i++)
    {
        if(i==0)
        {
            printf("Before sort : ");
        }
        printf("%d   ",h.h_arr[i]);
        if(i==9)
        {
            printf("\n");
        }
    }

    heapsort(10,&h);

     for(int i=0;i<10;i++)
    {
        if(i==0)
        {
            printf("After sort : ");
        }
        printf("%d   ",h.h_arr[i]);
        if(i==9)
        {
            printf("\n");
        }
    }
}
*/