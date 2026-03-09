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

Repo* Creeaza_Repo();
void Distruge_Repo(Repo* R);

void Adauga_Element(Repo* R, Tranzactie* T);
void Sterge_Element(Repo* R, int ID);
Tranzactie* Cauta_Element(Repo *R,int ID);



#endif //LAB2_REPO_H
