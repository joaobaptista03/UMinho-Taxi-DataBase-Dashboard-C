/**
 * @file cat_users.c
 * Este ficheiro contém a função que preenche o catálogo dos Users.
 * 
 */

#include "../include/cat_users.h"

return_struct inserir_users(FILE *users) {

    // Criar catálogo dos Users
    User *users_cat; users_cat = malloc(100001*sizeof(User));

    GHashTable *users_hash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);

    char *temp; temp = malloc(1000 * sizeof(char));                                // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, users); i++) {
        if (i != 0) {
            User temp_u;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_u.user, temp_u.name, temp_u.gender, temp_u.birth_date, temp_u.acc_creation, temp_u.pay_method, temp_u.status);

            users_cat[i] = temp_u;

            g_hash_table_insert(users_hash, g_strdup(temp_u.user), g_strdup_printf("%i", i));
        }
    }
    puts("Catálogo dos Users preenchido");

    User *users_cat_dup; users_cat_dup = malloc(100001*sizeof(User));
        for(int i = 1; i <= 100000; i++) users_cat_dup[i] = users_cat[i];
    free(users_cat);

    GHashTable *users_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(users_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(users_hash, new_hash, NULL);
    g_hash_table_destroy(users_hash);

    free(temp);

    return_struct r = {users_cat_dup, users_hash_dup};
    return r;
}