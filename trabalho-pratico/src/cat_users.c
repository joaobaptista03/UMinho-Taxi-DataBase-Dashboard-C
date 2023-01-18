/**
 * @file cat_users.c
 * Este ficheiro contém a função que preenche o catálogo dos Users.
 * 
 */

#include "../include/cat_users.h"

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

user_struct inserir_users(FILE *users) {
    int nr_users = 1, cap_malloc = 1;;

    // Criar catálogo dos Users
    User *users_cat; users_cat = malloc(sizeof(User));

    User generic_u;
            strcpy(generic_u.user, "");
            strcpy(generic_u.gender, "");
            strcpy(generic_u.birth_date, "");
            strcpy(generic_u.acc_creation, "");
            strcpy(generic_u.pay_method, "");
            strcpy(generic_u.status, "");

    GHashTable *users_hash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);

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

    sprintf(users_cat[0].user, "%d", nr_users - 1);
    strcpy(users_cat[0].name, "");
    strcpy(users_cat[0].gender, "");
    strcpy(users_cat[0].birth_date, "");
    strcpy(users_cat[0].acc_creation, "");
    strcpy(users_cat[0].pay_method, "");
    strcpy(users_cat[0].status, "");

    puts("Catálogo dos Users preenchido");

    User *users_cat_dup; users_cat_dup = malloc((1 + atoi(users_cat[0].user))*sizeof(User));
        for(int i = 0; i <= atoi(users_cat[0].user); i++) users_cat_dup[i] = users_cat[i];
    free(users_cat);

    GHashTable *users_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(users_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(users_hash, new_hash, NULL);
    g_hash_table_destroy(users_hash);

    free(temp);

    user_struct r = {users_cat_dup, users_hash_dup};
    return r;
}