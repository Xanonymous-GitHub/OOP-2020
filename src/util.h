#ifndef UTIL_H
#define UTIL_H

#include "table.h"
#include "row.h"
#include "col.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Table tableFromFile(string filePath)
{
    ifstream file(filePath);
    string line;
    Table result;
    if (file && file.is_open() && file.good())
    {
        while (getline(file, line))
        {
            result.setTitle(line);
            while (line != "") // making rows
            {
                getline(file, line);
                stringstream tmp;
                Row row;
                tmp << line;
                bool __add_row_activate = false;
                while (tmp >> line)
                {
                    __add_row_activate = true;
                    row.addCol(*new Col("", line));
                }
                if (__add_row_activate)
                {
                    result.addRow(row);
                }
            }
        }
        file.close();
    }
    else
    {
        throw "NO!";
    }
    return result;
}

#endif
