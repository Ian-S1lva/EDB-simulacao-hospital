//criar cabecalho .h
//criar corpo

//ESTRUTURA DE DADO: DEQUE
//obs.:

/*

capacidade maxima = 20

2 Verificar espaço na fila de espera (deque):

Se houver espaço e pacientes ainda não sorteados na tabela hash, sortear aleatoriamente um deles e inseri-lo no deque conforme sua prioridade:
Prioridade 4 ou 5 → início do deque.
Prioridade 1, 2 ou 3 → fim do deque.

=======================================================================

B Regras de Inserção e Remoção no Deque (Fila de Espera)

    Inserção: A inserção de pacientes no deque segue a seguinte lógica:

    Pacientes com prioridade 4 ou 5 (alta ou emergência) são inseridos na frente do deque.
    Pacientes com prioridade 1, 2 ou 3 (baixa a moderada) são inseridos no fim do deque.
    Remoção: A cada ciclo, para verificar se um paciente pode ser internado:

    A simulação compara os dois extremos do deque (frente e fim).
    Remove-se o paciente com maior prioridade entre as extremidades.
    Em caso de empate, priorizar a extremidade da frente.
    Exemplo:
    Deque = [ PAC017 (prio 5), ..., PAC043 (prio 4) ] → PAC017 e PAC043 são comparados.
    Como ambos têm alta prioridade, remove-se PAC017 (está na frente).

*/