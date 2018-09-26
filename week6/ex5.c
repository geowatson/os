#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
        pid_t f = getpid();
        pid_t k = fork();
        if (k) {
                while (1) {
                        printf("I’m alive\n");
                        sleep(1);
                }
        }
        else {
                sleep(10);
                kill(k, SIGTERM);
        }
}