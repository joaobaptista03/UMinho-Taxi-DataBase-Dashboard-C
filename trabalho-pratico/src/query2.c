/**
 * @file query2.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 2.
 * 
 */

#include "../include/query2.h"

/* TO DO - ORDEM DE DESENPATE:
    1 - VIAGEM MAIS RECENTE
    2 - ID DO DRIVER POR ORDEM CRESCENTE
*/

void query2 (int counter, Driver *drivers_cat, User *users_cat, Ride *rides_cat, char *N_arg) {
    int N = atoi(N_arg);                                                      // Converter argumento N string para int

    // Criar todas as arrays temporárias necessárias à função 
    double tot_avaliacoes[10001];
    int num_viagens[10001];
    double av_med[10001], av_med_cpy[10001];

    for (int i = 1; i <= 1000000; i++) {                                              // Percorrer o catálogo das rides
        int ind_driver = atoi(rides_cat[i].driver);                                   // Calcular índice do driver pretendido
        tot_avaliacoes[ind_driver] += atof(rides_cat[i].score_driver);                // Aumentar o total de avaliações do driver pretendido
        num_viagens[ind_driver]++;                                                    // Incrementar o número de viagens do driver pretendido
    }

    for (int i = 1; i <= 10000; i++) av_med[i] = tot_avaliacoes[i] / num_viagens[i];  // Calcular a avaliação média para cada Driver armazenando na array av_med

    int id_maiores[N];                                                                // Array que irá armazenar os ID's ordenados por ordem decrescente de maior av_med

    for (int i = 1; i <= 10000; i++) av_med_cpy[i] = av_med[i];                       // Clonar a array de avaliações médias para ser usado no for loop
    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher id_maiores
        int larg_av_ind = larger_double(av_med_cpy, 10001);
        id_maiores[i] = larg_av_ind;
        av_med_cpy[larg_av_ind] = 0;
    }

    for (int i = N-1; i >= 0; i--) {                                                  // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[500];
        sprintf(output, "%s;%s;%.3f\n", drivers_cat[id_maiores[i]].id, drivers_cat[id_maiores[i]].name, av_med[id_maiores[i]]);
        handle_outputs(counter, output);
    }
}