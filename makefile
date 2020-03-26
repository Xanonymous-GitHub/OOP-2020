all: directories bin/ut_all

bin/ui_main: src/main.cpp src/html.h src/text.h
	g++ -std=c++11 -o bin/ui_main src/main.cpp

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/ut_html.h test/ut_text.h src/html.h src/text.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*