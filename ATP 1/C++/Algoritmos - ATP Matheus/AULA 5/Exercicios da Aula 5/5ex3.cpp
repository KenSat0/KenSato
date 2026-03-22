#include <stdio.h>
#include <stdlib.h>

float celcius_para_fahrenheit(float c)
{
    return ((c*1.8f)+32.0f);
}

int main()
{
    float c;
    
    printf("Digite a temperatura em celcius: ");
    scanf("%f", &c);
    c = celcius_para_fahrenheit(c);

    printf("%.2f", c);
}
