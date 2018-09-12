#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        char * in = malloc(sizeof(char) * 1024);
        scanf("%s", in);
        system(in);
}
