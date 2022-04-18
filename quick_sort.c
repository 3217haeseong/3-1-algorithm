#include<stdio.h>

void partition(int low,int high, int* pivotpoint,int* arr)
{
    int i;
    int j;
    int pivotitem;
    int temp;

    pivotitem=arr[low];
    j=low;
    for(i=low+1;i<=high;i++)
    {
        if(arr[i]<pivotitem)
        {
            j++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    *pivotpoint=j;
    temp=arr[low];
    arr[low]=arr[*pivotpoint];
    arr[*pivotpoint]=temp;

}

void quicksort(int low, int high,int* arr)
{
    int pivotpoint=arr[0];

    if(high>low)
    {
        partition(low,high,&pivotpoint,arr);
        quicksort(low,pivotpoint-1,arr);
        quicksort(pivotpoint+1,high,arr);
    }
}


/*
int main()
{
    int arr[8]={15,22,13,27,12,10,20,25};
    printf("Quick sort\n");

    for(int i=0;i<8;i++)
    {
        if(i==0)
        {
            printf("Before sort : ");
        }
        printf("%d   ",arr[i]);
        if(i==7)
        {
            printf("\n");
        }
    }

    quicksort(0,8,arr);

    for(int i=0;i<8;i++)
    {
        if(i==0)
        {
            printf("After sort : ");
        }
        printf("%d   ",arr[i]);
        if(i==7)
        {
            printf("\n");
        }
    }
}
*/