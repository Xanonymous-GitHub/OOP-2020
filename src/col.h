#ifndef COL_H
#define COL_H

#include "tag.h"
#include <string>
using namespace std;

class Col : public Tag
{
private:
  string content;

public:
  Col() {}
  
  Col(string newId) : Tag(newId) {}

  Col(string newId, string content) : Tag(newId)
  {
    setContent(content);
  }

  string render() const override
  {
    return string("<td id='") + getId() + string("' style=''>") + this->getContent() + string("</td>");
  }

  void setContent(string content)
  {
    this->content = content;
  }

  string getContent() const
  {
    return this->content;
  }
};

#endif
