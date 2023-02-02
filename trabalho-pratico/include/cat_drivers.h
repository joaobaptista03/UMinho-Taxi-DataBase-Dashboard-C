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
typedef struct Driver Driver;

/**
 *
 * Esta é a Struct que liberta a memória do catálogo dos Drivers.
 * 
 */
void free_drivers();

/**
 *
 * Esta é a função que retornará o número de drivers, dado o catálogo dos Drivers.
 * 
 */
int get_n_drivers();

/**
 *
 * Esta é a função que dirá se o ID existe ou não.
 * 
 */
bool is_driver (char *id);

/**
 *
 * Esta é a função que retornará o índice do Driver.
 * 
 */
int get_driver_i(char *id);

/**
 *
 * Esta é a função que retornará o id do Driver.
 * 
 */
char* get_driver_id(int indice);

/**
 *
 * Esta é a função que retornará o nome do Driver.
 * 
 */
char* get_driver_name(char *id);

/**
 *
 * Esta é a função que retornará a data de nascimento do Driver.
 * 
 */
char* get_driver_birth_date(char *id);

/**
 *
 * Esta é a função que retornará o género do Driver.
 * 
 */
char* get_driver_gender(char *id);

/**
 *
 * Esta é a função que retornará a classe do carro do Driver.
 * 
 */
char* get_driver_car_class(char *id);

/**
 *
 * Esta é a função que retornará a matrícula do carro do Driver.
 * 
 */
char* get_driver_license_plate(char *id);

/**
 *
 * Esta é a função que retornará a cidade do Driver.
 * 
 */
char* get_driver_city(char *id);

/**
 *
 * Esta é a função que retornará a data de criação da conta do Driver.
 * 
 */
char* get_driver_acc_creation(char *id);

/**
 *
 * Esta é a função que retornará o estado do Driver.
 * 
 */
char* get_driver_status(char *id);

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
void inserir_drivers(FILE *drivers);

#endif