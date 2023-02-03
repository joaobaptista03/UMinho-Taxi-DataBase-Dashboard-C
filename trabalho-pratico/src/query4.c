/**
 * @file query4.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 4.
 * 
 */

#include "../include/query4.h"

void query4 (int counter, char *cidade, int mode) {
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    double preco_medio = get_city_preco_medio(cidade);

    if (preco_medio == 0) {
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        if (mode == 1) puts("\nResultado: Não há viagens!\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        if ((mode == 1) || (mode == 3)) printf("Fim da Q4 (Sem viagens) - %f segundos(input nº %i)\n", cpu_time_used, counter);
        return;
    }
    
    char output[150];
    sprintf(output, "%.3f\n", preco_medio);
    
    if (mode == 1) printf("\nForma do Resultado: preco_medio");
    if (mode == 1) printf("\nResultado: %s\n",output);
    
    if ((mode == 0) || (mode == 3)) handle_outputs(counter,output);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if ((mode == 1) || (mode == 3)) printf("Fim da Q4 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}