#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
        int p[2];
        char in[] = "very awesome code test";
        char buff[50];

        pipe(p);
        if (!fork()) {
                close(p[0]);
                write(p[1], in, strlen(in) + 1);
        }
        else {
                close(p[1]);
                read(p[0], buff, sizeof(buff));
                printf("%s", buff);
        }
}