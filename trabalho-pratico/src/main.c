/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include "../include/batch.h"
#include "../include/interactive.h"

int main(int argc, char *argv[]) {

    clock_t start;

    if (argc == 1) {
        start = clock();  
        puts("Número de argumentos válido! (3)\n");
        interactive();
    }

    else if (argc == 3) {
        start = clock();
        system("mkdir Resultados");
        puts("\nDiretório Resultados criado\n");        
        puts("Número de argumentos válido! (3)\n");
        batch(argv);
    }

    else {
        printf("\nNúmero de argumentos inválido (%i).\n", argc);
        return -1;
    }
    
    puts("");
    
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n\n", cpu_time_used );
    
    return 0;
}
