/**
 * @file query2.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 2.
 * 
 */

#include "../include/query2.h"

void query2 (int counter, Driver *drivers_cat, Ride *rides_cat, char *N_arg) {
    printf("\nA executar Q2 (linha de input %i)\n", counter);

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int N = atoi(N_arg);                                                      // Converter argumento N string para int

    // Criar todas as arrays temporárias necessárias à função 
    double *tot_avaliacoes; tot_avaliacoes = calloc(10001, sizeof(double));
    int *num_viagens; num_viagens = calloc(10001, sizeof(int));
    double *av_med; av_med = calloc(10001, sizeof(double));
    double *av_med_cpy; av_med_cpy = calloc(10001, sizeof(double));

    char **recent_ride;                                                                   // Criar array de strings dinâmicamente
    recent_ride = malloc(10001 * sizeof(char*));
    for (int i = 0; i < 10001; i++)
        recent_ride[i] = malloc((11+1) * sizeof(char));

    for (int i = 0; i <= 10000; i++) strcpy(recent_ride[i], "00/00/0000");                // Inicializar a array

    for (int i = 1; i <= 1000000; i++) {                                                  // Percorrer o catálogo das rides
        if (strcmp(drivers_cat[atoi(rides_cat[i].driver)].status, "active") == 0) {       // Verificar se o Driver está ativo
            int ind_driver = atoi(rides_cat[i].driver);                                   // Calcular índice do driver pretendido
            tot_avaliacoes[ind_driver] += atof(rides_cat[i].score_driver);                // Aumentar o total de avaliações do driver pretendido
            num_viagens[ind_driver]++;                                                    // Incrementar o número de viagens do driver pretendido
            if (most_recent(rides_cat[i].date, recent_ride[ind_driver]) == 1) strcpy(recent_ride[ind_driver], rides_cat[i].date);
        }
    }

    for (int i = 1; i <= 10000; i++) {                                                    // Calcular a avaliação média para cada Driver armazenando na array av_med
        if (num_viagens[i] != 0) av_med[i] = tot_avaliacoes[i] / num_viagens[i];
        else av_med[i] = 0;
    }

    for (int i = 1; i <= 10000; i++) av_med_cpy[i] = av_med[i];                       // Clonar a array de avaliações médias para ser usado no for loop

    int *id_maiores; id_maiores = calloc(N, sizeof(int));                           // Array que irá armazenar os ID's ordenados por ordem decrescente de maior av_med
    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher id_maiores
        int larg_av_ind = larger_double(av_med_cpy, 10001);
        id_maiores[i] = larg_av_ind;
        av_med_cpy[larg_av_ind] = 0;
    }

    for (int i = 0; i < N-1; i++) {
        if (av_med[id_maiores[i]] == av_med[id_maiores[i+1]]) {
            int rec_ride = most_recent(recent_ride[id_maiores[i]], recent_ride[id_maiores[i+1]]);
            if (rec_ride == 2) swap(id_maiores, i, i+1);
            else if (rec_ride == 3 && id_maiores[i] > id_maiores[i+1]) swap(id_maiores, i, i+1);
        }
    }

    for (int i = N-1; i >= 0; i--) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char *output; output = malloc(500 * sizeof(char));
        sprintf(output, "%s;%s;%.3f\n", drivers_cat[id_maiores[i]].id, drivers_cat[id_maiores[i]].name, av_med[id_maiores[i]]);
        handle_outputs(counter, output);
        free(output);
    }

    free(tot_avaliacoes);
    free(num_viagens);
    free(av_med);
    free(av_med_cpy);
    for(int i = 0; i <= 10000; i++) free(recent_ride[i]);
    free(recent_ride);
    free(id_maiores);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q2 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
}