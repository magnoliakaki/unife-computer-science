#include <stdio.h>

int giorno_giuliano(int giorno, int mese, int anno);

int main(){
    int G, M, A;

    printf("Inserisci la data da convertire: giorno, mese, anno\n");
    scanf("%d %d %d",&G,&M,&A);
    while((G>31)||(M>12)){
        printf("Data sbagliata!\n");
        scanf("%d %d %d",&G,&M,&A);
    }

    printf("\nGiorno giuliano corrispondente = %d",giorno_giuliano(G,M,A));
    return 0;
}

int giorno_giuliano(int giorno, int mese, int anno){
    int JD, N0, N1, N2, N3;

    N0=(mese-14)/12;
    N1=(1461*(anno+4800+N0))/4;
    N2=(367*(mese-2-12*N0))/12;
    N3=(3*(anno+4900+N0))/400;

    JD=N1+N2-N3+giorno-32075;
    return JD;
}