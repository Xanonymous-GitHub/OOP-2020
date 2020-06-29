#ifndef TABLE_H
#define TABLE_H

#include "tag.h"
#include "row.h"
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

  Table(const Table &otherTable) : Tag(otherTable.getId())
  {
    this->rows = otherTable.rows;
    this->inlineStyle = otherTable.inlineStyle;
    setTitle(otherTable.title);
  }

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

  Table operator=(const Table &otherTable)
  {
    this->rows = otherTable.rows;
    this->inlineStyle = otherTable.inlineStyle;
    setTitle(otherTable.title);
    return *this;
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
    if (order != "asc" && order != "desc")
    {
      throw "NO!";
    }
    sort(this->rows.begin(), this->rows.end(), [=](Row a, Row b) {
      if (order == "asc")
      {
        return a.getColContent(col) < b.getColContent(col);
      }
      else if (order == "desc")
      {
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
