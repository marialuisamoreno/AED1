#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f1, *f2, *f3;
    char c, d;

    f1 = fopen("ex4-arq1.txt", "r");
    if (f1 == NULL)
        printf("Nao foi possivel abrir\n");

    f2 = fopen("ex4-arq2.txt", "r");
    if (f2 == NULL)
        printf("Nao foi possivel abrir\n");

    f3 = fopen("ex4-arq3.txt", "w");
    if (f3 == NULL)
        printf("Nao foi possivel abrir\n");

    c = fgetc(f2);
    d = fgetc(f1);
    while (!feof(f2))
    {
        fputc(d, f3);
        fputc(c, f3);
        c = fgetc(f2);
        d = fgetc(f1);
    }

    fclose(f1);
    fclose(f2);
    printf("Fim\n");

    return 0;
}