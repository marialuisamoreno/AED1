#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int n, i, soma=0, count=1;
    float media;
    int *v=NULL;

    fp = fopen("ex2.txt","r");

    while(fscanf(fp,"%d",&n) != EOF)
    {
        if(v==NULL)
        {
            v = malloc(sizeof(n));
            *v = n;
        }
        else
        {
            count++;
            v = realloc(v,sizeof(v)*count);
            i = count -1;
            *(v+i) = n;
        }

    }

    n = 0;
    while(i>=0)
    {
        soma = soma + (*(v+n));
        i--;
        n++;
    }
    media = ((float)soma) / ((float)count);
    printf("Media: %.2f", media);
    fclose(fp);
    free(v);
    v = NULL;

    return 0;
}