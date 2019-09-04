#include <stdio.h>
#include <stdlib.h>

void nula (int matriz [][], int *linhas, int *colunas, int m, int n);

int main()
{
    int i, j, m, n, linhanull=0, colunanull=0, matriz[100][100];
    int *linhas, *colunas;

    linhas = &linhanull;
    colunas = &colunanull;

    printf("Digite o numero de colunas:\n");
    scanf("%d", &m);
    printf("Digite o numero de linhas:\n");
    scanf("%d", &n);

    for(i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
            scanf("%d", &matriz[i][j]);
    }
    nula (matriz, linhas, colunas, m, n);

    printf("A matriz possui %d linhas e %d colunas nulas.\n\n", linhanull, colunanull);
    return 0;
}

void nula (int matriz [100][100], int *linhas, int *colunas, int m, int n)
{
    int i, j, countlinhas=0, countcolunas=0;
    for (i=0; i<m; i++)
    {
        int z=0;
        for (j=0; j<n; j++)
        {
            if (matriz[i][j] == 0)
                z++;
        }
        if (z==m)
            countlinhas++;
    }
    for (j=0; j<m; j++)
    {
        int z=0;
        for (i=0; i<n; i++)
        {
            if (matriz[i][j] == 0)
                z++;
        }
        if (z==n)
            countcolunas++;
    }
    *linhas = countlinhas;
    *colunas = countcolunas;
}