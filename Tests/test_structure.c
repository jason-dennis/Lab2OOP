//
// Created by Ognean Jason Dennis on 10.03.2026.
//
#include "../Structure/vectordinamic.h"
#include <assert.h>
#include <stdlib.h>

int Compara(Element a, Element b)
{
    int valA = *(int*)a;
    int valB = *(int*)b;
    return valA - valB;
}
void f(Element a)
{
    free(a);
}
void test_structure(){

    VectorDinamic *v=Creeaza_Vector();

    int size=v->dim;
    Resize_Vector(v);
    assert(v->dim==2*size);

    size=v->dim;
    for(int i=20;i>=1;--i)
    {
        int* p = malloc(sizeof(int));
        *p = i;
        Adauga(v, p);
    }

    int* b = malloc(sizeof(int));
    *b=21;
    Adauga(v,b);
    assert(v->dim==2*size);

    SortareCrescator(v,(Functie) Compara);

    int first=*(int*)Get(v, 0);
    assert(first == 1);

    SortareDescrescator(v,(Functie) Compara);
    first=*(int*)Get(v,0);

    assert(first == 21);

    Distruge_Vector(v,(FreeFunc)f);


}