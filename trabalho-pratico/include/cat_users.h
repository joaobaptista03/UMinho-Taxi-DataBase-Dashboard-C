/**
 * @file cat_users.h
 * Este ficheiro contém a struct User e a função que preenche o catálogo dos Users.
 * 
 */

#ifndef CAT_USERS_H
#define CAT_USERS_H

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <stdbool.h>
#include "age_time.h"
#include "randomfuncs.h"

/**
 *
 * Esta é a Struct que define o que é um User, e contém todas as informações dele. Será inserida no catálogo dos Users.
 * 
 */
typedef struct {
    char user[30];
    char name[30];
    char gender[2];
    char birth_date[11];
    char acc_creation[11];
    char pay_method[10];
    char status[9];

} User;

/**
 *
 * Esta é a Struct que vai ser dada return no fim da função insere_users.
 * 
 */
typedef struct {
    User* userscat;
    GHashTable* usershash;
} user_struct;

/**
 *
 * Este é o header da função que verifica se um User é válido.
 * 
 */
bool isUvalid(User user1);

/**
 *
 * Este é o header da função que insere os dados dos drivers, users e rides nos catálogos respetivos.
 * 
 */
user_struct inserir_users(FILE *users);

#endif