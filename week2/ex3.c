#include <stdio.h>
#include stdlib.h
#include string.h

int main() {
    // declare n implicitly
    // for emergency situations
    int n = 6;
    scanf(%d, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            putchar(j >= n - i - 1 & j <= n - i - 1 + 2 * (i + 1) - 2 ? \'*\' : \' \');
        }
        i != n - 1 ? putchar(\'
\'): 0;
    }

    return 0;
}
