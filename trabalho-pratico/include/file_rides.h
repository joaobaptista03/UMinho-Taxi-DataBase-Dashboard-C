/**
 * @file file_rides.h
 * Este ficheiro contém a função que abre o ficheiro rides.csv.
 * 
 */

#ifndef FILE_RIDES_H
#define FILE_RIDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* open_file_rides(char *csv_path);

#endif