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

UI *Creeaza_UI(Service *s);
void Distruge_UI(UI *ui);
void Run_Console(UI* ui);

#endif