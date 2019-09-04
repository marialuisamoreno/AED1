#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int conteudo;
    struct Item *prox;
}Item;

void remover (Item *p);

int main ()
{
    int n;
    Item *A, *B, *C, *D, *E;

    A = malloc (sizeof (Item));
    B = malloc (sizeof (Item));
    C = malloc (sizeof (Item));
    D = malloc (sizeof (Item));
    E = malloc (sizeof (Item));
    A->prox = B;
    B->prox = C;
    C->prox = D;
    D->prox = E;
    E->prox = NULL;

    printf("Digite o conteudo das listas:\n");
    printf("Elemento 1: ");
    scanf("%d", &A->conteudo);
    printf("Elemento 2: ");
    scanf("%d", &B->conteudo);
    printf("Elemento 3: ");
    scanf("%d", &C->conteudo);
    printf("Elemento 4: ");
    scanf("%d", &D->conteudo);
    printf("Elemento 5: ");
    scanf("%d", &E->conteudo);

    printf("Qual elemento deseja remover: ");
    scanf("%d", &n);

    Item *p, *q;
    for (p = A; p != NULL; p = p->prox)
        printf ("%d ", p->conteudo);
    printf("\n");

    for (p = A; p != NULL; p = p->prox)
    {
        if (p->prox != NULL && p->prox->conteudo == n)
            remover(p);
    }

    if (A->conteudo != n)
        for (p = A; p != NULL; p = p->prox)
            printf ("%d ", p->conteudo);
    else
        for (p = B; p != NULL; p = p->prox)
            printf ("%d ", p->conteudo);

    return 0;
}

void remover (Item *p)
{
    Item *lixo;
    lixo = p->prox;
    p->prox = lixo->prox;
    free (lixo);
}