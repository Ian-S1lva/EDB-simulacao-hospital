CXX = gcc
CXXFLAGS = -g -W

main: main.o dados_pacientes.o fila_espera.o lista_leitos.o pilha_altas.o
	$(CXX) $(CXXFLAGS) main.o dados_pacientes.o fila_espera.o lista_leitos.o pilha_altas.o -o main

main.o:
	$(CXX) $(CXXFLAGS) -c files/main/main.c

dados_pacientes.o: dados_pacientes.c dados_pacientes.h
	$(CXX) $(CXXFLAGS) -c dados_pacientes.c

fila_espera.o: fila_espera.c fila_espera.h
	$(CXX) $(CXXFLAGS) -c fila_espera.c

lista_leitos.o: lista_leitos.c lista_leitos.h
	$(CXX) $(CXXFLAGS) -c lista_leitos.c

pilha_altas.o: pilha_altas.c pilha_altas.h
	$(CXX) $(CXXFLAGS) -c pilha_altas.c

test: main
	./main

clean:
	rm -f *.o main