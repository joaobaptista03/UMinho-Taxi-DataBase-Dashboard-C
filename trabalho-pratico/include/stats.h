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
 * Este é o header da função que liberta a memória alocada para todas as Estatísticas.
 * 
 */
void free_all_stats();

/**
 *
 * Este é o header da função que calcula o total gasto / auferido de uma viagem.
 * 
 */
double total_gasto_auferido(char *class, int distance, double tip);

/**
 *
 * Este é o header da função que preenche as Estatísticas.
 * 
 */
void stats();

#endif