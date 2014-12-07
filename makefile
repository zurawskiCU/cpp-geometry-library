all: libcppgeo.a

tests: testLinePoint

libcppgeo.a: src/LinePoint.o src/Polygon.o src/RegularPolygon.o src/Square.o
	ar -rc libcppgeo.a src/LinePoint.o src/Polygon.cxx src/RegularPolygon.o src/Square.o 
	mv libcppgeo.a lib/

testLinePoint: include/catch.hpp
	g++ -Wall src/testLinePoint.cxx src/LinePoint.cxx -o tests/testLinePoint

src/Square.o: src/LinePoint.o
	g++ -c -std=c++11 src/Square.cxx -o src/Square.o

src/RegularPolygon.o: src/RegularPolygon.cxx src/LinePoint.o
	g++ -Wall  -c -std=c++11 src/RegularPolygon.cxx -o src/RegularPolygon.o

src/Polygon.o: src/Polygon.cxx src/LinePoint.o
	g++ -Wall -c -std=c++11 src/Polygon.cxx -o src/Polygon.o

src/LinePoint.o: src/LinePoint.cxx
	g++ -Wall -c -std=c++11 src/LinePoint.cxx -o src/LinePoint.o

clean:
	@rm -f src/*o bin/* lib/* tests/*