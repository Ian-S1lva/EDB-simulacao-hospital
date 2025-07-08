#ifndef LOG_H
#define LOG_H

#include "dados_pacientes.h"

void iniciar_log();
void registrar_ciclo(int ciclo);
void registrar_evento(const char* tipo, Paciente* p);

#endif
