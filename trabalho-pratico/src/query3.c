/**
 * @file query3.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 3.
 * 
 */

#include "../include/query3.h"

char **recent_rides;                                                                   // Criar array de strings dinâmicamente

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

    recent_rides = malloc((get_nr_users()  + 1)* sizeof(char*));
    for (int i = 0; i <= get_nr_users(); i++)
        recent_rides[i] = malloc(11 * sizeof(char));

    for (int i = 1; i <= get_nr_users(); i++) strcpy(recent_rides[i], "00/00/0000");                // Inicializar a array

    for (int i = 1; i <= get_nr_rides(); i++) {                                              // Percorrer o catálogo das Rides
            userLine = get_user_i(get_ride_user(i));

            if (most_recent(get_ride_date(i), recent_rides[userLine]) == 1) strcpy(recent_rides[userLine], get_ride_date(i));
            if (stricmp(get_user_status(get_ride_user(i)), "active") == 0) tot_distancia[userLine] += atoi(get_ride_distance(i));      // Verificar se o User está ativo
    }

    for (int i = 1; i <= get_nr_users(); i++) tot_distancia_cpy[i] = tot_distancia[i];                       // Clonar tot_distancia para ser usado no for loop

    for (int i = 0; i < N-1; i++) {                                                     // For loop que irá preencher user_maiores
        int larg_totDist_user = larger_int(tot_distancia_cpy, (1 + get_nr_users()));

        if (larg_totDist_user == -1) {
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if (mode == 1) puts("\nResultado: Não existem Rides suficientes!\n");
            if ((mode == 1) || (mode == 3)) printf("Fim da Q3 (Sem Rides Suficientes) - %f segundos (input nº %i)\n", cpu_time_used, counter);
            if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
            return;
        }

        user_maioresID[i] = larg_totDist_user;
        tot_distancia_cpy[larg_totDist_user] = 0;
    }

    int last_av_i = larger_int(tot_distancia_cpy, (1 + get_nr_users()));
    int aux_av_i = last_av_i;
    double last_av = tot_distancia_cpy[last_av_i];
    int cap = N, nr_maiores = N-1;

    for(; tot_distancia_cpy[aux_av_i] == last_av; nr_maiores++) {
        if (nr_maiores + 1 > cap) {
            user_maioresID = realloc(user_maioresID, (cap + 5) * sizeof(int));
            cap += 5;
        }
        user_maioresID[nr_maiores] = aux_av_i;
        tot_distancia_cpy[aux_av_i] = 0;
        aux_av_i = larger_int(tot_distancia_cpy, (1 + get_nr_users()));
    }

    int curr_elem;
    for (int i = 0; i < nr_maiores - 1; i += curr_elem) {
        curr_elem = dist_elem(user_maioresID, nr_maiores, tot_distancia, tot_distancia[user_maioresID[i]]);
        if (curr_elem != 1) qsort(user_maioresID + i, curr_elem, sizeof(int), first_user);
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
    for (int i = 0; i <= get_nr_users(); i++) free(recent_rides[i]);
    free(recent_rides);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    if ((mode == 1) || (mode == 3)) printf("Fim da Q3 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}

char* get_recdate_user(int i) {
    return recent_rides[i];
}