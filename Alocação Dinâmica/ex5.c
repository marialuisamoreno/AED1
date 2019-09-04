#include <stdio.h>
#include <stdlib.h>

void f (float a[], float *m, float *n, int *pos1, int *pos2);

int main()
{
    float a[10];
    float maior, menor;
    float *m, *n;
    int *pos1, *pos2;
    int i, posmaior=0, posmenor=0;

    printf("Digite um valor diferente para cada posicao.\n\n");
    for (i=0; i<10; i++)
    {
        printf("A[%d]: ", i);
        scanf("%f", &a[i]);
    }
    m = &maior;
    n = &menor;
    pos1 = &posmaior;
    pos2 = &posmenor;

    f(a, m, n, pos1, pos2);

    printf("O menor elemento de N e %f e sua posicao dentro do vetor e %d\n\n", menor, posmenor);
    printf("O maior elemento de N e %f e sua posicao dentro do vetor e %d\n\n", maior, posmaior);

    return 0;
}

void f (float a[], float *m, float *n, int *pos1, int *pos2)
{
    int i;
    *m = a[0];
    *n = a[0];

    for (i=0; i<10; i++)
    {
        if (a[i]>*m)
        {
            *m = a[i];
            *pos1 = i;
        }
        if (a[i]<*n)
        {
            *n = a[i];
            *pos2 = i;
        }
    }
}