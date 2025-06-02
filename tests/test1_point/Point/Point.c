#include "Point.h"     // Inclusione della definizione della classe Point
#include <stdio.h>     // Inclusione per la funzione printf

// Definizione dell'interfaccia privata di Point, che contiene il membro 'secret'
CREATE_PRIVATE_INTERFACE(Point)
    int secret;
END_PRIVATE_INTERFACE

// Implementazione del metodo print per Point
void METHOD_OF(Point, print)(Point* self) {
    // Stampa le coordinate x e y e il valore 'secret' dalla parte privata dell'oggetto
    printf("Point at (%d, %d), secret = %d\n", self->x, self->y, PRIVATE(self, Point)->secret);
}

// Implementazione del metodo delete per Point
void METHOD_OF(Point, delete)(Point* self){
    DELETE(self);  // Dealloca la memoria occupata dall'oggetto e setta il puntatore a NULL
}

// Implementazione del metodo setsec per Point
void METHOD_OF(Point, setsec)(Point* self, int secret){
    PRIVATE(self, Point)->secret = secret;  // Imposta il valore 'secret' nella parte privata
}

// Definizione della vtable per Point, associando i metodi virtuali
ADD_METHODS(Point,  
        METHOD_OF(Point, print),  // Metodo print
        METHOD_OF(Point, setsec), // Metodo setsec
        METHOD_OF(Point, delete)  // Metodo delete
);

// Definizione del costruttore di Point con parametri x e y
DEF_CTOR(Point, int x, int y) {
    // Allocazione di un nuovo oggetto Point con spazio anche per la parte privata
    Point* p = NEW_ALLOC(Point, PointPrivate, &Point);

    if (!p) return NULL;  // Se l'allocazione fallisce, restituisce NULL

    p->x = x;  // Inizializza la coordinata x
    p->y = y;  // Inizializza la coordinata y

    PRIVATE(p, Point)->secret = 12345;  // Imposta un valore di default per il membro 'secret' privato

    return p;  // Restituisce il puntatore all'oggetto appena creato
}

