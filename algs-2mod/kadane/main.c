#include <stdio.h>

int a[] = {1, 5, 3, 6, 7, -100, 21, 23, 3, 5, 6, -1};


int kadane(int n)
{
    int l = 0, r = 0, mxsum = 0, sum = 0, start = 0, i = 0;
    while  (i < n) {
        sum += a[i];
        if (sum > mxsum) {
            mxsum = sum;
            l = start;
            r = i;
        }
        i++;
        if (sum < 0) {
            sum = 0;
            start = i;
        }
    }
    printf("%d%d", l, r);
}



int main() {
    kadane(11);
    return 0;
}
