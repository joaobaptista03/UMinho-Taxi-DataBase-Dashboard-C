/**
 * @file inputs_interactive.c
 * Este ficheiro contém a função que trata de cada input do modo interativo e redireciona-os para a query correspondente
 * 
 */

#include "../include/inputs_batch.h"

void handle_input(Driver *drivers_cat, GHashTable *drivers_hash, User *users_cat, GHashTable *users_hash, Ride *rides_cat) {

    // Encapsulamento Catálogos
    Driver *drivers_cat_dup; drivers_cat_dup = malloc((1 + atoi(drivers_cat[0].id))*sizeof(Driver));
        for(int i = 0; i <= atoi(drivers_cat[0].id); i++) drivers_cat_dup[i] = drivers_cat[i];
    free(drivers_cat);
    User *users_cat_dup; users_cat_dup = malloc((1 + atoi(users_cat[0].user))*sizeof(User));
        for(int i = 0; i <= atoi(users_cat[0].user); i++) users_cat_dup[i] = users_cat[i];
    free(users_cat);
    Ride *rides_cat_dup; rides_cat_dup = malloc((1 + atoi(rides_cat[0].id))*sizeof(Ride));
        for(int i = 0; i <= atoi(rides_cat[0].id); i++) rides_cat_dup[i] = rides_cat[i];
    free(rides_cat);
    // Encapsulamento Hash Table Users
    GHashTable *users_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash_u(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(users_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(users_hash, new_hash_u, NULL);
    g_hash_table_destroy(users_hash);
    // Encapsulamento Hash Table Drivers
    GHashTable *drivers_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash_d(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(drivers_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(drivers_hash, new_hash_d, NULL);
    g_hash_table_destroy(drivers_hash);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while ((fgets(input, 100, stdin)) && (stricmp(input, "EXIT\n") != 0)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                                                                // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') query1(counter, drivers_cat_dup, drivers_hash_dup, users_cat_dup, users_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '2') query2(counter, drivers_cat_dup, drivers_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '3') query3(counter, users_cat_dup, users_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '4') query4(counter, drivers_cat_dup, drivers_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '5') query5(counter, drivers_cat_dup, drivers_hash_dup, rides_cat_dup, input + 2, input + 13);
        else if (input[0] == '6') query6(counter, rides_cat_dup, input + 2);
        else if (input[0] == '7') query7(counter, drivers_cat_dup, drivers_hash_dup, rides_cat_dup, input + 2, input + 5);                             // Tem de fazer parsing porque o tamanho da city varia
        /*
        if (input[0] == '8') query8(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2, input + 4);
        if (input[0] == '9') query9(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2, input + 13);
        */
        counter++;
        puts("--------------------------------------------");
    }

    system("rm -r Resultados");   

    free(input);
    free(drivers_cat_dup);
    free(users_cat_dup);
    free(rides_cat_dup);
    g_hash_table_destroy(users_hash_dup);
    g_hash_table_destroy(drivers_hash_dup);

}

