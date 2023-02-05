/**
 * @file query6.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 6.
 * 
 */

#include "../include/query6.h"

void query6 (int counter, char *input, int mode) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    int i;
    char *city; city = malloc(20 * sizeof(char));
    for (i = 0; input[i] != ' '; i++) city[i] = input[i]; 
    city[i] = '\0';

    char *data1; data1 = malloc(20 * sizeof(char));
    memcpy(data1, input + 1 + i, 10); data1[10] = '\0';

    char *data2; data2 = malloc(20 * sizeof(char));
    memcpy(data2, input + i + 2 + 10, 10); data2[10] = '\0';

    int distance = 0;
    int contagem = 0;

    for(int i = 0; (i < get_city_nr_rides(city)); i++) {

        char *cityridedate = get_city_i_ride_date(city, i);
        if (most_recent(data1, cityridedate) == 1) {
            free(cityridedate);
            break;   
        }
        
        if ((most_recent(cityridedate, data2) == 2 || most_recent(cityridedate, data2) == 3)) {
            contagem++;
            distance += atoi(get_city_i_ride_distance(city, i));
        }
        free(cityridedate);
    }
    
    if (contagem == 0) {
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        free(city);
        free(data1);
        free(data2);
        
        if (mode == 1) printf("\nNão há viagens!\n\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        if ((mode == 1) || (mode == 3)) printf("Fim da Q6 (Sem viagens) - %f segundos (input nº %i)\n", cpu_time_used, counter);
        return;
    }

    char output[150];
    double resultado = (double) distance/contagem;
    sprintf(output, "%.3f\n", resultado);
    if (mode == 1) puts("\nForma do Resultado: distancia_media");
    if (mode == 1) printf("Resultado: %s\n",output);
    if ((mode == 0) || (mode == 3)) handle_outputs(counter,output);

    free(city);
    free(data1);
    free(data2);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if ((mode == 1) || (mode == 3)) printf("Fim da Q6 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}