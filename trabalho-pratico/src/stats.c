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

void free_cities() {
    for (int i = 0; i < nr_cities; i++) {
        free(cities[i].name);
        free(cities[i].rides);
    }
    free(cities);
}

void free_all_stats() {
    free(nr_viagens_d);
    free(nr_viagens_u);
    free(av_total_d);
    free(av_total_u);
    free(tot_auferido);
    free(tot_gasto);
    free_cities();
}