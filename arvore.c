#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct arvore{
    int pr;
    char info[MAX];
    struct arvore *esq;
    struct arvore *dir;
} arv;
arv primeira();
void  segunda();
int main()
{
    arv p;
    p=primeira();
    segunda(p);
return 0;
}

arv primeira()
{
    arv p;
    printf("Pense em um animal ! Irei adivinhar\n");
    printf("(poxa, nao sei D: Qual era o animal?\n");
    fgets(p.info,100,stdin );
    p.pr = 1;
    
    printf("sempre soube haha\n");
    
    return p;
}


void segunda(arv p)
{
    arv s,pp;
    char conf;
    int /*len,*/i;
    printf("Pense em um animal ! Irei adivinhar\n");
    //len=strlen(p.info);
    
    for(i=0;p.info[i]!='\0';i++)
    {
        if(p.info[i]=='\n')
        {
            p.info[i]='\0';
        }

    }
    printf("Seu animal eh %s?\n s/n ?\n",p.info);
    scanf("%c",&conf);
    if(conf=='s')
    {

        printf("Acertei!\n");
    }
    else
    {
        printf("Poxa :< qual era o animal?\n");
        fgets(s.info,100,stdin);
        s.pr= 1;
        printf("Uma pergunta que diferencia um %s de um %s",s.info, p.info);
        fgets(pp.info,100,stdin);
        pp.pr=0;
    }
}
