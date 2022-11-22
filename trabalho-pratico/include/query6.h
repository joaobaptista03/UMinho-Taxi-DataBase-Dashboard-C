/**
 * @file query6.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 6.
 * 
 */

#ifndef QUERY6_H
#define QUERY6_H

#include "cat_rides.h"
#include "outputs.h"
#include "randomfuncs.h"

/**
 *
 * Este é o header da função que executa a Query 6, dado um ID em forma de string, e um contador para dizer em que linha está.
 * 
 */
void query6 (int counter, Ride *rides_cat, char *input);

#endif