//
// Created by Ognean Jason Dennis on 05.03.2026.
//

#ifndef LAB2_VECTORDINAMIC_H
#define LAB2_VECTORDINAMIC_H

typedef void* Element;
typedef int (*Functie)(Element,Element);
typedef void (*FreeFunc)(Element);

typedef struct {
    Element* item;
    int dim;
    int cnt;
}VectorDinamic;

VectorDinamic * Creeaza_Vector();
void Distruge_Vector(VectorDinamic *V,FreeFunc Free);
void Resize_Vector(VectorDinamic* V);


void Adauga(VectorDinamic *v,Element el);
Element Get(VectorDinamic *v, int poz);
void Sterge(VectorDinamic *v,int poz,FreeFunc Free);
int Cauta(VectorDinamic *v,Element el,Functie f);


#endif //LAB2_VECTORDINAMIC_H
