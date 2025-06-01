#ifndef CPLUS_MEMORY_H
#define CPLUS_MEMORY_H

#include <stdlib.h>

// Funzione per allocare memoria per un oggetto, considerando la parte pubblica e privata
// pubsize: dimensione della parte pubblica (struct principale)
// privsize: dimensione della parte privata (struct privata)
// vtable: puntatore alla tabella virtuale da associare all'oggetto
void* new_alloc(size_t pubsize, size_t privsize, const void* vtable);

// Macro per allocare memoria per una classe e la sua parte privata
// Class: nome della struct pubblica (es. Point)
// privsize: nome della struct privata associata (es. PointPrivate) — NB: qui si passa il tipo, non la dimensione!
// vt: prefisso della vtable, senza il suffisso _vtable
// Nota: vt##_vtable concatena il nome per ottenere l'indirizzo della vtable
// Esempio:
//    NEW_ALLOC(Point, PointPrivate, Point)
//    si espande in:
//    (Point*)new_alloc(sizeof(Point), sizeof(PointPrivate), Point_vtable)
#define NEW_ALLOC(Class, privsize, vt) \
    (Class*)new_alloc(sizeof(Class), sizeof(privsize), vt##_vtable)

// Macro per deallocare un oggetto e azzerare il puntatore
#define DELETE(obj) do { \
    free(obj); \
    obj = NULL; \
} while(0)

// Macro per ottenere il puntatore alla parte privata di un oggetto
// obj: puntatore all'oggetto pubblico
// classname: nome della classe (es. Point)
// Restituisce un puntatore alla memoria subito dopo la parte pubblica,
// ovvero alla parte privata dell'oggetto
#define PRIVATE(obj, classname) ((classname##Private*)(((char*)(obj)) + sizeof(classname)))

#endif // CPLUS_MEMORY_H
