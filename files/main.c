// ler arquivo

// criar: dados pacientes, fila espera, lista leitos, pilha altas
// pode usar array ou vetor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#include "dados_pacientes.h"
#include "fila_espera.h"
#include "importar_arquivo.h"
#include "lista_leitos.h"
#include "pilha_altas.h"
#include "log.h"

int main()
{
    tabela_hash tabela;
    inicializar_tabela(&tabela);
    lerCSV(&tabela);

    FilaEspera fila;
    inicializar_fila(&fila);

    ListaLeitos leito;
    inicializar_leito(&leito);

    Alta pilha;
    inicializar_alta(&pilha);

    srand(time(NULL));
    iniciar_log();
    int ciclo = 0;
    while (true)
    {
        ciclo++;
        printf("\n[CICLO %02d]\n", ciclo);
        printf("espera: %d leitos: %d\n", fila.qtd, leito.qtd);

        // Passo 0 - Alta aleatoria
        if (leito_tem_paciente(&leito))
        {

            // srand(time(NULL));

            if (rand() % 3 == 1)
            {
                Paciente *paciente_alta = alta_aleatoria(&leito);
                inserir_pilha_alta(&pilha, paciente_alta);
                registrar_evento("ALTA", paciente_alta);
            }
        }

        // PASSO 1 - Internar paciente se possível
        if (fila_tem_pacientes(&fila) && !leito_cheio(&leito))
        {
            Paciente *internado = remover_maior_prioridade(&fila);
            inserir_leito(&leito, internado);
            registrar_evento("INTERNADO", internado);
        }

        // PASSO 2 - Inserir novo paciente na fila
        if (!fila_cheia(&fila) && pacientes_nao_atendidos(&tabela))
        {
            Paciente *novo = sortear_paciente(&tabela);
            inserir_fila_prioridade(&fila, novo);
            registrar_evento("ESPERA", novo);
            ;
        }

        // PASSO 3 - Encerrar se nada mais a fazer
        if (fila_vazia(&fila) && !pacientes_nao_atendidos(&tabela) && leito_vazio(&leito))
        {
            printf("\n>>> Fim da simulação.\n");
            break;
        }

        sleep(0.5);
    }

    return 0;
}
