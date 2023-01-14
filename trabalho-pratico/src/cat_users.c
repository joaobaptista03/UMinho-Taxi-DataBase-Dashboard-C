/**
 * @file cat_users.c
 * Este ficheiro contém a função que preenche o catálogo dos Users.
 * 
 */

#include "../include/cat_users.h"

return_struct inserir_users(FILE *users) {
    int nr_users = 0;

    // Criar catálogo dos Users
    User *users_cat; users_cat = malloc(sizeof(User));

    GHashTable *users_hash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);

    char *temp; temp = malloc(1000 * sizeof(char));                                // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, users); i++) {
        if (i != 0) {
            users_cat = realloc(users_cat, (nr_users+1) * sizeof(User));

            User temp_u;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_u.user, temp_u.name, temp_u.gender, temp_u.birth_date, temp_u.acc_creation, temp_u.pay_method, temp_u.status);

            users_cat[i] = temp_u;

            g_hash_table_insert(users_hash, g_strdup(temp_u.user), g_strdup_printf("%i", i));
        }
    }

    sprintf(users_cat[0].user, "%d", nr_users);
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

    return_struct r = {users_cat_dup, users_hash_dup};
    return r;
}