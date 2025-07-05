#define TAMANHO 10
#define TAMANHO_NOME 30


//struct
typedef struct No{
//cada No tem uma chave, e aponta para o proximo no do mesmo HASH
  int chave; //lê apenas o numero, ex.: PAC001 -> 001

  char nome[TAMANHO_NOME];
  int prioridade;
  int atendido;

  struct No *proximo;
} No;

typedef struct tabela_hash{
//tabela hash é um array, cada indice associa um hash
  No *tabela[TAMANHO];
}tabela_hash;


int funcao_hash(int chave);
No *criar_no(int chave);

void inicializar_tabela(tabela_hash *tabela);
void inserir(tabela_hash *tabela, int chave, char *nome, int prioridade, int atendido);
No* buscar(tabela_hash *tabela, int chave);
void remover(tabela_hash *tabela, int chave);
//NAO USADO
void imprimir_tabela(tabela_hash* tabela);
