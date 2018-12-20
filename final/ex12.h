
/***************************************************************************
 *   afd to er                                Version 20171128.121000      *
 *                                                                         *
 *   Library for efd2er, a program that convert AFD into Exp Reg           *
 *   Copyright (C) 2016-2017    by Ruben Carlo Benante                     *
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
#define VERSION "20171128.121000" /**< Version Number */
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
    unsigned short int ei;
    char *lei;
    unsigned short int ef;
    struct st_translist *prox;
} ltrans_t; 

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    int K;                  /* conjunto de estados */
    char A;                 /* alfabeto */
    int S;                  /* estado inicial */
    lest_t *F;               /* lista de estados finais */
    ltrans_t *D;               /* lista da funcao de transicao d(ei, le, ef) */
} quintupla_t;

/* ---------------------------------------------------------------------- */
/* prototypes */

void apaga_transicao(ltrans_t **list);
void apaga_estados(lest_t **list);
void remove_transicao(ltrans_t **list, ltrans_t *r);
void remove_estado(lest_t **list, lest_t *r);
void insere_transicao(ltrans_t **list, int ei, char *lei, int ef);
void insere_estado(lest_t **list, int est);
void imprime_transicao(ltrans_t *list, FILE *stream);
void imprime_estados(lest_t *list, FILE *stream);
void salva_quintupla(quintupla_t Q, char *arquivo);
int estado_eliminar(quintupla_t Q);
void concatena_aux(char **dest, char *ch, char *ch2);
void concatena(ltrans_t **list, int est);
int busca_semelhantes(ltrans_t *list, ltrans_t **pl, ltrans_t **pl2);
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei);
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef);
char *estrela(ltrans_t **list, int ei_ef);
ltrans_t *busca_por_ei(ltrans_t *list, int est);
ltrans_t *busca_por_ef(ltrans_t *list, int est);
void uniao(ltrans_t **list);
int lista_unitaria(ltrans_t *list);
void estados_limite(quintupla_t *Q);
void coleta_transicao(ltrans_t **list, FILE *stream);
void coleta_final(lest_t **list, FILE *stream);
void entrada_dados(quintupla_t *Q, const char *entrada);
int definir_tamanho(char *ch, char *ch2);

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void ex12_init(const char *arquivo);
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */

