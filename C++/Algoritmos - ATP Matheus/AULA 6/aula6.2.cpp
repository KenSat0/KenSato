#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int r;

    srand(time(NULL)); /*randomizador baseado no relogio interno*/

    for(int i = 0; i<10; i++)
    {
        r = rand();
        printf("%d\n", r % 6 + 1); //simulador de D6
    }

    getchar ();
    return 0;
}

