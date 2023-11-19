#include <stdio.h>
#include <string.h>

const int MXLEN = 1000;

char *concat(char **s, int n)
{
    size_t ln = 0;

    for ( int i = 0; i < n; i++)
        ln += strlen(s[i]);

    char *str[ln];

    for ( int i = 0; i < n; i++)
        str[i] = s[i];

    char **ans = str;

    return *ans;
}

int main() {
    int n;
    scanf("%d", &n);

    char s[MXLEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", &s[i]);
    }

    char *ans = concat(s, 3);
    printf("%s", ans);
}
