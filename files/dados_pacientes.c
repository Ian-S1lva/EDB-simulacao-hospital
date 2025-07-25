//criar cabecalho .h
//criar corpo

//ESTRUTURA DE DADO: TABELHA HASH
//obs.: possiveis pacientes a serem inseridos na lista de espera

/*

capacidade = 50 registros

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dados_pacientes.h"

#define TAMANHO 10
#define TAMANHO_NOME 30

/*
ex. de tabela:

tamamanho = 10
funcao = chave%tamanho

hash 0 -> 10, 100
hash 1 -> 51
hash 2 -> NULL
...
hash 9 -> 99, 89, 39, 999

*/

//a funcao hash associa cada chave ao indice correspondente ao resto da divisao chave%tamanho na tabela hash
int funcao_hash(int chave)
{
  return chave % TAMANHO;
}

char* converteCHAVE(int chave, char *saida) {
    sprintf(saida, "PAC%03d", chave);
    return saida;
}

//cria um novo NO
Paciente *criar_no(int chave)
{
  Paciente *novo_no = (Paciente *)malloc(sizeof(Paciente));
  if(novo_no){
    novo_no->chave = chave;
    novo_no->proximo = NULL;
  }
  return novo_no;
}

//todos os indices hash sao zerados
void inicializar_tabela(tabela_hash *tabela)
{
    for(int i = 0; i < TAMANHO; i++){
        tabela->tabela[i] = NULL;
    }

    return;
}

//insere chave no seu hash correspondente, o novo elemento inserido se torna o 1º na lista da tabela hash
// ex.: hash i = NOVO elemento -> elemento antigo -> ... -> NULL
void inserir(tabela_hash *tabela, int chave, char *nome, int prioridade, int atendido)
{
  int indice = funcao_hash(chave);
  Paciente* novo_no = criar_no(chave);

  if(tabela->tabela[indice] == NULL){
    tabela->tabela[indice] = novo_no;
  }else{
    novo_no->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novo_no;
  }

  //inicializa atributos do novo no
    for(int i = 0; i < TAMANHO_NOME; i++){
    novo_no->nome[i] = nome[i];
    }
    novo_no->prioridade = prioridade;
    novo_no->atendido = atendido;

    return;
}

//busca no hash correspondente a chave, se há um elemento com a chave
//retorna sim ou nao
Paciente* buscar(tabela_hash *tabela, int chave)
{
  int indice = funcao_hash(chave);
  Paciente *atual = tabela->tabela[indice];

  while(atual != NULL){
    if(atual->chave == chave){
      return atual;
    }
      atual = atual->proximo;
  }

  return NULL;
}

// remove hash correspondente a chave, se existir
void remover(tabela_hash *tabela, int chave)
{
  int indice = funcao_hash(chave);
  Paciente *atual = tabela->tabela[indice];
  Paciente *anterior = NULL;

  while(atual != NULL)
  {
    if(atual->chave == chave){
      if (anterior == NULL) {
        tabela->tabela[indice] = atual->proximo;
      }else{
        anterior->proximo = atual->proximo;
      }
      free(atual);
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }

}

//NAO USADO
void imprimir_tabela(tabela_hash* tabela)
{
  for(int i = 0; i < TAMANHO; i++){
    printf("Índice %d:\n", i);
    Paciente* atual = tabela->tabela[i];
    while(atual != NULL){
      printf("%d  %s  %d  %d ->\n", atual->chave,atual->nome,atual->prioridade, atual->atendido);
      atual = atual->proximo;
    }
    printf("NULL\n");
  }
}

// Retorna 1 se ainda tiver pacientes não atendidos 
int pacientes_nao_atendidos(tabela_hash *tabela) {
    for (int i = 0; i < TAMANHO; i++) {
        Paciente *p = tabela->tabela[i];
        while (p != NULL) {
            if (p->atendido == 0) return 1;
            p = p->proximo;
        }
    }
    return 0;
}

Paciente* sortear_paciente(tabela_hash *tabela) {
    Paciente *candidatos[50];
    int total = 0;

    for (int i = 0; i < TAMANHO; i++) {
        Paciente *p = tabela->tabela[i];
        while (p != NULL) {
            if (p->atendido == 0) {
                candidatos[total++] = p;
            }
            p = p->proximo;
        }
    }

    if (total == 0) return NULL;

   // srand(time(NULL));
    int sorteado = rand() % total;
    candidatos[sorteado]->atendido = 1;
    return candidatos[sorteado];
}


/*
3 Verificar término de pacientes não atendidos na tabela hash:

Caso todos os pacientes já tenham sido transferidos da tabela hash para o deque, nenhuma nova entrada será possível.


===========================================================================================

Dados dos Pacientes

        Cada paciente é identificado por um conjunto de atributos contidos no arquivo pacientes.csv, com exatamente 50 entradas. Os campos esperados para cada paciente são:

        ID: Código identificador (ex: PAC001)
        Nome completo
        Idade
        Sexo
        CPF
        Prioridade: Valor inteiro de 1 a 5 (1 = baixa prioridade, 5 = emergência)
        Atendido: Valor lógico 0 ou 1
        O campo Atendido indica se o paciente já foi sorteado da tabela hash para o deque:

        0 → Paciente ainda não foi selecionado
        1 → Paciente já foi sorteado e não pode ser sorteado novamente
        O arquivo CSV deve conter uma linha por paciente, separando os campos por ponto e vírgula.

        Exemplo de linha no CSV:
        PAC001;Carlos Silva;54;M;12345678900;4;

*/
