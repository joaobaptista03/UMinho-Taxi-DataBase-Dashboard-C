/**
 * @file query2.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 2.
 * 
 */

#ifndef QUERY2_H
#define QUERY2_H

#include "cat_drivers.h"
#include "cat_rides.h"
#include "randomfuncs.h"
#include "outputs.h"
#include "stats.h"

/**
 *
 * Este é o header da função que executa a Query 2, dado um ID em forma de string, e um contador para dizer em que linha está.
 * 
 */
void query2 (int counter, char *N_arg, int mode);

/**
 *
 * Este é o header da função que retorna um pointer para a string da data mais recent de um dado Driver.
 * 
 */
char *get_recdate_driver (char *id);

#endif