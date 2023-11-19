#include <stdio.h>
#include <stdlib.h>




void swap(int *p, int i, int j)
{
    int t = p[i];
    p[i] = p[j];
    p[j] = t;

}

int partition(int low, int high, int *p){
    int i = low;
    int j = low;
    while (j<high){
        if (p[j]<p[high]){
            swap(p,i,j);
            i = i+1;
        }
        j = j+1;
    }
    swap(p,i,high);
    return i;
}

int main()
{
    int n, m;
    scanf("%d%d", &n , &m);

    int *p = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", p + i);
    }
    partition(0, n - 1, p);

//    quicksort(0, n, m, p);

    for (int i = 0; i < n; i++)
        printf("%3d", *(p + i));

    return 0;
}
