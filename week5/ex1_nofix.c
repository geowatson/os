#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void funct(int n) {
        printf("%d\n",n);
        pthread_exit(NULL);
}

int main() {
        int n = 100;
        pthread_t * p = malloc(sizeof(pthread_t) * n);
        for (int i = 0; i < n; ++i) {
                pthread_create(&p[i], NULL, (void*)funct, (void*)i);
                printf("Thread %d created.\n", i);
        }
}
