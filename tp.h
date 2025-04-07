#ifndef TP_H
#define TP_H
#include <stdalign.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    char nom[20];
    int code;
    int date_prevention;
    int date_peremption;
    int prix;
    int unite;
    int stock_restant;
}Medicament;

void tri_a_bulles(Medicament *tab, int n);


#endif