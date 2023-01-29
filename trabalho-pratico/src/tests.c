/**
 * @file tests.c
 *  Este ficheiro contém as funções relacionadas com os testes funcionais e de desempenho.
 * 
 */

#include "../include/tests.h"

void q1_test(int counter, char *id) {
    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    query1(counter, id, 3);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q1 - %f segundos (input nº %i)\n", cpu_time_used);
}

int main() {
    
}