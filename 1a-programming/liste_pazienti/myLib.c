#include "myLib.h"

struct paziente {
    Str crn;
    int ora;
    float temp; 
    float sat;
};

struct nodo {
    Paziente p;
    int cont;
    struct nodo *next; 
};

//
void nuovaLista(Lista *pl) {
    *pl = NULL;
}

//
int ordinaLista(Lista *pl) {
    int a = 0;
    if (*pl == NULL || (*pl)->next == NULL) {
        printf("Lista vuota o con unico elemento.\n");
        return 0;
    }
    while(*pl) {
        if ((*pl)->next != NULL) {
            float t1 = (*pl)->p.temp/(*pl)->cont; 
            float t2 = (*pl)->next->p.temp/(*pl)->next->cont;
            if (t1 > t2) {
                Paziente tmp = (*pl)->p;
                int tmpcont  = (*pl)->cont;
                (*pl)->p = (*pl)->next->p;
                (*pl)->cont = (*pl)->next->cont;
                (*pl)->next->p = tmp; 
                (*pl)->next->cont = tmpcont; 
                a++;
            }
        }
        pl = &(*pl)->next;
    }
    return a;
}

//
int ordinaListaPunt(Lista *pl) {
    int a = 0;
    Nodo *prev = NULL; 
    if (*pl == NULL || (*pl)->next == NULL) {
        printf("Lista vuota o con unico elemento.\n");
        return 0;
    }
    while(*pl) {
        if ((*pl)->next != NULL) {
            float t1 = (*pl)->p.temp/(*pl)->cont; 
            float t2 = (*pl)->next->p.temp/(*pl)->next->cont;
            if (t1 > t2) {
                Nodo *succ = (*pl)->next;
                (*pl)->next = succ->next; 
                succ->next = *pl;
                if (prev != NULL) prev->next = succ;
                else *pl = succ;     
                a++;
            }
        }
        prev = *pl; 
        pl = &(*pl)->next;
    }
    return a;
}

//
void insTesta(Lista *pl, Paziente p) {
    Nodo *n = (Nodo*)calloc(1,sizeof(Nodo));
    if (n == NULL) {
        printf("Allocazione fallita");
        exit(1);
    } else {
        n->cont = 1;
        strcat(n->p.crn,p.crn);
        n->p.ora = p.ora;
        n->p.temp = p.temp;
        n->p.sat = p.sat;
        n->next = *pl;
        *pl = n;
    }
}

//
void insCoda(Lista *pl, Paziente p) {
    Nodo *n = (Nodo*)calloc(1,sizeof(Nodo));
    // in calloc c'è anche il numero di blocchi di quella dimensione da allocare
    if (n == NULL) {
        printf("Allocazione fallita");
        exit(1);
    } else {
        while (*pl) pl = &(*pl)->next;
        n->cont = 1;
        strcat(n->p.crn,p.crn);
        n->p.ora = p.ora;
        n->p.temp = p.temp;
        n->p.sat = p.sat;
        n->next = NULL;
        if (*pl == NULL) *pl = n;
        else (*pl)->next = n;
    }    
}

//
void insOrd(Lista *pl, Paziente p) {}

//
void stampaLista(Lista *pl) {
    while (*pl) {
        printf("%s %.1f %.1f\n",(*pl)->p.crn,(*pl)->p.temp/(*pl)->cont,(*pl)->p.sat/(*pl)->cont);
        pl = &(*pl)->next; 
    }
}

//
void binLista(Lista *pl, char *nomeFile) {
    FILE *fp = fopen(nomeFile,"rb");
    if (fp == NULL) {
        printf("Errore di apertura file");
        exit(1);
    } else {
        Paziente tmp; 
        while ( fread(&tmp,sizeof(Paziente),1,fp) == 1 ) {
            if ( cercaDato(pl,tmp) == 0 ) insTesta(pl,tmp); 
        }
    }
}

//
void eliminaVal(Lista *pl) {
    int b = 0;
    while (*pl) {
        b++;
        char anno[2] = {(*pl)->p.crn[6], (*pl)->p.crn[7]};
        if ( (atoi(anno) > 50 && (((*pl)->p.temp/(*pl)->cont) <= 37.5) && (((*pl)->p.sat/(*pl)->cont) >= 96)) ) {
            Nodo *tmp = *pl;
            *pl = (*pl)->next;
            free(tmp);
        }
        if (*pl != NULL) pl = &(*pl)->next; 
        
    }
}

//
int cercaDato(Lista *pl, Paziente p) {
    int tr = 0;
    while (*pl) {
        if ( strcmp((*pl)->p.crn,p.crn) == 0 ) {
            (*pl)->cont += 1;
            (*pl)->p.temp += p.temp;
            (*pl)->p.sat += p.sat;
            tr = 1;
            break;
        }
        pl = &(*pl)->next; 
    }
    return tr;
}