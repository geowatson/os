#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

int main() {
        int c = 0;
        while(c++!=10) {
                int * mem = malloc(sizeof(int) * 1024 * 256);
                memset(mem, 0, 1024 * 1024);
                sleep(1);
        }
}