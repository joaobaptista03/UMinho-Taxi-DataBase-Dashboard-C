/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include "../include/main.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Número de argumentos inválido.");
        return -1;
    }

    drivers = fopen(strcat(argv[1], "drivers.csv"), "r");
    users = fopen(strcat(argv[1], "users.csv"), "r");
    rides = fopen(strcat(argv[1], "rides.csv"), "r");
    inputs = fopen(argv[2], "r");

    //inserir_dados();                                                  // Inserir dados nos catálogos
    
    char input[100];                                                    // String para qual cada linha de input irá ser copiada
    while(fgets(input, 100, inputs)) {                                  // Loop While que irá fazer certas coisas (em cada loop) a cada linha do ficheiros de inputs
        if (strchr(input, '\n')) *strchr(input, '\n') = '\0';           // Trocar '\n' por '\0' na string input
        /*
        if (input[0] == '1') query1(input + 2);                         // Chamar a query1 se for o caso
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
