#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int key;
    struct Node* link;
} node;

typedef struct LinkedList
{
    node* header;
}linked_list;

typedef node* node_pointer;

node* create_node(int num)
{
    node_pointer r_pointer=(node_pointer)malloc(sizeof(node));
    r_pointer->key=num;
    r_pointer->link=NULL;

    return r_pointer;
}

linked_list* create_linkedlist()
{
    linked_list* r_list=(linked_list*)malloc(sizeof(linked_list));
    r_list->header=NULL;

    return r_list;
}

void add_node(linked_list* l_list, node_pointer node_for_add)
{
    node* temp=l_list->header;

    
    if(temp==NULL)
    {
        l_list->header=node_for_add;
    }else{
        while(temp!=NULL)
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

int distribute(linked_list* masterlist, linked_list* list[],int i)
{
    int j;
    int num=1;
    node* p;
    node* temp;

    printf("start\n");
    for(j=i;j>0;j--)
    {
        num=num*10;
    }

    for(j=0;j<=9;j++)
    {
        list[j]==create_linkedlist();
    }

    p=masterlist->header;

    while(p!=NULL)
    {
        temp=p;
        p=p->link;
        j=(temp->key)%num;
        printf("%d %d\n",temp->key,j);
        add_node(list[j],temp);       
    }
    printf("1\n");
}

void coalesce(linked_list* masterlist,linked_list* list[])
{
    int j;

    printf("c-start");
    masterlist->header=NULL;
    for(j=0;j<=9;j++)
    {
        add_node(masterlist,list[j]->header);
    }
}

void radixsort(linked_list* masterlist,int numdigits)
{
    int i;
    linked_list* list[10];

    for(i=0;i<10;i++)
    {
        list[i]=create_linkedlist();
    }

    for(i=1;i<=numdigits;i++)
    {
        distribute(masterlist,list,i);
        coalesce(masterlist,list);
    }

    for(i=0;i<10;i++)
    {
        free(list[i]);
    }


}

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