
#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "sort.h"

void ran_num(int* arr, int n)
{
    srand(time(NULL));
    int i;

    for(i=0;i<n;i++)
    {
        arr[i]=rand();
    }
}

int main()
{
    int arr[100];
    int arr2[500];
    int arr3[1000];
    int arr4[5000];
    int arr5[10000];
    int i;
    int j;

    heap a[5];

    clock_t start,end;
    float time=0;
    float time2=0;
    float time3=0;
    float time4=0;
    float time5=0;
    
    for(i=0;i<5;i++){
        ran_num(arr,100);
        ran_num(arr2,500);
        ran_num(arr3,1000);
        ran_num(arr4,5000);
        ran_num(arr5,10000);

        start=clock();
        exchangesort(100,arr);
        end=clock();
        time=time+(end-start);
        
        start=clock();
        exchangesort(500,arr2);
        end=clock();
        time2=time2+(end-start);

        start=clock();
        exchangesort(1000,arr3);
        end=clock();
        time3=time3+(end-start);

        start=clock();
        exchangesort(5000,arr4);
        end=clock();
        time4=time4+(end-start);

        start=clock();
        exchangesort(10000,arr5);
        end=clock();
        time5=time5+(end-start);

        if(i==4)
        {
            time=time/5;
            time2=time2/5;
            time3=time3/5;
            time4=time4/5;
            time5=time5/5;
        }
    }

    printf("exchange sort : %lf  %lf   %lf   %lf   %lf\n",time,time2,time3,time4,time5);

    for(i=0;i<5;i++){
        ran_num(arr,100);
        ran_num(arr2,500);
        ran_num(arr3,1000);
        ran_num(arr4,5000);
        ran_num(arr5,10000);

        start=clock();
        mergesort(100,arr);
        end=clock();
        time=time+(end-start);
        
        start=clock();
        mergesort(500,arr2);
        end=clock();
        time2=time2+(end-start);

        start=clock();
        mergesort(1000,arr3);
        end=clock();
        time3=time3+(end-start);

        start=clock();
        mergesort(5000,arr4);
        end=clock();
        time4=time4+(end-start);

        start=clock();
        mergesort(10000,arr5);
        end=clock();
        time5=time5+(end-start);

        if(i==4)
        {
            time=time/5;
            time2=time2/5;
            time3=time3/5;
            time4=time4/5;
            time5=time5/5;
        }
    }

    printf("merge sort : %lf  %lf   %lf   %lf   %lf\n",time,time2,time3,time4,time5);

    for(i=0;i<5;i++){
        ran_num(arr,100);
        ran_num(arr2,500);
        ran_num(arr3,1000);
        ran_num(arr4,5000);
        ran_num(arr5,10000);

        start=clock();
        quicksort(0,100,arr);
        end=clock();
        time=time+(end-start);
        
        start=clock();
        quicksort(0,500,arr2);
        end=clock();
        time2=time2+(end-start);

        start=clock();
        quicksort(0,1000,arr3);
        end=clock();
        time3=time3+(end-start);

        start=clock();
        quicksort(0,5000,arr4);
        end=clock();
        time4=time4+(end-start);

        start=clock();
        quicksort(0,10000,arr5);
        end=clock();
        time5=time5+(end-start);

        if(i==4)
        {
            time=time/5;
            time2=time2/5;
            time3=time3/5;
            time4=time4/5;
            time5=time5/5;
        }
    }

    printf("quick sort : %lf  %lf   %lf   %lf   %lf\n",time,time2,time3,time4,time5);

    for(i=0;i<5;i++){
        
        make_arr(&a[0],100);
        ran_num(a[0].h_arr,100);
        
        start=clock();
        heapsort(100,&a[0]);
        end=clock();
        time=time+(end-start);

        make_arr(&a[1],500);
        ran_num(a[1].h_arr,500);
        
        start=clock();
        heapsort(500,&a[1]);
        end=clock();
        time2=time2+(end-start);

        make_arr(&a[2],1000);
        ran_num(a[2].h_arr,1000);

        start=clock();
        heapsort(1000,&a[2]);
        end=clock();
        time3=time3+(end-start);

        make_arr(&a[3],5000);
        ran_num(a[3].h_arr,5000);

        start=clock();
        heapsort(5000,&a[3]);
        end=clock();
        time4=time4+(end-start);

        make_arr(&a[4],10000);
        ran_num(a[4].h_arr,10000);

        start=clock();
        heapsort(10000,&a[4]);
        end=clock();
        time5=time5+(end-start);

        if(i==4)
        {
            time=time/5;
            time2=time2/5;
            time3=time3/5;
            time4=time4/5;
            time5=time5/5;
        }


    }

    printf("heap sort : %lf  %lf   %lf   %lf   %lf\n",time,time2,time3,time4,time5);
}