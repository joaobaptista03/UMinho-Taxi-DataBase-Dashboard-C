/**
 * @file query1.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com as Query 1.
 * 
 */

#ifndef QUERY1_H
#define QUERY1_H

#include <string.h>

#include "cat_drivers.h"
#include "cat_users.h"
#include "cat_rides.h"
#include "randomfuncs.h"
#include "outputs.h"
#include "age_time.h"

/**
 *
 * Este é o header da função que decide se irá executar a Q1 no caso dos Drivers, ou Users com os respetivos argumentos necessários.
 * 
 */
void query1 (int counter, Driver *new_drivers_cat, User *new_users_cat, GHashTable *users_hash, Ride *new_rides_cat, char *id);

#endif