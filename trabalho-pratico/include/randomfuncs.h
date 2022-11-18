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

#endif