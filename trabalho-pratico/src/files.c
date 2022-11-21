/**
 * @file files.c
 * Este ficheiro abre os ficheiros de input.
 * 
 */

#include "../include/files.h"

FILE* open_files(char *path, char *filename) {
    
    FILE *file;
        char *filepath;
        filepath = (char *) malloc(1000 * sizeof(char));
        strcpy(filepath, path);
        strcat(filepath, filename);
        file = fopen(filepath, "r");
        free(filepath);
        if (file != NULL) puts("Ficheiro dos Users aberto");
        else puts("Erro na abertura do ficheiro dos Users");

    return file;
}