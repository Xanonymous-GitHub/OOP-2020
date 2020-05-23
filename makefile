.PHONY: directories clean

CFLAGS = -std=c++11
LIBS = -lgtest -lpthread
SRC = src/*.h
TEST = test/*.h

all: directories bin/ut_all

bin/ut_all: obj/ut_main.o
	g++ $(CFLAGS) -o $@ $< $(LIBS)

obj/ut_main.o: test/ut_main.cpp $(TEST) $(SRC)
	g++ $(CFLAGS) -c $< -o $@

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*
