#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_leitos.h"


void inicializar_leito(ListaLeitos* l){
    l->inicio = 0;
    l->fim = 0;
    l->qtd = 0;
}

int leito_vazio(ListaLeitos* l){
    return l->qtd == 0;
}

int leito_cheio(ListaLeitos* l){
    return l->qtd == TAM_LEITOS;
}

int leito_tem_paciente(ListaLeitos* l){
    return l->qtd > 0;
}

void inserir_leito(ListaLeitos* l, Paciente* p){
    if(leito_cheio(l)){
        return;
    }

    l->lista[l->qtd] = p;
    l->fim = l->qtd;
    l->qtd++;
    return;

}

Paciente* alta_aleatoria(ListaLeitos* l){
    if(leito_vazio(l)){
        return NULL;
    }

    //srand(time(NULL));
    int sorteado = rand() % l->qtd;
    Paciente* p = l->lista[sorteado];

    if(sorteado = l->fim){
        l->lista[sorteado] = NULL;
        l->qtd--;
        return p;
    }

    for(int i = sorteado; i < l->qtd; i++){
        l->lista[i] = l->lista[i+1];
    }

    l->qtd--;
    return p;

}