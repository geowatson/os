#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc/malloc.h>

void * my_realloc(void * ptr, size_t size);

int main() {
        int s1, s2;
        printf("Enter size 1 and size 2: ");
        scanf("%d %d", &s1, &s2);
        printf("\n");

        int * arr = malloc(s1 * sizeof(arr[0]));

        printf("Elements of array with s1: ");
        for (int i = 0; i < s1; ++i) {
                arr[i] = i;
                printf("%d ", arr[i]);
        }
        printf("\n");

        arr = my_realloc(arr, (size_t)s2);

        printf("Elements of array with s2: ");
        for (int i = 0; i < s2; ++i) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

void * my_realloc(void * ptr, size_t size) {
        void * nptr;

        if (!ptr) {
                nptr = malloc(size);
        }
        else {
                if (!size) {
                        free(ptr);
                        return NULL;
                }
                else {
                        nptr = malloc(size);
                        memcpy(nptr, ptr, malloc_size(ptr));
                        free(ptr);
                }
        }
        return nptr;
}