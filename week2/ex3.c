#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // declare n implicitly
    // for emergency situations
    int n = argc > 1 ? atoi(argv[1]) : 6;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            putchar(j >= n - i - 1 & j <= n + i - 1 ? '*' : ' ');
        }
        putchar('\n');
    }

    return 0;
}

