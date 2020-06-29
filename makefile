.PHONY: directories clean stat

all: directories bin/ut_all

bin/ui_main: src/main.cpp src/html.h src/tag.h src/text.h src/image.h \
			 src/color.h src/fontsize.h src/position.h src/size.h src/style.h \
			 src/table.h src/row.h src/col.h src/util.h
	g++ -std=c++11 src/main.cpp -o bin/ui_main

bin/ut_all: test/ut_main.cpp test/ut_style.h test/ut_html.h test/ut_image.h \
			test/ut_table.h test/ut_text.h test/ut_util.h src/tag.h src/html.h \
			src/table.h src/row.h src/col.h src/style.h src/color.h src/fontsize.h \
			src/position.h src/size.h src/util.h src/text.h src/image.h
	g++ -std=c++11  test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/* test/*
