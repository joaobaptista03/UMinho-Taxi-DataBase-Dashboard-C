/**
 * @file query4.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 4.
 * 
 */

#include "../include/query4.h"

void query4 (int counter, char *cidade, int mode) {
    
    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    double preco = 0;
    int contagem = 0;

    for (int i = 1; i <= get_nr_rides(); i++) {
        if (stricmp(get_ride_city(i), cidade) == 0) {
            int distance = atoi(get_ride_distance(i));
            char *class; class = malloc(10 * sizeof(char));
            strcpy(class, get_driver_car_class(get_ride_driver(i)));

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

            preco += taxa_dist * distance + taxa_base;
            contagem++;

            free(class);
        }
    }
    
    if (contagem == 0) {
        // Medição de tempo
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        if (mode == 1) puts("\nResultado: Não há viagens!\n");
        if (mode == 0) handle_outputs(counter, "");
        if ((mode == 1) || (mode == 3)) printf("Fim da Q4 (Sem viagens) - %f segundos(input nº %i)\n", cpu_time_used, counter);
        return;
    }
    
    char output[150];
    double resultado = preco/contagem;
    sprintf(output, "%.3f\n", resultado);
    
    if (mode == 1) printf("\nForma do Resultado: preco_medio");
    if (mode == 1) printf("\nResultado: %s\n",output);
    
    if (mode == 0) handle_outputs(counter,output);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if ((mode == 1) || (mode == 3)) printf("Fim da Q4 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}