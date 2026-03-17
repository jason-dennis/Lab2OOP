//
// Created by Ognean Jason Dennis on 05.03.2026.
//
#include "tranzactie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tranzactie *Creeaza_Tranzactie(int id,int day, int suma, int tip, char *descriere) {
    /*
     * Creeaza o Tranzactie nou si o returneaza
     * Parametrii:
     *      - day(int): reprezinta ziua in care s-a realizat tranzactia
     *      - suma(int): reprezinta valoarea sumei tranzactiei
     *      - tip(int): reprezinta tipul tranzactiei: 1/0 -> intrare/iesire
     *      - descriere(char): reprezinta o mica descriere a tranzactiei
     * Return: returneaza un element de tip Tranzactie
     */
    Tranzactie *T=(Tranzactie*)malloc(sizeof(Tranzactie));
    T->descriere=malloc(250*sizeof (char));
    T->id=id;
    T->day=day;
    T->suma=suma;
    T->tip=tip;
    strcpy(T->descriere,descriere);

    return T;
}

void Distruge_Tranzactie(Tranzactie *T) {
    /*
     * Sterge Tranzactia
     */
    free(T);
}

int ComparaID(Tranzactie *A, int* id) {
    /*
     * Compara un ID cu Id ul Tranzactiei A
     */
    return A->id==*id;
}

int Get_ID(Tranzactie *T) {
    /*
     * Returneaza ID ul tranzactiei
     */
    return T->id;
}

int Get_Day(Tranzactie *T) {
    /*
     * Returneaza ziua tranzactiei
     */
    return T->day;
}

int Get_Suma(Tranzactie *T) {
    /*
     * Returneaza suma tranzactiei
     */
    return T->suma;
}

int Get_Tip(Tranzactie *T) {
    /*
     * Returneaza tip ul tranzactiei
     */
    return T->tip;
}

const char *Get_Descriere(Tranzactie *T) {
    /*
     * Returneaza descrierea tranzactiei
     */
    return T->descriere;
}

void Set_Day(Tranzactie *T, int day) {
    /*
     * Modifica ziua tranzactiei
     */
    T->day=day;
}

void Set_Suma(Tranzactie *T, int suma) {
    /*
     * Modifica suma tranzactiei
     */
    T->suma=suma;
}

void Set_Tip(Tranzactie *T, int tip) {
    /*
     * Modifica tipul tranzactiei
     */
    T->tip=tip;
}

void Set_Descriere(Tranzactie *T, char *descriere) {
    /*
     * Modifica descrierea tranzactiei
     */
    strcpy(T->descriere,descriere);
}

int ComparaTranzactiiDayCresc(Tranzactie *A, Tranzactie *B) {
    /*
     * Compara 2 tranzactii dupa ziua
     * return :  > 0 -> A->day mai mare
     *           < 0 -> A-day mai mic
     *           0  -> A-day = B-day
     *
     */
    return A->day - B->day;
}
int ComparaTranzactiiDayDesc(Tranzactie *A, Tranzactie *B) {
    /*
     * Compara 2 tranzactii dupa ziua
     * return :  > 0 -> A->day mai mare
     *           < 0 -> A-day mai mic
     *           0  -> A-day = B-day
     *
     */
    return B->day - A->day;
}

int ComparaTranzactiiSumaCresc(Tranzactie *A, Tranzactie *B) {
    /*
     * Compara 2 tranzactii dupa suma
     * return :  > 0 -> A->suma mai mare
     *           < 0 -> A-suma mai mic
     *           0  -> A-suma = B-suma
     *
     */
    return A->suma - B->suma;
}
int ComparaTranzactiiSumaDesc(Tranzactie *A, Tranzactie *B) {
    /*
     * Compara 2 tranzactii dupa suma
     * return :  > 0 -> A->suma mai mare
     *           < 0 -> A-suma mai mic
     *           0  -> A-suma = B-suma
     *
     */
    return B->suma - A->suma;
}



