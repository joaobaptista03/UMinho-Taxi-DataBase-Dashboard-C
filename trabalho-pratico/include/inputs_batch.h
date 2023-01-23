/**
 * @file inputs_batch.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com os inputs do modo batch.
 * 
 */

#ifndef INPUTS_BATCH_H
#define INPUTS_BATCH_H

#include <string.h>
#include <stdio.h>

#include "../include/cat_drivers.h"
#include "../include/cat_users.h"
#include "../include/cat_rides.h"

#include "../include/query1.h"
#include "../include/query2.h"
#include "../include/query3.h"
#include "../include/query4.h"
#include "../include/query5.h"
#include "../include/query6.h"
#include "../include/query7.h"
#include "../include/query8.h"

/**
 *
 * Este é o header da função que faz o tratamento dos inputs e redireciona-os para as query's correspondentes.
 * 
 */
void handle_inputs(Driver *drivers_cat, GHashTable *drivers_hash, User *users_cat, GHashTable *users_hash, Ride *rides_cat, FILE *inputs);

#endif