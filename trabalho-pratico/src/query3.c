/**
 * @file query3.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 3.
 * 
 */

#include "../include/query3.h"

void query3 (int counter, Driver *drivers_cat, User *users_cat, Ride *rides_cat, char *N_arg) {
    int N = atoi(N_arg);                                                      // Converter argumento N string para int

    double tot_distancia[100001] = {0}, tot_distancia_cpy[100001] = {0};
    int user_maioresID[N];
    int userLine = -1;


    for (int i = 1; i <= 1000000; i++) {                                              // Percorrer o catálogo das Rides

        for (int j = 1; j <= 100000 && userLine == -1; j++) {                                            // Percorrer o catálogo dos Users
            if (strcmp(users_cat[j].user, rides_cat[i].user) == 0) {
                userLine = j;
            }
        }
        tot_distancia[userLine] += atof(rides_cat[i].distance);
        userLine = -1;
    }

    for (int i = 1; i <= 10000; i++) tot_distancia_cpy[i] = tot_distancia[i];                       // Clonar tot_distancia para ser usado no for loop
    puts("Q2 - tot_distancia clonada");

    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher user_maiores
        int larg_totDist_user = larger_double(tot_distancia_cpy, 100001);
        user_maioresID[i] = larg_totDist_user;
        tot_distancia_cpy[larg_totDist_user] = 0;
    }

    for (int i = N-1; i >= 0; i--) {                                                  // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[500];
        sprintf(output, "%s;%s;%.3f\n", users_cat[user_maioresID[i]].user, users_cat[user_maioresID[i]].name, tot_distancia[user_maioresID[i]]);
        handle_outputs(counter, output);
    }
}