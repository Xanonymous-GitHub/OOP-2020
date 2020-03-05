.PHONY: directories clean stat

all: directories bin/main bin/ut_all

bin/main: src/main.cpp src/dot.h
	#change command to gnu g++ 9 to macOS
	g++ -std=c++11 src/main.cpp -o bin/main

bin/ut_all: obj/ut_main.o
	#change command to gnu g++ 9 to macOS
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/ut_dot.h src/dot.h
	#change command to gnu g++ 9 to macOS
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*
