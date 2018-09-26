#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void SIGH(int sign) {
        if (sign == SIGKILL) {
                printf("Interrupted with kill command\n");
                exit(SIGKILL);
        }
        if (sign == SIGSTOP) {
                printf("Interrupted with stop command\n");
                exit(SIGSTOP);
        }
        if (sign == SIGUSR1) {
                printf("Interrupted with User 1 signal.\n");
                exit(SIGUSR1);
        }
}

int main() {
        signal(SIGKILL, SIGH);
        signal(SIGSTOP, SIGH);
        signal(SIGUSR1, SIGH);
        while (1) {
                sleep(1);
        }
}