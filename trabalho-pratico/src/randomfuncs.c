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

int larger_int(int *ints, int N) {
    int r = 0; int ind;
    for (int i = 1; i < N; i++) {
        if (ints[i] > r) {
            r = ints[i];
            ind = i;
        }
    }
    return ind;
}

int most_recent(char *date1, char *date2) {
    int year1 = date1[6]*1000 + date1[7]*100 + date1[8]*10 + date1[9];
    int year2 = date2[6]*1000 + date2[7]*100 + date2[8]*10 + date2[9];
    int month1 = date1[3]*10 + date1[4];
    int month2 = date2[3]*10 + date2[4];
    int day1 = date1[0]*10 + date1[1];
    int day2 = date2[0]*10 + date2[1];
    if (year1 > year2) return 1;
    if (year1 < year2) return 2;
    if (month1 > month2) return 1;
    if (month1 < month2) return 2;
    if (day1 > day2) return 1;
    if (day1 < day2) return 2;
    return 3;
}

double arred3(double x) {
    char temp[15];
    sprintf(temp, "%f", x);
    if (temp[5] >= 5) temp[4]++;
    temp[5] = '\0';
    return atof(temp);
}

void swap(int *x, int i, int j) {
    int temp = x[i];
    x[i] = x[j];
    x[i+1] = temp;
}