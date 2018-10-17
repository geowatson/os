#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <limits.h>

// p_num - page number
typedef int p_num;
typedef char bit;

// page frame - here we only require R bit,
// page number and counter, and algorithm will work
typedef struct {
        bit R;
        p_num number;
        unsigned long counter;
} frame;

void page_load(frame * f, p_num p);

static frame * frames;
static int tsize;
static int pmin;
static unsigned long cmin = LONG_MAX;
static int tcurrent = 0;
static int hit = 0, miss = 0;

int main() {
        p_num p;
        FILE * file = fopen("data", "r");

        printf("Enter size for page frames table: ");
        scanf("%d", &tsize);
        frames = (frame*)malloc(tsize * sizeof(frame));
        for (int i = 0; i < tsize; ++i) {
                frames[i].number = 0;
                frames[i].counter = 0;
                frames[i].R = 0;
        }

        while(!feof(file)) {
                fscanf(file, "%d", &p);
                page_load(frames, p);
        }
        printf("%.10f", (double)hit / miss);

        fclose(file);
        free(frames);
        return 0;
}

void page_load(frame * f, p_num n) {
        int is_hit = 0;
        for (int i = 0; i < tcurrent; ++i) {
                if (f[i].number == n) {
                        hit += 1;
                        is_hit = 1;
                        break;
                }
        }
        if (!is_hit) {
                miss++;
                if (tsize != tcurrent) {
                        f[tcurrent++].number = n;
                }
                else {
                        f[pmin].number = n;
                        f[pmin].counter = 0;
                }
        }

        for (int i = 0; i < tcurrent; ++i) {
                f[i].counter >>= 1;
                if (f[i].number == n) {
                        f[i].counter |= (unsigned long) 1 << 63;
                }
                if (cmin > f[i].counter) {
                        cmin = f[i].counter;
                        pmin = i;
                }
        }

        cmin = LONG_MAX;
}