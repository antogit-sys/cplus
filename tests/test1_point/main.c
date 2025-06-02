#include <stdio.h>
#include <stdlib.h>
#include "../../include/cplus.h"
#include "Point/Point.h"

int main(){
    int done = EXIT_SUCCESS;  // Valore di ritorno che indica successo

    Point_o p = NEW(Point, 10, 20);  // Crea un nuovo oggetto Point con coordinate (10,20)
    if(p){
        //PointPrivate* priv = PRIVATE(p, Point);
        //priv->secret = 0;
        //PRIVATE(p, Point)->secret=0;

        // Ora posso usare direttamente la vtable perché PointVTable è definito
        p->METHODS->print(p);          // Chiama il metodo print dell’oggetto Point
        p->METHODS->setsec(p,23);      // Imposta il valore ‘secret’ a 23 tramite setsec
        p->METHODS->print(p);          // Stampa di nuovo lo stato aggiornato



        CALL_METHOD(p, print);          // Invoca il metodo print usando la macro CALL_METHOD
        p->METHODS->delete(p);          // Chiama il distruttore per liberare la memoria

    }else
        done = EXIT_FAILURE;            // Se l’allocazione fallisce, segnalo l’errore con valore di uscita FALLIMENTO

    return done;                       // Restituisco il codice di uscita
}


