//
// Created by denni on 3/9/2026.
//
#include <stdio.h>
#include <assert.h>
#include "../Repository/repo.h"
#include "../Domain/tranzactie.h"

void test_repo() {

    //creem un repo
    Repo *repo = Creeaza_Repo();
    //verificam ca acesta s-a creeat corect
    assert(repo != NULL);
    assert(repo->Tranzactii->cnt == 0);

    //creem 2 tranzactii pentru a le aduga in repo
    Tranzactie *t1 = Creeaza_Tranzactie(1, 10, 50, 0, "Paine");
    Tranzactie *t2 = Creeaza_Tranzactie(2, 12, 1500, 1, "Bursa");

    //adaugam tranzactiile in repo
    Adauga_Element(repo, t1);
    Adauga_Element(repo, t2);
    //verificam daca sunt 2 elemente in repo
    assert(repo->Tranzactii->cnt == 2);

    // verificam cautarea unui element dupa id
    Tranzactie *gasit = Cauta_Element(repo, 2);
    assert(gasit != NULL);
    assert(Get_Suma(gasit) == 1500);

    ///verificam ca ne returneaza NULL pentru un element care nu exista
    Tranzactie *negasit = Cauta_Element(repo, 99);
    assert(negasit == NULL);

    //verificam stergerea elementului
    Sterge_Element(repo, 1);
    assert(repo->Tranzactii->cnt == 1);

    Tranzactie *sters = Cauta_Element(repo, 1);
    assert(sters == NULL);

    //eliberam memoria
    Distruge_Repo(repo);
}