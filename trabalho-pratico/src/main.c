/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include <stdio.h>
#include <string.h>

#include "../include/files.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("\nNúmero de argumentos inválido (%i).\n", argc);
        return -1;
    }
    else puts("\nNúmero de argumentos válido! (3)");

    puts("");
    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    puts("Diretório Resultados criado\n");

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    open_files(argv[1], argv[2]);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n\n", cpu_time_used );
    
    return 0;
}
