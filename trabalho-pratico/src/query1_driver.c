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

    char *driverstatus = get_driver_status(id);
    if (stricmp(driverstatus, "inactive") == 0) {
        free(driverstatus);
        if (mode == 1) puts("\nResultado: Driver inativo!\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }
    free(driverstatus);

    double av_media = (double) get_driver_av_total(get_driver_i(id)) / (double) get_driver_nr_viagens(get_driver_i(id));

    char output[150];
    if (mode == 1) puts("\nForma do Resultado: nome;genero;idade;avaliacao_media;numero_viagens;total_auferido");
    char *drivername = get_driver_name(id), *drivergender = get_driver_gender(id), *driverbirthdate = get_driver_birth_date(id);
    sprintf(output, "%s;%s;%i;%.3f;%i;%.3f\n", drivername, drivergender, age(driverbirthdate), av_media, get_driver_nr_viagens(get_driver_i(id)), get_tot_auferido(get_driver_i(id)));
    free(drivername); free(drivergender); free(driverbirthdate);
    if (mode == 1) printf("Resultado: %s\n",output);
    if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
}