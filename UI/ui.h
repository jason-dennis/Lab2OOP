#ifndef UI_H_
#define UI_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


#include "../Repository/repo.h"
#include "../Service/service.h"

typedef struct{
    Service *service;
}UI;


/*
 * Functia creaaza un UI
 */
UI *Creeaza_UI(Service *s);
/*
 * Functia distruge UI
 */
void Distruge_UI(UI *ui);
/*
 * Functia Porneste Ui si merge pana cand se doreste iesirea din el
 */
void Run_Console(UI* ui);

#endif