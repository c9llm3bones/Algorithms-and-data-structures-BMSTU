#include <stdio.h>
#include <string.h>

/*
 * void revarray(void *base, unsigned long nel, unsigned long width) {
    int *i, *j;
    i = base;
    for (j = base; j - i < vlen; j++);
    for (;i - j < 0; i++, j--) {

    }
}
*/
const int *n = 5;

int main() {

    int a[4] = {1, 2, 3, 4};
    int *p;

    for (p = a; p - a < 4; ++p) {
        printf("%d ", *p);
    }
    char s1 [8] = { 'm', 'o', 'u', 's', 'e' , 0};
    char s2 [8] = " mouse ";
    printf("%s\n", s1);
    n++;
    printf("%d", strlen(s1));
}
