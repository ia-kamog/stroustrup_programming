CC = c++

.PHONY: all
all: drill2 drill3 drill4 drill5 drill6 drill7

drill2: drill2.o point.o
drill2.o: drill2.cpp point.h

drill3: drill3.o point.o
drill3.o: drill3.cpp point.h

drill4: drill4.o point.o
drill4.o: drill4.cpp point.h

drill5: drill5.o point.o
drill5.o: drill5.cpp point.h

drill6: drill6.o point.o
drill6.o: drill6.cpp point.h

drill7: drill7.o point.o
drill7.o: drill7.cpp point.h

point.o: point.cpp point.h

.PHONY: clean
clean:
	-rm -f drill2 drill2.o point.o drill3 drill3.o \
		drill4.o drill4 drill5.o drill5 drill6.o drill6 \
		drill7.o drill7
