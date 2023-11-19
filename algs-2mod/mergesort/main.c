#include <stdio.h>

long *mergesort (long a[], int l, int r)
{
    if (r - l < 5) {
        for (int i = 0; i < r; i++)
            for (int j = i; j >= 0 && a[j - 1] > a[j]; j--) {
                long el = a[j - 1];
                a[j - 1] = a[j];
                a[j] = el;
            }
        for (int i = 0; i < r; i++)
            printf("%li ", a[i]);
        return a;
    }
    int M = (l + r) / 2;

    mergesort(a, M, r);
    printf("\n");
    mergesort(a, l, M);

}

int main() {
    int n;
    scanf("%d", &n);
    long a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%li", &a[i]);
    }

    long *ans = mergesort(a, 0, n);

    return 0;
}
