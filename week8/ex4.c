#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>

int main() {
        int c = 0;
        while(c++!=10) {
                int * mem = malloc(sizeof(int) * 1024 * 256);
                memset(mem, 0, 1024 * 1024);
                struct rusage ru;
                getrusage(RUSAGE_SELF, &ru);
                printf("Maximum resident set size utilized (Memory usage in bytes): %ld\n", ru.ru_maxrss);
                sleep(1);
        }
}