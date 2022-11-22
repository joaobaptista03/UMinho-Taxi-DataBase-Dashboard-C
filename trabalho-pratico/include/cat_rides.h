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

/**
 *
 * Esta é a Struct que define o que é uma Ride, e contém todas as informações dela. Será inserida no catálogo das Rides.
 * 
 */
typedef struct {
    char id[15];
    char date[15];
    char driver[15];
    char user[100];
    char city[20];
    char distance[10];
    char score_user[5];
    char score_driver[5];
    char tip[10];
    char comment[100];

} Ride;


/**
 *
 * Este é o header da função que insere os dados das Rides no catálogo.
 * 
 */
Ride* inserir_rides(FILE *rides);

#endif