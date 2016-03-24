a.exe: CNF.o util.o CYK.o
	g++ CNF.o util.o CYK.o
	
CNF.o: CNF.cpp
	g++ -c -g -O3 -std=c++14 CNF.cpp
	
util.o: util.cpp
	g++ -c -g -O3 -std=c++14 util.cpp
	
CYK.o: CYK.cpp
	g++ -c -g -O3 -std=c++14 CYK.cpp
	