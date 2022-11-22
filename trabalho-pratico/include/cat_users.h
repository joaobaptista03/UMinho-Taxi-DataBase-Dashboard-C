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

/**
 *
 * Esta é a Struct que define o que é um User, e contém todas as informações dele. Será inserida no catálogo dos Users.
 * 
 */
typedef struct {
    char user[100];
    char name[100];
    char gender[5];
    char birth_date[15];
    char acc_creation[15];
    char pay_method[20];
    char status[10];

} User;

/**
 *
 * Esta é a Struct que vai ser dada return no fim da função insere_users.
 * 
 */
typedef struct {
    User* userscat;
    GHashTable* usershash;
} return_struct;

/**
 *
 * Este é o header da função que insere os dados dos drivers, users e rides nos catálogos respetivos.
 * 
 */
return_struct inserir_users(FILE *users);

#endif