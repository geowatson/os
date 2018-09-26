#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
        int p[2];
        pid_t p1;
        pid_t p2;
        int status;

        pipe(p);
        p1 = fork();
        if (!p1) {
                read(p[0], &p2, 10);
                close(p[0]);
                sleep(2);
                kill(p2, SIGSTOP);
                printf("stopped child 2\n");
        }
        else {
                p2 = fork();
                if (!p2) {
                        printf("child 2 created\n");
                        while(1) {
                                sleep(1);
                                printf("child 2 alive\n");
                        }
                }
                else {
                        write(p[1], &p2, 10);
                        close(p[0]);
                        close(p[1]);
                        waitpid(p2, &status, WUNTRACED);
                        printf("child 2 stopped\n");
                }
        }
}