/**
 * @file file_users.h
 * Este ficheiro contém a função que abre o ficheiro users.csv.
 * 
 */

#ifndef FILE_USERS_H
#define FILE_USERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* open_file_users(char *csv_path);

#endif