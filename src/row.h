#ifndef ROW_H
#define ROW_H

#include "tag.h"
#include "col.h"
#include <string>
using namespace std;

class Row : public Tag
{
private:
  vector<Col> cols;
  string row_head = "<tr id='' style=''>", row_end = "</tr>";

public:
  Row(){}
  
  Row(string newId) : Tag(newId) {}

  string render() const override
  {
    string result = "";
    result += row_head;
    for (auto col : this->cols)
    {
      result += col.render();
    }
    result += row_end;
    return result;
  }

  void addCol(Col c)
  {
    this->cols.push_back(c);
  }

  string getColContent(int i) const
  {
    return this->cols[i].getContent();
  }
};

#endif
