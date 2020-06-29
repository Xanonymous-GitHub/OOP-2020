#include "../src/table.h"
#include "../src/util.h"
#include "../src/row.h"
#include "../src/col.h"

TEST(TABLE, setTitle)
{
    Table t;
    t.setTitle("jogijimrohivoihomihjoi");
    ASSERT_EQ("<table id='' style=''><th>jogijimrohivoihomihjoi</th></table>", t.render());
}

TEST(TABLE, addRow)
{
    Table t;
    Row r;
    Col a, b, c;
    a.setContent("iugherg");
    b.setContent("ihourgerere");
    c.setContent(";hokg;hmlg;,mh");
    r.addCol(a);
    r.addCol(b);
    r.addCol(c);
    t.addRow(r);
    ASSERT_EQ("<table id='' style=''><th></th><tr id='' style=''><td id='' style=''>iugherg</td><td id='' style=''>ihourgerere</td><td id='' style=''>;hokg;hmlg;,mh</td></tr></table>", t.render());
}

TEST(TABLE, sortRow)
{
    Table t;
    Row r1, r2, r3;
    Col a, b, c, d, e, f, g, h, i;
    a.setContent("456");
    b.setContent("102");
    c.setContent("453");
    d.setContent("ffgj");
    e.setContent("ghm");
    f.setContent(",hj");
    g.setContent("wef");
    h.setContent("4");
    i.setContent("hj ");
    r1.addCol(a);
    r1.addCol(b);
    r1.addCol(c);
    r2.addCol(d);
    r2.addCol(e);
    r2.addCol(f);
    r3.addCol(g);
    r3.addCol(h);
    r3.addCol(i);
    t.addRow(r1);
    t.addRow(r2);
    t.addRow(r3);
    t.sortRow(2, "asc");
    ASSERT_EQ("<table id='' style=''><th></th><tr id='' style=''><td id='' style=''>ffgj</td><td id='' style=''>ghm</td><td id='' style=''>,hj</td></tr><tr id='' style=''><td id='' style=''>456</td><td id='' style=''>102</td><td id='' style=''>453</td></tr><tr id='' style=''><td id='' style=''>wef</td><td id='' style=''>4</td><td id='' style=''>hj </td></tr></table>", t.render());
    t.sortRow(1, "desc");
    ASSERT_EQ("<table id='' style=''><th></th><tr id='' style=''><td id='' style=''>ffgj</td><td id='' style=''>ghm</td><td id='' style=''>,hj</td></tr><tr id='' style=''><td id='' style=''>wef</td><td id='' style=''>4</td><td id='' style=''>hj </td></tr><tr id='' style=''><td id='' style=''>456</td><td id='' style=''>102</td><td id='' style=''>453</td></tr></table>", t.render());
    ASSERT_ANY_THROW(t.sortRow(87, "posrboji hjoisbnjhoimjgp,oahjidjiohj "));
}
