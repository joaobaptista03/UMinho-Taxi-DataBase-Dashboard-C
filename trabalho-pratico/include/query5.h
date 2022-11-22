/**
 * @file query5.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 5.
 * 
 */

#ifndef QUERY5_H
#define QUERY5_H

#include "cat_drivers.h"
#include "cat_rides.h"
#include "outputs.h"
#include "randomfuncs.h"

/**
 *
 * Este é o header da função que executa a Query 5, dado um ID em forma de string, e um contador para dizer em que linha está.
 * 
 */
void query5 (int counter, Driver *drivers_cat, Ride *rides_cat, char *data1, char *data2);

#endif