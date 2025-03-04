#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void display(int *arr)
{
    int i;
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int start, int stop)
{
    int loc, flag;
    int beg, end;
    loc = beg = start;
    end = stop;
    flag = 0;
    while (flag == 0)
    {
        while (loc != end && arr[loc] <= arr[end])
            end--;
        if (loc == end)
            flag = 1;
        else if (arr[loc] > arr[end])
        {
            swap(arr + loc, arr + end);
            loc = end;
        }
        if (flag == 0)
        {
            while (loc != beg && arr[loc] >= arr[beg])
                beg++;
            if (loc == beg)
                flag = 1;
            if (arr[loc] < arr[beg])
            {
                swap(arr + loc, arr + beg);
                loc = beg;
            }
        }
    }

    return loc;
}

void quick_sort(int *arr, int beg, int end)
{
    int loc;

    if (beg < end)
    {
        loc = partition(arr, beg, end);
        quick_sort(arr, beg, loc - 1);
        quick_sort(arr, loc + 1, end);
    }
}

void func()
{
    int arr[SIZE], arr_cpy[SIZE];
    int i;
    srand(time(0));
    for (i = 0; i < SIZE; i++)
    {
        arr_cpy[i] = arr[i] = rand() % 100;
    }
    printf("Before sorting: ");
    display(arr);
    quick_sort(arr, 0, SIZE - 1);
    qsort(arr_cpy, SIZE, sizeof(int), compare);
    printf("\nAfter sorting: ");
    display(arr);
    display(arr_cpy);
}
void quick_sort_one_part_partition(int *arr, int beg, int end, int k)
{
    int loc;
    if (beg < end)
    {
        loc = partition(arr, beg, end);
        if (loc == k)
            return;
        else
        {
            if (loc < k)
                quick_sort_one_part_partition(arr, loc + 1, end, k);
            else
                quick_sort_one_part_partition(arr, beg, loc - 1, k);
        }
    }
}
void kth_smallest()
{
    int arr[SIZE], arr_cpy[SIZE];
    int i, k, res;
    srand(time(0));
    for (i = 0; i < SIZE; i++)
    {
        arr_cpy[i] = arr[i] = rand() % 100;
    }
    printf("Array is: ");
    display(arr);
    
    k = rand() % SIZE;
    
    quick_sort_one_part_partition(arr, 0, SIZE - 1, k);

    printf("%dth smallest element is %d\n", k, arr[k]);
    
    qsort(arr_cpy, SIZE, sizeof(int), compare);

    printf("\nAfter sorting: ");
    display(arr_cpy);
}
int main()
{
    kth_smallest();
    return 0;
}