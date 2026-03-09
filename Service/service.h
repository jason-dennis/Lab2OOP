//
// Created by denni on 3/9/2026.
//

#ifndef LAB2_SERVICE_H
#define LAB2_SERVICE_H
#include <stdlib.h>
#include "../Repository/repo.h"
#include "../Validator/validator_tranzactie.h"

typedef struct {
    Repo* repo;
    int id_contor;
}Service;

Service* Creeaza_Service();
void Distruge_Service(Service* S);

int Adauga_Tranzactie(Service* S, int day,int suma,int tip,char* descriere);
int Sterge_Tranzactie(Service* S,int ID);
int Modifica_Tranzactie_Day(Service* S,int ID,int Day);
int Modifica_Tranzactie_Suma(Service* S,int ID,int Suma);
int Modifica_Tranzactie_Tip(Service* S,int ID,int Tip);
int Modifica_Tranzactie_Descriere(Service* S,int ID,char* Descriere);

#endif //LAB2_SERVICE_H