/**
 * @file query1_driver.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 1, caso seja Driver.
 * 
 */

#include "../include/query1_driver.h"

void query1_driver (int counter, char *id, int mode) {
    if (!is_driver(id)) {
        if (mode == 1) puts("\nResultado: Driver não existe!\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    if (stricmp(get_driver_status(id), "inactive") == 0) {
        if (mode == 1) puts("\nResultado: Driver inativo!\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    double av_media = (double) get_driver_av_total(get_driver_i(id)) / (double) get_driver_nr_viagens(get_driver_i(id));

    char output[150];
    sprintf(output, "%s;%s;%i;%.3f;%i;%.3f\n", get_driver_name(id), get_driver_gender(id), age(get_driver_birth_date(id)), av_media, get_driver_nr_viagens(get_driver_i(id)), get_tot_auferido(get_driver_i(id)));
    if (mode == 1) puts("\nForma do Resultado: nome;genero;idade;avaliacao_media;numero_viagens;total_auferido");
    if (mode == 1) printf("Resultado: %s\n",output);
    if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
}