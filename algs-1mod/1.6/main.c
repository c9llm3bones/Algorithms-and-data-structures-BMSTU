#include <stdio.h>


/*
void dfs(int a[][10], int v)
{
    used[v] = 1;
    for (size_t i = 0; i < sizeof(a); ++i) {
        if (a[i][v] && used[i] == 0) {
            dfs(a, i);
        }
    }
}*/


int main()
{
    int n, k, idx = 0;
    long mx = 0;

    scanf("%d", &n);
    long a[n];

    for(int i = 0; i < n; ++i)
        scanf("%li", &a[i]);

    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        mx += a[i];

    long s = mx;


    for (int i = k; i < n; ++i) {
        s = s - a[idx] + a[i];
        idx++;
        if (mx < s)
            mx = s;
    }

    printf("%li", mx);
}
