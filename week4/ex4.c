#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern char ** environ;
static char * args[1024];
static int n = 0;

static char* skipwhite(char* s)
{
        while (isspace(*s)) ++s;
        return s;
}

static void split(char* cmd)
{
        cmd = skipwhite(cmd);
        char* next = strchr(cmd, ' ');
        int i = 0;

        while(next != NULL) {
                next[0] = '\0';
                args[i] = cmd;
                ++i;
                cmd = skipwhite(next + 1);
                next = strchr(cmd, ' ');
        }

        if (cmd[0] != '\0') {
                args[i] = cmd;
                next = strchr(cmd, '\n');
                next[0] = '\0';
                ++i;
        }
        n = i - 1;

        args[i] = NULL;
}

int main() {
        static char command[1024];
        pid_t pid;

        while(1) {
                fgets(command, 1024, stdin);
                split(command);
                if (strcmp(args[0], "exit") == 0) {
                        break;
                }
                if (strcmp("&", args[n]) == 0) {
                        if (fork() == 0) {
                                char ** args2 = args;
                                args2[n] = NULL;
                                execvp(args[0], args);
                        }
                }
                else {
                        system(command);
                }
        }
}
