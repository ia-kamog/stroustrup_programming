PROG = ex3
CC = c++
CXXFLAGS += -std=c++14 -pedantic -Wall -O2
CPPFLAGS += -MMD -MP
SRC = ex3.cpp name_pairs.cpp
OBJ = $(SRC:.cpp=.o)
ASM = $(SRC:.cpp=.s)
DEP = $(SRC:.cpp=.d)

$(PROG): $(OBJ)
.PHONY: clean
clean:
	-rm -f $(PROG) $(DEP) $(OBJ) $(ASM)
-include $(SRC:%.cpp=%.d)

