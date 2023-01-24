/**
 * @file query4.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 4.
 * 
 */

#include "../include/query4.h"

void query4 (int counter, Driver *drivers_cat, GHashTable *drivers_hash, Ride *rides_cat, char *cidade, int mode) {
    printf("\nA executar Q4 (linha de input %i)\n", counter);

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    double preco = 0;
    int contagem = 0;

    for (int i = 1; i <= atoi(rides_cat[0].id); i++) {
        if (stricmp(rides_cat[i].city, cidade) == 0) {
            int distance = atoi(rides_cat[i].distance);
            char *class; class = malloc(10 * sizeof(char));
            strcpy(class, get_driver_car_class(rides_cat[i].driver));

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
        handle_outputs(counter, "");
        printf("Fim da Q4 (Sem viagens) - %f segundos(linha de input %i)\n", cpu_time_used, counter);
        return;
    }
    
    char *output; output = malloc(70 * sizeof(char));
    double resultado = preco/contagem;
    sprintf(output, "%.3f\n", resultado);
    
    if (mode == 1) printf("\nForma do Resultado: preco_medio");
    if (mode == 1) printf("\nResultado: %s\n",output);
    
    handle_outputs(counter,output);

    free(output);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q4 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
}