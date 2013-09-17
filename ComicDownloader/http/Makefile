http:main.o http.o
	g++ -o http -DDEBUG main.o http.o
main.o:main.cpp http.h
	g++ -c  -DDEBUG main.cpp
http.o:http.cpp http.h
	g++ -c  -DDEBUG http.cpp
clean:
	rm -f *.o http
