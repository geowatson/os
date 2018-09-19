#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NMAX 10
// is_wake for consumer and producer
static int cwake = 0;
static int pwake = 1;

static int * buffer;
static int n = 0;

void *producer(pthread_t * pthread_id);
void *consumer(pthread_t * pthread_id);

int main() {
        pthread_t prod, cons;
        buffer = malloc(sizeof(int) * NMAX);
        for (int i = 0; i < NMAX; ++i) {
                buffer[i] = 0;
        }

        pthread_create(&prod, NULL, (void*)producer, prod);
        pthread_create(&cons, NULL, (void*)consumer, cons);

        pthread_exit(NULL);
}

void * producer(pthread_t * pthread_id) {
        while (1) {
                while (pwake) {
                        if (n + 1 == NMAX) {
                                pwake = 0;
                                cwake = 1;
                                // printf("s1\n");
                                break;
                        }
                        buffer[n] = 1;
                        n++;
                }
                printf("1\n");
                sleep(60);
        }
}

void *consumer(pthread_t * pthread_id) {
        while (1)
        while (cwake) {
                if (n == 0) {
                        pwake = 1;
                        cwake = 0;
                        // printf("s2\n");
                        break;
                }
                buffer[n] = 0;
                n--;
        }
}
