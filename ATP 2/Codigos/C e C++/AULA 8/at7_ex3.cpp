#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ackermann(int m, int n)
{
    if(m == 0)
    {
        return n + 1;
    }
    if(m > 0 && n == 0)
    {
        return (ackermann(m-1, 1));
    }
    if(m > 0 && n > 0)
    {
        return (ackermann(m - 1, ackermann(m, n - 1)));
    }
    return 0;
}

int main()
{
    printf("\n%d", ackermann(3, 2));

    getchar();
    return 0;
}
