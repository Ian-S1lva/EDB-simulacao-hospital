// ler arquivo

// criar: dados pacientes, fila espera, lista leitos, pilha altas
// pode usar array ou vetor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "dados_pacientes.h"
#include "importar_arquivo.h"
#include "fila_espera.h"

int main(){
    bool continuar = true;
    bool verificar_paciente_fila, verificar_paciente_nao_atendido, verificar_paciente_alta;
    int cont = 0;
    Paciente paciente_alta, paciente_inernado, paciente_espera;

    tabela_hash tabela;
    inicializar_tabela(&tabela);
    lerCSV(&tabela);
    imprimir_tabela(&tabela);

    FilaEspera fila;
    inicializar_fila(&fila);

    int ciclo = 0;
    while (true)
    {
        ciclo++;
        printf("\n[CICLO %02d]\n", ciclo);

        // PASSO 1 - Internar paciente se possível
        if (fila_tem_pacientes(&fila))
        {
            Paciente *internado = remover_maior_prioridade(&fila);
            printf("INTERNADO - PAC%03d (%s) (prioridade %d)\n",
                   internado->chave, internado->nome, internado->prioridade);
        }

        // PASSO 2 - Inserir novo paciente na fila
        if (!fila_cheia(&fila) && existem_pacientes_nao_atendidos(&tabela))
        {
            Paciente *novo = sortear_paciente(&tabela);
            inserir_fila_prioridade(&fila, novo);
            printf("ESPERA - PAC%03d (%s) (prioridade %d)\n",
                   novo->chave, novo->nome, novo->prioridade);
        }

        // PASSO 3 - Encerrar se nada mais a fazer
        if (fila_vazia(&fila) && !existem_pacientes_nao_atendidos(&tabela))
        {
            printf("\n>>> Fim da simulação.\n");
            break;
        }

        sleep(2);
    }

    return 0;
}
// INICIALIZA DADOS
// lista_leitos lista_leito
// pilha_altas pilha_alta
// inicializar_lista_leito(&lista_leito)
// inicializar_pilha_altas(&pilha_alta)

/* int ciclo = 0;
 while(continuar){
     ciclo++;

     if(ciclo>5){//só para nao rodar infinito
         continuar = 0;
     }

     //FUNCOES CHAMADAS POR CICLO
     //esboco
     /*
     verificar_paciente_fila = verificar_paciente_fila(fila_espera);
     verificar_paciente_nao_atendido = verificar_paciente_nao_atendido(tabela);
     verificar_paciente_alta = verificar_paciente_alta(lista_leito);

     */

/*
if(verificar_paciente_alta && chance_aleatoria(50%)){
    paciente_alta = retorno_leito(lista_leito);
    incluir_alta(pilha_alta, paciente_alta);
}
*/

/*
if(verificar_paciente_fila && verificar_vaga_leito(lista_leito)){
    paciente_leito = paciente_prioridade_fila(fila_espera);
    incluir_leito(lista_leito, paciente_leito);
}
*/

/*
if(verificar_paciente_nao_atendido && verificar_vaga_fila(fila_espera)){
    paciente_espera = tabela_retorno_aleatorio(tabela);
    incluir_fila_prioridade(fila_espera, paciente_espera);
}
*/

/*
if(!verificar_paciente_fila && !verificar_paciente_nao_atendido && !verificar_paciente_alta){
        continuar = false;
}



sleep(2);

printf("\n[CICLO %d]\n"
        "ALTA - PAC INT(STRING)\n"
        "INTERNADO - PAC INT (prioridade INT)\n"
        "ESPERA - PAC INT (prioridade INT)\n",ciclo);
//Adicionar no log - por print no arquivo
}


OK iterar ciclo (a cada 2 segundos) done

1. Atualiza leito
Atualiza alta

2. Atualiza fila de espera

3. Atualiza dados de pacientes

registrar no log


//encerra quando dados_pacientes, fila_espera, lista_leitos estiverem todos vazios
return 0;
}*/

/* LOGS

Todos os eventos devem ser registrados:

Em tempo real no terminal.
Em arquivo: processamento.log
Formato do Log: Cada evento deve estar em uma linha distinta, conforme o exemplo abaixo:

[CICLO 05]
ALTA - PAC011 (Carlos Lima)
INTERNADO - PAC007 (prioridade 5)
ESPERA - PAC024 (prioridade 3)
Essa estrutura permite maior organiza��o e an�lise dos eventos ocorridos durante a simula��o.


*/
