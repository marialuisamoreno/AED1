#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **A, **B, **C;
    int linhasA, linhasB, colunasA, colunasB;
    int i, j;

    printf("Qual o numero de linhas da matriz A?\n");
    scanf("%d", &linhasA);
    printf("E colunas?\n");
    scanf("%d", &colunasA);

    printf("\nQual o numero de linhas da matriz B?\n");
    scanf("%d", &linhasB);
    printf("E colunas?\n");
    scanf("%d", &colunasB);

    if (linhasA==linhasB && colunasA==colunasB)
    {
        ///alocando a matriz A
        A = (int**) calloc(linhasA, sizeof(int*));
        for (i=0; i<linhasA; i++ )
            A[i] = (int*)calloc(colunasA, sizeof(int));

        ///alocando a matriz B
        B = (int**) calloc(linhasB, sizeof(int*));
        for (i=0; i<linhasB; i++ )
            B[i] = (int*)calloc(colunasB, sizeof(int));

        ///alocando a matriz C
        C = (int**) calloc(linhasB, sizeof(int*));
        for (i=0; i<linhasB; i++ )
            C[i] = (int*)calloc(colunasB, sizeof(int));

        ///pegando valores de A
        printf("Digite os valores de A:\n");
        for (i=0; i<linhasA; i++)
            for (j=0; j<colunasA; j++)
                scanf("%d", &A[i][j]);

        ///pegando valores de B
        printf("Digite os valores de B:\n");
        for (i=0; i<linhasB; i++)
            for (j=0; j<colunasB; j++)
                scanf("%d", &B[i][j]);

        ///somando
        for (i=0; i<linhasA; i++)
            for (j=0; j<colunasA; j++)
                C[i][j] = A[i][j] + B[i][j];

        printf("Matriz A+B:\n");
        for (i=0; i<linhasA; i++)
        {
            for (j=0; j<colunasA; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
    }

    else
        printf("Nao e possivel somar as matrizes.\n\n");

    return 0;
}