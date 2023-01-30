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
    double r = 0; int ind = -1;
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

int stricmp(char const *a, char const *b) {
    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}

bool isInt (char *string) {
    if (strlen(string) == 0) return false;
    for(int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i])) return false;
    }
    return true;
}

bool isFloat (char *string) {
    if (strlen(string) == 0) return false;
    int nr_points = 0;
    for(int i = 0; i < strlen(string); i++) {
        if (string[i] == '.') {
            if (nr_points == 1) return false;
            nr_points++;
        }
        if (!isdigit(string[i]) && (string[i] != '.')) return false;
    }
    return true;
}

bool compare (FILE *file1, FILE *file2) {
    char input1[100], input2[100];
    while (fgets(input1, 100, file1) && fgets(input2, 100, file2)) {
        if (strcmp(input1, input2) != 0) return false;
    }
    return true;
}

int av_elem (int *id_maiores, int nr_maiores, double *av_med, double av) {
    int r = 0;
    for (int i = 0; i < nr_maiores; i++) {
        char id[13]; sprintf(id, "%012d", id_maiores[i]);
        if (av_med[get_driver_i(id)] == av) {
            r++;
        }
    }
    return r;
}

int dist_elem (int *user_maioresID, int nr_maiores, int *tot_distancia, int dist_total) {
    int r = 0;
    for (int i = 0; i < nr_maiores; i++) {
        if (tot_distancia[user_maioresID[i]] == dist_total) {
            r++;
        }
    }
    return r;
}

int first_driver(const void *i1, const void *i2) {
    int *a = (int*)i1;
    int *b = (int*)i2;

    char id1[13]; sprintf(id1, "%012d", *a);
    char id2[13]; sprintf(id2, "%012d", *b);

    int mostrecent = most_recent(get_recdate_driver(id1), get_recdate_driver(id2));
    if (mostrecent == 1) return -1;
    else if (mostrecent == 2) return 1;
    else if (mostrecent == 3) {
        if (atoi(id1) - atoi(id2) < 0) return -1;
    }
    return 1;
}

int first_user(const void *i1, const void *i2) {
    int *a = (int*)i1;
    int *b = (int*)i2;

    int mostrecent = most_recent(get_recdate_user(*a), get_recdate_user(*b));
    if (mostrecent == 1) return -1;
    else if (mostrecent == 2) return 1;
    else if (mostrecent == 3) {
        if (strcmp(get_user_username(*a), get_user_username(*b)) > 0) return 1;
    }
    return -1;
}

int first_driver7(const void *i1, const void *i2) {
    int *a = (int*)i1;
    int *b = (int*)i2;

    char id1[13]; sprintf(id1, "%012d", *a);
    char id2[13]; sprintf(id2, "%012d", *b);

    if (atoi(id1) - atoi(id2) < 0) return 1;
    return -1;
}