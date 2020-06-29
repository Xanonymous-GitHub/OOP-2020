#ifndef TABLE_H
#define TABLE_H

#include "tag.h"
#include "row.h"
#include <iostream> // debug
#include <algorithm>
#include <string>
using namespace std;
class Table : public Tag
{
private:
  string title, table_head = "<table id='", table_end = "</table>", inlineStyle;
  vector<Row> rows;

public:
  Table() {}

  Table(string newId) : Tag(newId) {}

  string render() const override
  {
    string result = "";
    result += table_head;
    result += getId();
    result += "' style='";
    result += inlineStyle;
    result += "'>";
    result += (string("<th>") + this->title + string("</th>"));
    for (auto row : this->rows)
    {
      result += row.render();
    }
    result += table_end;
    return result;
  }

  void setTitle(string title)
  {
    this->title = title;
  }

  void addRow(Row r)
  {
    this->rows.push_back(r);
  }

  void sortRow(int col, string order)
  {
    cout << "col: " << col << endl;
    for (auto row : rows)
    {
      cout << row.render() << endl;
    }
    if (order != "asc" && order != "desc")
    {
      throw "NO!";
    }
    sort(this->rows.begin(), this->rows.end(), [=](Row a, Row b) {
      if (order == "asc")
      {
        cout << "a size: " << a.__debug_size() << ", b size: " << a.__debug_size() << endl;
        return a.getColContent(col) < b.getColContent(col);
      }
      else if (order == "desc")
      {
        cout << "a size: " << a.__debug_size() << ", b size: " << a.__debug_size() << endl;
        return a.getColContent(col) > b.getColContent(col);
      }
      return false;
    });
  }

  void addStyle(Style *style)
  {
    inlineStyle += style->renderStyle();
  }
};

#endif
