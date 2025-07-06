
#ifndef PILHA_ALTAS_H
#define PILHA_ALTAS_H
#define TAM_PILHA 55
#include "dados_pacientes.h"

typedef struct {
    Paciente* pilha[TAM_PILHA];
    int topo;
    int qtd;
} Alta;

void inicializar_alta(Alta* a);
int alta_vazia(Alta* a);
void inserir_pilha_alta(Alta* a, Paciente* p);

#endif

