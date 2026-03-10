//
// Created by Ognean Jason Dennis on 10.03.2026.
//
#include "../Structure/vectordinamic.h"
#include <assert.h>
void test_structure(){

    VectorDinamic *v=Creeaza_Vector();

    int size=v->dim;
    Resize_Vector(v);
    assert(v->dim==2*size);

    size=v->dim;
    for(int i=1;i<=20;++i)
    {
        Adauga(v,&i);
    }

    int b=11;
    Adauga(v,&b);
    assert(v->dim==2*size);

}