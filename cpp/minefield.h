#ifndef MINEFIELD_H
#define MINEFIELD_H

#include "FieldItem.h"

#include <vector>
#include <string>


class MineField
{
private:
    /* data */
    std::vector<std::vector<FieldItem>> field;
    int detectNums = 0;
    int markNums  = 0;
    int length = 9;
    int width  = 9;
    int nmine  = 10;

public:
    MineField(/* args */);
    void init();
    void config(int len, int wid, int mines);
    ~MineField();
};



#endif /* MINEFIELD_H */