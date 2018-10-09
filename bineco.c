#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRMAX 100

typedef struct st_bineco
{
	char info[STRMAX];
	char tipo; /* 'r' -> resposta, 'p' -> resposta*/
	struct st_bineco *esq, *dir, *pai;
}bineco_t;

void entrada(char nome[STRMAX], bineco_t **raiz);
void insere_bineco(bineco_t **raiz, bineco_t *ant, bineco_t info);
void remove_tree(bineco_t **raiz);
void reconstrucao(bineco_t **raiz, bineco_t *nodo);
void jogar_bineco(bineco_t **raiz);
void primeira(bineco_t **raiz);
void salva_dados(bineco_t *raiz, FILE *stream);
void imprime_tree(bineco_t *raiz);

int main(void)
{
	char nome_arquivo[STRMAX]= "banco.txt";
	FILE *stream;
	bineco_t *ini= NULL;

	entrada(nome_arquivo, &ini);
	imprime_tree(ini);
	if(!ini)
		primeira(&ini);
	else
		jogar_bineco(&ini);

	salva_dados(ini, stream= fopen(nome_arquivo, "w"));
	fclose(stream);
	remove_tree(&ini);

	return 0;
}

void primeira(bineco_t **raiz)
{
	bineco_t p;
	printf("Pense em um animal\n ");
	getchar();	
	printf("Errei, qual era o animal ?");
	fgets(p.info, STRMAX, stdin);
	p.tipo= 'r';
	printf("Nao vou errar na proxima!\n");
	insere_bineco(raiz, NULL, p);
	return ;
}

	

void jogar_bineco(bineco_t **raiz)
{
	char cond;
	bineco_t  *s= *raiz;
	printf("Pense em um animal\n ");
	getchar();

	while(1)
	{
		if(s->tipo == 'p')
		{
			printf("%s? (s/n)\n", s->info);
			fscanf(stdin, "%c", &cond);
			if(cond == 's')
				s= s->dir;
			else if(cond == 'n')
				s= s->esq;
		}
		else if(s->tipo == 'r')
		{
			printf("O seu animal eh %s? (s/n)\n", s->info);
			fscanf(stdin, "%c", &cond);
			if(cond == 's')
			{
				printf(" Acertei! otario\n");
			}
			else
			{
				reconstrucao(raiz, s);
				printf("na proxima nao vou errar!\n");
			}
			break;
		}
	}
	return ;
} 

void reconstrucao(bineco_t **raiz, bineco_t *nodo)
{
	bineco_t perg, resp2, resp1;
	char cond;

	resp1.tipo= nodo->tipo;
	strcpy(resp1.info, nodo->info);

	printf("Qual animal voce pensou?\n");
	resp2.tipo= 'r';
	fgets(resp2.info, STRMAX, stdin);

	printf("O que diferencia %s de %s?\n", nodo->info, resp2.info);
	perg.tipo= 'p';
	fgets(perg.info, STRMAX, stdin);

	printf("%s eh S para %s?", perg.info, nodo->info);
	fscanf(stdin, " %c ", &cond);

	free(nodo);
	insere_bineco(raiz, NULL, perg);
	if(cond == 'S')
	{
		insere_bineco(raiz, NULL, resp2);
		insere_bineco(raiz, NULL, resp1);
	}
	else
	{
		insere_bineco(raiz, NULL, resp1);
		insere_bineco(raiz, NULL, resp2);
	}
	return;
}

void entrada(char nome[STRMAX], bineco_t **raiz)
{
	bineco_t info;

	FILE *stream= fopen(nome, "r");
	if(!stream)
	{
		printf("erro na aberto do arquivo, não existe");
		stream= fopen(nome, "w");
		//return;
	}

	while(fscanf(stream, "%c %s", &info.tipo, info.info) != EOF)
	{
		printf("arquivo vazio");
		insere_bineco(raiz, NULL, info);
	}
	fclose(stream);
	return;
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

void imprime_tree(bineco_t *raiz)
{
	salva_dados(raiz, stdout);
	return;
}

