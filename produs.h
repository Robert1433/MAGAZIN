//
// Created by Robert on 4/8/2024.
//

#ifndef MAGAZIN_PRODUS_H
#define MAGAZIN_PRODUS_H

#include "util.h"
int nr_produse;
typedef struct{
    int id;
    char nume[50];
    float pret;
    int cantitate;
}Produs;

void afisare_produse(Produs* produse){
    printf(" Produse disponibile:\n");
    printf("  ID | Nume           | Pret | Cantitate\n");
    printf("-----|----------------|------|-----------\n");
    for(int i=0;i<nr_produse;i++){
        printf("  %d | %-15s | %.2f | %d\n",produse[i].id,produse[i].nume,produse[i].pret,produse[i].cantitate);
    }
}

int cumparare_produs(Produs* produse,int id_produs, int cantitate){
    for(int i=0;i<nr_produse;i++){
        if(produse[i].id == id_produs){
            if(produse[i].cantitate >= cantitate){
                produse[i].cantitate -= cantitate;
                return 1;
            }else{
                return 0;
            }
        }
    }
    return 0;
}

Produs* citire_produse_csv(char* fisier){
    FILE* f = fopen(fisier,"r");
    if(f == NULL){
        printf("Nu se poate deschide fisierul!\n");
        return NULL;
    }
    int nr_produse;
    fscanf(f,"%d\n",&nr_produse);

    Produs* produse = malloc(sizeof (Produs) * nr_produse);
    if(produse == NULL){
        printf("Nu se poate aloca memorie pentru produse!\n");
        fclose(f);
        return NULL;
    }

    for(int i=0;i<nr_produse;i++){
        fscanf(f, "%d,%s,%f,%d\n", &produse[i].id, produse[i].nume, &produse[i].pret, &produse[i].cantitate);
    }
    fclose(f);
    free(produse);

    return produse;
}

void scriere_produse_csv(char* fisier, Produs* produse){
    FILE* f = fopen(fisier,"w");
    if(f == NULL){
        printf("Nu se poate deschide fisierul!\n");
        return;
    }
    fprintf(f,"%d\n",nr_produse);
    for(int i=0;i<nr_produse;i++){
        fprintf(f, "%d,%s,%.2f,%d\n", produse[i].id, produse[i].nume, produse[i].pret, produse[i].cantitate);
    }
    fclose(f);
}


#endif //MAGAZIN_PRODUS_H
