#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int j, i = 1;

    while (i <= 10)
    {
        j = 1;
        while (j <= 10)
        {
            printf("%d x %d = %d\n", i, j, i*j);
            j++;
        }
        i++;
    }

    scanf("%c");
    return(0);
}