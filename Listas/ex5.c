#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int conteudo;
    struct Item *prox;
}Item;
void remover (Item *p);

struct lista
{
    Item *inicio, *fim;
};

int main()
{
    char n;
    Item *A, *B, *C, *D, *E, *p, *q;

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
    printf("Lista 1: ");
    scanf("%d", &A->conteudo);
    printf("Lista 2: ");
    scanf("%d", &B->conteudo);
    printf("Lista 3: ");
    scanf("%d", &C->conteudo);
    printf("Lista 4: ");
    scanf("%d", &D->conteudo);
    printf("Lista 5: ");
    scanf("%d", &E->conteudo);

    printf("\n");
    for (p=A; p!=NULL; p=p->prox)
        printf("%d ", p->conteudo);
    printf("\n");

    Item *r;

    p = A;
    q = p->prox;
    for (r=q->prox; r!=NULL; r=r->prox)
    {
        q->prox = p;
        p = q;
        q = r;
    }
    A->prox = NULL;
    q->prox = p;


    for (p=q; p!=NULL; p=p->prox)
        printf("%d ", p->conteudo);
    printf("\n");

    return 0;
}

void remover (Item *p)
{
    Item *lixo;
    lixo = p->prox;
    p->prox = lixo->prox;
    //free (lixo);
}