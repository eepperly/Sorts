CXX=g++

main : main.o sort.o
	${CXX} main.o sort.o -o main

clean : 
	-rm main *.o