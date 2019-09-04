#include <stdio.h>
#include <stdlib.h>

typedef struct reg celula;

struct reg
{
   int *conteudo;
   celula *prox;
};

int main ()
{
    int i, count=0;
    celula *A, *B;

    A = malloc (sizeof (celula));
    B = malloc (sizeof (celula));

    A->prox = NULL;
    B->prox = A;

    A->conteudo = malloc(5*sizeof(int));
    B->conteudo = malloc(5*sizeof(int));

    printf("Valores de A:\n");
    for (i=0; i<5; i++)
        scanf("%d", &A->conteudo[i]);

    printf("Valores de B:\n");
    for (i=0; i<5; i++)
        scanf("%d", &B->conteudo[i]);

    for (i=0; i<5; i++)
    {
        if (A->conteudo[i] == B->conteudo[i])
            count ++;
    }

    if (count == 5)
        printf("Sao iguais!\n");
    else printf("Nao sao iguais!\n");

    return 0;
}