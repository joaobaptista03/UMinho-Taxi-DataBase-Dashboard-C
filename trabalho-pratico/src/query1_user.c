/**
 * @file query1_user.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 1, caso seja User.
 * 
 */

#include "../include/query1_user.h"

void query1_user (int counter, char *id, int mode) {

    if (!is_user(id)) {
        if (mode == 1) puts("\nResultado: User não existe!\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    if (stricmp(get_user_status(id), "inactive") == 0) {
        if (mode == 1) puts("\nResultado: User inativo!\n");
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    double av_media = (double) get_user_av_total(get_user_i(id)) / (double) get_user_nr_viagens(get_user_i(id));

    char output[150];
    sprintf(output, "%s;%s;%i;%.3f;%i;%.3f\n", get_user_name(id), get_user_gender(id), age(get_user_birth_date(id)), av_media, get_user_nr_viagens(get_user_i(id)), get_tot_gasto(get_user_i(id)));
    if (mode == 1) puts("\nForma do Resultado: nome;genero;idade;avaliacao_media;numero_viagens;total_gasto");
    if (mode == 1) printf("Resultado: %s\n",output);
    if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
}