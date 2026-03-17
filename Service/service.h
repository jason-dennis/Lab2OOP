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

//// Toate functiile int returneaza 1 sau 0: 1 daca s-a putut face operatia si 0 in caz contrar


/*
 * Functia initializeaza Service ul si il returneaza
*/
Service* Creeaza_Service(Repo* r);
/*
 * Functia Sterge Service ul si elibereaza memoria
*/
void Distruge_Service(Service* S);
/*
 * Functia valideaza si adauga o tranzactie nouaa
*/
int Adauga_Tranzactie(Service* S, int day,int suma,int tip,char* descriere);
/*
 * Functia Sterge o Tranzactie
*/
int Sterge_Tranzactie(Service* S,int ID);
/*
 *Functia Valideaza Modificarea si apoi o aplica
*/
int Modifica_Tranzactie_Day(Service* S,int ID,int Day);
/*
 *Functia Valideaza Modificarea si apoi o aplica
*/
int Modifica_Tranzactie_Suma(Service* S,int ID,int Suma);
/*
 *Functia Valideaza Modificarea si apoi o aplica
*/
int Modifica_Tranzactie_Tip(Service* S,int ID,int Tip);
/*
 *Functia Valideaza Modificarea si apoi o aplica
*/
int Modifica_Tranzactie_Descriere(Service* S,int ID,char* Descriere);

/*
 *Functia returneaza un vector dinamic cu tranzactiile de un anumit tip
*/
VectorDinamic* Vizualizeaza_tranzactie_dupa_tip(Service* S, int Tip);
/*
 *Functia returneaza un vector dinamic cu tranzactiile cu suma mai mica deca Suma
*/
VectorDinamic* Vizualizeaza_tranzactie_cu_suma_mai_mica(Service* S, int Suma);
/*
 *Functia returneaza un vector dinamic cu tranzactiile cu suma mai mare deca Suma
*/
VectorDinamic* Vizualizeaza_tranzactie_cu_suma_mai_mare(Service* S, int Suma);
/*
 *Functia returneaza un vector dinamic cu tranzactiile ordonate dupa zi
*/
VectorDinamic* Vizualizeaza_tranzactii_ordinate_zi(Service* S,int Day);
/*
 *Functia returneaza un vector dinamic cu tranzactiile ordonate dupa suma
*/
VectorDinamic* Vizualizeaza_tranzactii_ordinate_suma(Service* S,int Suma);

VectorDinamic *Vizualizeaza_Toate(Service *S);
#endif //LAB2_SERVICE_H