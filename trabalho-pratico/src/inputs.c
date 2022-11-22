/**
 * @file inputs.c
 * Este ficheiro contém a função que trata de cada input e redireciona-os para a query correspondente
 * 
 */

#include "../include/inputs.h"

void handle_inputs(Driver *drivers_cat, User *users_cat, GHashTable *users_hash, Ride *rides_cat, FILE *inputs) {

    // Encapsulamento Catálogos
    Driver *drivers_cat_dup; drivers_cat_dup = malloc(10001*sizeof(Driver));
        for(int i = 1; i <= 10000; i++) drivers_cat_dup[i] = drivers_cat[i];
    free(drivers_cat);
    User *users_cat_dup; users_cat_dup = malloc(100001*sizeof(User));
        for(int i = 1; i <= 100000; i++) users_cat_dup[i] = users_cat[i];
    free(users_cat);
    Ride *rides_cat_dup; rides_cat_dup = malloc(1000001*sizeof(Ride));
        for(int i = 1; i <= 1000000; i++) rides_cat_dup[i] = rides_cat[i];
    free(rides_cat);

    // Encapsulamento Hash Table
    GHashTable *users_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(users_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(users_hash, new_hash, NULL);
    g_hash_table_destroy(users_hash);

    // Início Inputs
    int counter = 1;                                                    // Contador do input em que está
    char *input; input = malloc(100 * sizeof(char));                    // String para qual cada linha de input irá ser copiada
    while(fgets(input, 100, inputs)) {                                  // Loop While que irá fazer certas coisas (em cada loop) a cada linha do ficheiros de inputs  
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';     // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') query1(counter, drivers_cat_dup, users_cat_dup, users_hash_dup, rides_cat_dup, input + 2);
        if (input[0] == '2') query2(counter, drivers_cat_dup, rides_cat_dup, input + 2);
        if (input[0] == '3') query3(counter, users_cat_dup, users_hash_dup, rides_cat_dup, input + 2);
        if (input[0] == '4') query4(counter, drivers_cat_dup, rides_cat_dup, input + 2);
        if (input[0] == '5') query5(counter, drivers_cat_dup, rides_cat_dup, input + 2, input + 13);
        if (input[0] == '6') query6(counter, rides_cat_dup, input + 2);                 
        /*
        if (input[0] == '7') query7(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2); // Tem de fazer parsing porque o tamanho da city varia
        if (input[0] == '8') query8(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2, input + 4);
        if (input[0] == '9') query9(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2, input + 13);
        */
       counter++;                                                       // Incrementar nº de inputs
    }

    free(input);
    free(drivers_cat_dup);
    free(users_cat_dup);
    free(rides_cat_dup);
    g_hash_table_destroy(users_hash_dup);
}
