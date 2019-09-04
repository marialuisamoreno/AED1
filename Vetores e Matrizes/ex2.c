#include <stdio.h>
#include <stdlib.h>

int* adicionar (int *v, int *size);
void imprimir (int *v, int n);

int main()
{
    int n, m=0, size=0;
    int *v=NULL;

    do
    {
        printf("Digite o numero da opcao que deseja fazer: \n");
        printf("1- Adicionar numeros\n");
        printf("2- Imprimir os numeros\n");
        printf("3- Sair do programa\n");

        scanf("%d", &n);

        switch (n)
        {
            case 1:
                v = adicionar(v, &size);
            break;

            case 2:
                imprimir(v, size);
            break;

            default:
                m=1;
        }
    } while (m==0);

    free(v);
    return 0;
}

int* adicionar (int *v, int *size)
{
    int n, i;
    printf("\nQuantos numeros deseja adicionar?\n");
    scanf("%d", &n);

    v = (int*)realloc(v, (*size + n)*sizeof(int));

    printf("Digite seus numeros:\n");
    for(i=0; i<n ; i++)
    {
        printf("Numero [%d]: ", i+1);
        scanf("%d", &v[*size+i]);
    }
    *size += n;
    return v;
}

void imprimir (int *v, int size)
{
    int i;

    printf("Imprimindo o vetor na tela:\n");
    for (i=0; i<size; i++)
        printf("%d ", v[i]);
    printf("\n\n");
}