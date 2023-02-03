/**
 * @file stats.c
 * Este ficheiro contém as funções que fazem as Estatísticas das viagens.
 * 
 */

#include "../include/stats.h"

int *nr_viagens_d;
int *nr_viagens_u;
int *av_total_d;
int *av_total_u;
double *tot_auferido;
double *tot_gasto;
city* cities;
int nr_cities = 0;
int *rides_m, nr_rides_m = 0, cap_rides_m = 0;
int *rides_f, nr_rides_f = 0, cap_rides_f = 0;
int *sortedrides;

struct city {
    char *name;
    int nr_viagens;
    int cap;
    double total_price;
    int *rides;
};

int get_driver_nr_viagens(int indice) {
    return nr_viagens_d[indice];
}

int get_user_nr_viagens(int indice) {
    return nr_viagens_u[indice];
}

int get_driver_av_total(int indice) {
    return av_total_d[indice];
}

int get_user_av_total(int indice) {
    return av_total_u[indice];
}

double get_tot_auferido(int indice) {
    return tot_auferido[indice];
}

double get_tot_gasto(int indice) {
    return tot_gasto[indice];
}

double get_city_preco_medio(char *name) {
    for (int i = 0; i < nr_cities; i++) {
        if (stricmp(cities[i].name, name) == 0) {
            return cities[i].total_price / (double) cities[i].nr_viagens;
        }
    }
    return 0;
}

int get_city_nr_rides(char *name) {
    for (int i = 0; i < nr_cities; i++) {
        if (stricmp(cities[i].name, name) == 0) {
            return cities[i].nr_viagens;
        }
    }
    return 0;
}

char* get_city_ride_driver (char *name, int indice) {
    for (int i = 0; i < nr_cities; i++) {
        if (stricmp(cities[i].name, name) == 0) {
            return get_ride_driver(cities[i].rides[indice]);
        }
    }
    return NULL;
}

char* get_city_ride_score_driver (char *name, int indice) {
    for (int i = 0; i < nr_cities; i++) {
        if (stricmp(cities[i].name, name) == 0) {
            return get_ride_score_driver(cities[i].rides[indice]);
        }
    }
    return NULL;
}

int get_gender_nr_rides(char *gender) {
    if (stricmp(gender, "m") == 0) return nr_rides_m;
    else if (stricmp(gender, "f") == 0) return nr_rides_f;
    return 0;
}

char *get_gender_ride_driver(char *gender, int indice) {
    if (stricmp(gender, "m") == 0) {
        return get_ride_driver(rides_m[indice]);
    }
    if (stricmp(gender, "f") == 0) {
        return get_ride_driver(rides_f[indice]);
    }
    return NULL;
}

char *get_gender_ride_user(char *gender, int indice) {
    if (stricmp(gender, "m") == 0) {
        return get_ride_user(rides_m[indice]);
    }
    if (stricmp(gender, "f") == 0) {
        return get_ride_user(rides_f[indice]);
    }
    return NULL;
}

int get_gender_ride_i_i (char *gender, int indice) {
    if (stricmp(gender, "m") == 0) {
        return rides_m[indice];
    }
    if (stricmp(gender, "f") == 0) {
        return rides_f[indice];
    }
    return -1;
}

void sorted_rides() {
    sortedrides = calloc(get_nr_rides(), sizeof(int));
    for(int i = 0; i < get_nr_rides(); i++) sortedrides[i] = i + 1;
    qsort(sortedrides, get_nr_rides(), sizeof(int), sort_rides);
}

char *get_sorted_ride_date(int indice) {
    return get_ride_date(sortedrides[indice]);
}

char *get_sorted_ride_driver(int indice) {
    return get_ride_driver(sortedrides[indice]);
}

char *get_sorted_ride_distance(int indice) {
    return get_ride_distance(sortedrides[indice]);
}

char *get_sorted_ride_city(int indice) {
    return get_ride_city(sortedrides[indice]);
}

char *get_sorted_ride_tip(int indice) {
    return get_ride_tip(sortedrides[indice]);
}

int get_sorted_ride_i(int indice) {
    return sortedrides[indice];
}

void init_stats_d(int nr_drivers) {
    nr_viagens_d = calloc(nr_drivers + 1, sizeof(int));
    av_total_d = calloc(nr_drivers + 1, sizeof(int));
    tot_auferido = calloc(nr_drivers + 1, sizeof(double));
}

void init_stats_u(int nr_users) {
    nr_viagens_u = calloc(nr_users + 1, sizeof(int));
    av_total_u = calloc(nr_users + 1, sizeof(int));
    tot_gasto = calloc(nr_users + 1, sizeof(double));
}

void insert_stats_d(int indice, int aval, double val) {
    nr_viagens_d[indice]++;
    av_total_d[indice] += aval;
    tot_auferido[indice] += val;
}

void insert_stats_u(int indice, int aval, double val) {
    nr_viagens_u[indice]++;
    av_total_u[indice] += aval;
    tot_gasto[indice] += val;
}

void insert_stats_c(char *name, int indice, double price) {
    for(int i = 0; i < nr_cities; i++) {
        if (stricmp(cities[i].name, name) == 0) {
            cities[i].nr_viagens++;
            if (cities[i].nr_viagens > cities[i].cap) {
                cities[i].cap *= 2;
                cities[i].rides = realloc(cities[i].rides, cities[i].cap * sizeof(int));   
            }
            (cities[i].rides)[cities[i].nr_viagens - 1] = indice;
            cities[i].total_price += price;
            return;
        }
    }
    
    city temp;
    temp.name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(temp.name, name);
    temp.nr_viagens = 1;
    temp.total_price = price;
    temp.rides = malloc(sizeof(int));
    temp.cap = 1;
    (temp.rides)[0] = indice;

    nr_cities++;
    cities = realloc(cities, nr_cities * sizeof(struct city));
    cities[nr_cities - 1] = temp;
}

void insert_stats_gender(char *gender, int indice) {
    if (stricmp(gender, "m") == 0) {
        nr_rides_m++;
        if (nr_rides_m > cap_rides_m) {
            if (cap_rides_m != 0) cap_rides_m *= 2;
                else cap_rides_m = 1;
            rides_m = realloc(rides_m, cap_rides_m * sizeof(int));
        }
        rides_m[nr_rides_m - 1] = indice;
    }
    else if (stricmp(gender, "f") == 0) {
        nr_rides_f++;
        if (nr_rides_f > cap_rides_f) {
            if (cap_rides_f != 0) cap_rides_f *= 2;
                else cap_rides_f = 1;
            rides_f = realloc(rides_f, cap_rides_f * sizeof(int));
        }
        rides_f[nr_rides_f - 1] = indice;
    }
}

void free_cities() {
    for (int i = 0; i < nr_cities; i++) {
        free(cities[i].name);
        free(cities[i].rides);
    }
    free(cities);
}

void free_gender() {
    free(rides_m);
    free(rides_f);
}

void free_all_stats() {
    free(nr_viagens_d);
    free(nr_viagens_u);
    free(av_total_d);
    free(av_total_u);
    free(tot_auferido);
    free(tot_gasto);
    free(sortedrides);
    free_cities();
    free_gender();
}