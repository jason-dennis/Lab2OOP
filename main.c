#include <stdio.h>
#include "Repository/repo.h"
#include "Service/service.h"
#include "UI/ui.h"
void test_domain();
void test_repo();
void test_service();
void test_structure();
int main(void) {

    ///Testam Domain,Repository si Service
    test_domain();
    test_repo();
    test_service();
    test_structure();

    Repo* repo = Creeaza_Repo();
    Service* service = Creeaza_Service(repo);
    UI* ui = Creeaza_UI(service);
    Run_Console(ui);


    Distruge_UI(ui);
    Distruge_Service(service);
    Distruge_Repo(repo);
    return 0;
}
