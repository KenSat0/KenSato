#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SelectSort(int* lista, int size)
{
    if (size == 1) 
    {
        printf("\nLista organizada");
        for (int i = 0; i<10; i++)
        {
            printf("\n%d", lista[i]);
        }
        return 1;
    }

    int high_index = 0;
    for (int i = 0; i<size; i++)
    {
        if (lista[i] > lista[high_index])
        {
            high_index = i;
            continue;
        }
    }

    int temp = lista[size-1];
    lista[size-1] = lista[high_index];
    lista[high_index] = temp;

    SelectSort(lista, size-1);
}

void Merge(int* listaA, int low, int medio, int n, int* listaZ)
{
    int i = low;
    int j = medio + 1;
    int k = low;

    while (i <= medio && j <= n)
    {
        if(listaA[i] <= listaA[j])
        {
            listaZ[k] = listaA[i];
            i++;
        }
        else
        {
            listaZ[k] = listaA[j];
            j++;
        }
        k++;
    }
    if (i>medio)
    {
        while (j <= n)
        {
            listaZ[k] = listaA[j];
            j++;
        }
    }
    else    
    {
        while (i <= medio)
        {
            listaZ[k] = listaA[i];
            i++;
        }
    }
}

void MergePart(int* listaA, int* listaZ, int n, int lenght)
{
    int i = 0;
    while (i<=n-2*lenght-1)
    {
        Merge(listaA, i, i+lenght-1, i+2*lenght-1, listaZ);
        i = i+2 * lenght;
    }
    if (i + lenght - 1 < n) Merge (listaA, i, i+lenght-1, n - 1, listaZ);
    else
    {
        int indexA = i;
        int indexZ = i;
        while(indexA <= n)
        {
            listaZ[indexZ] = listaA[indexA];
            indexZ++;
            indexA++;
        }
    }
}

void MSort(int* ListaA, int* ListaZ, int n)
{
    int lenght = 1;

    int* current = ListaA;
    int* temp = ListaZ;

    while (lenght < n)
    {
        MergePart(ListaA, ListaZ, n, lenght);
        lenght = 2*lenght;
        MergePart(ListaZ, ListaA, n, lenght);
        lenght = 2*lenght;

        int* swap = current;
        current = temp;
        temp = swap;
    }

    if(current == ListaA)
    {
        for (int i = 0; i<n; i++)
        {
            ListaZ[i] = ListaA[i];
        }
    }
}

int main()
{
    int ListaA[10] = {67, 22, 13, 17, 3, 55, 77, 9, 6, 69};
    int ListaZ[10];

    //SelectSort(ListaA, 10);

    MSort(ListaA, ListaZ, 10);
    for (int i = 0; i<10; i++)
    {
        printf("\n%d", ListaZ[i]);
    }
}

