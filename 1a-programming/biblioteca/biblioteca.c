#include <stdio.h>
#include <time.h>
/* cat __file__ | __a.exe__*/

void aggiungi(long long int id);
void togli(long long int id);
int conta(long long int id);

long long int biblioteca[200000][2];
int tot_libri;

int main(){
    long long int ope_tot,i,id,j;
    char ope;
    FILE *fptr; 
    clock_t start, end;
    double duration, dur_a, dur_t, dur_c;
    int a,t,c;

    tot_libri = 0;
    fptr = fopen("D:\\Docs\\GitHub\\Programmazione\\biblioteca\\tempi.txt","w");   

    fprintf(fptr,"Inizializzazione array\n");
    start=clock();
    for(j=0;j<200000;j++){
        biblioteca[j][0]=0;
        biblioteca[j][1]=0;
    }
    end=clock();
    duration=(double)end - (double)start;
    duration = duration/CLOCKS_PER_SEC;
    fprintf(fptr,"------- tempo =%f\n",duration);

    scanf(" %lld",&ope_tot);

    dur_a=0; 
    dur_t=0; 
    dur_c=0;
    a=0;
    c=0;
    t=0;

    for(i=0;i<ope_tot;i++){
        scanf(" %c %lld",&ope,&id);        
        switch(ope){
            case 'a':
                start=clock();
                aggiungi(id);
                end=clock();
                dur_a+=((double)end - start);
                a+=1;
                break;
            case 't':
                start=clock();            
                togli(id);
                end=clock();
                dur_t+=((double)end - start); 
                t+=1;         
                break;
            case 'c':
                //printf("%d\n",conta(id));
                //fprintf(fptr,"%d\n",conta(id));
                start=clock();                
                conta(id);
                end=clock();
                dur_c+=((double)end - start);   
                c+=1;         
                break;
        }
    }

    fprintf(fptr,"Tempo aggiungi =%f -- per %d volte (tempo per chiamata =%f)\n",dur_a/CLOCKS_PER_SEC,a,(dur_a/CLOCKS_PER_SEC)/a);    
    fprintf(fptr,"Tempo togli =%f-- per %d volte (tempo per chiamata =%f)\n",dur_t/CLOCKS_PER_SEC,t,(dur_t/CLOCKS_PER_SEC)/t);   
    fprintf(fptr,"Tempo conta =%f-- per %d volte (tempo per chiamata =%f)\n",dur_c/CLOCKS_PER_SEC,c,(dur_c/CLOCKS_PER_SEC)/c); 
    fprintf(fptr,"Tempo totale = %f",duration+(dur_a/CLOCKS_PER_SEC)+(dur_t/CLOCKS_PER_SEC)+(dur_c/CLOCKS_PER_SEC));             
    fclose(fptr);
    return 0;
}

void aggiungi(long long int id){
    int h, tr;
    for(h=0;h<tot_libri;h++){
        if(biblioteca[h][0]==id) {
            biblioteca[h][1]++;
            return;
        }
    }    
    biblioteca[tot_libri][0]=id; 
    biblioteca[tot_libri][1]++;
    tot_libri++;
}

void togli(long long int id){
    int h;
    for(h=0;h<tot_libri;h++){
        if(biblioteca[h][0]==id) {
            biblioteca[h][1]--;
            return;
        }
    }     
}

int conta(long long int id){
    int h, c;
    c=0;
    for(h=0;h<tot_libri;h++){
        if(biblioteca[h][0]==id) {
            return biblioteca[h][1];
        }
    }  
    return c;
}