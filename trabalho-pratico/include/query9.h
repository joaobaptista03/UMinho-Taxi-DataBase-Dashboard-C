/**
 * @file query9.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 9.
 * 
 */

#ifndef QUERY9_H
#define QUERY9_H

#include "cat_drivers.h"
#include "cat_rides.h"
#include "cat_users.h"
#include "randomfuncs.h"
#include "outputs.h"

/**
 *
 * Este é o header da função que executa a Query 9, dado um ID em forma de string, e um contador para dizer em que linha está.
 * 
 */
void query9 (int counter, char *data1, char* data2, int mode);


#endif