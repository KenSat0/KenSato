#include <stdio.h>
#include <stdlib.h>

float y(float x)
{
    float a = 2.0f, b = 3.0f;
    return a * x + b;
}

int main()
{
    char c;
    float resposta;

    for (int i = 0; i < 100; i++)
    {
        resposta = y(2.0f);
        printf("%.2f", resposta);
    }

    scanf("%c", &c);
    return 0;
}
    