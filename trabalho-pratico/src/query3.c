/**
 * @file query3.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 3.
 * 
 */

#include "../include/query3.h"

void query3 (int counter, char *N_arg, int mode) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    int N = atoi(N_arg);
    if (N == 0) {
        if (mode == 1) puts("\nResultado: N = 0\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        if ((mode == 1) || (mode == 3)) printf("Fim da Q3 - %f segundos (input nº %i)\n", cpu_time_used, counter);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    if (mode == 1) puts("\nForma do Resultado: username;nome;distancia_total");
    for (int i = 0, j = 0; i < N; j++) {
        
        char *user_username = get_user_username(get_sorted_user(j));
        char *userstatus = get_user_status(user_username);
        if (stricmp(userstatus, "active") == 0) {
            char output[150];
            char *username = get_user_name(user_username);
            sprintf(output, "%s;%s;%d\n", user_username, username, get_user_dist_total(get_sorted_user(j)));
            free(username);
            if (mode == 1) printf("%s",output);
            if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
       
            i++;
        }
        free(user_username); free(userstatus);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    if ((mode == 1) || (mode == 3)) printf("Fim da Q3 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}