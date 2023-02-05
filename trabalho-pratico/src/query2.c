/**
 * @file query2.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 2.
 * 
 */

#include "../include/query2.h"

void query2 (int counter, char *N_arg, int mode) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int N = atoi(N_arg);
    if (N == 0) {
        if (mode == 1) puts("\nResultado: N = 0\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        if ((mode == 1) || (mode == 3)) printf("Fim da Q2 - %f segundos (input nº %i)\n", cpu_time_used, counter);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    if (N > get_driver_nr_active()) {
        if (mode == 1) puts("\nResultado: Não existem N Drivers\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        if ((mode == 1) || (mode == 3)) printf("Fim da Q2 - %f segundos (input nº %i)\n", cpu_time_used, counter);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    if (mode == 1) puts("\nForma do Resultado: id;nome;avaliacao_media");
    for (int i = 0, j = 0; i < N; j++) {
        char id_i[13]; sprintf(id_i, "%012d", get_sorted_driver(j));
        char *driverstatus = get_driver_status(id_i);
        if (stricmp(driverstatus, "active") == 0) {
            char output[150];
            double av_med = 0;
            if (get_driver_nr_viagens(get_driver_i(id_i) != 0)) 
                av_med = (double) get_driver_av_total(get_driver_i(id_i)) / get_driver_nr_viagens(get_driver_i(id_i));
            
            char *drivername = get_driver_name(id_i);
            sprintf(output, "%s;%s;%.3f\n", id_i, drivername, av_med);
            free(drivername);
            if (mode == 1) printf("%s",output);
            if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);

            i++;
        }
        free(driverstatus);
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    if ((mode == 1) || (mode == 3)) printf("Fim da Q2 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}