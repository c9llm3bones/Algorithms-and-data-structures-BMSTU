#include <stdio.h>

#define ll long long

int main() {
    unsigned ll a, b, m, cnt = 0;
    scanf("%lli %lli %lli", &a, &b, &m);

    for (int i = 63; i >= 0; i--) {
        if (((a >> i) & 1) == 1) {
            cnt += b;
            cnt %= m;
        }
        if (i != 0) {
            cnt *= 2;
            cnt %= m;
        }
    }
    printf("%lli", cnt);
}
