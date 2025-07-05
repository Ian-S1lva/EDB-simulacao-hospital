//ler arquivo

//criar: dados pacientes, fila espera, lista leitos, pilha altas
//pode usar array ou vetor
#include "../dados_pacientes.h"
#define TAMANHO_LINHA 100

int lerCSV(const char* nome_arquivo, tabela_hash *tabela) {
    FILE* arquivo = fopen("input/pacientes.csv", "r");
    if (!arquivo) {
        perror("Arquivo pacientes.csv nao encontrado na pasta \"input\".\n");
        return 1;
    }
  
    char linha[TAMANHO_LINHA];

  int chave; //lê apenas o numero, ex.: PAC001 -> 001
  char nome[TAMANHO_NOME];
  int prioridade;
  int atendido;

    while(fscanf(arquivo, "%s", linha) != -1){//enquanto ler linhas
    
        //analise a entrada por campos
    for(int i = 0, j = 0, k = 0  ; i < TAMANHO_LINHA; i++){
        // i percorre a linha lida
        // j conta os campos separados por ';'
        // k marcaa posição do último ';'
        /* CAMPOS RELEVANTES: 0,1,5,6
      0->  ID: Código identificador (ex: PAC001)
      1->  Nome completo
      2  Idade     3  Sexo      4  CPF
      5->  Prioridade: Valor inteiro de 1 a 5 (1 = baixa prioridade, 5 = emergência)
      6->  Atendido: Valor lógico 0 ou 1
        */

        if(campo[i] == ';'){
            char campo[30];
            strncpy(campo, &linha[k], k-i+1);    
            
            if(j == 0){
                int n = strlen(campo) - 1;
                chave = campo[n] - '0' + 10*(campo[n-1] - '0') + 100*(campo[n-2] - '0');
            }
            else if(j == 1){
                strncpy(nome,campo,strlen(campo));
            }
            else if(j == 5){
                prioridade = campo[0] - '0';
            }
            else if(j == 6){
                atendido = campo[0] - '0';
            }

            //mais um ';'
            j++;
            k = i;
        }
    }
    //depois de analisar o campo, insere na tabela
    inserir(tabela, chave, nome, prioridade, atendido);
}
    
    fclose(arquivo);
    return 0;
}


int main(){



    
/* 
iterar ciclo (a cada 2 segundos)

1. Atualiza leito
    Atualiza alta

2. Atualiza fila de espera

3. Atualiza dados de pacientes

registrar no log
*/

//encerra quando dados_pacientes, fila_espera, lista_leitos estiverem todos vazios
return 0;
}

/* LOGS

Todos os eventos devem ser registrados:

Em tempo real no terminal.
Em arquivo: processamento.log
Formato do Log: Cada evento deve estar em uma linha distinta, conforme o exemplo abaixo:

[CICLO 05]
ALTA - PAC011 (Carlos Lima)
INTERNADO - PAC007 (prioridade 5)
ESPERA - PAC024 (prioridade 3)
Essa estrutura permite maior organização e análise dos eventos ocorridos durante a simulação.


*/