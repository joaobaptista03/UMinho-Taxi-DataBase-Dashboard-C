/**
 * @file age_time.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Datas.
 * 
 */

#include "../include/age_time.h"

int act_year() {
    time_t ts;
    struct tm *ct;
    ts = time(NULL);
    ct = localtime(&ts);
    return ct->tm_year + 1900;
}

int act_month() {
    time_t ts;
    struct tm *ct;
    ts = time(NULL);
    ct = localtime(&ts);
    return ct->tm_mon + 1;
}

int act_day() {
    time_t ts;
    struct tm *ct;
    ts = time(NULL);
    ct = localtime(&ts);
    return ct->tm_mday;
}

int age(char date[]) {

    int day = (date[0]-48)*10 + date[1]-48;
    int month = (date[3]-48)*10 + date[4]-48;
    int year = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)*10 + date[9]-48;

    int alr_bday = 1;

    if (act_month() > month) alr_bday = 0;
    else if (act_month() == month) {
        if (act_day() > day) alr_bday = 0;
    }

    return act_year() - year - alr_bday;
}