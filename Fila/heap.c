#include <stdio.h>
#include <stdlib.h>

void insere(int x, int Heap[], int ult);
void remover(int Heap[], int ult) ;

int main ()
{
    int heap[10];
    int i, j, n;

    for (i=0; i<10; i++)
        heap[i] = 0;

    printf("Insira os elementos do heap:\n");

    for (i=0; i<10; i++)
    {
        scanf("%d", &n);
        insere(n, heap, i);
    }

    printf("\nHeap: ");
    for (i=1; i<10; i++)
        printf("%d ", heap[i]);

    printf("\nRemocao:\n");
    for (i=10; i>1; i--)
    {
        printf("\nHeap: ");
        for (j=1; j<i; j++)
            printf("%d ", heap[j]);
        remover(heap, i);
    }

    return 0;
}

void insere(int x, int Heap[], int ult)
{
    ult = ult+1; ///ultimo índice do heapantes da inserção (no ex. ult= 9+1=10)
    int i = ult;

    while((i/2) && (x > Heap[i/2]))
    {
        Heap[i] = Heap[i/2];
        i = i/2;
    }
    Heap[i] = x;
}

void remover(int Heap[], int ult)
{
    int remove = Heap[1];
    int x = Heap[ult];
    ult = ult-1;
    int i = 1;

    while((2*i <= ult) && (x < Heap[2*i] ||x < Heap[2*i+1]))
    {
        if(Heap[2*i] > Heap[2*i+1])
        {
            Heap[i] = Heap[2*i];
            i = 2*i;
        }

        else
        {
            Heap[i] = Heap[2*i+1];
            i=2*i+1;
        }
    }
    Heap[i] = x;
}