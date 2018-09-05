#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}

int partition(int arr[], int l, int h) {
        int p = arr[h];
        int t = l;
        for (int i = l; i < h; ++i) {
                if (arr[i] < p) {
                        swap(&arr[i], &arr[t]);
                        t++;
                }
        }
        swap(&arr[t], &arr[h]);
        return t;
}

void quicksort(int arr[], int l, int h) {
        if (l < h) {
                int p = partition(arr, l, h);
                quicksort(arr, l, p - 1);
                quicksort(arr, p + 1, h);
        }
}

int main()
{
        int arr[] = {3, 5, 8, 2, 1, 1, 13};
        quicksort(arr, 0, ARRAY_SIZE(arr) - 1);
        for (int i = 0; i < ARRAY_SIZE(arr); ++i) {
                printf("%d ", arr[i]);
        }
        return 0;
}