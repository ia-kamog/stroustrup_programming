CXXFLAGS += -std=c++14 -I ../..
CC = c++
ex1: ex1.o symbol_table.o token_stream.o parser.o
ex1.o: ex1.cpp symbol_table.h token_stream.h parser.h
symbol_table.o: symbol_table.cpp symbol_table.h
token_stream.o: token_stream.cpp token_stream.h
parser.o: parser.cpp parser.h symbol_table.h token_stream.h
.PHONY: clean
clean:
	-rm ex1 *.o
