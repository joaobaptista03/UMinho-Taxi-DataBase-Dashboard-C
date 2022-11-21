/**
 * @file query5.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 5.
 * 
 */

#include "../include/query5.h"

void query5 (int counter, Driver *drivers_cat, Ride *rides_cat, char *data1, char* data2) {
    printf("\nA executar Q5 (linha de input %i)\n", counter);

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    data1[10] = '\0';
    
    double preco = 0;
    int contagem = 0;

    for(int i = 1; i <= 1000000; i++) {
        
        if (most_recent(rides_cat[i].date, data1) == 1 && most_recent(rides_cat[i].date, data2) == 2) {

            char *class; class = malloc(10 * sizeof(char));
            strcpy(class, drivers_cat[atoi(rides_cat[i].driver)].car_class);

            float taxa_base, taxa_dist;
            if (strcmp(class, "basic") == 0) {
                taxa_base = 3.25;
                taxa_dist = 0.62;
            }
            else if (strcmp(class, "green") == 0) {
                taxa_base = 4;
                taxa_dist = 0.79;
            }
            else if (strcmp(class, "premium") == 0) {
                taxa_base = 5.2;
                taxa_dist = 0.94;
            }
            contagem++;
            preco += taxa_dist * atoi(rides_cat[i].distance) + taxa_base;

            free(class);

        }
    }

    char *output; output = malloc(100 * sizeof(char));
    
    if (contagem == 0) {
        // Medição de tempo
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        handle_outputs(counter, "");
        printf("Fim da Q5 (Sem viagens) - %f segundos(linha de input %i)\n", cpu_time_used, counter);
        return;
    }
    
    double resultado = preco/contagem;
    sprintf(output, "%.3f\n", resultado);
    handle_outputs(counter,output);

    free(output);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q1 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
}