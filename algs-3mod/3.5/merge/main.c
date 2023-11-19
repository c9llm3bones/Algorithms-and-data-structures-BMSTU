#include <stdio.h>
#include <stdlib.h>


struct elem {
    int *elems;
    int size, idx;
};


struct priority_queue
{
    struct elem *heap;
    int cap, count;
};


struct priority_queue *newPQ(int capacity)
{
    struct priority_queue *PQ = (struct priority_queue *)malloc(sizeof(struct priority_queue));
    PQ->heap = (struct elem *)malloc(capacity * sizeof(struct elem));
    PQ->cap = capacity;
    PQ->count = 0;
    return PQ;
}

void swap(struct priority_queue *PQ, int i, int j)
{
    struct elem t = PQ->heap[i];

    PQ->heap[i] = PQ->heap[j];
    PQ->heap[j] = t;
    return;
}

int compare(struct elem a, struct elem b)
{
    if (a.elems[a.idx] > b.elems[b.idx])
        return 1;
    return 0;

}

int queueEmpty(struct priority_queue *PQ)
{
	if (PQ->count == 0)
        return 1;
    return 0;
}

void Heapify(struct priority_queue *PQ, int n, int i)
{
   while (1) {

        int l = 2*i + 1;
        int r = 2*i + 2;
        int j = i;

         if (l < n && compare(PQ->heap[i], PQ->heap[l]) == 1)
            i = l;

        if (r < n && compare(PQ->heap[i], PQ->heap[r]) == 1)
            i = r;

        if (i == j)
            break;

        swap(PQ, i, j);

    }

}

void Insert (struct priority_queue *PQ, struct elem ptr)
{
    int i = PQ->count;
    if (i == PQ->cap) {
        printf("ERROR: PQ is fulled\n");
        return;
    }

    PQ->count++;
    PQ->heap[i] = ptr;

    while (i > 0 && compare(PQ->heap[(i-1)/2],PQ->heap[i]) == 1) {
        swap(PQ, (i-1)/2, i);
        i = (i-1)/2;
    }

}

struct elem ExtractMax(struct priority_queue *PQ)
{
    struct elem MAX = PQ->heap[0];
    --PQ->count;
    if (PQ->count > 0) {
            PQ->heap[0] = PQ->heap[PQ->count];
            Heapify(PQ, PQ->count, 0);
    }
    return MAX;
}

void PrintQueue(struct priority_queue *PQ)
{
    while (1) {
        struct elem MAX = ExtractMax(PQ);
        printf("%d", MAX.elems[MAX.idx]);
        int cur_idx = MAX.idx + 1;
    }
}



int main()
{
    int k;  scanf("%d", &k);
    int *size_n = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &size_n[i]);
    }

    struct priority_queue *PQ = newPQ(k);

    for (int i = 0; i < k; i++) {
        struct elem *CurElem = (struct elem *)malloc(sizeof(struct elem));

        CurElem->elems = (int *)malloc(sizeof(int) * size_n[i]);
        for(int j = 0; j < size_n[i]; j++){
            scanf("%d", &CurElem->elems[j]);
        }

        CurElem->idx = 0;
        CurElem->size = size_n[i];

        Insert(PQ, *CurElem);
        free(CurElem);


    }

    while (1) {
        struct elem MAX = ExtractMax(PQ);
        printf("%d ", MAX.elems[MAX.idx]);
        int cur_idx = MAX.idx + 1;

        if (MAX.size > cur_idx) {
            MAX.elems[++MAX.idx] = MAX.elems[cur_idx];

            Insert(PQ, MAX);
        }

        else
            free(MAX.elems);

        if (PQ->count == 0)
            break;

    }


    free(size_n);
    free(PQ->heap);
    free(PQ);

    return 0;
}
