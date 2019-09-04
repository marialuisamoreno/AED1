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
    int n, i;
    celula *le;

    le = malloc (sizeof (celula));
    le->prox = NULL;

    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    le->conteudo = malloc(n*sizeof(int));

    for (i=0; i<n; i++)
        scanf("%d", &le->conteudo[i]);

    for (i=0; i<n; i++)
        printf ("%d\n", le->conteudo[i]);

    return 0;
}
