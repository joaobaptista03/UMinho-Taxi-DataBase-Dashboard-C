/**
 * @file cat_users.c
 * Este ficheiro contém a função que preenche o catálogo dos Users.
 * 
 */

#include "../include/cat_users.h"

struct User {
    char user[50];
    char name[40];
    char gender[2];
    char birth_date[11];
    char acc_creation[11];
    char pay_method[20];
    char status[9];

};

struct user_struct {
    User* userscat;
    GHashTable* usershash;
};

GHashTable *users_hash;
User *users_cat;

bool isUvalid(User user1) {
    return (
        (strlen(user1.user) > 0) &&
        (strlen(user1.name) > 0) &&
        (strlen(user1.gender) == 1) &&
        (isDate(user1.birth_date)) &&
        (isDate(user1.acc_creation)) &&
        (strlen(user1.pay_method) > 0) &&
        ((stricmp(user1.status,"active") == 0) || (stricmp(user1.status,"inactive") == 0))
    );
}

int get_nr_users() {
    return g_hash_table_size(users_hash);
}

bool is_user (char *user) {
    return g_hash_table_contains(users_hash, user);
}

int get_user_i(char *user) {
    return atoi(g_hash_table_lookup(users_hash, user));
}

char* get_user_username(int indice) {
    return users_cat[indice].user;
}

char* get_user_name(char *user) {
    return users_cat[atoi(g_hash_table_lookup(users_hash, user))].name;
}

char* get_user_gender(char *user) {
    return users_cat[atoi(g_hash_table_lookup(users_hash, user))].gender;
}

char* get_user_birth_date(char *user) {
    return users_cat[atoi(g_hash_table_lookup(users_hash, user))].birth_date;
}

char* get_user_acc_creation(char *user) {
    return users_cat[atoi(g_hash_table_lookup(users_hash, user))].acc_creation;
}

char* get_user_pay_method(char *user) {
    return users_cat[atoi(g_hash_table_lookup(users_hash, user))].pay_method;
}

char* get_user_status(char *user) {
    return users_cat[atoi(g_hash_table_lookup(users_hash, user))].status;
}

user_struct inserir_users(FILE *users) {
    int nr_users = 1, cap_malloc = 1;;

    // Criar catálogo dos Users
    users_cat = malloc(sizeof(User));

    User generic_u;
            strcpy(generic_u.user, "");
            strcpy(generic_u.gender, "");
            strcpy(generic_u.birth_date, "");
            strcpy(generic_u.acc_creation, "");
            strcpy(generic_u.pay_method, "");
            strcpy(generic_u.status, "");

    users_hash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);

    char *temp; temp = malloc(1000 * sizeof(char));                                // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, users); i++) {
        if (i != 0) {
            if (cap_malloc == nr_users) {
                users_cat = realloc(users_cat, 2 * cap_malloc * sizeof(User));
                cap_malloc *= 2;
            }
            
            User temp_u;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_u.user, temp_u.name, temp_u.gender, temp_u.birth_date, temp_u.acc_creation, temp_u.pay_method, temp_u.status);

            if (isUvalid(temp_u)) {
                users_cat[i] = temp_u;
                g_hash_table_insert(users_hash, g_strdup(temp_u.user), g_strdup_printf("%i", i));
                nr_users++;
            }
            else i--;

            temp_u = generic_u;

        }
    }

    strcpy(users_cat[0].user, "");
    strcpy(users_cat[0].name, "");
    strcpy(users_cat[0].gender, "");
    strcpy(users_cat[0].birth_date, "");
    strcpy(users_cat[0].acc_creation, "");
    strcpy(users_cat[0].pay_method, "");
    strcpy(users_cat[0].status, "");

    puts("Catálogo dos Users preenchido");
    
    free(temp);
    user_struct r = {users_cat, users_hash};
    return r;
}