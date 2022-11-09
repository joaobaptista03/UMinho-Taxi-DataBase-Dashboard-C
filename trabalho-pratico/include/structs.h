/**
 * @file structs.h
 * Este ficheiro contém as structs do Projeto.
 * 
 */

#ifndef STRUCTS
#define STRUCTS


typedef struct
{
    int id;
    char name[100];
    int age;
    char gender;
    char car_class[50];
    char licence_plate[10];
    char city[20];
    char acc_age[2];
    char status[10];

} Driver;

typedef struct
{
    char user[30];
    char name[100];
    char gender;
    int age;
    char acc_age[2];
    char pay_method[20];
    char status[10];

} User;

typedef struct
{
    int id;
    char date[10];
    char driver[100];
    char user[100];
    char city[20];
    int distance;
    int score_driver;
    float tip;
    char comment[100];

} Ride;



#endif