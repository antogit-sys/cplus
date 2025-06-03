#ifndef CPLUS_UTILS_H
#define CPLUS_UTILS_H

// Macro per concatenare due token (token pasting)
// Permette di unire due simboli in uno solo durante la fase di preprocessore.
// Esempio: CONCAT(Point, _new) diventa Point_new
#define CONCAT(a, b) a ## b

// Etichette semantiche per la visibilità
// __PUBLIC è solo un marcatore documentativo, non modifica il codice
// __PRIVATE esplicita che la funzione è statica (visibilità solo nel file, usato per le funzioni)
#define __PUBLIC /*nothing*/
#define __PRIVATE static

// Alias per accedere alla tabella virtuale (vtable) di un oggetto
#define METHODS vtable

// Macro per costruire il nome di un metodo appartenente a una classe
// c = nome della classe, m = nome del metodo
// Esempio: METHOD_OF(Point, print) => Point_print
#define METHOD_OF(c, m) c##_##m

// Macro per chiamare un metodo della vtable in modo generico
// obj: puntatore all'oggetto
// method: nome del metodo da chiamare (senza class prefix)
// __VA_ARGS__: parametri addizionali per il metodo
// Espande in: obj->vtable->method(obj, ...)
// Nota: usa ##__VA_ARGS__ per gestire anche chiamate senza argomenti extra
#define CALL_METHOD(obj, method, ...) ((obj)->METHODS->method((obj), ##__VA_ARGS__))

// Crea un alias per il puntatore a un tipo
// Esempio: CREATE_OBJ(Point) genera typedef Point* Point_o;
#define CREATE_OBJ(type) typedef type* type##_o

// Macro per creare un oggetto usando il costruttore parametrico
// Espande in: (class_name*)class_name_new(__VA_ARGS__)
// Esempio: NEW(Point, 1, 2) diventa (Point*)Point_new(1, 2)
#define NEW(class_name, ...) \
    ((class_name*)CONCAT(class_name, _new)(__VA_ARGS__))

// Macro per definire il costruttore vero e proprio, cioè la funzione che implementa la creazione dell’oggetto
// Espande in: class_name* class_name_new(parametri)
// Esempio: DEF_CTOR(Point, int x, int y) diventa Point* Point_new(int x, int y)
#define DEF_CTOR(class_name, ...) \
    class_name* CONCAT(class_name, _new)(__VA_ARGS__)

// Macro per dichiarare (aggiungere) il prototipo del costruttore(funzione) in un header
// Semplice alias che aggiunge un punto e virgola alla definizione del prototipo del costruttore
// Esempio: ADD_CTOR(Point, int x, int y) diventa Point* Point_new(int x, int y);
#define ADD_CTOR(class_name, ...) \
    DEF_CTOR(class_name, __VA_ARGS__);

#define PRVT_SPACE(classname) CONCAT(classname,Private)
#define PBLC_SPACE(classname) classname

#endif // CPLUS_UTILS_H

