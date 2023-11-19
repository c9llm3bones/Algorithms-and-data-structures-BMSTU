#include <stdio.h>


int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    long arr[n];
    for (int i = 0; i < n; i++)
        scanf("%li", &arr[i]);

    for (unsigned mask = 1; mask < (1U << n); mask++) {
        long s = 0;
        for (unsigned i = 0; i < n; ++i) {
            if ((1U << i) & mask)
                s += arr[i];
        }
        if (!(s & (s - 1)) && s != 0) {
            cnt++;
            //printf("%li\n", s);
        }
    }
    printf("%d", cnt);
}
