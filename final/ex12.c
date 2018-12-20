/***************************************************************************
 *   exN.c                                 Version 20171128.121000      *
 *                                                                         *
 *   Convert AFD into Exp Reg                                              *
 *   Copyright (C) 2016-2017    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
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
/**
 * @file exN.c
 * @ingroup GroupUnique
 * @brief Convert AFD into Exp Reg
 * @details This program really do a nice job as a template, and template only!
 * @version 20160520.000202
 * @date 2017-11-28
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc exN.c -o exN.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include "ex12.h" /* library with definitions */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <assert.h> */ /* Verify assumptions with assert */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./exN -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
int main(int argc, char *argv[])
{
  int opt; /* return from getopt() */

  IFDEBUG("Starting optarg loop...\n");

  /* getopt() configured options:i
   *        -h  help
   *        -c  copyrithg and version notes
   *        -v  verbose
   */
  opterr = 0;
  while((opt = getopt(argc, argv, "vhfc")) != EOF)
    switch(opt)
    {
      case 'h':
        help();
        break;
      case 'c':
        copyr();
        break;
      case 'f':
        ex12_init(argv[2]);
        break;
      case 'v':
        verb++;
        break;
      case '?':
      default:
        printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

  if(verb)
    printf("Verbose level set at: %d\n", verb);
  /* ...and we are done */
  return EXIT_SUCCESS;
}

/* ------------------------------------------------------*/
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void ex12_init(const char *arquivo)
{
  IFDEBUG("ex12_init()");

  int estado;
  quintupla_t Q;

  entrada_dados(&Q, arquivo);

  estados_limite(&Q);

  while(!lista_unitaria(Q.D))
  {
    uniao(&Q.D);

    estado= estado_eliminar(Q);

    concatena(&Q.D, estado);
  }
  fprintf(stdout, "Expressao Regular: %s\n", Q.D->lei);
  return;
}

/** 
 * @brief finalidade de coletar as entradas do arquivo (quintupla (AFND))
 * @param [out] Q armazena o quintupla adquirida do arquivo
 * @param [in] entrada nome do arquivo
 */
void entrada_dados(quintupla_t *Q, const char *entrada)
{
  FILE *pf= fopen(entrada, "r");
  char ch[SBUFF];

  fgets(ch, SBUFF, pf); /* #K*/
  fgets(ch, SBUFF, pf); /* #K*/
  Q->K= atoi(ch);

  fgets(ch, SBUFF, pf); /* #A*/
  fgets(ch, SBUFF, pf); /* #A*/
  Q->A= *ch;

  fgets(ch, SBUFF, pf); /* #S*/
  fgets(ch, SBUFF, pf); /* #S*/
  Q->S= atoi(ch);

  fgets(ch, SBUFF, pf); /* #F*/
  Q->F= NULL;
  coleta_final(&Q->F, pf);

  fgets(ch, SBUFF, pf); /* #D*/
  Q->D= NULL;
  coleta_transicao(&Q->D, pf);

  fclose(pf);

  return;
}

/** 
 * @brief coleta o estados finais do arquivo, auxilia a funcao entrada_dados()
 * @param [out] list armazena o estados finais
 * @param [in] stream referencia do arquivo
 * @return
 */
void coleta_final(lest_t **list, FILE *stream)
{
  char ch[SBUFF], *sch;

  fgets(ch, SBUFF, stream);
  sch= strtok(ch, " ");

  do
  {
    insere_estado(list, atoi(sch));
  }while((sch= strtok(NULL, " ")) != NULL);
}

/** 
 * @brief coleta as transicoes do arquivo, auxiliar a funcao entrada_dados()
 * @param [out] list armazena as transicoes
 * @param [in] stream referencia do arquivo
 * @return
 */

void coleta_transicao(ltrans_t **list, FILE *stream)
{
  char ch[SBUFF], *sei, *slei, *sef;

  while(fgets(ch, SBUFF, stream)!= NULL)
  {
    sei= strtok(ch, " ");
    slei= strtok(NULL, " ");
    sef= strtok(NULL, " ");
    insere_transicao(list, atoi(sei), slei, atoi(sef));
  }
}

/**
 * @brief limita a quintupla para apenas uma unica entrada e uma unica saida da AFD
 * @param [in, out] Q quintupla AFD
 */
void estados_limite(quintupla_t *Q)
{
  lest_t *pl= Q->F;
  insere_transicao(&Q->D, Q->K, "E", Q->S);

  while(pl!= NULL)
  {
    insere_transicao(&Q->D, pl->estado, "E", Q->K+1);
    pl= pl->prox;
  }
  return;
}

/**
 * @brief verifica se a lista das transicoes possui apenas um elemento
 * @param [in] list lista de transicoes
 * @return verdadeiro ou falso caso a lista seja unitaria
 */
int lista_unitaria(ltrans_t *list)
{
  if(!list)
    return 0;
  return list->prox == NULL ? 1 : 0;
}

/**
 * @brief procura por transicoes semelhantes do tipo transicao 1 e 2 (ei1 == ei2, lei1 != ou == lei2, ef1 == ef2), e faz a uniao das leis separando as pelo operador |
 * @param [in, out] list lista das transicoes
 */
void uniao(ltrans_t **list)
{
  ltrans_t *pl, *pl2, res/* variavel que vai unificar as transicoes semelhantes*/;

  while(busca_semelhantes(*list, &pl, &pl2)) /* procurando por transicoes semelhantes, retorna 0 se nada for encontrado, e 1 se encontrado*/
  {
    res.ei= pl->ei;
    res.ef= pl->ef;
    res.lei= malloc(definir_tamanho(pl->lei, pl2->lei) * sizeof(char)); /* definindo o tamanho da string que vai unir as leis*/

    /* processo de atribuicao da uniao das leis em um string*/
    if(strcmp(pl->lei, "E") != 0)
    {
      strcpy(res.lei, pl->lei);
      if(strcmp(pl2->lei, "E") != 0)
      {
        strcat(res.lei, "|");
        strcat(res.lei, pl2->lei);
      }
    }
    else
    {
      if(strcmp(pl2->lei, "E") != 0)
        strcpy(res.lei, pl2->lei);
      else
        strcpy(res.lei, "E");
    }
    /* ------------- */

    remove_transicao(list, pl);
    remove_transicao(list, pl2);
    insere_transicao(list, res.ei, res.lei, res.ef);
    free(res.lei);
  }
  return;
}

/**
 * @brief Procura pelo estado com menos interacoes, e ignora os estado limites
 * @param [in] Q quintupla
 * @return estado
 */
int estado_eliminar(quintupla_t Q)
{
  int vetor[Q.K], i, menor /* indice do vetor com menor valor*/;
  ltrans_t *pl= Q.D;

  for(i=0; i<Q.K; i++) vetor[i]= 0;

  while(pl!= NULL)
  {
    if(pl->ei < Q.K)
      vetor[pl->ei]+= 1;

    if(pl->ef < Q.K)
      vetor[pl->ef]+= 1;

    pl= pl->prox;
  }

  menor= 0; /* indice do vetor inicial*/
  for(i=1; i<Q.K; i++)
  {
    if(vetor[menor] == 0)
      menor = i;
    else if(vetor[menor] > vetor[i] && vetor[i] != 0)
      menor= i;
  }
  return menor;
}

/**
 * @brief faz a concatenacao de duas leis dado o estado que sera eliminado nessa juncao, Se apropria da funcao concatena_aux para atribuir as leis em uma unica string
 * @param [in] list lista de transicoes
 * @param [in] est estado a ser eliminado, referencia para de concatencao
 */
void concatena(ltrans_t **list, int est)
{
  ltrans_t *pl= *list, *pl2, *plr, *pl2r, res;
  char *chstar, *aux;

  chstar= estrela(list, est); /* verifica se o estado selecionado possui a estrela*/

  while((pl= busca_por_ef(pl, est)) != NULL) /* procurando por transicoes que terminam com o estado de referencia (est)*/
  {
    pl2= *list;
    while((pl2= busca_por_ei(pl2, est))!= NULL) /* procurando por transicoes que inicia com o 'est'*/
    {
      /* Processo de concatenacao*/
      res.ei= pl->ei;

      if(chstar!= NULL)
      {
        concatena_aux(&aux, pl->lei, chstar);
        concatena_aux(&res.lei, aux, pl2->lei);
      }
      else
        concatena_aux(&res.lei, pl->lei, pl2->lei);

      res.ef= pl2->ef;

      insere_transicao(list, res.ei, res.lei, res.ef);
      /* ---------------------------------- */

      pl2r= pl2;
      pl2= pl2->prox;
      remove_transicao(list, pl2r);
    }
    plr= pl;
    pl= pl->prox;
    remove_transicao(list, plr);
  }
  return;
}

/**
 * @brief Funcao que contatena (atribui) duas leis numa string
 * @param [out] lei concatenada
 * @param [in] ch lei 1
 * @param [in] ch2 lei 2
 */
void concatena_aux(char **dest, char *ch, char *ch2)
{
  *dest= malloc(definir_tamanho(ch, ch2) * sizeof(char));

  if(strcmp(ch, "E") != 0)
  {
    if(strlen(ch)> 1 && strcmp(ch2, "E") != 0)
    {
      strcpy(*dest, "(");
      strcat(*dest, ch);
      strcat(*dest, ")");
    }
    else
      strcpy(*dest, ch);
  }

  if(strcmp(ch2, "E") != 0)
  {
    if(strcmp(ch, "E") != 0)
    {
      strcat(*dest, ".");
      if(strlen(ch2)> 1)
      {
        strcat(*dest, "(");
        strcat(*dest, ch2);
        strcat(*dest, ")");
      }
      else
        strcat(*dest, ch2);
    }
    else
      strcpy(*dest, ch2);
  }

  if(strcmp(ch, "E") == 0 && strcmp(ch2, "E") == 0)
    strcpy(*dest, "E");

  return;
}

/**
 * @brief verfica se o estado dado possui a estrela, se caso sim, retorna a lei, se nao returna NULL
 * @param [in] list lista de transicoes
 * @param [in] ei_ef estado de referencia
 * @return lei com estrela(*), ou NULL
 */
char *estrela(ltrans_t **list, int ei_ef)
{
  int tamanho= 0;
  char *chstar;
  ltrans_t *plstar;

  if((plstar= busca_transicao_lei(*list, ei_ef, ei_ef)) == NULL)
    return NULL;

  if((tamanho= strlen(plstar->lei)) > 1)
    tamanho+= 2;

  chstar= malloc((tamanho + 1) * sizeof(char));

  if(strlen(plstar->lei) > 1)
    strcpy(chstar, "(");
  else
    strcpy(chstar, "");

  strcat(chstar, plstar->lei);

  if(strlen(plstar->lei) > 1)
    strcat(chstar, ")");

  strcat(chstar, "*");
  remove_transicao(list, plstar);

  return chstar;
}

/**
 * @brief define o tamanho de memoria que sera usada para armazena duas leis
 * @param [in] ch lei 1
 * @param [in] ch2 lei 2
 * @return o tamanho de bytes necessarios
 */
int definir_tamanho(char *ch, char *ch2)
{
  int tamanho= 0;

  if(strcmp(ch, "E") != 0)
  {
    tamanho+= strlen(ch) + 1; /* para o ponto ou \0 */
    if(strlen(ch) > 1)
      tamanho+= 2; /* 2 para os parenteses*/
  }

  if(strcmp(ch2, "E") != 0)
  {
    tamanho+= strlen(ch) + 1; /* para o \0*/
    if(strlen(ch) > 1)
      tamanho+= 2; /* 2 para os parenteses*/
  }
  return tamanho > 0 ? tamanho : 2;
}

/**
 * @brief busca por transicoes onde o estado inicial de uma transicao eh igual a de outra, como tambem com os estados finais ei1 == ei2 && ef1 == ef2  
 * @param [in] list lista das transicoes
 * @param [out] pl transicao semelhante a pl2
 * @param [out] pl2 transicao semelhante a pl
 * @return verdadeiro caso haja transicoes semelhantes, e falso para nao ha
 */
int busca_semelhantes(ltrans_t *list, ltrans_t **pl, ltrans_t **pl2)
{
  ltrans_t *plist= list, *plbusca;

  while(plist!= NULL)
  {
    if((plbusca= busca_transicao_lei(plist->prox, plist->ei, plist->ef)) != NULL)
    {
      *pl= plist;
      *pl2= plbusca;
      return 1;
    }
    plist= plist->prox;
  }
  return 0;
}

/**
 * @brief Busca uma transicao usando apenas o estado inicial como referencia de busca
 * @param [in] list lista das transicoes
 * @param [in] est estado inicial (referencia)
 * @return transicao com o estado inicial est
 */
ltrans_t *busca_por_ei(ltrans_t *list, int est)
{
  ltrans_t *pl= list;

  while(pl!= NULL)
  {
    if(pl->ei == est)
      return pl;
    pl= pl->prox;
  }

  return NULL;
}

/**
 * @brief Busca uma transicao usando apenas o estado final como referencia de busca
 * @param [in] list lista das transicoes
 * @param [in] est estado final (referencia)
 * @return transicao com o estado final est
 */
ltrans_t *busca_por_ef(ltrans_t *list, int est)
{
  ltrans_t *pl= list;

  while(pl!= NULL)
  {
    if(pl->ef == est)
      return pl;
    pl= pl->prox;
  }

  return NULL;
}

/**
 * @brief Busca uma transicao com o estado inicial e a lei como referencia
 * @param [in] list lista das transicoes
 * @param [in] ei estado inicial (referencia)
 * @param [in] lei lei
 * @return uma transicao
 */
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei)
{
  ltrans_t *pl= list;

  while(pl!= NULL)
  {
    if(pl->ei == ei && strcmp(pl->lei, lei)== 0)
      return pl;
    pl= pl->prox;
  }

  return NULL;
}

