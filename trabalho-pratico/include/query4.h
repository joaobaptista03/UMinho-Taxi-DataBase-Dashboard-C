/**
 * @file query4.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 4.
 * 
 */

#ifndef QUERY4_H
#define QUERY4_H

#include "cat_drivers.h"
#include "cat_rides.h"
#include "outputs.h"
#include "randomfuncs.h"
#include "stats.h"

/**
 *
 * Este é o header da função que executa a Query 4, dado um ID em forma de string, e um contador para dizer em que linha está.
 * 
 */
void query4 (int counter, char *cidade, int mode);

#endif