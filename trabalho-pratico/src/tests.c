/**
 * @file tests.c
 *  Este ficheiro contém as funções relacionadas com os testes funcionais e de desempenho.
 * 
 */

#include <time.h>

#include "../include/query1.h"
#include "../include/query2.h"
#include "../include/query3.h"
#include "../include/query4.h"
#include "../include/query5.h"
#include "../include/query6.h"
#include "../include/query7.h"
#include "../include/query8.h"
#include "../include/query9.h"

struct driver_struct {
    Driver* driverscat;
    GHashTable* drivershash;
};

struct user_struct {
    User* userscat;
    GHashTable* usershash;
};

void q1_test(int counter, char *id) {
    query1(counter, id, 3);
}

void q2_test(int counter, char *input) {
    query2(counter, input, 3);
}

void q3_test(int counter, char *input) {
    query3(counter, input, 3);
}

void q4_test(int counter, char *input) {
    query4(counter, input, 3);
}

void q5_test(int counter, char *data1, char *data2) {
    query5(counter, data1, data2, 3);
}

void q6_test(int counter, char *input) {
    query6(counter, input, 3);
}

void q7_test(int counter, char *input) {
    query7(counter, input, 3);
}

void q8_test(int counter, char *input) {
    query8(counter, input, 3);
}

void q9_test(int counter, char *data1, char *data2) {
    query9(counter, data1, data2, 3);
}

void regular_without() {
    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    FILE *inputs; inputs = fopen("Datasets/R-WITHOUT/inputs.txt", "r");
    FILE *drivers; drivers = fopen("Datasets/R-WITHOUT/drivers.csv", "r");
    FILE *users; users = fopen("Datasets/R-WITHOUT/users.csv", "r");
    FILE *rides; rides = fopen("Datasets/R-WITHOUT/rides.csv", "r");

    driver_struct drivers_struct = inserir_drivers(drivers);
    user_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
    fclose(users);
    fclose(rides);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                             // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') q1_test(counter, input + 2);
        else if (input[0] == '2') q2_test(counter, input + 2);
        else if (input[0] == '3') q3_test(counter, input + 2);
        else if (input[0] == '4') q4_test(counter, input + 2);
        else if (input[0] == '5') q5_test(counter, input + 2, input + 13);
        else if (input[0] == '6') q6_test(counter, input + 2);
        else if (input[0] == '7') q7_test(counter, input + 2);                             // Tem de fazer parsing porque o tamanho da city varia
        else if (input[0] == '8') q8_test(counter, input + 2);
        else if (input[0] == '9') q9_test(counter, input + 2, input + 13);
        counter++;
    }

    free(drivers_struct.driverscat);
    free(users_struct.userscat);
    free(rides_cat);
    g_hash_table_destroy(users_struct.usershash);
    g_hash_table_destroy(drivers_struct.drivershash);
    fclose(inputs);
    free(input);
}

int main() {
    puts("Regular Dataset Without Invalid Entries");
    regular_without();
}