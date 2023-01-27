/**
 * @file cat_rides.h
 * Este ficheiro contém a struct Ride e a função que preenche o catálogo das Rides.
 * 
 */

#ifndef CAT_RIDES_H
#define CAT_RIDES_H

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <stdbool.h>
#include "randomfuncs.h"
#include "age_time.h"

/**
 *
 * Esta é a Struct que define o que é uma Ride, e contém todas as informações dela. Será inserida no catálogo das Rides.
 * 
 */
typedef struct Ride Ride;

/**
 *
 * Este é o header da função que retornará o número de Rides.
 * 
 */
int get_nr_rides();

/**
 *
 * Este é o header da função que retornará o ID da Ride.
 * 
 */
char *get_ride_id(int indice);

/**
 *
 * Este é o header da função que retornará a data da Ride.
 * 
 */
char *get_ride_date(int indice);

/**
 *
 * Este é o header da função que retornará o Driver da Ride.
 * 
 */
char *get_ride_driver(int indice);

/**
 *
 * Este é o header da função que retornará o User da Ride.
 * 
 */
char *get_ride_user(int indice);

/**
 *
 * Este é o header da função que retornará a cidade da Ride.
 * 
 */
char *get_ride_city(int indice);

/**
 *
 * Este é o header da função que retornará a distância da Ride.
 * 
 */
char *get_ride_distance(int indice);

/**
 *
 * Este é o header da função que retornará o Score User da Ride.
 * 
 */
char *get_ride_score_user(int indice);

/**
 *
 * Este é o header da função que retornará o o Score Driver da Ride.
 * 
 */
char *get_ride_score_driver(int indice);

/**
 *
 * Este é o header da função que retornará a tip da Ride.
 * 
 */
char *get_ride_tip(int indice);

/**
 *
 * Este é o header da função que verifica se uma Ride é válido.
 * 
 */
bool isRvalid(Ride ride1);

/**
 *
 * Este é o header da função que insere os dados das Rides no catálogo.
 * 
 */
Ride* inserir_rides(FILE *rides);

#endif