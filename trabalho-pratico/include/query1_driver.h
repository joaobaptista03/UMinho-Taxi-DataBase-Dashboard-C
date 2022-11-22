/**
 * @file query1_driver.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com a Query 1, caso seja Driver.
 * 
 */

#ifndef QUERY1_DRIVER_H
#define QUERY1_DRIVER_H

#include <string.h>

#include "cat_drivers.h"
#include "cat_rides.h"
#include "randomfuncs.h"
#include "outputs.h"
#include "age_time.h"

/**
 *
 * Este é o header da função que executa a Query 1, caso seja Driver
 * 
 */
void query1_driver (int counter, Driver *new_drivers_cat, Ride *new_rides_cat, char *id);

#endif