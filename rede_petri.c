#include <stdio.h>
#include <stdlib.h>

typedef struct st_arco
{
	int orig;
	int peso;
	int dest;

	struct st_arco *prox;
}arco_t;

typedef struct st_lugar
{
	int tokens;
	int id;
	struct st_lugar *prox;
}lugar_t;

typedef struct st_dados
{
	int nTrans;
	int nLugar;
	lugar_t *lugares;
	arco_t *consumidor;
	arco_t *produtor;
}dados_t;

int main(void)
{
	return 0;
}

void rede_petri(void)
{
	dados_t dados;
	entrada(&dados);

	for(i=0; i< INTERACOES; i++)
	{
		t = sorteio(nTrans);
		if(habilitada(t)) /* return 0 -> nao esta habilitada, se 1 -> habilitada*/
		{
			/* Acao de disparar */
			consumir(dados.lugares, dados.consumidor, t);
			produzir(dados.lugares, dados.produtor, t);
			/* ---------------- */
		}
	}
	return;
}

void entrada(dados_t *dados)
{
	return;
}

int habilitada(dados_t dados, int t)
{
	lugar_t *plug;
	arco_t *pcons= dados.consumidor;

	while((pcons= busca_arcoC(pcons, t)) != NULL)
	{
		plug= busca_lugar(dados.lugares, pcons->orig);
		if(plug->tokens < pcons->peso)
			return 0; /*nao habilitada*/
		pcons= pcons->prox;
	}

	return 1; /* habilitada */
}

void consumir(lugar_t *lugares, arco_t *consumidor, int trans)
{
	arco_t *pcons= consumidor;
	lugar_t *plug;

	while((pcons= busca_arcoC(pcons, trans)) != NULL)
	{
		plug= busca_lugar(lugares, pcons->orig);
		plug->tokens-= pcons->peso;
		pcons= pcons->prox;
	}
	return;
}

void produzir()
{
	/* semelhante ao consumir*/
	return;
}

/* busca para arco Consumidor*/
arco_t *busca_arcoC(arco_t *list, int trans)
{
	arco_t *pl= list;

	while(pl!= NULL)
	{
		if(pl->dest == trans)
			return pl;
		pl= pl->prox;
	}

	return NULL;
}

/*busca para arco Produtores */
arco_t *busca_arcoP(arco_t *list, int trans)
{
	/* semelhante a busca_arcoC*/
	return;
}

lugar_t *busca_lugar(lugar_t *list, int lugar)
{
	int cont=0;
	lugar_t *pl = list;

	while(pl!= NULL)
	{
		if(cont == lugar)
			return pl;

		cont++;
		pl= pl->prox;
	}
	return NULL;
}







