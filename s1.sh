# task 1
mkdir ./week1
ls /usr/bin | grep gcc | sort -r > week1/ex1.txt

# task 2
history > week1/ex2.txt

# task 3
echo "date\nsleep 3\ndate" > week1/ex3.sh
sh week1/ex3.sh

# task 4
echo '#include <stdio.h>\nmain() {\n  printf("Hello World");\n}' > week1/main.c
gcc week1/main.c -o week1/ex4
week1/ex4
