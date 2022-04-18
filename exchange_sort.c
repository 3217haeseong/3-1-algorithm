#include<stdio.h>

int exchangesort(int n, int* arr)
{
    int temp;

    for(int i=0;i<n-1;i++)
    {   
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
/*
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