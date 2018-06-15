CXXFLAGS += -std=c++14 -I ../..
CC = c++
ex9: ex9.o symbol_table.o token_stream.o
ex9.o: ex9.cpp symbol_table.h token_stream.h
symbol_table.o: symbol_table.cpp symbol_table.h
token_stream.o: token_stream.cpp token_stream.h
.PHONY: clean
clean:
	-rm ex9 *.o
