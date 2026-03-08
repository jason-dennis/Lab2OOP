//
// Created by Ognean Jason Dennis on 06.03.2026.
//
#include "repo.h"
#include <stdio.h>
#include <stdlib.h>
Repo *Creeaza_Repo() {

    Repo *R=(Repo*)malloc(sizeof(Tranzactie));
    R->Tranzactii=Creeaza_Vector();
}

void Distruge_Repo(Repo *R) {

    Distruge_Vector(R->Tranzactii);
    free(R);
}

void Adauga_Element(Repo *R, Tranzactie *T) {
    Adauga(R->Tranzactii,T);
}

void Sterge_Element(Repo *R, Tranzactie *T) {

}






