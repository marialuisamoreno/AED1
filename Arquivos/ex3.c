#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float p1, p2;
    float t1;
}alunos;
void recolhedados (alunos *a, int n);
void media (alunos *a, int n);

int main()
{
    int n, i;
    FILE *pa;
    char *nome = "ex3.txt";

    printf("Quantos alunos?\n");
    scanf("%d", &n);

    alunos *a = (alunos*) malloc(n * sizeof(alunos));

    recolhedados(a, n);
    media(a, n);

    if((pa=fopen(nome,"w+b"))==NULL)
    {
        puts("Arquivo nao pode ser aberto.\n");
        exit(1);
    }
    for(i=0; i<2; i++)
    {
        if(fwrite(&a[i], sizeof(alunos), 1, pa) != 1)
            puts("Erro na escrita.\n");
    }
    rewind(pa);

    for(i=0; i<2; i++)
    {
        if(fread(&a[i], sizeof(alunos), 1, pa) != 1)
        {
            puts("Erro na escrita.\n");
            if(feof(pa))
                break;
            puts("Erro na leitura.\n");
        }
    }

    return 0;
}

void media (alunos *a, int n)
{
    int i;
    float soma=0.0, med;
    for (i=0; i<n; i++)
    {
        med = ((a[i].p1 + a[i].p2)/2)*0.8 + a[i].t1*0.2;
        printf("Media do aluno %d: %.2f\n", i+1, med);

        if (med>7)
            printf("Aluno aprovado\n\n");
        else
            printf("Aluno reprovado\n\n");
        med = 0.0;
    }
}
void recolhedados (alunos *a, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("Digite os dados do Aluno [%d]:\n", i+1);

        printf("Nome: ");
        fflush(stdin);
        fgets(a[i].nome, sizeof(a[i].nome), stdin);

        printf("Nota da P1: ");
        scanf("%f", &a[i].p1);

        printf("Nota da P2: ");
        scanf("%f", &a[i].p2);

        printf("Nota do T1: ");
        scanf("%f", &a[i].t1);

        printf("\n\n");
    }
}