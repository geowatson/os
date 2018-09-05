#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}

void bubble_sort(int arr[], int n) {
        for (int i = n; i > 0; --i) {
                for (int j = 0; j < i - 1; j++) {
                        if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
                }
        }
}

int main()
{
        int arr[] = {3, 2, 1, 9, 10, 215};
        bubble_sort(arr, ARRAY_SIZE(arr));
        for (int i = 0; i < ARRAY_SIZE(arr); ++i) {
              printf("%d ", arr[i]);
        }
        return 0;
}