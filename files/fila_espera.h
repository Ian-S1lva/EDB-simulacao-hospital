#ifndef FILA_ESPERA_H
#define FILA_ESPERA_H

#include "dados_pacientes.h"

#define TAM_FILA 20

typedef struct {
    Paciente* fila[TAM_FILA];
    int inicio;
    int fim;
    int qtd;
} FilaEspera;

void inicializar_fila(FilaEspera* f);
int fila_cheia(FilaEspera* f);
int fila_vazia(FilaEspera* f);
void inserir_fila_prioridade(FilaEspera* f, Paciente* p);
Paciente* remover_maior_prioridade(FilaEspera* f);
int fila_tem_pacientes(FilaEspera* f);

#endif
