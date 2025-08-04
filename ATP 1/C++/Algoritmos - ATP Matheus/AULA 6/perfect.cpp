int perfect(int n)
{
    int soma = 0;
    for (int i = 0; i<n; i++)
    {
        if (n%i == 0)
        {
            soma += i;
        }
    }
    if (soma==n) return (1);
    else return (0);
}