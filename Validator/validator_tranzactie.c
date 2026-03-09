//
// Created by denni on 3/9/2026.
//

#include "validator_tranzactie.h"
#include <string.h>

int Valideaza_Tranzactie(int day, int suma, int tip, char *descriere) {

    int valida=1;

    if (!(1<=day && day<=31)) {
        valida=0;
    }

    if (suma<=0) {
        valida=0;
    }

    if (tip!=0 && tip!=1) {
        valida=0;
    }

    if (descriere==NULL || strlen(descriere)==0) {
        valida=0;
    }

    return valida;
}

int Valideaza_Modificare_Suma(int suma) {

    if (suma<=0)
        return 0;
    return 1;
}

int Valideaza_Modificare_Day(int Day) {
    if (!(1<=Day && Day<=31)) {
        return 0;
    }
    return 1;
}

int Valideaza_Modificare_Tip(int Tip) {
    if (Tip !=1 && Tip !=0) {
        return 0;
    }
    return 1;
}

int Valideaza_Modificare_Descriere(char *Descriere) {

    if (Descriere==NULL || strlen(Descriere)==0) {
        return 0;
    }
    return 1;
}
