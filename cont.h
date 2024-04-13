//
// Created by Robert on 4/8/2024.
//

#ifndef MAGAZIN_CONT_H
#define MAGAZIN_CONT_H

#include "util.h"
#include "cont.h"

char* citire_string(char* mesaj){
    char * sir = malloc(100);
    printf("%s",mesaj);
    scanf(" %[^\n]%*c",sir);
    return sir;
}

int validare_parola(char* parola){
    int lungime = strlen(parola);
    int are_majuscula = 0;
    int are_minuscula = 0;
    int are_cifra = 0;
    for(int i=0;i<lungime;i++){
        if(parola[i] >= 'A' && parola[i] <= 'Z')
            are_majuscula = 1;
        else if (parola[i] >= 'a' && parola[i] <= 'z')
            are_minuscula = 1;
        else if (parola[i] >='0' && parola[i] <= '9')
            are_cifra = 1;
    }
    return lungime >=8 && are_majuscula && are_minuscula && are_cifra;
}






typedef struct {
    char username[50];
    char parola[50];
}Cont;


int numar_conturi(){
    int numar;
    FILE* f = fopen("conturi.csv","r");
    fscanf(f,"%d\n",&numar);
    return numar;
}




void creare_cont(Cont* conturi){
    int nr_conturi = numar_conturi();

    char* username = citire_string("Username: ");
    char* parola;

    do {
        parola = citire_string("Parola(Parola trebuie sa contina cel putin o majuscula si o cifra si 8 caractere): ");
    }while(!validare_parola(parola));
    for(int i=0;i<nr_conturi;i++){
        if(strcmp(conturi[i].username,username)==0){
            printf("Username-ul exista deja!\n");
            free(username);
            free(parola);
            return;
        }
    }



    strcpy(conturi[nr_conturi].username,username);
    strcpy(conturi[nr_conturi].parola,parola);
    nr_conturi++;



    //free(parola);
    //free(username);


}

int autentificare(Cont* conturi){
    int nr_conturi = numar_conturi();

    char* username = citire_string("Username: ");
    char* parola = citire_string("Parola: ");

    for(int i=0;i<nr_conturi;i++){
        if(strcmp(conturi[i].username,username) == 0 && strcmp(conturi[i].parola,parola)==0){
            free(username);
            free(parola);
            return 1;
        }
    }
    free(username);
    free(parola);
    return 0;
}

#endif //MAGAZIN_CONT_H
