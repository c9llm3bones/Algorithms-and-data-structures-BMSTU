#include <stdio.h>

int wcount(char *s)
{
    int cnt = 0, i = 0;
    for (; s[i] != 0; i++) {
        if (s[i] == ' ' && s[i - 1] != ' ' && i != 0)
            cnt++;
    }
    if (s[i - 1] != ' ' && s[0] != ' ')
        return cnt + 1;
    return cnt;
}


int main() {
    char *s;
    char *p = gets(s);
    //printf("%s\n", p);
    printf("%d", wcount(p));
}
//@%< !x 74. ; s0 [ P. ke \ t p r = XeD g
// cB 4