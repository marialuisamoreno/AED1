#include <stdio.h>
#include <stdlib.h>

/**  O algoritmo Bubblesort é um algoritmo de complexidade quadrática.
         Seu tempo de execução é da ordem de n^2.                       **/

int main()
{
    int *v;
    int n, i, j, aux;

    printf("Quantos numeros?\n");
    scanf("%d", &n); ///pega do teclado o numero de elementos do vetor

    v = (int*)malloc(n*sizeof(int)); ///aloca a qtd de numeros que o usuario quer

    printf("Digite os numeros:\n");
    for (i=0; i<n; i++)
        scanf("%d", &v[i]);

    for (i=0; i<(n-1); i++) ///Bubblesort
        for (j=i+1; j<n; j++)
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    for (i=0; i<n; i++) ///Imprime na tela o vetor ordenado
        printf("%d\n", v[i]);

    return 0;
}