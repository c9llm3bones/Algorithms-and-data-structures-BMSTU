#include <stdio.h>
#include <stdlib.h>



int main()
{
    int nums[100000] = {0}, primes[100000] = {0};

    int x, maxdl = 0;

    scanf("%d", &x);

    for (int i = 0; i < 100000; ++i) {
        nums[i] = i;
    }
    if (x < 0)
        x = -x;

    for (int p = 2, i = 0; p < 100000; p++) {
        if (nums[p] != 0) {
            i++;
            primes[i] = nums[p];
            if (x % primes[i] == 0 && maxdl < primes[i])
                maxdl = primes[i];
            for (int j = p*p; j < 100000 - p; j += p) {
                nums[j] = 0;
            }
        }

    }

    printf("%d", maxdl);
}