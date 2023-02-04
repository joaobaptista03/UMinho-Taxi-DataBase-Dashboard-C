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

void check(int counter, char *dataset) {
    char filename[30], filepath[60], resultfile[50];
    sprintf(filename, "command%d_output.txt", counter);
    sprintf(resultfile, "Resultados/%s", filename);

    if (strcmp(dataset, "rwo") == 0) sprintf(filepath, "Datasets/R-WITHOUT/outputs/%s", filename);
    if (strcmp(dataset, "rw") == 0) sprintf(filepath, "Datasets/R-WITH/outputs/%s", filename);
    if (strcmp(dataset, "lwo") == 0) sprintf(filepath, "Datasets/L-WITHOUT/outputs/%s", filename);
    if (strcmp(dataset, "lw") == 0) sprintf(filepath, "Datasets/L-WITH/outputs/%s", filename);

    FILE *expected = fopen(filepath, "r");
    FILE *result = fopen(resultfile, "r");
    if (compare(expected, result)) printf("Test %d passed ✅\n", counter);
        else printf("Test %d failed ❌\n", counter);
    fclose(expected);
    fclose(result);
}

void q1_test(int counter, char *id, char *dataset) {
    query1(counter, id, 3);
    check(counter, dataset);
}

void q2_test(int counter, char *input, char *dataset) {
    query2(counter, input, 3);
    check(counter, dataset);
}

void q3_test(int counter, char *input, char *dataset) {
    query3(counter, input, 3);
    check(counter, dataset);
}

void q4_test(int counter, char *input, char *dataset) {
    query4(counter, input, 3);
    check(counter, dataset);
}

void q5_test(int counter, char *data1, char *data2, char *dataset) {
    query5(counter, data1, data2, 3);
    check(counter, dataset);
}

void q6_test(int counter, char *input, char *dataset) {
    query6(counter, input, 3);
    check(counter, dataset);
}

void q7_test(int counter, char *input, char *dataset) {
    query7(counter, input, 3);
    check(counter, dataset);
}

void q8_test(int counter, char *input, char *dataset) {
    query8(counter, input, 3);
    check(counter, dataset);
}

void q9_test(int counter, char *data1, char *data2, char *dataset) {
    query9(counter, data1, data2, 3);
    check(counter, dataset);
}

int main() {
    puts("Large Dataset With Invalid Entries:");
    system("mkdir Resultados");
    FILE *inputs; inputs = fopen("Datasets/L-WITH/inputs.txt", "r");
    FILE *drivers; drivers = fopen("Datasets/L-WITH/drivers.csv", "r");
    FILE *users; users = fopen("Datasets/L-WITH/users.csv", "r");
    FILE *rides; rides = fopen("Datasets/L-WITH/rides.csv", "r");

    
    inserir_drivers(drivers);
    inserir_users(users);
    inserir_rides(rides);

    fclose(drivers);
    fclose(users);
    fclose(rides);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';
        puts("-----------------------------------------------");
        printf("Input: %s\n", input);
        if (input[0] == '1') q1_test(counter, input + 2, "lw");
        else if (input[0] == '2') q2_test(counter, input + 2, "lw");
        else if (input[0] == '3') q3_test(counter, input + 2, "lw");
        else if (input[0] == '4') q4_test(counter, input + 2, "lw");
        else if (input[0] == '5') q5_test(counter, input + 2, input + 13, "lw");
        else if (input[0] == '6') q6_test(counter, input + 2, "lw");
        else if (input[0] == '7') q7_test(counter, input + 2, "lw");
        else if (input[0] == '8') q8_test(counter, input + 2, "lw");
        else if (input[0] == '9') q9_test(counter, input + 2, input + 13, "lw");
        counter++;
    }

    free_drivers();
    free_users();
    free_rides();
    free_all_stats();

    fclose(inputs);
    free(input);
    system("rm -r Resultados");
    puts("-------------------------------------------");
}