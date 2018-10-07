#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_bineco
{
	char info[STR_MAX];
	char tipo; /* 'r' -> resposta, 'p' -> resposta*/
	struct st_bineco *esq, *dir, *pai;
}bineco_t;

int main(void)
{
	return 0;
}

void entrada()
{
	bineco_t info;

	while(fscanf(stream, "%c %s", info.tipo, info.) != EOF)
	{


}



void insere_bineco(bineco_t **raiz, bineco_t *ant, bineco_t info)
{
	bineco_t *pl= *raiz;

	if(!pl)
	{	
		pl= (bineco_t *) malloc(sizeof(bineco_t));
		strcpy(pl->info, info.info);
		pl->tipo=info.tipo;
		pl->esq= NULL;
		pl->dir= NULL;
		pl->pai= ant;
		*raiz= pl;
		return;
	}

	if(pl->tipo == 'r' || pl->dir == ant)
	{
		insere_bineco(&pl->pai, pl, info);
		return;
	}
	if(pl->esq == ant)
	{
		insere_bineco(&pl->dir, pl, info);
		return;
	}
	
	insere_bineco(&pl->esq, pl, info);
	return;
}

/* preOrdem*/ 
void salva_dados(bineco_t *raiz, FILE *stream)
{
	bineco_t *pl= raiz;

	if(!pl)
		return;

	fprintf(stream, "%c %s\n", pl->tipo, pl->info);
	salva_dados(pl->esq, stream);
	salva_dados(pl->dir, stream);
	return;
}

/* posOrdem */
void remove_tree(bineco_t **raiz)
{
	bineco_t *pl= *raiz;

	if(!pl)
		return;

	remove_tree(&pl->esq);
	remove_tree(&pl->dir);
	free(pl);
	return;
}


