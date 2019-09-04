#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bemFormada (char s[]);

int main()
{
    int resp;
    char N[1000];
    scanf("%s", &N);
    resp = bemFormada(N);

    if (resp == 0) printf("incorrect\n");
    else printf("correct\n");

    return 0;
}

int bemFormada (char s[])
{
    char *pilha;
    int t;
    int n, i;

    n = strlen (s);
    pilha = malloc (n * sizeof (char));
    t = 0;
    for (i = 0; s[i] != '\0'; ++i)
    {
      // a pilha está armazenada em pilha[0..t-1]
        switch (s[i])
        {
            case ')':
                if (t != 0 && pilha[t-1] == '(')
                    --t;
                else return 0;
            break;

            case ']':
                if (t != 0 && pilha[t-1] == '[')
                    --t;
                else return 0;
            break;

            default:  pilha[t++] = s[i];
        }
   }
    free (pilha);
    if (t == 0) return 1;
    else return 0;
}


#include <stdio.h>

int main(){
    char linha[1001];
    int i,esq, dir;
    while(scanf("%s",&linha) != EOF){
       esq = 0;
       dir = 0;
       for(i = 0; linha[i] != '\0'; i++){
             if(linha[i] == '(') esq++;
             else if (linha[i] == ')'){
                  dir++;
                  if(esq > 0){
                         esq--;
                         dir--;
                  }
             }
       }
       if(esq == 0 && dir == 0) printf("correct\n");
       else printf("incorrect\n");
    }
    return 0;
}