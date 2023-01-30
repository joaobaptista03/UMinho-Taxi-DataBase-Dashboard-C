/**
 * @file query2.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 2.
 * 
 */

#include "../include/query2.h"

char **recent_ride;                                                                   // Criar array de strings dinâmicamente


void query2 (int counter, char *N_arg, int mode) {

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int N = atoi(N_arg);                                                      // Converter argumento N string para int
    if (N == 0) {
        if (mode == 1) puts("\nResultado: N = 0\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        if ((mode == 1) || (mode == 3)) printf("Fim da Q2 - %f segundos (input nº %i)\n", cpu_time_used, counter);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    // Criar todas as arrays temporárias necessárias à função 
    double *tot_avaliacoes; tot_avaliacoes = calloc((1 + get_n_drivers()), sizeof(double));
    int *num_viagens; num_viagens = calloc((1 + get_n_drivers()), sizeof(int));
    double *av_med; av_med = calloc((1 + get_n_drivers()), sizeof(double));
    double *av_med_cpy; av_med_cpy = calloc((1 + get_n_drivers()), sizeof(double));

    recent_ride = malloc((1 + get_n_drivers()) * sizeof(char*));
    for (int i = 0; i < (1 + get_n_drivers()); i++)
        recent_ride[i] = malloc((11+1) * sizeof(char));

    for (int i = 0; i <= get_n_drivers(); i++) strcpy(recent_ride[i], "00/00/0000");                // Inicializar a array

    for (int i = 1; i <= get_nr_rides(); i++) {                                                  // Percorrer o catálogo das rides
        if (stricmp(get_driver_status(get_ride_driver(i)), "active") == 0) {       // Verificar se o Driver está ativo
            tot_avaliacoes[get_driver_i(get_ride_driver(i))] += atof(get_ride_score_driver(i));                // Aumentar o total de avaliações do driver pretendido
            num_viagens[get_driver_i(get_ride_driver(i))]++;                                                    // Incrementar o número de viagens do driver pretendido
            if (most_recent(get_ride_date(i), recent_ride[get_driver_i(get_ride_driver(i))]) == 1) strcpy(recent_ride[get_driver_i(get_ride_driver(i))], get_ride_date(i));
        }
    }

    for (int i = 1; i <= get_n_drivers(); i++) {                                                    // Calcular a avaliação média para cada Driver armazenando na array av_med
        if (num_viagens[i] != 0) av_med[i] = tot_avaliacoes[i] / num_viagens[i];
        else av_med[i] = 0;
    }

    for (int i = 1; i <= get_n_drivers(); i++) av_med_cpy[i] = av_med[i];                       // Clonar a array de avaliações médias para ser usado no for loop

    int *id_maiores; id_maiores = calloc(N, sizeof(int));                           // Array que irá armazenar os ID's ordenados por ordem decrescente de maior av_med
    for (int i = 0; i < N-1; i++) {                                                     // For loop que irá preencher id_maiores
        int larg_av_ind = larger_double(av_med_cpy, (1 + get_n_drivers()));

        if (larg_av_ind == -1) {
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if (mode == 1) puts("\nResultado: Não existem Rides suficientes!\n");
            if ((mode == 1) || (mode == 3)) printf("Fim da Q2 (Sem Rides Suficientes) - %f segundos (input nº %i)\n", cpu_time_used, counter);
            if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
            return;
        }

        id_maiores[i] = atoi(get_driver_id(larg_av_ind));
        av_med_cpy[larg_av_ind] = 0;
    }

    int last_av_i = larger_double(av_med_cpy, (1 + get_n_drivers()));
    int aux_av_i = last_av_i;
    double last_av = av_med_cpy[last_av_i];
    int cap = N, nr_maiores = N-1;

    for(; av_med_cpy[aux_av_i] == last_av; nr_maiores++) {
        if (nr_maiores + 1 > cap) {
            id_maiores = realloc(id_maiores, (cap + 5) * sizeof(int));
            cap += 5;
        }
        id_maiores[nr_maiores] = atoi(get_driver_id(aux_av_i));
        av_med_cpy[aux_av_i] = 0;
        aux_av_i = larger_double(av_med_cpy, (1 + get_n_drivers()));
    }

    int curr_elem;
    for (int i = 0; i < nr_maiores - 1; i += curr_elem) {
        char id_temp[13]; sprintf(id_temp, "%012d", id_maiores[i]);
        curr_elem = av_elem(id_maiores, nr_maiores, av_med, av_med[get_driver_i(id_temp)]);
        if (curr_elem != 1) qsort(id_maiores + i, curr_elem, sizeof(int), first_driver);
    }

    if (mode == 1) puts("\nForma do Resultado: id;nome;avaliacao_media");
    for (int i = 0; i < N; i++) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[150];
        char id_i[30]; sprintf(id_i, "%012d", id_maiores[i]);
        sprintf(output, "%s;%s;%.3f\n", id_i, get_driver_name(id_i), av_med[get_driver_i(id_i)]);
        if (mode == 1) printf("%s",output);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
    }

    free(tot_avaliacoes);
    free(num_viagens);
    free(av_med);
    free(av_med_cpy);
    for(int i = 0; i <= get_n_drivers(); i++) free(recent_ride[i]);
    free(recent_ride);
    free(id_maiores);
    
    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    if ((mode == 1) || (mode == 3)) printf("Fim da Q2 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}

char* get_recdate_driver(char *id) {
    return recent_ride[get_driver_i(id)];
}