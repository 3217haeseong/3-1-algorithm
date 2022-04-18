#include<stdio.h>

int exchangesort(int n, int* arr)       //exchange sort. 정렬할 배열과 배열의 크기를 입력받음.
{
    int temp;                           // 원소를 바꿀 때 사용할 변수

    for(int i=0;i<n-1;i++)              //마지막 원소 전까지 for문 실행. 
    {   
        for(int j=0;j<n-i-1;j++)        //처음 원소부터 n-i-1(정렬되지 않은 원소보다 하나 작음)의 인덱스까지 for문 실행.
        {
            if(arr[j]>arr[j+1])         //현재의 원소와 다음의 원소 중 다음의 것이 작다면 순서를 바꿈.
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
/* exchange sort 결과를 확인하기 위한 main
int main()
{
    int arr[10]={15,14,13,12,11,10,9,8,7,6};

    printf("Exchange sort\n");
    for(int i=0;i<10;i++)
    {
        if(i==0)
        {
            printf("Before sort : ");
        }
        printf("%d   ",arr[i]);
        if(i==9)
        {
            printf("\n");
        }
    }

    exchangesort(10,arr);

    for(int i=0;i<10;i++)
    {
        if(i==0)
        {
            printf("After sort : ");
        }
        printf("%d   ",arr[i]);
        if(i==9)
        {
            printf("\n");
        }
    }
    
}
*/