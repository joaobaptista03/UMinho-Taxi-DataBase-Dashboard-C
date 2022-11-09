/**
 * @file age_time.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Datas.
 * 
 */

#ifndef AGE_TIME
#define AGE_TIME

#include <time.h>

/**
 *
 * Este é o header da função que dá return ao ano atual.
 * 
 */
int act_year();

/**
 *
 * Este é o header da função que dá return ao mês atual.
 * 
 */
int act_month();

/**
 *
 * Este é o header da função que dá return ao dia atual.
 * 
 */
int act_day();

/**
 *
 * Este é o header da função que dá return à idade, dando input à data de nascimento em string.
 * 
 */
int age(char date[]);

#endif