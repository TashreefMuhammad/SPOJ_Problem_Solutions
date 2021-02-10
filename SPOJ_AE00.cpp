#include <stdio.h>

int main(void)
{
    int n, i, j, cnt = 0;

    scanf("%d", &n);

    for(i = 1; i * i <= n; ++i)
        cnt += ((n/i) - (i -1));

    printf("%d\n", cnt);

    return 0;
}
