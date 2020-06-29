#include "../src/table.h"
#include "../src/util.h"

TEST(UTIL, table_from_file)
{
    Table *table = new Table(tableFromFile("./sample_data1.txt"));
    ASSERT_EQ("<table id='' style=''><th>title\r</th><tr id='' style=''><td id='' style=''>c1</td><td id='' style=''>c2</td></tr></table>", table->render());
    table = new Table(tableFromFile("./sample_data2.txt"));
    ASSERT_EQ("<table id='' style=''><th>this is title\r</th><tr id='' style=''><td id='' style=''>r1</td><td id='' style=''>content</td><td id='' style=''>in</td><td id='' style=''>first</td><td id='' style=''>row</td></tr><tr id='' style=''><td id='' style=''>r2</td><td id='' style=''>content</td><td id='' style=''>in</td><td id='' style=''>second</td><td id='' style=''>row</td></tr><tr id='' style=''><td id='' style=''>r3</td><td id='' style=''>content</td><td id='' style=''>in</td><td id='' style=''>third</td><td id='' style=''>row</td></tr></table>", table->render());
    table = new Table(tableFromFile("./sample_data3.txt"));
    ASSERT_EQ("<table id='' style=''><th>title\r</th><tr id='' style=''><td id='' style=''>2</td><td id='' style=''>3</td></tr><tr id='' style=''><td id='' style=''>1</td><td id='' style=''>2</td></tr><tr id='' style=''><td id='' style=''>3</td><td id='' style=''>4</td></tr></table>", table->render());
}

TEST(UTIL, table_from_not_exist_file)
{
    ASSERT_ANY_THROW(Table *table = new Table(tableFromFile("./oirhoeripeihjeorihjeriphjeprih.txt")));
}

// TEST(UTIL, main)
// {
// NOTE: the TA promised to me that this is not needed when exam!
// }