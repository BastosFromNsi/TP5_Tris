#include "tp.h"
#include <stdlib.h>
#include <stdio.h>

void tri_a_bulles(Medicament *tab, int n)
{
    if (tab == NULL || n <= 0)
    {
        return -1;
    }

    int i, j;
    Medicament temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (tab[j + 1].date_peremption < tab[j].date_peremption)
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int n = 4;

    Medicament tab[] = {
        {"Medicament1", 101, 20230101, 20220302, 100, 1, 50},
        {"Medicament2", 102, 20230201, 20240701, 200, 2, 30},
        {"Medicament3", 103, 20230401, 20240301, 150, 1, 20},
        {"Medicament4", 104, 20230301, 20240401, 250, 3, 10},
    };

    printf("Tableau avant le tri :\n");
    for (int i = 0; i < n; i++)
    {
        printf(" Nom : %s, Code : %d, Date de prevention : %d, Date de peremption : %d, Prix : %d, Unite : %d, Stock restant : %d\n",
               tab[i].nom, tab[i].code, tab[i].date_prevention, tab[i].date_peremption, tab[i].prix, tab[i].unite, tab[i].stock_restant);
    }

    tri_a_bulles(tab, n);

    printf(" Tableau apres le tri : \n");

    for (int i = 0; i < n; i++)
    {
        printf(" Nom : %s, Code : %d, Date de prevention : %d, Date de peremption : %d, Prix : %d, Unite : %d, Stock restant : %d\n",
               tab[i].nom, tab[i].code, tab[i].date_prevention, tab[i].date_peremption, tab[i].prix, tab[i].unite, tab[i].stock_restant);
    }

    return 0;
}
