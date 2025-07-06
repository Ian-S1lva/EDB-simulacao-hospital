#ifndef LISTA_LEITOS_H
#define LISTA_LEITOS_H
#define TAM_LEITOS 10
#include "dados_pacientes.h"

typedef struct {
    Paciente* lista[TAM_LEITOS];
    int inicio;
    int fim;
    int qtd;
} ListaLeitos;

void inicializar_leito(ListaLeitos* l);
int leito_vazio(ListaLeitos* l);
int leito_cheio(ListaLeitos* l);
int leito_tem_paciente(ListaLeitos* l);
void inserir_leito(ListaLeitos* l, Paciente* p);
Paciente* alta_aleatoria(ListaLeitos* l);



#endif