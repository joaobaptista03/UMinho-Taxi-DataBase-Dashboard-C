/**
 * @file randomfuncs.h
 * 
 * Este ficheiro contém as assinaturas das funções aleatórias que podem ser usadas em vários assuntos.
 * 
 */

#ifndef RANDOM_FUNCS_H
#define RANDOM_FUNCS_H

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "cat_drivers.h"
#include "cat_users.h"
#include "cat_rides.h"
#include "query2.h"
#include "query3.h"

/**
 *
 * Este é o header da função que dada uma string, verifica se a string é um dígito, e se for, é porque é driver, caso contrário é user.
 * 
 */
int isDriver(char str[], int N);

/**
 *
 * Este é o header da função que dada uma array de doubles e o tamanho da mesma, calcula o maior valor (a partir do índice 1 apenas).
 * 
 */
int larger_double(double *doubles, int N);

/**
 *
 * Este é o header da função que dada uma array de ints e o tamanho da mesma, calcula o maior valor (a partir do índice 1 apenas).
 * 
 */
int larger_int(int *ints, int N);

/**
 *
 * Este é o header da função que dadas 2 datas, retorna 1 se a primeira data for mais recente e 2 se a segunda data for mais recente.
 * 
 */
int most_recent(char *date1, char *date2);

/**
 *
 * Este é o header da função que dado um double com 1 dígito antes da vírgula, retorna o mesmo double arredondado a 3 casas.
 * 
 */
double arred3(double x);

/**
 *
 * Este é o header da função que dada uma array de int's e dois índices, troca-os.
 * 
 */
void swap(int *x, int i, int j);

/**
 *
 * Este é o header da função similar à strcmp, porém não é sensível a maiúsculas.
 * 
 */
int stricmp(char const *a, char const *b);

/**
 *
 * Este é o header da função que verifica se uma dada string é um inteiro.
 * 
 */
bool isInt (char *string);

/**
 *
 * Este é o header da função que verifica se uma dada string é um float.
 * 
 */
bool isFloat (char *string);

/**
 *
 * Este é o header da função que verifica se dois dados ficheiros são iguais.
 * 
 */
bool compare (FILE *file1, FILE *file2);

/**
 *
 * Este é o header da função que devolve o número de id's que contém avaliação média igual a av.
 * 
 */
int av_elem (int *id_maiores, int nr_maiores, double *av_med, double av);

/**
 *
 * Este é o header da função que devolve o número de id's que contém distância total igual a dist_total.
 * 
 */
int dist_elem (int *user_maioresID, int nr_maiores, int *tot_distancia, int dist_total);

/**
 *
 * Este é o header da função que decide qual dos drivers deve aparecer primeiro.
 * 
 */
int first_driver(const void *i1, const void *i2);

/**
 *
 * Este é o header da função que decide qual dos Users deve aparecer primeiro.
 * 
 */
int first_user(const void *i1, const void *i2);

#endif