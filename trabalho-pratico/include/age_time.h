/**
 * @file age_time.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Datas.
 * 
 */

#ifndef AGE_TIME_H
#define AGE_TIME_H

#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 *
 * Este é o header da função que verifica se uma string é uma data.
 * 
 */
bool isDate(char *date);

/**
 *
 * Este é o header da função que dá return à idade, dando input à data de nascimento em string.
 * 
 */
int age(char date[]);

#endif