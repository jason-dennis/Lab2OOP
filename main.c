#include <stdio.h>
void test_domain();
void test_repo();
void test_service();
int main(void) {

    test_domain();
    test_repo();
    test_service();

    printf("Testele au trecut");
    return 0;
}
