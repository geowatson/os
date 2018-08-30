#include <stdio.h>
#include <stdlib.h>

// suppose n, i > 0; c in int.
#define profunctor_optics ( \
(c == 1) ? 1 : \
(c == 2) ? 1 : \
(c == 3) ? 1 : j >= n - i - 1 & j <= n + i - 1)

// defines height
#define habr ( \
(c == 2) ? 2 * n - 1 : n)

// defines width
// p.s I am sorry for using one macro in another.
#define nplus1 ( \
(c == 1) ? i + 1 : \
(c == 2) ? i < habr / 2 ? i + 1 : habr - i : \
(c == 3) ? n : n + i)

/*
    Choices 1, 2, 3 goes from task 5;
    Anything else: base chart (task 3);

    How to run : ./ex5 <height(optional)> <choice(optional, only after height)>

    Running without any parameter or without choice will plot chart from task 3
*/
int main(int argc, char** argv) {
    // n - height (or width) - basic case 6;
    // c - choice - basic case 0;
    int n = argc > 1 ? atoi(argv[1]) : 6;
    int c = argc > 2 ? atoi(argv[2]) : 0;

    // habr is usually n; 2n+1 if right-sided triangle.
    for (int i = 0; i < habr; ++i) {
        // nplus1 is a current width parameter
        for (int j = 0; j < nplus1; ++j) {
            // profunctor is a choice for (programmers) * symbol
            putchar(profunctor_optics ? '*' : ' ');
        }
        putchar('\n');
    }

    return 0;
}
