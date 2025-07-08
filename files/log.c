#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

static FILE* arquivo_log = NULL;

void iniciar_log() {
    arquivo_log = fopen("../log/processamento.log", "w"); // sobrescreve o antigo
    if (!arquivo_log) {
        perror("Erro ao criar arquivo de log");
        exit(1);
    }
}

void registrar_ciclo(int ciclo) {
    printf("\n[CICLO %02d]\n", ciclo);
    fprintf(arquivo_log, "\n[CICLO %02d]\n", ciclo);
}

void registrar_evento(const char* tipo, Paciente* p) {
    char id[10];
    converteCHAVE(p->chave, id);

    // Terminal
    if (strcmp(tipo, "ALTA") == 0)
        printf("ALTA       - %s (%s)\n", id, p->nome);
    else
        printf("%-11s- %s (%s) (prioridade %d)\n", tipo, id, p->nome, p->prioridade);

    // Arquivo
    if (strcmp(tipo, "ALTA") == 0)
        fprintf(arquivo_log, "ALTA       - %s (%s)\n", id, p->nome);
    else
        fprintf(arquivo_log, "%-11s- %s (%s) (prioridade %d)\n", tipo, id, p->nome, p->prioridade);
}
