/**
 * @file file_inputs.c
 * Este ficheiro abre o ficheiro inputs.txt.
 * 
 */

#include "../include/file_inputs.h"

FILE* open_file_inputs(char *inputs_path) {

    FILE *inputs;
        inputs = fopen(inputs_path, "r");
        if (inputs != NULL) puts("Ficheiro dos Inputs aberto\n");

    return inputs;
}