/**
 * @file query5.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 6.
 * 
 */

#include "../include/query6.h"

void query6 (int counter, Ride *rides_cat, char *input) {
    printf("A executar Q6 (linha de input %i)\n", counter);
    
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

    for(int i = 1; i <= 1000000; i++) {
        
        if ((most_recent(rides_cat[i].date, data1) == 1 || most_recent(rides_cat[i].date, data1) == 3)
        &&  (most_recent(rides_cat[i].date, data2) == 2 || most_recent(rides_cat[i].date, data2) == 3)
        && strcmp(rides_cat[i].city, city) == 0) {
            contagem++;
            distance += atoi(rides_cat[i].distance);
        }
    }

    char *output; output = malloc(100 * sizeof(char));
    
    if (contagem == 0) {
        handle_outputs(counter, "");
        printf("Fim da Q6 (linha de input %i)\n", counter);
        return;
    }
    
    double resultado = (double) distance/contagem;
    sprintf(output, "%.3f\n", resultado);
    handle_outputs(counter,output);

    free(output);


    printf("Fim da Q6 (linha de input %i)\n", counter);
}