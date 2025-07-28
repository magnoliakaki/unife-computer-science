#include <stdio.h>
/* cat __file__ | __a.exe__*/

void aggiungi(long long int id);
void togli(long long int id);
int conta(long long int id);

long long int biblioteca[200000][2];
int tot_libri;

void aggiungi(long long int id){
    int h, tr;
    tr=0;
    for(h=0;h<tot_libri;h++){
        if(biblioteca[h][0]==id) {
            biblioteca[h][1]++;
            tr=2;
            break;
        }
    }    

    if(tr==0){
    biblioteca[tot_libri][0]=id; 
    biblioteca[tot_libri][1]++;
    tot_libri++;
    }      
}

void togli(long long int id){
    int h;
    for(h=0;h<tot_libri;h++){
        if(biblioteca[h][0]==id) {
            biblioteca[h][1]--;
            if(biblioteca[h][1]==0){
                biblioteca[h][0]==0;
    
            }
            break;
        }
    }     
}

int conta(long long int id){
    int h, c;
    c=0;
    for(h=tot_libri-1;h>=0;h--){
        if(biblioteca[h][0]==id) {
            c=biblioteca[h][1];
            return c;
        }
    }  
    return c;
}