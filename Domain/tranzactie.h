//
// Created by Ognean Jason Dennis on 05.03.2026.
//

#ifndef LAB2_TRANZACTIE_H
#define LAB2_TRANZACTIE_H

typedef struct{
    int id,day,suma,tip;
    char descriere[256];
}Tranzactie;


/*
 * Creeaza o Tranzactie nou si o returneaza
 * Parametrii:
 *      - day(int): reprezinta ziua in care s-a realizat tranzactia
 *      - suma(int): reprezinta valoarea sumei tranzactiei
 *      - tip(int): reprezinta tipul tranzactiei: 1/0 -> intrare/iesire
 *      - descriere(char): reprezinta o mica descriere a tranzactiei
 * Return: returneaza un element de tip Tranzactie
 */
Tranzactie *Creeaza_Tranzactie(int id,int day,int suma,int tip,char* descriere);

/*
 * Sterge Tranzactia
 */
void Distruge_Tranzactie(Tranzactie *T);
/*
 * Compara 2 tranzactii dupa ziua
 * return :  > 0 -> A->day mai mare
 *           < 0 -> A-day mai mic
 *           0  -> A-day = B-day
 *
 */
int ComparaTranzactiiDay(Tranzactie* A, Tranzactie* B);
/*
 * Compara 2 tranzactii dupa suma
 * return :  > 0 -> A->suma mai mare
 *           < 0 -> A-suma mai mic
 *           0  -> A-suma = B-suma
 *
 */
int ComparaTranzactiiSuma(Tranzactie* A, Tranzactie* B);

/*
 * Compara un ID cu Id ul Tranzactiei A
 */
int ComparaID(Tranzactie* A,int* id);

/*
 * Returneaza ID ul tranzactiei
 */
int Get_ID(Tranzactie* T);
/*
 * Returneaza ziua tranzactiei
 */
int Get_Day(Tranzactie* T);
/*
 * Returneaza suma tranzactiei
 */
int Get_Suma(Tranzactie* T);
/*
 * Returneaza tip ul tranzactiei
 */
int Get_Tip(Tranzactie *T);
/*
 * Returneaza descrierea tranzactiei
 */
const char* Get_Descriere(Tranzactie *T);
/*
 * Modifica ziua tranzactiei
 */
void Set_Day(Tranzactie *T, int day);
/*
 * Modifica suma tranzactiei
 */
void Set_Suma(Tranzactie *T, int suma);
/*
 * Modifica tipul tranzactiei
 */
void Set_Tip(Tranzactie *T, int tip);
/*
 * Modifica descrierea tranzactiei
 */
void Set_Descriere(Tranzactie *T, char *descriere);


#endif //LAB2_TRANZACTIE_H
