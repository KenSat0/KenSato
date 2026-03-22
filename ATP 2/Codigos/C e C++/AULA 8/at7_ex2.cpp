#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int str_rev(char *str, int lenght)
{
    printf("%c", str[lenght]);
    if(lenght == 0)
    {
        return 0;
    }
    return(str_rev(str, lenght-1));
}

int main()
{
    char str[11]= "merda mole";
    str_rev(str, strlen(str));

    getchar();
    return 0;
}
