#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore
{
    int x;
    char pr[MAX];
    struct arvore *esq;
    struct arvore *dir;
    struct arvore *pai;
}arv;

arv *criar()
{
    return NULL;

}

arv imprimir(arv *t)
{
    printf("%d", t->x);
    imprimir(t->esq);
    imprimir(t->dir);
}


void inserir(arv **t, arv *ant, arv info)
{
    arv *p= *t;

    if(p== NULL)
    {
        p= (arv*)malloc(sizeof(arv));
        p->esq=NULL;
        p->dir=NULL;
        p->x=info.x;
        p->pai= ant;
        strcpy(p->pr, info.pr);
        *t= p;
        return;
    }

    if(p->x==1 || p->dir == ant)
    {
        inserir(&p->pai, p, info);
        return;
    }

    if(p->esq== ant)
    {
        inserir(&p->dir, p, info);
        return;
    }

    inserir(&p->esq, p, info);
    return;
}

int main()
{



    return 0;
}
