#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vogal (char string []);

int main()
{
    int qnts, count;
    char nome[100];

    printf("Quantos nomes iremos ler?\n");
    scanf("%d", &qnts);
    printf("Por favor digite a seguir os nomes em letras minusculas.\n");

    for (count=0; count<=qnts; count++)
    {
        printf("Digite o nome %d:\n", count); ///O programa nao pega o nome 0.
        gets (nome);                            ///Tive o mesmo problema em LP, mas não lembro como se arruma isso.
        vogal(nome);                                ///Em geral, o programa cumpriu o solicitado :).
    }

    return 0;
}

void vogal (char nome[])
{
    int i, vogais=0, consoantes=0;
    int tam = strlen(nome);

    for (i=0; i<=tam; i++)
    {
        if (nome [i] == 'a' || nome [i] == 'e' ||
            nome [i] == 'i' || nome [i] == 'o' ||
            nome [i] == 'u')
                vogais ++;
        else
            consoantes ++;
    }

    printf("%d vogais e %d consoantes\n\n", vogais, consoantes-1);
}