//
// Created by Ognean Jason Dennis on 06.03.2026.
//
#include "repo.h"
#include <stdio.h>
#include <stdlib.h>
Repo *Creeaza_Repo() {
    /*
    * Functia creeaza Repo ul
    */
    Repo *R=malloc(sizeof(Repo));
    R->Tranzactii=Creeaza_Vector();
    return R;
}

void Distruge_Repo(Repo *R) {
    /*
    * Functia Sterge Repo ul si elibereaza memoria
    */
    Distruge_Vector(R->Tranzactii,(FreeFunc) Distruge_Tranzactie);
    free(R);
}

void Adauga_Element(Repo *R, Tranzactie *T) {
    /*
    * Functia adauga in repo tranzactia T
    */
    Adauga(R->Tranzactii,T);
}

void Sterge_Element(Repo *R, int ID){
    /*
    * Functia Sterge Elementul cu ID-ul =ID;
    */
    int pozitie=Cauta(R->Tranzactii,&ID,(Functie)ComparaID);
    Sterge(R->Tranzactii,pozitie,(FreeFunc) Distruge_Tranzactie);
}

Tranzactie* Cauta_Element(Repo *R, int ID) {
    /*
    *  Functia Cauta un element dupa ID si il returneaza
    */
    int pozitie=Cauta(R->Tranzactii,&ID,(Functie)ComparaID);
    if (pozitie==-1) {
        return NULL;
    }
    return Get(R->Tranzactii,pozitie);
}







