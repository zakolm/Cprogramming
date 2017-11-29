#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "constant.h"
#include "MyMath.h"
#include "WorkFile.h"

#define N 5

unsigned long tick(void)
{
    unsigned long d;
    
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    
    return d;
}

void time(int n, char name_mas[])
{
    FILE * file;

    unsigned long tb, te, t;

    int *arr_1;
    int *arr_1_e;

    file = fopen(name_mas, "r");
    printf("Test %d:\n", n + 1);
    t = 0;
    for (int i = 0; i < N; ++i)
    {
        fseek(file, 0, seek_set);
        scan_array(file, &arr_1, &arr_1_e);
        tb = tick();
        mysort(arr_1, arr_1_e - arr_1, sizeof(int), compare_int_and_ch);
        te = tick();
        t += (te - tb);
        free(arr_1);
    }

    printf("    'mysort': %lu\n", t / N);

    int *arr_2;
    int *arr_2_e;

    t = 0;
    for (int i = 0; i < N; ++i)
    {
        fseek(file, 0, seek_set);
        scan_array(file, &arr_2, &arr_2_e);
        tb = tick();
        qsort(arr_2, arr_2_e - arr_2, sizeof(int), compare_int_and_ch);
        te = tick();
        t += (te - tb);
        free(arr_2);
    }

    printf("    'qsort': %lu\n", t / N);

    printf("\n");

    fclose(file);
}

int main(void)
{
    char files[][14] =
        {
        "src/in_1.txt",
        "src/in_2.txt",
        "src/in_3.txt",
        "src/in_4.txt",
        "src/in_5.txt",
        "src/in_6.txt",
        "src/in_7.txt",
        "src/in_8.txt",
        "src/in_9.txt",
        "src/in_10.txt"
        };

    for (int i = 0; i < sizeof(files) / sizeof(files[0]); ++i)
        time(i, files[i]);

    return 0;
}