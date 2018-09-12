#include <stdio.h>
#include <unistd.h>

int main() {
        switch (fork()) {
                case 0: {
                        printf("Hello from child [PID - %d]\n", getpid());
                        break;
                }
                default: {
                        printf("Hello from parent [PID - %d]\n", getpid());
                        break;
                }
        }
}
