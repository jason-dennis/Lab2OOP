//
// Created by denni on 3/9/2026.
//

#include "validator_tranzactie.h"
#include <string.h>

int Valideaza_Tranzactie(int day, int suma, int tip, char *descriere) {
    /*
     *Functia Valideaza datele unei tranzictii
    */

    if (!(1<=day && day<=31)) {
        return 0;
    }
    else if (suma<=0) {
        return 0;
    }
    else if (tip!=0 && tip!=1) {
        return 0;
    }
    else if (descriere==NULL || strlen(descriere)==0) {
        return 0;
    }

    return 1;
}

int Valideaza_Modificare_Suma(int suma) {
    /*
     *Functia Valideaza suma pentru modificarea tranzactiei
    */
    if (suma<=0)
        return 0;
    return 1;
}

int Valideaza_Modificare_Day(int Day) {
    /*
 *Functia Valideaza ziua pentru modificarea tranzactiei
*/
    if (!(1<=Day && Day<=31)) {
        return 0;
    }
    return 1;
}

int Valideaza_Modificare_Tip(int Tip) {
    /*
     *Functia Valideaza tipul pentru modificarea tranzactiei
    */
    if (Tip !=1 && Tip !=0) {
        return 0;
    }
    return 1;
}

int Valideaza_Modificare_Descriere(char *Descriere) {
    /*
     *Functia Valideaza descrierea pentru modificarea tranzactiei
    */
    if (Descriere==NULL || strlen(Descriere)==0) {
        return 0;
    }
    return 1;
}
