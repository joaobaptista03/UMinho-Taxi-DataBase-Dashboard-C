/**
 * @file randomfuncs.c
 * 
 * Este ficheiro contém o conteúdo das funções aleatórias que podem ser usadas em vários assuntos.
 * 
 */

#include "../include/randomfuncs.h"

int isDriver(char str[], int N) {
    for (int i = 0; i < N; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int larger_double(double *doubles, int N) {
    double r = 0; int ind;
    for (int i = 1; i < N; i++) {
        if (doubles[i] > r) {
            r = doubles[i];
            ind = i;
        }
    }
    return ind;
}