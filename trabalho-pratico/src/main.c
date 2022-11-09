/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include "../include/main.h"

int main() {

    drivers = fopen("Ficheiros CSV/drivers.csv","r");
    rides = fopen("Ficheiros CSV/rides.csv","r");
    users = fopen("Ficheiros CSV/users.csv","r");
    inputs = fopen("text files/inputs.txt","r");
    outputs = fopen("text files/outputs.txt","w");

    char input[100];

    while(fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *strchr(input, '\n') = '\0';
        if (input[0] == '1') query1(input + 2);
        /*
        if (input[0] == '2') query2(input + 2);
        if (input[0] == '3') query3(input + 2);
        if (input[0] == '4') query4(input + 2);
        if (input[0] == '5') query5(input + 2, input + 13);
        if (input[0] == '6') query6(input + 2); // Tem de fazer parsing porque o tamanho da city varia
        if (input[0] == '7') query7(input + 2); // Tem de fazer parsing porque o tamanho da city varia
        if (input[0] == '8') query8(input + 2, input + 4);
        if (input[0] == '9') query9(input + 2, input + 13);
        */
    }
    
    fclose(drivers);
    fclose(rides);
    fclose(users);
    fclose(inputs);
    
    return 0;
}
