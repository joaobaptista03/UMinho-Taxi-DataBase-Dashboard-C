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

void free_all_stats() {
    free(nr_viagens_d);
    free(nr_viagens_u);
    free(av_total_d);
    free(av_total_u);
    free(tot_auferido);
    free(tot_gasto);
}

double total_gasto_auferido(char *class, int distance, double tip) {
    int taxa_base = 0, taxa_dist = 0;
    
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

void stats() {
    nr_viagens_d = calloc(get_n_drivers() + 1, sizeof(int));
    nr_viagens_u = calloc(get_nr_users() + 1, sizeof(int));
    av_total_d = calloc(get_n_drivers() + 1, sizeof(int));
    av_total_u = calloc(get_nr_users() + 1, sizeof(int));
    tot_auferido = calloc(get_n_drivers() + 1, sizeof(double));
    tot_gasto = calloc(get_nr_users() + 1, sizeof(double));

    for(int i = 1; i < get_nr_rides(); i++) {
        nr_viagens_d[get_driver_i(get_ride_driver(i))]++;
        nr_viagens_u[get_user_i(get_ride_user(i))]++;

        av_total_d[get_driver_i(get_ride_driver(i))] += atoi(get_ride_score_driver(i));
        av_total_u[get_user_i(get_ride_user(i))] += atoi(get_ride_score_user(i));

        double tot_gasto_auferido = total_gasto_auferido(get_driver_car_class(get_ride_driver(i)), atoi(get_ride_distance(i)), atof(get_ride_tip(i)));
        tot_auferido[get_driver_i(get_ride_driver(i))] += tot_gasto_auferido;
        tot_gasto[get_user_i(get_ride_user(i))] += tot_gasto_auferido;
    }

}