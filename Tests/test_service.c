//
// Created by denni on 3/9/2026.
//

#include <assert.h>
#include <string.h>
#include "../Service/service.h"
#include "../Domain/tranzactie.h"

void test_service() {

    //creem service ul
    Repo* R=Creeaza_Repo();
    Service* s = Creeaza_Service(R);
    //verificam daca s-a creat corect
    assert(s != NULL);
    assert(s->id_contor == 1);

    // verificam daca se adauga tranzactia cu succes
    int rez_adauga = Adauga_Tranzactie(s, 10, 500, 1, "Salariu");
    assert(Adauga_Tranzactie(s,45,124,0,"ABC")==0);
    assert(Adauga_Tranzactie(s,7,125,2,"ABC")==0);
    assert(Adauga_Tranzactie(s,12,124,0,"")==0);
    assert(rez_adauga == 1);

    //verificam daca s-a stocat elementul
    Tranzactie* t = Cauta_Element(s->repo, 1);
    assert(t != NULL);
    assert(Get_Suma(t) == 500);


    /// verificam daca ne returneaza 0 pentur o tranzacrie invalida
    int rez_adauga_invalid = Adauga_Tranzactie(s, 10, -50, 1, "Eroare");
    assert(rez_adauga_invalid == 0);

    // verificare modificare day
    assert(Modifica_Tranzactie_Day(s, 1, 15) == 1);
    assert(Get_Day(t) == 15);
    assert(Modifica_Tranzactie_Day(s, 1, 40) == -1);
    assert(Modifica_Tranzactie_Day(s, 99, 15) == 0);

    //verificare modificare suma
    assert(Modifica_Tranzactie_Suma(s, 1, 1000) == 1);
    assert(Get_Suma(t) == 1000);
    assert(Modifica_Tranzactie_Suma(s, 99, 100) == 0);
    assert(Modifica_Tranzactie_Suma(s, 1, -10) == -1);

    //Verificare Modificare tip
    assert(Modifica_Tranzactie_Tip(s, 1, 0) == 1);
    assert(Get_Tip(t) == 0);

    assert(Modifica_Tranzactie_Tip(s,1,23)==-1);
    assert(Get_Tip(t)==0);

    assert(Modifica_Tranzactie_Tip(s,231,1)==0);


    //Verificare Modificare Descriere
    assert(Modifica_Tranzactie_Descriere(s, 1, "Cheltuieli") == 1);
    assert(strcmp(Get_Descriere(t), "Cheltuieli") == 0);
    assert(Modifica_Tranzactie_Descriere(s,102,"Catalog")==0);
    assert(Modifica_Tranzactie_Descriere(s,1,"")==-1);

    // verificam functia de stergere
    assert(Sterge_Tranzactie(s, 99) == 0);

    assert(Sterge_Tranzactie(s, 1) == 1);
    assert(Cauta_Element(s->repo, 1) == NULL);


    // Adaugam cateva tranzactii pentru testare
    Adauga_Tranzactie(s, 10, 100, 1, "Intrare1"); // ID 1
    Adauga_Tranzactie(s, 5, 500, 0, "Iesire1");   // ID 2
    Adauga_Tranzactie(s, 20, 300, 1, "Intrare2"); // ID 3

    VectorDinamic* Toate = Vizualizeaza_Toate(s);
    assert(Toate->cnt == 3);
    Distruge_Vector_Copie(Toate);

    // 1. Test Filtrare dupa Tip (1 - Intrare)
    VectorDinamic* filtratTip = Vizualizeaza_tranzactie_dupa_tip(s, 1);
    assert(filtratTip->cnt == 2);
    Distruge_Vector_Copie(filtratTip);

//    // 2. Test Filtrare dupa Suma (Mai mare de 200)
    VectorDinamic* filtratSumaMare = Vizualizeaza_tranzactie_cu_suma_mai_mare(s, 200);
    assert(filtratSumaMare->cnt == 2); // 500 si 300
    Distruge_Vector_Copie(filtratSumaMare);
//
//    // 3. Test Filtrare dupa Suma (Mai mica de 200)
    VectorDinamic* filtratSumaMica = Vizualizeaza_tranzactie_cu_suma_mai_mica(s, 200);
    assert(filtratSumaMica->cnt == 1); // 100
    Distruge_Vector_Copie(filtratSumaMica);
//
//    // 4. Test Sortare dupa Zi (Crescator: 5, 10, 20)
    VectorDinamic* sortatZi = Vizualizeaza_tranzactii_ordinate_zi(s, 0);
    assert(Get_Day((Tranzactie*)Get(sortatZi, 0)) == 5);
    assert(Get_Day((Tranzactie*)Get(sortatZi, 1)) == 10);
    assert(Get_Day((Tranzactie*)Get(sortatZi, 2)) == 20);
    Distruge_Vector_Copie(sortatZi);
    sortatZi = Vizualizeaza_tranzactii_ordinate_zi(s, 1);
    assert(Get_Day((Tranzactie*)Get(sortatZi, 2)) == 5);
    assert(Get_Day((Tranzactie*)Get(sortatZi, 1)) == 10);
    assert(Get_Day((Tranzactie*)Get(sortatZi, 0)) == 20);
    Distruge_Vector_Copie(sortatZi);
//
//    // 5. Test Sortare dupa Suma (Descrescator: 500, 300, 100)
    VectorDinamic* sortatSuma = Vizualizeaza_tranzactii_ordinate_suma(s, 1);
    assert(Get_Suma((Tranzactie*)Get(sortatSuma, 0)) == 500);
    assert(Get_Suma((Tranzactie*)Get(sortatSuma, 1)) == 300);
    assert(Get_Suma((Tranzactie*)Get(sortatSuma, 2)) == 100);
    Distruge_Vector_Copie(sortatSuma);

    sortatSuma = Vizualizeaza_tranzactii_ordinate_suma(s, 0);
    assert(Get_Suma((Tranzactie*)Get(sortatSuma, 2)) == 500);
    assert(Get_Suma((Tranzactie*)Get(sortatSuma, 1)) == 300);
    assert(Get_Suma((Tranzactie*)Get(sortatSuma, 0)) == 100);
    Distruge_Vector_Copie(sortatSuma);


    Distruge_Service(s);
}