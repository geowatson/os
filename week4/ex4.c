#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
        static char * command;

        while(1) {
                printf("simple: shell$ ");
                command = malloc(sizeof(char) * 1024);
                fgets(command, 1024, stdin);
                if (!strcmp(command, "exit\n")) {
                        break;
                }
                if (strlen(command) && command[strlen(command) - 1] == '&') {
                        if (fork() == 0) {
                                system(command);
                        }
                }
                else if (strlen(command)) {
                        system(command);
                }
        }
}
