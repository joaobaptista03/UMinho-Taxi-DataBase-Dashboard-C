/**
 * @file query7.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 7.
 * 
 */

#include "../include/query7.h"

void query7 (int counter, char *input, int mode) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int N = atoi(input);
    if (N == 0) {
        if (mode == 1) puts("\nResultado: N = 0\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        if ((mode == 1) || (mode == 3)) printf("Fim da Q7 - %f segundos (input nº %i)\n", cpu_time_used, counter);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    char *cidaded;
    cidaded = strstr(input, " ");
    char cidade[20];
    strcpy(cidade, cidaded + 1);

    int *tot_avaliacoes; tot_avaliacoes = calloc((1 + get_n_drivers()), sizeof(int));
    int *num_viagens; num_viagens = calloc((1 + get_n_drivers()), sizeof(int));
    double *av_med; av_med = calloc((1 + get_n_drivers()), sizeof(double));
    double *av_med_cpy; av_med_cpy = calloc((1 + get_n_drivers()), sizeof(double));

    for (int i = 0; i < get_city_nr_rides(cidade); i++) {
        if ((stricmp(get_driver_status(get_city_ride_driver(cidade, i)), "active") == 0)) {
            tot_avaliacoes[get_driver_i(get_city_ride_driver(cidade, i))] += atoi(get_city_ride_score_driver(cidade, i));
            num_viagens[get_driver_i(get_city_ride_driver(cidade, i))]++;
        }
    }

    for (int i = 1; i <= get_n_drivers(); i++) {
        if (num_viagens[i] != 0) av_med[i] = (double) tot_avaliacoes[i] / num_viagens[i];
        else av_med[i] = 0;
    }

    for (int i = 1; i <= get_n_drivers(); i++) av_med_cpy[i] = av_med[i];

    int *id_maiores; id_maiores = calloc(N, sizeof(int));
    for (int i = 0; i < N-1; i++) {
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
        if (curr_elem != 1) qsort(id_maiores + i, curr_elem, sizeof(int), first_driver7);
    }

    if (mode == 1) puts("\nForma do Resultado: id;nome;avaliacao_media");
    for (int i = 0; i < N; i++) {
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
    free(id_maiores);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    if ((mode == 1) || (mode == 3)) printf("Fim da Q7 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}