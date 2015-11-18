ThreadAssignment : ThreadAssignment.o
	g++ ThreadAssignment.o -pthread -o ThreadAssignment

ThreadAssignment.o : ThreadAssignment.cpp
	g++ -c -fpermissive ThreadAssignment.cpp

clear :
	rm *.o ThreadAssignment
