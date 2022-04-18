#include<stdio.h>

void merge(int h,int m, int* sub_arr,int* sub_arr2,int* arr)
{
    int i,j,k;

    i=0;
    j=0;
    k=0;


    while(i<h && j<m)
    {
        if(sub_arr[i]<sub_arr2[j])
        {
            arr[k]=sub_arr[i];
            i++;
        }
        else
        {
            arr[k]=sub_arr2[j];
            j++;
        }
        k++;
    }

    if(i>=h)
    {
        while(j<m)
        {
            arr[k]=sub_arr2[j];
            k++;
            j++;
        }    
    }else
    {
        while(i<h)
        {
            arr[k]=sub_arr[i];
            k++;
            i++;
        }
    }
}

void mergesort(int n, int* arr)
{
    int h;
    int m;
    int i;
    int j=0;
    
    if(n>1)
    {
        h=n/2;
        m=n-h;

        int sub_arr[h];
        int sub_arr2[m];

        for(i=0;i<h;i++)
        {
            sub_arr[i]=arr[i];
        }

        for(i=h;i<n;i++)
        {
            sub_arr2[j]=arr[i];
            j++;
        }
        

        mergesort(h,sub_arr);
        mergesort(m,sub_arr2);
        merge(h,m,sub_arr,sub_arr2,arr);
    }
}

/*
int main()
{
    int arr[8]={27,10,12,20,25,13,15,22};

    printf("Merge sort\n");
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

    mergesort(8,arr);

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