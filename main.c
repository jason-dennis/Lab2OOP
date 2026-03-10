#include <stdio.h>
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

    printf("Testele au trecut");
    return 0;
}
