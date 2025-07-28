#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paziente Paziente;
typedef struct nodo Nodo;
typedef char Str[17];
typedef Nodo *Lista;

void nuovaLista(Lista *pl);
int ordinaLista(Lista *pl);
int ordinaListaPunt(Lista *pl);
void insTesta(Lista *pl, Paziente p);
void insCoda(Lista *pl, Paziente p);
void insOrd(Lista *pl, Paziente p);
void stampaLista(Lista *pl);
void binLista(Lista *pl, char *nomeFile);
void eliminaVal(Lista *pl);
int cercaDato(Lista *pl, Paziente p);

