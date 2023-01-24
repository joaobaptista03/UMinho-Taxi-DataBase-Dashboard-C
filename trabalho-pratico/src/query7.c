/**
 * @file query7.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 7.
 * 
 */

#include "../include/query7.h"

void query7 (int counter, char *input, int mode) {
    printf("\nA executar Q7 (linha de input %i)\n", counter);
    if (mode == 1) printf("\n");

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int N = atoi(input);                                                      // Converter argumento N string para int
    
    char *cidaded;
    cidaded = strstr(input, " ");
    char cidade[20];
    strcpy(cidade, cidaded + 1);

    // Criar todas as arrays temporárias necessárias à função 
    double *tot_avaliacoes; tot_avaliacoes = calloc((1 + get_n_drivers()), sizeof(double));
    int *num_viagens; num_viagens = calloc((1 + get_n_drivers()), sizeof(int));
    double *av_med; av_med = calloc((1 + get_n_drivers()), sizeof(double));
    double *av_med_cpy; av_med_cpy = calloc((1 + get_n_drivers()), sizeof(double));


    for (int i = 1; i <= get_nr_rides(); i++) {                                                  // Percorrer o catálogo das rides
        if ((stricmp(get_driver_status(get_ride_driver(i)), "active") == 0) && (stricmp(get_ride_city(i), cidade) == 0)) {       // Verificar se o Driver está ativo
            tot_avaliacoes[get_driver_i(get_ride_driver(i))] += atof(get_ride_score_driver(i));                // Aumentar o total de avaliações do driver pretendido
            num_viagens[get_driver_i(get_ride_driver(i))]++;                                                    // Incrementar o número de viagens do driver pretendido
        }
    }

    for (int i = 1; i <= get_n_drivers(); i++) {                                                    // Calcular a avaliação média para cada Driver armazenando na array av_med
        if (num_viagens[i] != 0) av_med[i] = tot_avaliacoes[i] / num_viagens[i];
        else av_med[i] = 0;
    }

    for (int i = 1; i <= get_n_drivers(); i++) av_med_cpy[i] = av_med[i];                       // Clonar a array de avaliações médias para ser usado no for loop

    int *id_maiores; id_maiores = calloc(N, sizeof(int));                           // Array que irá armazenar os ID's ordenados por ordem decrescente de maior av_med
    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher id_maiores
        int larg_av_ind = larger_double(av_med_cpy, (1 + get_n_drivers()));
        id_maiores[i] = atoi(get_driver_id(larg_av_ind));
        av_med_cpy[larg_av_ind] = 0;
    }

    if (mode == 1) puts("Forma do Resultado: id;nome;avaliacao_media");
    for (int i = 0; i < N; i++) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[150];
        char id_i[30]; sprintf(id_i, "%012d", id_maiores[i]);
        sprintf(output, "%s;%s;%.3f\n", id_i, get_driver_name(id_i), av_med[get_driver_i(id_i)]);
        if (mode == 1) printf("%s",output);
        if (mode == 0) handle_outputs(counter, output);
    }

    free(tot_avaliacoes);
    free(num_viagens);
    free(av_med);
    free(av_med_cpy);
    free(id_maiores);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    printf("Fim da Q7 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
}
