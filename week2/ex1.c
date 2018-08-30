#include <stdio.h>
#include "limits.h"
#include "float.h"

int main() {
    int i;
    float f;
    double d;

    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    // i, f, d - size : value
    printf("%d %d\n%d %f\n%d %f\n", (int)sizeof(i), i, (int)sizeof(f), f, (int)sizeof(d), d);

    return 0;
}
