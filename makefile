testLinePoint: catch.hpp
	g++ -Wall -o testLinePoint testLinePoint.cxx LinePoint.cxx

unittest: catch.hpp
	g++ -Wall  -o unittest unittest.cxx LinePoint.cxx Polygon.cxx

polygon-test: polygon-test.o LinePoint.o Polygon.o
	g++ -Wall  polygon-test.o LinePoint.o Polygon.o -o polytest

Square.o: LinePoint.o
	g++ -Wall  -c -std=c++11 Square.cxx

RegularPolygon.o: RegularPolygon.cxx LinePoint.o
	g++ -Wall  -c -std=c++11 RegularPolygon.cxx

polygon-test.o: polygon-test.cxx
	g++ -Wall -c -std=c++11 polygon-test.cxx

Polygon.o: Polygon.cxx LinePoint.o
	g++ -Wall -c -std=c++11 Polygon.cxx

LinePoint.o: LinePoint.cxx
	g++ -Wall  -c -std=c++11 LinePoint.cxx

clean:
	@rm -f *o unittest unittestLinePoint test