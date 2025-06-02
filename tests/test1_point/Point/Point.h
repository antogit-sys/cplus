#ifndef POINT_H
#define POINT_H

#include "../../../include/cplus.h"  // Inclusione del framework OOP in C con macro e definizioni utili

// Definizione dell'interfaccia pubblica della classe Point
// Qui dichiariamo i membri dati visibili all'esterno (public)
CREATE_PUBLIC_INTERFACE(Point)
    int x;  // Coordinata X del punto
    int y;  // Coordinata Y del punto
END_PUBLIC_INTERFACE       // Fine della definizione dell'interfaccia pubblica

// Dichiarazione della vtable (tavola dei metodi virtuali) della classe Point
DECLARE_VTABLE(Point){
    // Metodo virtuale per stampare le coordinate del punto
    METHOD(void, print, Point*);

    // Metodo virtuale per impostare il valore "segreto" (esempio di metodo con parametro addizionale)
    METHOD(void, setsec, Point*, int);

    // Metodo virtuale per deallocare (distruggere) l'oggetto Point
    METHOD(void, delete, Point*);
};

// Creazione di un typedef per il puntatore all'oggetto Point, alias Point_o
CREATE_OBJ(Point);

// Definizione della firma del costruttore di Point che prende due interi x e y
DEF_CTOR(Point, int x, int y);

// Dichiarazione dei metodi virtuali come funzioni con prefisso "Point_"
// Questi sono i metodi che la vtable punterà a implementare
void METHOD_OF(Point, print)(Point* self);
void METHOD_OF(Point, setsec)(Point* self, int);
void METHOD_OF(Point, delete)(Point* self);

#endif // POINT_H

