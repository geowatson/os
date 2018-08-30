#include <stdio.h>

void swap(long * a, long * b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main() {
    long a, b;
    scanf("%ld %ld", &a, &b);
    swap(&a, &b);
    printf("%ld %ld\n", a, b);
}
