/**
 * @file query1_user.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 1, caso seja User.
 * 
 */

#include "../include/query1_user.h"

void query1_user (int counter, Ride *rides_cat, char *id, int mode) {
    printf("\nA executar Q1 (linha de input %i)\n", counter);

    if (!is_user(id)) {
        if (mode == 1) puts("\nResultado: User não existe!\n");
        if (mode == 0) handle_outputs(counter, "");
        return;
    }

    // Se o user for inactive
    if (stricmp(get_user_status(id), "inactive") == 0) {
        if (mode == 1) puts("\nResultado: User inativo!\n");
        if (mode == 0) handle_outputs(counter, "");
        return;
    }
    
    float taxa_dist, taxa_base;
    int total_avaliacoes = 0; double av_media = 0;
    int num_viagens = 0;
    double tot_gasto = 0;

    // for loop que percorre o catálogo das Rides, e se cada ride for do User pretendido, faz os devidos cálculos
    for (int i = 1; i <= atoi(rides_cat[0].id); i++) {
        if (stricmp(rides_cat[i].user, id) == 0) {
            total_avaliacoes += atof(rides_cat[i].score_user);
            num_viagens++;
            // Calcula a taxa base e a taxa por distância de acordo com a classe do carro do Driver dessa Ride
            char class[10];
            strcpy(class, get_driver_car_class(rides_cat[i].driver));
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
            tot_gasto += atof(rides_cat[i].distance) * taxa_dist + taxa_base + atof(rides_cat[i].tip);
        }
    }
    
    // Se o número de viagens for 0, o divisor será 0, logo iria dar erro. Logo, a avaliação média é imediatamente 0
    if (num_viagens != 0) av_media = (double) total_avaliacoes / (double) num_viagens;
    else av_media = 0;
    
    char output[150];
    sprintf(output, "%s;%s;%i;%.3f;%i;%.3f\n", get_user_name(id), get_user_gender(id), age(get_user_birth_date(id)), av_media, num_viagens, tot_gasto);
    if (mode == 1) puts("\nForma do Resultado: nome;genero;idade;avaliacao_media;numero_viagens;total_gasto");
    if (mode == 1) printf("Resultado: %s\n",output);
    if (mode == 0) handle_outputs(counter, output);
}