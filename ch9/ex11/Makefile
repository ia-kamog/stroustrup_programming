PROG = ex11
CC = c++
CXXFLAGS += -std=c++14 -pedantic -Wall -O2
CPPFLAGS += -MMD -MP
SRC = $(PROG).cpp date.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

$(PROG): $(OBJ)
.PHONY: clean
clean:
	-rm -f $(PROG) $(DEP) $(OBJ)
-include $(SRC:%.cpp=%.d)

