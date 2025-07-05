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


//cada No tem uma chave, e aponta para o proximo no do mesmo HASH
typedef struct No{
  int chave; //lê apenas o numero, ex.: PAC001 -> 001

  char nome[TAMANHO_NOME];
  int prioridade;
  int atendido;

  struct No *proximo;
} No;

//tabela hash é um array, cada indice associa um hash
typedef struct tabela_hash{
  No *tabela[TAMANHO];
}tabela_hash;


//a funcao hash associa cada chave ao indice correspondente ao resto da divisao chave%tamanho na tabela hash
int funcao_hash(int chave)
{
  return chave % TAMANHO;
}

//cria um novo NO
No *criar_no(int chave)
{
  No *novo_no = (No *)malloc(sizeof(No));
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
}

//insere chave no seu hash correspondente, o novo elemento inserido se torna o 1º na lista da tabela hash
// ex.: hash i = NOVO elemento -> elemento antigo -> ... -> NULL
void inserir(tabela_hash *tabela, int chave, char *nome, int prioridade, int atendido)
{
  int indice = funcao_hash(chave);
  No* novo_no = criar_no(chave);

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


}

//busca no hash correspondente a chave, se há um elemento com a chave
//retorna sim ou nao
No* buscar(tabela_hash *tabela, int chave)
{
  int indice = funcao_hash(chave);
  No *atual = tabela->tabela[indice];

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
  No *atual = tabela->tabela[indice];
  No *anterior = NULL;

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
    printf("Índice %d: ", i);
    No* atual = tabela->tabela[i];
    while(atual != NULL){
      printf("%d -> ", atual->chave);
      atual = atual->proximo;
    }
    printf("NULL\n");
  }
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