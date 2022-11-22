/**
 * @file query3.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 3.
 * 
 */

#ifndef QUERY3_H
#define QUERY3_H

#include "cat_users.h"
#include "cat_rides.h"
#include "randomfuncs.h"
#include "outputs.h"

/**
 *
 * Este é o header da função que executa a Query 3, dado um ID em forma de string, e um contador para dizer em que linha está.
 * 
 */
void query3 (int counter, User *new_users_cat, GHashTable *users_hash, Ride *new_rides_cat, char *N_arg);


#endif