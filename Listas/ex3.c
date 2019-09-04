#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg celula;

struct reg
{
   char string1[100];
   char string2[100];
   char string3[100];
   celula *prox;
};

int main ()
{
    int i, count=0;
    celula *A, *B;

    A = malloc (sizeof (celula));
    B = malloc (sizeof (celula));
    A->prox = B;
    B->prox = NULL;

    printf("Lista A:\n");
    printf("String 1: ");
    gets(A->string1);
    printf("String 2: ");
    gets(A->string2);
    printf("String 3: ");
    gets(A->string3);

    printf("Lista B:\n");
    printf("String 1: ");
    gets(B->string1);
    printf("String 2: ");
    gets(B->string2);
    printf("String 3: ");
    gets(B->string3);

    strcat(A->string1, B->string1);
    strcat(A->string2, B->string2);
    strcat(A->string3, B->string3);

    printf("String 1: %s\n", A->string1);
    printf("String 2: %s\n", A->string2);
    printf("String 3: %s\n", A->string3);

    return 0;
}