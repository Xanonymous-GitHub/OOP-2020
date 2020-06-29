#include "../src/table.h"
#include "../src/util.h"
#include "../src/row.h"
#include "../src/position.h"

TEST(COL, default_constructor)
{
    Col c;
    ASSERT_EQ("<td id='' style=''></td>", c.render());
}

TEST(COL, constructor)
{
    Col c("slduhshbgsobsjodbj");
    ASSERT_EQ("<td id='slduhshbgsobsjodbj' style=''></td>", c.render());
}

TEST(COL, set_content)
{
    Col c;
    c.setContent("aoisfhaifjaoijfaiofjio");
    ASSERT_EQ("<td id='' style=''>aoisfhaifjaoijfaiofjio</td>", c.render());
}

TEST(COL, add_style)
{
    Col c;
    Position *p = new Position(999, 9999);
    c.addStyle(p);
    ASSERT_EQ("<td id='' style='top:999px;left:9999px;position:absolute;'></td>", c.render());
}

TEST(COL, get_content)
{
    Col c;
    c.setContent("oeighgwoeghoweifhwoegihwohegih");
    ASSERT_EQ("oeighgwoeghoweifhwoegihwohegih", c.getContent());
}

TEST(ROW, default_constructor)
{
    Row c;
    ASSERT_EQ("<tr id='' style=''></tr>", c.render());
}

TEST(ROW, constructor)
{
    Row c("slduhshbgsobsjodbj");
    ASSERT_EQ("<tr id='slduhshbgsobsjodbj' style=''></tr>", c.render());
}

TEST(ROW, add_style)
{
    Row c;
    Position *p = new Position(999, 9999);
    c.addStyle(p);
    ASSERT_EQ("<tr id='' style='top:999px;left:9999px;position:absolute;'></tr>", c.render());
}

TEST(ROW, add_col)
{
    Row c;
    Col c1, c2, c3;
    c1.setContent("wefwef");
    c2.setContent("tktyktyk");
    c3.setContent("3t4t34t34");
    c.addCol(c1);
    c.addCol(c2);
    c.addCol(c3);
    ASSERT_EQ("<tr id='' style=''><td id='' style=''>wefwef</td><td id='' style=''>tktyktyk</td><td id='' style=''>3t4t34t34</td></tr>", c.render());
}

TEST(ROW, get_col_content)
{
    Row c;
    Col c1, c2, c3;
    c1.setContent("wefwef");
    c2.setContent("tktyktyk");
    c3.setContent("3t4t34t34");
    c.addCol(c1);
    c.addCol(c2);
    c.addCol(c3);
    ASSERT_EQ("wefwef", c.getColContent(0));
    ASSERT_EQ("tktyktyk", c.getColContent(1));
    ASSERT_EQ("3t4t34t34", c.getColContent(2));
}

TEST(TABLE, default_constructor)
{
    Table t;
    ASSERT_EQ("<table id='' style=''><th></th></table>", t.render());
}

TEST(TABLE, constructor)
{
    Table t("lsiglgjljglwejgopwiejgowiejgpweojgpwoejg");
    ASSERT_EQ("<table id='lsiglgjljglwejgopwiejgowiejgpweojgpwoejg' style=''><th></th></table>", t.render());
}

TEST(TABLE, setTitle)
{
    Table t;
    t.setTitle("jogijimrohivoihomihjoi");
    ASSERT_EQ("<table id='' style=''><th>jogijimrohivoihomihjoi</th></table>", t.render());
}

TEST(TABLE, add_style)
{
    Table t;
    Position *p = new Position(999, 9999);
    t.addStyle(p);
    ASSERT_EQ("<table id='' style='top:999px;left:9999px;position:absolute;'><th></th></table>", t.render());
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
