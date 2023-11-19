#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strdiff(char *a, char *b)
{
    int idx = 0, res;

    for (size_t i = 0; a[i] != 0 && b[i] != 0; i++)  {
        res = a[i] & b[i];
        if (res != a[i] || res != b[i]) {
            int rasn = abs(a[i] - b[i]), step = 0;
            while (rasn != 1) {
                step++;
                rasn = rasn >> 1;
            }
            return idx + step;
        }
        idx += 8;
        //printf("%d\n", res);
    }
    if (strlen(a) == strlen(b))
        return -1;
    else
        return idx + 1;
}


int main() {
    char a[] = "";
    char b[] = "The quick brown fox jumps over the lazy dog";
    printf("%d", strdiff(a, b));
}
