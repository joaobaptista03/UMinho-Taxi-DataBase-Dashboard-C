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

void inc_nr_viagens_d(int indice) {
    nr_viagens_d[indice]++;
}

void inc_nr_viagens_u(int indice) {
    nr_viagens_u[indice]++;
}

void add_av_total_d(int indice, int aval) {
    av_total_d[indice] += aval;
}

void add_av_total_u(int indice, int aval) {
    av_total_u[indice] += aval;
}

void add_total_auferido(int indice, double val) {
    tot_auferido[indice] += val;
}

void add_total_gasto(int indice, double val) {
    tot_gasto[indice] += val;
}

void free_all_stats() {
    free(nr_viagens_d);
    free(nr_viagens_u);
    free(av_total_d);
    free(av_total_u);
    free(tot_auferido);
    free(tot_gasto);
}