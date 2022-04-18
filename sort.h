
typedef struct Heap
{
    int* h_arr;
    int heapsize;
} heap;

int exchangesort(int n, int* arr);
void merge(int h,int m, int* sub_arr,int* sub_arr2,int* arr);
void mergesort(int n, int* arr);
void partition(int low,int high, int* pivotpoint,int* arr);
void quicksort(int low, int high,int* arr);
void removekeys(int n, heap* H, int* arr);
void siftdown(heap* H,int i);
int root(heap* H);
void make_arr(heap* h,int n);
int makeheap(int n, heap*H);
void heapsort(int n,heap* H);