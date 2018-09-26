#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void SIGH(int s) {
        if (s == SIGINT) {
                printf("\nInterrupted with Ctrl+C (or any other command)\n");
                exit(SIGINT);
        }
}

int main() {
        signal(SIGINT, SIGH);
        while (1) {
                sleep(1);
        }
}