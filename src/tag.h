#ifndef TAG_H
#define TAG_H

#include "style.h"

#include <string>
using namespace std;

class Tag
{
private:
    string id;

public:
    virtual string render() const = 0;

    Tag() : id("") {}

    Tag(string id) : id(id) {}

    virtual ~Tag() {}

    string getId() const
    {
        return id;
    }
};

#endif
