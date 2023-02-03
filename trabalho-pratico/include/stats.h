/**
 * @file stats.h
 * Este ficheiro contém os headers das funções que fazem as Estatísticas das viagens.
 * 
 */

#ifndef STATS_H
#define STATS_H

#include "cat_drivers.h"
#include "cat_users.h"
#include "cat_rides.h"

/**
 *
 * Esta é a Struct que define o que é uma City, e contém todas as informações dela. Será inserida nas Estatísticas.
 * 
 */
typedef struct city city;

/**
 *
 * Este é o header da função que devolve o número de viagens de um dado Driver.
 * 
 */
int get_driver_nr_viagens(int indice);

/**
 *
 * Este é o header da função que devolve o número de viagens de um dado User.
 * 
 */
int get_user_nr_viagens(int indice);

/**
 *
 * Este é o header da função que devolve a avaliação total de um dado Driver.
 * 
 */
int get_driver_av_total(int indice);

/**
 *
 * Este é o header da função que devolve a avaliação total de um dado User.
 * 
 */
int get_user_av_total(int indice);

/**
 *
 * Este é o header da função que devolve o total auferido de um dado Driver.
 * 
 */
double get_tot_auferido(int indice);

/**
 *
 * Este é o header da função que devolve o total gasto de um dado User.
 * 
 */
double get_tot_gasto(int indice);

/**
 *
 * Este é o header da função que devolve o preço médio de uma Cidade.
 * 
 */
double get_city_preco_medio(char *name);

/**
 *
 * Este é o header da função que devolve número de Rides de uma dada City.
 * 
 */
int get_city_nr_rides(char *name);

/**
 *
 * Este é o header da função que devolve o Driver de uma Ride de uma dada City
 * 
 */
char* get_city_ride_driver (char *name, int indice);

/**
 *
 * Este é o header da função que devolve o Score Driver de uma Ride de uma dada City
 * 
 */
char* get_city_ride_score_driver (char *name, int indice);

/**
 *
 * Este é o header da função que insere os dados de um Driver nas Estatísticas.
 * 
 */
void insert_stats_d(int indice, int aval, double val);

/**
 *
 * Este é o header da função que insere os dados de um User nas Estatísticas.
 * 
 */
void insert_stats_u(int indice, int aval, double val);

/**
 *
 * Este é o header da função que insere os dados de uma City nas Estatísticas.
 * 
 */
void insert_stats_c(char *name, int indice, double price);

/**
 *
 * Este é o header da função que liberta a memória alocada para todas as Estatísticas.
 * 
 */
void free_all_stats();

/**
 *
 * Este é o header da função que inicializa as Estatísticas dos Drivers.
 * 
 */
void init_stats_d(int nr_drivers);

/**
 *
 * Este é o header da função que inicializa as Estatísticas dos Users.
 * 
 */
void init_stats_u(int nr_users);

#endif