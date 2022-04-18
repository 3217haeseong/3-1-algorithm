#include<stdio.h>

void merge(int h,int m, int* sub_arr,int* sub_arr2,int* arr)     // 합치는 과정에 해당하는 함수 sub_arr,sub_arr2는 나눠진 배열, arr은 합쳐진 후의 배열
{                                                                // h는 sub_arr의 크기, m은 sub_arr의 크기
    int i,j,k;                                                    
    i=0;
    j=0;
    k=0;


    while(i<h && j<m)                                   // 나눠진 두 배열 모두가 아직 남아있을 경우
    {
        if(sub_arr[i]<sub_arr2[j])                      //더 작은 쪽의 원소를 합쳐진 배열에 넣음
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

    if(i>=h)                                            // 둘 중 하나의 배열이 다 비었을 경우 중, sub_arr이 다 비워졌다면
    {
        while(j<m)                                      // sub_arr2의 원소를 arr에 넣음.
        {
            arr[k]=sub_arr2[j];
            k++;
            j++;
        }    
    }else                                               // 그렇지 않고 sub_arr2이 다 비워졌다면
    {
        while(i<h)
        {
            arr[k]=sub_arr[i];                          // sub_arr의 원소를 arr에 넣음
            k++;
            i++;
        }
    }
}

void mergesort(int n, int* arr)                     // 둘로 나눌 배열과 배열의 크기를 입력받아 두 배열로 나누는 함수.
{
    int h;
    int m;
    int i;
    int j=0;
    
    if(n>1)                                 // 나눠질 배열의 수가 1개보다 많으면 실행
    {
        h=n/2;                              // 나눈 후 첫번째 배열의 크기
        m=n-h;                              // 나눈 후 두번째 배열의 크기

        int sub_arr[h];                     // 나눈 후 첫번째 배열 생성
        int sub_arr2[m];                    // 나눈 후 두번째 배열 생성

        for(i=0;i<h;i++)                    // sub_arr에 나눠질 배열의 앞 절반을 넣음. 
        {
            sub_arr[i]=arr[i];
        }

        for(i=h;i<n;i++)                    // sub_arr2에 나눠질 배열의 남은 절반을 넣음.
        {
            sub_arr2[j]=arr[i];
            j++;
        }
        

        mergesort(h,sub_arr);               // 나뉜 배열의 크기가 1일때까지 실행하기 위해 sub_arr에 대해 재귀 실행
        mergesort(m,sub_arr2);              // 나뉜 배열의 크기가 1일때까지 실행하기 위해 sub_arr2에 대해 재귀 실행
        merge(h,m,sub_arr,sub_arr2,arr);    // 나뉜 배열을 원소의 크기를 비교하면 넣어 정렬 완성.
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