#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "cont.h"
#include "produs.h"

int main() {
    Cont* conturi = citire_produse_csv("conturi.csv");
    Produs* produse = citire_produse_csv("produse.csv");

    int optiune;

    do{
        printf("1. Creare cont\n");
        printf("2. Autentificare\n");
        printf("0. Iesire\n");
        scanf("%d",&optiune);

        switch (optiune) {
            case 1:
                creare_cont(conturi);
                break;
            case 2:
                if(autentificare(conturi)){
                    afisare_produse(produse);
                    int id_produs,cantitate;
                    printf("Introduceti ID-ul produsului: ");
                    scanf("%d",&id_produs);
                    printf("Introduceti cantitatea: ");
                    scanf("%d",&cantitate);
                    if(cumparare_produs(produse,id_produs,cantitate)){
                        printf("Produsul a fost achizitonat cu succes!\n");
                    } else{
                        printf("Stoc insuficient pentru produsul selectat,\n");
                    }
                }else{
                    printf("Date de autentificare incorecte!\n");
                }
                break;
            case 0:
                printf("La revedere!\n");
                break;
            default:
                printf("Optiune invalida");
        }

    }while(optiune != 0);

    scriere_conturi_csv("conturi.csv", conturi);
    scriere_produse_csv("produse.csv",produse);

    free(conturi);
    free(produse);
    return 0;
}
