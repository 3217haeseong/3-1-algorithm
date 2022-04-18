#include<stdio.h>

void partition(int low,int high, int* pivotpoint,int* arr)     //정렬할 배열의 시작 인데스(low)와 끝 인덱스(high)와 pivotpoint와 배열을 입력받음.
{                                                              //pivotpoint는 이 함수가 종료되고 나서도 다른 함수의 인자로 전달되어야 하기 때문에 
    int i;
    int j;                                                    //배열을 한 번 순회하고 나서의 피봇이 최종적으로 들어갈 위치.
    int pivotitem;
    int temp;

    pivotitem=arr[low];                                       //pivot을 정렬할 배열의 첫번째 값으로 지정
    j=low;
    for(i=low+1;i<=high;i++)                                  //pivot 이후 인덱스의 배열 원소들을 순회함.
    {
        if(arr[i]<pivotitem)                                  // 만약 pivot보다 작은 값이 있다면
        {
            j++;                                              // j의 1 늘리고
            temp=arr[i];                                      // j 인덱스 위치에 있는 원소와 pivot보다 작은 값을 바꿈.
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    *pivotpoint=j;                                          // pivotpoint의 값을 pivot의 값이 위치할 인덱스로 지정 
    temp=arr[low];                                          // povotpoint 인덱스 위치에 원소와 원래 사용했던 pivot(배열의 첫번째 값)을 바꿈.
    arr[low]=arr[*pivotpoint];
    arr[*pivotpoint]=temp;

}

void quicksort(int low, int high,int* arr)     // 정렬할 배열의 시작 인데스(low)와 끝 인덱스(high)와 pivotpoint와 배열을 입력받음.
{
    int pivotpoint=arr[0];                      //pivot을 정렬할 배열의 첫번째 값으로 지정

    if(high>low)                                //
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