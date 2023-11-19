// не работает
#include <stdio.h>
#include <stdlib.h>


int fib(int n) {
    if (n < 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}


int main() {
    int x;
    scanf("%d", &x);

    int fibs[100] = {0};
    for (int i = 0; i < 100; ++i) {
        fibs[i] = fib(i);
    }

    while (x > 0)
    {
        int  r = 100, l = -1;

        while (l + 1 < r) {
            int mid = (r + l) / 2;
            if (fibs[mid] <= x)
                l = mid;
            else
                r = mid;
        }
        printf("%d ", fibs[l]);
        x -= fibs[l];
    }

}
