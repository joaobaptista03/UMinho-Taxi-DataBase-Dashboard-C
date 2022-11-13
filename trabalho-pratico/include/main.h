/**
 * @file main.h
 * Este ficheiro contém a informações importantes da main para outros ficheiros.
 * 
 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <glib.h>

#include "structs.h"
#include "query1.h"
#include "age_time.h"

FILE *drivers;
FILE *users;
FILE *rides;
FILE *inputs;

/**
 *
 * Este é o header da função principal que executa o programa.
 * 
 */
int main();

#endif