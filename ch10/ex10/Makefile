CXXFLAGS += -std=c++14 -I ../..
CC = c++
ex10: ex10.o symbol_table.o token_stream.o
ex10.o: ex10.cpp symbol_table.h token_stream.h
symbol_table.o: symbol_table.cpp symbol_table.h
token_stream.o: token_stream.cpp token_stream.h
.PHONY: clean
clean:
	-rm ex10 *.o
