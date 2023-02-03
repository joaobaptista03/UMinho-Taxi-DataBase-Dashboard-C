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
    int r = 0; int ind = -1;
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
    int ch1, ch2;
    int same = 1;
    while (((ch1 = fgetc(file1)) != EOF) && ((ch2 = fgetc(file2)) != EOF)) {
        if (ch1 != ch2) {
            same = 0;
            break;
        }
    }
    if (same) {
        if (fgetc(file1) == EOF && fgetc(file2) == EOF) same = 1;
        else same = 0;
    }
    return same;
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

int first_ride(const void *i1, const void *i2) {
    int *a = (int*)i1;
    int *b = (int*)i2;

    int mostrecent_d = most_recent(get_driver_acc_creation(get_ride_driver(*a)), get_driver_acc_creation(get_ride_driver(*b)));
    int mostrecent_u = most_recent(get_user_acc_creation(get_ride_user(*a)), get_user_acc_creation(get_ride_user(*b)));

    if (mostrecent_d == 1) return 1;
    if (mostrecent_d == 2) return -1;
    if (mostrecent_u == 1) return 1;
    if (mostrecent_u == 2) return -1;
    return (*a - *b);
}

int first_ride9(const void *i1, const void *i2) {
    int *a = (int*)i1;
    int *b = (int*)i2;

    if (atoi(get_ride_distance(*a)) > atoi(get_ride_distance(*b))) return -1;
    else if (atoi(get_ride_distance(*a)) < atoi(get_ride_distance(*b))) return 1;

    int mostrecent = most_recent(get_ride_date(*a), get_ride_date(*b));
    if (mostrecent == 1) return -1;
    else if (mostrecent == 2) return 1;

    return (*b - *a);
}

double total_gasto_auferido(char *class, int distance, double tip) {
    double taxa_base = 0, taxa_dist = 0;

    if (stricmp(class, "basic") == 0) {
        taxa_base = 3.25;
        taxa_dist = 0.62;
    }
    else if (stricmp(class, "green") == 0) {
            taxa_base = 4;
            taxa_dist = 0.79;
    }
    else if (stricmp(class, "premium") == 0) {
            taxa_base = 5.2;
            taxa_dist = 0.94;
    }

    return taxa_base + (taxa_dist * distance) + tip;
}

int sort_rides (const void *i1, const void *i2) {
    int *a = (int*)i1;
    int *b = (int*)i2;

    int mostrecent = most_recent(get_ride_date(*a), get_ride_date(*b));
    if (mostrecent == 1) return -1;
    return 1;
}