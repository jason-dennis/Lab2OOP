//
// Created by denni on 3/9/2026.
//

#include <assert.h>
#include <string.h>
#include "../Service/service.h"
#include "../Domain/tranzactie.h"

void test_service() {

    //creem service ul
    Service* s = Creeaza_Service();
    //verificam daca s-a creat corect
    assert(s != NULL);
    assert(s->id_contor == 1);

    // verificam daca se adauga tranzactia cu succes
    int rez_adauga = Adauga_Tranzactie(s, 10, 500, 1, "Salariu");
    assert(rez_adauga == 1);

    //verificam daca s-a stocat elementul
    Tranzactie* t = Cauta_Element(s->repo, 1);
    assert(t != NULL);
    assert(Get_Suma(t) == 500);


    /// verificam daca ne returneaza 0 pentur o tranzacrie invalida
    int rez_adauga_invalid = Adauga_Tranzactie(s, 10, -50, 1, "Eroare");
    assert(rez_adauga_invalid == 0);

    // verificam functiile de modificare
    assert(Modifica_Tranzactie_Day(s, 1, 15) == 1);
    assert(Get_Day(t) == 15);

    assert(Modifica_Tranzactie_Suma(s, 1, 1000) == 1);
    assert(Get_Suma(t) == 1000);

    assert(Modifica_Tranzactie_Tip(s, 1, 0) == 1);
    assert(Get_Tip(t) == 0);

    assert(Modifica_Tranzactie_Descriere(s, 1, "Cheltuieli") == 1);
    assert(strcmp(Get_Descriere(t), "Cheltuieli") == 0);


    assert(Modifica_Tranzactie_Day(s, 1, 40) == -1);
    assert(Modifica_Tranzactie_Suma(s, 1, -10) == -1);


    assert(Modifica_Tranzactie_Day(s, 99, 15) == 0);
    assert(Modifica_Tranzactie_Suma(s, 99, 100) == 0);

    // verificam functia de stergere
    assert(Sterge_Tranzactie(s, 99) == 0);

    assert(Sterge_Tranzactie(s, 1) == 1);
    assert(Cauta_Element(s->repo, 1) == NULL);

    //eliberam memoria
    Distruge_Service(s);
}