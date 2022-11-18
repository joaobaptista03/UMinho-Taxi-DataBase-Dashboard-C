/**
 * @file query3.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 3.
 * 
 */

#include "../include/query3.h"

void query3 (int counter, Driver *drivers_cat, User *users_cat, Ride *rides_cat, char *N_arg) {
    int N = atoi(N_arg);                                                      // Converter argumento N string para int

    int *tot_distancia; tot_distancia = calloc(100001, sizeof(int));
    int *tot_distancia_cpy; tot_distancia_cpy = calloc(100001, sizeof(int));
    int *user_maioresID; user_maioresID = calloc(N, sizeof(int));
    int userLine = -1;

    for (int i = 1; i <= 1000000; i++) {                                              // Percorrer o catálogo das Rides
            char *status; status = malloc(10 * sizeof(char));
            for (int j = 1; j <= 100000 && userLine == -1; j++) {                                            // Percorrer o catálogo dos Users
                if (strcmp(users_cat[j].user, rides_cat[i].user) == 0) {
                    strcpy(status, users_cat[j].status);
                    userLine = j;
                }
            }
            if (strcmp(status, "active") == 0) tot_distancia[userLine] += atoi(rides_cat[i].distance);
            userLine = -1;
            free(status);
    }

    for (int i = 1; i <= 100000; i++) tot_distancia_cpy[i] = tot_distancia[i];                       // Clonar tot_distancia para ser usado no for loop
    puts("Q2 - tot_distancia clonada");

    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher user_maiores
        int larg_totDist_user = larger_int(tot_distancia_cpy, 100001);
        user_maioresID[i] = larg_totDist_user;
        tot_distancia_cpy[larg_totDist_user] = 0;
    }

    for (int i = N-1; i >= 0; i--) {                                                  // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[500];
        sprintf(output, "%s;%s;%i\n", users_cat[user_maioresID[i]].user, users_cat[user_maioresID[i]].name, tot_distancia[user_maioresID[i]]);
        handle_outputs(counter, output);
    }

    free(tot_distancia);
    free(tot_distancia_cpy);
    free(user_maioresID);
}