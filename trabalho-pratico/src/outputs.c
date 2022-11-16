/**
 * @file outputs.c
 * Este ficheiro contém a função que trata de cada output e cria um ficheiro para escrever os mesmos.
 * 
 */

#include "../include/outputs.h"

void handle_outputs(int counter, char *output) {
    char filename[50];
    sprintf(filename, "Resultados/command%i_output.txt", counter);

    FILE *new_output;
        new_output = fopen(filename, "a");
    fprintf(new_output, "%s", output);
}