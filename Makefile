CXX=g++

main : main.o sort.o testFuncs.o
	${CXX} main.o sort.o testFuncs.o -o main

clean : 
	-rm -f main *.o *~