#include <stdio.h>
#include "stdlib.h"
#include "string.h"

int main() {
    // Reserve str in dynamic memory.
    // Implicitly declare len for your
    // string if not matches requirements.
    long len = 100000;
    char *str = malloc(sizeof(char) * len);
    
    scanf("%s", str);
    for (int i = (int)strlen(str); i > 0; --i) {
        putchar(str[i - 1]);
    }
    
    return 0;
}
