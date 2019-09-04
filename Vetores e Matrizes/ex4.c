#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char cpf[10];
    char endereco [200];
    char nascimento[100];
    float salario;
} empresas;

void recolhedados (empresas *e, int n);
void imprimir (empresas *e, int n);

int main()
{
    int n, i;

    printf("Quantos cadastros deseja fazer?\n");
    scanf("%d", &n);
    empresas *e = (empresas*)malloc(n*sizeof(empresas));
    recolhedados(e, n);
    printf("Dados armazenados:\n");
    imprimir(e, n);

    printf("Funcionarios que recebem mais que R$1000,00:\n");
    for (i=0; i<n; i++)
        if (e[i].salario>1000.00)
            printf("Funcionario [%d]: %s\n", i+1, e[i].nome);

    return 0;
}

void imprimir (empresas *e, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("Imformacoes do funcionario [%d]:\n", i+1);
        printf("Nome: %s", e[i].nome);
        printf("CPF: %s", e[i].cpf);
        printf("Endereco: %s", e[i].endereco);
        printf("Data de Nascimento: %s", e[i].nascimento);
        printf("Salario: %.2f", e[i].salario);
        printf("\n\n");
    }
}
void recolhedados (empresas *e, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("Digite os dados do funcionario [%d]:\n", i+1);
        printf("Nome: ");
        fflush(stdin);
        fgets(e[i].nome, sizeof(e[i].nome), stdin);

        printf("CPF: ");
        fflush(stdin);
        fgets(e[i].cpf, sizeof(e[i].cpf), stdin);

        printf("Endereco: ");
        fflush(stdin);
        fgets(e[i].endereco, sizeof(e[i].endereco), stdin);

        printf("Data de Nascimento: ");
        fflush(stdin);
        fgets(e[i].nascimento, sizeof(e[i].nascimento), stdin);

        printf("Salario: ");
        scanf("%f", &e[i].salario);

        printf("\n\n");
    }
}