/**
 * @brief Busca uma transicao com o estado inicial e o estado final como referencia
 * @param [in] list lista das transicoes
 * @param [in] ei estado inicial (referencia)
 * @param [in] ef estado final (referencia)
 * @return uma transicao
 */
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef)
{
  ltrans_t *pl= list;

  while(pl!= NULL)
  {
    if(pl->ei== ei && pl->ef == ef)
      return pl;
    pl= pl->prox;
  }

  return NULL;
}

/* ----------------------------------------------------- */
/** 
 * @brief salva um quintupla no arquivo caso dado o nome, caso nao imprime na tela
 * @param [in] Q quintupla
 * @param [in] arquivo nome do aquivo
 */
void salva_quintupla(quintupla_t Q, char *arquivo)
{
  FILE *pf;

  if(!arquivo)
    pf= stdout;
  else
    pf= fopen(arquivo, "w");

  fprintf(pf, "#K\n");
  fprintf(pf, "%d\n", Q.K);
  fprintf(pf, "#A\n");
  fprintf(pf, "%c\n", Q.A);
  fprintf(pf, "#S\n");
  fprintf(pf, "%d\n", Q.S);
  fprintf(pf, "#F\n");
  imprime_estados(Q.F, pf);
  fprintf(pf, "#D\n");
  imprime_transicao(Q.D, pf);

  if(arquivo)
    fclose(pf);

  return;
}

