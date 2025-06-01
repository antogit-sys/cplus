#ifndef CPLUS_CLASS_H
#define CPLUS_CLASS_H

// --- Inizio dell'interfaccia pubblica della classe ---
// Questa macro definisce la parte "pubblica" della classe, 
// ovvero la struct che rappresenta l'oggetto visibile all'esterno.
// Include il puntatore alla vtable per i metodi virtuali.

#define CREATE_PUBLIC_INTERFACE(classname) \
    typedef struct classname classname; /* Dichiarazione incompleta per uso come tipo puntatore */ \
    typedef struct classname##VTable classname##VTable; /* Dichiarazione incompleta della vtable associata */ \
    struct classname { \
        const classname##VTable* vtable; /* Puntatore alla tabella dei metodi virtuali */

        
// --- Fine dell'interfaccia pubblica della classe ---
// Serve a chiudere la struct pubblica aperta sopra.
#define END_PUBLIC_INTERFACE \
    };


// --- Inizio dell'interfaccia privata della classe ---
// Questa macro definisce la parte "privata" della classe, tipicamente usata per dati
// che non devono essere visibili all'esterno, ma solo all'interno dei file di implementazione.
#define CREATE_PRIVATE_INTERFACE(classname) \
    typedef struct classname##Private classname##Private; /* Dichiarazione incompleta del tipo privato */ \
    struct classname##Private { /* Apertura della struct privata */


// --- Fine dell'interfaccia privata della classe ---
// Serve a chiudere la struct privata aperta sopra.
#define END_PRIVATE_INTERFACE \
    };


// --- Macro per estendere una classe base (ereditarietà) ---
// Permette di inserire una struct base all'interno di una struct derivata, 
// realizzando così un meccanismo di ereditarietà "simulata".
#define EXTENDS(baseclass) \
    baseclass base;


#endif // CPLUS_CLASS_H

