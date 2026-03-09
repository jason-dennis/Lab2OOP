//
// Created by denni on 3/9/2026.
//

#include <assert.h>
#include <string.h>
#include "../Domain/tranzactie.h"

void test_domain() {

    Tranzactie *t = Creeaza_Tranzactie(1, 15, 250, 1, "Salariu");

    assert(Get_ID(t) == 1);
    assert(Get_Day(t) == 15);
    assert(Get_Suma(t) == 250);
    assert(Get_Tip(t) == 1);
    assert(strcmp(Get_Descriere(t), "Salariu") == 0);


    Set_Suma(t, 300);
    assert(Get_Suma(t) == 300);

    Set_Day(t, 16);
    assert(Get_Day(t) == 16);

    Set_Descriere(t, "Salariu marit");
    assert(strcmp(Get_Descriere(t), "Salariu marit") == 0);

    Distruge_Tranzactie(t);
}