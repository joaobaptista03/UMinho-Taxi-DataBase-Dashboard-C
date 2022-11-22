/**
 * @file query1_user.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com a Query 1, caso seja User.
 * 
 */

#ifndef QUERY1_USER_H
#define QUERY1_USER_H

#include <string.h>

#include "cat_drivers.h"
#include "cat_users.h"
#include "cat_rides.h"
#include "randomfuncs.h"
#include "outputs.h"
#include "age_time.h"

/**
 *
 * Este é o header da função que executa a Query 1, caso seja Driver
 * 
 */
void query1_user (int counter, Driver *drivers_cat, User *users_cat, GHashTable *users_hash, Ride *rides_cat, char *id);

#endif