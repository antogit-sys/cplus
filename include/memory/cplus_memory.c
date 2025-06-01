#include "cplus_memory.h"
#include <string.h>
#include <stdlib.h>  // malloc

// Funzione che alloca dinamicamente memoria per un oggetto
// comprensivo della sua parte pubblica e privata, e imposta la vtable.
// Parametri:
// - pubsize: dimensione (in byte) della parte pubblica della struct
// - privsize: dimensione (in byte) della parte privata della struct
// - vtable: puntatore alla vtable specifica per quel tipo di oggetto
//
// Restituisce un puntatore all'oggetto allocato, con vtable impostata
// e parte privata azzerata (se presente). Ritorna NULL in caso di errore.
void* new_alloc(size_t pubsize, size_t privsize, const void* vtable) {
    // Calcola la dimensione totale da allocare (pubblica + privata)
    size_t total_size = pubsize + privsize;

    // Alloca memoria dinamica
    void* obj = malloc(total_size);
    if (!obj) {
        // malloc fallito, ritorna NULL
        return NULL;
    }

    // Imposta il puntatore alla vtable nella parte pubblica (all'inizio)
    *(const void**)obj = vtable;

    // Se esiste una parte privata, la azzera a zero per sicurezza
    if (privsize > 0) {
        // Calcola l'indirizzo di inizio della parte privata
        void* priv = (char*)obj + pubsize;
        // Imposta tutta la memoria privata a zero
        memset(priv, 0, privsize);
    }

    // Restituisce il puntatore all'oggetto completo allocato
    return obj;
}