/**
 * @brief imprime uma lista de estados
 * @param [in] list lista de estados
 * @param [in] stream objeto onde será impresso a lista de estados
 */
void imprime_estados(lest_t *list, FILE *stream)
{
  lest_t *pl= list;

  if(pl!= NULL)
  {
    fprintf(stream, "%d", pl->estado);
    pl= pl->prox;
  }

  while(pl!= NULL)
  {
    fprintf(stream, " %d", pl->estado);
    pl= pl->prox;
  }
  fprintf(stream, "\n");
  return;
}

/**
 * @brief imprime uma lista de Transicoes
 * @param [in] list lista de Transicoes
 * @param [in] stream objeto onde será impresso a lista de transicoes
 */
void imprime_transicao(ltrans_t *list, FILE *stream)
{
  ltrans_t *pl= list;

  while(pl!= NULL)
  {
    fprintf(stream, "%d %s %d\n", pl->ei, pl->lei, pl->ef);
    pl= pl->prox;
  }
  return;
}

/**
 * @brief cria uma lista e atribui novos elementos a lista de estados
 * @param [out] list lista de estados
 * @param [in] est estado(valor) a ser atribuido na lista
 */
void insere_estado(lest_t **list, int est)
{
  lest_t *pl= *list, *plant= NULL;

  while(pl!= NULL)
  {
    plant= pl;
    pl= pl->prox;
  }

  pl= malloc(sizeof(lest_t));
  pl->estado= est;
  pl->prox= NULL;

  if(!plant)
    *list= pl;
  else
    plant->prox= pl;

  return;
}

