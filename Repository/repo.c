//
// Created by Ognean Jason Dennis on 06.03.2026.
//
#include "repo.h"
#include <stdio.h>
#include <stdlib.h>
Repo *Creeaza_Repo() {

    Repo *R=malloc(sizeof(Repo));
    R->Tranzactii=Creeaza_Vector();
    return R;
}

void Distruge_Repo(Repo *R) {

    Distruge_Vector(R->Tranzactii,(FreeFunc) Distruge_Tranzactie);
    free(R);
}

void Adauga_Element(Repo *R, Tranzactie *T) {
    Adauga(R->Tranzactii,T);
}

void Sterge_Element(Repo *R, int ID){

    int pozitie=Cauta(R->Tranzactii,&ID,(Functie)ComparaID);
    Sterge(R->Tranzactii,pozitie,(FreeFunc) Distruge_Tranzactie);
}

Tranzactie* Cauta_Element(Repo *R, int ID) {

    int pozitie=Cauta(R->Tranzactii,&ID,(Functie)ComparaID);
    if (pozitie==-1) {
        return NULL;
    }
    return Get(R->Tranzactii,pozitie);
}







