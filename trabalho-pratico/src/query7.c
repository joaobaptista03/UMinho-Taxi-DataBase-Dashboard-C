/**
 * @file query7.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 7.
 * 
 */

#include "../include/query7.h"

void query7 (int counter, Driver *drivers_cat, GHashTable *drivers_hash, Ride *rides_cat, char *input, int mode) {
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
    double *tot_avaliacoes; tot_avaliacoes = calloc((1 + atoi(drivers_cat[0].id)), sizeof(double));
    int *num_viagens; num_viagens = calloc((1 + atoi(drivers_cat[0].id)), sizeof(int));
    double *av_med; av_med = calloc((1 + atoi(drivers_cat[0].id)), sizeof(double));
    double *av_med_cpy; av_med_cpy = calloc((1 + atoi(drivers_cat[0].id)), sizeof(double));


    for (int i = 1; i <= atoi(rides_cat[0].id); i++) {                                                  // Percorrer o catálogo das rides
        if ((stricmp(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, rides_cat[i].driver))].status, "active") == 0) && (stricmp(rides_cat[i].city, cidade) == 0)) {       // Verificar se o Driver está ativo
            tot_avaliacoes[atoi(g_hash_table_lookup(drivers_hash, rides_cat[i].driver))] += atof(rides_cat[i].score_driver);                // Aumentar o total de avaliações do driver pretendido
            num_viagens[atoi(g_hash_table_lookup(drivers_hash, rides_cat[i].driver))]++;                                                    // Incrementar o número de viagens do driver pretendido
        }
    }

    for (int i = 1; i <= atoi(drivers_cat[0].id); i++) {                                                    // Calcular a avaliação média para cada Driver armazenando na array av_med
        if (num_viagens[i] != 0) av_med[i] = tot_avaliacoes[i] / num_viagens[i];
        else av_med[i] = 0;
    }

    for (int i = 1; i <= atoi(drivers_cat[0].id); i++) av_med_cpy[i] = av_med[i];                       // Clonar a array de avaliações médias para ser usado no for loop

    int *id_maiores; id_maiores = calloc(N, sizeof(int));                           // Array que irá armazenar os ID's ordenados por ordem decrescente de maior av_med
    for (int i = 0; i < N; i++) {                                                     // For loop que irá preencher id_maiores
        int larg_av_ind = larger_double(av_med_cpy, (1 + atoi(drivers_cat[0].id)));
        id_maiores[i] = atoi(drivers_cat[larg_av_ind].id);
        av_med_cpy[larg_av_ind] = 0;
    }

    if (mode == 1) puts("Forma do Resultado: id;nome;avaliacao_media");
    for (int i = 0; i < N; i++) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char *output; output = malloc(70 * sizeof(char));
        char id_i[30]; sprintf(id_i, "%012d", id_maiores[i]);
        sprintf(output, "%s;%s;%.3f\n", drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id_i))].id, drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id_i))].name, av_med[id_maiores[i]]);
        if (mode == 1) printf("%s",output);
        handle_outputs(counter, output);
        free(output);
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
