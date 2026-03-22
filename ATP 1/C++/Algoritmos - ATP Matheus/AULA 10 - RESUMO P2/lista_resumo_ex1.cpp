#include <stdio.h>
#include <stdlib.h>

int count = 0;

int main()
{
    printf("\n%d", count);
    count++;
    main();

    return 0;
}