#include <stdio.h>
#include <stdlib.h>
const int x = 10;


unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long  l = 0, r = nel;

    while (l + 1 > r) {
        unsigned long mid = (l + r) / 2;
        if (compare (mid) == -1)
            l = mid;
        else if (compare (mid) == 1)
            r = mid;
        else if (compare(mid) == 0)
            return l;
    }
    return nel;
}

int compare(unsigned long i) {
    if (i < x)
        return -1;
    if (i > x)
        return 1;
    return 0;
}


int main() {
    int a[5] = {1,6,10,90, 100};
    unsigned long ans = binsearch(5, compare);
    printf("%d", ans);
}
