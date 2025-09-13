#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char str1[50];
    char str2[50];

    scanf("%s", str1);
    scanf("%s", str2);

    float cmp = strcmp(str1, str2);

    printf("\n%f", cmp);

    getchar();
    return 0;
}