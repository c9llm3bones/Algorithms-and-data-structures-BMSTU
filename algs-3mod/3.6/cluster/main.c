#include <stdio.h>
#include <stdlib.h>

struct priority_queue {
    int *data;
    int cap, count;
};

struct priority_queue *InitPriorityQueue(int capacity)
{
    struct priority_queue *q = (struct priority_queue *)calloc(1, sizeof(struct priority_queue));
    q->cap = capacity;
    q->count = 0;
    q->data = (int *)malloc(sizeof(int)*capacity);
    return q;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void swap (int *data, int i, int j)
{
    int t = data[i];
    data[i] = data[j];
    data[j] = t;
    return;
}


void Insert (struct priority_queue *PQ, int ptr)
{
    int i = PQ->count;
    if (i == PQ->cap) {
        printf("ERROR: PQ is fulled\n");
        return;
    }

    PQ->count++;
    PQ->data[i] = ptr;

    while (i > 0 && PQ->data[(i-1)/2]>PQ->data[i]) {
        swap(PQ->data, (i-1)/2, i);
        i = (i-1)/2;
    }

}

void Heapify(struct priority_queue *PQ, int n, int i)
{
   while (1) {

        int l = 2*i + 1;
        int r = 2*i + 2;
        int j = i;

         if (l < n && PQ->data[i] > PQ->data[l])
            i = l;

        if (r < n && PQ->data[i] > PQ->data[r])
            i = r;

        if (i == j)
            break;

        swap(PQ->data, i, j);

    }

}


int ExtractMax(struct priority_queue *pq)
{
    int x = pq->data[0];
    pq->count--;

    if (pq->count > 0) {
        pq->data[0] = pq->data[pq->count];
		Heapify(pq, pq->count, 0);
	}

	return x;
}




int main()
{
    int n, m, ans = 0, sum = 0;
    scanf("%d\n%d", &n, &m);
    struct priority_queue *pq = InitPriorityQueue(n);

    for(int i = 0; i < n; i++) {

		int t1, t2;
		scanf("%d %d", &t1, &t2);

		sum = t1 + t2;

		ans = max(sum, ans);

		Insert(pq, sum);
	}

	for(int i = n; i < m; i++) {

		int cur = ExtractMax(pq);
		int t1, t2;

		scanf("%d %d", &t1, &t2);

		cur = max(cur, t1) + t2;
		ans = max(ans, cur);

		Insert(pq, cur);
	}
	printf("%d\n", ans);

	free(pq->data);
	free(pq);

    return 0;
}
