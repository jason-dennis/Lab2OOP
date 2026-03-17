//
// Created by Ognean Jason Dennis on 05.03.2026.
//

#include "vectordinamic.h"
#include <stdlib.h>
#define INIT_CAPACITY 10

VectorDinamic *Creeaza_Vector() {
    VectorDinamic* V=malloc(sizeof(VectorDinamic));
    V->item=malloc(INIT_CAPACITY*sizeof(Element));
    V->dim=INIT_CAPACITY;
    V->cnt=0;

    return V;
}

void Distruge_Vector(VectorDinamic *V,FreeFunc Free) {
    for(int i=0;i<V->cnt;++i)
    {
        if(V->item[i]!=NULL)
            Free(V->item[i]);
    }
    free(V->item);
    free(V);
}

void Distruge_Vector_Copie(VectorDinamic *V) {
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
    return V->item[poz];
}

void Sterge(VectorDinamic *V, int poz,FreeFunc Free) {
    if(0 <= poz && poz < V->cnt)
    {
        Free(V->item[poz]);
        if(poz<V->cnt-1)
            V->item[poz]=V->item[V->cnt-1];
        V->item[V->cnt-1]=NULL;
        V->cnt--;
    }
}

int Cauta(VectorDinamic *V, Element el,Functie f) {
    for(int i=0;i<V->cnt;++i)
    {
        if(f(V->item[i],el))
        {
            return i;
        }
    }
    return -1;
}

void Resize_Vector(VectorDinamic *V) {
    int dimensiune_nou=V->dim*2;
    Element* item_nou=realloc(V->item,dimensiune_nou*sizeof(Element));
    if (item_nou!=NULL) {
        V->item=item_nou;
        V->dim=dimensiune_nou;
    }
}


void Sortare(VectorDinamic *V, Functie f)
{
    for (int i = 0; i < V->cnt- 1; i++) {
        for (int j = i + 1; j < V->cnt; j++) {
            if (f(V->item[i], V->item[j]) > 0) {
                Element temp = V->item[i];
                V->item[i] = V->item[j];
                V->item[j] = temp;
            }
        }
    }
}