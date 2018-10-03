#include <stdio.h>
#include <stdlib.h>

int main() {
        static int N;
        printf("Prompt >> Enter N: ");
        scanf("%d", &N);
        int M = N;

        int * arr = malloc(N * sizeof(int));

        while(M) arr[--M] = (M - 1);
        for (int i = 0; i < N; ++i)
                printf("%d ", arr[i]);
        printf("\n");

        free(arr);

        return 0;
}