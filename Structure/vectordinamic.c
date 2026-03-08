//
// Created by Ognean Jason Dennis on 05.03.2026.
//

#include "vectordinamic.h"
#include <stdlib.h>
#define INIT_CAPACITY 100

VectorDinamic *Creeaza_Vector() {
    VectorDinamic* V=malloc(sizeof(VectorDinamic));
    V->item=malloc(INIT_CAPACITY*sizeof(Element));
    V->dim=INIT_CAPACITY;
    V->cnt=0;

    return V;
}

void Distruge_Vector(VectorDinamic *V) {
    for(int i=0;i<V->cnt;++i)
    {
        free(V->item[i]);
    }
    free(V->item);
    free(V);
}

void Adauga(VectorDinamic *V, Element el) {
    if(V->cnt==V->dim)
    {
        Resize_Vector(V);
    }
    V->item[V->cnt++]=el;
}

Element Get(VectorDinamic *V, int poz) {
    if(poz<=V->cnt)
    {
        return V->item[poz];
    }
}

void Sterge(VectorDinamic *V, int poz) {
    if(poz<=V->cnt)
    {
        V->item[poz]=V->item[V->cnt-1];
        V->cnt--;
    }
}

int Cauta(VectorDinamic *V, Element el) {
    for(int i=0;i<V->cnt;++i)
    {
        if(V->item[i]==el)
        {
            return i;
        }
    }
    return -1;
}

void Resize_Vector(VectorDinamic *V) {
    Element* item_nou=(Element*)malloc(2*V->dim*sizeof(Element));
    for(int i=0;i<V->cnt;++i)
    {
        item_nou[i]=V->item[i];
    }

    free(V->item);
    V->item=item_nou;
    V->dim=2*V->dim;
}
