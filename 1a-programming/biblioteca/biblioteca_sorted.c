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
    fptr = fopen("D:\\Docs\\GitHub\\Programmazione\\biblioteca\\tempi_s.txt","w");   

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
                fprintf(fptr,"%d\n",conta(id));
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
    fprintf(fptr,"Tempo totale = %f\n",duration+(dur_a/CLOCKS_PER_SEC)+(dur_t/CLOCKS_PER_SEC)+(dur_c/CLOCKS_PER_SEC));           
    fclose(fptr);
    return 0;
}

void aggiungi(long long int id){
    int mid,low,high,found,i;

    mid=0;
    found=0;
    low=0;
    high=tot_libri;

    while(low<=high){
        mid = low+(high-low)/2;
        //printf("mid=%d,low=%d,high=%d\n",mid,low,high);
        if(biblioteca[mid][0]==id){
            biblioteca[mid][1]++;
            found=2;
            break;
        } else if(id<biblioteca[mid][0]) high = mid-1; 
        else low = mid+1;
    }

    if(found==0){ //return;
            if((biblioteca[mid][0]<id)&&(mid<tot_libri)) mid+=1;
            for(i=tot_libri-1;i>=mid;i--){
                biblioteca[i+1][0]=biblioteca[i][0];
                biblioteca[i+1][1]=biblioteca[i][1];        
            }
            biblioteca[mid][0]=id;
            biblioteca[mid][1]=1;
            tot_libri++;
    }
    
    // printf("------------------------------\n");
    // for(i=0;i<tot_libri;i++){
    //     printf("%d,",biblioteca[i][0]);
    // }
    // printf("\n");
    // for(i=0;i<tot_libri;i++){
    //     printf("%d,",biblioteca[i][1]);
    // }
    //     printf("\n");
    // printf("------------------------------\n");        
}

void togli(long long int id){
    int mid,low,high;

    mid=0;
    low=0;
    high=tot_libri;

    while(low<=high){
        mid = low+(high-low)/2;
        if(biblioteca[mid][0]==id){
            biblioteca[mid][1]--;
            break;
        } else if(id<biblioteca[mid][0]) high = mid-1; 
        else low = mid+1;
    }
}

int conta(long long int id){
    int mid,low,high;

    mid=0;
    low=0;
    high=tot_libri;

    while(low<=high){
        mid = low+(high-low)/2;
        if(biblioteca[mid][0]==id){
            return biblioteca[mid][1];
        } else if(id<biblioteca[mid][0]) high = mid-1; 
        else low = mid+1;
    }
    return 0;
}