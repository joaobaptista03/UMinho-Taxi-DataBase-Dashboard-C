/**
 * @file inputs_interactive.c
 * Este ficheiro contém a função que trata de cada input do modo interativo e redireciona-os para a query correspondente
 * 
 */

#include "../include/inputs_batch.h"

void handle_input(Driver *drivers_cat, GHashTable *drivers_hash, User *users_cat, GHashTable *users_hash, Ride *rides_cat) {

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while ((fgets(input, 100, stdin)) && (stricmp(input, "EXIT\n") != 0)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                                                                // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') query1(counter, drivers_cat, drivers_hash, users_cat, users_hash, rides_cat, input + 2, 1);
        else if (input[0] == '2') query2(counter, drivers_cat, drivers_hash, rides_cat, input + 2, 1);
        else if (input[0] == '3') query3(counter, users_cat, users_hash, rides_cat, input + 2, 1);
        else if (input[0] == '4') query4(counter, drivers_cat, drivers_hash, rides_cat, input + 2, 1);
        else if (input[0] == '5') query5(counter, drivers_cat, drivers_hash, rides_cat, input + 2, input + 13, 1);
        else if (input[0] == '6') query6(counter, rides_cat, input + 2, 1);
        else if (input[0] == '7') query7(counter, drivers_cat, drivers_hash, rides_cat, input + 2, 1);                             // Tem de fazer parsing porque o tamanho da city varia
        else if (input[0] == '8') query8(counter, drivers_cat, drivers_hash, users_cat, users_hash, rides_cat, input + 2, 1);
        else if (input[0] == '9') query9(counter, rides_cat, input + 2, input + 13, 1);
        counter++;
        puts("--------------------------------------------");
    }

    free(input);
    free(drivers_cat);
    free(users_cat);
    free(rides_cat);
    g_hash_table_destroy(users_hash);
    g_hash_table_destroy(drivers_hash);

}

