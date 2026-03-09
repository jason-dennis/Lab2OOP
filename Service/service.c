//
// Created by denni on 3/9/2026.
//

#include "service.h"

Service * Creeaza_Service() {
    /*
     * Functia initializeaza Service ul
    */


    Service* S=(Service*)malloc(sizeof(Service));
    S->repo=Creeaza_Repo();
    S->id_contor=1;
    return S;
}

void Distruge_Service(Service* S) {
    /*
     * Functia Sterge Service ul si elibereaza memoria
    */
    Distruge_Repo(S->repo);
    free(S);
}

int Adauga_Tranzactie(Service* S,int day, int suma, int tip, char *descriere) {
    /*
     * Functia valideaza si adauga o tranzactie nouaa
    */
    if (Valideaza_Tranzactie(day,suma,tip,descriere)) {

        Tranzactie *T=Creeaza_Tranzactie(S->id_contor,day,suma,tip,descriere);
        Adauga_Element(S->repo,T);
        S->id_contor++;
        return 1;
    }
    return 0;
}

int Sterge_Tranzactie(Service *S, int ID) {
    /*
     * Functia Sterge o Tranzactie
    */
    Tranzactie* T=Cauta_Element(S->repo,ID);
    if (T==NULL) {
        return 0;
    }
    Sterge_Element(S->repo,ID);

    return 1;
}

int Modifica_Tranzactie_Day(Service *S, int ID, int Day) {
    /*
     *Functia Valideaza Modificarea si apoi o aplica
    */
    if (!Valideaza_Modificare_Day(Day)) {
        return -1;
    }
    Tranzactie* T=Cauta_Element(S->repo,ID);
    if (T==NULL) {
        return 0;
    }
    Set_Day(T, Day);
    return 1;
}

int Modifica_Tranzactie_Suma(Service *S, int ID, int Suma) {
    /*
     *Functia Valideaza Modificarea si apoi o aplica
    */
    if (!Valideaza_Modificare_Suma(Suma)) {
        return -1;
    }
    Tranzactie* T=Cauta_Element(S->repo,ID);
    if (T==NULL) {
        return 0;
    }
    Set_Suma(T,Suma);
    return 1;
}

int Modifica_Tranzactie_Tip(Service *S, int ID, int Tip) {
    /*
     *Functia Valideaza Modificarea si apoi o aplica
    */
    if (!Valideaza_Modificare_Tip(Tip)) {
        return -1;
    }

    Tranzactie* T=Cauta_Element(S->repo,ID);
    if (T==NULL) {
        return 0;
    }
    Set_Tip(T,Tip);
    return 1;
}

int Modifica_Tranzactie_Descriere(Service *S, int ID, char *Descriere) {
    /*
     *Functia Valideaza Modificarea si apoi o aplica
    */
    if (!Valideaza_Modificare_Descriere(Descriere)) {
        return -1;
    }

    Tranzactie* T=Cauta_Element(S->repo,ID);
    if (T==NULL) {
        return 0;
    }
    Set_Descriere(T,Descriere);
    return 1;
}

