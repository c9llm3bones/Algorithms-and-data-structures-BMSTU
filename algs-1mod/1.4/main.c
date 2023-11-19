#include <stdio.h>

int main() {

    unsigned long int s1 = 0, s2 = 0;
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int num;
        scanf("%d", &num);
        s1 = s1 | (1 << num);
    }

    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        int num;
        scanf("%d", &num);
        s2 = s2 | (1 << num);
    }
    unsigned long int ans = s1 & s2;
    //printf("%ld %ld ", s1, s2);
    //printf("%ld ", ans);

    for (int i = 0; i <= 31; ++i) {
        if ((1 << i) > ans)
            break;
        if (((ans >> i) & 1) == 1)
            printf("%d ", i);
    }
    return 0;
}