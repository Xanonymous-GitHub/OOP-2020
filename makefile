all: directories bin/ut_all test

bin/ui_main: src/*.cpp src/*.h
	g++ -std=c++11 -o bin/ui_main src/main.cpp

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/*.cpp test/*.h src/*.h src/*.cpp
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*

test:
	./bin/ut_all