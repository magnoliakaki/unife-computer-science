#include "myLib.h"

int main(int argc, char **argv) {
    Lista p;
    nuovaLista(&p);

    if (argc >= 2) {
        int a = 0;
        binLista(&p,argv[1]);
        stampaLista(&p);
        do a = ordinaListaPunt(&p); while (a > 0); 
        printf("--------------------------\n");
        stampaLista(&p);
    } else {
        printf("Troppi pochi argomenti");
    }
}