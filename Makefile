


BOOST_INC := /fserver/reida/lib/boost_1_66_0
CXX := icpc
CFLAGS := -O3 -xHOST -qopenmp -I$(BOOST_INC)
LDFLAGS := -qopenmp



main : main.o debruijn.o
	$(CXX) $(LDFLAGS) -o main main.o debruijn.o

main.o : main.cpp preface.h
	$(CXX) $(CFLAGS) -c main.cpp -o main.o


debruijn.o : debruijn.cpp debruijn.h preface.h
	$(CXX) $(CFLAGS) -c debruijn.cpp



.PHONY : clean



clean :
	rm -rf ./main
	rm -rf ./*.o
