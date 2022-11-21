/**
 * @file file_users.c
 * Este ficheiro abre o ficheiro users.csv.
 * 
 */

#include "../include/file_users.h"

FILE* open_file_users(char *csv_path) {
    
    FILE *users;
        char *userspath;
        userspath = (char *) malloc(1000 * sizeof(char));
        strcpy(userspath, csv_path);
        strcat(userspath, "/users.csv");
        users = fopen(userspath, "r");
        free(userspath);
        if (users != NULL) puts("Ficheiro dos Users aberto");
        else puts("Erro na abertura do ficheiro dos Users");

    return users;
}