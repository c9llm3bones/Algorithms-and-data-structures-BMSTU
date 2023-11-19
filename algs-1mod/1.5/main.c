
#include <stdio.h>

const int n = 8;

int main() {
    int s1 = 0, s2 = 0;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        s1 += a[i];
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        s2 += b[i];
    }

    if (s1 == s2) {
        int k = 0, prev = 0;

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < n; ++j) {
                if (a[i] == b[j])
                    k++;
            }

            if (k == prev) {
                printf("%s", "no");
                return 0;
            }

            prev = k;
        }
        if (k >= n)
            printf("%s", "yes");
    }

    else
        printf("%s", "no");

    return 0;
}