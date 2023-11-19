#include <stdio.h>
#include <stdlib.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
    unsigned long *maxel = base;
    int idx = 0;

    for ( int i = 0; i < nel; i++ ) {
        if ( compare(base + i * width, maxel) > 0 ) {
            maxel = base + i * width;
            idx = i + 1;
        }
    }
    return idx;
}

int compare (void *a, void *b) {
    return (*(int*)a - *(int*)b);
}



int main() {
    int a[10] = {-2, -5, 20, 10, 20, -56, -3, 4, 5, 5};
    int *p = a;
    int ans;
    ans = maxarray(p, 10, sizeof(int), compare);
    printf("%d", ans);


}
