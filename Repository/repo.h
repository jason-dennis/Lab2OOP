//
// Created by Ognean Jason Dennis on 06.03.2026.
//

#ifndef LAB2_REPO_H
#define LAB2_REPO_H
#include "../Domain/tranzactie.h"
#include "../Structure/vectordinamic.h"

typedef struct{
    VectorDinamic* Tranzactii;
}Repo;
/*
* Functia creeaza Repo ul
*/
Repo* Creeaza_Repo();
/*
* Functia Sterge Repo ul si elibereaza memoria
*/
void Distruge_Repo(Repo* R);
/*
* Functia adauga in repo tranzactia T
*/
void Adauga_Element(Repo* R, Tranzactie* T);
/*
* Functia Sterge Elementul cu ID-ul =ID;
*/
void Sterge_Element(Repo* R, int ID);
/*
*  Functia Cauta un element dupa ID si il returneaza
*/
Tranzactie* Cauta_Element(Repo *R,int ID);



#endif //LAB2_REPO_H
