# OOP 2020 108820003 HW
### All made by Xanonymous.


```bash
[==========] Running 42 tests from 8 test cases.
[----------] Global test environment set-up.
[----------] 6 tests from TEXT
[ RUN      ] TEXT.default_constructor
[       OK ] TEXT.default_constructor (0 ms)
[ RUN      ] TEXT.constuctor
[       OK ] TEXT.constuctor (0 ms)
[ RUN      ] TEXT.set_text
[       OK ] TEXT.set_text (0 ms)
[ RUN      ] TEXT.add_color
[       OK ] TEXT.add_color (0 ms)
[ RUN      ] TEXT.add_fontSize
[       OK ] TEXT.add_fontSize (0 ms)
[ RUN      ] TEXT.add_multiple_style
[       OK ] TEXT.add_multiple_style (1 ms)
[----------] 6 tests from TEXT (15 ms total)

[----------] 4 tests from HTML
[ RUN      ] HTML.render
[       OK ] HTML.render (0 ms)
[ RUN      ] HTML.append_text
[       OK ] HTML.append_text (0 ms)
[ RUN      ] HTML.append_image
[       OK ] HTML.append_image (0 ms)
[ RUN      ] HTML.append_multiChild
[       OK ] HTML.append_multiChild (0 ms)
[----------] 4 tests from HTML (11 ms total)

[----------] 8 tests from STYLE
[ RUN      ] STYLE.color_default
[       OK ] STYLE.color_default (0 ms)
[ RUN      ] STYLE.color_set_the_color
[       OK ] STYLE.color_set_the_color (0 ms)
[ RUN      ] STYLE.fontsize_default
[       OK ] STYLE.fontsize_default (0 ms)
[ RUN      ] STYLE.fontsize_set_the_size
[       OK ] STYLE.fontsize_set_the_size (0 ms)
[ RUN      ] STYLE.position_default
[       OK ] STYLE.position_default (0 ms)
[ RUN      ] STYLE.position_set_top_and_left
[       OK ] STYLE.position_set_top_and_left (0 ms)
[ RUN      ] STYLE.size_default
[       OK ] STYLE.size_default (0 ms)
[ RUN      ] STYLE.size_set_height_and_right
[       OK ] STYLE.size_set_height_and_right (0 ms)
[----------] 8 tests from STYLE (22 ms total)

[----------] 6 tests from IMAGE
[ RUN      ] IMAGE.default_constructor
[       OK ] IMAGE.default_constructor (0 ms)
[ RUN      ] IMAGE.constructor
[       OK ] IMAGE.constructor (0 ms)
[ RUN      ] IMAGE.set_src
[       OK ] IMAGE.set_src (0 ms)
[ RUN      ] IMAGE.add_position
[       OK ] IMAGE.add_position (0 ms)
[ RUN      ] IMAGE.add_size
[       OK ] IMAGE.add_size (0 ms)
[ RUN      ] IMAGE.add_multiple_style
[       OK ] IMAGE.add_multiple_style (0 ms)
[----------] 6 tests from IMAGE (16 ms total)

[----------] 5 tests from COL
[ RUN      ] COL.default_constructor
[       OK ] COL.default_constructor (0 ms)
[ RUN      ] COL.constructor
[       OK ] COL.constructor (0 ms)
[ RUN      ] COL.set_content
[       OK ] COL.set_content (0 ms)
[ RUN      ] COL.add_style
[       OK ] COL.add_style (0 ms)
[ RUN      ] COL.get_content
[       OK ] COL.get_content (0 ms)
[----------] 5 tests from COL (12 ms total)

[----------] 5 tests from ROW
[ RUN      ] ROW.default_constructor
[       OK ] ROW.default_constructor (0 ms)
[ RUN      ] ROW.constructor
[       OK ] ROW.constructor (0 ms)
[ RUN      ] ROW.add_style
[       OK ] ROW.add_style (0 ms)
[ RUN      ] ROW.add_col
[       OK ] ROW.add_col (0 ms)
[ RUN      ] ROW.get_col_content
[       OK ] ROW.get_col_content (0 ms)
[----------] 5 tests from ROW (10 ms total)

[----------] 6 tests from TABLE
[ RUN      ] TABLE.default_constructor
[       OK ] TABLE.default_constructor (0 ms)
[ RUN      ] TABLE.constructor
[       OK ] TABLE.constructor (0 ms)
[ RUN      ] TABLE.setTitle
[       OK ] TABLE.setTitle (0 ms)
[ RUN      ] TABLE.add_style
[       OK ] TABLE.add_style (0 ms)
[ RUN      ] TABLE.addRow
[       OK ] TABLE.addRow (0 ms)
[ RUN      ] TABLE.sortRow
[       OK ] TABLE.sortRow (0 ms)
[----------] 6 tests from TABLE (11 ms total)

[----------] 2 tests from UTIL
[ RUN      ] UTIL.table_from_file
[       OK ] UTIL.table_from_file (1 ms)
[ RUN      ] UTIL.table_from_not_exist_file
[       OK ] UTIL.table_from_not_exist_file (0 ms)
[----------] 2 tests from UTIL (4 ms total)

[----------] Global test environment tear-down
[==========] 42 tests from 8 test cases ran. (130 ms total)
[  PASSED  ] 42 tests.
```