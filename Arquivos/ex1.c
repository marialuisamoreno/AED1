#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    char *nome = "ex1.txt";
    int c, tam=0;

    if((arq = fopen(nome,"w+")) == NULL)
        printf("Não eh possivel abrir o arquivo\n");

    else
    {
        c = getchar();
        while(c!='0')
        {
            fputc(c,arq);
            c = getchar();
            tam ++;
        }
        rewind(arq);
        printf("Escrita finalizada!\n");
        printf("Qtd de caracteres: %d\n", tam-1);
        printf("Texto digitado:\n");

        c = fgetc(arq);
        while(!feof(arq))
        {
            putchar(c);
            c = fgetc(arq);
        }
        fclose(arq);
        getchar();
    }
    return 0;
}