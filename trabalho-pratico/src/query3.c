/**
 * @file query3.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 3.
 * 
 */

#include "../include/query3.h"

void query3 (int counter, User *users_cat, GHashTable *users_hash, Ride *rides_cat, char *N_arg) {
    printf("\nA executar Q3 (linha de input %i)\n", counter);

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int N = atoi(N_arg);                                                      // Converter argumento N string para int

    int *tot_distancia; tot_distancia = calloc(100001, sizeof(int));
    int *tot_distancia_cpy; tot_distancia_cpy = calloc(100001, sizeof(int));
    int *user_maioresID; user_maioresID = calloc(N, sizeof(int));
    int userLine;

    char **recent_ride;                                                                 // Criar array de strings dinâmicamente
    recent_ride = malloc(100001 * sizeof(char*));
    for (int i = 0; i <= 100000; i++)
        recent_ride[i] = malloc(11 * sizeof(char));

    for (int i = 1; i <= 100000; i++) strcpy(recent_ride[i], "00/00/0000");                // Inicializar a array

    for (int i = 1; i <= 1000000; i++) {                                              // Percorrer o catálogo das Rides
            userLine = atoi(g_hash_table_lookup(users_hash, rides_cat[i].user));

            char *status = strdup(users_cat[userLine].status);

            if (most_recent(rides_cat[i].date, recent_ride[userLine]) == 1) strcpy(recent_ride[userLine], rides_cat[i].date);
            if (strcmp(status, "active") == 0) tot_distancia[userLine] += atoi(rides_cat[i].distance);      // Verificar se o User está ativo

            free(status);
    }

    for (int i = 1; i <= 100000; i++) tot_distancia_cpy[i] = tot_distancia[i];                       // Clonar tot_distancia para ser usado no for loop

    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher user_maiores
        int larg_totDist_user = larger_int(tot_distancia_cpy, 100001);
        user_maioresID[i] = larg_totDist_user;
        tot_distancia_cpy[larg_totDist_user] = 0;
    }

    for (int i = 0; i < N-1; i++) {
        if (tot_distancia[user_maioresID[i]] == tot_distancia[user_maioresID[i+1]]) {
            int rec_ride = most_recent(recent_ride[user_maioresID[i]], recent_ride[user_maioresID[i+1]]);
            if (rec_ride == 2) swap(user_maioresID, i, i+1);
            else if (rec_ride == 3 && strcmp(users_cat[i].user, users_cat[i+1].user) > 0) swap(user_maioresID, i, i+1);
        }
    }

    for (int i = N-1; i >= 0; i--) {                                                  // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[500];
        sprintf(output, "%s;%s;%i\n", users_cat[user_maioresID[i]].user, users_cat[user_maioresID[i]].name, tot_distancia[user_maioresID[i]]);
        handle_outputs(counter, output);
    }

    free(tot_distancia);
    free(tot_distancia_cpy);
    free(user_maioresID);
    for (int i = 0; i <= 100000; i++) free(recent_ride[i]);
    free(recent_ride);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q3 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
}