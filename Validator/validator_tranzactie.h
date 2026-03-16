//
// Created by denni on 3/9/2026.
//

#ifndef LAB2_VALIDATOR_TRANZACTIE_H
#define LAB2_VALIDATOR_TRANZACTIE_H

/// Functiile returneaza 1 daca informatiile sunt valide si 0
/// in caz contrar


/*
 *Functia Valideaza datele unei tranzictii
*/
int Valideaza_Tranzactie(int day,int suma,int tip,char* descriere);
/*
 *Functia Valideaza suma pentru modificarea tranzactiei
*/
int Valideaza_Modificare_Suma(int Suma);
/*
*Functia Valideaza ziua pentru modificarea tranzactiei
*/
int Valideaza_Modificare_Day(int Day);
/*
*Functia Valideaza ziua pentru modificarea tranzactiei
*/
int Valideaza_Modificare_Tip(int Tip);
/*
 *Functia Valideaza descrierea pentru modificarea tranzactiei
*/
int Valideaza_Modificare_Descriere(char* Descriere);
#endif //LAB2_VALIDATOR_TRANZACTIE_H