#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <utility>

int mdc(int x, int y)
{
    if(x > y)
    {
        int temp = y;
        y = x;
        x = temp;
    }
    if(y%x == 0)
    {
        return x;
    }
    return(mdc(x, y%x));
}

int main()
{
    int a, b, c;
    printf("\nA: ");
    scanf("%d", &a);

    printf("\nB: ");
    scanf("%d", &b);

    printf("\nC: ");
    scanf("%d", &c);

    printf("\nMDC: %d", mdc(mdc(a, b), c));

    getchar();
    return 0;
}