/**
 * @brief cria uma lista e atribui novos elementos a lista de transicoes
 * @param [out] list lista de transicoes
 * @param [in] ei estado(valor) a ser atribuido na lista, parte da transicao
 * @param [in] lei expressao que compoe a transicao a ser atribuida na lista
 * @param [in] ef estado(valor) a ser atribuido na lista, parte da transicao
 */
void insere_transicao(ltrans_t **list, int ei, char *lei, int ef)
{
  ltrans_t *pl= *list, *plant= NULL;

  while(pl!= NULL)
  {
    plant= pl;
    pl= pl->prox;
  }

  pl= malloc(sizeof(ltrans_t));
  pl->ei= ei;
  pl->lei= (char *) malloc(strlen(lei) * sizeof(char));
  strcpy(pl->lei, lei);
  pl->ef= ef;
  pl->prox= NULL;

  if(!plant)
    *list= pl;
  else
    plant->prox= pl;

  return;
}

/**
 * @brief remove um elemento da lista de estados
 * @param [out] list lista de estados
 * @param [in] r elemento a ser eliminado
 */
void remove_estado(lest_t **list, lest_t *r)
{
  lest_t *pl= *list, *plant= NULL;

  while(pl!= NULL)
  {
    if(pl == r)
      break;
    plant= pl;
    pl= pl->prox;
  }

  if(!pl)
    return;

  if(!plant)
    *list= pl->prox;
  else
    plant->prox= pl->prox;

  free(pl);
  return;
}

