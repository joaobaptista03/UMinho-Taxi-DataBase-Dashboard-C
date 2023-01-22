/**
 * @file cat_drivers.h
 * Este ficheiro contém a struct Driver e a função que preenche o catálogo dos Drivers.
 * 
 */

#ifndef CAT_DRIVERS_H
#define CAT_DRIVERS_H

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <stdbool.h>
#include "age_time.h"
#include "randomfuncs.h"

/**
 *
 * Esta é a Struct que define o que é um Driver, e contém todas as informações dele. Será inserida no catálogo das Drivers.
 * 
 */
typedef struct {
    char id[13];
    char name[30];
    char birth_date[11];
    char gender[2];
    char car_class[8];
    char license_plate[9];
    char city[10];
    char acc_creation[11];
    char status[9];

} Driver;

/**
 *
 * Esta é a Struct que vai ser dada return no fim da função insere_driver.
 * 
 */
typedef struct {
    Driver* driverscat;
    GHashTable* drivershash;
} driver_struct;

/**
 *
 * Este é o header da função que verifica se um Driver é válido.
 * 
 */
bool isDvalid(Driver driver1);

/**
 *
 * Este é o header da função que insere os dados dos Drivers no catálogo.
 * 
 */
driver_struct inserir_drivers(FILE *drivers);

#endif