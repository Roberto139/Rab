/***************************************************************************
 *   exN.h                                 Version 20160609.110111       *
 *                                                                         *
 *   Library for exN, a program that converts ER into AFND               *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION
#define VERSION "20160609.110111" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb=0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_estlist
{
    int estado;
    struct st_estlist *prox;
} lest_t;

/* tipo lista encadeada simples da funcao de transicao */
typedef struct st_translist
{
    int ei;  /* estado inicial */
    char lei;         /* lei (string com rotulos) */
    int ef;  /* estado final */
    struct st_translist *prox;
} ltrans_t;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    int K;   /* conjunto de estados */
    char A;                 /* alfabeto */
    int S;   /* estado inicial */
    lest_t *F;               /* lista de estados finais */
    ltrans_t *D;               /* lista da funcao de transicao d(ei, le, ef) */
}quintupla_t;

typedef struct st_arvore
{
    char *expReg;
    int tipo_op; /*tipo de operador, 0->nao operador, 1 ->operador unario, 2->operador binario*/
    quintupla_t Q;
    struct st_arvore *esq, *dir, *pai;
}t_arvore;
/* Variaveis Global*/

int id_estado= 0;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void ex16_init(char *expReg); /* global initialization function */
void quebraExpressao(char *expReg, t_arvore **raiz);
void separador(char *expReg, char **partEsc, char **partDir, char *op, int size);
void imprime_arvore(t_arvore *raiz, FILE *stream);
void insere_arvore(t_arvore **raiz, t_arvore *ant, char *info);
int tipo_operador(char info);
void entrada_dados(char *expReg, char *entrada);
/*------------nao testados --------------------*/

void transformacao(t_arvore *raiz);
void insere_estado(lest_t **list, int est);
void insere_transicao(ltrans_t **list, int ei, char lei, int ef);
void mini_quintupla(quintupla_t *q, char lei);
void copia_ltrans(ltrans_t **dest, ltrans_t *list);
void copia_lestado(lest_t **dest, lest_t *list);
void transicoes_finais(ltrans_t **dest, lest_t *list, int novoFinal);
void operacao_estrela(quintupla_t *res, quintupla_t q);
void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2);
void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2);
void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op);


void imprime_transicao(ltrans_t *list, FILE *stream);
void imprime_estados(lest_t *list, FILE *stream);
void salva_quintupla(quintupla_t Q, char *arquivo);




