.PHONY: directories clean stat

all: directories bin/ut_all bin/main

bin/main: src/main.cpp
	g++ -std=c++11 src/main.cpp -o bin/main

bin/ut_all: test/ut_main.cpp
	g++ -std=c++11  test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*
