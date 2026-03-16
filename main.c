#include <stdio.h>
#include "Repository/repo.h"
#include "Service/service.h"
#include "UI/ui.h"
void test_domain();
void test_repo();
void test_service();
void test_structure();
int main(void) {

    test_domain();
    test_repo();
    test_service();
    test_structure();

    Repo* repo = Creeaza_Repo();
    Service* service = Creeaza_Service(repo);
    UI* ui = Creeaza_UI(service);
    Run_Console(ui);


    Distruge_UI(ui);
    return 0;
}

////gcc -g -O0 -o /tmp/main main.c Domain/tranzactie.c Repository/repo.c Service/service.c Structure/vectordinamic.c Tests/test_domain.c Tests/test_repo.c Tests/test_service.c Tests/test_structure.c UI/ui.c Validator/validator_tranzactie.c
