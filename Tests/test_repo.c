//
// Created by denni on 3/9/2026.
//
#include <stdio.h>
#include <assert.h>
#include "../Repository/repo.h"
#include "../Domain/tranzactie.h"

void test_repo() {

    Repo *repo = Creeaza_Repo();
    assert(repo != NULL);
    assert(repo->Tranzactii->cnt == 0);


    Tranzactie *t1 = Creeaza_Tranzactie(1, 10, 50, 0, "Paine");
    Tranzactie *t2 = Creeaza_Tranzactie(2, 12, 1500, 1, "Bursa");

    Adauga_Element(repo, t1);
    Adauga_Element(repo, t2);
    assert(repo->Tranzactii->cnt == 2);

    Tranzactie *gasit = Cauta_Element(repo, 2);
    assert(gasit != NULL);
    assert(Get_Suma(gasit) == 1500);


    Tranzactie *negasit = Cauta_Element(repo, 99);
    assert(negasit == NULL);

    Sterge_Element(repo, 1);
    assert(repo->Tranzactii->cnt == 1);

    Tranzactie *sters = Cauta_Element(repo, 1);
    assert(sters == NULL);

    Distruge_Repo(repo);
}