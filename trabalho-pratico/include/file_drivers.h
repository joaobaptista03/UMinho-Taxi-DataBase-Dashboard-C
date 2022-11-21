/**
 * @file file_drivers.h
 * Este ficheiro contém a função que abre o ficheiro drivers.csv.
 * 
 */

#ifndef FILE_DRIVERS_H
#define FILE_DRIVERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* open_file_drivers(char *csv_path);

#endif