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
typedef struct User User;

/**
 *
 * Esta é a Struct que vai ser dada return no fim da função insere_users.
 * 
 */
typedef struct user_struct user_struct;

/**
 *
 * Esta é a função que retornará o número de users, dado o catálogo dos Users.
 * 
 */
int get_nr_users();

/**
 *
 * Esta é a função que dirá se o user existe ou não.
 * 
 */
bool is_user (char *user);

/**
 *
 * Esta é a função que retornará o índice do User.
 * 
 */
int get_user_i(char *user);

/**
 *
 * Esta é a função que retornará o username do User.
 * 
 */
char* get_user_username(int indice);

/**
 *
 * Esta é a função que retornará o nome do User.
 * 
 */
char* get_user_name(char *user);

/**
 *
 * Esta é a função que retornará o género do User.
 * 
 */
char* get_user_gender(char *user);

/**
 *
 * Esta é a função que retornará a data de nascimento do User.
 * 
 */
char* get_user_birth_date(char *user);

/**
 *
 * Esta é a função que retornará a data de criação da conta do User.
 * 
 */
char* get_user_acc_creation(char *user);

/**
 *
 * Esta é a função que retornará o método de pagamento do User.
 * 
 */
char* get_user_pay_method(char *user);

/**
 *
 * Esta é a função que retornará o estado User.
 * 
 */
char* get_user_status(char *user);

/**
 *
 * Este é o header da função que verifica se um User é válido.
 * 
 */
bool isUvalid(User user1);

/**
 *
 * Este é o header da função que insere os dados dos Users, users e rides nos catálogos respetivos.
 * 
 */
user_struct inserir_users(FILE *users);

#endif