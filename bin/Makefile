CXX = gcc
CXXFLAGS = -g -W

main: main.o dados_pacientes.o fila_espera.o log.o importar_arquivo.o lista_leitos.o pilha_altas.o
	$(CXX) $(CXXFLAGS) main.o dados_pacientes.o fila_espera.o log.o importar_arquivo.o lista_leitos.o  pilha_altas.o -o main

main.o: ../files/main.c ../files/dados_pacientes.h ../files/fila_espera.h ../files/log.h ../files/importar_arquivo.h ../files/lista_leitos.h ../files/pilha_altas.h
	$(CXX) $(CXXFLAGS) -c ../files/main.c -o main.o

dados_pacientes.o: ../files/dados_pacientes.c ../files/dados_pacientes.h
	$(CXX) $(CXXFLAGS) -c ../files/dados_pacientes.c -o dados_pacientes.o

fila_espera.o: ../files/fila_espera.c ../files/fila_espera.h
	$(CXX) $(CXXFLAGS) -c ../files/fila_espera.c -o fila_espera.o

log.o: ../files/log.c ../files/log.h
	$(CXX) $(CXXFLAGS) -c ../files/log.c -o log.o

importar_arquivo.o: ../files/importar_arquivo.c ../files/importar_arquivo.h ../files/dados_pacientes.h
	$(CXX) $(CXXFLAGS) -c ../files/importar_arquivo.c -o importar_arquivo.o

lista_leitos.o: ../files/lista_leitos.c ../files/lista_leitos.h
	$(CXX) $(CXXFLAGS) -c ../files/lista_leitos.c -o lista_leitos.o

pilha_altas.o: ../files/pilha_altas.c ../files/pilha_altas.h
	$(CXX) $(CXXFLAGS) -c ../files/pilha_altas.c -o pilha_altas.o

test: main
	./main

clean:
	rm -f *.o main