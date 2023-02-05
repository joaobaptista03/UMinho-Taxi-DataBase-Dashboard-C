/**
 * @file query5.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 5.
 * 
 */

#include "../include/query5.h"

void query5 (int counter, char *data1, char* data2, int mode) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    data1[10] = '\0';
    
    double preco = 0;
    int contagem = 0;

    for(int i = 0; i < get_nr_rides(); i++) {
        
        char *sortedridedate = get_sorted_ride_date(i);

        if (most_recent(data1, sortedridedate) == 1) {
            free(sortedridedate);
            break;
        }

        if ((most_recent(sortedridedate, data2) == 2 || most_recent(sortedridedate, data2) == 3)) {

            char *sortedridedriver = get_sorted_ride_driver(i);
            char *class = get_driver_car_class(sortedridedriver);

            float taxa_base, taxa_dist;
            if (stricmp(class, "basic") == 0) {
                taxa_base = 3.25;
                taxa_dist = 0.62;
            }
            else if (stricmp(class, "green") == 0) {
                taxa_base = 4;
                taxa_dist = 0.79;
            }
            else if (stricmp(class, "premium") == 0) {
                taxa_base = 5.2;
                taxa_dist = 0.94;
            }
            contagem++;

            char *sortedridedistance = get_sorted_ride_distance(i);
            preco += taxa_dist * atoi(sortedridedistance) + taxa_base;
            free(sortedridedistance);

            free(class); free(sortedridedriver);
        }

        free(sortedridedate);
    }
    
    if (contagem == 0) {
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        if (mode == 1) printf("\nNão há viagens!\n\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        if ((mode == 1) || (mode == 3)) printf("Fim da Q5 (Sem viagens) - %f segundos (input nº %i)\n", cpu_time_used, counter);
        return;
    }
    
    char output[150];
    double resultado = preco/contagem;
    sprintf(output, "%.3f\n", resultado);
    if (mode == 1) printf("\nForma do Resultado: preco_medio\n");
    if (mode == 1) printf("Resultado: %s\n",output);
    if ((mode == 0) || (mode == 3)) handle_outputs(counter,output);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if ((mode == 1) || (mode == 3)) printf("Fim da Q5 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}