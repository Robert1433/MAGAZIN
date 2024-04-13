#ifndef MAGAZIN_UTIL_H
#define MAGAZIN_UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cont.h"

/*char* citire_string(char* mesaj){
    char * sir = malloc(100);
    printf("%s",mesaj);
    scanf(" %[^\n]%*c",sir);
    return sir;
}*/

//verificam daca parola introdusa este valida si sigura



//citire conturi din csv
int nr_conturi;
Cont* citire_conturi_csv(char* fisier){
    FILE* f = fopen(fisier,"r");
    if(f == NULL){
        printf("Nu exista fisierul %s!\n",fisier);
        return NULL;
    }
    //int nr_conturi;
    fscanf(f,"%d\n",&nr_conturi);
    Cont* conturi = malloc(sizeof(Cont)*nr_conturi);
    if(conturi ==  NULL){
        printf("Nu se poate aloca memorie pentru conturi!\n");
        fclose(f);
        return NULL;
    }
    for(int i=0;i<nr_conturi;i++){
        fscanf(f,"%s,%s\n",conturi[i].username,conturi[i].parola);
    }
    fclose(f);
    return conturi;
}

//scriere conturi csv

void scriere_conturi_csv(char* fisier, Cont* conturi){
    FILE* f = fopen(fisier,"w");
    if(f == NULL){
        printf("Nu se poate deschide fisierul!\n");
        return;
    }
    fprintf(f,"%d\n",nr_conturi);
    for(int i=0;i<nr_conturi;i++){
        fprintf(f,"%s,%s\n",conturi[i].username,conturi[i].parola);
    }
    fclose(f);
}


#endif //MAGAZIN_UTIL_H
