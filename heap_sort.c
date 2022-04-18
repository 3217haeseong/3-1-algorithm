#include<stdio.h>
#include<stdlib.h>
#include "sort.h"


void make_arr(heap* h,int n)                  //힙과 배열의 크기를 입력받아 힙안에 배열을 만들고 heapsize의 크기를 초기화함.
{
    h->h_arr=(int*)malloc(sizeof(int)*n);
    h->heapsize=n;
}

void siftdown(heap* H,int i)                  // 힙을 만드는 과정 중 하나. 
{
    int parent,largerchild;   
    int siftkey;
    int spotfound;

    siftkey=H->h_arr[i-1];                   // heap의 루트노드에 있는 값을 선택.
    parent=i-1;                              // parent의 위치를 정함/
    spotfound=0;                             // 올바른 위치를 정했는지 판별하기 위한 변수.
    while(2*parent<=H->heapsize && !spotfound)  // 만약 자식노드가 있고, 아직 들어갈 자리를 찾지 못하는 동안에
    {
        if(2*parent<H->heapsize && H->h_arr[2*parent]<H->h_arr[2*parent+1]){    // 만약 자식 노드 중 오른쪽 노드의 값이 크다면 더 큰 노드의 인덱스를 정장
            largerchild=2*parent+1;
        } else{
           largerchild=2*parent;                                        // 왼쪽 노드의 값이 크다면 왼쪽 노드의 인덱스를 저장
        } 
        
        if(siftkey<H->h_arr[largerchild]){                              // 만약 두 자식노드 중 더 큰값의 값보다 현재의 값이 작다면 
            H->h_arr[parent]=H->h_arr[largerchild];                     // 현재의 값이 있던 노드에 두 자식 노드 중 더 큰 값을 넣음.
            parent=largerchild;                                         // 현재의 값이 들어 갈 인덱스의 값을 두 자식 노드 중 더 큰 값의 인덱스로 바꿈.
        } else{                                                         // 그렇지 않다면 맞는 자리를 찾았다는 표시를 함.
            spotfound=1;            
        }
    }
    H->h_arr[parent]=siftkey;                                           // 현재의 값을 맞는 자리에 넣음.
}
int root(heap* H)                           //heap으로부터 루트 노드를 빼내는 함수.
{
    int keyout;

    keyout=H->h_arr[0];                     // heap에서 가장 큰 값을 넣음 
    H->h_arr[0]=H->h_arr[H->heapsize-1];    // 가장 큰 값이 있던 자리에 heap의 리프 노드 중 가장 오른쪽에 있는 값을 넣음.
    H->heapsize=H->heapsize-1;              // 원소가 하나 빠져나갔으므로 heapsize를 하나 줄임.
    siftdown(H,1);                          // heap의 조건을 다시 만족시키위해 siftdown, siftdown에서 두번째 인자의 -1 한 값을 사용하기 때문에 가장 큰값을 위해선 1을 인수로 넣어야 함.
    return keyout;                          // 가장 큰 값 반환.
}

void removekeys(int n, heap* H, int* arr)   //heap의 루트노드를 빼내서 배열에 마지막에 넣음.
{
    int i;
    for(i=n-1;i>=0;i--)                     
    {
        arr[i]=root(H);                 
    }
}

int makeheap(int n, heap*H)          // 입력 받은 크기를 가진 heap을 만듦.
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
    makeheap(n,H);              // heap을 만들고 
    removekeys(n,H,H->h_arr);   // heap의 가장 큰 값을 heap안의 배열의 마지막으로 넣음.  
}

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
