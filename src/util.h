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
                while (tmp >> line)
                {
                    row.addCol(*new Col("", line));
                }
                result.addRow(row);
            }
        }
        file.close();
    }
    return result;
}

#endif
