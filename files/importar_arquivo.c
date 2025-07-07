#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "dados_pacientes.h"
#include "importar_arquivo.h"
#define TAMANHO_LINHA 200

int lerCSV(tabela_hash *tabela){
    FILE* arquivo;
    arquivo = fopen("../input/pacientes.csv", "r");
    if (!arquivo) {
        perror("Arquivo pacientes.csv nao encontrado.\n");
        return 1;
    }
        /* CAMPOS RELEVANTES: 0,1,5,6
          0->  ID: C�digo identificador (ex: PAC001)
          1->  Nome completo
          2  Idade     3  Sexo      4  CPF
          5->  Prioridade: Valor inteiro de 1 a 5 (1 = baixa prioridade, 5 = emerg�ncia)
          6->  Atendido: Valor l�gico 0 ou 1
        */
    char linha[TAMANHO_LINHA];
    char campo[30];

    int chave; //l� apenas o numero, ex.: PAC001 -> 001
    char nome[30];
    int prioridade;
    int atendido;

    fgets(linha, sizeof linha, arquivo);
    while(fgets(linha, sizeof linha, arquivo) != NULL){//enquanto ler linhas
        //separacao da entrada em campos
        int i = 0, j = 0, k = 0;
        for(; linha[i] != '\0'; i++){
        // i percorre a linha lida
        // j conta os campos separados por ';'
        // k marca posição do último ';'
            if(linha[i] == ';'){
                strncpy(campo, &linha[k], i-k);
                campo[i-k] = '\0';
                if(j == 0){
                    int n = strlen(campo) - 1;
                    chave = campo[n] - '0' + 10*(campo[n-1] - '0') + 100*(campo[n-2] - '0');
                }
                else if(j == 1){
                    strncpy(nome,campo,strlen(campo)+1);
                }
                else if(j == 5){
                    prioridade = campo[0] - '0';
                }
                j++;
                k = i + 1;
            }
        }
        //ultimo n�o tem ponto e virgula, essa parte roda mais uma vez para cobrir esse caso
        strncpy(campo, &linha[k], i-k);
        campo[i-k] = '\0';
        atendido = campo[0] - '0';
        //depois de analisar o campo, insere na tabela
        inserir(tabela, chave, nome, prioridade, atendido);
    }
    fclose(arquivo);
    return 0;
}
