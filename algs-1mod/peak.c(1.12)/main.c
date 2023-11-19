#include <stdio.h>


int array[] = {1, 2, 3, 4, 5, 3, 2, -5};

int less(unsigned long i, unsigned long j)
{
    return array[i] < array[j];
}

unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j))
{
    unsigned long int i;
    if (nel == 2)
    	return i;
    if (nel < 2)
    	return nel;
    for (i = 1; i < nel - 1; i++) {
        if (less(i, i + 1) == 1 && less(i, i - 1) == 0)
            return i;
    }
    return nel;

}


int main() {
    unsigned long i = peak(8, less);
    if ((i == 0 || array[i] >= array[i - 1]) && (i == 7 || array[i] >= array[i + 1])) {
        printf("Correct");
    }

}
