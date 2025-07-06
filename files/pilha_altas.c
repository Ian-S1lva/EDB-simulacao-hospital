#include <stdio.h>
#include <stdlib.h>
#include "pilha_altas.h"

void inicializar_alta(Alta* a){
    a->topo = 0;
    a->qtd = 0;
}
int alta_vazia(Alta* a){
    return a->qtd == 0;
}
void inserir_pilha_alta(Alta* a, Paciente* p){
    if(alta_vazia(a)){
        a->pilha[a->topo] = p;
        a->qtd++;
        return;
    }

    a->pilha[a->topo+1] = p;
    a->qtd++;
    a->topo++;
    return;
}