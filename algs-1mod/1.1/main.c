#include <stdio.h>
#define ll long long

/*
5
2
3 4 5 2 3 6
resp = 3 * 2 *5 +
*/
int main()
{
    ll n, x0, resp = 0, res = 0, a1;
    //printf("%d", 3 * 2 * 5 + 4 * 2 * 4 + 5 * 2 * )
    scanf("%lli %lli %lli", &n, &x0, &a1);

    for (int i = 0; i < n; i++) {
        ll a;
        scanf("%lli", &a);

        if (i == 0) {
            res = a1 * x0 + a;
            resp = n * a1 * x0 + a * (n - 1);
        }

        else {
            res = res * x0 + a;
            if (i + 1 != n)
                resp = resp * x0 + a * (n - i - 1);
            }
    }

    printf("%lli %lli", res, resp);


}