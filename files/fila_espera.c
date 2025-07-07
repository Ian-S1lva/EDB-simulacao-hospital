#include <stdio.h>
#include <stdlib.h>
#include "fila_espera.h"

void inicializar_fila(FilaEspera* f) {
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

int fila_cheia(FilaEspera* f) {
    return f->qtd >= TAM_FILA;
}

int fila_vazia(FilaEspera* f) {
    return f->qtd == 0;
}

int fila_tem_pacientes(FilaEspera* f) {
    return f->qtd > 0;
}

void inserir_fila_prioridade(FilaEspera* f, Paciente* p) {
    if (fila_cheia(f)) return;

    // Inserção do primeiro elemento
    if (f->qtd == 0) {
        f->inicio = f->fim = 0;
        f->fila[0] = p;
    }
    // Alta prioridade (>= 4) → insere no início
    else if (p->prioridade >= 4) {
        f->inicio = (f->inicio - 1 + TAM_FILA) % TAM_FILA;
        f->fila[f->inicio] = p;
    }
    // Prioridade baixa → insere no fim
    else {
        f->fim = (f->fim + 1) % TAM_FILA;
        f->fila[f->fim] = p;
    }

    f->qtd++;
}

Paciente* remover_maior_prioridade(FilaEspera* f) {    
    if (fila_vazia(f)) return NULL;
    
    Paciente* p_inicio = f->fila[f->inicio];
    Paciente* p_fim = f->fila[f->fim];
    Paciente* escolhido;

    if (p_inicio->prioridade >= p_fim->prioridade) {
        escolhido = p_inicio;
        f->inicio = (f->inicio + 1) % TAM_FILA;
    } else {
        escolhido = p_fim;
        f->fim = (f->fim - 1 + TAM_FILA) % TAM_FILA;
    }

    f->qtd--;
    return escolhido;
}

/*

capacidade maxima = 20

2 Verificar espaço na fila de espera (deque):

Se houver espaço e pacientes ainda não sorteados na tabela hash, sortear aleatoriamente um deles e inseri-lo no deque conforme sua prioridade:
Prioridade 4 ou 5 → início do deque.
Prioridade 1, 2 ou 3 → fim do deque.

=======================================================================

B Regras de Inserção e Remoção no Deque (Fila de Espera)

    Inserção: A inserção de pacientes no deque segue a seguinte lógica:

    Pacientes com prioridade 4 ou 5 (alta ou emergência) são inseridos na frente do deque.
    Pacientes com prioridade 1, 2 ou 3 (baixa a moderada) são inseridos no fim do deque.
    Remoção: A cada ciclo, para verificar se um paciente pode ser internado:

    A simulação compara os dois extremos do deque (frente e fim).
    Remove-se o paciente com maior prioridade entre as extremidades.
    Em caso de empate, priorizar a extremidade da frente.
    Exemplo:
    Deque = [ PAC017 (prio 5), ..., PAC043 (prio 4) ] → PAC017 e PAC043 são comparados.
    Como ambos têm alta prioridade, remove-se PAC017 (está na frente).

*/
