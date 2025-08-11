#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *str1;

    printf("\nDigite sua palavra: ");
    scanf("%s", str1);

    printf("A palavra digitada tem %d caracteres", strlen(str1));

    getchar();
    return 0;
}