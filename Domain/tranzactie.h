//
// Created by Ognean Jason Dennis on 05.03.2026.
//

#ifndef LAB2_TRANZACTIE_H
#define LAB2_TRANZACTIE_H

typedef struct{
    int id,day,suma,tip;
    char descriere[256];
}Tranzactie;

Tranzactie *Creeaza_Tranzactie(int day,int suma,int tip,char* descriere);
void Distruge_Tranzactie(Tranzactie *T);

int Get_ID(Tranzactie* T);
int Get_Day(Tranzactie* T);
int Get_Suma(Tranzactie* T);
int Get_Tip(Tranzactie *T);
const char* Get_Descriere(Tranzactie *T);

void Set_Day(Tranzactie *T, int day);
void Set_Suma(Tranzactie *T, int suma);
void Set_Tip(Tranzactie *T, int tip);
void Set_Descriere(Tranzactie *T, char *descriere);


#endif //LAB2_TRANZACTIE_H
