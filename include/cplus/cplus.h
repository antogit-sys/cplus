#ifndef CPLUS_H
#   define CPLUS_H

// Macro per concatenare due token (es. CONCAT(Point, _new) => Point_new)
#   define CONCAT(a, b) a ## b

// Etichette semantiche per visibilità (solo a scopo documentativo)
// __PUBLIC non fa nulla, __PRIVATE definisce 'static' per limitare la visibilità al file corrente
#   define __PUBLIC     /* nothing */
#   define __PRIVATE    static

// Macro per creare un oggetto usando il costruttore di default
// Esempio: NEW_DEFAULT(Point) => Point_new_default()
#   define NEW_DEFAULT(class_name) \
        (CONCAT(class_name, _new_default)())

// Macro per creare un oggetto con costruttore parametrico
// Esempio: NEW(Point, 1, 2) => Point_new(1, 2)
#   define NEW(class_name, ...) \
        (CONCAT(class_name, _new)(__VA_ARGS__))

// Macro per definire l'intestazione di un costruttore di default
// Esempio: DEF_CTOR_DEFAULT(Point) => Point Point_new_default()
#   define DEF_CTOR_DEFAULT(class_name) \
        class_name CONCAT(class_name, _new_default) ()

// Macro per aggiungere la dichiarazione del costruttore di default in una struct o header
// Esempio: ADD_CTOR_DEFAULT(Point) => Point Point_new_default();
#   define ADD_CTOR_DEFAULT(class_name) \
        DEF_CTOR_DEFAULT(class_name);

// Macro per definire l'intestazione di un costruttore con parametri
// Esempio: DEF_CTOR(Point, int, int) => Point Point_new(int x, int y);
#   define DEF_CTOR(class_name, ...) \
        class_name CONCAT(class_name, _new)(__VA_ARGS__)

// Macro per aggiungere la dichiarazione di un costruttore parametrico in una struct o header
// Esempio: ADD_CTOR(Point, int x, int y) => Point Point_new(int x, int y);
#   define ADD_CTOR(class_name, ...) \
        DEF_CTOR(class_name, __VA_ARGS__);

#endif // CPLUS_H

