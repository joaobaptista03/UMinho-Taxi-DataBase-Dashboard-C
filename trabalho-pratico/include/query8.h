/**
 * @file query8.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 8.
 * 
 */

#ifndef QUERY8_H
#define QUERY8_H

#include "cat_drivers.h"
#include "cat_rides.h"
#include "randomfuncs.h"
#include "outputs.h"

/**
 *
 * Este é o header da função que executa a Query 8, dado um ID em forma de string, e um contador para dizer em que linha está.
 * 
 */
void query8 (int counter, Driver *drivers_cat, GHashTable *drivers_hash, Ride *new_rides_cat, char *input, int mode);


#endif