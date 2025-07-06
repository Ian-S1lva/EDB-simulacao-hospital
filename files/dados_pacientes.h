#define TAMANHO 10
#define TAMANHO_NOME 30
#ifndef DADOS_PACIENTES_H
#define DADOS_PACIENTES_H


//struct
typedef struct Paciente{
//cada No tem uma chave, e aponta para o proximo no do mesmo HASH
  int chave; //l� apenas o numero, ex.: PAC001 -> 001

  char nome[TAMANHO_NOME];
  int prioridade;
  int atendido;

  struct Paciente *proximo;
} Paciente;

typedef struct tabela_hash{
//tabela hash � um array, cada indice associa um hash
  Paciente *tabela[TAMANHO];
}tabela_hash;


int funcao_hash(int chave);
Paciente *criar_no(int chave);

void inicializar_tabela(tabela_hash *tabela);
void inserir(tabela_hash *tabela, int chave, char *nome, int prioridade, int atendido);
Paciente* buscar(tabela_hash *tabela, int chave);
void remover(tabela_hash *tabela, int chave);
//NAO USADO
void imprimir_tabela(tabela_hash* tabela);
int pacientes_nao_atendidos(tabela_hash *tabela);
Paciente* sortear_paciente(tabela_hash *tabela);
char* converteCHAVE(int chave, char *saida);
#endif
