/**
 * @file query6.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 6.
 * 
 */

#include "../include/query6.h"

void query6 (int counter, char *input, int mode) {

    // Medição de tempo
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

    for(int i = 1; i <= get_nr_rides(); i++) {
        
        if ((most_recent(get_ride_date(i), data1) == 1 || most_recent(get_ride_date(i), data1) == 3)
        &&  (most_recent(get_ride_date(i), data2) == 2 || most_recent(get_ride_date(i), data2) == 3)
        && stricmp(get_ride_city(i), city) == 0) {
            contagem++;
            distance += atoi(get_ride_distance(i));
        }
    }
    
    if (contagem == 0) {
        // Medição de tempo
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        free(city);
        free(data1);
        free(data2);
        
        if (mode == 1) printf("\nNão há viagens!\n\n");
        if (mode == 0) handle_outputs(counter, "");
        if (mode == 1) printf("Fim da Q6 (Sem viagens) - %f segundos(input nº %i)\n", cpu_time_used, counter);
        return;
    }

    char output[150];
    double resultado = (double) distance/contagem;
    sprintf(output, "%.3f\n", resultado);
    if (mode == 1) puts("\nForma do Resultado: distancia_media");
    if (mode == 1) printf("Resultado: %s\n",output);
    if (mode == 0) handle_outputs(counter,output);

    free(city);
    free(data1);
    free(data2);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("Fim da Q6 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}