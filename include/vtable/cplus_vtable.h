#ifndef CPLUS_VTABLE_H
#define CPLUS_VTABLE_H

// Macro per definire un metodo virtuale nella vtable
// Definisce un puntatore a funzione con il nome del metodo, tipo di ritorno, tipo del parametro 'self' e altri parametri opzionali
// Esempio: void METHOD(print, Point*) diventa: void (*print)(Point* self)

#define METHOD(func_name, self_type, ...) \
    (*func_name)(self_type self, ##__VA_ARGS__)

// Macro per dichiarare la struttura della vtable di una classe
// Espande in: struct NomeClasseVTable
// Dove verranno definiti i puntatori alle funzioni/metodi virtuali della classe
#define DECLARE_VTABLE(classname) \
    struct classname##VTable

// Macro per definire e inizializzare la vtable di una classe con i metodi virtuali forniti
// Espande in: const NomeClasseVTable NomeClasse_vtable = { metodi... }
// Esempio: ADD_METHODS(Point, Point_print, Point_delete)
#define ADD_METHODS(classname, ...) \
    const classname##VTable classname##_vtable = { __VA_ARGS__ }

// Macro per ricavare il nome della vtable di una classe generica
// Esempio: VTABLE(Point) --> Point_vtable
#define VTABLE(classname) classname##_vtable

// Macro epr ricaavre l'indirizzo della vtable di una classe generica
// Esempio ADDRVT(Point) --> &VTABLE(Point) --> &Point_vtable
#define ADDRVT(classname) &VTABLE(classname)

#endif // CPLUS_VTABLE_H
