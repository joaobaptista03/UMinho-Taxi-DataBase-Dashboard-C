/**
 * @file query8.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 8.
 * 
 */

#include "../include/query8.h"

void query8 (int counter, Driver *drivers_cat, GHashTable *drivers_hash, User *users_cat, GHashTable *users_hash, Ride *rides_cat, char *input, int mode) {
    printf("\nA executar Q8 (linha de input %i)\n", counter);
    if (mode == 1) printf("\n");
    
    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    char genero = input[0];
    int anos = atoi(input + 2);

    Ride *ridesr = malloc(2 * sizeof(Ride));
    int cap = 2;
    int rides_n = 0;
    int contador = 0;

    for (int i = 1; i <= atoi(rides_cat[0].id); i++) {                                                  // Percorrer o catálogo das rides
        if ((stricmp(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, rides_cat[i].driver))].status, "active") == 0) 
            && (stricmp(users_cat[atoi(g_hash_table_lookup(users_hash, rides_cat[i].user))].status, "active") == 0)
            && (drivers_cat[atoi(g_hash_table_lookup(drivers_hash, rides_cat[i].driver))].gender[0] == genero)
            && (users_cat[atoi(g_hash_table_lookup(users_hash, rides_cat[i].user))].gender[0] == genero)
            && (age(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, rides_cat[i].driver))].acc_creation) >= anos)
            && (age(users_cat[atoi(g_hash_table_lookup(users_hash, rides_cat[i].user))].acc_creation) >= anos)
            ) {                                                                           // Incrementar o número de viagens do driver pretendido    
              rides_n++;
              if (rides_n > cap) {
                ridesr = realloc(ridesr, 2 * cap * sizeof(Ride));
                cap *= 2;
              }
              ridesr[contador] = rides_cat[i];
              contador++; 

        }
    }

    if (mode == 1) puts("Forma do Resultado: id_condutor;nome_condutor;username_utilizador,nome_utilizador");
    for (int i = 0; i < contador - 1; i++) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char *output; output = malloc(70 * sizeof(char));
        sprintf(output, "%s;%s;%s;%s\n", drivers_cat[atoi(g_hash_table_lookup(drivers_hash, ridesr[i].driver))].id, drivers_cat[atoi(g_hash_table_lookup(drivers_hash, ridesr[i].driver))].name, users_cat[atoi(g_hash_table_lookup(users_hash, ridesr[i].user))].user,users_cat[atoi(g_hash_table_lookup(users_hash, ridesr[i].user))].name);
        if (mode == 1) printf("%s",output);
        handle_outputs(counter, output);
        free(output);
    }

    free(ridesr);

   
   
   
    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    printf("Fim da Q8 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
}