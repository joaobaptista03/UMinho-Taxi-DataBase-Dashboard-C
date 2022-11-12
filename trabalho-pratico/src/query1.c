/**
 * @file query1.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 1.
 * 
 */

#include "../include/query1.h"

void query1 (char* id) {
    int isD = isDriver(id, strlen(id));
        if (isD) {
            char info[200];
            while (fgets(info, 200, drivers)) {
                if (strncmp(info,id,strlen(id)) == 0) {
                    
                    char *new_info = strchr(info, ';') + 1;
                    for(int i = 0; new_info[i] != ';'; i++) {
                        printf("%c", *(new_info+i));
                        fprintf(outputs, "%c", *(new_info+i));
                    }

                    

                    break;
                }

            }
    }
        else if (!isD) {
            char info[200];
            while (fgets(info, 200, users)) {
                if (strncmp(info,id,strlen(id)) == 0) {
                    // faz cenas
                    break;
                }
            }
        }
}