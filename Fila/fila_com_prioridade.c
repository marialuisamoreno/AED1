#include <stdio.h>
#include <stdlib.h>

typedef struct Titem
{
    int conteudo;
    struct Titem *prox;
    int prioridade;
}Titem;

typedef struct Fila
{
    Titem *inicio;
    Titem *fim;
    int tamanho;
}Fila;

void inserir_fim(Fila *f, int d, int p);
void inserir_inicio (Fila *f, int d, int p);
void inicializar(Fila *f);
void imprime(Fila *f);
void remover(Fila *f);

int main ()
{
    int m=1, aux=0, p;
    Fila cont;
    inicializar(&cont);

    printf("Fila com prioridade\n");
    printf("Digite 0 para sair\n\n");

    while (m!=0)
    {
        scanf("%d", &m);
        if (m != 0)
        {
            printf("P: ");
            scanf("%d", &p);
            printf("\n");

            if (p > aux)
                inserir_inicio(&cont, m, p);
            else if (p < aux)
                inserir_fim(&cont, m, p);
            else
                inserir_fim(&cont, m, p);

            aux = p;
        }
    }

    printf("Elementos inseridos: ");
    imprime(&cont);

    return 0;
}

void inicializar (Fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void inserir_fim (Fila *f, int d, int p)
{
    Titem *novo = malloc(sizeof(Titem));

    f->tamanho++;
    novo->prox = NULL;
    novo->conteudo = d;
    novo->prioridade = p;

    if(f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }

    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void inserir_inicio (Fila *f, int d, int p)
{
    Titem *novo = malloc(sizeof(Titem));

    f->tamanho++;
    novo->conteudo = d;
    novo->prioridade = p;

    if(f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }

    else
    {
        novo->prox = f->inicio;
        f->inicio = novo;
    }
}

void imprime (Fila *f)
{
    Titem *percorre;
    percorre = f->inicio;

    while(percorre != NULL)
    {
        printf("%d ", percorre->conteudo);
        percorre = percorre->prox;
    }
}