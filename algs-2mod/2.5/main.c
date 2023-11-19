#pragma GCC optimize("unroll-loops", "O3")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(char *s)
{
    int i = 0;
    char c;
    while (1)
    {
        c = getchar();
        if (c == '\n')
            return;
        s[i] = c;
        i++;

    }

}

void dsort(char *s)
{
    char alph[] = "abcdefghijklmnopqrstuvwxyz";
    int counters[150] = {0};
    int size = strlen(s);
    for (int i = 0; i < size; i++) {
        int a;
        a = s[i] - '0';
        counters[a]++;
    }
    for (int i = 49; i < 75; i++){
        for (int j = 0; j < counters[i]; j++)
            printf("%c", alph[i - 49]);

    }

}


int main()
{
    char *s = (char*)malloc(1000000*sizeof(char));
    scan(s);
    dsort(s);
    free(s);
    return 0;
}