#include <stdio.h>
#include <stdlib.h>

typedef struct Lista Lista;

typedef struct Vertice
{
    int dado;
    Lista *lista_adj;
    struct Vertice *prox;
}Vertice;

struct Lista
{
    Vertice *inicio;
    Vertice *fim;
    int qtd;
};

typedef struct
{
    Vertice **v;
    int qtd;
}Grafo;

void inicializa_grafo (Grafo *grafo, int V);
void inicializa_lista (Lista *lista);

void inserir_vertice (Grafo *grafo);

int main ()
{
    int v, i;
    Grafo grafo;
    printf("Numero de vertices: ");
    scanf("%d", &v);
    inicializa_grafo(&grafo, v);

    for (i=0; i<v; i++)
    {
        inserir_vertice(&grafo);
    }

    return 0;
}

void inicializa_grafo (Grafo *grafo, int V) ///ok
{
    grafo->v = (Vertice**)malloc(V*sizeof(Vertice*));
    grafo->qtd = 0;
}

void inserir_vertice (Grafo *grafo)
{
    int dado;
    Vertice *novo;

    novo = (Vertice*)malloc(sizeof(Vertice));
    novo->lista_adj = (Lista*)malloc(sizeof(Lista));
    inicializa_lista(novo->lista_adj);

    printf("\nDado: ");
    scanf("%d", &dado);
    novo->dado = dado;
    novo->prox = NULL;

    grafo->v[grafo->qtd] = novo;
    grafo->qtd++;
}

void inicializa_lista (Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}