/**
 * @breif remove um elemento da lista das transicoes
 * @param [out] list lista de estados
 * @param [in] r elemento a ser eliminado
 */
void remove_transicao(ltrans_t **list, ltrans_t *r)
{
  ltrans_t *pl= *list, *plant= NULL;

  while(pl!= NULL)
  {
    if(pl == r)
      break;
    plant= pl;
    pl= pl->prox;
  }

  if(!pl)
    return;

  if(!plant)
    *list= pl->prox;
  else
    plant->prox= pl->prox;

  free(pl);
  return;
}

/**
 * @brief apaga toda um lista de estados
 * @param [in,out] list lista de estados
 */
void apaga_estados(lest_t **list)
{
  lest_t *pl= *list;

  while(pl!= NULL)
  {
    remove_estado(list, pl);
    pl= *list;
  }
  return;
}

/**
 * @brief apaga toda um lista de transicoes
 * @param [in,out] list lista de transicoes
 */
void apaga_transicao(ltrans_t **list)
{
  ltrans_t *pl= *list;

  while(pl!= NULL)
  {
    remove_transicao(list, pl);
    pl= *list;
  }
}

/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void help(void)
{
  IFDEBUG("help()");
  printf("%s v.%s - %s\n", "ex12", VERSION, "Convert AFD into Exp Reg");
  printf("\nUsage: %s [-h|-v|-c]\n", "ex12");
  printf("\nOptions:\n");
  printf("\t-h,  --help\n\t\tShow this help.\n");
  printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
  printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
  /* add more options here */
  printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
  printf("\nTodo:\n\tLong options not implemented yet.\n");
  printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
  exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void copyr(void)
{
  IFDEBUG("copyr()");
  printf("%s - Version %s\n", "exN", VERSION);
  printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
  if(verb>3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
  exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function does bla bla bla
 * @details It works by doing first a bla, followed by two bla's, giving
 * bla bla bla
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @return The returned value @a r means rhit
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x==funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @warning   Be carefull with blu
 * @deprecated This function will be deactivated in version +33
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @todo Need to change its output format to conform POSIX
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 * @copyright Only if not the same as the whole file
 *
 */
int funcexample(int i, int *o, int *z)
{
  IFDEBUG("funcexample()");
  i += *z;
  *o = (*z)++;
  return i-4;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=2 sw=2 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20150619.231433      */

