#include <stdio.h>
#include <stdlib.h>

typedef struct B_TREE_NODE{         // 트리의 노드 구조체
    int* key_arr;
    struct B_TREE_NODE** p_arr;
    int count;
    int child_node;
}node;

typedef struct B_TREE{              // 트리 구조체 
    node* root;                     // 루트 노드를 가리키는 포인터
    int t;                          // 최소 
    int max;                        // 노드의 최대 개수를 나타내는 변수.

} b_tree;

node* create_node(int t)
{
    node* r_node=(node *)malloc(sizeof(node));
    r_node->key_arr=(int *)malloc(sizeof(int)*(2*t-1));
    r_node->p_arr=(int **)malloc(sizeof(int *)*(2*t));
    r_node->count=0;
    r_node->child_node=0;

    return r_node;                   
}
           
b_tree* create_b_tree(int t)        // 트리를 만드는 함수
{
    b_tree* r_tree=(b_tree*)malloc(sizeof(b_tree));   // 트리의 메모리 할당
    r_tree-> t=t;                                     // 최소 차수 
    r_tree-> max=2*t-1;                               // 한 노드의 최대 값의 개수
    
    r_tree->root=create_node(t);                      // root 노드를 만들어 

    return r_tree;                      // 트리 반환
}

int compare_key(node* compare_node,int key)                     //루트 노드의 데이터 배열들과 키의 값을 비교함.
{
    int i;
    int temp;

    for(i=0;i<compare_node->count;i++)
    {
        temp=compare_node->key_arr[i];
        if(temp>key)
        {
            return i;        
        }
    }

    return 0;                                   //모든 데이터 배열의 값보다 작으면 가장 왼쪽에 있는 
}

void insert_node(b_tree* bt,int key)
{
    int num;
    int* bt_int=bt->root->key_arr;     
    node** bt_p=bt->root->p_arr;
    int i;
    int j;
    node* temp;

    if(bt->root->count==0)                        
    {
        bt_int[0]=key;
        (bt->root->count)++;
    }else  
    {
        if((bt->root->child_node)==0)
        {
            for(int i=0;i<=(bt->root->count);i++)
            {
                if(bt_int[i]>key)
                {
                    for(j=bt->root->count;j>i;j--)
                    {
                        bt_int[j]=bt_int[j-1];
                    }
                    bt_int[j]=key;
                    (bt->root->count)++;
                     break;
                }
                bt_int[bt->root->count]=key;
                (bt->root->count)++;
            }
        } else if((bt->root->child_node)==1){
            num=compare_key(root_node, key);
        } 
    }

    if(br->root->count==bt->max)                                            // 삽입으로 인해 노드의 수가 꽉차면 데이터 배열의 중간을 부모 노드로 만들기
    {
        node* parent_node=create_node(bt->t);           

        

    }
}

void delete_node(b_tree* bt,int key)
{

}

int main()
{
    clock_t start,end;
    
    b_tree* test_tree=create_b_tree(5);
    b_tree* test_tree2=create_b_tree(7);
    b_tree* test_tree3=create_b_tree(9);

    float time=0;

    start=clock();
    for(int i=0;i<1000;i++)
    {
        key=rand()%10000;
        insert_node(test_tree,rand);
    }
    end=clock();

    time=end-start;

    printf("t=5 insert time: %lf\n",time);

    start=clock();
    for(int i=0;i<1000;i++)
    {
        key=rand()%10000;
        insert_node(test_tree2,rand);
    }
    end=clock();

    time=end-start;
    printf("t=7 insert time: %lf\n",time);
    

    start=clock();
    for(int i=0;i<1000;i++)
    {
        key=rand()%10000;
        insert_node(test_tree3,rand);
    }
    end=clock();

    time=end-start;

    printf("t=9 insert time: %lf\n",time);



    start=clock();
    for(int i=0;i<1000;i++)
    {
        key=rand()%10000;
        delete_node(test_tree,rand);
    }
    end=clock();

    time=end-start;

    printf("t=5 delete time: %lf\n",time);

    start=clock();
    for(int i=0;i<1000;i++)
    {
        key=rand()%10000;
        delete_node(test_tree2,rand);
    }
    end=clock();

    time=end-start;

    printf("t=7 delete time: %lf\n",time);

    start=clock();
    for(int i=0;i<1000;i++)
    {
        key=rand()%10000;
        delete_node(test_tree,rand);
    }
    end=clock();

    time=end-start;

    printf("t=5 delete time: %lf\n",time);
}