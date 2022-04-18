#include<stdio.h>
#include<stdlib.h>

typedef struct Node         // 링크드 리스트에 사용할 노드
{
    int key;                // 값을 위한 변수
    struct Node* link;      // 다음 노드를 가리키는 노드 포인터
} node;

typedef struct LinkedList   // 링크드 리스트
{
    node* header;           // 링크드 리스트의 처음을 
}linked_list;           

typedef node* node_pointer;

node* create_node(int num)      // 값을 입력 받아 노드를 반환해주는 함수
{
    node_pointer r_pointer=(node_pointer)malloc(sizeof(node));  // 노드 포인터에 노드 메모리 할당
    r_pointer->key=num;                                         // 노드에 값 할당
    r_pointer->link=NULL;                                       // 노드에 link에 NULL 할당

    return r_pointer;               // 노드 포인터 반환
}

linked_list* create_linkedlist()      // 링크드 리스트를 만드는 함수
{
    linked_list* r_list=(linked_list*)malloc(sizeof(linked_list));  // 링크드 리스트 포인터에 링크드 리스트 메모리 할당
    r_list->header=NULL;                                            // 링크드 리스트의 header에 NULL 할당

    return r_list;                 // 링크드 리스트 포인터 반환
}

void add_node(linked_list* l_list, node_pointer node_for_add)    //링크드 리스트 마지막에 노드를 추가하는 함수.
{
    node* temp=l_list->header;                    

    
    if(temp==NULL)                          //링크드 리스트의 헤더노드가 NULL을 가리킨다면 헤더노드를 새로운 노드로 할당.
    {
        l_list->header=node_for_add;
    }else{                                  //그렇지 않다면
        while(temp!=NULL)                   // 링크드 리스트의 끝에 노드를 추가.
        {
            if(temp->link==NULL)
            {
                temp->link=node_for_add;
                break;
            }
            temp=temp->link;
        }
    }
}

int distribute(linked_list* masterlist, linked_list* list[],int i)  // 링크드 리스트의 원소들을 i번째 자릿수의 값에 따라 list의 배열에 넣는 함수 
{
    int j;
    int num=1;
    node* p;
    node* temp;

    for(j=i;j>0;j--)                                                // num을 자릿수를 변수로 만듦.
    {
        num=num*10;
    }

    for(j=0;j<=9;j++)                                               // 링크드 리스트의 배열을 초기화.
    {
        list[j]==create_linkedlist();
    }

    p=masterlist->header;                                   // 정렬할 배열의 첫번째를 가리킴.

    while(p!=NULL)                                          // 배열을 자릿수의 값과 일치하는 인덱스를 가진 링크드리스트 배열에 넣음.
    {
        temp=p;
        p=p->link;                                          // 노드(값을) 넣을 때 링크드 리스트 배열에선 해당 노드가 마지막이어야 하므로 노드의 link를 NULL로 지정.
        j=(temp->key)%num;
        add_node(list[j],temp);                             // 노드 추가
    }
}

void coalesce(linked_list* masterlist,linked_list* list[]) // 자릿수에 따라 정렬한 결과를 다시 원래 배열에 넣음.
{
    int j;

    masterlist->header=NULL;                            // 원래 배열 초기화.
    for(j=0;j<=9;j++)
    {
        add_node(masterlist,list[j]->header);           // 자릿수의 값에 따라 만든 링크드리스트 배열을 차례로 원래 배열에 넣음.
    }
}

void radixsort(linked_list* masterlist,int numdigits)   // 링크드 리스트와 가장 큰 자릿수를 입력받음.
{
    int i;
    linked_list* list[10];

    for(i=0;i<10;i++)                           //링크드 리스트 배열 생성.
    {
        list[i]=create_linkedlist();
    }

    for(i=1;i<=numdigits;i++)                   //자릿수에 따라 분리하고 합치는 과정을 실행.
    {
        distribute(masterlist,list,i);
        coalesce(masterlist,list);
    }

    for(i=0;i<10;i++)
    {
        free(list[i]);
    }


}

/*
    결과 실행을 위한 main 함수
*/
int main()
{
    linked_list* a=create_linkedlist();
    node_pointer b=create_node(18);
    node_pointer c=create_node(17);
    node_pointer d=create_node(16);
    node_pointer e=create_node(15);
    node_pointer f=create_node(14);
    node_pointer g=create_node(13);
    node_pointer h=create_node(12);
    node_pointer i=create_node(11);
    node_pointer j=create_node(10);
    node_pointer temp;
    add_node(a,b);
    add_node(a,c);
    add_node(a,d);
    add_node(a,e);
    add_node(a,f);
    add_node(a,g);
    add_node(a,h);
    add_node(a,i);
    add_node(a,j);
    temp=a->header;

    while(temp!=NULL)
    {
        
        printf("%d\n",temp->key);
        temp=temp->link;
    }

    radixsort(a,2);

    temp=a->header;

    while(temp!=NULL)
    {
        
        printf("%d\n",temp->key);
        temp=temp->link;
    }



}