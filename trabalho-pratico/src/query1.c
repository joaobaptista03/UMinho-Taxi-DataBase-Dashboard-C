/**
 * @file query1.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 1.
 * 
 */

#include "../include/query1.h"

void query1 (int counter, Driver *drivers_cat, User *users_cat, GHashTable *users_hash, Ride *rides_cat, char *id) {
    printf("A executar Q1 (linha de input %i)\n", counter);
        if (isDriver(id, strlen(id))) {

            int id_driver = atoi(id);                           // Converter string id do input para int

            // Se o driver não existir
            if ((id_driver > 10000 || id_driver < 1)) {
                handle_outputs(counter, "");
                return;
            }

            Driver q1_d = drivers_cat[id_driver];               // Ir buscar o driver pretendido pelo ID ao Catálogo

            // Se o Driver estiver inativo
            if (strcmp(q1_d.status, "inactive") == 0) {
                handle_outputs(counter, "");
                return;
            }

            // Calcula a taxa base e a taxa por distância de acordo com a classe do carro
            float taxa_base, taxa_dist;
            if (strcmp(q1_d.car_class, "basic") == 0) {
                taxa_base = 3.25;
                taxa_dist = 0.62;
            }
            else if (strcmp(q1_d.car_class, "green") == 0) {
                taxa_base = 4;
                taxa_dist = 0.79;
            }
            else if (strcmp(q1_d.car_class, "premium") == 0) {
                taxa_base = 5.2;
                taxa_dist = 0.94;
            }

            char avaliacao_media[15]; int total_avaliacoes = 0; double av_media = 0;
            char numero_viagens[10]; int num_viagens = 0;
            char total_auferido[15]; double tot_auferido = 0;

            // for loop que percorre o catálogo das Rides, e se cada ride for do Driver pretendido, faz os devidos cálculos
            for (int i = 1; i <= 1000000; i++) {
                if (strcmp(rides_cat[i].driver, id) == 0) {
                    total_avaliacoes += atof(rides_cat[i].score_driver);
                    num_viagens++;
                    tot_auferido += atof(rides_cat[i].distance) * taxa_dist + taxa_base + atof(rides_cat[i].tip);
                }
            }
            // Se o número de viagens for 0, o divisor será 0, logo iria dar erro. Logo, a avaliação média é imediatamente 0
            if (num_viagens != 0) av_media = (double) total_avaliacoes / (double) num_viagens;
            else av_media = 0;

            // Colocar nas respetivas strings os valores devidos, para posteriormente juntar tudo na string output
            sprintf(avaliacao_media, "%.3f", av_media);
            sprintf(numero_viagens, "%i", num_viagens);
            sprintf(total_auferido, "%.3f", tot_auferido);

            char output[150];
            sprintf(output, "%s;%s;%i;%s;%s;%s\n", q1_d.name, q1_d.gender, age(q1_d.birth_date), avaliacao_media, numero_viagens, total_auferido);
            handle_outputs(counter, output);
        }
        else {                                                      // Se não for Driver / Se for User

            User q1_u;                                              // Definição do User pretendido
            
            if (g_hash_table_lookup(users_hash, id) != NULL) q1_u = users_cat[atoi(g_hash_table_lookup(users_hash, id))];
            else {
                handle_outputs(counter, "");
                return;
            }

            // Se o user for inactive
            if (strcmp(q1_u.status, "inactive") == 0) {
                handle_outputs(counter, "");
                return;
            }
           
            float taxa_dist, taxa_base;
            int total_avaliacoes = 0; double av_media = 0;
            int num_viagens = 0;
            double tot_gasto = 0;

            // for loop que percorre o catálogo das Rides, e se cada ride for do User pretendido, faz os devidos cálculos
            for (int i = 1; i <= 1000000; i++) {
                if (strcmp(rides_cat[i].user, id) == 0) {
                    total_avaliacoes += atof(rides_cat[i].score_user);
                    num_viagens++;
                    // Calcula a taxa base e a taxa por distância de acordo com a classe do carro do Driver dessa Ride
                    char class[10];
                    strcpy(class, drivers_cat[atoi(rides_cat[i].driver)].car_class);
                    if (strcmp(class, "basic") == 0) {
                        taxa_base = 3.25;
                        taxa_dist = 0.62;
                    }
                    else if (strcmp(class, "green") == 0) {
                            taxa_base = 4;
                            taxa_dist = 0.79;
                    }
                    else if (strcmp(class, "premium") == 0) {
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
            sprintf(output, "%s;%s;%i;%.3f;%i;%.3f\n", q1_u.name, q1_u.gender, age(q1_u.birth_date), av_media, num_viagens, tot_gasto);
            handle_outputs(counter, output);
        }
    printf("Fim da Q1 (linha de input %i)\n", counter);
}