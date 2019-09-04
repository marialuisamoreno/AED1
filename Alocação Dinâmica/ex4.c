#include <stdio.h>
#include <stdlib.h>

void primo (int n, int v[]);

int main()
{
    int n, i, v[100];

    for (i=0; i<100; i++)
        v[i] = 0;

    printf("Digite um número:\n");
    scanf("%d", &n);
    primo(n, v);
    for (i=0; i<=n; i++)
    {
        if(v[i] == 0)
            break;
        else
            printf("%d\n", v[i]);
    }

    return 0;
}

void primo (int n, int v[])
{
    int i, j, div=0, h=0;

    for (j=1; j<=n; j++)
    {
       for (i=1; i<=j; i++)
        {
            if (j%i == 0)
                div++;
        }
        if (div == 2)
        {
            v[h] = j;
            h++;
        }
        div=0;
    }
}