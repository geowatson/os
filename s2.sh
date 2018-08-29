# exercise 1
echo '#include <stdio.h>\n#include "limits.h"\n#include "float.h"\n\nint main() {\n    int i;\n    float f;\n    double d;\n\n    i = INT_MAX;\n    f = FLT_MAX;\n    d = DBL_MAX;\n    // i, f, d - size : value\n    printf("%d %d\\n%d %f\\n%d %f", (int)sizeof(i), i, (int)sizeof(f), f, (int)sizeof(d), d);\n\n    return 0;\n}' > week2/ex1.c

# exersice 2
echo '#include <stdio.h>\n#include "stdlib.h"\n#include "string.h"\n\nint main() {\n    // Reserve str in dynamic memory.\n    // Implicitly declare len for your\n    // string if not matches requirements.\n    long len = 100000;\n    char *str = malloc(sizeof(char) * len);\n    \n    scanf("%s", str);\n    for (int i = (int)strlen(str); i > 0; --i) {\n        putchar(str[i - 1]);\n    }\n    \n    return 0;\n}' > week2/ex2.c

# exersice 3
echo "#include <stdio.h>\n#include "stdlib.h"\n#include "string.h"\n\nint main() {\n    // declare n implicitly\n    // for emergency situations\n    int n = 6;\n    scanf("%d", &n);\n    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < 2 * n - 1; ++j) {\n            putchar(j >= n - i - 1 & j <= n - i - 1 + 2 * (i + 1) - 2 ? \'*\' : \' \');\n        }\n        i != n - 1 ? putchar(\'\\n\'): 0;\n    }\n\n    return 0;\n}" > week2/ex3.c

# exersice 4
# echo > ex4.c
