PROG = drill3
CC = c++
CXXFLAGS += -std=c++14 -pedantic -Wall -O2
CPPFLAGS += -MMD -MP
SRC = date.cpp drill3.cpp
OBJ = $(SRC:.cpp=.o)
ASM = $(SRC:.cpp=.s)
DEP = $(SRC:.cpp=.d)

$(PROG): $(OBJ)
.PHONY: clean
clean:
	-rm -f $(PROG) $(DEP) $(OBJ) $(ASM)
-include $(SRC:%.cpp=%.d)

