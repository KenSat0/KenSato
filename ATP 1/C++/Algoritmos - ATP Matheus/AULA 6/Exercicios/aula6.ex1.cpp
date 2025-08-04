/*programa que imprime um numero aleatorio de 2 até 12 (inclusos)*/

#include <stdio.h>
#include <Stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("%d", 2 + rand() % 11);
    
    getchar();
    return 0;
}