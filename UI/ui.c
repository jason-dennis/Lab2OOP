//
// Created by Ognean Jason Dennis on 13.03.2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"


UI *Creeaza_UI(Service *s) {
    UI* U= malloc(sizeof (UI));
    U->service=s;
    return U;
}

void Distruge_UI(UI *ui) {
    Distruge_Service(ui->service);
    free(ui);
}


void afiseaza_lista_tranzactii(VectorDinamic* lista) {
    /*
 *  Functia afiseaza o lista de tranzactii
 */
    if (lista == NULL || lista->cnt == 0) {
        printf("Nu exista tranzactii de afisat.\n");
        return;
    }

    printf("\nID | Zi | Suma | Tip | Descriere\n");
    printf("----------------------------------\n");
    for (int i = 0; i < lista->cnt; i++) {
        Tranzactie* t = (Tranzactie*)Get(lista, i);
        printf("%d | %d | %d | %s | %s\n",
               t->id,
               t->day,
               t->suma,
               t->tip == 1 ? "Intrare" : "Iesire",
               t->descriere);
    }
}

void ui_adauga(UI* ui) {
    /*
 *  Functia adauga o comanda noiua
 */
    int zi, suma, tip;
    char descriere[100];

    printf("Ziua (1-31): ");
    scanf("%d", &zi);

    printf("Suma: ");
    scanf("%d", &suma);

    printf("Tip (1-Intrare, 0-Iesire): ");
    scanf("%d", &tip);

    printf("Descriere: ");
    scanf("%s", descriere);

    int eroare = Adauga_Tranzactie(ui->service, zi, suma, tip, descriere);

    if (eroare == 1)
        printf("Tranzactie adaugata cu succes!\n");
    else
        printf("Date invalide! Tranzactia nu a fost adaugata.\n");
}

void ui_modifica(UI* ui) {
    /*
 *  Functia modifica o tranzactie
 */
    int id, opt, val_noua;
    char desc_noua[100];

    printf("ID-ul tranzactiei de modificat: ");
    scanf("%d", &id);

    printf("Ce doriti sa modificati? (1-Zi, 2-Suma, 3-Tip, 4-Descriere): ");
    scanf("%d", &opt);

    int rez = -1;
    switch (opt) {
        case 1: printf("Zi noua: ");
                scanf("%d", &val_noua);
                rez = Modifica_Tranzactie_Day(ui->service, id, val_noua);
                break;
        case 2: printf("Suma noua: ");
                scanf("%d", &val_noua);
                rez = Modifica_Tranzactie_Suma(ui->service, id, val_noua);
                break;
        case 3: printf("Tip nou (0/1): ");
                scanf("%d", &val_noua);
                rez = Modifica_Tranzactie_Tip(ui->service, id, val_noua);
                break;
        case 4: printf("Descriere noua: ");
                scanf("%s", desc_noua);
                rez = Modifica_Tranzactie_Descriere(ui->service, id, desc_noua);
                break;
        default: printf("Optiune invalida.\n");
                return;
    }

    if (rez == 1)
        printf("Modificare reusita!\n");
    else
        printf("Eroare la modificare (ID inexistent sau date invalide).\n");
}

void ui_sterge(UI* ui) {
    /*
 *  FUnctia sterge o tranzactie
 */
    int id;
    printf("ID-ul tranzactiei de sters: ");
    scanf("%d", &id);

    if (Sterge_Tranzactie(ui->service, id) == 1)
        printf("Sters cu succes!\n");
    else
        printf("ID-ul nu a fost gasit.\n");
}

void ui_vizualizare_filtru(UI* ui) {
    /*
 *  Functia afiseaza lista filtrata in functie de tip, suma < sau suma >
 */
    int opt;
    printf("\nFiltrare dupa:\n1. Tip\n2. Suma mai mica\n3. Suma mai mare\nOptiune: ");
    scanf("%d", &opt);

    if (opt == 1) {
        int tip;
        printf("Tip (1-Intrare, 0-Iesire): ");
        scanf("%d", &tip);

        afiseaza_lista_tranzactii(Vizualizeaza_tranzactie_dupa_tip(ui->service, tip));
    } else if (opt == 2) {
        int suma;
        printf("Suma limita: ");
        scanf("%d", &suma);

        afiseaza_lista_tranzactii(Vizualizeaza_tranzactie_cu_suma_mai_mica(ui->service, suma));
    }

}

void ui_vizualizare_ordonata(UI* ui) {
    /*
 *   Functia afiseaza lista de tranzactii ordonata crescator sau descrescator dupa zi sau dupa suma
 */
    int opt;
    printf("\nOrdonare dupa:\n1. Zi\n2. Suma\nOptiune: ");
    scanf("%d", &opt);

    int ord;
    printf("\nOrdonare:\n1. Crescator\n2. Descrecator\nOptiune: ");
    scanf("%d", &ord);
    ord--;
    if (opt == 1) {
        afiseaza_lista_tranzactii(Vizualizeaza_tranzactii_ordinate_zi(ui->service, ord));
    }
    else if (opt == 2) {
        afiseaza_lista_tranzactii( Vizualizeaza_tranzactii_ordinate_suma(ui->service, ord));
    }
}

void Run_Console(UI* ui) {
    /*
 *  Functia ruleaza consola aplicatiei
 */
    int optiune;
    int running = 1;

    while (running) {
        printf("\n--- MENIU TRANZACTII ---\n");
        printf("1. Adauga tranzactie\n");
        printf("2. Modifica tranzactie\n");
        printf("3. Sterge tranzactie\n");
        printf("4. Filtrare tranzactii\n");
        printf("5. Vizualizare ordonata\n");
        printf("0. Iesire\n");
        printf("Alege optiune: ");

        if (scanf("%d", &optiune) != 1) {
            printf("Te rog introdu un numar.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (optiune) {
            case 1: ui_adauga(ui);
                    break;
            case 2: ui_modifica(ui);
                    break;
            case 3: ui_sterge(ui);
                    break;
            case 4: ui_vizualizare_filtru(ui);
                    break;
            case 5: ui_vizualizare_ordonata(ui);
                    break;
            case 0: running = 0; printf("Pa Sefu!\n");
                    break;
            default: printf("Optiune invalida!\n");
        }
    }
}
