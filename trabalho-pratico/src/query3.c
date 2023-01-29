/**
 * @file query3.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 3.
 * 
 */

#include "../include/query3.h"

void query3 (int counter, char *N_arg, int mode) {

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    int N = atoi(N_arg);                                                      // Converter argumento N string para int

    int *tot_distancia; tot_distancia = calloc((1 + get_nr_users()), sizeof(int));
    int *tot_distancia_cpy; tot_distancia_cpy = calloc((1 + get_nr_users()), sizeof(int));
    int *user_maioresID; user_maioresID = calloc(N, sizeof(int));
    int userLine;

    char **recent_ride;                                                                 // Criar array de strings dinâmicamente
    recent_ride = malloc((get_nr_users()  + 1)* sizeof(char*));
    for (int i = 0; i <= get_nr_users(); i++)
        recent_ride[i] = malloc(11 * sizeof(char));

    for (int i = 1; i <= get_nr_users(); i++) strcpy(recent_ride[i], "00/00/0000");                // Inicializar a array

    for (int i = 1; i <= get_nr_rides(); i++) {                                              // Percorrer o catálogo das Rides
            userLine = get_user_i(get_ride_user(i));

            if (most_recent(get_ride_date(i), recent_ride[userLine]) == 1) strcpy(recent_ride[userLine], get_ride_date(i));
            if (stricmp(get_user_status(get_ride_user(i)), "active") == 0) tot_distancia[userLine] += atoi(get_ride_distance(i));      // Verificar se o User está ativo
    }

    for (int i = 1; i <= get_nr_users(); i++) tot_distancia_cpy[i] = tot_distancia[i];                       // Clonar tot_distancia para ser usado no for loop

    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher user_maiores
        int larg_totDist_user = larger_int(tot_distancia_cpy, (1 + get_nr_users()));
        user_maioresID[i] = larg_totDist_user;
        tot_distancia_cpy[larg_totDist_user] = 0;
    }

    for (int i = 0; i < N-1; i++) {
        if (tot_distancia[user_maioresID[i]] == tot_distancia[user_maioresID[i+1]]) {
            int rec_ride = most_recent(recent_ride[user_maioresID[i]], recent_ride[user_maioresID[i+1]]);
            if (rec_ride == 2) swap(user_maioresID, i, i+1);
            else if (rec_ride == 3 && stricmp(get_user_username(i), get_user_username(i+1)) > 0) swap(user_maioresID, i, i+1);
        }
    }

    if (mode == 1) puts("\nForma do Resultado: username;nome;distancia_total");
    for (int i = 0; i < N; i++) {                                                  // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[150];
        sprintf(output, "%s;%s;%i\n", get_user_username(user_maioresID[i]), get_user_name(get_user_username(user_maioresID[i])), tot_distancia[user_maioresID[i]]);
        if (mode == 1) printf("%s",output);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
    }

    free(tot_distancia);
    free(tot_distancia_cpy);
    free(user_maioresID);
    for (int i = 0; i <= get_nr_users(); i++) free(recent_ride[i]);
    free(recent_ride);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if ((mode == 1) || (mode == 3)) printf("\nFim da Q3 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}