/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include "../include/batch.h"

int main(int argc, char *argv[]) {

    clock_t start;

    if (argc == 1) {
        // Medição de tempo
        start = clock();
    }

    else if (argc == 3) {
        // Medição de tempo
        start = clock();

        system("mkdir Resultados");                                               // Criar diretório para os Resultados
        puts("Diretório Resultados criado\n");        

        batch (argv);
        puts("\nNúmero de argumentos válido! (3)");
    }

    else {
        printf("\nNúmero de argumentos inválido (%i).\n", argc);
        return -1;
    }

    puts("");

    // Medição de tempo
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n\n", cpu_time_used );
    
    return 0;
}
