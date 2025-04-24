#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int xa, xb, ya, yb;

float distancia(int xa, int xb, int ya, int yb)
{
    return (sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));
}

int main()
{
    int xa = 6;
    int xb = 3;
    int ya = 5;
    int yb = 1;
    float dist;

    dist = distancia(xa, xb, ya, yb);

    printf("%.2f", dist);
    
    return 0;
}