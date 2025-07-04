//criar cabecalho .h
//criar corpo

//ESTRUTURA DE DADO: TABELHA HASH
//obs.: possiveis pacientes a serem inseridos na lista de espera

/*

capacidade = 50 registros

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