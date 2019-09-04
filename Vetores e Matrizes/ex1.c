#include <stdio.h>
#include <stdlib.h>

void crescente (int v[], int n);
void mediana (int v[], int n, float *med);

int main()
{
    int *v;
    int n, i;
    float med;
    printf("Quantos numeros iremos analisar?\n");
    scanf("%d", &n);

    v = (int*)malloc(n*sizeof(int));

    printf("Digite os numeros:\n");
    for (i=0; i<n; i++)
        scanf("%d", &v[i]);

    crescente(v, n);
    mediana(v, n, &med);

    printf("\n\nMediana: %.0f\n", med);

    free(v);
    return 0;
}

void mediana (int v[], int n, float *med)
{
    int i;
    float m1, m2;

    printf("Vetor Ordenado:\n");
    for (i=0; i<n; i++)
        printf ("%d ", v[i]);

    switch (n%2)
    {
        case 0: ///par
        m1 = v[n/2 - 1];
        m2 = v[n/2];
        m1 += m2;
        *med = (m1/2);

        case 1: ///impar
        m1 = v[(n-1)/2];
        *med = m1;
  }
}

void crescente (int v[], int n)
{
    int i, j, aux;

    for (i=0; i<(n-1); i++)
    for (j=i+1; j<n; j++)
        if (v[i] > v[j])
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
}